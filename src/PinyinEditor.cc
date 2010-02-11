#include "Config.h"
#include "PinyinEditor.h"
#include "SimpTradConverter.h"
#include "HalfFullConverter.h"

namespace PY {

#define MAX_PINYIN_LEN 64

/* init static members */
PinyinParser PinyinEditor::m_parser;

PinyinEditor::PinyinEditor (PinyinProperties & props)
    : m_pinyin (MAX_PHRASE_LEN),
      m_pinyin_len (0),
      m_buffer (64),
      m_lookup_table (Config::pageSize ()),
      m_phrase_editor (props),
      Editor (props)
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

    insert (keyval);
    return TRUE;
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
    else if ((modifiers & ~ IBUS_LOCK_MASK) == IBUS_CONTROL_MASK)
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

    if (m_phrase_editor.pinyinExistsAfterCursor ()) {
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
    if (m_text.isEmpty ())
        return FALSE;

    if (CMSHM_FILTER (modifiers) != 0)
        return TRUE;

    switch (keyval) {
    case IBUS_apostrophe:
        insert (keyval);
        return TRUE;
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
    if (m_text.isEmpty ())
        return FALSE;

    /* ignore numlock */
    modifiers = CMSHM_FILTER (modifiers);

    if (modifiers != 0 && modifiers != IBUS_CONTROL_MASK)
        return TRUE;


    /* process some cursor control keys */
    gboolean _update = FALSE;
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
            removeCharBefore ();
            break;

        case IBUS_Delete:
        case IBUS_KP_Delete:
            removeCharAfter ();
            break;

        case IBUS_Left:
        case IBUS_KP_Left:
            moveCursorLeft ();
            break;

        case IBUS_Right:
        case IBUS_KP_Right:
            moveCursorRight ();
            break;

        case IBUS_Home:
        case IBUS_KP_Home:
            moveCursorToBegin ();
            break;

        case IBUS_End:
        case IBUS_KP_End:
            moveCursorToEnd ();
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
            removeWordBefore ();
            break;

        case IBUS_Delete:
        case IBUS_KP_Delete:
            removeWordAfter ();
            break;

        case IBUS_Left:
        case IBUS_KP_Left:
            moveCursorLeftByWord ();
            break;

        case IBUS_Right:
        case IBUS_KP_Right:
            moveCursorToEnd ();
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
    gboolean result = FALSE;

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
    if (G_UNLIKELY (m_phrase_editor.isEmpty () && m_text.isEmpty ())) {
        hidePreeditText ();
        return;
    }

    if (m_cursor == m_text.length ())
        updatePreeditTextInTypingMode ();
    else
        updatePreeditTextInEditingMode ();
}

inline void
PinyinEditor::updatePreeditTextInTypingMode (void)
{
    m_buffer.truncate (0);

    /* add select phrases */
    if (G_UNLIKELY (m_phrase_editor.selectedString ())) {
        m_buffer << m_phrase_editor.selectedString ();
    }

    /* add highlight candidate */
    guint candidate_begin = m_buffer.utf8Length ();
    guint candidate_length = 0;
    if (m_phrase_editor.candidates ().length () > 0) {
        if (m_lookup_table.cursorPos () == 0 && !m_props.modeSimp ()) {
            const PhraseArray & phrases = m_phrase_editor.candidate0 ();
            candidate_length = 0;
            for (guint i = 0; i < phrases.length (); i++) {
                candidate_length += phrases[i].len;
                SimpTradConverter::simpToTrad (phrases[i], m_buffer);
            }
        }
        else {
            const Phrase & candidate = m_phrase_editor.candidate (m_lookup_table.cursorPos ());
            candidate_length = candidate.len;
            if (m_props.modeSimp ())
                m_buffer << candidate;
            else
                SimpTradConverter::simpToTrad (candidate, m_buffer);
        }
    }

    /* add rest text */
    const PinyinArray & pinyin = m_phrase_editor.pinyin ();
    if (candidate_begin + candidate_length < pinyin.length ())
        m_buffer << ((const gchar *) textAfterPinyin (
                                                candidate_begin + candidate_length));
    else
        m_buffer << ((const gchar *) textAfterPinyin ());

    StaticText preedit_text (m_buffer);
    /* underline */
    preedit_text.appendAttribute (IBUS_ATTR_TYPE_UNDERLINE, IBUS_ATTR_UNDERLINE_SINGLE, 0, -1);

    /* candidate */
    if (candidate_length != 0) {
        preedit_text.appendAttribute (IBUS_ATTR_TYPE_FOREGROUND, 0x00000000,
                candidate_begin, candidate_begin + candidate_length);
        preedit_text.appendAttribute (IBUS_ATTR_TYPE_BACKGROUND, 0x00c8c8f0,
                candidate_begin, candidate_begin + candidate_length);
    }
    // ibus_engine_update_preedit_text (m_engine, preedit_text, m_buffer.utf8Length (), TRUE);
    Editor::updatePreeditText (preedit_text, candidate_begin, TRUE);
}

inline void
PinyinEditor::updatePreeditTextInEditingMode (void)
{
    m_buffer.truncate (0);

    /* add select phrases */
    if (G_UNLIKELY (m_phrase_editor.selectedString ())) {
        m_buffer << m_phrase_editor.selectedString ();
    }

    /* add highlight candidate */
    const PinyinArray & pinyin = m_phrase_editor.pinyin ();
    guint candidate_begin = m_buffer.utf8Length ();
    guint candidate_length = 0;
    guint candidate_pinyin_end = 0;
    if (m_phrase_editor.candidates ().length () > 0) {
        const Phrase & candidate = m_phrase_editor.candidate (m_lookup_table.cursorPos ());
        candidate_length = candidate.len;

        m_buffer << pinyin[candidate_begin]->sheng << pinyin[candidate_begin]->yun;

        for (guint i = 1; i < candidate_length; i++) {
            m_buffer << ' ' << pinyin[candidate_begin + i]->sheng << pinyin[candidate_begin + i]->yun;
        }
        candidate_pinyin_end = m_buffer.utf8Length ();
    }

    /* add rest text */
    if (candidate_begin + candidate_length < pinyin.length ()) {
        if (m_buffer)
            m_buffer << ' ' ;
        m_buffer << textAfterPinyin (candidate_begin + candidate_length);
    }
    else {
        const gchar * p = textAfterPinyin ();
        if (*p != '\0') {
            if (m_buffer)
                m_buffer << ' ';
            m_buffer << p;
        }
    }

    StaticText preedit_text (m_buffer);
    /* underline */
    preedit_text.appendAttribute (IBUS_ATTR_TYPE_UNDERLINE, IBUS_ATTR_UNDERLINE_SINGLE, 0, -1);

    /* candidate */
    if (candidate_length != 0) {
        preedit_text.appendAttribute (IBUS_ATTR_TYPE_FOREGROUND, 0x00000000,
                candidate_begin, candidate_pinyin_end);
        preedit_text.appendAttribute (IBUS_ATTR_TYPE_BACKGROUND, 0x00c8c8f0,
                candidate_begin, candidate_pinyin_end);
    }
    // ibus_engine_update_preedit_text (m_engine, preedit_text, m_buffer.utf8Length (), TRUE);
    Editor::updatePreeditText (preedit_text, candidate_begin, TRUE);
}

void
PinyinEditor::updateAuxiliaryText (void)
{
    /* clear pinyin array */
    if (G_UNLIKELY (m_text.isEmpty () ||
        m_phrase_editor.cursor () == m_pinyin.length ())) {
        hideAuxiliaryText ();
        return;
    }

    // guint cursor_pos;
    m_buffer.truncate (0);
    for (guint i = m_phrase_editor.cursor (); i < m_pinyin.length (); ++i) {
        if (G_LIKELY (i != m_phrase_editor.cursor ()))
            m_buffer << ' ';
        const Pinyin *p = m_pinyin[i];
        m_buffer << p->sheng;
        m_buffer << p->yun;
    }

    if (G_UNLIKELY (m_pinyin_len == m_cursor)) {
        /* aux = pinyin + non-pinyin */
        // cursor_pos =  m_buffer.utf8Length ();
        m_buffer << '|' << textAfterPinyin ();
    }
    else {
        /* aux = pinyin + non-pinyin before cursor + non-pinyin after cursor */
        m_buffer.append (textAfterPinyin (),
                     m_cursor - m_pinyin_len);
        // cursor_pos =  m_buffer.utf8Length ();
        m_buffer  << '|' << textAfterCursor ();
    }

    StaticText aux_text (m_buffer);
    Editor::updateAuxiliaryText (aux_text, TRUE);
}

void
PinyinEditor::updateLookupTable (void)
{
    m_lookup_table.clear ();
    m_lookup_table.setPageSize (Config::pageSize ());

    guint candidate_nr = m_phrase_editor.candidates ().length ();

    if (G_UNLIKELY (candidate_nr == 0)) {
        hideLookupTable ();
        return;
    }

    if (G_LIKELY (m_props.modeSimp () || !Config::tradCandidate ())) {
        for (guint i = 0; i < candidate_nr; i++) {
            StaticText text (m_phrase_editor.candidate (i));
            if (m_phrase_editor.candidateIsUserPhease (i))
                text.appendAttribute (IBUS_ATTR_TYPE_FOREGROUND, 0x000000ef, 0, -1);
            m_lookup_table.appendCandidate (text);
        }
    }
    else {
        for (guint i = 0; i < candidate_nr; i++) {
            m_buffer.truncate (0);
            SimpTradConverter::simpToTrad (m_phrase_editor.candidate (i), m_buffer);
            Text text (m_buffer);
            if (m_phrase_editor.candidateIsUserPhease (i))
                text.appendAttribute (IBUS_ATTR_TYPE_FOREGROUND, 0x000000ef, 0, -1);
            m_lookup_table.appendCandidate (text);
        }
    }

    updateLookupTableFast (m_lookup_table, TRUE);
}

void
PinyinEditor::pageUp (void)
{
    if (m_lookup_table.pageUp ()) {
        updateLookupTableFast (m_lookup_table, TRUE);
        updatePreeditText ();
    }
}

void
PinyinEditor::pageDown (void)
{
    if (m_lookup_table.pageDown ()) {
        updateLookupTableFast (m_lookup_table, TRUE);
        updatePreeditText ();
    }
}

void
PinyinEditor::cursorUp (void)
{
    if (m_lookup_table.cursorUp ()) {
        updateLookupTableFast (m_lookup_table, TRUE);
        updatePreeditText ();
    }
}

void
PinyinEditor::cursorDown (void)
{
    if (m_lookup_table.cursorDown ()) {
        updateLookupTableFast (m_lookup_table, TRUE);
        updatePreeditText ();
    }
}

void
PinyinEditor::candidateClicked (guint index, guint button, guint state)
{
   selectCandidateInPage (index);
}

void
PinyinEditor::update (void)
{
    updatePreeditText ();
    updateAuxiliaryText ();
    updateLookupTable ();
}

void
PinyinEditor::updatePhraseEditor (void)
{
    m_phrase_editor.update (m_pinyin);
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
    if (G_UNLIKELY (isEmpty ()))
        return;

    m_buffer.truncate (0);
    m_buffer << m_phrase_editor.selectedString ();

    const gchar *p = textAfterPinyin (m_buffer.utf8Length ());
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
    if (m_phrase_editor.selectCandidate (i)) {
        if ((!m_phrase_editor.pinyinExistsAfterCursor ()) &&
            *textAfterPinyin () == '\0') {
            commit ();
        }
        else
            update ();
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

