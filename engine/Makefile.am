# vim:set noet ts=4:
#
# ibus-tmpl - The Input Bus template project
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

engine_enchant_PYTHON = \
	engine.py \
	factory.py \
	main.py \
	$(NULL)

engine_enchantdir = $(datadir)/ibus/engine/enchant

libexec_SCRIPTS = ibus-engine-enchant

CLEANFILES = \
	*.pyc \
	$(NULL)

EXTRA_DIST = \
	ibus-engine-enchant.in \
	$(NULL)

test:
	$(ENV) LANG=en_US PYTHONPATH=$(top_srcdir) $(PYTHON) $(srcdir)/main.py

