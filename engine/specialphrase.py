# vim: set noet ts=4:
# -*- coding: utf-8 -*-
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
import os.path
import time

class SpecialPhrase:
	_dict = None
	def __init__ (self):
		if SpecialPhrase._dict == None:
			self._load_table ()
			SpecialPhrase._dict = self._dict
		else:
			self._dict = SpecialPhrase._dict	

	def _load_table (self):
		self._dict = {}
		name = os.path.join (os.path.dirname (__file__), "special_phrase")
		for l in file (name):
			l = l.strip ()
			if l == "" or l[0] == "#":
				continue
			py, phrase = l.split ("\t")
			phrase = unicode (phrase, "utf8")
			if py not in self._dict:
				self._dict[py] = []
			self._dict[py].append (phrase)

	def lookup (self, py):
		result = []
		now = time.localtime ()
		weeks1 = (u"一", u"二", u"三", u"四", u"五", u"六", u"日")
		weeks2 = (u"一", u"二", u"三", u"四", u"五", u"六", u"天")
		values = {
			"year" : now[0],
			"month" : now[1],
			"day" : now[2],
			"hour_24" : now[3],
			"minute" : now[4],
			"second" : now[5],
			"week1" : weeks1[now[6]],
			"week2" : weeks2[now[6]],
		}
		if py in self._dict:
			for phrase in self._dict[py]:
				if phrase[0] == "#":
					phrase = phrase[1:] % values
				if phrase not in result:
					result.append (phrase)
		return result

if __name__ == "__main__":
	SpecialPhrase ()._load_table ()

