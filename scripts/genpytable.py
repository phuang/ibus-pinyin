# vim:set et sts=4:
# -*- coding: utf-8 -*-

from pydict import *
from bopomofo import *

def str_cmp(a, b):
    if len(a) == len(b):
        return cmp(a, b)
    else:
        return len(a) - len(b)

pinyin_list = PINYIN_DICT.keys()
pinyin_list.sort()

shengmu_list = SHENGMU_DICT.keys()
shengmu_list.remove("")
shengmu_list.sort()

auto_correct = [
    # "correct", "wrong"
    ("ng", "gn"),
    ("ng", "mg"),
    ("iu", "iou"),
    ("ui", "uei"),
    ("un", "uen"),
#    ("ue", "ve"),
    ("ve", "ue"),
    ("ong", "on"),
]

auto_correct_ext = [
    # "correct", "wrong", flag
    ("ju", "jv", "PINYIN_CORRECT_V_TO_U"),
    ("qu", "qv", "PINYIN_CORRECT_V_TO_U"),
    ("xu", "xv", "PINYIN_CORRECT_V_TO_U"),
    ("yu", "yv", "PINYIN_CORRECT_V_TO_U"),

    ("jue", "jve", "PINYIN_CORRECT_V_TO_U"),
    ("que", "qve", "PINYIN_CORRECT_V_TO_U"),
    ("xue", "xve", "PINYIN_CORRECT_V_TO_U"),
    ("yue", "yve", "PINYIN_CORRECT_V_TO_U"),

    ("juan", "jvan", "PINYIN_CORRECT_V_TO_U"),
    ("quan", "qvan", "PINYIN_CORRECT_V_TO_U"),
    ("xuan", "xvan", "PINYIN_CORRECT_V_TO_U"),
    ("yuan", "yvan", "PINYIN_CORRECT_V_TO_U"),

    ("jun", "jvn", "PINYIN_CORRECT_V_TO_U"),
    ("qun", "qvn", "PINYIN_CORRECT_V_TO_U"),
    ("xun", "xvn", "PINYIN_CORRECT_V_TO_U"),
    ("yun", "yvn", "PINYIN_CORRECT_V_TO_U"),

    ("juang", "jvang", "PINYIN_FUZZY_UANG_UAN | PINYIN_CORRECT_V_TO_U"),
    ("quang", "qvang", "PINYIN_FUZZY_UANG_UAN | PINYIN_CORRECT_V_TO_U"),
    ("xuang", "xvang", "PINYIN_FUZZY_UANG_UAN | PINYIN_CORRECT_V_TO_U"),
    ("yuang", "yvang", "PINYIN_FUZZY_UANG_UAN | PINYIN_CORRECT_V_TO_U"),

    ("jun", "jven", "PINYIN_CORRECT_UEN_TO_UN | PINYIN_CORRECT_V_TO_U"),
    ("qun", "qven", "PINYIN_CORRECT_UEN_TO_UN | PINYIN_CORRECT_V_TO_U"),
    ("xun", "xven", "PINYIN_CORRECT_UEN_TO_UN | PINYIN_CORRECT_V_TO_U"),
    ("yun", "yven", "PINYIN_CORRECT_UEN_TO_UN | PINYIN_CORRECT_V_TO_U"),
]

fuzzy_shengmu = [
    ("c", "ch"),
    ("ch", "c"),
    ("z", "zh"),
    ("zh", "z"),
    ("s", "sh"),
    ("sh", "s"),
    ("l", "n"),
    ("n", "l"),
    ("f", "h"),
    ("h", "f"),
    ("l", "r"),
    ("r", "l"),
    ("k", "g"),
    ("g", "k"),
]

fuzzy_yunmu = [
    ("an", "ang"),
    ("ang", "an"),
    ("en", "eng"),
    ("eng", "en"),
    ("in", "ing"),
    ("ing", "in"),
    ("ian", "iang"),
    ("iang", "ian"),
    ("uan", "uang"),
    ("uang", "uan"),
]

def get_sheng_yun(pinyin):
    if pinyin == None:
        return None, None
    if pinyin == "ng":
        return "", "ng"
    for i in range(2, 0, -1):
        s = pinyin[:i]
        if s in shengmu_list:
            return s, pinyin[i:]
    return "", pinyin

yunmu_list = set([])
for p in pinyin_list:
    s, y = get_sheng_yun(p)
    yunmu_list |= set([y])
yunmu_list = list(yunmu_list)
yunmu_list.sort()

shengmu_yunmu_list = shengmu_list + yunmu_list
id_dict = {}
for i, y in enumerate(shengmu_yunmu_list):
    id_dict[y] = i + 1

fuzzy_shengmu_dict = {}
for s1, s2 in fuzzy_shengmu:
    if s1 not in fuzzy_shengmu_dict:
        fuzzy_shengmu_dict[s1] = []
    fuzzy_shengmu_dict[s1].append(s2)

fuzzy_yunmu_dict = {}
for y1, y2 in fuzzy_yunmu:
    if y1 not in fuzzy_yunmu_dict:
        fuzzy_yunmu_dict[y1] = []
    fuzzy_yunmu_dict[y1].append(y2)

def encode_pinyin(pinyin):
    if pinyin == None or pinyin == "":
        return 0
    return id_dict[pinyin]

    e = 0
    for c in pinyin:
        e = (e << 5) + (ord(c) - ord('a') + 1)
    return e

def get_pinyin():
    for p in pinyin_list:
        s, y = get_sheng_yun(p)
        yield p, s, y, len(p), []

    for s in shengmu_list:
        yield s, s, "", len(s), ["PINYIN_INCOMPLETE_PINYIN"]

    for c, w in auto_correct:
        flag = "PINYIN_CORRECT_%s_TO_%s" % (w.upper(), c.upper())
        for p in pinyin_list:
            if p.endswith(c) and p != c:
                wp = p.replace(c, w)
                s, y = get_sheng_yun(p)
                yield wp, s, y, len(wp), [flag]

    for c, w, flag in auto_correct_ext:
        s, y = get_sheng_yun(c)
        yield w, s, y, len(w), [flag]

    for s1, s2 in fuzzy_shengmu:
        flag = "PINYIN_FUZZY_%s_%s" % (s1.upper(), s2.upper())
        for y in  yunmu_list:
            if s1 + y not in pinyin_list and s2 + y in pinyin_list:
                yield s1 + y, s1, y, len(s1) + len(y),  [flag]
        for c, w in auto_correct:
            if s1 + w not in pinyin_list and \
               s1 + c not in pinyin_list and \
               s2 + w not in pinyin_list and \
               s2 + c in pinyin_list:
                flag_correct = "PINYIN_CORRECT_%s_TO_%s" % (w.upper(), c.upper())
                yield s1 + w, s1, c, len(s2) + len(w), ["%s | %s" % (flag, flag_correct)]

            # if s2 + y not in pinyin_list and s1 + y in pinyin_list:
            #     yield s2 + y, s2, y, len (s2) + len(y), [flag]

    for y1, y2 in fuzzy_yunmu:
        flag = "PINYIN_FUZZY_%s_%s" % (y1.upper(), y2.upper())
        for s in shengmu_list:
            if s + y1 not in pinyin_list and s + y2 in pinyin_list:
                yield s + y1, s, y1, len(s) + len(y1), [flag]
            # if s + y2 not in pinyin_list and s + y1 in pinyin_list:
            #     yield s + y2, s, y2, len(s) + len(y2), [flag]


def get_pinyin_with_fuzzy():
    for text, s, y, l, flags in get_pinyin():
        fss = fuzzy_shengmu_dict.get(s, ["", ""])
        fys = fuzzy_yunmu_dict.get(y, ["", ""])

        try:
            fs1, fs2 = fss
        except:
            fs1, fs2 = fss[0], ""

        try:
            fy1, fy2 = fys
        except:
            fy1, fy2 = fys[0], ""

        if fs1 and \
            (fs1 + y not in pinyin_list) and \
            (fy1 and fs1 + fy1 not in pinyin_list) and \
            (fy2 and fs1 + fy2 not in pinyin_list):
            fs1 = ""

        if fs2 and \
            (fs2 + y not in pinyin_list) and \
            (fy1 and fs2 + fy1 not in pinyin_list) and \
            (fy2 and fs2 + fy2 not in pinyin_list):
            fs2 = ""

        if fy1 and \
            (s + fy1 not in pinyin_list) and \
            (fs1 and fs1 + fy1 not in pinyin_list) and \
            (fs2 and fs2 + fy1 not in pinyin_list):
            fy1 = ""

        if fy2 and \
            (s + fy2 not in pinyin_list) and \
            (fs1 and fs1 + fy2 not in pinyin_list) and \
            (fs2 and fs2 + fy2 not in pinyin_list):
            fy2 = ""

        bopomofo = pinyin_bopomofo_map.get(text, "")

        if bopomofo == "":
            if all([f.startswith("PINYIN_FUZZY_") for f in flags[0].split(" | ")]):
                #if it is fuzzy pinyin or normal pinyin
                if s in sheng_yun_bopomofo_map and y in sheng_yun_bopomofo_map:
                    if isinstance(sheng_yun_bopomofo_map[s], str):
                        bopomofo = sheng_yun_bopomofo_map[s]
                    else:
                        if y in sheng_yun_bopomofo_map[s][1][0]:
                            bopomofo += sheng_yun_bopomofo_map[s][1][1]
                        else:
                            bopomofo += sheng_yun_bopomofo_map[s][0]

                    if isinstance(sheng_yun_bopomofo_map[y], str):
                        bopomofo += sheng_yun_bopomofo_map[y]
                    else:
                        if s in sheng_yun_bopomofo_map[y][1][0]:
                            bopomofo += sheng_yun_bopomofo_map[y][1][1]
                        else:
                            bopomofo += sheng_yun_bopomofo_map[y][0]
                else:
                    print text

        yield text, bopomofo, s, y, fs1, fy1, fs2, fy2, l, flags


def gen_header():
    print '''/* Please do not modify this file. It is generated by script */
#include "Types.h"

namespace PY {
'''

def gen_macros():
    print '#define PINYIN_ID_VOID    (-1)'
    print '#define PINYIN_ID_ZERO    (0)'
    for y in shengmu_list:
        print '#define PINYIN_ID_%s    (%d)' % (y.upper(), encode_pinyin(y))

    for y in yunmu_list:
        print '#define PINYIN_ID_%s    (%d)' % (y.upper(), encode_pinyin(y))
    print
    print
    print

def gen_option_check(name, fuzzy):
    print '''static gboolean
%s (guint option, gint id, gint fid)
{
    switch ((id << 16) | fid) {''' % name
    for y1, y2 in fuzzy:
        flag = "PINYIN_FUZZY_%s_%s" % (y1.upper(), y2.upper())
        args = tuple(["PINYIN_ID_%s" % y.upper() for y in [y1, y2]]) + (flag, )
        print '''    case (%s << 16) | %s:
        return (option & %s);''' % args

    print '    default: return FALSE;'
    print '    }'
    print '}'

def union_dups(a):
    n = {}
    for r in a:
        if r[:-1] in n:
            n[r[:-1]] += r[-1]
        else:
            n[r[:-1]] = r[-1]
    na = []
    for k, flags in n.items():
        na.append (tuple(list(k) + [" | ".join(flags) if flags else "0"]))
    na.sort()
    return na

def gen_table():

    pinyins = list(get_pinyin_with_fuzzy())
    pinyins = union_dups(pinyins)

    print 'static const Pinyin pinyin_table[] = {'
    for i, (text, bopomofo, s, y, fs1, fy1, fs2, fy2, l, flags)  in enumerate(pinyins):
        s_id = "PINYIN_ID_%s" % s.upper() if s else "PINYIN_ID_ZERO"
        y_id = "PINYIN_ID_%s" % y.upper() if y else "PINYIN_ID_ZERO"
        fs1_id = "PINYIN_ID_%s" % fs1.upper() if fs1 else "PINYIN_ID_ZERO"
        fy1_id = "PINYIN_ID_%s" % fy1.upper() if fy1 else "PINYIN_ID_ZERO"
        fs2_id = "PINYIN_ID_%s" % fs2.upper() if fs2 else "PINYIN_ID_ZERO"
        fy2_id = "PINYIN_ID_%s" % fy2.upper() if fy2 else "PINYIN_ID_ZERO"

        # args = (i, ) + tuple(['"%s"' % s for s in p[:3]]) + tuple(["PINYIN_ID_%s" % s.upper() if s else "PINYIN_ID_ZERO" for s in p[3:9]]) + p[9:-1] + (str(p[-1]), )
        print '''    {  /* %d */
        text        : "%s",
        bopomofo    : L"%s",
        sheng       : "%s",
        yun         : "%s",
        pinyin_id   : {{ %s, %s }, { %s, %s }, { %s, %s }},
        len         : %d,
        flags       : %s
    },''' % (i, text, bopomofo, s, y.replace("v", "ü"), s_id, y_id, fs1_id, fy1_id, fs2_id, fy2_id, l, flags)

    print '};'
    print

    return pinyins

def gen_bopomofo_table(pinyins):
    bopomofo_table = [ (i, p) for i, p in enumerate(pinyins)]
    bopomofo_table.sort(lambda a, b: cmp(a[1][1], b[1][1]))
    print 'static const Pinyin *bopomofo_table[] = {'
    for i, p in bopomofo_table:
        if p[1]:
            print '    %-20s %s' % ('&pinyin_table[%d],' % i, '// "%s" => "%s"' % (p[1], p[0]))
    print '};'
    print

def get_all_special(pinyins):
    for p in pinyins:
        if p[-1] in ["n", "g", "r"]:
            for yun in yunmu_list:
                if yun not in pinyin_list:
                    continue
                new_pinyin = p[-1] + yun
                # if new_pinyin in pinyin_list:
                yield p, yun, p[:-1], new_pinyin
        elif p[-1] in ["e"]:
            yield p, "r", p[:-1], "er"

def get_max_freq_2(db, p1, p2):
    s1, y1 = get_sheng_yun(p1)
    s2, y2 = get_sheng_yun(p2)

    sql = "select max(freq), phrase from py_phrase_1 where s0 = %d and y0 = %d and s1 = %d and y1 = %d"

    c = db.execute(sql % (encode_pinyin(s1), encode_pinyin(y1), encode_pinyin(s2), encode_pinyin(y2)))
    for r in c:
        return r[0]
    return 0

def get_max_freq_1(db, p1):
    s1, y1 = get_sheng_yun(p1)

    sql = "select max(freq), phrase from py_phrase_0 where s0 = %d and y0 = %d"

    c = db.execute(sql % (encode_pinyin(s1), encode_pinyin(y1)))
    for r in c:
        return r[0] if r[0] else 0
    return 0

def compaired_special(pinyins):
    import sqlite3
    db = sqlite3.connect("open-phrase.db")
    # db = sqlite3.connect("main.db")

    for p1, p2, p3, p4 in get_all_special(pinyins):
        if p3 not in pinyin_list or p4 not in pinyin_list:
            continue
        if p1 not in pinyin_list or p2 not in pinyin_list:
            yield p1, p2, p3, p4
            continue

        if p3 not in pinyin_list or p4 not in pinyin_list:
            continue

        a1 = get_max_freq_2(db, p1, p2)
        a2 = get_max_freq_2(db, p3, p4)
        if a1 == a2:
            a1 = get_max_freq_1(db, p1) + get_max_freq_1(db, p2)
            a2 = get_max_freq_1(db, p3) + get_max_freq_1(db, p4)
        if a1 < a2:
            yield p1, p2, p3, p4

def gen_full_pinyin_table(pinyins):
    _dict = {}
    for i in xrange(0, len(pinyins)):
        _dict[pinyins[i]] = i
    full_pinyin = []
    for i in xrange(0, len(pinyins)):
        if pinyins[i][0] in pinyin_list:
            full_pinyin.append (pinyins[i])
    full_pinyin.sort(lambda a, b: (cmp(a[1], b[1]) << 16) + cmp(a[2],b[4]))
    print 'static const Pinyin *full_pinyin_table[] = {'
    for p in full_pinyin:
        print "    &pinyin_table[%d],    // %s" % (_dict[p], p[0])
    print '};'
    print


def gen_special_table(pinyins):
    _dict = {}
    for i in xrange(0, len(pinyins)):
        _dict[pinyins[i][0]] = i

    l = list(compaired_special(_dict.keys()))
    l.sort()
    print 'static const Pinyin *special_table[][4] = {'
    for r in l:
        ids =  [("&pinyin_table[%d]," % _dict[py]).ljust(20) for py in r]

        print '    { %s %s %s %s },' % tuple(ids), "/* %s %s => %s %s */" % r
    print '};'
    print


def main():
    # gen_header()
    # gen_macros()
    pinyins = gen_table()
    # gen_full_pinyin_table (pinyins)
    gen_bopomofo_table(pinyins)
    gen_special_table(pinyins)
    # gen_option_check("pinyin_option_check_sheng", fuzzy_shengmu)
    # gen_option_check("pinyin_option_check_yun", fuzzy_yunmu)


if __name__ == "__main__":
    main()

