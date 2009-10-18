/* vim:set et sts=4: */
#ifndef __PY_RAW_EDITOR__
#define __PY_RAW_EDITOR__

#include <glib.h>
#include "String.h"

namespace PY {

class RawEditor {
public:
    RawEditor () : m_cursor (0) {}

    gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers, gboolean &update) {
        update = FALSE;
        if (modifiers & IBUS_RELEASE_MASK)
            return FALSE;

        modifiers &= (IBUS_SHIFT_MASK |
                      IBUS_CONTROL_MASK |
                      IBUS_MOD1_MASK |
                      IBUS_SUPER_MASK |
                      IBUS_HYPER_MASK |
                      IBUS_META_MASK);
        if (modifiers != 0)
            return TRUE;

        switch (keyval) {
        case IBUS_exclam ... IBUS_asciitilde:
            m_text.insert (m_cursor++, keyval);
            update = TRUE;
            return TRUE;
        case IBUS_BackSpace:
            if (m_cursor > 0) {
                m_text.erase (--m_cursor, 1);
                update = TRUE;
                return TRUE;
            }
            return FALSE;
        case IBUS_Delete:
        case IBUS_KP_Delete:
            if (m_cursor < m_text.length ()) {
                m_text.erase (m_cursor, 1);
                update = TRUE;
                return TRUE;
            }
            return FALSE;
        case IBUS_Left:
        case IBUS_KP_Left:
            if (m_cursor > 0) {
                m_cursor --;
                update = TRUE;
                return TRUE;
            }
            return FALSE;
        case IBUS_Right:
        case IBUS_KP_Right:
            if (m_cursor < m_text.length ()) {
                m_cursor ++;
                update = TRUE;
                return TRUE;
            }
            return FALSE;
        default:
            break;
        }
        return TRUE;
    }

    void reset (void) {
        m_text.truncate (0);
        m_cursor = 0;
    }

    guint cursor (void) const { return m_cursor; }
    operator const String & (void) const {
        return m_text;
    }

protected:
    String m_text;
    guint m_cursor;
};

};
#endif
