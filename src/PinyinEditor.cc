/* vim:set et ts=4 sts=4:
 *
 * ibus-pinyin - The Chinese PinYin engine for IBus
 *
 * Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#include "PinyinEditor.h"
#include "SimpTradConverter.h"
#include "HalfFullConverter.h"

namespace PY {

/* init static members */
PinyinEditor::PinyinEditor (PinyinProperties & props, Config & config)
    : PhoneticEditor (props, config)
{
}


/**
 * process pinyin
 */
inline gboolean
PinyinEditor::processPinyin (guint keyval, guint keycode, guint modifiers)
{
    if (G_UNLIKELY (CMSHM_FILTER (modifiers) != 0))
        return m_text ? TRUE : FALSE;

    return insert (keyval);
}

/**
 * process numbers
 */
inline gboolean
PinyinEditor::processNumber (guint keyval, guint keycode, guint modifiers)
{
    guint i;

    if (!m_text)
        return FALSE;

    switch (keyval) {
    case IBUS_0:
    case IBUS_KP_0:
        i = 9;
        break;
    case IBUS_1 ... IBUS_9:
        i = keyval - IBUS_1;
        break;
    case IBUS_KP_1 ... IBUS_KP_9:
        i = keyval - IBUS_KP_1;
        break;
    default:
        g_return_val_if_reached (FALSE);
    }
    if (modifiers == 0)
        selectCandidateInPage (i);
    else if ((modifiers & ~IBUS_LOCK_MASK) == IBUS_CONTROL_MASK)
        resetCandidateInPage (i);
    return TRUE;
}

inline gboolean
PinyinEditor::processPunct (guint keyval, guint keycode, guint modifiers)
{
    if (m_text.empty ())
        return FALSE;

    if (CMSHM_FILTER (modifiers) != 0)
        return TRUE;

    switch (keyval) {
    case IBUS_apostrophe:
        return insert (keyval);
    case IBUS_comma:
        if (m_config.commaPeriodPage ()) {
            pageUp ();
            return TRUE;
        }
        break;
    case IBUS_minus:
        if (m_config.minusEqualPage ()) {
            pageUp ();
            return TRUE;
        }
        break;
    case IBUS_period:
        if (m_config.commaPeriodPage ()) {
            pageDown ();
            return TRUE;
        }
        break;
    case IBUS_equal:
        if (m_config.minusEqualPage ()) {
            pageDown ();
            return TRUE;
        }
        break;
    }

    if (m_config.autoCommit ()) {
        if (m_phrase_editor.pinyinExistsAfterCursor ()) {
            selectCandidate (m_lookup_table.cursorPos ());
        }
        commit ();
        return FALSE;
    }
    return TRUE;
}

inline gboolean
PinyinEditor::processFunctionKey (guint keyval, guint keycode, guint modifiers)
{
    if (m_text.empty ())
        return FALSE;

    /* ignore numlock */
    modifiers = CMSHM_FILTER (modifiers);

    if (modifiers != 0 && modifiers != IBUS_CONTROL_MASK)
        return TRUE;

    /* process some cursor control keys */
    if (modifiers == 0) {
        switch (keyval) {
        case IBUS_Shift_L:
            if (!m_config.shiftSelectCandidate ())
                return FALSE;
            selectCandidateInPage (1);
            return TRUE;

        case IBUS_Shift_R:
            if (!m_config.shiftSelectCandidate ())
                return FALSE;
            selectCandidateInPage (2);
            return TRUE;
        };
    }

    return PhoneticEditor::processFunctionKey (keyval, keycode, modifiers);
}

gboolean
PinyinEditor::processKeyEvent (guint keyval, guint keycode, guint modifiers)
{
    modifiers &= (IBUS_SHIFT_MASK |
                  IBUS_CONTROL_MASK |
                  IBUS_MOD1_MASK |
                  IBUS_SUPER_MASK |
                  IBUS_HYPER_MASK |
                  IBUS_META_MASK |
                  IBUS_LOCK_MASK);

    switch (keyval) {
    /* letters */
    case IBUS_a ... IBUS_z:
        return processPinyin (keyval, keycode, modifiers);
    case IBUS_0 ... IBUS_9:
    case IBUS_KP_0 ... IBUS_KP_9:
        return processNumber (keyval, keycode, modifiers);
    case IBUS_exclam ... IBUS_slash:
    case IBUS_colon ... IBUS_at:
    case IBUS_bracketleft ... IBUS_quoteleft:
    case IBUS_braceleft ... IBUS_asciitilde:
        return processPunct (keyval, keycode, modifiers);
    case IBUS_space:
        return processSpace (keyval, keycode, modifiers);
    default:
        return processFunctionKey (keyval, keycode, modifiers);
    }
}

void
PinyinEditor::commit ()
{
    if (G_UNLIKELY (m_buffer.empty ()))
        return;

    m_buffer.clear ();

    m_buffer << m_phrase_editor.selectedString ();

    const gchar *p;

    if (m_selected_special_phrase.empty ()) {
        p = textAfterPinyin (m_buffer.utf8Length ());
    }
    else {
        m_buffer << m_selected_special_phrase;
        p = textAfterCursor ();
    }

    if (G_UNLIKELY (m_props.modeFull ())) {
        while (*p != '\0') {
            m_buffer.appendUnichar (HalfFullConverter::toFull (*p++));
        }
    }
    else {
        m_buffer << p;
    }
    m_phrase_editor.commit ();
    reset ();
    PhoneticEditor::commit ((const gchar *)m_buffer);
}

void
PinyinEditor::updatePreeditText ()
{
    /* preedit text = selected phrases + highlight candidate + rest text */
    if (G_UNLIKELY (m_phrase_editor.empty () && m_text.empty ())) {
        hidePreeditText ();
        return;
    }

    guint edit_begin = 0;
    guint edit_end = 0;

    m_buffer.clear ();

    /* add selected phrases */
    m_buffer << m_phrase_editor.selectedString ();

    if (G_UNLIKELY (! m_selected_special_phrase.empty ())) {
        /* add selected special phrase */
        m_buffer << m_selected_special_phrase;
        edit_begin = m_buffer.utf8Length ();

        /* append text after cursor */
        m_buffer << textAfterCursor ();
    }
    else {
        edit_begin = m_buffer.utf8Length ();
        if (m_lookup_table.size () > 0) {
            guint cursor = m_lookup_table.cursorPos ();

            if (cursor < m_special_phrases.size ()) {
                m_buffer << m_special_phrases[cursor].c_str ();
                edit_end = m_buffer.utf8Length ();
                /* append text after cursor */
                m_buffer << textAfterCursor ();
            }
            else {
                const Phrase & candidate = m_phrase_editor.candidate (cursor - m_special_phrases.size ());
                if (m_text.size () == m_cursor) {
                    /* cursor at end */
                    if (m_props.modeSimp ())
                        m_buffer << candidate;
                    else
                        SimpTradConverter::simpToTrad (candidate, m_buffer);
                    edit_end = m_buffer.utf8Length ();

                    /* append rest text */
                    m_buffer << textAfterPinyin (edit_end);
                }
                else {
                    guint candidate_end = edit_begin + candidate.len;
                    m_buffer << m_pinyin[edit_begin]->sheng << m_pinyin[edit_begin]->yun;

                    for (guint i = edit_begin + 1; i < candidate_end; i++) {
                        m_buffer << ' ' << m_pinyin[i]->sheng << m_pinyin[i]->yun;
                    }
                    m_buffer << '|' << textAfterPinyin (candidate_end);
                    edit_end = m_buffer.utf8Length ();
                }
            }
        }
        else {
            m_buffer << textAfterPinyin ();
        }
    }

    StaticText preedit_text (m_buffer);
    /* underline */
    preedit_text.appendAttribute (IBUS_ATTR_TYPE_UNDERLINE, IBUS_ATTR_UNDERLINE_SINGLE, 0, -1);

    /* candidate */
    if (edit_begin < edit_end) {
        preedit_text.appendAttribute (IBUS_ATTR_TYPE_FOREGROUND, 0x00000000,
                                        edit_begin, edit_end);
        preedit_text.appendAttribute (IBUS_ATTR_TYPE_BACKGROUND, 0x00c8c8f0,
                                        edit_begin, edit_end);
    }
    Editor::updatePreeditText (preedit_text, edit_begin, TRUE);
}

void
PinyinEditor::updateAuxiliaryText ()
{
    /* clear pinyin array */
    if (G_UNLIKELY (m_text.empty () ||
        m_lookup_table.size () == 0)) {
        hideAuxiliaryText ();
        return;
    }

    m_buffer.clear ();

    updateAuxiliaryTextBefore (m_buffer);

    if (m_selected_special_phrase.empty ()) {
        if (m_lookup_table.cursorPos () < m_special_phrases.size ()) {
            guint begin = m_phrase_editor.cursorInChar ();
            m_buffer << m_text.substr (begin, m_cursor - begin)
                     << '|' << textAfterCursor ();
        }
        else {
            for (guint i = m_phrase_editor.cursor (); i < m_pinyin.size (); ++i) {
                if (G_LIKELY (i != m_phrase_editor.cursor ()))
                    m_buffer << ' ';
                const Pinyin *p = m_pinyin[i];
                m_buffer << p->sheng
                         << p->yun;
            }

            if (G_UNLIKELY (m_pinyin_len == m_cursor)) {
                /* aux = pinyin + non-pinyin */
                // cursor_pos =  m_buffer.utf8Length ();
                m_buffer << '|' << textAfterPinyin ();
            }
            else {
                /* aux = pinyin + ' ' + non-pinyin before cursor + non-pinyin after cursor */
                m_buffer << ' ';
                m_buffer.append (textAfterPinyin (),
                             m_cursor - m_pinyin_len);
                // cursor_pos =  m_buffer.utf8Length ();
                m_buffer  << '|' << textAfterCursor ();
            }
        }
    }
    else {
        if (m_cursor < m_text.size ()) {
            m_buffer  << '|' << textAfterCursor ();
        }
    }

    updateAuxiliaryTextAfter (m_buffer);

    StaticText aux_text (m_buffer);
    Editor::updateAuxiliaryText (aux_text, TRUE);
}


void
PinyinEditor::updateLookupTable ()
{
    m_lookup_table.setPageSize (m_config.pageSize ());
    m_lookup_table.setOrientation (m_config.orientation ());
    PhoneticEditor::updateLookupTable ();
}

};

