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

# @MAINTAINER_MODE_FALSE@skip_gentable=test -f $@ ||

# AM_CFLAGS = \
# 	@IBUS_CFLAGS@ \
# 	@SQLITE_CFLAGS@ \
# 	-DPKGDATADIR=\"$(pkgdatadir)\" \
# 	$(NULL)
# AM_CXXFLAGS = $(AM_CFLAGS)
# AM_LDADD = \
# 	@IBUS_LIBS@ \
# 	@SQLITE_LIBS@ \
# 	$(NULL)
# 

libexec_PROGRAMS = ibus-engine-pinyin
ibus_engine_c_sources = \
	Config.cc \
	CustomPhrase.cc \
	Database.cc \
	DoublePinyinEditor.cc \
	Editor.cc \
	Engine.cc \
	ExtEditor.cc \
	FallbackEditor.cc \
	FullPinyinEditor.cc \
	HalfFullConverter.cc \
	Main.cc \
	PhraseEditor.cc \
	PinyinEditor.cc \
	PinyinEngine.cc \
	PinyinParser.cc \
	PinyinProperties.cc \
	SimpTradConverter.cc \
	SpecialTable.cc \
	$(NULL)
ibus_engine_built_h_sources = \
	PinyinParserTable.h \
	SimpTradConverterTable.h \
	$(NULL)
ibus_engine_h_sources = \
	Bus.h \
	Config.h \
	CustomPhrase.h \
	Database.h \
	DoublePinyinEditor.h \
	DoublePinyinTable.h \
	Editor.h \
	Engine.h \
	ExtEditor.h \
	FallbackEditor.h \
	FullPinyinEditor.h \
	HalfFullConverter.h \
	HashTable.h \
	LookupTable.h \
	Phrase.h \
	PhraseArray.h \
	PhraseEditor.h \
	PinyinArray.h \
	PinyinEditor.h \
	PinyinEngine.h \
	PinyinParser.h \
	PinyinParserTable.h \
	PinyinProperties.h \
	Pointer.h \
	RawEditor.h \
	Regex.h \
	Property.h \
	SimpTradConverter.h \
	SimpTradConverterTable.h \
	SpecialTable.h \
	String.h \
	Text.h \
	Types.h \
	Util.h \
	WideString.h \
	$(NULL)
ibus_engine_pinyin_SOURCES = \
	$(ibus_engine_c_sources) \
	$(ibus_engine_h_sources) \
	$(ibus_engine__built_c_sources) \
	$(ibus_engine__built_h_sources) \
	$(NULL)
ibus_engine_pinyin_CXXFLAGS = \
	@IBUS_CFLAGS@ \
	@SQLITE_CFLAGS@ \
	@UUID_CFLAGS@ \
	@SIGC_CFLAGS@ \
	-DGETTEXT_PACKAGE=\"@GETTEXT_PACKAGE@\" \
	-DPKGDATADIR=\"$(pkgdatadir)\" \
	-DLIBEXECDIR=\"$(libexecdir)\" \
	$(NULL)
ibus_engine_pinyin_LDADD = \
	@IBUS_LIBS@ \
	@SQLITE_LIBS@ \
	@UUID_LIBS@ \
	@SIGC_LIBS@ \
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
	ZhConversion.* \
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

PinyinParserTable.h:
	$(PYTHON) $(top_srcdir)/scripts/genpytable.py > $@

SimpTradConverterTable.h:
	$(PYTHON) $(srcdir)/update-simptrad-table.py > $@
update-simptrad-table:
	$(RM) ZhConversion.php ZhConversion.py SimpTradConverterTable.h
	$(MAKE) ZhConversion.php
	$(MAKE) ZhConversion.py
	$(MAKE) SimpTradConverterTable.h

pinyin.xml: pinyin.xml.in
	$(AM_V_GEN) \
	( \
		libexecdir=${libexecdir}; \
		pkgdatadir=${pkgdatadir}; \
		s=`cat $<`; \
		eval "echo \"$${s}\""; \
	) > $@

test: ibus-engine-pinyin
	$(ENV) \
		G_DEBUG=fatal_criticals \
		$(builddir)/ibus-engine-pinyin

# test: ibus-engine-pinyin
# 	$(ENV) G_DEBUG=fatal_warnings \
# 	$(builddir)/ibus-engine-pinyin

ZhConversion.php:
	svn cat http://svn.wikimedia.org/svnroot/mediawiki/trunk/phase3/includes/ZhConversion.php > $@

ZhConversion.py: ZhConversion.php
	php php_2_py.php > $@

