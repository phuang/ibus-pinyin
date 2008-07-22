# vim:set noet ts=4:
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

engine_pinyin_PYTHON = \
	factory.py \
	main.py \
	pinyin.py \
	pycreatedb.py \
	pydict.py \
	pyparser.py \
	specialphrase.py \
	specialtable.py \
	pysqlitedb.py \
	pyutil.py \
	$(NULL)
engine_pinyin_DATA = \
	special_phrase \
	special_table \
	py.db \
	$(NULL)
engine_pinyindir = $(datadir)/ibus-pinyin

libexec_SCRIPTS = ibus-engine-pinyin

engine_DATA = pinyin.engine
enginedir = $(datadir)/ibus/engine

CLEANFILES = \
	*.pyc \
	$(NULL)

EXTRA_DIST = \
	ibus-engine-pinyin.in \
	pinyin.engine.in \
	$(NULL)

test:
	$(ENV) DBUS_DEBUG=true LANG=en_US PYTHONPATH=$(top_srcdir) $(PYTHON) $(srcdir)/main.py

