/* vim:set et ts=4 sts=4:
 *
 * ibus-pinyin - The Chinese PinYin engine for IBus
 *
 * Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
 * Copyright (c) 2010 BYVoid <byvoid1@gmail.com>
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
#include "BopomofoEditor.h"
#include "Config.h"
#include "PinyinProperties.h"
#include "SimpTradConverter.h"

namespace PY {
#include "BopomofoKeyboard.h"

const static gchar * bopomofo_select_keys[] = {
    "1234567890",
    "asdfghjkl;",
    "1qaz2wsxed",
    "asdfzxcvgb",
    "1234qweras",
    "aoeu;qjkix",
    "aoeuhtnsid",
    "aoeuidhtns",
    "qweasdzxcr"
};

BopomofoEditor::BopomofoEditor (PinyinProperties & props, Config & config)
    : PhoneticEditor (props, config),
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
    PhoneticEditor::reset ();
}

gboolean
BopomofoEditor::insert (gint ch)
{
    /* is full */
    if (G_UNLIKELY (m_text.length () >= MAX_PINYIN_LEN))
        return TRUE;

    m_text.insert (m_cursor++, ch);

    if (G_UNLIKELY (!(m_config.option () & PINYIN_INCOMPLETE_PINYIN))) {
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

gboolean
BopomofoEditor::processGuideKey (guint keyval, guint keycode, guint modifiers)
{
    if (!m_config.guideKey ())
        return FALSE;

    if (G_UNLIKELY (cmshm_filter (modifiers) != 0))
        return FALSE;

    if (G_LIKELY (m_select_mode))
        return FALSE;

    if (G_UNLIKELY (keyval == IBUS_space)) {
        m_select_mode = TRUE;
        updateLookupTable ();
        return TRUE;
    }

    return FALSE;
}

gboolean
BopomofoEditor::processAuxiliarySelectKey (guint keyval, guint keycode, guint modifiers)
{
    if (G_UNLIKELY (cmshm_filter (modifiers) != 0))
        return FALSE;

    guint i;

    switch (keyval) {
    case IBUS_KP_0:
        i = 9;
        if (!m_config.auxiliarySelectKeyKP ())
            return FALSE;
        break;
    case IBUS_KP_1 ... IBUS_KP_9:
        i = keyval - IBUS_KP_1;
        if (!m_config.auxiliarySelectKeyKP ())
            return FALSE;
        break;
    case IBUS_F1 ... IBUS_F10:
        i = keyval - IBUS_F1;
        if (!m_config.auxiliarySelectKeyF ())
            return FALSE;
        break;
    default:
        return FALSE;
    }

    m_select_mode = TRUE;
    selectCandidateInPage (i);

    return TRUE;
}

gboolean
BopomofoEditor::processSelectKey (guint keyval, guint keycode, guint modifiers)
{
    if (G_UNLIKELY (!m_text))
        return FALSE;

    if (G_LIKELY (!m_select_mode && ((modifiers & IBUS_MOD1_MASK) == 0)))
        return FALSE;

    const gchar * pos = strchr (bopomofo_select_keys[m_config.selectKeys ()], keyval);
    if (pos == NULL)
        return FALSE;

    m_select_mode = TRUE;

    guint i = pos - bopomofo_select_keys[m_config.selectKeys ()];
    selectCandidateInPage (i);

    return TRUE;
}

gboolean
BopomofoEditor::processBopomofo (guint keyval, guint keycode, guint modifiers)
{
    if (G_UNLIKELY (cmshm_filter (modifiers) != 0))
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


    if (G_UNLIKELY (processGuideKey (keyval, keycode, modifiers)))
        return TRUE;
    if (G_UNLIKELY (processSelectKey (keyval, keycode, modifiers) == TRUE))
        return TRUE;
    if (G_UNLIKELY (processAuxiliarySelectKey (keyval, keycode, modifiers)))
        return TRUE;
    if (G_UNLIKELY (processBopomofo (keyval, keycode ,modifiers)))
        return TRUE;

    switch (keyval) {
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
        return PhoneticEditor::processFunctionKey (keyval, keycode, modifiers);

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
        return PhoneticEditor::processFunctionKey (keyval, keycode, modifiers);

    default:
        return PhoneticEditor::processFunctionKey (keyval, keycode, modifiers);
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
                                                    m_config.option (),   // option
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

    StaticText aux_text (m_buffer);
    Editor::updateAuxiliaryText (aux_text, TRUE);
}

void
BopomofoEditor::commit (void)
{
    if (G_UNLIKELY (m_buffer.empty ()))
        return;

    m_buffer.clear ();

    if (m_select_mode) {
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
    }
    else {
        m_buffer << m_text;
    }

    m_phrase_editor.commit ();
    reset ();
    PhoneticEditor::commit ((const gchar *)m_buffer);
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

void
BopomofoEditor::updateLookupTableLabel ()
{
    std::string str;
    guint color = m_select_mode ? 0x000000 : 0xBBBBBB;
    for (const gchar *p = bopomofo_select_keys[m_config.selectKeys ()]; *p; p++)
    {
        guint i = p - bopomofo_select_keys[m_config.selectKeys ()];
        if (i >= m_config.pageSize ())
            break;
        str = *p;
        str += ".";
        Text text_label (str);
        text_label.appendAttribute (IBUS_ATTR_TYPE_FOREGROUND, color, 0, -1);
        m_lookup_table.setLabel (i, text_label);
    }
    if (m_config.guideKey ())
        m_lookup_table.setCursorVisable (m_select_mode);
    else
        m_lookup_table.setCursorVisable (TRUE);
}

void
BopomofoEditor::updateLookupTableFast ()
{
    updateLookupTableLabel ();
    PhoneticEditor::updateLookupTableFast ();
}

void
BopomofoEditor::updateLookupTable ()
{
    m_lookup_table.setPageSize (m_config.pageSize ());
    m_lookup_table.setOrientation (m_config.orientation ());
    updateLookupTableLabel ();
    PhoneticEditor::updateLookupTable ();
}

static gint
keyboard_cmp (gconstpointer p1, gconstpointer p2)
{
    const gint s1 = GPOINTER_TO_INT (p1);
    const guint8 *s2 = (const guint8 *) p2;
    return s1 - s2[0];
}

gint
BopomofoEditor::keyvalToBopomofo(gint ch)
{
    const gint keyboard = m_config.bopomofoKeyboardMapping ();
    const guint8 *brs;
    brs = (const guint8 *) std::bsearch (GINT_TO_POINTER (ch),
                                       bopomofo_keyboard[keyboard],
                                       G_N_ELEMENTS (bopomofo_keyboard[keyboard]),
                                       sizeof(bopomofo_keyboard[keyboard][0]),
                                       keyboard_cmp);
    if (G_UNLIKELY (brs == NULL))
        return BOPOMOFO_ZERO;
    return brs[1];
}

};
