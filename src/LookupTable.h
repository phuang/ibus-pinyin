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
#ifndef __PY_LOOKUP_TABLE_H_
#define __PY_LOOKUP_TABLE_H_

#include <ibus.h>
#include "Object.h"
#include "Text.h"

namespace PY {

class LookupTable : Object {
public:
    LookupTable (guint page_size = 10,
                 guint cursor_pos = 0,
                 gboolean cursor_visible = TRUE,
                 gboolean round = FALSE)
        : Object (ibus_lookup_table_new (page_size, cursor_pos, cursor_visible, round)) { }

    guint pageSize (void)       { return ibus_lookup_table_get_page_size (*this); }
    guint orientation (void)    { return ibus_lookup_table_get_orientation (*this); }
    guint cursorPos (void)      { return ibus_lookup_table_get_cursor_pos (*this); }
    guint size (void)           { return ibus_lookup_table_get_number_of_candidates (*this); }

    gboolean pageUp (void)      { return ibus_lookup_table_page_up (*this); }
    gboolean pageDown (void)    { return ibus_lookup_table_page_down (*this); }
    gboolean cursorUp (void)    { return ibus_lookup_table_cursor_up (*this); }
    gboolean cursorDown (void)  { return ibus_lookup_table_cursor_down (*this); }

    void setPageSize (guint size)           { ibus_lookup_table_set_page_size (*this, size); }
    void setCursorPos (guint pos)           { ibus_lookup_table_set_cursor_pos (*this, pos); }
    void setOrientation (gint orientation)  { ibus_lookup_table_set_orientation (*this, orientation); }
    void clear (void)                       { ibus_lookup_table_clear (*this); }
    void setCursorVisable (gboolean visable){ ibus_lookup_table_set_cursor_visible (*this, visable); }
    void setLabel (guint index, IBusText *text) { ibus_lookup_table_set_label (*this, index, text); }

    void appendCandidate (IBusText *text)   { ibus_lookup_table_append_candidate (*this, text); }

    operator IBusLookupTable * (void) const
    {
        return get<IBusLookupTable> ();
    }
};

};

#endif
