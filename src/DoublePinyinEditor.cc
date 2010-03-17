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

#define ID_TO_SHENG(id) \
    double_pinyin_map[Config::doublePinyinSchema ()].sheng[id]
#define ID_TO_YUNS(id) \
    double_pinyin_map[Config::doublePinyinSchema ()].yun[id]

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


gboolean
DoublePinyinEditor::insert (gint ch)
{
    const Pinyin *pinyin;
    gint id;
    /* is full */
    if (G_UNLIKELY (m_text.length () >= MAX_PINYIN_LEN))
        return TRUE;

    id = _id (ch);
    if (id == -1) {
        /* it is not availidate ch */
        return FALSE;
    }

    if (G_UNLIKELY (m_text.isEmpty () && ID_TO_SHENG(id) == PINYIN_ID_VOID)) {
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
            if ((pinyin = isPinyin (_id (m_text[m_cursor - 2]), id)) == NULL) {
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
                    if ((pinyin = isPinyin (_id (m_text[m_cursor - 2]), id)) != NULL) {
                        m_pinyin.pop ();
                        m_pinyin.append (pinyin, m_pinyin_len - 1, 2);
                        m_pinyin_len = m_cursor;
                        break;
                    }
                }
            }
            if ((pinyin = isPinyin (id)) == NULL) {
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
    if (pinyin->flags & PINYIN_INCOMPLETE_PINYIN) {
        m_pinyin_len = m_cursor;
    }
    else {
        if ((pinyin = isPinyin (_id (m_text[m_cursor - 1]))) != NULL) {
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

    if (pinyin->flags & PINYIN_INCOMPLETE_PINYIN) {
        m_text.erase (m_cursor - 1, 1);
        m_cursor -= 1;
        m_pinyin_len -= 1;
    }
    else {
        m_text.erase (m_cursor - 2, 2);
        m_cursor -= 2;
        m_pinyin_len -= 2;
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
        if ((pinyin = isPinyin (_id (m_text[m_cursor - 1]))) != NULL) {
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
            if ((pinyin = isPinyin (_id (m_text[m_cursor - 2]),
                                    _id (m_text[m_cursor - 1]))) == NULL) {
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
                    if ((pinyin = isPinyin (_id (m_text[m_cursor - 2]),
                                            _id (m_text[m_cursor -1]))) != NULL) {
                        m_pinyin.pop ();
                        m_pinyin.append (pinyin, m_pinyin_len - 1, 2);
                        m_pinyin_len = m_cursor;
                        break;
                    }
                }
            }
            if ((pinyin = isPinyin (_id (m_text[m_cursor - 1]))) == NULL) {
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
            pinyin = isPinyin (_id (m_text[m_pinyin_len]));
        }
        else {
            pinyin = isPinyin (m_text[m_pinyin_len], m_text[m_pinyin_len + 1]);
            if (pinyin == NULL)
                pinyin =  isPinyin ( _id (m_text[m_pinyin_len]));
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


