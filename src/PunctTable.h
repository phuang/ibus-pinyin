static const gchar * const
puncts[] = {
    "", "，", "。", "「", "」", "、", "：", "；", "？", "！", NULL,
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
    &puncts[11],    // "!"
    &puncts[17],    // "\""
    &puncts[22],    // "#"
    &puncts[27],    // "$"
    &puncts[35],    // "%"
    &puncts[43],    // "&"
    &puncts[47],    // "'"
    &puncts[52],    // "("
    &puncts[57],    // ")"
    &puncts[62],    // "*"
    &puncts[73],    // "+"
    &puncts[78],    // ","
    &puncts[84],    // "-"
    &puncts[96],    // "."
    &puncts[103],    // "/"
    &puncts[110],    // "0"
    &puncts[114],    // "1"
    &puncts[118],    // "2"
    &puncts[122],    // "3"
    &puncts[126],    // "4"
    &puncts[130],    // "5"
    &puncts[134],    // "6"
    &puncts[138],    // "7"
    &puncts[142],    // "8"
    &puncts[146],    // "9"
    &puncts[150],    // ":"
    &puncts[155],    // ";"
    &puncts[159],    // "<"
    &puncts[167],    // "="
    &puncts[176],    // ">"
    &puncts[184],    // "?"
    &puncts[190],    // "@"
    &puncts[199],    // "A"
    &puncts[203],    // "B"
    &puncts[207],    // "C"
    &puncts[211],    // "D"
    &puncts[215],    // "E"
    &puncts[219],    // "F"
    &puncts[223],    // "G"
    &puncts[227],    // "H"
    &puncts[231],    // "I"
    &puncts[235],    // "J"
    &puncts[239],    // "K"
    &puncts[243],    // "L"
    &puncts[247],    // "M"
    &puncts[251],    // "N"
    &puncts[255],    // "O"
    &puncts[259],    // "P"
    &puncts[263],    // "Q"
    &puncts[267],    // "R"
    &puncts[271],    // "S"
    &puncts[275],    // "T"
    &puncts[279],    // "U"
    &puncts[283],    // "V"
    &puncts[287],    // "W"
    &puncts[291],    // "X"
    &puncts[295],    // "Y"
    &puncts[299],    // "Z"
    &puncts[303],    // "["
    &puncts[313],    // "\\"
    &puncts[319],    // "]"
    &puncts[329],    // "^"
    &puncts[337],    // "_"
    &puncts[343],    // "`"
    &puncts[347],    // "a"
    &puncts[351],    // "b"
    &puncts[355],    // "c"
    &puncts[359],    // "d"
    &puncts[363],    // "e"
    &puncts[367],    // "f"
    &puncts[371],    // "g"
    &puncts[375],    // "h"
    &puncts[379],    // "i"
    &puncts[383],    // "j"
    &puncts[387],    // "k"
    &puncts[391],    // "l"
    &puncts[395],    // "m"
    &puncts[399],    // "n"
    &puncts[403],    // "o"
    &puncts[407],    // "p"
    &puncts[411],    // "q"
    &puncts[415],    // "r"
    &puncts[419],    // "s"
    &puncts[423],    // "t"
    &puncts[427],    // "u"
    &puncts[431],    // "v"
    &puncts[435],    // "w"
    &puncts[439],    // "x"
    &puncts[443],    // "y"
    &puncts[447],    // "z"
    &puncts[451],    // "{"
    &puncts[459],    // "|"
    &puncts[470],    // "}"
    &puncts[478],    // "~"
};
