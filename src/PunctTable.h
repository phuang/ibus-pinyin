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
    &puncts[113],    // "1"
    &puncts[116],    // "2"
    &puncts[119],    // "3"
    &puncts[122],    // "4"
    &puncts[125],    // "5"
    &puncts[128],    // "6"
    &puncts[131],    // "7"
    &puncts[134],    // "8"
    &puncts[137],    // "9"
    &puncts[140],    // ":"
    &puncts[145],    // ";"
    &puncts[149],    // "<"
    &puncts[157],    // "="
    &puncts[166],    // ">"
    &puncts[174],    // "?"
    &puncts[180],    // "@"
    &puncts[189],    // "A"
    &puncts[192],    // "B"
    &puncts[195],    // "C"
    &puncts[198],    // "D"
    &puncts[201],    // "E"
    &puncts[204],    // "F"
    &puncts[207],    // "G"
    &puncts[210],    // "H"
    &puncts[213],    // "I"
    &puncts[216],    // "J"
    &puncts[219],    // "K"
    &puncts[222],    // "L"
    &puncts[225],    // "M"
    &puncts[228],    // "N"
    &puncts[231],    // "O"
    &puncts[234],    // "P"
    &puncts[237],    // "Q"
    &puncts[240],    // "R"
    &puncts[243],    // "S"
    &puncts[246],    // "T"
    &puncts[249],    // "U"
    &puncts[252],    // "V"
    &puncts[255],    // "W"
    &puncts[258],    // "X"
    &puncts[261],    // "Y"
    &puncts[264],    // "Z"
    &puncts[267],    // "["
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
