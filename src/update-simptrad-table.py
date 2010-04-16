#!/usr/bin/env python
from ZhConversion import *
from valid_hanzi import *

def convert(s, d, n):
    out = u""
    end = len(s)
    begin = 0
    while begin < end:
        for i in range(min(n, end - begin), 0, -1):
            t = s[begin:begin+i]
            t = d.get(t, t if i == 1 else None)
            if t:
                break
        out = out + t
        begin += i
    return out

def filter_more(records, n):
    han = filter(lambda (k, v): len(k) <= n, records)
    hand = dict(han)
    hanm = filter(lambda (k, v): convert(k, hand, n) != v, records)
    return hanm + han

def get_records():
    records = zh2Hant.items()

    # remove invalid hanzi
    records = filter(lambda (k, v): all([c in valid_hanzi for c in k]) and  all([c in valid_hanzi for c in v]), records)

    # remove if length is not equal
    records = filter(lambda (k, v): len(k) == len(v), records)

    # remove if length > 4
    records = filter(lambda (k, v): len(k) <= 6, records)

    maxlen = max(map(lambda (k,v): len(k), records))
    for i in range(1,  maxlen - 1, 1):
        records = filter_more(records, i)

    records.sort()
    return maxlen, records

def main():

    print "const wchar_t * const simp_to_trad[][2] = {"
    maxlen, records = get_records()
    for s, ts in records:
        print '    { L"%s", L"%s" },' % (s.encode("utf8"), ts.encode("utf8"))
    print "};"
    print '#define SIMP_TO_TRAD_MAX_LEN (%d)' % maxlen

if __name__ == "__main__":
    main()
