#include "Config.h"
#include "DoublePinyinEditor.h"

namespace PY {

#include "DoublePinyinTable.h"

DoublePinyinEditor::DoublePinyinEditor (PinyinProperties & props)
    : PinyinEditor (props)
{
}

static inline gint
_id (gint ch)
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
DoublePinyinEditor::isPinyin (gchar i)
{
    if ((Config::option () & PINYIN_INCOMPLETE_PINYIN) == 0) {
        return NULL;
    }

    gint schema = Config::doublePinyinSchema ();
    gint sheng = double_pinyin_map[schema].sheng[_id (i)];

    if (sheng == PINYIN_ID_VOID) {
        return NULL;
    }

    return m_parser.isPinyin (sheng, 0, PINYIN_INCOMPLETE_PINYIN);
}

inline const Pinyin *
DoublePinyinEditor::isPinyin (gchar i, gchar j)
{
    const Pinyin *pinyin = NULL;
    gint schema = Config::doublePinyinSchema ();
    gint sheng = double_pinyin_map[schema].sheng[_id (i)];
    const gint *yun = double_pinyin_map[schema].yun[_id (j)];

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


gboolean
DoublePinyinEditor::insert (gint ch)
{
    const Pinyin *pinyin;
    /* is full */
    if (G_UNLIKELY (m_text.length () >= MAX_PINYIN_LEN))
        return FALSE;

    if (_id (ch) < 0) {
        /* it is not availidate ch */
        return FALSE;
    }

    m_text.insert (m_cursor++, ch);

    if (m_cursor > m_pinyin_len + 2) {
        updatePreeditText ();
        updateAuxiliaryText ();
        return TRUE;
    }

    do {
        if (m_cursor == m_pinyin_len + 2) {
            if ((pinyin = isPinyin (m_text[m_cursor - 2], ch)) == NULL) {
                updatePreeditText ();
                updateAuxiliaryText ();
                return TRUE;
            }
            m_pinyin.append (pinyin, m_pinyin_len, 2);
            m_pinyin_len = m_cursor;
            break;
        }
        if (m_cursor == m_pinyin_len + 1) {
            if (!m_pinyin.isEmpty ()) {
                pinyin = m_pinyin.back ();
                if (pinyin->flags & PINYIN_INCOMPLETE_PINYIN) {
                    /* prev pinyin is incomplete */
                    if ((pinyin = isPinyin (m_text[m_cursor - 2], ch)) != NULL) {
                        m_pinyin.pop ();
                        m_pinyin.append (pinyin, m_pinyin_len - 1, 2);
                        m_pinyin_len = m_cursor;
                        break;
                    }
                }
            }
            if ((pinyin = isPinyin (ch)) == NULL) {
                updatePreeditText ();
                updateAuxiliaryText ();
                return TRUE;
            }
            m_pinyin.append (pinyin, m_pinyin_len , 1);
            m_pinyin_len = m_cursor;
        }
    } while (0);

    /* update all */
    updatePhraseEditor ();
    update ();
    return TRUE;
}

gboolean
DoublePinyinEditor::removeCharBefore (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    m_cursor --;
    m_text.erase (m_cursor, 1);

    if (m_cursor >= m_pinyin_len) {
        updatePreeditText ();
        updateAuxiliaryText ();
        return TRUE;
    }

    const Pinyin *pinyin = m_pinyin.back ();
    m_pinyin.pop ();
    if ((pinyin->flags & PINYIN_INCOMPLETE_PINYIN) != 0) {
        m_pinyin_len = m_cursor;
    }
    else {
        if ((pinyin = isPinyin (m_text[m_cursor - 1])) != NULL) {
            m_pinyin.append (pinyin, m_cursor - 1, 1);
            m_pinyin_len = m_cursor;
        }
        else {
            m_pinyin_len = m_cursor - 1;
        }
    }

    updatePhraseEditor ();
    update ();
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
        return TRUE;
    }

    const Pinyin *pinyin = m_pinyin.back ();
    m_pinyin.pop ();

    if ((pinyin->flags & PINYIN_INCOMPLETE_PINYIN) == 0) {
        m_text.erase (m_cursor - 2, 2);
        m_cursor -= 2;
        m_pinyin_len -= 2;
    }
    else {
        m_text.erase (m_cursor - 1, 1);
        m_cursor -= 1;
        m_pinyin_len -= 1;
    }

    updatePhraseEditor ();
    update ();
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
        return TRUE;
    }

    const Pinyin *pinyin = m_pinyin.back ();
    m_pinyin.pop ();

    if (pinyin->flags & PINYIN_INCOMPLETE_PINYIN) {
        m_pinyin_len -= 1;
    }
    else {
        if ((pinyin = isPinyin (m_text[m_cursor - 1])) != NULL) {
            m_pinyin.append (pinyin, m_cursor - 1, 1);
            m_pinyin_len = m_cursor;
        }
        else {
            m_pinyin_len -= 2;
        }
    }

    updatePhraseEditor ();
    update ();
    return TRUE;
}

gboolean
DoublePinyinEditor::moveCursorRight (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_cursor ++;
    if (m_cursor > m_pinyin_len + 2) {
        updatePreeditText ();
        updateAuxiliaryText ();
        return TRUE;
    }

    do {
        const Pinyin *pinyin = NULL;
        if (m_cursor == m_pinyin_len + 2) {
            if ((pinyin = isPinyin (m_text[m_cursor - 2], m_text[m_cursor - 1])) == NULL) {
                updatePreeditText ();
                updateAuxiliaryText ();
                return TRUE;
            }
            m_pinyin.append (pinyin, m_pinyin_len, 2);
            m_pinyin_len = m_cursor;
            break;
        }
        if (m_cursor == m_pinyin_len + 1) {
            if (!m_pinyin.isEmpty ()) {
                pinyin = m_pinyin.back ();
                if ((pinyin->flags & PINYIN_INCOMPLETE_PINYIN) != 0) {
                    /* prev pinyin is incomplete */
                    if ((pinyin = isPinyin (m_text[m_cursor - 2], m_text[m_cursor -1])) != NULL) {
                        m_pinyin.pop ();
                        m_pinyin.append (pinyin, m_pinyin_len - 1, 2);
                        m_pinyin_len = m_cursor;
                        break;
                    }
                }
            }
            if ((pinyin = isPinyin (m_text[m_cursor - 1])) == NULL) {
                updatePreeditText ();
                updateAuxiliaryText ();
                return TRUE;
            }
            m_pinyin.append (pinyin, m_pinyin_len, 2);
            m_pinyin_len = m_cursor;
        }
    } while (0);

    /* update all */
    updatePhraseEditor ();
    update ();
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
        return TRUE;
    }

    const Pinyin *pinyin = m_pinyin.back ();
    m_pinyin.pop ();
    if (pinyin->flags & PINYIN_INCOMPLETE_PINYIN) {
        m_cursor -= 1;
        m_pinyin_len -= 1;
    }
    else {
        m_cursor -= 2;
        m_pinyin_len -= 2;
    }

    updatePhraseEditor ();
    update ();

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

    if (m_cursor >= m_pinyin_len + 2) {
        m_cursor = m_text.length ();
        updatePreeditText ();
        updateAuxiliaryText ();
    }
    else {
        m_cursor = m_text.length ();
        updatePinyin  ();
    }
    return TRUE;
}

void
DoublePinyinEditor::reset (void)
{
    gboolean _update = FALSE;
    if (m_cursor != 0) {
        m_cursor = 0;
        _update = TRUE;
    }

    if (!m_text.isEmpty ()) {
        _update = TRUE;
        m_text.truncate (0);
    }

    if (!m_pinyin.isEmpty ()) {
        m_pinyin.removeAll ();
        m_pinyin_len = 0;
        updatePhraseEditor ();
        _update = TRUE;
    }

    if (_update) {
        update ();
    }
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

    while (m_pinyin_len < m_cursor) {
        const Pinyin *pinyin = NULL;

        if (m_pinyin_len == m_cursor - 1) {
            pinyin = isPinyin (m_text[m_pinyin_len]);
        }
        else {
            pinyin = isPinyin (m_text[m_pinyin_len], m_text[m_pinyin_len + 1]);
            if (pinyin == NULL)
                pinyin =  isPinyin (m_text[m_pinyin_len]);
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

    updatePhraseEditor ();
    update ();
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


