/* vim:set et sts=4: */
#ifndef __PY_FALLBACK_EDITOR__
#define __PY_FALLBACK_EDITOR__

#include <glib.h>
#include "Editor.h"

namespace PY {

class FallbackEditor : public Editor {
public:
    FallbackEditor (PinyinProperties &props)
        : Editor (props),
          m_quote (TRUE),
          m_double_quote (TRUE),
          m_prev_committed_char (0) {}

    gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    void reset (void);

    void setPrevCommittedChar (gunichar ch) {
        m_prev_committed_char = ch;
    }

private:
    void commit (gchar ch) {
        gchar str[2] = {ch, 0};
        StaticText text (str);
        commitText (text);
    }

    void commit (gunichar ch) {
        Text text (ch);
        commitText (text);
    }

    void commit (const gchar *str) {
        StaticText text (str);
        commitText (text);
    }

    void commit (const String &str) {
        commit ((const gchar *)str);
    }

    gboolean processPunct (guint keyval, guint keycode, guint modifiers);

private:
    gboolean m_quote;
    gboolean m_double_quote;
    gunichar m_prev_committed_char;
    
};

};
#endif
