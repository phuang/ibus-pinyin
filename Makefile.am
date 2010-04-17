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

SUBDIRS = \
	data \
	src \
	setup \
	m4 \
	po \
	$(NULL)

DISTCHECK_CONFIGURE_FLAGS = \
	--enable-db-android \
	--enable-db-open-phrase \
	$(NULL)

ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = \
	autogen.sh \
	ibus-pinyin.spec.in \
	$(NULL)

noinst_DIST = \
	$(NULL)


DISTCLEANFILES = \
	po/stamp-it \
	$(NULL)

dist-hook:
	if test -d .git ; then \
		git log --name-status --date=iso > $(distdir)/ChangeLog ; \
	fi

rpm: dist @PACKAGE_NAME@.spec
	rpmbuild -bb \
			--define "_sourcedir `pwd`" \
			--define "_builddir `pwd`/rpm" \
			--define "_srcrpmdir `pwd`/rpm" \
			--define "_rpmdir `pwd`/rpm" \
			--define "_specdir `pwd`" \
			@PACKAGE_NAME@.spec

srpm: dist @PACKAGE_NAME@.spec
	rpmbuild -bs \
			--define "_sourcedir `pwd`" \
			--define "_builddir `pwd`/rpm" \
			--define "_srcrpmdir `pwd`/rpm" \
			--define "_rpmdir `pwd`/rpm" \
			--define "_specdir `pwd`" \
			@PACKAGE_NAME@.spec
upload: dist
	./tools/googlecode_upload.py \
		-s "ibus-pinyin（拼音）source code" \
		-p ibus \
		-l "Type-Source,OpSys-Linux,Chinese,Unstable" \
		$(distdir).tar.gz

clean-rpm:
	$(RM) -r "`uname -i`"

clean-local: clean-rpm
