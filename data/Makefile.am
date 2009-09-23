# vim:set noet ts=4:
#
# ibus-pinyin - The Chinese PinYin engine for IBus
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


SUBDIRS = \
	icons \
	$(NULL)

main_db_DATA = \
	db/main.db \
	db/COPYING \
	db/create_index.sql \
	$(NULL)
main_dbdir = $(pkgdatadir)/db

install-data-hook:
	@( \
if test "$(NO_INDEX)" = ""; then \
  cd $(DESTDIR)$(main_dbdir); \
  echo "Create INDEX"; \
  sqlite3 main.db ".read create_index.sql"; \
fi)

DBVER = 1.2.99
DBTAR = pinyin-database-$(DBVER).tar.bz2

$(DBTAR):
	wget http://ibus.googlecode.com/files/$(DBTAR)

db.stamp: $(DBTAR)
	tar jxvfm $(DBTAR)
	touch $@

$(main_db_DATA): db.stamp

CLEANFILES = \
	db.stamp \
	db/* \
	$(NULL)

DISTCLEANFILES = \
	$(DBTAR) \
	$(NULL)
