# vim:set et sts=4:
# -*- coding: utf-8 -*-

bopomofo = [
"BOPOMOFO_ZERO",
"BOPOMOFO_B",
"BOPOMOFO_P",
"BOPOMOFO_M",
"BOPOMOFO_F",
"BOPOMOFO_D",
"BOPOMOFO_T",
"BOPOMOFO_N",
"BOPOMOFO_L",
"BOPOMOFO_G",
"BOPOMOFO_K",
"BOPOMOFO_H",
"BOPOMOFO_J",
"BOPOMOFO_Q",
"BOPOMOFO_X",
"BOPOMOFO_ZH",
"BOPOMOFO_CH",
"BOPOMOFO_SH",
"BOPOMOFO_R",
"BOPOMOFO_Z",
"BOPOMOFO_C",
"BOPOMOFO_S",
"BOPOMOFO_I",
"BOPOMOFO_U",
"BOPOMOFO_V",
"BOPOMOFO_A",
"BOPOMOFO_O",
"BOPOMOFO_E",
"BOPOMOFO_E2",
"BOPOMOFO_AI",
"BOPOMOFO_EI",
"BOPOMOFO_AO",
"BOPOMOFO_OU",
"BOPOMOFO_AN",
"BOPOMOFO_EN",
"BOPOMOFO_ANG",
"BOPOMOFO_ENG",
"BOPOMOFO_ER",
"BOPOMOFO_TONE_2",
"BOPOMOFO_TONE_3",
"BOPOMOFO_TONE_4",
"BOPOMOFO_TONE_5",
]

bopomofo_keyboard = (
    #標準注音鍵盤
    (
    "1","q","a","z","2","w","s","x","e","d","c","r","f","v","5","t","g","b","y","h","n",
    "u","j","m","8","i","k",",","9","o","l",".","0","p",";","/","-",
    "6","3","4","7",
    ),
    #精業注音鍵盤
    (
    "2","w","s","x","3","e","d","c","r","f","v","t","g","b","6","y","h","n","u","j","m",
    "-","[","'","8","i","k",",","9","o","l",".","0","p",";","/","=",
    "q","a","z","1",
    ),
    #倚天注音鍵盤
    (
    "b","p","m","f","d","t","n","l","v","k","h","g","7","c",",",".","/","j",";","'","s",
    "e","x","u","a","o","r","w","i","q","z","y","8","9","0","-","=",
    "2","3","4","1",
    ),
    #IBM注音鍵盤
    (
    "1","2","3","4","5","6","7","8","9","0","-","q","w","e","r","t","y","u","i","o","p",
    "a","s","d","f","g","h","j","k","l",";","z","x","c","v","b","n",
    "m",",",".","/",
    ),
)

def tochar(ch):
    if ch == "'" or ch == "\\":
        ch = "\\" + ch;
    return "'" + ch + "'"

def gen_table():
    i = 0
    print 'static const guint8'
    print 'bopomofo_keyboard[][41][2] = {'
    for keyboard in bopomofo_keyboard:
        print '    {'
        items = []
        i=1
        for v in keyboard:
            items.append ((v,bopomofo[i]));
            i += 1
        items.sort()
        for k,v in items:
            print '        { %-4s, %-15s },' % (tochar(k),v)
        print '    },'
    print '};'
    print

if __name__ == "__main__":
    gen_table()
