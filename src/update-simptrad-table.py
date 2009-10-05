#!/usr/bin/evn python

def str_to_unicode(s):
    if not s.startswith("U+"):
        raise Exception("%s is not a unicode" % s)
    s = s[2:]
    return unichr(int(s, 16))

def read_unihan():
    for line in file("Unihan_Variants.txt"):
        if line.startswith("#"):
            continue
        tokens = line.decode("utf8").strip().split()
        if u"kTraditionalVariant" not in tokens:
            continue
        yield str_to_unicode(tokens[0]), map(str_to_unicode, tokens[2:])
        
def main():
    print "const gunichar simp_to_trad[][2] = {"
    
    records = list(read_unihan())
    records.sort()
    for s, ts in records:
        print "    { 0x%x, 0x%x },   // %s => %s" % (ord(s), ord(ts[0]), s.encode("utf8"), ts[0].encode("utf8"))

    print "};"
    print '#define SIMP_TO_TRAD_NR (sizeof (simp_to_trad) / sizeof (simp_to_trad[0]))'
    print


if __name__ == "__main__":
    main()
