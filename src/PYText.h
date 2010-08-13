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
#ifndef __PY_TEXT_H_
#define __PY_TEXT_H_

#include <string>
#include <ibus.h>
#include "PYObject.h"

namespace PY {

class Text : Object {
public:
    Text (IBusText *text)
        : Object (text) { }
    Text (const gchar *str)
        : Object (ibus_text_new_from_string (str)) { }

    Text (const std::string & str)
        : Object (ibus_text_new_from_string (str.c_str ())) { }

    Text (gunichar ch)
        : Object (ibus_text_new_from_unichar (ch)) { }

    void appendAttribute (guint type, guint value, guint start, guint end)
    {
        ibus_text_append_attribute (get<IBusText> (), type, value, start, end);
    }

    const gchar *text (void) const
    {
        return get<IBusText> ()->text;
    }

    operator IBusText * (void) const
    {
        return get<IBusText> ();
    }
};

class StaticText : public Text {
public:
    StaticText (const gchar *str)
        : Text (ibus_text_new_from_static_string (str)) { }

    StaticText (const std::string & str)
        : Text (ibus_text_new_from_static_string (str.c_str ())) { }

    StaticText (gunichar ch)
        : Text (ch) { }

    operator IBusText * (void) const
    {
        return Text::operator IBusText * ();
    }
};

};

#endif
