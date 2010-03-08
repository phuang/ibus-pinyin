#ifndef __PY_TEXT_H_
#define __PY_TEXT_H_

#include <ibus.h>
#include "Pointer.h"
#include "String.h"

namespace PY {

class Text : public Pointer<IBusText> {
public:
    Text (IBusText *text)
        : Pointer<IBusText> (text) {}
    Text (const gchar *str)
        : Pointer<IBusText> (ibus_text_new_from_string (str)) {}

    Text (const String & str)
        : Pointer<IBusText> (ibus_text_new_from_string ((const gchar *) str)) {}

    Text (gunichar ch)
        : Pointer<IBusText> (ibus_text_new_from_unichar (ch)) {}

    void appendAttribute (guint type, guint value, guint start, guint end) {
        ibus_text_append_attribute (*this, type, value, start, end);
    }
};

class StaticText : public Text {
public:
    StaticText (const gchar *str)
        : Text (ibus_text_new_from_static_string (str)) {}

    StaticText (const String & str)
        : Text (ibus_text_new_from_static_string ((const gchar *) str)) {}

    StaticText (gunichar ch)
        : Text (ch) {}
};

};

#endif
