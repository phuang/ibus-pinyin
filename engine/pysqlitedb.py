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

import os
import os.path as path
import time
import sys
import sqlite3 as sqlite
import re
import uuid
import traceback
import pyutil
import pydict
import pyparser

(YLEN, Y0, Y1, Y2, Y3, YX, S0, S1, S2, S3, PHRASE, FREQ, USER_FREQ) = range (0, 13)

FLUSH_PERIOD = 60 * 5 # 5 minute

class PYSQLiteDB:
    """phrase database that contains all phrases and phrases' pinyin"""
    def __init__ (self, name = "py.db", user_db = None, filename = None):
    
        # init last flush time
        self._last_flush_time = None
    
        if filename:
            self.db = sqlite.connect (filename)
            self.parser = pyparser.PinYinParser ()
            return

        name = os.path.join (os.path.dirname (__file__), name)

        # open system phrase database
        self.db = sqlite.connect (name)

        self.parser = pyparser.PinYinParser ()
        # self.db.execute ("PRAGMA locking_mode = EXCLUSIVE;")
        self.db.execute ("PRAGMA synchronous = NORMAL;")
        self.db.execute ("PRAGMA temp_store = MEMORY;")
        
        if user_db != None:
            home_path = os.getenv ("HOME")
            pinyin_path = path.join (home_path, ".scim", "scim-python", "pinyin")
            user_db = path.join (pinyin_path, user_db)
            if not path.isdir (pinyin_path):
                os.makedirs (pinyin_path)

            try:
                desc = get_database_desc (user_db)
                if desc == None or desc["id"] != "0.1":
                    new_name = "%s.%d" %(user_db, os.getpid())
                    print >> sys.stderr, "Can not support the user db. We will rename it to %s" % new_name
                    os.rename (user_db, new_name)
            except:
                pass
        else:
            user_db = ":memory:"
        
        
        # open user phrase database
        try:
            self.db.execute ("ATTACH DATABASE \"%s\" AS user_db;" % user_db)
        except:
            print >> sys.stderr, "The user database was damaged. We will recreate it!"
            os.rename (user_db, "%s.%d" % (user_db, os.getpid ()))
            self.db.execute ("ATTACH DATABASE \"%s\" AS user_db;" % user_db)

        
        # try create all tables in user database
        self.create_tables ("user_db")
        self.create_indexes ("user_db")
        self.generate_userdb_desc ()

        self.select_cache = Cache ()

    def create_tables (self, database = "main"):
        """create all phrases tables that contain all phrases"""
        
        try:
            self.db.executescript ("PRAGMA default_cache_size = 5000;")
            self.flush (True)
        except:
            pass

        # create pinyin table
        sqlstring = "CREATE TABLE IF NOT EXISTS %s.py_pinyin (pinyin TEXT PREMARY KEY);" % database
        self.db.execute (sqlstring)
        
        # create pinyin table
        sqlstring = "CREATE TABLE IF NOT EXISTS %s.py_shengmu (shengmu TEXT PREMARY KEY);" % database
        self.db.execute (sqlstring)

        # create phrase table
        sqlstring = """CREATE TABLE IF NOT EXISTS %(database)s.py_phrase (
                            ylen INTEGER, 
                            y0 INTEGER, y1 INTEGER, y2 INTEGER, y3 INTEGER, yx TEXT,
                            s0 INTEGER, s1 INTEGER, s2 INTEGER, s3 INTEGER,
                            phrase TEXT,
                            freq INTEGER, user_freq INTEGER);"""
        
        self.db.executescript (sqlstring % { "database":database })
        self.flush (True)

    def generate_userdb_desc (self):
        try:
            sqlstring = "CREATE TABLE user_db.desc (name PRIMARY KEY, value);"
            self.db.executescript (sqlstring)
            sqlstring = "INSERT INTO user_db.desc  VALUES (?, ?);"
            self.db.execute (sqlstring, ("version", "0.1"))
            self.db.execute (sqlstring, ("id", str (uuid.uuid4 ())))
            sqlstring = "INSERT INTO user_db.desc  VALUES (?, DATETIME(\"now\", \"localtime\"));"
            self.db.execute (sqlstring, ("create-time", ))
            self.flush (True)
        except:
            print "desc table has been created."

    def create_indexes (self, database = "main"):
        # create indexes
        sqlstring = """
                CREATE INDEX IF NOT EXISTS %(database)s.py_phrase_index_1 ON
                    py_phrase (y0, y1, y2, y3);
                CREATE INDEX IF NOT EXISTS %(database)s.py_phrase_index_2 ON
                    py_phrase (ylen, y0, y1, y2, y3);
                CREATE INDEX IF NOT EXISTS %(database)s.py_phrase_index_3 ON
                    py_phrase (ylen, s0, s1, s2, s3);
                CREATE INDEX IF NOT EXISTS %(database)s.py_phrase_index_4 ON
                    py_phrase (s0, s1, s2, s2, s3);
                CREATE INDEX IF NOT EXISTS %(database)s.py_phrase_index_5 ON
                    py_phrase (phrase);
                """
        self.db.executescript (sqlstring % { "database" : database })
        self.flush (True)

    def optimize_database (self):
        sqlstring = """
                CREATE TABLE tmp AS SELECT * FROM py_phrase;
                DELETE FROM py_phrase;
                INSERT INTO py_phrase SELECT * FROM tmp ORDER BY ylen, y0, y1, y2, y3, yx, phrase;
                DROP TABLE tmp;
                """
        self.db.executescript (sqlstring)
        self.db.executescript ("VACUUM;")

    def init_pinyin_table (self):
        """create table pinyin that contains all pinyin"""
        sqlstring = "INSERT INTO py_pinyin (pinyin) VALUES (?)"
        for py in pydict.PINYIN_DICT.keys ():
            self.db.execute (sqlstring, (unicode (py),))
        self.flush (True)
    
    def init_shengmu_table (self):
        """create table shengmu that contains all shengmu of pinyin"""
        sqlstring = "INSERT INTO py_shengmu (shengmu) VALUES (?)"
        for shengmu in pydict.SHENGMU_DICT.keys ():
            self.db.execute (sqlstring, (unicode (shengmu),))
        self.flush (True)

    def add_phrases (self, phrases, database = "main"):
        """ add phrases to database, phrases is a iterable object
        Like: [(phrase, pinyin, freq), (phrase, pinyin, freq), ...]
        """
        sqlstring = """INSERT INTO %s.py_phrase (ylen, y0, y1, y2, y3, yx, s0, s1, s2, s3, phrase, freq, user_freq)
            VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"""
        line = 1
        for  phrase, pinyin, freq in phrases:
            try:
                py = self.parser.parse (pinyin)
                if len (py) != len (phrase):
                    error_message = u"%s %s: Can not parse pinyin." % (phrase, pinyin)
                    raise Exception (error_message.encode ("utf8"))
                record = [None, None, None, None, None, None, None, None, None, None, None, None, None]
                record [YLEN] = len (py)
                i = 0
                for p in py[:4]:
                    record[Y0 + i] = p.get_pinyin_id ()
                    record[S0 + i] = p.get_sheng_mu_id ()
                    i += 1
                if len (py) > 4:
                    record[YX] = "'".join (map (str, py[4:]))
                record[PHRASE] = phrase
                record[FREQ] = freq
                record[USER_FREQ] = None
                self.db.execute (sqlstring % database, record)
            except Exception, e:
                print line, ":", phrase.encode ("utf-8"), pinyin, freq
                import traceback
                traceback.print_exc ()
                # print e
            line += 1
            
        self.flush (True)

    def get_pinyin_table (self):
        """get pinyin table"""
        try:
            return self._pinyin_table
        except:
            pass

        sql = "SELECT phrase, y0, s0 FROM py_phrase WHERE ylen = 1"
        
        pinyin_table = {}
        result = self.db.execute (sql % i)
        for phrase, y0, s0 in result:
            if phrase not in pinyin_table:
                pinyin_table [phrase] = []
            pinyin_table [phrase].append ((y0, s0))
        self._pinyin_table = pinyin_table
        
        return pinyin_table

    def select_words_by_pinyin_list (self, pys, mohu = False):
        """select words from database by list that contains pyutil.PinYinWord objects"""
        
        pinyin_string = u"'".join (map (str, pys))
        result = self.select_cache [pinyin_string]
        if result != None:
            return result
        
        tables_union = """( SELECT * FROM main.py_phrase WHERE %(conditions)s UNION ALL
        SELECT * FROM user_db.py_phrase WHERE %(conditions)s )"""
        
        if mohu:
            sql_conditions = ["+ylen = %d" % len (pys) ]
        else:
            sql_conditions = ["ylen = %d" % len (pys) ]
            

        i = 0
        if mohu == False:
            for py in pys[:4]:
                if py.is_valid_pinyin ():
                    sql_conditions.append ("y%d = %d" % (i, py.get_pinyin_id ()))
                else:
                    sql_conditions.append ("s%d = %d" % (i, py.get_sheng_mu_id ()))
                i += 1
        else:
            for py in pys[:4]:
                if py.is_valid_pinyin ():
                    shengmu = py.get_shengmu ()
                    yunmu = py.get_pinyin ()[len (shengmu):]
                    if shengmu in pydict.MOHU_SHENGMU:
                        shengmu_list = pydict.MOHU_SHENGMU[shengmu]
                    else:
                        shengmu_list = [shengmu]

                    if yunmu in pydict.MOHU_YUNMU:
                        yunmu_list = pydict.MOHU_YUNMU[yunmu]
                    else:
                        yunmu_list = [yunmu]
                        
                    pinyin_ids = []
                    for s in shengmu_list:
                        for y in yunmu_list:
                            pinyin = s + y
                            if pinyin in pydict.PINYIN_DICT:
                                pinyin_ids.append (str (pydict.PINYIN_DICT[pinyin]))
                    if len (pinyin_ids) > 1:
                        sql_conditions.append ("y%d in (%s)" % (i, ",".join (pinyin_ids)))
                    else:
                        sql_conditions.append ("y%d == %s" % (i, pinyin_ids[0]))
                        
                else:
                    shengmu = py.get_shengmu ()
                    if shengmu in pydict.MOHU_SHENGMU:
                        shengmu_ids = []
                        for s in pydict.MOHU_SHENGMU[shengmu]:
                            shengmu_ids.append (str (pydict.SHENGMU_DICT[s]))
                        sql_conditions.append ("s%d in (%s)" % (i, ",".join (shengmu_ids)))
                    else:
                        sql_conditions.append ("s%d = %d" % (i, py.get_sheng_mu_id ()))
                i += 1
        
        if pys[4:]:
            pp = lambda (x): x.get_pattern (mohu)
            pattern = "'".join (map (pp, pys[4:]))
            sql_conditions.append ("yx LIKE \"" + pattern + "\"")
        

        tables_union = tables_union % { "conditions" : " AND ".join (sql_conditions) }
        sql_prefix = "SELECT * FROM " + tables_union

        sql_string = sql_prefix + " GROUP BY phrase ORDER BY user_freq DESC, freq DESC;"

        result = list (self.db.execute (sql_string).fetchall ())
        
        self.select_cache [pinyin_string] = result

        return result
    
    def select_words_by_pinyin_string (self, string, mohu = False):
        """select words from the database by pinyin string"""

        pys = self.parser.parse (string)
        result = self.select_words_by_pinyin_list (pys, mohu)
        return result

    def commit_phrases (self, records):
        """this function adjusts frequence of phrase in user database."""

        for record in records:
            if record [USER_FREQ] != None:
                sql = "UPDATE user_db.py_phrase SET user_freq = user_freq + 1 WHERE ylen = ? AND y0 = ? AND phrase = ?;"
                self.db.execute (sql, (record[YLEN], record[Y0], record[PHRASE]))
            else:
                sql = """INSERT INTO user_db.py_phrase (ylen, y0, y1, y2, y3, yx, s0, s1, s2, s3, phrase, freq, user_freq)
                    VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, 1);"""
                self.db.execute (sql, record[:12])
        self.flush ()
        self.select_cache.clear ()

    def commit_phrase (self, record):
        self.commit_phrases ([record])

    def commit_char (self, char, pinyin_id, shengmu_id):
        sql = "SELECT * FROM main.py_phrase WHERE ylen = 1 AND y0 = ? AND phrase = ?"
        records = self.db.execute (sql, (pinyin_id, char)).fetchall ()
        self.commit_phrases (records)

    def new_phrase (self, phrases, freq = None, user_freq = 1):
        """this function create a new phrase from a phrase list and put it into user database."""
        pinyin_ids = []
        shengmu_ids = []
        phrase = u""
        phrase_length = 0
        for p in phrases:
            if phrase_length + p[YLEN] > 8:
                break
            phrase += p[PHRASE]
            phrase_length += p[YLEN]
            if p[YLEN] > 4:
                ys = p[YX].split ("'")
            for i in range (0, p[YLEN]):
                if i < 4:
                    pinyin_ids.append (p[Y0 + i])
                    shengmu_ids.append (p[S0 + i])
                else:
                    w = pyutil.PinYinWord (ys[i - 4])
                    pinyin_ids.append (w.get_pinyin_id ())
                    shengmu_ids.append (w.get_sheng_mu_id ())
        
        sql = """INSERT INTO user_db.py_phrase
            (ylen, y0, y1, y2, y3, yx, s0, s1, s2, s3, phrase, freq, user_freq) 
            VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"""

        values = [phrase_length, None, None, None, None, None, None, None, None, None, phrase, freq, user_freq]

        if phrase_length <=4:
            values[1: 1 + phrase_length] = pinyin_ids [:phrase_length]
            values[6: 6 + phrase_length] = shengmu_ids [:phrase_length]
        else:
            values[1: 5] = pinyin_ids [:4]
            values[6: 10] = shengmu_ids [:4]
            get_pinyin = lambda id: pydict.ID_PINYIN_DICT[id]
            values[5] = "'".join (map (get_pinyin, pinyin_ids[4:]))

        self.db.execute (sql, values)

        self.flush ()
        self.select_cache.clear ()

    def remove_phrase (self, record):
        "Remove phrase from user database"

        sql = "DELETE FROM user_db.py_phrase WHERE ylen = ? AND y0 = ? AND phrase = ?"

        self.db.execute (sql, (record[YLEN], record[Y0], record[PHRASE]))
        
        self.flush ()
        self.select_cache.clear ()

    def flush (self, force = False):
        if self._last_flush_time == None:
            self._last_flush_time = time.time ()
        if force or time.time() - self._last_flush_time >= FLUSH_PERIOD:
            self.db.commit ()
            self._last_flush_time = time.time ()

    
class Cache:
    """cache object for cache history queries"""

    class Slot:
        """Slot item of cache object"""
        def __init__ (self):
            self.time = -1
            self.value = None
            self.index = None
    
    def __init__ (self, max_slot = 1024):
        self._max_slot = max_slot
        self.clear ()

    def clear (self):
        self._slots = []
        self._dict = {}
        self._time = 0

    def __delitem__ (self, index):
        if not self._dict.has_key (index):
            return None
        del self._dict [index]

    def __getitem__ (self, index):
        """return a vale associate with the giving index. It cache does not has this index,
        it will retrun None."""
        if not self._dict.has_key (index):
            return None
        
        slot = self._dict [index]
        self._time += 1
        slot.time = self._time
        return slot.value

    def __setitem__ (self, index, value):
        if self._dict.has_key (index):
            slot = self._dict[index]
        else:
            slot = self.get_slot ()
        self._time += 1
        slot.value = value
        slot.time = self._time
        slot.index = index
        self._dict[index] = slot

    def get_slot (self):
        """get_slot will return a empty slot. If there is not any empty slot, 
        it will find the oldest slot and return it."""
        if len (self._slots) < self._max_slot:
            slot = Cache.Slot ()
            self._slots.append (slot)
        else:
            self._slots.sort (lambda x,y : x.time - y.time)        
            slot = self._slots[0]
            del self._dict[slot.index]
        return slot

def get_database_desc (db_file):
    if not path.exists (db_file):
        raise Exception ("%s does not exist!" % dbname)
    try:
        desc = {}
        db = sqlite.connect (db_file)
        for row in db.executescript ("SELECT * FROM desc;"):
            desc [row[0]] = row[1]
        return desc
    except:
        return None

def test_select_words ():
    import time

    db = PYSQLiteDB ()
    while True:
        l = raw_input ().strip ()
        if not l:
            break
        t = time.time ()
        res = db.select_words_by_pinyin_string (l)
        
        t = time.time () - t
        
        i = 0
        for p in res:
            print "%s = %s %s " % (i, str (p), p[PHRASE].encode ("utf8"))
            i += 1
        print "OK t =", t, " count =", len (res)
        while True:
            try:
                commit = int (raw_input ("commit = ").strip ())
                db.commit_phrase (res[commit])
            except KeyboardInterrupt, e:
                print "Exit"
                sys.exit (0)
            except:
                print "Input is invalidate"
                continue
            break

    

def test_case (string):
    db = PYSQLiteDB ()
    parser = pyparser.PinYinParser ()
    pys = parser.parse (string)

    result = u""

    while len (result) != len (pys):
        pps = pys[len (result):]
        for x in range (len (pps), 0, -1):
            candidates = db.select_words_by_pinyin_list (pps[:x])
            if candidates:
                result += candidates[0][PHRASE]
                break
    print "'".join (map (str, pys))
    print result

def test ():
    test_case ("gaodangfangdichankaifashangdedongtianjiuyaolaile")
    test_case ("huanyingshiyongwokaifadezhinengpinyinshurufa")
    test_case ("beijingshirenminzhengfujuedingzaitongzhouqujianlizhengfuxingzhengjidi")
    test_case ("woguojuminshoumingqiwangtigaodaoqishisansui")
    test_case ("wgjmshmqwtgdqshss")
    test_case ("xjinyhuiyouyongme")
    
if __name__ == "__main__":
    import timeit
    t = timeit.Timer ("pysqlitedb.test ()", "import pysqlitedb")
    print t.repeat (3,1)

