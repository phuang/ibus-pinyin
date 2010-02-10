#include "Editor.h"

namespace PY {

Editor::Editor (PinyinProperties & props)
    : m_text (128),
      m_cursor (0),
      m_props (props)
{
}

Editor::~Editor (void)
{
}

gboolean
Editor::processKeyEvent (guint keyval, guint keycode, guint modifiers)
{
    /* ignore release key events */
    if (modifiers & IBUS_RELEASE_MASK)
        return FALSE;

    modifiers &= (IBUS_SHIFT_MASK |
                  IBUS_CONTROL_MASK |
                  IBUS_MOD1_MASK |
                  IBUS_SUPER_MASK |
                  IBUS_HYPER_MASK |
                  IBUS_META_MASK);
    /* ignore key events with some masks */
    if (modifiers != 0)
        return TRUE;

    if (keyval >= IBUS_exclam && keyval <= IBUS_asciitilde) {
        /* char key */
        m_text.insert (m_cursor++, keyval);
        update ();
        return TRUE;
    }
    else {
        /* control key */
        if (!m_text)
            return FALSE;
    }

    switch (keyval) {
    case IBUS_BackSpace:
        if (m_cursor > 0) {
            m_text.erase (--m_cursor, 1);
            update ();
        }
        return TRUE;
    case IBUS_Delete:
    case IBUS_KP_Delete:
        if (m_cursor < m_text.length ()) {
            m_text.erase (m_cursor, 1);
            update ();
        }
        return TRUE;
    case IBUS_Left:
    case IBUS_KP_Left:
        if (!m_text)
            return FALSE;
        if (m_cursor > 0) {
            m_cursor --;
            update ();
        }
        return TRUE;
    case IBUS_Right:
    case IBUS_KP_Right:
        if (m_cursor < m_text.length ()) {
            m_cursor ++;
            update ();
        }
        return TRUE;
    case IBUS_Return:
    case IBUS_KP_Enter:
        {
            StaticText text (m_text);
            commitText (text);
            reset ();
        }
        return TRUE;
    case IBUS_Escape:
        reset ();
        return TRUE;
    default:
        g_debug ("Unknown keyval %d", keyval);
        return TRUE;
    }
}

void
Editor::reset (void)
{
    gboolean need_update = (m_cursor != 0 || m_text);
    m_cursor = 0;
    m_text = "";
    if (need_update)
        update ();
}

void
Editor::pageUp (void)
{
}

void
Editor::pageDown (void)
{
}

void
Editor::cursorUp (void)
{
}

void
Editor::cursorDown (void)
{
}

void
Editor::candidateClicked (guint index, guint button, guint state)
{
}

void
Editor::update (void)
{
    if (m_text) {
        StaticText text (m_text);
        text.appendAttribute (IBUS_ATTR_TYPE_UNDERLINE, IBUS_ATTR_UNDERLINE_SINGLE, 0, -1);
        updatePreeditText (text, m_cursor, TRUE);
    }
    else {
        hidePreeditText ();
    }
}

};

