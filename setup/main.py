# vim:set et sts=4 sw=4:
#
# ibus-pinyin - The PinYin engine for IBus
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

import sys
from os import path
import os
import signal
import gobject
import gtk
import gtk.gdk as gdk
import gtk.glade as glade
import ibus
import gettext
import locale
from pydict import SHUANGPIN_SCHEMAS

from gettext import dgettext
_ = lambda a : dgettext("ibus-pinyin", a)

RGB_COLOR = lambda c : ((c.red & 0xff00) << 8) + (c.green & 0xff00) + ((c.blue & 0xff00) >> 8)
GDK_COLOR = lambda c : gdk.Color(((c >> 16) & 0xff) * 256, ((c >> 8) & 0xff) * 256, (c & 0xff) * 256)
RGB = lambda r, g, b : ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff)


class SetupUI ():
    def __init__ (self):
        self.__need_reload_config = False
        self.__bus = ibus.Bus()
        self.__config = self.__bus.get_config()

        self.__options = {
            "SupportGBK" :      [False, self.__checkbutton_op],
            "ShuangPin" :       [False, self.__checkbutton_op],
            "AutoCorrect" :     [True, self.__checkbutton_op],

            "FuzzyPinYin" :     [False, self.__checkbutton_op],
            "FuzzyS_Sh" :       [False, self.__checkbutton_op],
            "FuzzyC_Ch" :       [False, self.__checkbutton_op],
            "FuzzyZ_Zh" :       [False, self.__checkbutton_op],
            "FuzzyL_N" :        [False, self.__checkbutton_op],
            "FuzzyIn_Ing" :     [False, self.__checkbutton_op],
            "FuzzyEn_Eng" :     [False, self.__checkbutton_op],
            "FuzzyAn_Ang" :     [False, self.__checkbutton_op],

            "SpellCheck" :      [True, self.__checkbutton_op],
            "UVToTemp" :        [True, self.__checkbutton_op],
            "ShiftSelectCandidates" :
                                [True, self.__checkbutton_op],

            "CommaPageDownUp" : [True, self.__checkbutton_op],
            "EqualPageDownUp" : [True, self.__checkbutton_op],
            "AutoCommit" :      [False, self.__checkbutton_op],

            "PhraseColor" :     [RGB (0, 0, 0), self.__colorbutton_op],
            "NewPhraseColor" :  [RGB (0xef, 0, 0), self.__colorbutton_op],
            "UserPhraseColor" : [RGB (0, 0, 0xbf), self.__colorbutton_op],
            "SpecialPhraseColor" :
                                [RGB (0, 0xbf, 0), self.__colorbutton_op],
            "EnglishPhraseColor" :
                                [RGB (0, 0xbf, 0), self.__colorbutton_op],
            "ErrorEnglishPhraseColor" :
                                [RGB (0xef, 0, 0), self.__colorbutton_op],
            "PageSize" :        [5, self.__combobox_op, range(1, 10)],
            "ShuangPinSchema" : ["MSPY", self.__combobox_op, SHUANGPIN_SCHEMAS.keys()],
            "HalfPunctuations" : ["+-*/=%", self.__entry_op],
        }

    def run(self):
        self.__init_ui()
        self.__load_config()
        signal.signal(signal.SIGUSR1, self.__sigusr1_cb)
        gtk.main()

    def __sigusr1_cb(self, *arg):
        window = self.__xml.get_widget("window_main")
        window.present()

    def __entry_op(self, name, opt, info):
        widget = self.__xml.get_widget(name)
        if widget == None:
            print >> sys.stderr, "Can not find widget %s" % name
            return ""
        if opt == "read":
            info[0] = self.__read(name, info[0])
            widget.set_text(info[0])
            return True
        if opt == "write":
            info[0] = widget.get_text()
            self.__write(name, info[0])
            return True
        if opt == "check":
            return info[0] != widget.get_text()
        return ""

    def __combobox_op(self, name, opt, info):
        widget = self.__xml.get_widget(name)
        if widget == None:
            print >> sys.stderr, "Can not find widget %s" % name
            return False
        if opt == "read":
            info[0] = self.__read(name, info[0])
            widget.set_active(info[2].index(info[0]))
            return True
        if opt == "write":
            info[0] = info[2][widget.get_active()]
            self.__write(name, info[0])
            return True
        if opt == "check":
            return info[0] != info[2][widget.get_active()]

        if opt == "init":
            model = gtk.ListStore(str)
            for v in info[2]:
                model.append([_(str(v))])
            widget.set_model(model)
        return False

    def __colorbutton_op(self, name, opt, info):
        widget = self.__xml.get_widget(name)
        if widget == None:
            print >> sys.stderr, "Can not find widget %s" % name
            return False
        if opt == "read":
            info[0] = self.__read(name, info[0])
            widget.set_color(GDK_COLOR(info[0]))
            return True
        if opt == "write":
            info[0] = RGB_COLOR (widget.get_color())
            self.__write(name, info[0])
            return True
        if opt == "check":
            return info[0] != RGB_COLOR(widget.get_color())
        return False

    def __checkbutton_op(self, name, opt, info):
        widget = self.__xml.get_widget(name)
        if widget == None:
            print >> sys.stderr, "Can not find widget %s" % name
            return False

        if opt == "read":
            info[0] = self.__read(name, info[0])
            widget.set_active(info[0])
            return True
        if opt == "write":
            info[0] = widget.get_active()
            self.__write(name, info[0])
            return True
        if opt == "check":
            return info[0] != widget.get_active()
        return False

    def __read(self, name, v):
        return self.__config.get_value("engine/PinYin", name, v)

    def __write(self, name, v):
        return self.__config.set_value("engine/PinYin", name, v)

    def __init_ui(self):

        locale.setlocale(locale.LC_ALL, "")
        localedir = os.getenv("IBUS_LOCALEDIR")

        gettext.bindtextdomain("ibus-pinyin", localedir)
        gettext.bind_textdomain_codeset("ibus-pinyin", "UTF-8")
        glade.bindtextdomain("ibus-pinyin", localedir)
        glade.textdomain("ibus-pinyin")

        glade_file = path.join(path.dirname(__file__), "setup.glade")
        self.__xml = glade.XML (glade_file)
        self.__window = self.__xml.get_widget("window_main")
        for name, info in self.__options.items():
            info[1] (name, "init", info)
            info[1] (name, "read", info)
        self.__xml.signal_autoconnect(self)
        self.__window.show_all()

    def __load_config(self):
        for name, info in self.__options.items():
            info[1] (name, "read", info)

    def __save_config(self):
        self.__need_reload_config = True
        for name, info in self.__options.items():
            info[1] (name, "write", info)

    def __query_changed(self):
        for name, info in self.__options.items():
            if info[1] (name, "check", info):
                return True
        return False

    def __quit(self, need_confirm ):
        if need_confirm == False:
            gtk.main_quit()
            return True
        else:
            dlg = gtk.MessageDialog(self.__window, gtk.DIALOG_MODAL, gtk.MESSAGE_QUESTION,
                        gtk.BUTTONS_YES_NO, _("Are you sure to close Python PinYin Setup without save configure?"))
            id = dlg.run()
            dlg.destroy()
            if id == gtk.RESPONSE_YES:
                gtk.main_quit()
                return True
        return False

    def __optimize_user_db(self):
        import sqlite3
        dlg = gtk.MessageDialog(self.__window, gtk.DIALOG_MODAL, gtk.MESSAGE_INFO,
                        gtk.BUTTONS_OK, _("The user phrases database will be reorganized! Please don't use python PinYin now."))
        dlg.run()
        dlg.destroy()

        try:
            db = sqlite3.connect(path.expanduser("~/.ibus/pinyin/user.db"))
            sqlstring = """
                BEGIN TRANSACTION;
                CREATE TABLE tmp AS SELECT * FROM py_phrase;
                DELETE FROM py_phrase;
                INSERT INTO py_phrase SELECT * FROM tmp ORDER BY ylen, y0, y1, y2, y3, yx, phrase;
                DROP TABLE tmp;
                COMMIT;
            """
            db.executescript(sqlstring)
            db.executescript("VACUUM;")
        except:
            import traceback
            traceback.print_exc()

        dlg.destroy()
        dlg = gtk.MessageDialog(self.__window, gtk.DIALOG_MODAL, gtk.MESSAGE_INFO,
                                gtk.BUTTONS_OK, _("Reorganizing is over!"))
        dlg.run()
        dlg.destroy()

    # events handlers
    def on_window_main_delete_event(self, widget, event):
        changed = self.__query_changed()
        self.__quit(changed)

    def on_button_ok_clicked(self, button):
        changed = self.__query_changed()
        if changed:
            self.__save_config()
        self.__quit(False)

    def on_button_apply_clicked(self, button):
        self.__save_config()

    def on_button_cancel_clicked(self, button):
        changed = self.__query_changed()
        self.__quit(changed)

    def on_button_optimize_db_clicked(self, button):
        self.__optimize_user_db()

    def on_value_changed(self, widget, data = None):
        if self.__query_changed():
            self.__xml.get_widget("button_apply").set_sensitive(True)
        else:
            self.__xml.get_widget("button_apply").set_sensitive(False)


if __name__ == "__main__":
    ui = SetupUI()
    ui.run()

