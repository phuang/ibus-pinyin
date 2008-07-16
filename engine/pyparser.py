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

import sys
import pyutil
import pydict

class PinYinParser:
	pinyin_dict = set (pydict.PINYIN_DICT.keys () + pydict.SHENGMU_DICT.keys ())
	gb2312_pinyin_dict = pinyin_dict - set (["eng", "chua", "fe", "fiao", "liong"])
	correct_yunmu = { 
		"ing" : ("ign", "img"), "ui" : ("uei", "iu", "i"), 
		"un" : ("uen",), "iu" : ("iou", "ui"),
		"ao" : ("au", ), "ei" : ("i", ),
		"iao" : ("ioa", "ia", "i"), "ian" : ("ia", "i"), "iang" : ("ian", "ia", "i")}

	correct_table = {}
	
	def __init__ (self):
		self.init_corrent_table ()

	def init_corrent_table (self):
		if PinYinParser.correct_table:
			return
		for key, id in pydict.PINYIN_DICT.items ():
			if key[-3:] in PinYinParser.correct_yunmu:
				for yunmu in PinYinParser.correct_yunmu[key[-3:]]:
					pinyin = key[:-3] + yunmu
					if pinyin not in pydict.PINYIN_DICT:
						PinYinParser.correct_table [pinyin] = key
			if key[-2:] in PinYinParser.correct_yunmu:
				for yunmu in PinYinParser.correct_yunmu[key[-2:]]:
					pinyin = key[:-2] + yunmu
					if pinyin not in pydict.PINYIN_DICT:
						PinYinParser.correct_table [pinyin] = key

	def parse_recursive (self, string, auto_correct = True, gbk = True):
		l = min (6, len (string))
		if l == 0:
			return []
		p = None
		for i in range (l, 0, -1):
			py = string[-i:]
			
			if gbk:
				if py in self.pinyin_dict:
					p = pyutil.PinYinWord (py)
					break
			else:
				if py in self.gb2312_pinyin_dict:
					p = pyutil.PinYinWord (py)
					break
			
			if p == None and auto_correct and py in PinYinParser.correct_table:
				py = PinYinParser.correct_table[py]
				if gbk:
					if py in self.pinyin_dict:
						p = pyutil.PinYinWord (py)
						break
				else:
					if py in self.gb2312_pinyin_dict:
						p = pyutil.PinYinWord (py)
						break
		if p == None:
			raise Exception ("can not parse '%s'" % string.encode ("utf-8"))
		pys = self.parse_recursive (string[:-i], auto_correct, gbk)
		pys.append (p)
		return pys

	def parse (self, string, auto_correct = True, gbk = True):
		try:
			pys = []
			for py in string.split (u"'"):
				pys += self.parse_recursive (py, auto_correct, gbk)
			return pys
		except Exception, e:
			import traceback
			traceback.print_exc ()
			raise e

class ShuangPinParser:
	def __init__ (self, schema = "MSPY"):
		self._gbk = True
		self._schema = schema
		self._shengmu_dict, self._yunmu_dict = pydict.SHUANGPIN_SCHEMAS[self._schema]

	def parse_shuangpin_recursive (self, pys, string, auto_correct = True, gbk = True):
		if len (string) == 0:
			return []

		if len (string) == 1:
			try:
				shengmu = self._shengmu_dict[string[0]]
				if shengmu == "'":
					shengmu = ""
			except:
				raise Exception ("can not parse '%s'" % string.encode ("utf-8"))
			
			return [pyutil.PinYinWord (shengmu)]

		try:
			shengmu = self._shengmu_dict[string[0]]
			if shengmu == "'":
				shengmu = ""
			yunmu = self._yunmu_dict[string[1]]
		except:
			raise Exception ("can not parse '%s'" % string.encode ("utf-8"))

		p = None

		for i in yunmu:
			pinyin = shengmu + i
			if pinyin in PinYinParser.pinyin_dict:
				p = pyutil.PinYinWord (pinyin)
				break
		
		if p == None:
			raise Exception ("can not parse '%s'" % string.encode ("utf-8"))

		pys.append (p)
		pys = self.parse_shuangpin_recursive (pys, string[2:], auto_correct, gbk)

		return pys

	def parse (self, string, auto_correct = True, gbk = True):
		pys = []
		pys += self.parse_shuangpin_recursive (pys, string, auto_correct, gbk)
		return pys

if __name__ == "__main__":
	# parser = PinYinParser ()
	parser = ShuangPinParser ()	
	pys = parser.parse (sys.argv[1])
	print "'".join (map (str, pys))
				
