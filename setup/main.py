# -*- coding: utf-8 -*-
# vim: set noet ts=4:
#
# scim-python
#
# Copyright (c) 2007-2008 Huang Peng <shawn.p.huang@gmail.com>
#
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this program; if not, write to the
# Free Software Foundation, Inc., 59 Temple Place, Suite 330,
# Boston, MA  02111-1307  USA
#
# $Id: $
#
import os.path as path
import scim
import gobject
import gtk
import gtk.gdk as gdk
import gtk.glade as glade
import sys

from gettext import dgettext
_ = lambda a : dgettext ("scim-python", a)

try:
    from PYDict import *
except:
    pathname = path.dirname (__file__)
    pathname = path.abspath(pathname)
    pathname = path.join (pathname, "../../engine/PinYin")
    pathname = path.abspath(pathname)
    sys.path.append(pathname)
    from PYDict import *

RGB_COLOR = lambda c : ((c.red & 0xff00) << 8) + (c.green & 0xff00) + ((c.blue & 0xff00) >> 8)
GDK_COLOR = lambda c : gdk.Color (((c >> 16) & 0xff) * 256, ((c >> 8) & 0xff) * 256, (c & 0xff) * 256)
RGB = lambda r, g, b : ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff)


class SetupUI ():
	def __init__ (self, helper_info):
		self._helper_info = helper_info
		self._helper_agent = scim.HelperAgent ()
		self._need_reload_config = False
		
		self._options = {
			"SupportGBK" :		[True, self._checkbutton_op],
			"ShuangPin" :		[False, self._checkbutton_op],
			"AutoCorrect" :		[True, self._checkbutton_op],
			#FuzzyPinYin Hacking by YW
			"FuzzyPinYin" :		[False, self._checkbutton_op],#0
			"FuzzyS_Sh" :		[False, self._checkbutton_op],#1
            "FuzzyC_Ch" :		[False, self._checkbutton_op],#2
            "FuzzyZ_Zh" :		[False, self._checkbutton_op],#3
            "FuzzyL_N" :		[False, self._checkbutton_op],#4
            "FuzzyIn_Ing" :		[False, self._checkbutton_op],#5
			"FuzzyEn_Eng" :		[False, self._checkbutton_op],#6
			"FuzzyAn_Ang" :		[False, self._checkbutton_op],#7
			
            "SpellCheck" :		[True, self._checkbutton_op],
			"UVToTemp" :		[True, self._checkbutton_op],
			"ShiftSelectCandidates" :
								[True, self._checkbutton_op],
			
			"CommaPageDownUp" :	[True, self._checkbutton_op],
			"EqualPageDownUp" :	[True, self._checkbutton_op],
			"AutoCommit" :		[False, self._checkbutton_op],
			
			"PhraseColor" :		[RGB (0, 0, 0), self._colorbutton_op],
			"NewPhraseColor" : 	[RGB (0xef, 0, 0), self._colorbutton_op],
			"UserPhraseColor" : [RGB (0, 0, 0xbf), self._colorbutton_op],
			"SpecialPhraseColor" :
								[RGB (0, 0xbf, 0), self._colorbutton_op],
			"EnglishPhraseColor" : 	[RGB (0, 0xbf, 0), self._colorbutton_op],
			"ErrorEnglishPhraseColor" : 
								[RGB (0xef, 0, 0), self._colorbutton_op],
			"PageSize" : 		[5, self._combobox_op, range (1, 10)],
			"ShuangPinSchema" : ["MSPY", self._combobox_op, SHUANGPIN_SCHEMAS.keys ()],
		}

	def run (self, uuid, config, display):
		self._config = config
		self._uuid = uuid
		self._display = display

		self._init_agent ()
		self._init_ui ()
		self._load_config ()
		gtk.main ()
		if self._need_reload_config:
			self._config.flush ()
			self._helper_agent.reload_config ()
		self._helper_agent.close_connection ()

	def _combobox_op (self, name, opt, info):
		widget = self._xml.get_widget (name)
		if widget == None:
			print >> sys.stderr, "Can not find widget %s" % name
			return False
		if opt == "read":
			info[0] = self._read (name, info[0])
			widget.set_active (info[2].index (info[0]))
			return True
		if opt == "write":
			info[0] = info[2][widget.get_active ()]
			self._write (name, info[0])
			return True
		if opt == "check":
			return info[0] != info[2][widget.get_active ()]

		if opt == "init":
			model = gtk.ListStore (str)
			for v in info[2]:
				model.append ([_(str (v))])
			widget.set_model (model)
		return False
	
	def _colorbutton_op (self, name, opt, info):
		widget = self._xml.get_widget (name)
		if widget == None:
			print >> sys.stderr, "Can not find widget %s" % name
			return False
		if opt == "read":
			info[0] = self._read (name, info[0])
			widget.set_color (GDK_COLOR (info[0]))
			return True
		if opt == "write":
			info[0] = RGB_COLOR (widget.get_color ())
			self._write (name, info[0])
			return True
		if opt == "check":
			return info[0] != RGB_COLOR (widget.get_color ())
		return False

	def _checkbutton_op (self, name, opt, info):
		widget = self._xml.get_widget (name)
		if widget == None:
			print >> sys.stderr, "Can not find widget %s" % name
			return False

		if opt == "read":
			info[0] = self._read (name, info[0])
			widget.set_active (info[0])
			return True
		if opt == "write":
			info[0] = widget.get_active ()
			self._write (name, info[0])
			return True
		if opt == "check":
			return info[0] != widget.get_active ()
		return False

	def _read (self, name, v):
		return self._config.read ("/IMEngine/Python/PinYin/" + name, v)
	
	def _write (self, name, v):
		return self._config.write ("/IMEngine/Python/PinYin/" + name, v)
	
	def _init_ui (self):
		glade.textdomain("scim-python")
		glade_file = path.join (path.dirname (__file__), "SetupUI.glade")
		self._xml = glade.XML (glade_file)
		self._window = self._xml.get_widget ("window_main")
		for name, info in self._options.items ():
			info[1] (name, "init", info)
			info[1] (name, "read", info)
		self._xml.signal_autoconnect (self)
		self._window.show_all ()

	def _init_agent (self):
		fd = self._helper_agent.open_connection (self._helper_info, self._display)
		if fd >= 0:
			condition = gobject.IO_IN | gobject.IO_ERR | gobject.IO_HUP
			gobject.io_add_watch (fd, condition, self.on_agent_event)

	def _load_config (self):
		for name, info in self._options.items ():
			info[1] (name, "read", info)

	def _save_config (self):
		self._need_reload_config = True
		for name, info in self._options.items ():
			info[1] (name, "write", info)
	
	def _query_changed (self):
		for name, info in self._options.items ():
			if info[1] (name, "check", info):
				return True
		return False
	
	def _quit (self, need_confirm ):
		if need_confirm == False:
			gtk.main_quit ()
			return True
		else:
			dlg = gtk.MessageDialog (self._window, gtk.DIALOG_MODAL, gtk.MESSAGE_QUESTION,
						gtk.BUTTONS_YES_NO, _("Are you sure to close Python PinYin Setup without save configure?"))
			id = dlg.run ()
			dlg.destroy ()
			if id == gtk.RESPONSE_YES:
				gtk.main_quit ()
				return True
		return False

	def _optimize_user_db (self):
		import sqlite3
		dlg = gtk.MessageDialog (self._window, gtk.DIALOG_MODAL, gtk.MESSAGE_INFO, 
						gtk.BUTTONS_OK, _("The user phrases database will be reorganized! Please don't use python PinYin now."))
		dlg.run ()
		dlg.destroy ()
		
		try:
			db = sqlite3.connect (path.expanduser ("~/.scim/scim-python/pinyin/user.db"))
			sqlstring = """
				BEGIN TRANSACTION;
				CREATE TABLE tmp AS SELECT * FROM py_phrase;
				DELETE FROM py_phrase;
				INSERT INTO py_phrase SELECT * FROM tmp ORDER BY ylen, y0, y1, y2, y3, yx, phrase;
				DROP TABLE tmp;
				COMMIT;
			"""
			db.executescript (sqlstring)
			db.executescript ("VACUUM;")
		except:
			import traceback
			traceback.print_exc ()

		dlg.destroy ()
		dlg = gtk.MessageDialog (self._window, gtk.DIALOG_MODAL, gtk.MESSAGE_INFO,
		                        gtk.BUTTONS_OK, _("Reorganizing is over!"))
		dlg.run ()
		dlg.destroy ()

	# events handlers
	def on_window_main_delete_event (self, widget, event):
		result = self._quit (True)
		return True
	
	def on_button_ok_clicked (self, button):
		changed = self._query_changed ()
		if changed:
			self._save_config ()
		self._quit (False)
	
	def on_button_apply_clicked (self, button):
		self._save_config ()
	
	def on_button_cancel_clicked (self, button):
		changed = self._query_changed ()
		self._quit (changed)
	
	def on_button_optimize_db_clicked (self, button):
		self._optimize_user_db ()

	def on_value_changed (self, widget, data = None):
		if self._query_changed ():
			self._xml.get_widget ("button_apply").set_sensitive (True)
		else:
			self._xml.get_widget ("button_apply").set_sensitive (False)
			
	def on_agent_event (self, fd, condition):
		
		if condition == gobject.IO_IN:
			while self._helper_agent.has_pending_event ():
				self._helper_agent.filter_event ()
			return True
		
		elif condition == gobject.IO_ERR or condition == gobject.IO_HUP:
			gtk.main_quit ()
			return False
		
		return False

if __name__ == "__main__":
	class CC:
		def __init__ (self):
			pass

		def read (self, name, v):
			return v
		def write (self, name, v):
			pass
		def flush (self):
			pass

	helper_info = ("eebeecd7-cb22-48f4-8ced-70e42dad1a79", "", "", "", 1)
	SetupUI (helper_info). run ("eebeecd7-cb22-48f4-8ced-70e42dad1a79", CC (), ":0.0")
	
