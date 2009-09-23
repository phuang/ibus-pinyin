#ifndef __PY_TEXT_H_
#define __PY_TEXT_H_

#include <ibus.h>
#include "Pointer.h"

namespace PY {

class Text : public Pointer <IBusText> {
public:
    Text (const gchar *str)
        : Pointer <IBusText> (ibus_text_new_from_static_string (str)) { }

    Text (gunichar ch)
        : Pointer <IBusText> (ibus_text_new_from_unichar (ch)) { }
    
    Text (const String & str)
        : Pointer <IBusText> (ibus_text_new_from_static_string ((const gchar *) str)) { }

    void appendAttribute (guint type, guint value, guint start, guint end) {
        ibus_text_append_attribute (*this, type, value, start, end);
    }
};

};

#endif
