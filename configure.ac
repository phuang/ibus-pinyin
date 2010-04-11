# vim:set et ts=4:
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

# if not 1, append datestamp to the version number.
m4_define([ibus_released], [1])
m4_define([ibus_major_version], [1])
m4_define([ibus_minor_version], [3])
m4_define([ibus_micro_version], [2])
m4_define(ibus_maybe_datestamp,
    m4_esyscmd([if test x]ibus_released[ != x1; then date +.%Y%m%d | tr -d '\n\r'; fi]))

m4_define([ibus_version],
    ibus_major_version.ibus_minor_version.ibus_micro_version[]ibus_maybe_datestamp)

AC_INIT([ibus-pinyin], [ibus_version], [http://code.google.com/p/ibus/issues/entry],[ibus-pinyin])
AM_INIT_AUTOMAKE([1.10])
AC_GNU_SOURCE

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

# define PACKAGE_VERSION_* variables
AS_VERSION
AS_NANO
AM_SANITY_CHECK
AM_MAINTAINER_MODE
AM_DISABLE_STATIC
AC_PROG_CC
AC_PROG_CXX
AM_PROG_CC_C_O
AC_ISC_POSIX
AC_HEADER_STDC
IT_PROG_INTLTOOL([0.35.0])
AM_PROG_LIBTOOL

# check ibus
PKG_CHECK_MODULES(IBUS, [
    ibus-1.0
])

# check sqlite
PKG_CHECK_MODULES(SQLITE, [
    sqlite3
])
AC_PATH_PROG(SQLITE3, sqlite3)

# check uuid
PKG_CHECK_MODULES(UUID, [
    uuid
],
[
    cat >>confdefs.h <<_ACEOF
#define HAVE_UUID_UUID_H 1
#define HAVE_UUID_GENERATE 1
_ACEOF
],
[
    uuid_revert_save_LIBS=$LIBS
    AC_CHECK_HEADERS(uuid.h uuid/uuid.h sys/uuid.h)
    AC_SEARCH_LIBS(uuid_create, uuid, [
        if test "$ac_cv_search_uuid_create" != "none required"; then
            UUID_LIBS=$ac_cv_search_uuid_create
        fi
        AC_CHECK_FUNCS(uuid_create)
    ],
    [
        AC_SEARCH_LIBS(uuid_generate, uuid, [
            if test "$ac_cv_search_uuid_generate" != "none required"; then
                UUID_LIBS=$ac_cv_search_uuid_generate
            fi
            AC_CHECK_FUNCS(uuid_generate)
        ])
    ])
    LIBS=$uuid_revert_save_LIBS
])

# check sigc
PKG_CHECK_MODULES(SIGC, [
    sigc++-2.0
])

# check env
AC_PATH_PROG(ENV, env)
AC_SUBST(ENV)

#check python
AM_PATH_PYTHON([2.5])

# define GETTEXT_* variables
GETTEXT_PACKAGE=ibus-pinyin
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [Gettext package])

AM_GLIB_GNU_GETTEXT

# --enable-db-android
AC_ARG_ENABLE(db-android,
    AS_HELP_STRING([--disable-db-android],
        [do not build database from pinyin in android]),
    [enable_db_android=$enableval],
    [enable_db_android=yes]
)
AM_CONDITIONAL(IBUS_BUILD_DB_ANDROID, [test x"$enable_db_android" = x"yes" ])

# --enable-db-open-phrase
AC_ARG_ENABLE(db-open-phrase,
    AS_HELP_STRING([--enable-db-open-phrase],
        [build open-phrase database]),
    [enable_db_open_phrase=$enableval],
    [enable_db_open_phrase=no]
)
AM_CONDITIONAL(IBUS_BUILD_DB_OPEN_PHRASE, [test x"$enable_db_open_phrase" = x"yes" ])

# OUTPUT files
AC_CONFIG_FILES([ po/Makefile.in
Makefile
ibus-pinyin.spec
src/Makefile
src/pinyin.xml.in
setup/Makefile
setup/ibus-setup-pinyin
setup/version.py
data/Makefile
data/db/Makefile
data/db/android/Makefile
data/db/open-phrase/Makefile
data/icons/Makefile
m4/Makefile
])

AC_OUTPUT

AC_MSG_RESULT([
Build options:
    Version                     $VERSION
    Install prefix              $prefix
    Build database android      $enable_db_android
    Build database open-phrase  $enable_db_open_phrase
])

