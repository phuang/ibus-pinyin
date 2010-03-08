/* vim:set et sts=4: */
#ifndef __PY_EXT_EDITOR__
#define __PY_EXT_EDITOR__

#include <glib.h>
#include "Editor.h"

namespace PY {

class ExtEditor : public Editor {
public:
    ExtEditor (PinyinProperties &props);

    virtual gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    virtual void pageUp (void);
    virtual void pageDown (void);
    virtual void cursorUp (void);
    virtual void cursorDown (void);
    virtual void update (void);
    virtual void reset (void);
    virtual void candidateClicked (guint index, guint button, guint state);

private:
};

};
#endif
