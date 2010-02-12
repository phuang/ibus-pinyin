/* vim:set et sts=4: */
#ifndef __PY_EXT_EDITOR__
#define __PY_EXT_EDITOR__

#include <glib.h>
#include "Editor.h"

namespace PY {

class ExtEditor : public Editor {
public:
    ExtEditor (PinyinProperties &props) : Editor (props) {}
};

};
#endif
