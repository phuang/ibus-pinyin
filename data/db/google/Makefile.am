# vim:set noet ts=4:
#
# ibus-pinyin - The Chinese PinYin engine for IBus
#
# Copyright (c) 2007-2008 Peng Huang <shawn.p.huang@gmail.com>
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

create_scripts = \
	create_db.py \
	id.py \
	pydict.py \
	valid_hanzi.py \
	$(NULL)
data_files = \
	README \
	rawdict_utf16_65105_freq.txt \
	$(NULL)

if IBUS_BUILD_DB_GOOGLE
main_db_DATA = \
	google.db \
	$(NULL)
main_dbdir = $(pkgdatadir)/db
endif

google.db: $(google_raw_data) $(create_scripts)
	$(RM) $@
	$(srcdir)/create_db.py $(srcdir)/rawdict_utf16_65105_freq.txt | sqlite3 $@

EXTRA_DIST = \
	$(data_files) \
	$(create_scripts) \
	$(NULL)

CLEANFILES = \
	google.db \
	$(NULL)

DISTCLEANFILES = \
	$(NULL)

