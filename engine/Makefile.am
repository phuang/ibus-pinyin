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
engine_pinyindir = $(datadir)/ibus-pinyin/engine

bin_SCRIPTS = ibus-engine-pinyin

engine_DATA = pinyin.engine
enginedir = $(datadir)/ibus/engine

DBVER = 0.1.10.6
DBTAR = pinyin-database-${DBVER}.tar.bz2

${DBTAR}:
	wget http://ibus.googlecode.com/files/${DBTAR}

py.db: ${DBTAR}
	tar jxvfm ${DBTAR}


EXTRA_DIST = \
	ibus-engine-pinyin.in \
	pinyin.engine.in \
	special_phrase \
	special_table \
	$(NULL)

CLEANFILES = \
	*.pyc \
	py.db \
	$(DBTAR) \
	$(NULL)

test:
	$(ENV) \
		IBUS_PINYIN_LOCATION=$(abs_top_srcdir) \
		DBUS_DEBUG=true \
		LANG=en_US \
		PYTHONPATH=$(abs_top_srcdir) \
		$(PYTHON) $(srcdir)/main.py

install-data-hook:
	@(if test "${NO_INDEX}" = ""; then \
		cd $(DESTDIR)$(engine_pinyindir); \
		echo "Creating INDEX"; \
		$(PYTHON) -c "import pysqlitedb; db = pysqlitedb.PYSQLiteDB (filename='py.db'); db.create_indexes ();" ;\
	fi)

