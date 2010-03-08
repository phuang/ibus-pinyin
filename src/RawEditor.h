/* vim:set et sts=4: */
#ifndef __PY_RAW_EDITOR__
#define __PY_RAW_EDITOR__

#include <glib.h>
#include "Editor.h"

namespace PY {

class RawEditor : public Editor {
public:
    RawEditor (PinyinProperties &props) : Editor (props) {}
};

};
#endif
