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

lua_script_DATA = base.lua \
	 $(NULL)

lua_scriptdir = $(pkgdatadir)

noinst_LTLIBRARIES = \
	libpylua.la \
	$(NULL)

libpylua_la_SOURCES = \
	lua-plugin.h \
	lua-plugin.c \
	lua-plugin-init.c \
	lmyoslib.c \
	$(NULL)

libpylua_la_CFLAGS = \
	@IBUS_CFLAGS@ \
	@LUA_CFLAGS@ \
	$(NULL)

libpylua_la_LIBADD = \
	@IBUS_LIBS@ \
	@LUA_LIBS@ \
	$(NULL)

TESTS = \
	test-lua-plugin \
	$(NULL)

noinst_PROGRAMS = \
	lua-ext-console \
	$(TESTS) \
	$(NULL)

test_lua_plugin_SOURCES = \
	test-lua-plugin.c \
	$(NULL)

test_lua_plugin_CFLAGS = \
	@IBUS_CFLAGS@ \
	@LUA_CFLAGS@ \
	$(NULL)

test_lua_plugin_LDADD = \
	libpylua.la \
	$(NULL)

lua_ext_console_SOURCES = \
	lua-ext-console.c \
	$(NULL)

lua_ext_console_CFLAGS = \
    @IBUS_CFLAGS@ \
    @LUA_CFLAGS@ \
    $(NULL)

lua_ext_console_LDADD = \
    libpylua.la \
    $(NULL)
