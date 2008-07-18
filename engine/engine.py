# vim:set et sts=4 sw=4:
#
# ibus-tmpl - The Input Bus template project
#
# Copyright (c) 2007-2008 Huang Peng <shawn.p.huang@gmail.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

import gobject
import pango
import enchant
import ibus
from ibus import keysyms
from ibus import modifier

class Engine(ibus.EngineBase):
    __dict = enchant.Dict()

    def __init__(self, conn, object_path):
        super(Engine, self).__init__(conn, object_path)
        self.__is_invalidate = False
        self.__preedit_string = u""
        self.__lookup_table = ibus.LookupTable()
        self.__prop_list = ibus.PropList()
        self.__prop_list.append(ibus.Property("test", icon = "ibus-locale"))

    def process_key_event(self, keyval, is_press, state):
        # ignore key release events
        if not is_press:
            return False

        if self.__preedit_string:
            if keyval == keysyms.Return:
                self.__commit_string(self.__preedit_string)
                return True
            elif keyval == keysyms.Escape:
                self.__preedit_string = u""
                self.__update()
                return True
            elif keyval == keysyms.BackSpace:
                self.__preedit_string = self.__preedit_string[:-1]
                self.__invalidate()
                return True
            elif keyval == keysyms.space:
                if self.__lookup_table.get_number_of_candidates() > 0:
                    self.__commit_string(self.__lookup_table.get_current_candidate()[0])
                else:
                    self.__commit_string(self.__preedit_string)
                return False
            elif keyval >= keysyms._1 and keyval <= keysyms._9:
                index = keyval - keysyms._1
                candidates = self.__lookup_table.get_canidates_in_current_page()
                if index >= len(candidates):
                    return False
                candidate = candidates[index][0]
                self.__commit_string(candidate)
                return True
            elif keyval == keysyms.Page_Up or keyval == keysyms.KP_Page_Up:
                if self.__lookup_table.page_up():
                    self.__update_lookup_table()
                return True
            elif keyval == keysyms.Up:
                self.cursor_up()
                return True
            elif keyval == keysyms.Down:
                self.cursor_down()
                return True
            elif keyval == keysyms.Left or keyval == keysyms.Right:
                return True
            elif keyval == keysyms.Page_Down or keyval == keysyms.KP_Page_Down:
                if self.__lookup_table.page_down():
                    self.__update_lookup_table()
                return True
        if keyval in xrange(keysyms.a, keysyms.z + 1) or \
            keyval in xrange(keysyms.A, keysyms.Z + 1):
            if state & (modifier.CONTROL_MASK | modifier.ALT_MASK) == 0:
                self.__preedit_string += unichr(keyval)
                self.__invalidate()
                return True
        else:
            if keyval < 128 and self.__preedit_string:
                self.__commit_string(self.__preedit_string)

        return False

    def __invalidate(self):
        if self.__is_invalidate:
            return
        self.__is_invalidate = True
        gobject.idle_add(self.__update, priority = gobject.PRIORITY_LOW)

    def cursor_up(self):
        if self.__lookup_table.cursor_up():
            self.__update_lookup_table()
            return True
        return False

    def cursor_down(self):
        if self.__lookup_table.cursor_down():
            self.__update_lookup_table()
            return True
        return False

    def __commit_string(self, text):
        self.commit_string(text)
        self.__preedit_string = u""
        self.__update()

    def __update(self):
        preedit_len = len(self.__preedit_string)
        attrs = ibus.AttrList()
        self.__lookup_table.clean()
        if preedit_len > 0:
            if not self.__dict.check(self.__preedit_string):
                attrs.append(ibus.AttributeForeground(0xff0000, 0, preedit_len))
                for text in self.__dict.suggest(self.__preedit_string):
                    self.__lookup_table.append_candidate(text)
        self.update_aux_string(self.__preedit_string, attrs, preedit_len > 0)
        attrs.append(ibus.AttributeUnderline(pango.UNDERLINE_SINGLE, 0, preedit_len))
        self.update_preedit(self.__preedit_string, attrs, preedit_len, preedit_len > 0)
        self.__update_lookup_table()
        self.__is_invalidate = False

    def __update_lookup_table(self):
        show = self.__lookup_table.get_number_of_candidates() > 0
        self.update_lookup_table(self.__lookup_table, show)


    def focus_in(self):
        self.register_properties(self.__prop_list)

    def focus_out(self):
        pass

    def reset(self):
        pass

    def property_activate(self, prop_name):
        print "PropertyActivate(%s)" % prop_name

