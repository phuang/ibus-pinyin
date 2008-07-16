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

def main ():
    srcdir = "."
    if len (sys.argv) == 2:
        srcdir = sys.argv[1]

    filename = "py.db"
    try:
        os.unlink (filename)
    except:
        pass
    
    print "Create DB"
    db = pysqlitedb.PYSQLiteDB (filename = filename)
    db.create_tables ()
    db.init_pinyin_table ()
    db.init_shengmu_table ()

    def phrase_pinyin_parser (f):
        for l in f:
            phrase, pinyin, freq = unicode (l, "utf-8").strip ().split ()
            pinyin = pinyin.replace (u"u:", u"v")
            yield (phrase, pinyin, int (freq))

    def phrase_pinyin_parser_pinyin (f):
        for l in f:
            phrase, pinyin, freq = unicode (l, "utf-8").strip ().split ()
            pinyin = pinyin.replace (u"u:", u"v")
            yield (phrase, pinyin, int (freq)*1300)

    print "Load pinyin_table.txt"
    filename = os.path.join (srcdir, "../../../data/pinyin_table.txt")
    db.add_phrases (phrase_pinyin_parser_pinyin (file (filename)))

    print "Load phrase_pinyin.txt.bz2"
    filename = os.path.join (srcdir, "phrase_pinyin.txt.bz2")
    bzf = bz2.BZ2File (filename, "r")
    db.add_phrases (phrase_pinyin_parser (bzf))
    
    print "Load phrase_pinyin_duoyin.txt"
    filename = os.path.join (srcdir, "phrase_pinyin_duoyin.txt")
    db.add_phrases (phrase_pinyin_parser (file (filename)))

    print "Optimizing database"
    db.optimize_database ()
    
if __name__ == "__main__":
    main ()
