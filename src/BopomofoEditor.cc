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
#include "Config.h"
#include "BopomofoEditor.h"
#include "SimpTradConverter.h"

#define CMSHM_MASK              \
        (IBUS_CONTROL_MASK |    \
         IBUS_MOD1_MASK |       \
         IBUS_SUPER_MASK |      \
         IBUS_HYPER_MASK |      \
         IBUS_META_MASK)

#define CMSHM_FILTER(modifiers)  \
    (modifiers & (CMSHM_MASK))

namespace PY {

BopomofoEditor::BopomofoEditor (PinyinProperties & props)
    : PinyinEditor (props),
      m_select_mode (FALSE)
{
}

BopomofoEditor::~BopomofoEditor (void)
{
}

void
BopomofoEditor::reset (void)
{
    m_select_mode = FALSE;
    PinyinEditor::reset ();
}

gboolean
BopomofoEditor::insert (gint ch)
{
    /* is full */
    if (G_UNLIKELY (m_text.length () >= MAX_PINYIN_LEN))
        return TRUE;

    m_text.insert (m_cursor++, ch);

    if (G_UNLIKELY (!(Config::option () & PINYIN_INCOMPLETE_PINYIN))) {
        updateSpecialPhrases ();
        updatePinyin ();
    }
    else if (G_LIKELY (m_cursor <= m_pinyin_len + 2)) {
        updateSpecialPhrases ();
        updatePinyin ();
    }
    else {
        if (updateSpecialPhrases ()) {
            update ();
        }
        else {
            updatePreeditText ();
            updateAuxiliaryText ();
        }
    }
    return TRUE;
}

gboolean
BopomofoEditor::removeCharBefore (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    m_cursor --;
    m_text.erase (m_cursor, 1);

    updateSpecialPhrases ();
    updatePinyin ();

    return TRUE;
}

gboolean
BopomofoEditor::removeCharAfter (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_text.erase (m_cursor, 1);
    updatePreeditText ();
    updateAuxiliaryText ();

    return TRUE;
}

gboolean
BopomofoEditor::removeWordBefore (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    guint cursor;

    if (G_UNLIKELY (m_cursor > m_pinyin_len)) {
        cursor = m_pinyin_len;
    }
    else {
        const Pinyin & p = *m_pinyin.back ();
        cursor = m_cursor - p.len;
        m_pinyin_len -= p.len;
        m_pinyin.pop_back ();
    }

    m_text.erase (cursor, m_cursor - cursor);
    m_cursor = cursor;
    updateSpecialPhrases ();
    updatePhraseEditor ();
    update ();
    return TRUE;
}

gboolean
BopomofoEditor::removeWordAfter (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_text.erase (m_cursor, -1);
    updatePreeditText ();
    updateAuxiliaryText ();
    return TRUE;
}

gboolean
BopomofoEditor::moveCursorLeft (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    m_cursor --;
    updateSpecialPhrases ();
    updatePinyin ();

    return TRUE;
}

gboolean
BopomofoEditor::moveCursorRight (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_cursor ++;

    updateSpecialPhrases ();
    updatePinyin ();

    return TRUE;
}

gboolean
BopomofoEditor::moveCursorLeftByWord (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    if (G_UNLIKELY (m_cursor > m_pinyin_len)) {
        m_cursor = m_pinyin_len;
        return TRUE;
    }

    const Pinyin & p = *m_pinyin.back ();
    m_cursor -= p.len;
    m_pinyin_len -= p.len;
    m_pinyin.pop_back ();

    updateSpecialPhrases ();
    updatePhraseEditor ();
    update ();

    return TRUE;
}

gboolean
BopomofoEditor::moveCursorRightByWord (void)
{
    return moveCursorToEnd ();
}

gboolean
BopomofoEditor::moveCursorToBegin (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    m_cursor = 0;
    m_pinyin.clear ();
    m_pinyin_len = 0;

    updateSpecialPhrases ();
    updatePhraseEditor ();
    update ();

    return TRUE;
}

gboolean
BopomofoEditor::moveCursorToEnd (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_cursor = m_text.length ();
    updateSpecialPhrases ();
    updatePinyin ();

    return TRUE;
}

inline gboolean
BopomofoEditor::processSpace (guint keyval, guint keycode, guint modifiers)
{
    if (!m_text)
        return FALSE;
    if (CMSHM_FILTER (modifiers) != 0)
        return TRUE;
    if (m_lookup_table.size () != 0) {
        selectCandidate (m_lookup_table.cursorPos ());
    }
    else {
        commit ();
    }
    return TRUE;
}

gboolean
BopomofoEditor::processNumber (guint keyval, guint keycode, guint modifiers)
{
    guint i;

    if (!m_text)
        return FALSE;

    m_select_mode = TRUE;

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
        return FALSE;
    }

    selectCandidateInPage (i);

    return TRUE;
}

gboolean
BopomofoEditor::processNumberWithShift (guint keyval, guint keycode, guint modifiers)
{
    guint i;

    if (!m_text)
        return FALSE;
    if (G_UNLIKELY ((modifiers & IBUS_SHIFT_MASK) == 0))
        return FALSE;

    m_select_mode = TRUE;

    switch (keyval) {
    case IBUS_exclam:
        i = 0;
        break;
    case IBUS_at:
        i = 1;
        break;
    case IBUS_numbersign:
        i = 2;
        break;
    case IBUS_dollar:
        i = 3;
        break;
    case IBUS_percent:
        i = 4;
        break;
    case IBUS_asciicircum:
        i = 5;
        break;
    case IBUS_ampersand:
        i = 6;
        break;
    case IBUS_asterisk:
        i = 7;
        break;
    case IBUS_parenleft:
        i = 8;
        break;
    case IBUS_parenright:
        i = 9;
        break;
    default:
        return FALSE;
    }

    selectCandidateInPage (i);

    return TRUE;
}

inline gboolean
BopomofoEditor::processBopomofo (guint keyval, guint keycode, guint modifiers)
{
    if (G_UNLIKELY (CMSHM_FILTER(modifiers) != 0))
        return m_text ? TRUE : FALSE;

    if (keyvalToBopomofo (keyval) == BOPOMOFO_ZERO)
        return FALSE;

    m_select_mode = FALSE;

    return insert (keyval);
}

gboolean
BopomofoEditor::processKeyEvent (guint keyval, guint keycode, guint modifiers)
{
    modifiers &= (IBUS_SHIFT_MASK |
                  IBUS_CONTROL_MASK |
                  IBUS_MOD1_MASK |
                  IBUS_SUPER_MASK |
                  IBUS_HYPER_MASK |
                  IBUS_META_MASK |
                  IBUS_LOCK_MASK);

    if (m_select_mode == TRUE && processNumber (keyval, keycode, modifiers) == TRUE)
        return TRUE;
    if (processNumberWithShift (keyval, keycode, modifiers) == TRUE)
        return TRUE;
    if (processBopomofo (keyval, keycode ,modifiers))
        return TRUE;

    switch (keyval) {
    /* Bopomofo */
    case IBUS_KP_0 ... IBUS_KP_9:
        return processNumber (keyval, keycode, modifiers);

    case IBUS_space:
        m_select_mode = TRUE;
        return processSpace (keyval, keycode, modifiers);

    case IBUS_Up:
    case IBUS_KP_Up:
    case IBUS_Down:
    case IBUS_KP_Down:
    case IBUS_Page_Up:
    case IBUS_KP_Page_Up:
    case IBUS_Page_Down:
    case IBUS_KP_Page_Down:
    case IBUS_Tab:
        m_select_mode = TRUE;
        return PinyinEditor::processKeyEvent (keyval, keycode, modifiers);

    case IBUS_BackSpace:
    case IBUS_Delete:
    case IBUS_KP_Delete:
    case IBUS_Left:
    case IBUS_KP_Left:
    case IBUS_Right:
    case IBUS_KP_Right:
    case IBUS_Home:
    case IBUS_KP_Home:
    case IBUS_End:
    case IBUS_KP_End:
        m_select_mode = FALSE;
        return PinyinEditor::processKeyEvent (keyval, keycode, modifiers);

    default:
        return PinyinEditor::processKeyEvent (keyval, keycode, modifiers);
    }

}

void
BopomofoEditor::updatePinyin (void)
{
    if (G_UNLIKELY (m_text.empty ())) {
        m_pinyin.clear ();
        m_pinyin_len = 0;
    }
    else {
        bopomofo.clear();
        for(String::iterator i = m_text.begin (); i != m_text.end (); ++i) {
            bopomofo += bopomofo_char[keyvalToBopomofo (*i)];
        }

        m_pinyin_len = PinyinParser::parseBopomofo (bopomofo,            // bopomofo
                                                    m_cursor,            // text length
                                                    Config::option (),   // option
                                                    m_pinyin,            // result
                                                    MAX_PHRASE_LEN);     // max result length
    }

    updatePhraseEditor ();
    update ();
}

void
BopomofoEditor::updateAuxiliaryText (void)
{
    if (G_UNLIKELY (m_text.empty () ||
        m_lookup_table.size () == 0)) {
        hideAuxiliaryText ();
        return;
    }

    m_buffer.clear ();

    updateAuxiliaryTextBefore (m_buffer);

    guint si = 0;
    guint m_text_len = m_text.length();
    for (guint i = m_phrase_editor.cursor (); i < m_pinyin.size (); ++i) {
        if (G_LIKELY (i != m_phrase_editor.cursor ()))
            m_buffer << ',';
        m_buffer << (gunichar *)m_pinyin[i]->bopomofo;
        for (guint sj = 0; m_pinyin[i]->bopomofo[sj] == bopomofo_char[keyvalToBopomofo(m_text.c_str()[si])] ; si++,sj++);
        if (si < m_text_len) {
            gint ch = keyvalToBopomofo(m_text.c_str()[si]);
            if (ch >= BOPOMOFO_TONE_2 && ch <= BOPOMOFO_TONE_5) {
                m_buffer.appendUnichar(bopomofo_char[ch]);
                ++si;
            }
        }
    }

    for (String::iterator i = m_text.begin () + m_pinyin_len; i != m_text.end (); i++) {
        if (m_cursor == (guint)(i - m_text.begin ()))
            m_buffer << '|';
        m_buffer.appendUnichar (bopomofo_char[keyvalToBopomofo (*i)]);
    }
    if (m_cursor == m_text.length ())
        m_buffer << '|';

    updateAuxiliaryTextAfter (m_buffer);

    StaticText aux_text (m_buffer);
    Editor::updateAuxiliaryText (aux_text, TRUE);
}

void
BopomofoEditor::commit (void)
{
    if (G_UNLIKELY (empty ()))
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

    while (*p != '\0') {
        m_buffer.appendUnichar ((gunichar)bopomofo_char[keyvalToBopomofo (*p++)]);
    }

    m_phrase_editor.commit ();
    reset ();
    PinyinEditor::commit ((const gchar *)m_buffer);
}

void
BopomofoEditor::updatePreeditText (void)
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
                    for (const gchar *p=m_text.c_str() + m_pinyin_len; *p ;++p) {
                        m_buffer.appendUnichar(bopomofo_char[keyvalToBopomofo(*p)]);
                    }
                }
                else {
                    for (const gchar *p = m_text.c_str (); *p; ++p) {
                        if ((guint) (p - m_text.c_str ()) == m_cursor)
                            m_buffer << ' ';
                        m_buffer.appendUnichar (bopomofo_char[keyvalToBopomofo (*p)]);
                    }
                    edit_end = m_buffer.utf8Length ();
                }
            }
        }
        else {
            for (const gchar *p=m_text.c_str () + m_pinyin_len; *p ; ++p) {
                m_buffer.appendUnichar (bopomofo_char[keyvalToBopomofo (*p)]);
            }
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

};
