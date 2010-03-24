#include "Config.h"
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
    (double_pinyin_map[Config::doublePinyinSchema ()].sheng[id])
#define ID_TO_YUNS(id) \
    (double_pinyin_map[Config::doublePinyinSchema ()].yun[id])

#define IS_ALPHA(c) \
        ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))

DoublePinyinEditor::DoublePinyinEditor (PinyinProperties & props)
    : PinyinEditor (props)
{
}

gboolean
DoublePinyinEditor::insert (gint ch)
{
    const Pinyin *pinyin;
    gint id;
    /* is full */
    if (G_UNLIKELY (m_text.length () >= MAX_PINYIN_LEN))
        return TRUE;

    id = ID (ch);
    if (id == -1) {
        /* it is not availidate ch */
        return FALSE;
    }

    if (G_UNLIKELY (m_text.isEmpty () &&
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
            updatePreeditText ();
            updateAuxiliaryText ();
            return TRUE;
        }
    }
    else {
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
        updatePhraseEditor ();
        update ();
    }
    else {
        updatePreeditText ();
        updateAuxiliaryText ();
    }
    return TRUE;
}

gboolean
DoublePinyinEditor::removeCharAfter (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_text.erase (m_cursor, 1);
    updatePreeditText ();
    updateAuxiliaryText ();
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
        updatePreeditText ();
        updateAuxiliaryText ();
    }
    else {
        m_cursor = m_pinyin_len = m_pinyin.back ().begin;
        m_pinyin.pop ();
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

    m_text.erase (m_cursor, -1);
    updatePreeditText ();
    updateAuxiliaryText ();
    return TRUE;
}

gboolean
DoublePinyinEditor::moveCursorLeft (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    m_cursor --;

    if (m_cursor >= m_pinyin_len) {
        updatePreeditText ();
        updateAuxiliaryText ();
    }
    else {
        if (updatePinyin (FALSE)) {
            updatePhraseEditor ();
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
DoublePinyinEditor::moveCursorRight (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_cursor ++;
    if (updatePinyin (FALSE)) {
        updatePhraseEditor ();
        update ();
    }
    else {
        updatePreeditText ();
        updateAuxiliaryText ();
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
        updatePreeditText ();
        updateAuxiliaryText ();
    }
    else {
        m_cursor = m_pinyin_len = m_pinyin.back ().begin;
        m_pinyin.pop ();
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
    m_pinyin.removeAll ();
    m_pinyin_len = 0;
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
        updatePhraseEditor ();
        update ();
    }
    else {
        updatePreeditText ();
        updateAuxiliaryText ();
    }
    return TRUE;
}

void
DoublePinyinEditor::reset (void)
{
    if (m_cursor != 0 ||
        m_text.isEmpty () == FALSE ||
        m_pinyin.isEmpty () == FALSE) {
        m_cursor = 0;
        m_text.truncate (0);
        m_pinyin.removeAll ();
        m_pinyin_len = 0;
        updatePhraseEditor ();
        update ();
    }
}

inline const Pinyin *
DoublePinyinEditor::isPinyin (gint i)
{
    if ((Config::option () & PINYIN_INCOMPLETE_PINYIN) == 0) {
        return NULL;
    }

    gint sheng = ID_TO_SHENG (i);

    if (sheng == PINYIN_ID_VOID) {
        return NULL;
    }

    return m_parser.isPinyin (sheng, 0, PINYIN_INCOMPLETE_PINYIN);
}

inline const Pinyin *
DoublePinyinEditor::isPinyin (gint i, gint j)
{
    const Pinyin *pinyin = NULL;
    gint sheng = ID_TO_SHENG (i);
    const gint *yun = ID_TO_YUNS (j);

    if (sheng == PINYIN_ID_VOID || yun[0] == PINYIN_ID_VOID)
        return pinyin;

    if (sheng == PINYIN_ID_ZERO && yun[0] == PINYIN_ID_ZERO)
        return pinyin;

    pinyin = m_parser.isPinyin (sheng, yun[0],
                        Config::option () & PINYIN_FUZZY_ALL);
    if (pinyin == NULL && yun[1] != PINYIN_ID_VOID)
        pinyin = m_parser.isPinyin (sheng, yun[1],
                        Config::option () & PINYIN_FUZZY_ALL);
    return pinyin;
}

inline gboolean
DoublePinyinEditor::updatePinyin (gboolean all)
{
    gboolean retval = FALSE;

    if (all &&
        (m_pinyin_len != 0 || !m_pinyin.isEmpty ())) {
        m_pinyin.removeAll ();
        m_pinyin_len = 0;
        retval = TRUE;
    }

    if (m_pinyin_len > m_cursor) {
        retval = TRUE;
        while (m_pinyin_len > m_cursor) {
            m_pinyin_len = m_pinyin.back ().begin;
            m_pinyin.pop ();
        }
    }

    if (m_pinyin_len == m_cursor) {
        return retval;
    }

    if (m_pinyin_len < m_cursor) {
        gint len = m_pinyin_len;
        if (m_pinyin.isEmpty () == FALSE &&
            m_pinyin.back ()->flags & PINYIN_INCOMPLETE_PINYIN) {
            const Pinyin *pinyin = isPinyin (ID (m_text[m_pinyin_len -1]),ID (m_text[m_pinyin_len]));
            if (pinyin) {
                m_pinyin.pop ();
                m_pinyin.append (pinyin, m_pinyin_len - 1, 2);
                m_pinyin_len += 1;
            }
        }
        while (m_pinyin_len < m_cursor && m_pinyin.length () < MAX_PHRASE_LEN) {
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
}

#define CMSHM_MASK              \
        (IBUS_CONTROL_MASK |    \
         IBUS_MOD1_MASK |       \
         IBUS_SUPER_MASK |      \
         IBUS_HYPER_MASK |      \
         IBUS_META_MASK)

#define CMSHM_FILTER(modifiers)  \
    (modifiers & (CMSHM_MASK))

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


