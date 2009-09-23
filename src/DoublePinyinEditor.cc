#include "Config.h"
#include "DoublePinyinEditor.h"

namespace PY {

#include "DoublePinyinTable.h"

DoublePinyinEditor::DoublePinyinEditor (void)
{
}

static inline gint
char_to_id (gint ch)
{
    switch (ch) {
    case IBUS_a ... IBUS_z:
        return ch - IBUS_a;
    case IBUS_semicolon:
        return 26;
    default:
        return -1;
    }
}

inline const Pinyin *
DoublePinyinEditor::isPinyin (gchar i, gchar j)
{
    const Pinyin *pinyin;
    gint schema = Config::doublePinyinSchema ();
    gint sheng = double_pinyin_map[schema].sheng[char_to_id(i)];
    const gint *yun = double_pinyin_map[schema].yun[char_to_id(j)];

    if (sheng == PINYIN_ID_VOID || yun[0] == PINYIN_ID_VOID)
        return NULL;

    if (sheng == PINYIN_ID_ZERO && yun[0] == PINYIN_ID_ZERO)
        return NULL;

    pinyin = m_parser.isPinyin (sheng, yun[0], Config::option () & PINYIN_FUZZY_ALL);
    if (pinyin == NULL && yun[1] != PINYIN_ID_ZERO)
        pinyin = m_parser.isPinyin (sheng, yun[1], Config::option () & PINYIN_FUZZY_ALL);
    return pinyin;
}

gboolean
DoublePinyinEditor::insert (gint ch)
{
    /* is full */
    if (G_UNLIKELY (m_text.length () >= MAX_PINYIN_LEN))
        return FALSE;

    gint i = char_to_id (ch);
    if (i < 0)
        return FALSE;

    m_text.insert (m_cursor++, ch);

    if (m_cursor != m_pinyin_len + 2)
        return TRUE;

    const Pinyin *pinyin = isPinyin (m_text[m_cursor - 2], ch);
    if (pinyin == NULL)
        return TRUE;
    m_pinyin << pinyin;
    m_pinyin_len += 2;
    return TRUE;
}

gboolean
DoublePinyinEditor::removeCharBefore (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    m_cursor --;
    m_text.erase (m_cursor, 1);

    if (m_cursor < m_pinyin_len) {
        m_pinyin.pop ();
        m_pinyin_len -= 2;
    }

    return TRUE;
}

gboolean
DoublePinyinEditor::removeCharAfter (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_text.erase (m_cursor, 1);

    return TRUE;
}

gboolean
DoublePinyinEditor::removeWordBefore (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    guint cursor;

    if (G_UNLIKELY (m_cursor > m_pinyin_len)) {
        cursor = m_pinyin_len;
    }
    else {
        m_pinyin.pop ();
        cursor = m_cursor - 2;
        m_pinyin_len -= 2;
    }

    m_text.erase (cursor, m_cursor - cursor);
    m_cursor = cursor;
    return TRUE;
}

gboolean
DoublePinyinEditor::removeWordAfter (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_text.erase (m_cursor, -1);
    return TRUE;
}

gboolean
DoublePinyinEditor::moveCursorLeft (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;
    m_cursor --;

    if (m_cursor >= m_pinyin_len)
        return TRUE;

    m_pinyin.pop ();
    m_pinyin_len -= 2;
    return TRUE;
}

gboolean
DoublePinyinEditor::moveCursorRight (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_cursor ++;
    updatePinyin ();

    return TRUE;
}

gboolean
DoublePinyinEditor::moveCursorLeftByWord (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    if (G_UNLIKELY (m_cursor > m_pinyin_len)) {
        m_cursor = m_pinyin_len;
        return TRUE;
    }

    m_pinyin.pop ();
    m_cursor -= 2;
    m_pinyin_len -= 2;
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

    return TRUE;
}

gboolean
DoublePinyinEditor::moveCursorToEnd (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_cursor = m_text.length ();
    updatePinyin  ();

    return TRUE;
}
gboolean
DoublePinyinEditor::reset (void)
{
        gboolean retval = FALSE;
        if (m_cursor != 0) {
            m_cursor = 0;
            retval = TRUE;
        }

        if (m_text.length () != 0) {
            m_text.truncate (0);
            retval = TRUE;
        }

        if (retval)
            updatePinyin ();

        return retval;
    }


void
DoublePinyinEditor::updatePinyin (void)
{
    if (G_UNLIKELY (m_text.isEmpty ())) {
        m_pinyin.removeAll ();
        m_pinyin_len = 0;
        return;
    }

    m_pinyin.removeAll ();
    m_pinyin_len = 0;
    for (guint i = 0; i + 1 < m_cursor; i+= 2) {
        const Pinyin *pinyin = isPinyin (m_text[i], m_text[i + 1]);
        if (pinyin == NULL)
            break;
        m_pinyin << pinyin;
        m_pinyin_len += 2;
    }
}

};


