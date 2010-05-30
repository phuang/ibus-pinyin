/* vim:set et ts=4 sts=4:
 *
 * ibus-pinyin - The Chinese PinYin engine for IBus
 *
 * Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
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

    void setLabel (IBusText *text)
    {
        ibus_property_set_label (get<IBusProperty> (), text);
    }

    void setLabel (const gchar *text)
    {
        setLabel (Text (text));
    }

    void setIcon (const gchar *icon)
    {
        ibus_property_set_icon (get<IBusProperty> (), icon);
    }

    void setSensitive (gboolean sensitive)
    {
        ibus_property_set_sensitive (get<IBusProperty> (), sensitive);
    }

    operator IBusProperty * (void) const
    {
        return get<IBusProperty> ();
    }
};


class PropList : Object {
public:
    PropList (void) : Object (ibus_prop_list_new ()) { }

    void append (Property &prop)
    {
        ibus_prop_list_append (get<IBusPropList> (), prop);
    }

    operator IBusPropList * (void) const
    {
        return get<IBusPropList> ();
    }
};

};

#endif
