# vim:set et sts=4:
# -*- coding: utf-8 -*-

from punct import *

def tocstr(s):
    s = s.replace('\\', '\\\\')
    s = s.replace('"', '\\"')
    return '"%s"' % s

def gen_table():
    array = []
    i = 0
    print 'static const gchar * const'
    print 'puncts[] = {'
    for k, vs in punct_map:
        k = tocstr(k)
        vs = map(tocstr, vs)
        array.append((i, k))
        line = '    %s, %s, NULL,' % (k, ", ".join(vs))
        print line.encode("utf8")
        i += len(vs) + 2
    print '};'
    print
    print 'static const gchar * const * const'
    print 'punct_table[] = {'
    for i, k in array:
        print '    &puncts[%d],    // %s' % (i, k)
    print '};'

if __name__ == "__main__":
    gen_table()
