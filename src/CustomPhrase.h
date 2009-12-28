#ifndef __PY_CUSTOM_PHRASE_H_
#define __PY_CUSTOM_PHRASE_H_

#include <glib.h>

namespace PY {

class CustomPhrase {
public:
    CustomPhrase (void) {}
private:
    gboolean load (const gchar *file);
};

};

#endif
