# vim:set et sts=4 ts=4:
# -*- coding: utf-8 -*-
from bopomofo import bopomofo_pinyin_map, bopomofo_tone_map

def chewing2pinyin(chewing):
    pinyin = bopomofo_pinyin_map.get(chewing.encode("utf8"), None)
    tone = 1
    if pinyin == None:
        pinyin = bopomofo_pinyin_map.get(chewing[:-1].encode("utf8"), None)
        tone = bopomofo_tone_map[chewing[-1:].encode("utf8")]
    return pinyin, tone

def main():
    lineno = 0
    for line in file("tsi.src"):
        lineno += 1
        try:
            line = line.strip().decode("utf8")
            phrase, freq, chewing =  line.split(' ', 2)
            chewing = chewing.split()
            pinyin = map(chewing2pinyin, chewing)
            print phrase, freq, pinyin
        except:
            print lineno, ":", line
            raise


if __name__ == "__main__":
    main()
