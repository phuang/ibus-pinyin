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
	PYBopomofoKeyboard.h \
	PYPinyinParserTable.h \
	PYPunctTable.h \
	PYSimpTradConverterTable.h \
	$(NULL)
ibus_engine_pinyin_c_sources = \
	PYBopomofoEditor.cc \
	PYBopomofoEngine.cc \
	PYConfig.cc \
	PYDatabase.cc \
	PYDoublePinyinEditor.cc \
	PYEditor.cc \
	PYEngine.cc \
	PYFallbackEditor.cc \
	PYFullPinyinEditor.cc \
	PYHalfFullConverter.cc \
	PYMain.cc \
	PYPhoneticEditor.cc \
	PYPhraseEditor.cc \
	PYPinyinEditor.cc \
	PYPinyinEngine.cc \
	PYPinyinParser.cc \
	PYPinyinProperties.cc \
	PYPunctEditor.cc \
	PYSimpTradConverter.cc \
	PYDynamicSpecialPhrase.cc \
	PYSpecialPhrase.cc \
	PYSpecialPhraseTable.cc \
	$(NULL)
ibus_engine_pinyin_h_sources = \
	PYBopomofo.h \
	PYBopomofoEditor.h \
	PYBopomofoEngine.h \
	PYBus.h \
	PYConfig.h \
	PYDatabase.h \
	PYDoublePinyinEditor.h \
	PYDoublePinyinTable.h \
	PYEditor.h \
	PYEngine.h \
	PYExtEditor.h \
	PYFallbackEditor.h \
	PYFullPinyinEditor.h \
	PYHalfFullConverter.h \
	PYLookupTable.h \
	PYObject.h \
	PYPhoneticEditor.h \
	PYPhrase.h \
	PYPhraseArray.h \
	PYPhraseEditor.h \
	PYPinyinArray.h \
	PYPinyinEditor.h \
	PYPinyinEngine.h \
	PYPinyinParser.h \
	PYPinyinProperties.h \
	PYPointer.h \
	PYProperty.h \
	PYPunctEditor.h \
	PYRawEditor.h \
	PYRegex.h \
	PYSignal.h \
	PYSimpTradConverter.h \
	PYSpecialPhrase.h \
	PYDynamicSpecialPhrase.h \
	PYSpecialPhraseTable.h \
	PYString.h \
	PYText.h \
	PYTypes.h \
	PYUtil.h \
	PYEnglishEditor.h \
	$(NULL)

if IBUS_BUILD_LUA_EXTENSION
ibus_engine_pinyin_c_sources += PYExtEditor.cc
endif

if IBUS_BUILD_ENGLISH_INPUT_MODE
ibus_engine_pinyin_c_sources += PYEnglishEditor.cc
endif

ibus_engine_pinyin_SOURCES = \
	$(ibus_engine_pinyin_c_sources) \
	$(ibus_engine_pinyin_h_sources) \
	$(ibus_engine_pinyin_built_c_sources) \
	$(ibus_engine_pinyin_built_h_sources) \
	$(NULL)


ibus_engine_pinyin_CXXFLAGS = \
	@IBUS_CFLAGS@ \
	@SQLITE_CFLAGS@ \
	@OPENCC_CFLAGS@ \
	-DGETTEXT_PACKAGE=\"@GETTEXT_PACKAGE@\" \
	-DPKGDATADIR=\"$(pkgdatadir)\" \
	-DLIBEXECDIR=\"$(libexecdir)\" \
	$(NULL)

if HAVE_BOOST
ibus_engine_pinyin_CXXFLAGS += \
	@BOOST_CPPFLAGS@ \
	$(NULL)
else
ibus_engine_pinyin_CXXFLAGS += \
	-std=c++0x \
	$(NULL)
endif

ibus_engine_pinyin_LDADD = \
	@IBUS_LIBS@ \
	@SQLITE_LIBS@ \
	@OPENCC_LIBS@ \
	$(NULL)

if HAVE_LIBUUID
ibus_engine_pinyin_CXXFLAGS += $(LIBUUID_CFLAGS)
ibus_engine_pinyin_LDADD += $(LIBUUID_LIBS)
endif

if IBUS_BUILD_LUA_EXTENSION
    ibus_engine_pinyin_CXXFLAGS +=  \
	@LUA_CFLAGS@ \
	-DIBUS_BUILD_LUA_EXTENSION \
	-I$(top_srcdir)/lua/ \
	$(NULL)
endif

if IBUS_BUILD_LUA_EXTENSION
    ibus_engine_pinyin_LDADD += \
	@LUA_LIBS@ \
	-L../lua/ \
	-lpylua \
	$(NULL)
endif

if IBUS_BUILD_ENGLISH_INPUT_MODE
   ibus_engine_pinyin_CXXFLAGS += \
	-DIBUS_BUILD_ENGLISH_INPUT_MODE \
	$(NULL)
endif

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

PYBopomofoKeyboard.h:
	$(AM_V_GEN) \
	$(PYTHON) $(top_srcdir)/scripts/genbopomofokeyboard.py > $@ || \
		( $(RM) $@; exit 1 )

PYPinyinParserTable.h:
	$(AM_V_GEN) \
	$(PYTHON) $(top_srcdir)/scripts/genpytable.py > $@ || \
		( $(RM) $@; exit 1 )

PYPunctTable.h:
	$(AM_V_GEN) \
	$(PYTHON) $(top_srcdir)/scripts/genpuncttable.py > $@ || \
		( $(RM) $@; exit 1 )

PYSimpTradConverterTable.h:
	$(AM_V_GEN) \
	$(PYTHON) $(top_srcdir)/scripts/update-simptrad-table.py > $@ || \
		( $(RM) $@; exit 1 )

update-simptrad-table:
	$(RM) ZhConversion.php ZhConversion.py PYSimpTradConverterTable.h
	$(MAKE) ZhConversion.php
	$(MAKE) ZhConversion.py
	$(MAKE) PYSimpTradConverterTable.h

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
	$(AM_V_GEN) \
	svn cat http://svn.wikimedia.org/svnroot/mediawiki/trunk/phase3/includes/ZhConversion.php > $@ || \
		( $(RM) $@; exit 1 )

ZhConversion.py: ZhConversion.php
	$(AM_V_GEN) \
	php $(top_srcdir)/scripts/php_2_py.php > $@ || \
		( $(RM) $@; exit 1 )

