# vim:set noet ts=4:
#
# ibus-pinyin - The Chinese PinYin engine for IBus
#
# Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
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

WORDLIST = wordlist
ENGLISH_AWK = english.awk
ENGLISH_DB = english.db

SUBDIRS = \
	db \
	icons \
	$(NULL)

english_db_DATA = \
        $(ENGLISH_DB) \
        $(NULL)
english_dbdir = $(pkgdatadir)/db

$(ENGLISH_DB): $(WORDLIST) $(ENGLISH_AWK)
	$(AM_V_GEN) \
	$(RM) $@; \
	$(AWK) -f $(srcdir)/$(ENGLISH_AWK) $(srcdir)/$(WORDLIST) | @SQLITE3@ $@ || \
		( $(RM) $@ ; exit 1 )

EXTRA_DIST = \
	$(WORDLIST) \
	$(ENGLISH_AWK) \
	$(NULL)

CLEANFILES = \
	$(ENGLISH_DB) \
	$(NULL)
