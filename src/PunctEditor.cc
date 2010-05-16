#include "PunctEditor.h"
#include <cstdio>

#define CMSHM_MASK              \
        (IBUS_CONTROL_MASK |    \
         IBUS_MOD1_MASK |       \
         IBUS_SUPER_MASK |      \
         IBUS_HYPER_MASK |      \
         IBUS_META_MASK)

#define CMSHM_FILTER(modifiers)  \
    (modifiers & (CMSHM_MASK))

namespace PY {

#include "PunctTable.h"

PunctEditor::PunctEditor (PinyinProperties & props)
    : Editor (props),
      m_punct_mode (FALSE),
      m_lookup_table (Config::pageSize ())
{
}

gboolean
PunctEditor::insert (gchar ch)
{
    m_text.insert (m_cursor++, ch);
    update ();
    return TRUE;
}

inline gboolean
PunctEditor::processSpace (guint keyval, guint keycode, guint modifiers)
{
    if (!m_text)
        return FALSE;
    if (CMSHM_FILTER (modifiers) != 0)
        return TRUE;
    if (m_lookup_table.size () != 0) {
        selectCandidate (m_lookup_table.cursorPos ());
    }
    else {
        commit ();
    }
    return TRUE;
}

gboolean
PunctEditor::processPunct (guint keyval, guint keycode, guint modifiers)
{
    if (CMSHM_FILTER (modifiers) != 0)
        return TRUE;

    if (m_punct_mode == FALSE) {
        if (keyval == IBUS_grave) {
            m_punct_mode = TRUE;
            return insert('`');
        }
        return FALSE;
    }

    switch (keyval) {
    case IBUS_grave:        /* ` */
    case IBUS_asciitilde:   /* ~ */
    case IBUS_exclam:       /* ~ */
    case IBUS_at:           /* @ */
    case IBUS_numbersign:   /* # */
    case IBUS_dollar:       /* $ */
    case IBUS_percent:      /* % */
    case IBUS_asciicircum:  /* ^ */
    case IBUS_ampersand:    /* & */
    case IBUS_asterisk:     /* * */
    case IBUS_parenleft:    /* ( */
    case IBUS_parenright:   /* ) */
    case IBUS_minus:        /* - */
    case IBUS_underscore:   /* _ */
    case IBUS_equal:        /* = */
    case IBUS_plus:         /* + */
    case IBUS_bracketleft:  /* [ */
    case IBUS_bracketright: /* ] */
    case IBUS_braceleft:    /* { */
    case IBUS_braceright:   /* } */
    case IBUS_backslash:    /* \ */
    case IBUS_bar:          /* | */
    case IBUS_colon:        /* : */
    case IBUS_semicolon:    /* ; */
    case IBUS_apostrophe:   /* ' */
    case IBUS_quotedbl:     /* " */
    case IBUS_comma:        /* , */
    case IBUS_period:       /* . */
    case IBUS_less:         /* < */
    case IBUS_greater:      /* > */
    case IBUS_slash:        /* / */
    case IBUS_question:     /* ? */
    case IBUS_0...IBUS_9:
    case IBUS_a...IBUS_z:
    case IBUS_A...IBUS_Z:
        return insert(keyval);
    default:
        return FALSE;
    }
}

gboolean
PunctEditor::processKeyEvent (guint keyval, guint keycode, guint modifiers)
{
    modifiers &= (IBUS_SHIFT_MASK |
                  IBUS_CONTROL_MASK |
                  IBUS_MOD1_MASK |
                  IBUS_SUPER_MASK |
                  IBUS_HYPER_MASK |
                  IBUS_META_MASK |
                  IBUS_LOCK_MASK);

    if (processPunct(keyval,keycode,modifiers) == TRUE)
        return TRUE;

    switch (keyval) {
    case IBUS_space:
        return processSpace (keyval, keycode, modifiers);

    case IBUS_Return:
    case IBUS_KP_Enter:
        commit ();
        return TRUE;

    case IBUS_BackSpace:
        removeCharBefore ();
        return TRUE;

    case IBUS_Delete:
    case IBUS_KP_Delete:
        removeCharAfter ();
        return TRUE;

    case IBUS_Left:
    case IBUS_KP_Left:
        moveCursorLeft ();
        return TRUE;

    case IBUS_Right:
    case IBUS_KP_Right:
        moveCursorRight ();
        return TRUE;

    case IBUS_Home:
    case IBUS_KP_Home:
        moveCursorToBegin ();
        return TRUE;

    case IBUS_End:
    case IBUS_KP_End:
        moveCursorToEnd ();
        return TRUE;

    case IBUS_Up:
    case IBUS_KP_Up:
        cursorUp ();
        return TRUE;

    case IBUS_Down:
    case IBUS_KP_Down:
        cursorDown ();
        return TRUE;

    case IBUS_Page_Up:
    case IBUS_KP_Page_Up:
        pageUp ();
        return TRUE;

    case IBUS_Page_Down:
    case IBUS_KP_Page_Down:
    case IBUS_Tab:
        pageDown ();
        return TRUE;
    default:
        return Editor::processKeyEvent (keyval, keycode, modifiers);
    }
}

void
PunctEditor::pageUp (void)
{
    if (G_LIKELY (m_lookup_table.pageUp ())) {
        updateLookupTableFast (m_lookup_table, TRUE);
        updatePreeditText ();
        updateAuxiliaryText ();
    }
}

void
PunctEditor::pageDown (void)
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
PunctEditor::cursorUp (void)
{
    if (G_LIKELY (m_lookup_table.cursorUp ())) {
        updateLookupTableFast (m_lookup_table, TRUE);
        updatePreeditText ();
        updateAuxiliaryText ();
    }
}

void
PunctEditor::cursorDown (void)
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

gboolean
PunctEditor::moveCursorLeft (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;
    m_cursor --;
    update();
    return TRUE;
}

gboolean
PunctEditor::moveCursorRight (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;
    m_cursor ++;
    update();
    return TRUE;
}

gboolean
PunctEditor::moveCursorToBegin (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;
    m_cursor = 0;
    update ();
    return TRUE;
}

gboolean
PunctEditor::moveCursorToEnd (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;
    m_cursor = m_text.length ();
    update();
    return TRUE;
}

gboolean
PunctEditor::removeCharBefore (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    m_cursor --;
    m_text.erase (m_cursor, 1);
    if (m_text.empty())
        m_punct_mode = FALSE;

    update();

    return TRUE;
}

gboolean
PunctEditor::removeCharAfter (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    m_text.erase (m_cursor, 1);
    if (m_text.empty())
        m_punct_mode = FALSE;

    update();

    return TRUE;
}

void
PunctEditor::reset (void)
{
    m_punct_mode = FALSE;
    Editor::reset ();
}

void
PunctEditor::candidateClicked (guint index, guint button, guint state)
{
    selectCandidateInPage(index);
}

inline void
PunctEditor::commit (const gchar *str)
{
    StaticText text(str);
    commitText (text);
}

void
PunctEditor::commit (void)
{
    commit ((const gchar *)m_text);
    reset();
}

inline gboolean
PunctEditor::selectCandidate (guint i)
{
    m_buffer.clear ();
    m_buffer << m_punct_candidates[i];
    reset();
    commit ((const gchar *) m_buffer);
    return FALSE;
}

inline gboolean
PunctEditor::selectCandidateInPage (guint i)
{
    guint page_size = m_lookup_table.pageSize ();
    guint cursor_pos = m_lookup_table.cursorPos ();

    if (G_UNLIKELY (i >= page_size))
        return FALSE;
    i += (cursor_pos / page_size) * page_size;

    return selectCandidate (i);
}

void
PunctEditor::update (void)
{
    updateLookupTable ();
    updatePreeditText ();
    updateAuxiliaryText ();
}

void
PunctEditor::updateLookupTable (void)
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

static int
punct_cmp (const void *p1, const void *p2)
{
    const gchar *s1 = (gchar *) p1;
    const gchar *s2 = **(gchar ***) p2;
    return std::strcmp (s1, s2);
}

void
PunctEditor::getPunctCandidates (void)
{
    const gchar *** brs;
    const gchar ** res;
    m_punct_candidates.clear();

    if (m_text.empty())
        return;

    brs = (const gchar ***) std::bsearch (m_text.c_str() + 1, punct_table,
                                          G_N_ELEMENTS (punct_table),
                                          sizeof(punct_table[0]),
                                          punct_cmp);
    if (brs == NULL)
        return;

    for (res = (*brs) + 1 ;*res != NULL; ++res ) {
        m_punct_candidates.push_back(*res);
    }
}

gboolean
PunctEditor::fillLookupTableByPage (void)
{
    guint filled_nr = m_lookup_table.size ();
    guint page_size = m_lookup_table.pageSize ();
    guint candidates_count;

    getPunctCandidates();
    candidates_count = m_punct_candidates.size();

    guint need_nr = MIN (page_size, candidates_count - filled_nr);
    g_assert (need_nr >= 0);
    if (need_nr == 0) {
        return FALSE;
    }

    for (guint i = filled_nr; i < filled_nr + need_nr; i++) {
        Text text (m_punct_candidates[i]);
        text.appendAttribute (IBUS_ATTR_TYPE_FOREGROUND, 0x004466, 0, -1);
        m_lookup_table.appendCandidate (text);
    }

    return TRUE;
}

void
PunctEditor::updateAuxiliaryText (void)
{
    if (G_UNLIKELY (m_punct_mode == FALSE)) {
        hideAuxiliaryText ();
        return;
    }

    m_buffer.clear();
    for (String::iterator i = m_text.begin(); i!=m_text.end(); ++i) {
        if (i - m_text.begin() == (gint) m_cursor)
            m_buffer << '|';
        m_buffer << *i;
    }
    if (m_text.end() - m_text.begin() == (gint) m_cursor)
        m_buffer << '|';

    StaticText aux_text (m_buffer);
    Editor::updateAuxiliaryText (aux_text, TRUE);
}

void
PunctEditor::updatePreeditText (void)
{
    if (G_UNLIKELY (m_punct_mode == FALSE )) {
        hidePreeditText ();
        return;
    }

    guint edit_begin = 0;
    guint edit_end = 0;

    m_buffer.clear ();
    if (m_lookup_table.size() != 0) {
        guint cursor = m_lookup_table.cursorPos ();
        m_buffer << m_punct_candidates[cursor];
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


