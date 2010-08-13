static const gchar * const
puncts[] = {
    "", "·", "，", "。", "「", "」", "、", "：", "；", "？", "！", NULL,
    "!", "！", "﹗", "‼", "⁉", NULL,
    "\"", "“", "”", "＂", NULL,
    "#", "＃", "﹟", "♯", NULL,
    "$", "＄", "€", "﹩", "￠", "￡", "￥", NULL,
    "%", "％", "﹪", "‰", "‱", "㏙", "㏗", NULL,
    "&", "＆", "﹠", NULL,
    "'", "、", "‘", "’", NULL,
    "(", "（", "︵", "﹙", NULL,
    ")", "）", "︶", "﹚", NULL,
    "*", "＊", "×", "※", "╳", "﹡", "⁎", "⁑", "⁂", "⌘", NULL,
    "+", "＋", "±", "﹢", NULL,
    ",", "，", "、", "﹐", "﹑", NULL,
    "-", "…", "—", "－", "¯", "﹉", "￣", "﹊", "ˍ", "–", "‥", NULL,
    ".", "。", "·", "‧", "﹒", "．", NULL,
    "/", "／", "÷", "↗", "↙", "∕", NULL,
    "0", "０", "0", NULL,
    "1", "１", "1", NULL,
    "2", "２", "2", NULL,
    "3", "３", "3", NULL,
    "4", "４", "4", NULL,
    "5", "５", "5", NULL,
    "6", "６", "6", NULL,
    "7", "７", "7", NULL,
    "8", "８", "8", NULL,
    "9", "９", "9", NULL,
    ":", "：", "︰", "﹕", NULL,
    ";", "；", "﹔", NULL,
    "<", "＜", "〈", "《", "︽", "︿", "﹤", NULL,
    "=", "＝", "≒", "≠", "≡", "≦", "≧", "﹦", NULL,
    ">", "＞", "〉", "》", "︾", "﹀", "﹥", NULL,
    "?", "？", "﹖", "⁇", "⁈", NULL,
    "@", "＠", "⊕", "⊙", "㊣", "﹫", "◉", "◎", NULL,
    "A", "Ａ", "A", NULL,
    "B", "Ｂ", "B", NULL,
    "C", "Ｃ", "C", NULL,
    "D", "Ｄ", "D", NULL,
    "E", "Ｅ", "E", NULL,
    "F", "Ｆ", "F", NULL,
    "G", "Ｇ", "G", NULL,
    "H", "Ｈ", "H", NULL,
    "I", "Ｉ", "I", NULL,
    "J", "Ｊ", "J", NULL,
    "K", "Ｋ", "K", NULL,
    "L", "Ｌ", "L", NULL,
    "M", "Ｍ", "M", NULL,
    "N", "Ｎ", "N", NULL,
    "O", "Ｏ", "O", NULL,
    "P", "Ｐ", "P", NULL,
    "Q", "Ｑ", "Q", NULL,
    "R", "Ｒ", "R", NULL,
    "S", "Ｓ", "S", NULL,
    "T", "Ｔ", "T", NULL,
    "U", "Ｕ", "U", NULL,
    "V", "Ｖ", "V", NULL,
    "W", "Ｗ", "W", NULL,
    "X", "Ｘ", "X", NULL,
    "Y", "Ｙ", "Y", NULL,
    "Z", "Ｚ", "Z", NULL,
    "[", "「", "［", "『", "【", "｢", "︻", "﹁", "﹃", NULL,
    "\\", "＼", "↖", "↘", "﹨", NULL,
    "]", "」", "］", "』", "】", "｣", "︼", "﹂", "﹄", NULL,
    "^", "︿", "〈", "《", "︽", "﹤", "＜", NULL,
    "_", "＿", "╴", "←", "→", NULL,
    "`", "‵", "′", NULL,
    "a", "ａ", "a", NULL,
    "b", "ｂ", "b", NULL,
    "c", "ｃ", "c", NULL,
    "d", "ｄ", "d", NULL,
    "e", "ｅ", "e", NULL,
    "f", "ｆ", "f", NULL,
    "g", "ｇ", "g", NULL,
    "h", "ｈ", "h", NULL,
    "i", "ｉ", "i", NULL,
    "j", "ｊ", "j", NULL,
    "k", "ｋ", "k", NULL,
    "l", "ｌ", "l", NULL,
    "m", "ｍ", "m", NULL,
    "n", "ｎ", "n", NULL,
    "o", "ｏ", "o", NULL,
    "p", "ｐ", "p", NULL,
    "q", "ｑ", "q", NULL,
    "r", "ｒ", "r", NULL,
    "s", "ｓ", "s", NULL,
    "t", "ｔ", "t", NULL,
    "u", "ｕ", "u", NULL,
    "v", "ｖ", "v", NULL,
    "w", "ｗ", "w", NULL,
    "x", "ｘ", "x", NULL,
    "y", "ｙ", "y", NULL,
    "z", "ｚ", "z", NULL,
    "{", "｛", "︷", "﹛", "〔", "﹝", "︹", NULL,
    "|", "｜", "↑", "↓", "∣", "∥", "︱", "︳", "︴", "￤", NULL,
    "}", "｝", "︸", "﹜", "〕", "﹞", "︺", NULL,
    "~", "～", "﹋", "﹌", NULL,
};

static const gchar * const * const
punct_table[] = {
    &puncts[0],    // ""
    &puncts[12],    // "!"
    &puncts[18],    // "\""
    &puncts[23],    // "#"
    &puncts[28],    // "$"
    &puncts[36],    // "%"
    &puncts[44],    // "&"
    &puncts[48],    // "'"
    &puncts[53],    // "("
    &puncts[58],    // ")"
    &puncts[63],    // "*"
    &puncts[74],    // "+"
    &puncts[79],    // ","
    &puncts[85],    // "-"
    &puncts[97],    // "."
    &puncts[104],    // "/"
    &puncts[111],    // "0"
    &puncts[115],    // "1"
    &puncts[119],    // "2"
    &puncts[123],    // "3"
    &puncts[127],    // "4"
    &puncts[131],    // "5"
    &puncts[135],    // "6"
    &puncts[139],    // "7"
    &puncts[143],    // "8"
    &puncts[147],    // "9"
    &puncts[151],    // ":"
    &puncts[156],    // ";"
    &puncts[160],    // "<"
    &puncts[168],    // "="
    &puncts[177],    // ">"
    &puncts[185],    // "?"
    &puncts[191],    // "@"
    &puncts[200],    // "A"
    &puncts[204],    // "B"
    &puncts[208],    // "C"
    &puncts[212],    // "D"
    &puncts[216],    // "E"
    &puncts[220],    // "F"
    &puncts[224],    // "G"
    &puncts[228],    // "H"
    &puncts[232],    // "I"
    &puncts[236],    // "J"
    &puncts[240],    // "K"
    &puncts[244],    // "L"
    &puncts[248],    // "M"
    &puncts[252],    // "N"
    &puncts[256],    // "O"
    &puncts[260],    // "P"
    &puncts[264],    // "Q"
    &puncts[268],    // "R"
    &puncts[272],    // "S"
    &puncts[276],    // "T"
    &puncts[280],    // "U"
    &puncts[284],    // "V"
    &puncts[288],    // "W"
    &puncts[292],    // "X"
    &puncts[296],    // "Y"
    &puncts[300],    // "Z"
    &puncts[304],    // "["
    &puncts[314],    // "\\"
    &puncts[320],    // "]"
    &puncts[330],    // "^"
    &puncts[338],    // "_"
    &puncts[344],    // "`"
    &puncts[348],    // "a"
    &puncts[352],    // "b"
    &puncts[356],    // "c"
    &puncts[360],    // "d"
    &puncts[364],    // "e"
    &puncts[368],    // "f"
    &puncts[372],    // "g"
    &puncts[376],    // "h"
    &puncts[380],    // "i"
    &puncts[384],    // "j"
    &puncts[388],    // "k"
    &puncts[392],    // "l"
    &puncts[396],    // "m"
    &puncts[400],    // "n"
    &puncts[404],    // "o"
    &puncts[408],    // "p"
    &puncts[412],    // "q"
    &puncts[416],    // "r"
    &puncts[420],    // "s"
    &puncts[424],    // "t"
    &puncts[428],    // "u"
    &puncts[432],    // "v"
    &puncts[436],    // "w"
    &puncts[440],    // "x"
    &puncts[444],    // "y"
    &puncts[448],    // "z"
    &puncts[452],    // "{"
    &puncts[460],    // "|"
    &puncts[471],    // "}"
    &puncts[479],    // "~"
};
