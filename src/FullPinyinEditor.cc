#include "Config.h"
#include "FullPinyinEditor.h"

namespace PY {

FullPinyinEditor::FullPinyinEditor (PinyinProperties & props)
    : PinyinEditor (props)
{
}

FullPinyinEditor::~FullPinyinEditor (void)
{
}

void
FullPinyinEditor::reset (void)
{
    PinyinEditor::reset ();
}

gboolean
FullPinyinEditor::insert (gint ch)
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
FullPinyinEditor::removeCharBefore (void)
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
FullPinyinEditor::removeCharAfter (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_text.erase (m_cursor, 1);
    updatePreeditText ();
    updateAuxiliaryText ();

    return TRUE;
}

gboolean
FullPinyinEditor::removeWordBefore (void)
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
FullPinyinEditor::removeWordAfter (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_text.erase (m_cursor, -1);
    updatePreeditText ();
    updateAuxiliaryText ();
    return TRUE;
}

gboolean
FullPinyinEditor::moveCursorLeft (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    m_cursor --;
    updateSpecialPhrases ();
    updatePinyin ();

    return TRUE;
}

gboolean
FullPinyinEditor::moveCursorRight (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_cursor ++;

    updateSpecialPhrases ();
    updatePinyin ();

    return TRUE;
}

gboolean
FullPinyinEditor::moveCursorLeftByWord (void)
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
FullPinyinEditor::moveCursorRightByWord (void)
{
    return moveCursorToEnd ();
}

gboolean
FullPinyinEditor::moveCursorToBegin (void)
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
FullPinyinEditor::moveCursorToEnd (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_cursor = m_text.length ();
    updateSpecialPhrases ();
    updatePinyin ();

    return TRUE;
}

void
FullPinyinEditor::updatePinyin (void)
{
    if (G_UNLIKELY (m_text.empty ())) {
        m_pinyin.clear ();
        m_pinyin_len = 0;
    }
    else {
        m_pinyin_len = PinyinParser::parse (m_text,              // text
                                            m_cursor,            // text length
                                            Config::option (),   // option
                                            m_pinyin,            // result
                                            MAX_PHRASE_LEN);     // max result length
    }

    updatePhraseEditor ();
    update ();
}

};
