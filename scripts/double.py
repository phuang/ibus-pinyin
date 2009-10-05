import pydict

for name, (sheng, yun) in pydict.SHUANGPIN_SCHEMAS.items():
    print "static const gint double_pinyin_%s_sheng[] = {" % name.lower()
    for c in "abcdefghijklmnopqrstuvwxyz;":
        s = sheng.get(c, "VOID")
        if s == "'":
            s = "ZERO"
        else:
            s = s.upper()
        print "    PINYIN_ID_%s // %s" % ((s + ",").ljust(5), c.upper())
    print "};"
    
    print "static const gint double_pinyin_%s_yun[][2] = {" % name.lower()
    for c in "abcdefghijklmnopqrstuvwxyz;":
        s = yun.get(c, ("VOID", "VOID"))
        if len(s) == 1:
            s1 = s[0]
            s2 = "VOID"
        else:
            s1, s2 = s
        if s1 == "'":
            s1 = "ZERO"
        if s2 == "'":
            s2 = "ZERO"
        s1 = s1.upper()
        s2 = s2.upper()
        print "    { PINYIN_ID_%s PINYIN_ID_%s }, // %s" % ((s1 + ",").ljust(5), s2.ljust(4), c.upper())
    print "};"

print '''
static const struct {
    const gint  (&sheng)[27];
    const gint  (&yun)[27][2];
} double_pinyin_map [] = {'''
for name, (sheng, yun) in pydict.SHUANGPIN_SCHEMAS.items():
    print "    { double_pinyin_%s_sheng, double_pinyin_%s_yun}," %  (name.lower(), name.lower())
print "};"
