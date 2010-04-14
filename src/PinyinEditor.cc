#include "Config.h"
#include "PinyinEditor.h"
#include "SimpTradConverter.h"
#include "HalfFullConverter.h"

namespace PY {

#define MAX_PINYIN_LEN 64

/* init static members */
PinyinEditor::PinyinEditor (PinyinProperties & props)
    : Editor (props),
      m_pinyin (MAX_PHRASE_LEN),
      m_pinyin_len (0),
      m_buffer (64),
      m_lookup_table (Config::pageSize ()),
      m_phrase_editor (props)
{
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
 * process pinyin
 */
inline gboolean
PinyinEditor::processPinyin (guint keyval, guint keycode, guint modifiers)
{
    if (G_UNLIKELY (CMSHM_FILTER(modifiers) != 0))
        return m_text ? TRUE : FALSE;

    return insert (keyval);
}

/**
 * process numbers
 */
inline gboolean
PinyinEditor::processNumber (guint keyval, guint keycode, guint modifiers)
{
    guint i;

    if (!m_text)
        return FALSE;

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
        g_return_val_if_reached (FALSE);
    }
    if (modifiers == 0)
        selectCandidateInPage (i);
    else if ((modifiers & ~IBUS_LOCK_MASK) == IBUS_CONTROL_MASK)
        resetCandidateInPage (i);
    return TRUE;
}

inline gboolean
PinyinEditor::processSpace (guint keyval, guint keycode, guint modifiers)
{
    if (!m_text)
        return FALSE;
    if (CMSHM_FILTER (modifiers) != 0)
        return TRUE;
    if (m_selected_special_phrase.empty () &&
        m_phrase_editor.pinyinExistsAfterCursor ()) {
            selectCandidate (m_lookup_table.cursorPos ());
    }
    else {
        commit ();
    }
    return TRUE;
}

inline gboolean
PinyinEditor::processPunct (guint keyval, guint keycode, guint modifiers)
{
    if (m_text.empty ())
        return FALSE;

    if (CMSHM_FILTER (modifiers) != 0)
        return TRUE;

    switch (keyval) {
    case IBUS_apostrophe:
        return insert (keyval);
    case IBUS_comma:
        if (Config::commaPeriodPage ()) {
            pageUp ();
            return TRUE;
        }
        break;
    case IBUS_minus:
        if (Config::minusEqualPage ()) {
            pageUp ();
            return TRUE;
        }
        break;
    case IBUS_period:
        if (Config::commaPeriodPage ()) {
            pageDown ();
            return TRUE;
        }
        break;
    case IBUS_equal:
        if (Config::minusEqualPage ()) {
            pageDown ();
            return TRUE;
        }
        break;
    }

    if (Config::autoCommit ()) {
        if (m_phrase_editor.pinyinExistsAfterCursor ()) {
            selectCandidate (m_lookup_table.cursorPos ());
        }
        commit ();
        return FALSE;
    }
    return TRUE;
}

inline gboolean
PinyinEditor::processOthers (guint keyval, guint keycode, guint modifiers)
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
        case IBUS_Shift_L:
            if (Config::shiftSelectCandidate ()) {
                selectCandidateInPage (1);
            }
            break;

        case IBUS_Shift_R:
            if (Config::shiftSelectCandidate ()) {
                selectCandidateInPage (2);
            }
            break;

        case IBUS_Return:
        case IBUS_KP_Enter:
            commit ();
            break;

        case IBUS_BackSpace:
            if (m_phrase_editor.unselectCandidates ()) {
                update ();
            }
            else {
                removeCharBefore ();
            }
            break;

        case IBUS_Delete:
        case IBUS_KP_Delete:
            removeCharAfter ();
            break;

        case IBUS_Left:
        case IBUS_KP_Left:
            if (m_phrase_editor.unselectCandidates ()) {
                update ();
            }
            else {
                moveCursorLeft ();
            }
            break;

        case IBUS_Right:
        case IBUS_KP_Right:
            if (m_phrase_editor.unselectCandidates ()) {
                update ();
            }
            else {
                moveCursorRight ();
            }
            break;

        case IBUS_Home:
        case IBUS_KP_Home:
            if (m_phrase_editor.unselectCandidates ()) {
                update ();
            }
            else {
                moveCursorToBegin ();
            }
            break;

        case IBUS_End:
        case IBUS_KP_End:
            if (m_phrase_editor.unselectCandidates ()) {
                update ();
            }
            else {
                moveCursorToEnd ();
            }
            break;

        case IBUS_Up:
        case IBUS_KP_Up:
            cursorUp (); break;

        case IBUS_Down:
        case IBUS_KP_Down:
            cursorDown (); break;

        case IBUS_Page_Up:
        case IBUS_KP_Page_Up:
            pageUp (); break;

        case IBUS_Page_Down:
        case IBUS_KP_Page_Down:
            pageDown (); break;

        case IBUS_Escape:
            reset (); break;
        default:
            break;
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
            break;

        case IBUS_Delete:
        case IBUS_KP_Delete:
            removeWordAfter ();
            break;

        case IBUS_Left:
        case IBUS_KP_Left:
            if (m_phrase_editor.unselectCandidates ()) {
                update ();
            }
            else {
                moveCursorLeftByWord ();
            }
            break;

        case IBUS_Right:
        case IBUS_KP_Right:
            if (m_phrase_editor.unselectCandidates ()) {
                update ();
            }
            else {
                moveCursorToEnd ();
            }
            break;

        default:
            break;
        };
    }
    return TRUE;
}

gboolean
PinyinEditor::processKeyEvent (guint keyval, guint keycode, guint modifiers)
{
    modifiers &= (IBUS_SHIFT_MASK |
                  IBUS_CONTROL_MASK |
                  IBUS_MOD1_MASK |
                  IBUS_SUPER_MASK |
                  IBUS_HYPER_MASK |
                  IBUS_META_MASK |
                  IBUS_LOCK_MASK);

    switch (keyval) {
    /* letters */
    case IBUS_a ... IBUS_z:
        return processPinyin (keyval, keycode, modifiers);
    case IBUS_0 ... IBUS_9:
    case IBUS_KP_0 ... IBUS_KP_9:
        return processNumber (keyval, keycode, modifiers);
    case IBUS_exclam ... IBUS_slash:
    case IBUS_colon ... IBUS_at:
    case IBUS_bracketleft ... IBUS_quoteleft:
    case IBUS_braceleft ... IBUS_asciitilde:
        return processPunct (keyval, keycode, modifiers);
    /* space */
    case IBUS_space:
        return processSpace (keyval, keycode, modifiers);
    /* others */
    default:
        return processOthers (keyval, keycode, modifiers);
    }
}

void
PinyinEditor::updatePreeditText (void)
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
                    m_buffer << textAfterPinyin (edit_end);
                }
                else {
                    guint candidate_end = edit_begin + candidate.len;
                    m_buffer << m_pinyin[edit_begin]->sheng << m_pinyin[edit_begin]->yun;

                    for (guint i = edit_begin + 1; i < candidate_end; i++) {
                        m_buffer << ' ' << m_pinyin[i]->sheng << m_pinyin[i]->yun;
                    }
                    m_buffer << ' ' << textAfterPinyin (candidate_end);
                    edit_end = m_buffer.utf8Length ();
                }
            }
        }
        else {
            m_buffer << textAfterPinyin ();
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
PinyinEditor::updateAuxiliaryText (void)
{
    /* clear pinyin array */
    if (G_UNLIKELY (m_text.empty () ||
        m_phrase_editor.cursor () == m_pinyin.size ())) {
        hideAuxiliaryText ();
        return;
    }

    m_buffer.clear ();

    updateAuxiliaryTextBefore (m_buffer);

    if (m_selected_special_phrase.empty ()) {
        if (m_lookup_table.cursorPos () < m_special_phrases.size ()) {
            guint begin = m_phrase_editor.cursorInChar ();
            m_buffer << m_text.substr (begin, m_cursor - begin)
                     << '|' << textAfterCursor ();
        }
        else {
            for (guint i = m_phrase_editor.cursor (); i < m_pinyin.size (); ++i) {
                if (G_LIKELY (i != m_phrase_editor.cursor ()))
                    m_buffer << ' ';
                const Pinyin *p = m_pinyin[i];
                m_buffer << p->sheng
                         << p->yun;
            }

            if (G_UNLIKELY (m_pinyin_len == m_cursor)) {
                /* aux = pinyin + non-pinyin */
                // cursor_pos =  m_buffer.utf8Length ();
                m_buffer << '|' << textAfterPinyin ();
            }
            else {
                /* aux = pinyin + ' ' + non-pinyin before cursor + non-pinyin after cursor */
                m_buffer << ' ';
                m_buffer.append (textAfterPinyin (),
                             m_cursor - m_pinyin_len);
                // cursor_pos =  m_buffer.utf8Length ();
                m_buffer  << '|' << textAfterCursor ();
            }
        }
    }
    else {
        if (m_cursor < m_text.size ()) {
            m_buffer  << '|' << textAfterCursor ();
        }
    }

    updateAuxiliaryTextAfter (m_buffer);

    StaticText aux_text (m_buffer);
    Editor::updateAuxiliaryText (aux_text, TRUE);
}

void
PinyinEditor::updateLookupTable (void)
{
    m_lookup_table.clear ();
    m_lookup_table.setPageSize (Config::pageSize ());
    m_lookup_table.setOrientation (Config::orientation ());

    fillLookupTableByPage ();
    if (m_lookup_table.size ()) {
        Editor::updateLookupTable (m_lookup_table, TRUE);
    }
    else {
        hideLookupTable ();
    }
}

inline gboolean
PinyinEditor::fillLookupTableByPage (void)
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
            if (G_LIKELY (m_props.modeSimp () || !Config::tradCandidate ())) {
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
PinyinEditor::pageUp (void)
{
    if (G_LIKELY (m_lookup_table.pageUp ())) {
        updateLookupTableFast (m_lookup_table, TRUE);
        updatePreeditText ();
        updateAuxiliaryText ();
    }
}

void
PinyinEditor::pageDown (void)
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
PinyinEditor::cursorUp (void)
{
    if (G_LIKELY (m_lookup_table.cursorUp ())) {
        updateLookupTableFast (m_lookup_table, TRUE);
        updatePreeditText ();
        updateAuxiliaryText ();
    }
}

void
PinyinEditor::cursorDown (void)
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
PinyinEditor::candidateClicked (guint index, guint button, guint state)
{
   selectCandidateInPage (index);
}

void
PinyinEditor::updateAuxiliaryTextBefore (String &buffer)
{
}

void
PinyinEditor::updateAuxiliaryTextAfter (String &buffer)
{
}

void
PinyinEditor::reset (void)
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
PinyinEditor::update (void)
{
    updateLookupTable ();
    updatePreeditText ();
    updateAuxiliaryText ();
}

inline void
PinyinEditor::commit (const gchar *str)
{
    StaticText text(str);
    commitText (text);
}

void
PinyinEditor::commit (void)
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

    if (G_UNLIKELY (m_props.modeFull ())) {
        while (*p != '\0') {
            m_buffer.appendUnichar (HalfFullConverter::toFull (*p++));
        }
    }
    else {
        m_buffer << p;
    }
    m_phrase_editor.commit ();
    reset ();
    commit ((const gchar *)m_buffer);
}

inline gboolean
PinyinEditor::selectCandidate (guint i)
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

inline gboolean
PinyinEditor::selectCandidateInPage (guint i)
{
    guint page_size = m_lookup_table.pageSize ();
    guint cursor_pos = m_lookup_table.cursorPos ();

    if (G_UNLIKELY (i >= page_size))
        return FALSE;
    i += (cursor_pos / page_size) * page_size;

    return selectCandidate (i);
}

inline gboolean
PinyinEditor::resetCandidate (guint i)
{
    if (m_phrase_editor.resetCandidate (i)) {
        update ();
    }
    return TRUE;
}

inline gboolean
PinyinEditor::resetCandidateInPage (guint i)
{
    guint page_size = m_lookup_table.pageSize ();
    guint cursor_pos = m_lookup_table.cursorPos ();
    i += (cursor_pos / page_size) * page_size;

    return resetCandidate (i);
}

};

