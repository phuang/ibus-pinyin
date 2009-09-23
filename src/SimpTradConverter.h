#ifndef __SIMP_TRAD_CONVERTER_H_
#define __SIMP_TRAD_CONVERTER_H_

#include <glib.h>
#include "String.h"

namespace PY {

class SimpTradConverter {
public:
    static void simpToTrad (const gchar *in, String &out);
};

};
#endif
