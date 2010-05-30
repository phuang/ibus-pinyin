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
ibus_engine_pinyin_built_c_sources = \
	$(NULL)
ibus_engine_pinyin_built_h_sources = \
	BopomofoKeyboard.h \
	PinyinParserTable.h \
	PunctTable.h \
	SimpTradConverterTable.h \
	$(NULL)
ibus_engine_pinyin_c_sources = \
	BopomofoEditor.cc \
	BopomofoEngine.cc \
	Config.cc \
	Database.cc \
	DoublePinyinEditor.cc \
	Editor.cc \
	Engine.cc \
	ExtEditor.cc \
	FallbackEditor.cc \
	FullPinyinEditor.cc \
	HalfFullConverter.cc \
	Main.cc \
	PhoneticEditor.cc \
	PhraseEditor.cc \
	PinyinEditor.cc \
	PinyinEngine.cc \
	PinyinParser.cc \
	PinyinProperties.cc \
	PunctEditor.cc \
	SimpTradConverter.cc \
	DynamicSpecialPhrase.cc \
	SpecialPhrase.cc \
	SpecialPhraseTable.cc \
	$(NULL)
ibus_engine_pinyin_h_sources = \
	Bopomofo.h \
	BopomofoEditor.h \
	BopomofoEngine.h \
	Bus.h \
	Config.h \
	Database.h \
	DoublePinyinEditor.h \
	DoublePinyinTable.h \
	Editor.h \
	Engine.h \
	ExtEditor.h \
	FallbackEditor.h \
	FullPinyinEditor.h \
	HalfFullConverter.h \
	LookupTable.h \
	Object.h \
	PhoneticEditor.h \
	Phrase.h \
	PhraseArray.h \
	PhraseEditor.h \
	PinyinArray.h \
	PinyinEditor.h \
	PinyinEngine.h \
	PinyinParser.h \
	PinyinProperties.h \
	Pointer.h \
	Property.h \
	PunctEditor.h \
	RawEditor.h \
	Regex.h \
	Signal.h \
	SimpTradConverter.h \
	SpecialPhrase.h \
	DynamicSpecialPhrase.h \
	SpecialPhraseTable.h \
	String.h \
	Text.h \
	Types.h \
	Util.h \
	$(NULL)
ibus_engine_pinyin_SOURCES = \
	$(ibus_engine_pinyin_c_sources) \
	$(ibus_engine_pinyin_h_sources) \
	$(ibus_engine_pinyin_built_c_sources) \
	$(ibus_engine_pinyin_built_h_sources) \
	$(NULL)
ibus_engine_pinyin_CXXFLAGS = \
	@IBUS_CFLAGS@ \
	@SQLITE_CFLAGS@ \
	@BOOST_CPPFLAGS@ \
	-DGETTEXT_PACKAGE=\"@GETTEXT_PACKAGE@\" \
	-DPKGDATADIR=\"$(pkgdatadir)\" \
	-DLIBEXECDIR=\"$(libexecdir)\" \
	$(NULL)
ibus_engine_pinyin_LDADD = \
	@IBUS_LIBS@ \
	@SQLITE_LIBS@ \
	$(NULL)

if HAVE_LIBUUID
ibus_engine_pinyin_CXXFLAGS += $(LIBUUID_CFLAGS)
ibus_engine_pinyin_LDADD += $(LIBUUID_LIBS)
endif

# if HAVE_BOOST_SIGNALS2
# # do nothing
# else
# ibus_engine_pinyin_CXXFLAGS += $(LIBUUID_CFLAGS)
# ibus_engine_pinyin_LDADD += \
# 	$(BOOST_SIGNALS_LDFLAGS) \
# 	$(BOOST_SIGNALS_LIBS) \
# 	$(NULL)
# endif

BUILT_SOURCES = \
	$(ibus_engine_built_c_sources) \
	$(ibus_engine_built_h_sources) \
	$(NULL)

pkgdata_DATA = \
	phrases.txt \
	$(NULL)

component_DATA = \
	pinyin.xml \
	$(NULL)
componentdir = @datadir@/ibus/component

EXTRA_DIST = \
	pinyin.xml.in \
	phrases.txt \
	$(NULL)

CLEANFILES = \
	pinyin.xml \
	ZhConversion.* \
	$(NULL)

BopomofoKeyboard.h:
	$(PYTHON) $(top_srcdir)/scripts/genbopomofokeyboard.py > $@

PinyinParserTable.h:
	$(PYTHON) $(top_srcdir)/scripts/genpytable.py > $@

PunctTable.h:
	$(PYTHON) $(top_srcdir)/scripts/genpuncttable.py > $@

SimpTradConverterTable.h:
	$(PYTHON) $(top_srcdir)/scripts/update-simptrad-table.py > $@

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

