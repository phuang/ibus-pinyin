# -*- coding: utf-8 -*-
# vim: set noet ts=4:
#
# scim-python
#
# Copyright (c) 2007-2008 Huang Peng <shawn.p.huang@gmail.com>
#
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this program; if not, write to the
# Free Software Foundation, Inc., 59 Temple Place, Suite 330,
# Boston, MA  02111-1307  USA
#
# $Id: $
#
import sys
import scim

from gettext import dgettext
_ = lambda a : dgettext ("scim-python", a)

__UUID__ = "eebeecd7-cb22-48f4-8ced-70e42dad1a79"
__NAME__ = _("Python PinYin Setup")
__ICON__ = "/usr/share/scim/icons/setup.png"
__DESC__ = _("Python PinYin Setup Helper")
__OPT__ = 0

helper_info = (__UUID__, __NAME__, __ICON__, __DESC__, __OPT__)

def get_info ():
	return helper_info

def run_helper (uuid, config, display):
	if uuid != __UUID__:
		return
	display_arg = "--display=%s" % display
	sys.argv.append (display_arg)
	import SetupUI
	SetupUI.SetupUI (helper_info).run (uuid, config, display)


