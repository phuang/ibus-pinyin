/* vim:set et ts=4 sts=4:
 *
 * ibus-pinyin - The Chinese PinYin engine for IBus
 *
 * Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
 * Copyright (c) 2010 BYVoid <byvoid1@gmail.com>
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
#include "PunctEditor.h"

namespace PY {

#include "PunctTable.h"

PunctEditor::PunctEditor (PinyinProperties & props, Config & config)
    : Editor (props, config),
      m_punct_mode (MODE_DISABLE),
      m_lookup_table (m_config.pageSize ())
{
}

gboolean
PunctEditor::insert (gchar ch)
{
    switch (m_punct_mode) {
    case MODE_DISABLE:
        {
            g_assert (ch == IBUS_grave);
            g_assert (m_cursor == 0);
            m_text.insert (m_cursor++, ch);
            m_punct_mode = MODE_INIT;
            updatePunctCandidates (0);
            m_selected_puncts.clear ();
            m_selected_puncts.insert (m_selected_puncts.begin (), m_punct_candidates[0]);
            update ();
        }
        break;
    case MODE_INIT:
        {
            m_text.clear ();
            m_selected_puncts.clear ();
            m_cursor = 0;
        }
    case MODE_NORMAL:
        {
            m_text.insert (m_cursor, ch);
            updatePunctCandidates (ch);
            m_punct_mode = MODE_NORMAL;
            if (m_punct_candidates.size () > 0) {
                m_selected_puncts.insert (m_selected_puncts.begin () + m_cursor, m_punct_candidates[0]);
            }
            m_cursor ++;
            update ();
        }
        break;
    default:
        g_assert_not_reached ();
    }

    return TRUE;
}

inline gboolean
PunctEditor::processSpace (guint keyval, guint keycode, guint modifiers)
{
    if (m_punct_mode != MODE_INIT && m_punct_mode != MODE_NORMAL)
        return FALSE;
    if (CMSHM_FILTER (modifiers) != 0)
        return TRUE;
    commit ();
    return TRUE;
}

gboolean
PunctEditor::processPunct (guint keyval, guint keycode, guint modifiers)
{
    if (CMSHM_FILTER (modifiers) != 0)
        return TRUE;

    if (m_punct_mode == MODE_DISABLE) {
        if (keyval == IBUS_grave) {
            insert (keyval);
            return TRUE;
        }
    }

    g_assert (m_punct_mode == MODE_INIT || m_punct_mode == MODE_NORMAL);

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
        return insert (keyval);
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

    switch (keyval) {
    case IBUS_space:
        return processSpace (keyval, keycode, modifiers);

    case IBUS_Return:
    case IBUS_KP_Enter:
        commit (m_text);
        return TRUE;

    case IBUS_Escape:
        reset ();
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
        return processPunct(keyval, keycode, modifiers);
    }
}

void
PunctEditor::pageUp (void)
{
    if (G_LIKELY (m_lookup_table.pageUp ())) {
        m_selected_puncts[m_cursor - 1] = m_punct_candidates[m_lookup_table.cursorPos ()];
        updateLookupTableFast (m_lookup_table, TRUE);
        updatePreeditText ();
        updateAuxiliaryText ();
    }
}

void
PunctEditor::pageDown (void)
{
    if (G_LIKELY (m_lookup_table.pageDown ())) {
        m_selected_puncts[m_cursor - 1] = m_punct_candidates[m_lookup_table.cursorPos ()];
        updateLookupTableFast (m_lookup_table, TRUE);
        updatePreeditText ();
        updateAuxiliaryText ();
    }
}

void
PunctEditor::cursorUp (void)
{
    if (G_LIKELY (m_lookup_table.cursorUp ())) {
        m_selected_puncts[m_cursor - 1] = m_punct_candidates[m_lookup_table.cursorPos ()];
        updateLookupTableFast (m_lookup_table, TRUE);
        updatePreeditText ();
        updateAuxiliaryText ();
    }
}

void
PunctEditor::cursorDown (void)
{
    if (G_LIKELY (m_lookup_table.cursorDown ())) {
        m_selected_puncts[m_cursor - 1] = m_punct_candidates[m_lookup_table.cursorPos ()];
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
    if (m_cursor == 0)  {
        m_punct_candidates.clear ();
        fillLookupTable ();
    }
    else {
        updatePunctCandidates (m_text[m_cursor - 1]);
        /* restore cursor pos */
        std::vector<const gchar *>::iterator it;
        it = std::find (m_punct_candidates.begin (),
                        m_punct_candidates.end (),
                        m_selected_puncts[m_cursor - 1]);
        g_assert (it != m_punct_candidates.end ());
        m_lookup_table.setCursorPos (it - m_punct_candidates.begin ());
    }
    update();
    return TRUE;
}

gboolean
PunctEditor::moveCursorRight (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;
    m_cursor ++;
    updatePunctCandidates (m_text[m_cursor - 1]);

    /* restore cursor pos */
    std::vector<const gchar *>::iterator it;
    it = std::find (m_punct_candidates.begin (),
                    m_punct_candidates.end (),
                    m_selected_puncts[m_cursor - 1]);
    g_assert (it != m_punct_candidates.end ());
    m_lookup_table.setCursorPos (it - m_punct_candidates.begin ());

    update();
    return TRUE;
}

gboolean
PunctEditor::moveCursorToBegin (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    g_assert (m_punct_mode == MODE_NORMAL);
    m_cursor = 0;
    m_punct_candidates.clear ();
    fillLookupTable ();
    update ();

    return TRUE;
}

gboolean
PunctEditor::moveCursorToEnd (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;

    g_assert (m_punct_mode == MODE_NORMAL);
    m_cursor = m_text.length ();
    updatePunctCandidates (m_text[m_cursor - 1]);

    /* restore cursor pos */
    std::vector<const gchar *>::iterator it;
    it = std::find (m_punct_candidates.begin (),
                    m_punct_candidates.end (),
                    m_selected_puncts[m_cursor - 1]);
    g_assert (it != m_punct_candidates.end ());
    m_lookup_table.setCursorPos (it - m_punct_candidates.begin ());

    update();
    return TRUE;
}

gboolean
PunctEditor::removeCharBefore (void)
{
    if (G_UNLIKELY (m_cursor == 0))
        return FALSE;

    m_cursor --;
    m_selected_puncts.erase (m_selected_puncts.begin () + m_cursor);
    m_text.erase (m_cursor, 1);
    if (m_text.empty()) {
        reset ();
    }
    else {
        if (m_cursor > 0) {

            updatePunctCandidates (m_text[m_cursor - 1]);
            /* restore cursor pos */
            std::vector<const gchar *>::iterator it;
            it = std::find (m_punct_candidates.begin (),
                            m_punct_candidates.end (),
                            m_selected_puncts[m_cursor - 1]);
            g_assert (it != m_punct_candidates.end ());
            m_lookup_table.setCursorPos (it - m_punct_candidates.begin ());
        }
        else {
            m_punct_candidates.clear ();
            fillLookupTable ();
        }
    }

    update();

    return TRUE;
}

gboolean
PunctEditor::removeCharAfter (void)
{
    if (G_UNLIKELY (m_cursor == m_text.length ()))
        return FALSE;
    m_selected_puncts.erase (m_selected_puncts.begin () + m_cursor);
    m_text.erase (m_cursor, 1);
    if (m_text.empty()) {
        reset ();
    }

    update();

    return TRUE;
}

void
PunctEditor::reset (void)
{
    m_punct_mode = MODE_DISABLE;
    m_selected_puncts.clear ();
    m_punct_candidates.clear ();
    fillLookupTable ();
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
    reset ();
}

void
PunctEditor::commit (void)
{
    m_buffer.clear ();
    for (std::vector<const gchar *>::iterator it = m_selected_puncts.begin ();
         it != m_selected_puncts.end (); it++) {
        m_buffer << *it;
    }

    commit (m_buffer);
}

inline gboolean
PunctEditor::selectCandidate (guint i)
{
    switch (m_punct_mode) {
    case MODE_INIT:
        {
            g_assert (m_cursor == 1);
            m_lookup_table.setCursorPos (i);
            m_selected_puncts[m_cursor - 1] = m_punct_candidates[i];
            commit ();
            return TRUE;
        }
    case MODE_NORMAL:
        {
            m_lookup_table.setCursorPos (i);
            m_selected_puncts[m_cursor - 1] = m_punct_candidates[i];

            /* if it is the last punct, commit the result */
            if (m_cursor == m_text.length ()) {
                commit ();
            }
            else {
                moveCursorRight ();
            }
            return TRUE;
        }
    default:
        g_assert_not_reached ();
    }

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
PunctEditor::fillLookupTable (void)
{
    m_lookup_table.clear ();
    m_lookup_table.setPageSize (m_config.pageSize ());
    m_lookup_table.setOrientation (m_config.orientation ());

    for (std::vector<const gchar *>::iterator it = m_punct_candidates.begin ();
         it != m_punct_candidates.end (); it++) {
        StaticText text (*it);
        // text.appendAttribute (IBUS_ATTR_TYPE_FOREGROUND, 0x004466, 0, -1);
        m_lookup_table.appendCandidate (text);
    }
}

void
PunctEditor::updateLookupTable (void)
{
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
    const gint s1 = (gint)(glong) p1;
    const gchar *s2 = **(gchar ***) p2;
    return s1 - s2[0];
}

void
PunctEditor::updatePunctCandidates (gchar ch)
{
    const gchar *** brs;
    const gchar ** res;

    m_punct_candidates.clear();

    brs = (const gchar ***) std::bsearch ((void *) ch,
                                          punct_table,
                                          G_N_ELEMENTS (punct_table),
                                          sizeof(punct_table[0]),
                                          punct_cmp);
    if (brs != NULL) {
        for (res = (*brs) + 1; *res != NULL; ++res) {
            m_punct_candidates.push_back (*res);
        }
    }
    fillLookupTable ();
}

void
PunctEditor::updateAuxiliaryText (void)
{
    switch (m_punct_mode) {
    case MODE_DISABLE:
        hideAuxiliaryText ();
        break;
    case MODE_INIT:
        {
            m_buffer = "`";
            StaticText aux_text (m_buffer);
            Editor::updateAuxiliaryText (aux_text, TRUE);
        }
        break;
    case MODE_NORMAL:
        {
            if (m_cursor == 0) {
                hideAuxiliaryText ();
            }
            else {
                m_buffer.clear ();
                for (String::iterator i = m_text.begin (); i != m_text.end (); ++i) {
                    if (i - m_text.begin () == (gint) m_cursor)
                        m_buffer << '|';
                    m_buffer << *i;
                }
                if (m_text.end () - m_text.begin () == (gint) m_cursor)
                    m_buffer << '|';

                StaticText aux_text (m_buffer);
                Editor::updateAuxiliaryText (aux_text, TRUE);
            }
        }
        break;
    default:
        g_assert_not_reached ();
    }
}

void
PunctEditor::updatePreeditText (void)
{
    switch (m_punct_mode) {
    case MODE_DISABLE:
        hidePreeditText ();
        break;
    case MODE_INIT:
        {
            m_buffer = m_punct_candidates[m_lookup_table.cursorPos ()];
            StaticText preedit_text (m_buffer);
            /* underline */
            preedit_text.appendAttribute (IBUS_ATTR_TYPE_UNDERLINE, IBUS_ATTR_UNDERLINE_SINGLE, 0, -1);
            Editor::updatePreeditText (preedit_text, m_cursor, TRUE);
        }
        break;
    case MODE_NORMAL:
        {
            m_buffer.clear ();
            for (std::vector<const gchar *>::iterator it = m_selected_puncts.begin ();
                 it != m_selected_puncts.end (); it++) {
                m_buffer << *it;
            }
            StaticText preedit_text (m_buffer);
            /* underline */
            preedit_text.appendAttribute (IBUS_ATTR_TYPE_UNDERLINE, IBUS_ATTR_UNDERLINE_SINGLE, 0, -1);
            Editor::updatePreeditText (preedit_text, m_cursor, TRUE);
        }
        break;
    default:
        g_assert_not_reached ();
    }
}

};


