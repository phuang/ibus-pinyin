static const gchar * const
puncts[] = {
    "", "，", "。", "「", "」", "、", "：", "；", "？", "！", NULL,
    "!", "！", "﹗", "‼", "⁉", NULL,
    "\"", "“", "”", "＂", NULL,
    "#", "＃", "﹟", "♯", NULL,
    "$", "＄", "€", "﹩", "￠", "￡", "￥", NULL,
    "%", "％", "﹪", "‰", "‱", "㏙", "㏗", NULL,
    "&", "＆", "﹠", NULL,
    "(", "（", "︵", "﹙", NULL,
    ")", "）", "︶", "﹚", NULL,
    "*", "＊", "×", "※", "╳", "﹡", "⁎", "⁑", "⁂", "⌘", NULL,
    "+", "＋", "±", "﹢", NULL,
    ",", "，", "、", "﹐", "﹑", NULL,
    "-", "…", "—", "－", "¯", "﹉", "￣", "﹊", "ˍ", "–", "‥", NULL,
    ".", "。", "·", "‧", "﹒", "．", NULL,
    "/", "／", "÷", "↗", "↙", "∕", NULL,
    "0", "０", NULL,
    "1", "１", NULL,
    "2", "２", NULL,
    "3", "３", NULL,
    "4", "４", NULL,
    "5", "５", NULL,
    "6", "６", NULL,
    "7", "７", NULL,
    "8", "８", NULL,
    "9", "９", NULL,
    ":", "：", "︰", "﹕", NULL,
    ";", "；", "﹔", NULL,
    "<", "＜", "〈", "《", "︽", "︿", "﹤", NULL,
    "=", "＝", "≒", "≠", "≡", "≦", "≧", "﹦", NULL,
    ">", "＞", "〉", "》", "︾", "﹀", "﹥", NULL,
    "?", "？", "﹖", "⁇", "⁈", NULL,
    "@", "＠", "⊕", "⊙", "㊣", "﹫", "◉", "◎", NULL,
    "A", "Ａ", NULL,
    "B", "Ｂ", NULL,
    "C", "Ｃ", NULL,
    "D", "Ｄ", NULL,
    "E", "Ｅ", NULL,
    "F", "Ｆ", NULL,
    "G", "Ｇ", NULL,
    "H", "Ｈ", NULL,
    "I", "Ｉ", NULL,
    "J", "Ｊ", NULL,
    "K", "Ｋ", NULL,
    "L", "Ｌ", NULL,
    "M", "Ｍ", NULL,
    "N", "Ｎ", NULL,
    "O", "Ｏ", NULL,
    "P", "Ｐ", NULL,
    "Q", "Ｑ", NULL,
    "R", "Ｒ", NULL,
    "S", "Ｓ", NULL,
    "T", "Ｔ", NULL,
    "U", "Ｕ", NULL,
    "V", "Ｖ", NULL,
    "W", "Ｗ", NULL,
    "X", "Ｘ", NULL,
    "Y", "Ｙ", NULL,
    "Z", "Ｚ", NULL,
    "[", "「", "［", "『", "【", "｢", "︻", "﹁", "﹃", NULL,
    "'", "、", "‘", "’", NULL,
    "\\", "＼", "↖", "↘", "﹨", NULL,
    "]", "」", "］", "』", "】", "｣", "︼", "﹂", "﹄", NULL,
    "^", "︿", "〈", "《", "︽", "﹤", "＜", NULL,
    "_", "＿", "╴", "←", "→", NULL,
    "`", "‵", "′", NULL,
    "a", "ａ", NULL,
    "b", "ｂ", NULL,
    "c", "ｃ", NULL,
    "d", "ｄ", NULL,
    "e", "ｅ", NULL,
    "f", "ｆ", NULL,
    "g", "ｇ", NULL,
    "h", "ｈ", NULL,
    "i", "ｉ", NULL,
    "j", "ｊ", NULL,
    "k", "ｋ", NULL,
    "l", "ｌ", NULL,
    "m", "ｍ", NULL,
    "n", "ｎ", NULL,
    "o", "ｏ", NULL,
    "p", "ｐ", NULL,
    "q", "ｑ", NULL,
    "r", "ｒ", NULL,
    "s", "ｓ", NULL,
    "t", "ｔ", NULL,
    "u", "ｕ", NULL,
    "v", "ｖ", NULL,
    "w", "ｗ", NULL,
    "x", "ｘ", NULL,
    "y", "ｙ", NULL,
    "z", "ｚ", NULL,
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
    &puncts[47],    // "("
    &puncts[52],    // ")"
    &puncts[57],    // "*"
    &puncts[68],    // "+"
    &puncts[73],    // ","
    &puncts[79],    // "-"
    &puncts[91],    // "."
    &puncts[98],    // "/"
    &puncts[105],    // "0"
    &puncts[108],    // "1"
    &puncts[111],    // "2"
    &puncts[114],    // "3"
    &puncts[117],    // "4"
    &puncts[120],    // "5"
    &puncts[123],    // "6"
    &puncts[126],    // "7"
    &puncts[129],    // "8"
    &puncts[132],    // "9"
    &puncts[135],    // ":"
    &puncts[140],    // ";"
    &puncts[144],    // "<"
    &puncts[152],    // "="
    &puncts[161],    // ">"
    &puncts[169],    // "?"
    &puncts[175],    // "@"
    &puncts[184],    // "A"
    &puncts[187],    // "B"
    &puncts[190],    // "C"
    &puncts[193],    // "D"
    &puncts[196],    // "E"
    &puncts[199],    // "F"
    &puncts[202],    // "G"
    &puncts[205],    // "H"
    &puncts[208],    // "I"
    &puncts[211],    // "J"
    &puncts[214],    // "K"
    &puncts[217],    // "L"
    &puncts[220],    // "M"
    &puncts[223],    // "N"
    &puncts[226],    // "O"
    &puncts[229],    // "P"
    &puncts[232],    // "Q"
    &puncts[235],    // "R"
    &puncts[238],    // "S"
    &puncts[241],    // "T"
    &puncts[244],    // "U"
    &puncts[247],    // "V"
    &puncts[250],    // "W"
    &puncts[253],    // "X"
    &puncts[256],    // "Y"
    &puncts[259],    // "Z"
    &puncts[262],    // "["
    &puncts[272],    // "'"
    &puncts[277],    // "\\"
    &puncts[283],    // "]"
    &puncts[293],    // "^"
    &puncts[301],    // "_"
    &puncts[307],    // "`"
    &puncts[311],    // "a"
    &puncts[314],    // "b"
    &puncts[317],    // "c"
    &puncts[320],    // "d"
    &puncts[323],    // "e"
    &puncts[326],    // "f"
    &puncts[329],    // "g"
    &puncts[332],    // "h"
    &puncts[335],    // "i"
    &puncts[338],    // "j"
    &puncts[341],    // "k"
    &puncts[344],    // "l"
    &puncts[347],    // "m"
    &puncts[350],    // "n"
    &puncts[353],    // "o"
    &puncts[356],    // "p"
    &puncts[359],    // "q"
    &puncts[362],    // "r"
    &puncts[365],    // "s"
    &puncts[368],    // "t"
    &puncts[371],    // "u"
    &puncts[374],    // "v"
    &puncts[377],    // "w"
    &puncts[380],    // "x"
    &puncts[383],    // "y"
    &puncts[386],    // "z"
    &puncts[389],    // "{"
    &puncts[397],    // "|"
    &puncts[408],    // "}"
    &puncts[416],    // "~"
};
