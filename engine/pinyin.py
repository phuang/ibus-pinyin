# -*- coding: utf-8 -*-
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

import ibus
from ibus import keysyms
from ibus import modifier
from ibus import interface

# from scim import IMEngine
# from scim import Attribute
import pyparser
import pysqlitedb
from specialtable import SpecialTable
from specialphrase import SpecialPhrase
import pyutil
import pydict
import scim.ascii as ascii

from gettext import dgettext
_  = lambda a : dgettext ("scim-python", a)
N_ = lambda a : a

__MAX_LEN__ = 64		# Max length of preedit pinyin

# Define colours
RGB = lambda r, g, b : (((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff))

try:
	import enchant
	__EN_DICT__ = enchant.Dict ("en_US")
except:
	class MY_DICT:
		def __init__ (self):
			pass
		def suggest (self, word):
			return []
		def check (self, word):
			return True
	__EN_DICT__ = MY_DICT ()



class PinYinEngine (interface.IEngine):
	
	# create pinyin database
	_pydb = pysqlitedb.PYSQLiteDB (user_db = "user.db")

	# create special table
	_special_phrase = SpecialPhrase ()
	_special_table = SpecialTable ()
	
	# shuang pin 
	_shuangpin = False
	_shuangpin_schema = "MSPY"

	# gbk
	_gbk = True

	# fuzzy pinyin & auto correct
	_fuzzy_pinyin = False
	_auto_correct = True
	_spell_check = True

	# colors
	_phrase_color 			= RGB (0, 0, 0)
	_user_phrase_color 		= RGB (0, 0, 0xef)
	_new_phrase_color 		= RGB (0xef, 0, 0)
	_special_phrase_color 	= RGB (0, 0xbf, 0)
	_english_phrase_color 	= RGB (0, 0xbf, 0)
	_error_eng_phrase_color	= RGB (0xef, 0, 0)

	# lookup table page size
	_page_size = 5

	# press [u] or [v] to temp English mode
	_uv_to_temp = True
	
	# press [shift] to select candidates
	_shift_select_candidates = True

	# press [-] [=] to page down & up candidates
	_equal_page_down_up = True

	# press [,] [.] to page down & up candidates
	_comma_page_down_up = True

	# auto commit
	_auto_commit = False


	def __init__ (self, dbusconn, object_path):
        super(PinYinEngine, self).__init__(dbusconn, object_path)
		
		self._lookup_table = ibus.LookupTable (PinYinEngine._page_size)
		
		self._py_parser = pyparser.PinYinParser ()
		self._user_input = UserInput (self._py_parser)
		
		# 0 = english input mode
		# 1 = chinese input mode
		self._mode = 1
		self._full_width_letter = [False, False]
		self._full_width_punct = [False, True]
		self._full_width_punct[1] = config.read ("/IMEngine/Python/PinYin/FullWidthPunct", True)

		self._committed_phrases = PhraseList ()
		self._preedit_phrases = PhraseList ()
		self.reset ()

        # init properties
        self._prop_list = ibus.PropList()
		self._status_property = ibus.Property ("status")
        self._prop_list.append (self._status_property)
		self._letter_property = ibus.Property ("full_letter")
        self._prop_list.append (self._letter_property)
		self._punct_property = ibus.Property ("full_punct")
        self._prop_list.append (self._punct_property)
		# self._shuangpin_property = ibus.Property ("shuangpin")
        # self._prop_list.append (self._shuangpin_property)
		# self._gbk_property = ibus.Property ("gbk")
        # self._prop_list.append (self._gbk_property)
		self._setup_property = ibus.Property ("setup")
        self._prop_list.append (self._setup_property)

	def _refresh_properties (self):
		if self._mode == 1: # refresh mode
			self._status_property.label = _("CN")
			self._status_property.tip = _("Switch to English mode")
		else:
			self._status_property.label = _("EN")
			self._status_property.tip = _("Switch to Chinese mode")

		if self._full_width_letter[self._mode]:
			self._letter_property.icon = "/usr/share/scim/icons/full-letter.png" 
			self._letter_property.tip = _("Switch to half letter mode")
		else:
			self._letter_property.icon = "/usr/share/scim/icons/half-letter.png" 
			self._letter_property.tip = _("Switch to full letter mode")

		if self._full_width_punct[self._mode]:
			self._punct_property.icon = "/usr/share/scim/icons/full-punct.png" 
			self._punct_property.tip = _("Switch to half punctuation mode")
		else:
			self._punct_property.icon = "/usr/share/scim/icons/half-punct.png" 
			self._punct_property.tip = _("Switch to full punctuation mode")

		# if PinYinEngine._shuangpin:
		# 	self._shuangpin_property.label = _("SHUANG")
		# 	self._shuangpin_property.tip = _("Switch to QUAN PIN")
		# else:
		# 	self._shuangpin_property.label = _("QUAN")
		# 	self._shuangpin_property.tip = _("Switch to SHUANG PIN")

		# if PinYinEngine._gbk:
		# 	self._gbk_property.label = _("GBK")
		# 	self._gbk_property.tip = _("Switch to GB2312 codeset")
		# else:
		# 	self._gbk_property.label = _("GB")
		# 	self._gbk_property.tip = _("Switch to GBK codeset")
			
		properties = (
			self._status_property, 
			self._letter_property, 
			self._punct_property, 
			# self._shuangpin_property, 
			# self._gbk_property,
			)

		for prop in properties:
			self.update_property (prop)
		

	def _change_mode (self):
		self._mode = (self._mode + 1) % 2
		self._refresh_properties ()

	def _is_input_english (self):
		return self._mode == 0

	def _update_candidates (self):
		if self._temp_english_mode:
			if self._spell_check == False:
				return
			self._english_candidates = []
			string = "".join (self._user_input.get_chars ())
			if string[0] in u"uv":
				string = string [1:]
			words = string.split ()
			if not words:
				return
			word = words[-1]
			
			if len (words) == 1 and word[0:1] in u"uv":
				word = word[1:]

			if not word.isalpha ():
				return
			if  __EN_DICT__.check (word):
				return
			self._current_word = word
			candidates = __EN_DICT__.suggest (word)
			is_same  = lambda x : x[0].isupper () == word[0].isupper ()
			self._english_candidates = filter (is_same, candidates)[:10]
			return

		if self._i_mode:
			chars = self._user_input.get_chars()[1:]
			self._candidates = self._special_phrase.lookup (u"".join (chars))
			self._candidates += self._special_table.lookup (u"".join (chars))
			return
		
		self._preedit_phrases.clear ()
		
		if len (self._user_input.get_pinyin_list ()) == 0:
			self._candidates = []
			self._special_candidates = []
			return

		if len (self._committed_phrases) == 0:
			self._special_candidates = self._special_phrase.lookup (u"".join (self._user_input.get_chars ()))
		else:
			self._special_candidates = []
			

		pinyin_list = self._user_input.get_pinyin_list ()
		pinyin_list = pinyin_list [self._committed_phrases.length_of_chars ():]


		if pinyin_list:
			self._candidates =  self._get_candidates (pinyin_list)
			self._preedit_phrases.append (self._candidates[0])

		count = self._preedit_phrases.length_of_chars ()

		while count < len (pinyin_list):
			candidate = self._get_a_candidate (pinyin_list[count:])
			self._preedit_phrases.append (candidate)
			count += candidate[pysqlitedb.YLEN]

	def _update_ui (self):
		if self._i_mode:
			preedit_string = u"".join (self._user_input.get_chars ())
			self.update_preedit_string (preedit_string)
			self.update_preedit_caret (len (preedit_string))
			self.show_preedit_string ()
			
			self.update_aux_string (u"")
			self.hide_aux_string ()
			
			self._lookup_table.clear ()
			self._lookup_table.show_cursor (True)
			if not self._candidates:
				self.hide_lookup_table ()
			else:
				for c in self._candidates:
					attrs = []
					self._lookup_table.append_candidate (c, attrs)
				self.update_lookup_table (self._lookup_table)
				self.show_lookup_table ()
			return 
			
		if self._temp_english_mode:
			preedit_string = u"".join (self._user_input.get_chars ())
			if preedit_string [0:1] in (u"v", u"u"):
				preedit_string = " " + preedit_string[1:]
			else:
				preedit_string = " " + preedit_string

			words = preedit_string.split()
			if words:
				aux_string = words[-1]
			else:
				aux_string = u""

			if preedit_string and self._spell_check:
				self.update_preedit_string (preedit_string)
				self.update_preedit_caret (len (preedit_string))
				self.show_preedit_string ()
				if  not __EN_DICT__.check (aux_string): 
					attrs = [Attribute (0, len (aux_string), scim.ATTR_FOREGROUND, PinYinEngine._error_eng_phrase_color)]
				else:
					attrs = None
				self.update_aux_string (aux_string, attrs)
				self.show_aux_string ()
			else:
				self.update_preedit_string (u"")
				self.update_preedit_caret (0)
				self.hide_preedit_string ()
				self.update_aux_string (u"")
				self.hide_aux_string ()


			self._lookup_table.clear ()
			self._lookup_table.show_cursor (False)
			if not self._english_candidates:
				self.hide_lookup_table ()
			else:
				for c in self._english_candidates:
					attrs = [Attribute (0, len (preedit_string), scim.ATTR_FOREGROUND, PinYinEngine._english_phrase_color)]
					self._lookup_table.append_candidate (c, attrs)
				self.update_lookup_table (self._lookup_table)
				self.show_lookup_table ()
				
			return

		if len (self._candidates) == 0:
			self.hide_lookup_table ()
		else:
			self._lookup_table.clear ()
			candidates = self._candidates[:]
			if len (self._preedit_phrases) != 1: # we need display the automatically created new phrase
				preedit_string = self._preedit_phrases.get_string ()
				attrs = [Attribute (0, len (preedit_string), scim.ATTR_FOREGROUND, PinYinEngine._new_phrase_color)]
				self._lookup_table.append_candidate (preedit_string, attrs)
			else:
				c = candidates[0]
				if c[pysqlitedb.FREQ] == None: # This phrase was created by user.
					attrs = [Attribute (0, c[pysqlitedb.YLEN], scim.ATTR_FOREGROUND, PinYinEngine._user_phrase_color)]
				else:
					attrs = [Attribute (0, c[pysqlitedb.YLEN], scim.ATTR_FOREGROUND, PinYinEngine._phrase_color)]
				self._lookup_table.append_candidate (c[pysqlitedb.PHRASE], attrs)
				del candidates[0]

			for c in self._special_candidates:
				attrs = [Attribute (0, len (c), scim.ATTR_FOREGROUND, PinYinEngine._special_phrase_color)]
				self._lookup_table.append_candidate (c, attrs)

			for c in candidates:
				if c[pysqlitedb.FREQ] == None: # This phrase was created by user.
					attrs = [Attribute (0, c[pysqlitedb.YLEN], scim.ATTR_FOREGROUND, PinYinEngine._user_phrase_color)]
				else:
					attrs = [Attribute (0, c[pysqlitedb.YLEN], scim.ATTR_FOREGROUND, PinYinEngine._phrase_color)]
				self._lookup_table.append_candidate (c[pysqlitedb.PHRASE], attrs)
			self._lookup_table.show_cursor (True)
			self._lookup_table.set_cursor_pos (0)
			self.update_lookup_table (self._lookup_table)
			self.show_lookup_table ()
		
		committed_string = self._committed_phrases.get_string ()
		invalid_pinyin = self._user_input.get_invalid_string ()
		preedit_string = " ".join ([committed_string, self._preedit_phrases.get_string (), invalid_pinyin])
		preedit_string = preedit_string.strip ()

		if preedit_string:
			self.update_preedit_string (preedit_string)
			self.update_preedit_caret (len (preedit_string))
			self.show_preedit_string ()
		else:
			self.update_preedit_string (u"")
			self.update_preedit_caret (0)
			self.hide_preedit_string ()
			
		if committed_string or len (self._user_input) != 0:
			pinyin_list = self._user_input.get_pinyin_list ()
			pinyin_list = pinyin_list [len (committed_string):]
			pinyin_list = map (str, pinyin_list)
			if committed_string:
				aux_string = u"".join ([committed_string, u" ", u"'".join (pinyin_list)])
			else:
				aux_string = u"'".join (pinyin_list)
				
			if aux_string:
				self.update_aux_string (aux_string)
				self.show_aux_string ()
			else:
				self.update_aux_string (u"")
				self.hide_aux_string ()
		else:
			self.update_aux_string (u"")
			self.hide_aux_string ()

	def _update (self):
		self._update_candidates ()
			
		self._update_ui ()
	
	def _is_gb2312 (self, record):
		try:
			record[pysqlitedb.PHRASE].encode ("gb2312")
		except:
			return False
		return True

	def _get_candidates (self, pinyin_list):
		candidates = []
		
		for i in range (len (pinyin_list), 0, -1):
			candidates += self._pydb.select_words_by_pinyin_list (pinyin_list[:i], PinYinEngine._fuzzy_pinyin)
		if not PinYinEngine._gbk:
			candidates = filter (self._is_gb2312, candidates)
		return candidates

	def _get_a_candidate (self, pinyin_list):
		for i in range (len (pinyin_list), 0, -1):
			candidates = self._pydb.select_words_by_pinyin_list (pinyin_list[:i], PinYinEngine._fuzzy_pinyin)
			if not PinYinEngine._gbk:
				candidates = filter (self._is_gb2312, candidates)
			if candidates:
				return candidates[0]
		return None


	def _append_char (self, char):
		self._user_input.append (char)
		self._committed_phrases.clear ()
		self._update ()

		return True

	def _pop_char (self):
		if len (self._user_input) == 0:
			return False
		if len (self._committed_phrases) != 0:
			self._committed_phrases.pop ()
		else:
			self._user_input.pop ()
		self._update ()
		
		return True

	def _match_hotkey (self, key, code, mask):
		
		if key.code == code and key.mask == mask:
			if self._prev_key and key.code == self._prev_key.code and key.mask & modifier.RELEASE_MASK:
				return True
			if not key.mask & modifier.RELEASE_MASK:
				return True

		return False

	def _internal_process_key_event (self, key):
		
		# When CapsLock is lock, we ignore all key events
		if key.mask & modifier.LOCK_MASK:
			return False
		
		# Match mode switch hotkey
		if self._match_hotkey (key, keysyms.Shift_L, modifier.SHIFT_MASK + modifier.RELEASE_MASK) or \
			self._match_hotkey (key, keysyms.Shift_R, modifier.SHIFT_MASK + modifier.RELEASE_MASK):
			if self._candidates and not self._is_input_english () and PinYinEngine._shift_select_canidates:
				index = self._lookup_table.get_current_page_start ()
				if key.code == keysyms.Shift_L:
					index += 1
				else:
					index += 2
				result = self._commit_candidate (index)
				if result:
					if self._committed_special_phrase:
						self.commit_string (self._committed_special_phrase)
					else:
						commit_phrases = self._committed_phrases.get_phrases ()
						commit_string = self._committed_phrases.get_string ()
						self.commit_string (commit_string + self._user_input.get_invalid_string ())
						
						# adjust phrase freq and create new phrase
						self._pydb.commit_phrases (commit_phrases)
						if len (commit_phrases) > 1:
							self._pydb.new_phrase (commit_phrases)
				return True
			else:
				self.trigger_property ("status")
				self.reset ()
			return True
		
		# Match full half letter mode switch hotkey
		if self._match_hotkey (key, keysyms.space, modifier.SHIFT_MASK):
			self.trigger_property ("full_letter")
			return True
		
		# Match full half punct mode switch hotkey
		if self._match_hotkey (key, keysyms.period, modifier.CONTROL_MASK):
			self.trigger_property ("full_punct")
			return True

		# Match remove user phrase hotkeys
		for code in xrange (keysyms.1, keysyms.1 + PinYinEngine._page_size):
			if self._match_hotkey (key, code, modifier.CONTROL_MASK):
				index = code - keysyms.1 + self._lookup_table.get_current_page_start ()
				return self._remove_candidate (index)

		# we ignore all hotkeys
		if key.mask & (modifier.CONTROL_MASK + modifier.ALT_MASK):
			return False

		# Ignore key release event
		if key.mask & modifier.RELEASE_MASK:
			return True
		
		if self._is_input_english ():
			return self._english_mode_process_key_event (key)
		else:
			if self._temp_english_mode:
				return self._temp_english_mode_process_key_event (key)
			elif self._i_mode:
				return self._i_mode_process_key_event (key)
			else:
				return self._chinese_mode_process_key_event (key)

	def _convert_to_full_width (self, c):
		if c == u".":
			return u"\u3002"
		elif c == u"\\":
			return u"\u3001"
		elif c == u"^":
			return u"\u2026\u2026"
		elif c == u"_":
			return u"\u2014\u2014"
		elif c == u"$":
			return u"\uffe5"
		elif c == u"\"":
			self._double_quotation_state = not self._double_quotation_state
			if self._double_quotation_state:
				return u"\u201c"
			else:
				return u"\u201d"
		elif c == u"'":
			self._single_quotation_state = not self._single_quotation_state
			if self._single_quotation_state:
				return u"\u2018"
			else:
				return u"\u2019"
 
 		elif c == u"<":
 			if not self._is_input_english ():
 				return u"\u300a"
 		elif c == u">":
 			if not self._is_input_english ():
 				return u"\u300b"
 		
		return scim.unichar_half_to_full (c)
	
	def _english_mode_process_key_event (self, key):
		# ignore if key code is not a normal ascii char
		if key.code >= 128:
			return False

		c = unichr (key.code)
		if ascii.ispunct (key.code): # if key code is a punctation
			if self._full_width_punct[self._mode]:
				self.commit_string (self._convert_to_full_width (c))
				return True
			else:
				self.commit_string (c)
				return True
			
		if self._full_width_letter[self._mode]: # if key code is a letter or digit
			self.commit_string (self._convert_to_full_width (c))
			return True
		else:
			self.commit_string (c)
			return True
		
		# should not reach there
		return False

	def _i_mode_process_key_event (self, key):
		if key.code in (keysyms.Return, keysyms.KP_Enter):
			commit_string = u"".join (self._user_input.get_chars ())
			self.commit_string (commit_string)
			return True
		elif key.code == keysyms.BackSpace and len (self._user_input) != 0:
			self._user_input.pop ()
			if len (self._user_input) == 0:
				self._i_mode = False
			self._update ()
			return True
		elif key.code == keysyms.Escape:
			self._user_input.clear ()
			self._i_mode = False
			self._update ()
			return True
		elif key.code >= keysyms.1 and key.code <= keysyms.9:
			if not self._candidates:
				return True
			index = key.code - keysyms.1
			if index >= PinYinEngine._page_size:
				return True
			index += self._lookup_table.get_current_page_start ()
			if index >= len (self._candidates):
				return True
			self.commit_string (self._candidates[index])
			return True
		elif key.code in (keysyms.KP_Space, keysyms.space):
			if not self._candidates:
				return True
			index = self._lookup_table.get_cursor_pos ()
			if index >= len (self._candidates):
				return True
			self.commit_string (self._candidates[index])
			return True
		elif key.code == keysyms.Down:
			self.lookup_table_cursor_down ()
			return True
		elif key.code == keysyms.Up:
			self.lookup_table_cursor_up ()
			return True
		elif key.code == keysyms.Page_Down and self._candidates: # press PageDown
			self.lookup_table_page_down ()
			return True
		elif key.code == keysyms.Page_Up and self._candidates: # press PageUp
			self.lookup_table_page_up ()
			return True
		elif key.code == keysyms.period and self._candidates and PinYinEngine._comma_page_down_up: # press .
			self.lookup_table_page_down ()
			return True
		elif key.code == keysyms.comma and self._candidates and PinYinEngine._comma_page_down_up: # press ,
			self.lookup_table_page_up ()
			return True
		elif key.code == keysyms.equal and self._candidates and PinYinEngine._equal_page_down_up: # press =
			self.lookup_table_page_down ()
			return True
		elif key.code == keysyms.minus and self._candidates and PinYinEngine._equal_page_down_up: # press -
			self.lookup_table_page_up ()
			return True

		if key.code >= 128:
			return True
		
		self._user_input.append (unichr (key.code))
		self._update ()
		
		return True

	def _temp_english_mode_process_key_event (self, key):
		if key.code in (keysyms.Return, keysyms.KP_Enter):
			commit_string = u"".join (self._user_input.get_chars ())
			if commit_string[0] in (u"v", u"u"):
				commit_string = commit_string[1:]
			self.commit_string (commit_string)
			return True
		elif key.code == keysyms.BackSpace and len (self._user_input) != 0:
			self._user_input.pop ()
			if len (self._user_input) == 0:
				self._temp_english_mode = False
			self._update ()
			return True
		elif key.code == keysyms.Escape:
			self._user_input.clear ()
			self._temp_english_mode = False
			self._update ()
			return True
		elif key.code >= keysyms.1 and key.code <= keysyms.9 and self._english_candidates:
			index = key.code - keysyms.1
			if index >= PinYinEngine._page_size:
				return False
			index += self._lookup_table.get_current_page_start ()
			if index >=0 and index < len (self._english_candidates):
				for i in xrange (0, len (self._current_word)):
					self._user_input.pop ()
				for c in self._english_candidates[index]:
					self._user_input.append (c)
				self._update ()
				return True
			return False
		elif key.code in (keysyms.Page_Down, ) and self._english_candidates:
			self.lookup_table_page_down ()
			return True
		elif key.code in (keysyms.Page_Up, ) and self._english_candidates:
			self.lookup_table_page_up ()
			return True

		if key.code >= 128:
			return True

		self._user_input.append (unichr (key.code))
		self._update ()

		return True

	def _chinese_mode_process_key_event (self, key):
		# define a condition half to full width translate functions
		cond_letter_translate = lambda (c): \
			self._convert_to_full_width (c) if self._full_width_letter [self._mode] else c
		cond_punct_translate = lambda (c): \
			self._convert_to_full_width (c) if self._full_width_punct [self._mode] else c

		if key.code in (keysyms.Return, keysyms.KP_Enter):
			if len (self._user_input) == 0: # forward Return if inputed chars is empty
				return False
			chars = map (cond_letter_translate, self._user_input.get_chars ())
			commit_string = u"".join (chars)
			self.commit_string (commit_string)
			return True
		elif key.code == keysyms.Escape:
			if len (self._user_input) != 0:
				self.reset ()
				return True
			return False
		elif key.code == keysyms.Down:
			return self.lookup_table_cursor_down ()
		elif key.code == keysyms.Up:
			return self.lookup_table_cursor_up ()
		elif key.code == keysyms.BackSpace:
			return self._pop_char ()
		elif key.code >= keysyms.1 and key.code <= keysyms.9:
			if not self._candidates:
				self.commit_string (cond_letter_translate (unichr (key.code)))
			else:
				index = key.code - keysyms.1
				if index >= PinYinEngine._page_size:
					return True
				index += self._lookup_table.get_current_page_start ()
				result = self._commit_candidate (index)
				if result:
					if self._committed_special_phrase:
						self.commit_string (self._committed_special_phrase)
					else:
						commit_phrases = self._committed_phrases.get_phrases ()
						commit_string = self._committed_phrases.get_string ()
						self.commit_string (commit_string + self._user_input.get_invalid_string ())
						
						# adjust phrase freq and create new phrase
						self._pydb.commit_phrases (commit_phrases)
						if len (commit_phrases) > 1:
							self._pydb.new_phrase (commit_phrases)
			return True
		elif key.code in (keysyms.KP_Space, keysyms.space):
			if not self._candidates:
				self.commit_string (cond_letter_translate (u" "))
			else:
				index = self._lookup_table.get_cursor_pos ()
				result = self._commit_candidate (index)
				if result:
					if self._committed_special_phrase:
						self.commit_string (self._committed_special_phrase)
					else:
						commit_phrases = self._committed_phrases.get_phrases ()
						commit_string = self._committed_phrases.get_string ()
						self.commit_string (commit_string + self._user_input.get_invalid_string ())
						
						# adjust phrase freq and create new phrase
						self._pydb.commit_phrases (commit_phrases)
						if len (commit_phrases) > 1:
							self._pydb.new_phrase (commit_phrases)
			return True
		elif key.code == keysyms.Page_Down and self._candidates: # press PageDown
			self.lookup_table_page_down ()
			return True
		elif key.code == keysyms.equal and self._candidates and PinYinEngine._equal_page_down_up: # press equal
			self.lookup_table_page_down ()
			return True
		elif key.code == keysyms.period and self._candidates and PinYinEngine._comma_page_down_up: # press period
			self.lookup_table_page_down ()
			return True
		elif key.code == keysyms.Page_Up and self._candidates: # press PageUp
			self.lookup_table_page_up ()
			return True
		elif key.code == keysyms.minus and self._candidates and PinYinEngine._equal_page_down_up: # press minus
			self.lookup_table_page_up ()
			return True
		elif key.code == keysyms.comma and self._candidates and PinYinEngine._comma_page_down_up: #press comma
			self.lookup_table_page_up ()
			return True

		elif key.code in (keysyms.bracketleft, keysyms.bracketright) and self._candidates:
			cursor_pos = self._lookup_table.get_cursor_pos ()
			candidate = self._candidates[cursor_pos]
			if key.code == keysyms.bracketleft:
				i = 0
			else:
				i = len (candidate[pysqlitedb.PHRASE]) - 1
			char = candidate[pysqlitedb.PHRASE][i]
			if i < 4:
				pinyin_id = candidate[pysqlitedb.Y0 + i]
				shengmu_id = candidate[pysqlitedb.S0 + i]
			else:
				pinyin = candidate[pysqlitedb.YX].split ("'")[-1]
				word = pyutil.PinYinWord (pinyin)
				pinyin_id = word.get_pinyin_id ()
				shengmu_id = word.get_sheng_mu_id ()

			self._pydb.commit_char (char, pinyin_id, shengmu_id)
			self.commit_string (char)
			return True
		elif PinYinEngine._uv_to_temp and not PinYinEngine._shuangpin \
		     and len (self._user_input) == 0 \
		     and key.code in (keysyms.v, keysyms.u):
			self._user_input.append (unichr (key.code))
			self._temp_english_mode = True
			self._update ()
			return True
		elif key.code >= keysyms.A and key.code <= keysyms.Z and len (self._user_input) == 0:
			self._user_input.append (unichr (key.code))
			self._temp_english_mode = True
			self._update ()
			return True
		elif not PinYinEngine._shuangpin \
			 and len (self._user_input) == 0 \
			 and key.code == keysyms.i:
			self._user_input.append (unichr (key.code))
			self._i_mode = True
			self._update ()
			return True
		elif (key.code >= keysyms.a and key.code <= keysyms.z) or \
			(key.code == keysyms.apostrophe and len (self._user_input) != 0) or \
			(key.code == keysyms.semicolon and len (self._user_input) != 0 and PinYinEngine._shuangpin) :
			return self._append_char (unichr (key.code))
		elif key.code <= 127:
			if len (self._user_input) != 0:
				if PinYinEngine._auto_commit:
					self._chinese_mode_process_key_event (scim.KeyEvent (keysyms.space, 0, key.mask))	
				else:
					return True
			c = chr (key.code)
			if c == "." and self._prev_char and self._prev_char.isdigit () \
				and self._prev_key and chr (self._prev_key.code) == self._prev_char:
				self.commit_string (u".")
			elif ascii.ispunct (key.code):
				self.commit_string (cond_punct_translate (unichr (key.code)))
			else:
				self.commit_string (cond_letter_translate (unichr (key.code)))
			return True
		
		return False

	def _commit_candidate (self, i):
		if i == 0:
			for phrase in self._preedit_phrases.get_phrases ():
				self._committed_phrases.append (phrase)
			return True
			
		if i >=1 and i <= len (self._special_candidates):
			self._committed_special_phrase = self._special_candidates [i - 1]
			return True
			
		if len (self._preedit_phrases) != 1:
			i -= 1

		i -= len (self._special_candidates)

		if i >= len (self._candidates):
			return False

		self._committed_phrases.append ( self._candidates[i])
		pinyin_list = self._user_input.get_pinyin_list ()
		
		if self._committed_phrases.length_of_chars () == len (pinyin_list):
			return True
		
		self._update ()

		return False

	def _remove_candidate (self, i):
		if i >= 1:
			i -= len (self._special_candidates)

		if len (self._preedit_phrases) != 1:
			i -= 1

		if i >= len (self._candidates) or i < 0:
			return False

		if self._candidates[i][pysqlitedb.FREQ] != None: # This phrase was not create by user.
			return False

		candidate = self._candidates.pop (i)
		self._pydb.remove_phrase (candidate)
		self._update ()

		return True

	def process_key_event (self, key):
		result = self._internal_process_key_event (key)
		self._prev_key = key
		return result

	def commit_string (self, string):
		self._temp_english_mode = False
		self._i_mode = False
		self._candidates = []
		self._english_candidates = []
		self._cursor = 0
		self._user_input.clear ()
		self._preedit_string = u""
		self._committed_phrases.clear ()
		self._committed_special_phrase = u""
		IMEngine.commit_string (self, string)
		self._prev_char = string[-1]
		self._update ()

	def move_preedit_caret (self, pos):
		IMEngine.move_preedit_caret (self, pos)
	
	def select_candidate (self, index):
		IMEngine.select_candidate (self, index)

	def update_lookup_table_page_size (self, page_size):
		IMEngine.update_lookup_table_page_size (self, page_size)

	def lookup_table_page_up (self):
		if self._lookup_table.page_up ():
			self.update_lookup_table (self._lookup_table)
			return True
		
		IMEngine.lookup_table_page_up (self)
		return True

	def lookup_table_page_down (self):
		if self._lookup_table.page_down ():
			self.update_lookup_table (self._lookup_table)
			return True
		
		IMEngine.lookup_table_page_down (self)
		return True

	def lookup_table_cursor_up (self):
		if len (self._candidates) == 0:
			return False
		
		if self._lookup_table.cursor_up ():
			self.update_lookup_table (self._lookup_table)
		return True

	def lookup_table_cursor_down (self):
		if len (self._candidates) == 0:
			return False
		
		if self._lookup_table.cursor_down ():
			self.update_lookup_table (self._lookup_table)
		return True

	def reset (self):
		self._temp_english_mode = False
		self._i_mode = False
		self._user_input.clear ()
		self._committed_phrases.clear ()
		self._committed_special_phrase = u""
		self._preedit_string = u""
		self._special_candidates = []
		self._candidates = []
		self._english_candidates = []
		self._cursor = 0
		self._double_quotation_state = False
		self._single_quotation_state = False
		self._prev_key = None
		self._prev_char = None
		self._update ()
		IMEngine.reset (self)

	def focus_in (self):
		self._init_properties ()
		if PinYinEngine._shuangpin:
			self._py_parser = pyparser.ShuangPinParser (PinYinEngine._shuangpin_schema)
		else:
			self._py_parser = pyparser.PinYinParser ()
		self._user_input.set_parser (self._py_parser)
		self._user_input.set_gbk (PinYinEngine._gbk)
		self._user_input.set_auto_correct (PinYinEngine._auto_correct)
		IMEngine.focus_in (self)
		self._update ()
	
	def focus_out (self):
		self.reset ()
		IMEngine.focus_out (self)

	def trigger_property (self, property):
		if property == "status":
			self._change_mode ()
		elif property == "full_letter":
			self._full_width_letter [self._mode] = not self._full_width_letter [self._mode]
			self._refresh_properties ()
		elif property == "full_punct":
			self._full_width_punct [self._mode] = not self._full_width_punct [self._mode]
			self._refresh_properties ()
		elif property == "shuangpin":
			PinYinEngine._shuangpin = not PinYinEngine._shuangpin
			self.reset ()
			if PinYinEngine._shuangpin:
				self._py_parser = pyparser.ShuangPinParser (PinYinEngine._shuangpin_schema)
			else:
				self._py_parser = pyparser.PinYinParser ()
			self._user_input.set_parser (self._py_parser)
			self._config.write ("/IMEngine/Python/PinYin/ShuangPin", PinYinEngine._shuangpin)
			self._refresh_properties ()
		elif property == "gbk":
			PinYinEngine._gbk = not PinYinEngine._gbk
			self.reset ()
			self._config.write ("/IMEngine/Python/PinYin/SupportGBK", PinYinEngine._gbk)
			self._refresh_properties ()

		elif property == "setup":
			self.start_helper ("eebeecd7-cb22-48f4-8ced-70e42dad1a79")

		IMEngine.trigger_property (self, property)

	def process_helper_event (self, helper_uuid, trans):
		IMEngine.process_helper_event (self, helper_uuid, trans)

	def update_client_capabilities (self, cap):
		IMEngine.update_client_capabilities (self, cap)

	def reload_config (self, config):
		self._lookup_table.set_page_size (PinYinEngine._page_size)
		self.focus_in ()

class UserInput:
	"UserInput holds user input chars"
	def __init__ (self, parser, max_length = __MAX_LEN__):
		self._parser = parser
		self._max_length = max_length
		self._auto_correct = True
		self._gbk = True
		self._chars = ([], [])
		self._pinyin_list = []


	def clear (self):
		self._chars = ([], [])
		self._pinyin_list = []

	def set_parser (self, parser):
		self.clear ()
		self._parser = parser

	def set_gbk (self, gbk):
		self._gbk = gbk
		self.clear ()

	def set_auto_correct (self, auto_correct):
		self._auto_correct = auto_correct
		self.clear ()

	def get_pinyin_list (self):
		return self._pinyin_list

	def get_chars (self):
		return self._chars[0] + self._chars[1]

	def get_invalid_chars (self):
		return self._chars[1]

	def get_invalid_string (self):
		return "".join (self._chars[1])

	def append (self, c):
		if len (self._chars[0]) + len (self._chars[1])  == self._max_length:
			return
			
		if self._chars[1]:
			self._chars[1].append (c)
		else:
			try:
				self._pinyin_list = self._parser.parse ("".join (self._chars[0] + [c]), self._auto_correct, self._gbk)
				self._chars[0].append (c)
			except:
				self._chars[1].append (c)

	def pop (self):
		resutl = []
		if len (self._chars[1]) != 0:
			return self._chars[1].pop ()
		elif len (self._chars[0]) != 0:
			c = self._chars[0].pop ()
			if len (self._chars[0]) != 0:
				self._pinyin_list = self._parser.parse ("".join (self._chars[0]), self._auto_correct, self._gbk)
			else:
				self._pinyin_list = []
			return c
		else:
			return ""

	def __len__ (self):
		return len (self._chars[0]) + len (self._chars[1])
	
class PhraseList:
	"""PhraseList contains phrases"""
	def __init__ (self):
		self._list = []
		self._length_of_chars = 0

	def clear (self):
		"""Remove all phrases from the list"""
		self._list = []
		self._length_of_chars = 0

	def append (self, phrase):
		"""Append a phrase into the list"""
		self._list.append (phrase)
		self._length_of_chars += phrase[pysqlitedb.YLEN]

	def pop (self):
		phrase = self._list.pop ()
		self._length_of_chars -= phrase[pysqlitedb.YLEN]
		return phrase

	def count (self):
		"""Return count of phrases in the list"""
		return len (self._list)

	def length_of_chars (self):
		"""Return number of chars in all phrases in the list"""
		return self._length_of_chars

	def get_phrases (self):
		"""Return all phrases"""
		return self._list
	
	def get_string (self):
		"""Join all phrases into a string object and return it."""
		get_phrase = lambda x: x[pysqlitedb.PHRASE]
		return u"".join (map (get_phrase, self._list))

	def __str__ (self):
		return self.get_string ().encode ("utf8")

	def __len__ (self):
		return len (self._list)

	def reload_config (self, config):
		PinYinEngine._shuangpin_schema = \
			config.read ("/IMEngine/Python/PinYin/ShuangPinSchema", "MSPY")
		if PinYinEngine._shuangpin_schema not in pydict.SHUANGPIN_SCHEMAS:
			PinYinEngine._shuangpin_schema = "MSPY"

		PinYinEngine._fuzzy_pinyin = \
			config.read ("/IMEngine/Python/PinYin/FuzzyPinYin", False)
		PinYinEngine._auto_correct = \
			config.read ("/IMEngine/Python/PinYin/AutoCorrect", True)
		PinYinEngine._spell_check = \
			config.read ("/IMEngine/Python/PinYin/AutoCorrect", True)
		PinYinEngine._page_size = \
			config.read ("/IMEngine/Python/PinYin/PageSize", 5)
		if PinYinEngine._page_size < 1 or PinYinEngine._page_size > 9:
			PinYinEngine._page_size = 5
		PinYinEngine._gbk = \
			config.read ("/IMEngine/Python/PinYin/SupportGBK", True)
		PinYinEngine._shuangpin = \
			config.read ("/IMEngine/Python/PinYin/ShuangPin", False)

		PinYinEngine._phrase_color = \
			config.read ("/IMEngine/Python/PinYin/PhraseColor", PinYinEngine._phrase_color)
		PinYinEngine._new_phrase_color = \
			config.read ("/IMEngine/Python/PinYin/NewPhraseColor", PinYinEngine._new_phrase_color)
		PinYinEngine._user_phrase_color = \
			config.read ("/IMEngine/Python/PinYin/UserPhraseColor", PinYinEngine._user_phrase_color)
		PinYinEngine._special_phrase_color = \
			config.read ("/IMEngine/Python/PinYin/SpecialPhraseColor", PinYinEngine._special_phrase_color)
		PinYinEngine._english_phrase_color = \
			config.read ("/IMEngine/Python/PinYin/EnglishPhraseColor", PinYinEngine._english_phrase_color)
		PinYinEngine._error_eng_phrase_color = \
			config.read ("/IMEngine/Python/PinYin/ErrorEnglishPhraseColor", PinYinEngine._error_eng_phrase_color)
		PinYinEngine._uv_to_temp = \
			config.read ("/IMEngine/Python/PinYin/UVToTemp", PinYinEngine._uv_to_temp)
		PinYinEngine._shift_select_canidates = \
			config.read ("/IMEngine/Python/PinYin/ShiftSelectCandidates", PinYinEngine._shift_select_candidates)
		PinYinEngine._comma_page_down_up = \
			config.read ("/IMEngine/Python/PinYin/CommaPageDownUp", PinYinEngine._comma_page_down_up)
		PinYinEngine._equal_page_down_up = \
			config.read ("/IMEngine/Python/PinYin/EqualPageDownUp", PinYinEngine._equal_page_down_up)
		PinYinEngine._auto_commit = \
			config.read ("/IMEngine/Python/PinYin/AutoCommit", PinYinEngine._auto_commit)


