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

@MAINTAINER_MODE_FALSE@skip_genpytable=test -f $@ ||
GENPYTABLE = scripts/genpytable.py

AM_CFLAGS = \
	@IBUS_CFLAGS@ \
	@SQLITE_CFLAGS@ \
	-DPKGDATADIR=\"$(pkgdatadir)\" \
	$(NULL)
AM_LDFLAGS = \
	@IBUS_LIBS@ \
	@SQLITE_LIBS@ \
	$(NULL)

AM_CXXFLAGS = $(AM_CFLAGS)

libexec_PROGRAMS = ibus-engine-pinyin

ibus_engine_c_sources = \
	Config.cc \
	Database.cc \
	DoublePinyinEditor.cc \
	Engine.cc \
	FullPinyinEditor.cc \
	HalfFullConverter.cc \
	Main.cc \
	PhraseEditor.cc \
	PinyinEditor.cc \
	PinyinEngine.cc \
	PinyinParser.cc \
	SpecialTable.cc \
	$(NULL)
ibus_engine_h_sources = \
	Array.h \
	Bus.h \
	Config.h \
	Database.h \
	DoublePinyinEditor.h \
	DoublePinyinTable.h \
	Engine.h \
	FullPinyinEditor.h \
	HalfFullConverter.h \
	LookupTable.h \
	PhraseArray.h \
	PhraseEditor.h \
	PinyinArray.h \
	PinyinEditor.h \
	PinyinEngine.h \
	PinyinParser.h \
	Pointer.h \
	Property.h \
	SpecialTable.h \
	String.h \
	Table.h \
	Text.h \
	Types.h \
	Util.h \
	$(NULL)
ibus_engine_pinyin_SOURCES = \
	$(ibus_engine_c_sources) \
	$(ibus_engine_h_sources) \
	$(NULL)
ibus_engine_pinyin_CXXFLAGS = \
	@IBUS_CFLAGS@ \
	@SQLITE_CFLAGS@ \
	@UUID_CFLAGS@ \
	-DGETTEXT_PACKAGE=\"@GETTEXT_PACKAGE@\" \
	-DPKGDATADIR=\"$(pkgdatadir)\" \
	-DLIBEXECDIR=\"$(libexecdir)\" \
	$(NULL)
ibus_engine_pinyin_LDFLAGS = \
	@IBUS_LIBS@ \
	@SQLITE_LIBS@ \
	@UUID_LIBS@ \
	$(NULL)

BUILT_SOURCES = \
	$(ibus_engine_built_c_sources) \
	$(ibus_engine_built_h_sources) \
	$(NULL)

# db_DATA = \
# 	py.db \
# 	$(NULL)
# dbdir = $(pkgdatadir)

component_DATA = \
	pinyin.xml \
	$(NULL)
componentdir = @datadir@/ibus/component

EXTRA_DIST = \
	pinyin.xml.in \
	$(NULL)

CLEANFILES = \
	pinyin.xml \
	$(NULL)

check_PROGRAMS =

# check_PROGRAMS += test-parser
# test_parser_SOURCES = \
# 	PinyinParser.cc \
# 	Table.h \
# 	$(NULL)
# test_parser_CFLAGS = \
# 	$(AM_CFLAGS) \
# 	-DTEST \
# 	$(NULL)
# 
# check_PROGRAMS += test-pydatabase
# test_pydatabase_SOURCES = \
# 	Database.cc \
# 	Database.h \
# 	$(NULL)
# test_pydatabase_CFLAGS = \
# 	$(AM_CFLAGS) \
# 	-DTEST \
# 	$(NULL)

TESTS = \
	$(check_PROGRAMS) \
	$(NULL)

Table.h:
	$(skip_genpytable) $(PYTHON) $(srcdir)/$(GENPYTABLE) > $@

pinyin.xml: pinyin.xml.in
	( \
		libexecdir=${libexecdir}; \
		pkgdatadir=${pkgdatadir}; \
		s=`cat $<`; \
		eval "echo \"$${s}\""; \
	) > $@

test: ibus-engine-pinyin
	$(builddir)/ibus-engine-pinyin

