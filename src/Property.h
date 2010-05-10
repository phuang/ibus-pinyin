#ifndef __PY_PROPERTY_H_
#define __PY_PROPERTY_H_

#include <ibus.h>
#include "Object.h"
#include "Text.h"

namespace PY {

class Property : public Object {
public:
    Property (const gchar   *key,
              IBusPropType   type = PROP_TYPE_NORMAL,
              IBusText      *label = NULL,
              const gchar   *icon = NULL,
              IBusText      *tooltip = NULL,
              gboolean       sensitive = TRUE,
              gboolean       visible = TRUE,
              IBusPropState  state = PROP_STATE_UNCHECKED,
              IBusPropList  *props = NULL)
        : Object (ibus_property_new (key, type, label, icon, tooltip, sensitive, visible, state, props)) { }

    void setLabel (IBusText *text) {
        ibus_property_set_label (get<IBusProperty> (), text);
    }

    void setLabel (const gchar *text) {
        setLabel (Text (text));
    }

    void setIcon (const gchar *icon) {
        ibus_property_set_icon (get<IBusProperty> (), icon);
    }

    void setSensitive (gboolean sensitive) {
        ibus_property_set_sensitive (get<IBusProperty> (), sensitive);
    }

    operator IBusProperty * (void) const {
        return get<IBusProperty> ();
    }
};


class PropList : Object {
public:
    PropList (void) : Object (ibus_prop_list_new ()) { }

    void append (Property &prop) {
        ibus_prop_list_append (get<IBusPropList> (), prop);
    }

    operator IBusPropList * (void) const {
        return get<IBusPropList> ();
    }
};

};

#endif
