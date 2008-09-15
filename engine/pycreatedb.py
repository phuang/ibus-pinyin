# -*- coding: utf-8 -*-
# vim:set et sts=4 sw=4:
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

import sys, os, re
import pysqlitedb
import bz2

def phrase_pinyin_parser(f):
    for l in f:
        pinyin, phrase, freq = unicode(l, "utf-8").strip().split()
        pinyin = pinyin.replace(u"u:", u"v")
        yield (phrase, pinyin, int(freq))

def main():
    srcdir = "."
    if len(sys.argv) == 2:
        srcdir = sys.argv[1]

    filename = "py-new.db"
    try:
        os.unlink(filename)
    except:
        pass
    
    db = pysqlitedb.PYSQLiteDB(filename = filename)
    db.create_tables()
    db.init_pinyin_table()
    db.init_shengmu_table()

    for phrase_filename in sys.argv[1:]:
        print "Loading %s" % phrase_filename
        db.add_phrases(phrase_pinyin_parser(file(phrase_filename)))
    
    print "Optimizing database"
    db.optimize_database()
    
if __name__ == "__main__":
    main()
