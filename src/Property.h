#ifndef __PY_PROPERTY_H_
#define __PY_PROPERTY_H_

#include <ibus.h>
#include "Pointer.h"
#include "Text.h"

namespace PY {

class Property : public Pointer<IBusProperty> {
public:
    Property & operator= (IBusProperty *p) {
        set (p);
        return *this;
    }

    void setLabel (const Text & text) {
        ibus_property_set_label (*this, text);
    }
    void setLabel (const gchar *text) {
        setLabel (Text (text));
    }
    void setIcon (const gchar *icon) {
        ibus_property_set_icon (*this, icon);
    }
    void setSensitive (gboolean sensitive) {
        ibus_property_set_sensitive (*this, sensitive);
    }
};


class PropList : public Pointer<IBusPropList> {
public:
    PropList (void) : Pointer<IBusPropList> (ibus_prop_list_new ()) { }

    void append (Property &prop) {
        ibus_prop_list_append (*this, prop);
    }
};

};

#endif
