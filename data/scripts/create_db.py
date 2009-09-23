import sqlite3
from pydict import *
from id import *
import sys

con1 = sqlite3.connect("py.db")
con2 = sqlite3.connect("py-new.db")
con2.execute ("PRAGMA synchronous = NORMAL;")
con2.execute ("PRAGMA temp_store = MEMORY;")
con2.execute ("PRAGMA default_cache_size = 5000;")

sql = "CREATE TABLE py_phrase_%d (phrase TEXT, freq INTEGER, %s)"

for i in range(0, 16):
	column= []
	for j in range(0, i + 1):
		column.append ("s%d INTEGER" % j)
		column.append ("y%d INTEGER" % j)
	column = ",".join(column)
	con2.execute(sql % (i, column))
con2.commit()

def get_sheng_yun(pinyin):
	if pinyin == None:
		return None, None
	if pinyin == "ng":
		return "", "en"
	for i in xrange(2, 0, -1):
		t = pinyin[:i]
		if t in SHENGMU_DICT:
			return t, pinyin[len(t):]
	return "", pinyin

def encode_pinyin(pinyin):
	if pinyin == None or pinyin == "":
		return 0
        return pinyin_id[pinyin]
	e = 0
	for c in pinyin:
		e = (e << 5) + (ord(c) - ord('a') + 1)
	return e

insert_sql = "INSERT INTO py_phrase_%d VALUES (%s);"
con2.commit()
new_freq = 0
freq = 0

print "INSERTING"
for  r in con1.execute("SELECT * FROM py_phrase ORDER BY freq"):
	ylen = r[0]
	phrase = r[10]
	if r[11] > freq:
		freq = r[11]
		new_freq += 1

	if ylen <= 4:
		pys = map(lambda id: ID_PINYIN_DICT[id], r[1: 1 + ylen])
	else:
		pys = map(lambda id: ID_PINYIN_DICT[id], r[1: 5]) + r[5].encode("utf8").split("'")

	i = ylen - 1
	if i >= 15:
		i = 15

	pys = pys[0:16]

	sheng_yun = []
	for s, y in map(get_sheng_yun, pys):
		sheng_yun.append(s)
		sheng_yun.append(y)
	
	
	column = [phrase, new_freq] + map(encode_pinyin, sheng_yun)

	sql = insert_sql % (i, ",".join(["?"] * len(column)))
	con2.execute (sql, column)

print "Remove duplicate"
for i in xrange(0, 16):
    sql = "DELETE FROM py_phrase_%d WHERE rowid IN (SELECT rowid FROM (SELECT count() as count, rowid FROM py_phrase_%d GROUP by %s,phrase) WHERE count > 1)" % (i, i, ",".join(map(lambda i: "s%d,y%d"%(i,i), range(0, i + 1))))
    con2.execute(sql)
con2.commit()
print "CACUUM"
con2.execute("VACUUM;")
con2.commit()

# con2.execute("create index index_0_0 on py_phrase_0(s0, y0)")
# 
# for i in xrange(1, 16):
# 	con2.execute("create index index_%d_0 on py_phrase_%d(s0, y0, s1, y1)" % (i, i))
# 	con2.execute("create index index_%d_1 on py_phrase_%d(s0, s1, y1)" % (i, i))
# 
# con2.execute("vacuum")
# con2.commit()
