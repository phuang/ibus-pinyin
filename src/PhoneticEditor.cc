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
#include "PhoneticEditor.h"
#include "SimpTradConverter.h"

namespace PY {

/* init static members */
PhoneticEditor::PhoneticEditor (PinyinProperties & props, Config & config)
    : Editor (props, config),
      m_pinyin (MAX_PHRASE_LEN),
      m_pinyin_len (0),
      m_buffer (64),
      m_lookup_table (m_config.pageSize ()),
      m_phrase_editor (props, config)
{
}

gboolean
PhoneticEditor::processSpace (guint keyval, guint keycode, guint modifiers)
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
PhoneticEditor::processFunctionKey (guint keyval, guint keycode, guint modifiers)
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
        case IBUS_Return:
        case IBUS_KP_Enter:
            commit ();
            return TRUE;

        case IBUS_BackSpace:
            if (m_phrase_editor.unselectCandidates ()) {
                update ();
            }
            else {
                removeCharBefore ();
            }
            return TRUE;

        case IBUS_Delete:
        case IBUS_KP_Delete:
            removeCharAfter ();
            return TRUE;

        case IBUS_Left:
        case IBUS_KP_Left:
            if (m_phrase_editor.unselectCandidates ()) {
                update ();
            }
            else {
                moveCursorLeft ();
            }
            return TRUE;

        case IBUS_Right:
        case IBUS_KP_Right:
            if (m_phrase_editor.unselectCandidates ()) {
                update ();
            }
            else {
                moveCursorRight ();
            }
            return TRUE;

        case IBUS_Home:
        case IBUS_KP_Home:
            if (m_phrase_editor.unselectCandidates ()) {
                update ();
            }
            else {
                moveCursorToBegin ();
            }
            return TRUE;

        case IBUS_End:
        case IBUS_KP_End:
            if (m_phrase_editor.unselectCandidates ()) {
                update ();
            }
            else {
                moveCursorToEnd ();
            }
            return TRUE;

        case IBUS_Up:
        case IBUS_KP_Up:
            cursorUp ();
            return TRUE;

        case IBUS_Down:
        case IBUS_KP_Down:
            cursorDown ();
            return TRUE;

        case IBUS_Page_Up:
        case IBUS_KP_Page_Up:
            pageUp ();
            return TRUE;

        case IBUS_Page_Down:
        case IBUS_KP_Page_Down:
        case IBUS_Tab:
            pageDown ();
            return TRUE;

        case IBUS_Escape:
            reset ();
            return TRUE;
        default:
            return TRUE;
        }
    }
    else {
        switch (keyval) {
        case IBUS_BackSpace:
            if (m_phrase_editor.unselectCandidates ()) {
                update ();
            }
            else {
                removeWordBefore ();
            }
            return TRUE;

        case IBUS_Delete:
        case IBUS_KP_Delete:
            removeWordAfter ();
            return TRUE;

        case IBUS_Left:
        case IBUS_KP_Left:
            if (m_phrase_editor.unselectCandidates ()) {
                update ();
            }
            else {
                moveCursorLeftByWord ();
            }
            return TRUE;

        case IBUS_Right:
        case IBUS_KP_Right:
            if (m_phrase_editor.unselectCandidates ()) {
                update ();
            }
            else {
                moveCursorToEnd ();
            }
            return TRUE;

        default:
            return TRUE;
        };
    }
    return TRUE;
}

gboolean
PhoneticEditor::processKeyEvent (guint keyval, guint keycode, guint modifiers)
{
    return FALSE;
}

gboolean
PhoneticEditor::updateSpecialPhrases (void)
{
    guint size = m_special_phrases.size ();
    m_special_phrases.clear ();

    if (!m_config.specialPhrases ())
        return FALSE;

    if (!m_selected_special_phrase.empty ())
        return FALSE;

    guint begin = m_phrase_editor.cursorInChar ();
    guint end = m_cursor;

    if (begin < end) {
        SpecialPhraseTable::instance ().lookup (
            m_text.substr (begin, m_cursor - begin),
            m_special_phrases);
    }

    return size != m_special_phrases.size () || size != 0;
}



void
PhoneticEditor::updateLookupTable (void)
{
    m_lookup_table.clear ();

    fillLookupTableByPage ();
    if (m_lookup_table.size ()) {
        Editor::updateLookupTable (m_lookup_table, TRUE);
    }
    else {
        hideLookupTable ();
    }
}

gboolean
PhoneticEditor::fillLookupTableByPage (void)
{
    if (!m_selected_special_phrase.empty ()) {
        return FALSE;
    }

    guint filled_nr = m_lookup_table.size ();
    guint page_size = m_lookup_table.pageSize ();

    if (m_special_phrases.size () + m_phrase_editor.candidates ().size () < filled_nr + page_size)
        m_phrase_editor.fillCandidates ();

    guint need_nr = MIN (page_size, m_special_phrases.size () + m_phrase_editor.candidates ().size () - filled_nr);
    g_assert (need_nr >= 0);
    if (need_nr == 0) {
        return FALSE;
    }

    for (guint i = filled_nr; i < filled_nr + need_nr; i++) {
        if (i < m_special_phrases.size ()) {
            Text text (m_special_phrases[i].c_str ());
            text.appendAttribute (IBUS_ATTR_TYPE_FOREGROUND, 0x0000ef00, 0, -1);
            m_lookup_table.appendCandidate (text);
        }
        else {
            if (G_LIKELY (m_props.modeSimp ())) {
                Text text (m_phrase_editor.candidate (i - m_special_phrases.size ()));
                if (m_phrase_editor.candidateIsUserPhease (i - m_special_phrases.size ()))
                    text.appendAttribute (IBUS_ATTR_TYPE_FOREGROUND, 0x000000ef, 0, -1);
                m_lookup_table.appendCandidate (text);
            }
            else {
                m_buffer.truncate (0);
                SimpTradConverter::simpToTrad (m_phrase_editor.candidate (i - m_special_phrases.size ()), m_buffer);
                Text text (m_buffer);
                if (m_phrase_editor.candidateIsUserPhease (i - m_special_phrases.size ()))
                    text.appendAttribute (IBUS_ATTR_TYPE_FOREGROUND, 0x000000ef, 0, -1);
                m_lookup_table.appendCandidate (text);
            }
        }
    }


    return TRUE;
}

void
PhoneticEditor::pageUp (void)
{
    if (G_LIKELY (m_lookup_table.pageUp ())) {
        updateLookupTableFast (m_lookup_table, TRUE);
        updatePreeditText ();
        updateAuxiliaryText ();
    }
}

void
PhoneticEditor::pageDown (void)
{
    if (G_LIKELY(
            (m_lookup_table.pageDown ()) ||
            (fillLookupTableByPage () && m_lookup_table.pageDown ()))) {
        updateLookupTableFast (m_lookup_table, TRUE);
        updatePreeditText ();
        updateAuxiliaryText ();
    }
}

void
PhoneticEditor::cursorUp (void)
{
    if (G_LIKELY (m_lookup_table.cursorUp ())) {
        updateLookupTableFast (m_lookup_table, TRUE);
        updatePreeditText ();
        updateAuxiliaryText ();
    }
}

void
PhoneticEditor::cursorDown (void)
{
    if (G_LIKELY (
            (m_lookup_table.cursorPos () == m_lookup_table.size () - 1) &&
            (fillLookupTableByPage () == FALSE))) {
        return;
    }

    if (G_LIKELY (m_lookup_table.cursorDown ())) {
        updateLookupTableFast (m_lookup_table, TRUE);
        updatePreeditText ();
        updateAuxiliaryText ();
    }
}

void
PhoneticEditor::candidateClicked (guint index, guint button, guint state)
{
   selectCandidateInPage (index);
}

void
PhoneticEditor::reset (void)
{
    m_pinyin.clear ();
    m_pinyin_len = 0;
    m_lookup_table.clear ();
    m_phrase_editor.reset ();
    m_special_phrases.clear ();
    m_selected_special_phrase.clear ();

    Editor::reset ();
}

void
PhoneticEditor::update (void)
{
    updateLookupTable ();
    updatePreeditText ();
    updateAuxiliaryText ();
}

void
PhoneticEditor::commit (const gchar *str)
{
    StaticText text(str);
    commitText (text);
}

gboolean
PhoneticEditor::selectCandidate (guint i)
{
    if (i < m_special_phrases.size ()) {
        /* select a special phrase */
        m_selected_special_phrase = m_special_phrases[i];
        if (m_cursor == m_text.size ()) {
            m_buffer = m_phrase_editor.selectedString ();
            m_buffer << m_selected_special_phrase;
            m_phrase_editor.commit ();
            reset ();
            commit ((const gchar *)m_buffer);
        }
        else {
            updateSpecialPhrases ();
            update ();
        }
        return TRUE;
    }

    i -= m_special_phrases.size ();
    if (m_phrase_editor.selectCandidate (i)) {
        if (m_phrase_editor.pinyinExistsAfterCursor () ||
            *textAfterPinyin () != '\0') {
            updateSpecialPhrases ();
            update ();
        }
        else {
            commit ();
        }
        return TRUE;
    }
    return FALSE;
}

gboolean
PhoneticEditor::selectCandidateInPage (guint i)
{
    guint page_size = m_lookup_table.pageSize ();
    guint cursor_pos = m_lookup_table.cursorPos ();

    if (G_UNLIKELY (i >= page_size))
        return FALSE;
    i += (cursor_pos / page_size) * page_size;

    return selectCandidate (i);
}

gboolean
PhoneticEditor::resetCandidate (guint i)
{
    i -= m_special_phrases.size ();
    if (m_phrase_editor.resetCandidate (i)) {
        update ();
    }
    return TRUE;
}

gboolean
PhoneticEditor::resetCandidateInPage (guint i)
{
    guint page_size = m_lookup_table.pageSize ();
    guint cursor_pos = m_lookup_table.cursorPos ();
    i += (cursor_pos / page_size) * page_size;

    return resetCandidate (i);
}

};

