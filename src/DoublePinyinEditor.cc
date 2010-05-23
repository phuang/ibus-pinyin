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
#include "DoublePinyinEditor.h"

namespace PY {

#include "DoublePinyinTable.h"

/*
 * c in 'a' ... 'z' => id = c - 'a'
 * c == ';'         => id = 26
 * else             => id = -1
 */
#define ID(c) \
    ((c >= IBUS_a && c <= IBUS_z) ? c - IBUS_a : (c == IBUS_semicolon ? 26 : -1))

#define ID_TO_SHENG(id) \
    (double_pinyin_map[m_config.doublePinyinSchema ()].sheng[id])
#define ID_TO_YUNS(id) \
    (double_pinyin_map[m_config.doublePinyinSchema ()].yun[id])

#define IS_ALPHA(c) \
        ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))

DoublePinyinEditor::DoublePinyinEditor (PinyinProperties & props, Config & config)
    : PinyinEditor (props, config)
{
}

gboolean
DoublePinyinEditor::insert (gint ch)
{
    gint id;
    /* is full */
    if (G_UNLIKELY (m_text.length () >= MAX_PINYIN_LEN))
        return TRUE;

    id = ID (ch);
    if (id == -1) {
        /* it is not availidate ch */
        return FALSE;
    }

    if (G_UNLIKELY (m_text.empty () &&
        ID_TO_SHENG (id) == PINYIN_ID_VOID)) {
        return FALSE;
    }

    m_text.insert (m_cursor++, ch);

    if (m_cursor > m_pinyin_len + 2 || updatePinyin (FALSE) == FALSE) {
        if (!IS_ALPHA (ch)) {
            m_text.erase (--m_cursor, 1);
            return FALSE;
        }
        else {
            if (updateSpecialPhrases ()) {
                update ();
            }
            else {
                updatePreeditText ();
                updateAuxiliaryText ();
            }
            return TRUE;
        }
    }
    else {
        updateSpecialPhrases ();
        updatePhraseEditor ();
        update ();
        return TRUE;
    }
}

gboolean
DoublePinyinEditor::removeCharBefore (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    m_cursor --;
    m_text.erase (m_cursor, 1);

    if (updatePinyin (FALSE)) {
        updateSpecialPhrases ();
        updatePhraseEditor ();
        update ();
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
DoublePinyinEditor::removeCharAfter (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_text.erase (m_cursor, 1);
    if (updateSpecialPhrases ()) {
        update ();
    }
    else {
        updatePreeditText ();
        updateAuxiliaryText ();
    }
    return TRUE;
}

gboolean
DoublePinyinEditor::removeWordBefore (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    if (G_UNLIKELY (m_cursor > m_pinyin_len)) {
        m_text.erase (m_pinyin_len, m_cursor - m_pinyin_len);
        m_cursor = m_pinyin_len;
        if (updateSpecialPhrases ()) {
            update ();
        }
        else {
            updatePreeditText ();
            updateAuxiliaryText ();
        }
    }
    else {
        m_pinyin_len = m_pinyin.back ().begin;
        m_pinyin.pop_back ();
        m_text.erase (m_pinyin_len, m_cursor - m_pinyin_len);
        m_cursor = m_pinyin_len;
        updateSpecialPhrases ();
        updatePhraseEditor ();
        update ();
    }

    return TRUE;
}

gboolean
DoublePinyinEditor::removeWordAfter (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_text.erase (m_cursor);
    if (updateSpecialPhrases ()) {
        update ();
    }
    else {
        updatePreeditText ();
        updateAuxiliaryText ();
    }
    return TRUE;
}

gboolean
DoublePinyinEditor::moveCursorLeft (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    m_cursor --;

    if (m_cursor >= m_pinyin_len) {
        if (updateSpecialPhrases ()) {
            update ();
        }
        else {
            updatePreeditText ();
            updateAuxiliaryText ();
        }
    }
    else {
        if (updatePinyin (FALSE)) {
            updateSpecialPhrases ();
            updatePhraseEditor ();
            update ();
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
    }

    return TRUE;
}

gboolean
DoublePinyinEditor::moveCursorRight (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_cursor ++;
    if (updatePinyin (FALSE)) {
        updateSpecialPhrases ();
        updatePhraseEditor ();
        update ();
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
DoublePinyinEditor::moveCursorLeftByWord (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    if (G_UNLIKELY (m_cursor > m_pinyin_len)) {
        m_cursor = m_pinyin_len;
        if (updateSpecialPhrases ()) {
            update ();
        }
        else {
            updatePreeditText ();
            updateAuxiliaryText ();
        }
    }
    else {
        m_cursor = m_pinyin_len = m_pinyin.back ().begin;
        m_pinyin.pop_back ();
        updateSpecialPhrases ();
        updatePhraseEditor ();
        update ();
    }

    return TRUE;
}

gboolean
DoublePinyinEditor::moveCursorRightByWord (void)
{
    return moveCursorToEnd ();
}

gboolean
DoublePinyinEditor::moveCursorToBegin (void)
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
DoublePinyinEditor::moveCursorToEnd (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_cursor = m_text.length ();
    if (updatePinyin (FALSE)) {
        updateSpecialPhrases ();
        updatePhraseEditor ();
        update ();
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

void
DoublePinyinEditor::reset (void)
{
    PinyinEditor::reset ();
}

inline const Pinyin *
DoublePinyinEditor::isPinyin (gint i)
{
    if ((m_config.option () & PINYIN_INCOMPLETE_PINYIN) == 0) {
        return NULL;
    }

    gint sheng = ID_TO_SHENG (i);

    if (sheng == PINYIN_ID_VOID) {
        return NULL;
    }

    return PinyinParser::isPinyin (sheng, 0, PINYIN_INCOMPLETE_PINYIN);
}

inline const Pinyin *
DoublePinyinEditor::isPinyin (gint i, gint j)
{
    const Pinyin *pinyin;
    gint sheng = ID_TO_SHENG (i);
    const gint *yun = ID_TO_YUNS (j);

    if (sheng == PINYIN_ID_VOID || yun[0] == PINYIN_ID_VOID)
        return NULL;

    if (sheng == PINYIN_ID_ZERO && yun[0] == PINYIN_ID_ZERO)
        return NULL;

    if (yun[1] == PINYIN_ID_VOID) {
        return PinyinParser::isPinyin (sheng, yun[0],
                        m_config.option () & (PINYIN_FUZZY_ALL | PINYIN_CORRECT_V_TO_U));
    }

    pinyin = PinyinParser::isPinyin (sheng, yun[0],
                    m_config.option () & (PINYIN_FUZZY_ALL));
    if (pinyin == NULL)
        pinyin = PinyinParser::isPinyin (sheng, yun[1],
                        m_config.option () & (PINYIN_FUZZY_ALL));
    if (pinyin != NULL)
        return pinyin;

    /* if sheng == j q x y and yun == v, try to correct v to u */
    if ((m_config.option () & PINYIN_CORRECT_V_TO_U) == 0)
        return NULL;

    if (yun[0] != PINYIN_ID_V && yun[1] != PINYIN_ID_V)
        return NULL;

    switch (sheng) {
    case PINYIN_ID_J:
    case PINYIN_ID_Q:
    case PINYIN_ID_X:
    case PINYIN_ID_Y:
        return PinyinParser::isPinyin (sheng, PINYIN_ID_V,
                            m_config.option () & (PINYIN_FUZZY_ALL | PINYIN_CORRECT_V_TO_U));
    default:
        return NULL;
    }
}

inline gboolean
DoublePinyinEditor::updatePinyin (gboolean all)
{
    gboolean retval = FALSE;

    if (all &&
        (m_pinyin_len != 0 || !m_pinyin.empty ())) {
        m_pinyin.clear ();
        m_pinyin_len = 0;
        retval = TRUE;
    }

    if (m_pinyin_len > m_cursor) {
        retval = TRUE;
        while (m_pinyin_len > m_cursor) {
            m_pinyin_len = m_pinyin.back ().begin;
            m_pinyin.pop_back ();
        }
    }

    if (m_pinyin_len == m_cursor) {
        return retval;
    }

    if (m_pinyin_len < m_cursor) {
        guint len = m_pinyin_len;
        if (m_pinyin.empty () == FALSE &&
            m_pinyin.back ()->flags & PINYIN_INCOMPLETE_PINYIN) {
            const Pinyin *pinyin = isPinyin (ID (m_text[m_pinyin_len -1]),ID (m_text[m_pinyin_len]));
            if (pinyin) {
                m_pinyin.pop_back ();
                m_pinyin.append (pinyin, m_pinyin_len - 1, 2);
                m_pinyin_len += 1;
            }
        }
        while (m_pinyin_len < m_cursor && m_pinyin.size () < MAX_PHRASE_LEN) {
            const Pinyin *pinyin = NULL;
            if (m_pinyin_len == m_cursor - 1) {
                pinyin = isPinyin (ID (m_text[m_pinyin_len]));
            }
            else {
                pinyin = isPinyin (ID (m_text[m_pinyin_len]), ID (m_text[m_pinyin_len + 1]));
                if (pinyin == NULL)
                    pinyin = isPinyin (ID (m_text[m_pinyin_len]));
            }
            if (pinyin == NULL)
                break;
            if (pinyin->flags & PINYIN_INCOMPLETE_PINYIN) {
                m_pinyin.append (pinyin, m_pinyin_len, 1);
                m_pinyin_len += 1;
            }
            else {
                m_pinyin.append (pinyin, m_pinyin_len, 2);
                m_pinyin_len += 2;
            }
        }
        if (len == m_pinyin_len)
            return retval;
        return TRUE;
    }
    return retval;
}

void
DoublePinyinEditor::updateAuxiliaryTextAfter (String &buffer)
{
    if (G_LIKELY (!m_config.doublePinyinShowRaw ()))
        return;

    if (G_LIKELY (m_config.orientation () == IBUS_ORIENTATION_HORIZONTAL)) {
        buffer << "        [ ";
    }
    else {
        buffer << "\n[ ";
    }
    
    if (G_LIKELY (m_cursor == m_text.length ())) {
        m_buffer << m_text << " ]";
    }
    else {
        buffer.append (m_text.c_str (), m_cursor);
        buffer << " ";
        buffer.append (m_text.c_str () + m_cursor);
        buffer << " ]";
    }
}

gboolean
DoublePinyinEditor::processKeyEvent (guint keyval, guint keycode, guint modifiers)
{
    /* handle ';' key */
    if (G_UNLIKELY (keyval == IBUS_semicolon)) {
        if (CMSHM_FILTER (modifiers) == 0) {
            if (insert (keyval))
                return TRUE;
        }
    }

    return PinyinEditor::processKeyEvent (keyval, keycode, modifiers);
}

};


