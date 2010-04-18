#ifndef __PY_TEXT_H_
#define __PY_TEXT_H_

#include <ibus.h>
#include "Object.h"
#include "String.h"

namespace PY {

class Text : Object {
public:
    Text (IBusText *text)
        : Object (text) {}
    Text (const gchar *str)
        : Object (ibus_text_new_from_string (str)) {}

    Text (const String & str)
        : Object (ibus_text_new_from_string ((const gchar *) str)) {}

    Text (gunichar ch)
        : Object (ibus_text_new_from_unichar (ch)) {}

    void appendAttribute (guint type, guint value, guint start, guint end) {
        ibus_text_append_attribute (get<IBusText> (), type, value, start, end);
    }

    operator IBusText * (void) const {
        return get<IBusText> ();
    }
};

class StaticText : public Text {
public:
    StaticText (const gchar *str)
        : Text (ibus_text_new_from_static_string (str)) {
    }

    StaticText (const String & str)
        : Text (ibus_text_new_from_static_string ((const gchar *) str)) {}

    StaticText (gunichar ch)
        : Text (ch) {}

    operator IBusText * (void) const {
        return Text::operator IBusText * ();
    }
};

};

#endif
