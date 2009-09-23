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

setup_pinyin_PYTHON = \
	main.py \
	ibus-pinyin-preferences.glade \
	$(NULL)
setup_pinyindir = $(datadir)/ibus-pinyin/setup

libexec_SCRIPTS = ibus-setup-pinyin

CLEANFILES = \
	*.pyc \
	$(NULL)

EXTRA_DIST = \
	ibus-setup-pinyin.in \
	$(NULL)

test:
	$(ENV) DBUS_DEBUG=true \
		   IBUS_LOCALEDIR=@localedir@ \
		   PYTHONPATH=$(abs_top_srcdir):$(pyexecdir) \
		   $(PYTHON) $(srcdir)/main.py

