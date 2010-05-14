#include "Config.h"
#include "BopomofoEditor.h"
#include "SimpTradConverter.h"

namespace PY {

BopomofoEditor::BopomofoEditor (PinyinProperties & props)
    : PinyinEditor (props)
{
}

BopomofoEditor::~BopomofoEditor (void)
{
}

void
BopomofoEditor::reset (void)
{
    PinyinEditor::reset ();
}

gboolean
BopomofoEditor::insert (gint ch)
{
    /* is full */
    if (G_UNLIKELY (m_text.length () >= MAX_PINYIN_LEN))
        return TRUE;

    m_text.insert (m_cursor++, keyvalToBopomofo(ch));

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

gboolean
BopomofoEditor::processKeyEvent (guint keyval, guint keycode, guint modifiers)
{
    switch (keyval) {
    /* Bopomofo */
    case IBUS_a ... IBUS_z:
    case IBUS_0 ... IBUS_9:
    case IBUS_comma:
    case IBUS_period:
    case IBUS_slash:
    case IBUS_semicolon:
    case IBUS_minus:
        return processBopomofo (keyval, keycode, modifiers);

    default:
        return PinyinEditor::processKeyEvent (keyval, keycode, modifiers);
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

/**
 * process bopomofo
 */
inline gboolean
BopomofoEditor::processBopomofo (guint keyval, guint keycode, guint modifiers)
{
    if (G_UNLIKELY (CMSHM_FILTER(modifiers) != 0))
        return m_text ? TRUE : FALSE;

    return insert (keyval);
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
        for(String::iterator i = m_text.begin();i != m_text.end(); ++i) {
            bopomofo += bopomofo_char[keyvalToBopomofo(*i)];
        }

        m_pinyin_len = PinyinParser::parseBopomofo(bopomofo,            // bopomofo
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

    for (String::iterator i = m_text.begin(); i != m_text.end(); i++) {
        if (m_cursor == i - m_text.begin())
            m_buffer << '|';
        m_buffer.appendUnichar(bopomofo_char[keyvalToBopomofo(*i)]);
    }
    if (m_cursor == m_text.length())
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
        m_buffer.appendUnichar ((gunichar)bopomofo_char[keyvalToBopomofo(*p++)]);
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
                    if (m_cursor >= MAX_PHRASE_LEN) {
                        for (const gchar *p=m_text.c_str() + MAX_PHRASE_LEN; *p ;++p) {
                            m_buffer.appendUnichar(bopomofo_char[keyvalToBopomofo(*p)]);
                        }
                    }
                }
                else {
                    for (const gchar *p=m_text.c_str(); *p ;++p) {
                        if (p - m_text.c_str() == m_cursor)
                            m_buffer << ' ';
                        m_buffer.appendUnichar(bopomofo_char[keyvalToBopomofo(*p)]);
                    }
                    edit_end = m_buffer.utf8Length ();
                }
            }
        }
        else {
            for (const gchar *p=m_text.c_str() + m_pinyin_len; *p ;++p) {
                m_buffer.appendUnichar(bopomofo_char[keyvalToBopomofo(*p)]);
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
