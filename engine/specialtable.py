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
import os.path
import time

class SpecialTable:
	_dict = None
	def __init__ (self):
		if SpecialTable._dict == None:
			self._load_table ()

	def _load_table (self):
		_dict = {}
		def parse_table (name, _dict):
			if not os.path.isfile (name):
				return
			for l in file (name):
				l = l.strip ()
				if l == "" or l[0] == "#":
					continue
				key, values = l.decode ("utf8").split (u"=")
				key = key.strip ()
				values = map (lambda x: x.decode ("utf8"), eval (values + u","))
				if key not in _dict:
					_dict[key] = []
				_dict[key] += list (values)
		name = os.path.join (os.path.dirname (__file__), "special_table")
		try:
			parse_table (name, _dict)
		except Exception, e:
			print e
		name = os.path.expanduser ("~/.scim/scim-python/pinyin/special_table")
		try:
			parse_table (name, _dict)
		except Exception, e:
			print e
		SpecialTable._dict = _dict

	def lookup (self, key):
		if key in SpecialTable._dict:
			return  SpecialTable._dict[key][:]
		keys = SpecialTable._dict.keys ()
		keys = filter (lambda k: k.startswith(key), keys)
		if len (keys) == 1:
			return SpecialTable._dict.get (keys[0], [])[:]
		else:
			return []

if __name__ == "__main__":
	SpecialTable ()._load_table ()
	print SpecialTable._dict

