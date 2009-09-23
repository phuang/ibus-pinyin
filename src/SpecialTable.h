#ifndef __PY_SPECIAL_TABLE_H_
#define __PY_SPECIAL_TABLE_H_

#include <glib.h>

namespace PY {

class SpecialTable {
public:
    SpecialTable (void) {}
private:
    gboolean load (const gchar *file);
};

};

#endif
