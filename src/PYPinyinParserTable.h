static const Pinyin pinyin_table[] = {
    {  /* 0 */
        text        : "a",
        bopomofo    : L"ㄚ",
        sheng       : "",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_A }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : 0
    },
    {  /* 1 */
        text        : "agn",
        bopomofo    : L"",
        sheng       : "",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 2 */
        text        : "ai",
        bopomofo    : L"ㄞ",
        sheng       : "",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_AI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 3 */
        text        : "amg",
        bopomofo    : L"",
        sheng       : "",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 4 */
        text        : "an",
        bopomofo    : L"ㄢ",
        sheng       : "",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 5 */
        text        : "ang",
        bopomofo    : L"ㄤ",
        sheng       : "",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 6 */
        text        : "ao",
        bopomofo    : L"ㄠ",
        sheng       : "",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_AO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 7 */
        text        : "b",
        bopomofo    : L"ㄅ",
        sheng       : "b",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 8 */
        text        : "ba",
        bopomofo    : L"ㄅㄚ",
        sheng       : "b",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_A }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 9 */
        text        : "bagn",
        bopomofo    : L"",
        sheng       : "b",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 10 */
        text        : "bai",
        bopomofo    : L"ㄅㄞ",
        sheng       : "b",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_AI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 11 */
        text        : "bamg",
        bopomofo    : L"",
        sheng       : "b",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 12 */
        text        : "ban",
        bopomofo    : L"ㄅㄢ",
        sheng       : "b",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 13 */
        text        : "bang",
        bopomofo    : L"ㄅㄤ",
        sheng       : "b",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 14 */
        text        : "bao",
        bopomofo    : L"ㄅㄠ",
        sheng       : "b",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_AO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 15 */
        text        : "begn",
        bopomofo    : L"",
        sheng       : "b",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 16 */
        text        : "bei",
        bopomofo    : L"ㄅㄟ",
        sheng       : "b",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_EI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 17 */
        text        : "bemg",
        bopomofo    : L"",
        sheng       : "b",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 18 */
        text        : "ben",
        bopomofo    : L"ㄅㄣ",
        sheng       : "b",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 19 */
        text        : "beng",
        bopomofo    : L"ㄅㄥ",
        sheng       : "b",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 20 */
        text        : "bi",
        bopomofo    : L"ㄅㄧ",
        sheng       : "b",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_I }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 21 */
        text        : "bian",
        bopomofo    : L"ㄅㄧㄢ",
        sheng       : "b",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 22 */
        text        : "biang",
        bopomofo    : L"ㄅㄧㄤ",
        sheng       : "b",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_IANG_IAN
    },
    {  /* 23 */
        text        : "biao",
        bopomofo    : L"ㄅㄧㄠ",
        sheng       : "b",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_IAO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 24 */
        text        : "bie",
        bopomofo    : L"ㄅㄧㄝ",
        sheng       : "b",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_IE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 25 */
        text        : "bign",
        bopomofo    : L"",
        sheng       : "b",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 26 */
        text        : "bimg",
        bopomofo    : L"",
        sheng       : "b",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 27 */
        text        : "bin",
        bopomofo    : L"ㄅㄧㄣ",
        sheng       : "b",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 28 */
        text        : "bing",
        bopomofo    : L"ㄅㄧㄥ",
        sheng       : "b",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 29 */
        text        : "bo",
        bopomofo    : L"ㄅㄛ",
        sheng       : "b",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_O }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 30 */
        text        : "bu",
        bopomofo    : L"ㄅㄨ",
        sheng       : "b",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_B, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 31 */
        text        : "c",
        bopomofo    : L"",
        sheng       : "c",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 32 */
        text        : "ca",
        bopomofo    : L"ㄘㄚ",
        sheng       : "c",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_A }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 33 */
        text        : "cagn",
        bopomofo    : L"",
        sheng       : "c",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_ANG }, { PINYIN_ID_CH, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 34 */
        text        : "cai",
        bopomofo    : L"ㄘㄞ",
        sheng       : "c",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_AI }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 35 */
        text        : "camg",
        bopomofo    : L"",
        sheng       : "c",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_ANG }, { PINYIN_ID_CH, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 36 */
        text        : "can",
        bopomofo    : L"ㄘㄢ",
        sheng       : "c",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_AN }, { PINYIN_ID_CH, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 37 */
        text        : "cang",
        bopomofo    : L"ㄘㄤ",
        sheng       : "c",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_ANG }, { PINYIN_ID_CH, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 38 */
        text        : "cao",
        bopomofo    : L"ㄘㄠ",
        sheng       : "c",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_AO }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 39 */
        text        : "ce",
        bopomofo    : L"ㄘㄜ",
        sheng       : "c",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_E }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 40 */
        text        : "cegn",
        bopomofo    : L"",
        sheng       : "c",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_ENG }, { PINYIN_ID_CH, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 41 */
        text        : "cemg",
        bopomofo    : L"",
        sheng       : "c",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_ENG }, { PINYIN_ID_CH, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 42 */
        text        : "cen",
        bopomofo    : L"ㄘㄣ",
        sheng       : "c",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_EN }, { PINYIN_ID_CH, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 43 */
        text        : "ceng",
        bopomofo    : L"ㄘㄥ",
        sheng       : "c",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_ENG }, { PINYIN_ID_CH, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 44 */
        text        : "ch",
        bopomofo    : L"",
        sheng       : "ch",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 45 */
        text        : "cha",
        bopomofo    : L"ㄔㄚ",
        sheng       : "ch",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_A }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 46 */
        text        : "chagn",
        bopomofo    : L"",
        sheng       : "ch",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_ANG }, { PINYIN_ID_C, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 47 */
        text        : "chai",
        bopomofo    : L"ㄔㄞ",
        sheng       : "ch",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_AI }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 48 */
        text        : "chamg",
        bopomofo    : L"",
        sheng       : "ch",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_ANG }, { PINYIN_ID_C, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 49 */
        text        : "chan",
        bopomofo    : L"ㄔㄢ",
        sheng       : "ch",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_AN }, { PINYIN_ID_C, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 50 */
        text        : "chang",
        bopomofo    : L"ㄔㄤ",
        sheng       : "ch",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_ANG }, { PINYIN_ID_C, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 51 */
        text        : "chao",
        bopomofo    : L"ㄔㄠ",
        sheng       : "ch",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_AO }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 52 */
        text        : "che",
        bopomofo    : L"ㄔㄜ",
        sheng       : "ch",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_E }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 53 */
        text        : "chegn",
        bopomofo    : L"",
        sheng       : "ch",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_ENG }, { PINYIN_ID_C, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 54 */
        text        : "chemg",
        bopomofo    : L"",
        sheng       : "ch",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_ENG }, { PINYIN_ID_C, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 55 */
        text        : "chen",
        bopomofo    : L"ㄔㄣ",
        sheng       : "ch",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_EN }, { PINYIN_ID_C, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 56 */
        text        : "cheng",
        bopomofo    : L"ㄔㄥ",
        sheng       : "ch",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_ENG }, { PINYIN_ID_C, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 57 */
        text        : "chi",
        bopomofo    : L"ㄔ",
        sheng       : "ch",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_I }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 58 */
        text        : "chogn",
        bopomofo    : L"",
        sheng       : "ch",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_ONG }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 59 */
        text        : "chomg",
        bopomofo    : L"",
        sheng       : "ch",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_ONG }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 60 */
        text        : "chon",
        bopomofo    : L"",
        sheng       : "ch",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_ONG }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 61 */
        text        : "chong",
        bopomofo    : L"ㄔㄨㄥ",
        sheng       : "ch",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_ONG }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 62 */
        text        : "chou",
        bopomofo    : L"ㄔㄡ",
        sheng       : "ch",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_OU }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 63 */
        text        : "chu",
        bopomofo    : L"ㄔㄨ",
        sheng       : "ch",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_U }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 64 */
        text        : "chuagn",
        bopomofo    : L"",
        sheng       : "ch",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UANG }, { PINYIN_ID_C, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 65 */
        text        : "chuai",
        bopomofo    : L"ㄔㄨㄞ",
        sheng       : "ch",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UAI }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 66 */
        text        : "chuamg",
        bopomofo    : L"",
        sheng       : "ch",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UANG }, { PINYIN_ID_C, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 67 */
        text        : "chuan",
        bopomofo    : L"ㄔㄨㄢ",
        sheng       : "ch",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UAN }, { PINYIN_ID_C, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 68 */
        text        : "chuang",
        bopomofo    : L"ㄔㄨㄤ",
        sheng       : "ch",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UANG }, { PINYIN_ID_C, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : 0
    },
    {  /* 69 */
        text        : "chuei",
        bopomofo    : L"",
        sheng       : "ch",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UI }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 70 */
        text        : "chuen",
        bopomofo    : L"",
        sheng       : "ch",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UN }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 71 */
        text        : "chui",
        bopomofo    : L"ㄔㄨㄟ",
        sheng       : "ch",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UI }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 72 */
        text        : "chun",
        bopomofo    : L"ㄔㄨㄣ",
        sheng       : "ch",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UN }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 73 */
        text        : "chuo",
        bopomofo    : L"ㄔㄨㄛ",
        sheng       : "ch",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UO }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 74 */
        text        : "ci",
        bopomofo    : L"ㄘ",
        sheng       : "c",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_I }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 75 */
        text        : "cogn",
        bopomofo    : L"",
        sheng       : "c",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_ONG }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 76 */
        text        : "comg",
        bopomofo    : L"",
        sheng       : "c",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_ONG }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 77 */
        text        : "con",
        bopomofo    : L"",
        sheng       : "c",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_ONG }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 78 */
        text        : "cong",
        bopomofo    : L"ㄘㄨㄥ",
        sheng       : "c",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_ONG }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 79 */
        text        : "cou",
        bopomofo    : L"ㄘㄡ",
        sheng       : "c",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_OU }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 80 */
        text        : "cu",
        bopomofo    : L"ㄘㄨ",
        sheng       : "c",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_U }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 81 */
        text        : "cuai",
        bopomofo    : L"ㄘㄨㄞ",
        sheng       : "c",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_UAI }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_C_CH
    },
    {  /* 82 */
        text        : "cuan",
        bopomofo    : L"ㄘㄨㄢ",
        sheng       : "c",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_UAN }, { PINYIN_ID_CH, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 83 */
        text        : "cuang",
        bopomofo    : L"ㄘㄨㄤ",
        sheng       : "c",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_UANG }, { PINYIN_ID_CH, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_C_CH | PINYIN_FUZZY_UANG_UAN
    },
    {  /* 84 */
        text        : "cuei",
        bopomofo    : L"",
        sheng       : "c",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_UI }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 85 */
        text        : "cuen",
        bopomofo    : L"",
        sheng       : "c",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_UN }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 86 */
        text        : "cui",
        bopomofo    : L"ㄘㄨㄟ",
        sheng       : "c",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_UI }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 87 */
        text        : "cun",
        bopomofo    : L"ㄘㄨㄣ",
        sheng       : "c",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_UN }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 88 */
        text        : "cuo",
        bopomofo    : L"ㄘㄨㄛ",
        sheng       : "c",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_UO }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 89 */
        text        : "d",
        bopomofo    : L"ㄉ",
        sheng       : "d",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 90 */
        text        : "da",
        bopomofo    : L"ㄉㄚ",
        sheng       : "d",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_A }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 91 */
        text        : "dagn",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 92 */
        text        : "dai",
        bopomofo    : L"ㄉㄞ",
        sheng       : "d",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_AI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 93 */
        text        : "damg",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 94 */
        text        : "dan",
        bopomofo    : L"ㄉㄢ",
        sheng       : "d",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 95 */
        text        : "dang",
        bopomofo    : L"ㄉㄤ",
        sheng       : "d",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 96 */
        text        : "dao",
        bopomofo    : L"ㄉㄠ",
        sheng       : "d",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_AO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 97 */
        text        : "de",
        bopomofo    : L"ㄉㄜ",
        sheng       : "d",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_E }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 98 */
        text        : "degn",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 99 */
        text        : "dei",
        bopomofo    : L"ㄉㄟ",
        sheng       : "d",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_EI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 100 */
        text        : "demg",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 101 */
        text        : "den",
        bopomofo    : L"ㄉㄣ",
        sheng       : "d",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_EN_ENG
    },
    {  /* 102 */
        text        : "deng",
        bopomofo    : L"ㄉㄥ",
        sheng       : "d",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 103 */
        text        : "di",
        bopomofo    : L"ㄉㄧ",
        sheng       : "d",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_I }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 104 */
        text        : "dia",
        bopomofo    : L"ㄉㄧㄚ",
        sheng       : "d",
        yun         : "ia",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_IA }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 105 */
        text        : "dian",
        bopomofo    : L"ㄉㄧㄢ",
        sheng       : "d",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 106 */
        text        : "diang",
        bopomofo    : L"ㄉㄧㄤ",
        sheng       : "d",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_IANG_IAN
    },
    {  /* 107 */
        text        : "diao",
        bopomofo    : L"ㄉㄧㄠ",
        sheng       : "d",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_IAO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 108 */
        text        : "die",
        bopomofo    : L"ㄉㄧㄝ",
        sheng       : "d",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_IE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 109 */
        text        : "dign",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 110 */
        text        : "dimg",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 111 */
        text        : "din",
        bopomofo    : L"ㄉㄧㄣ",
        sheng       : "d",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_IN_ING
    },
    {  /* 112 */
        text        : "ding",
        bopomofo    : L"ㄉㄧㄥ",
        sheng       : "d",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 113 */
        text        : "diou",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_IOU_TO_IU
    },
    {  /* 114 */
        text        : "diu",
        bopomofo    : L"ㄉㄧㄡ",
        sheng       : "d",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 115 */
        text        : "dogn",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 116 */
        text        : "domg",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 117 */
        text        : "don",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 118 */
        text        : "dong",
        bopomofo    : L"ㄉㄨㄥ",
        sheng       : "d",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 119 */
        text        : "dou",
        bopomofo    : L"ㄉㄡ",
        sheng       : "d",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_OU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 120 */
        text        : "du",
        bopomofo    : L"ㄉㄨ",
        sheng       : "d",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 121 */
        text        : "duan",
        bopomofo    : L"ㄉㄨㄢ",
        sheng       : "d",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 122 */
        text        : "duang",
        bopomofo    : L"ㄉㄨㄤ",
        sheng       : "d",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 123 */
        text        : "duei",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_UI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 124 */
        text        : "duen",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 125 */
        text        : "dui",
        bopomofo    : L"ㄉㄨㄟ",
        sheng       : "d",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_UI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 126 */
        text        : "dun",
        bopomofo    : L"ㄉㄨㄣ",
        sheng       : "d",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 127 */
        text        : "duo",
        bopomofo    : L"ㄉㄨㄛ",
        sheng       : "d",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_UO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 128 */
        text        : "e",
        bopomofo    : L"ㄜ",
        sheng       : "",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_E }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : 0
    },
    {  /* 129 */
        text        : "ei",
        bopomofo    : L"ㄟ",
        sheng       : "",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_EI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 130 */
        text        : "en",
        bopomofo    : L"ㄣ",
        sheng       : "",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 131 */
        text        : "er",
        bopomofo    : L"ㄦ",
        sheng       : "",
        yun         : "er",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_ER }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 132 */
        text        : "f",
        bopomofo    : L"ㄈ",
        sheng       : "f",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 133 */
        text        : "fa",
        bopomofo    : L"ㄈㄚ",
        sheng       : "f",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_A }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 134 */
        text        : "fagn",
        bopomofo    : L"",
        sheng       : "f",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_ANG }, { PINYIN_ID_H, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 135 */
        text        : "fai",
        bopomofo    : L"ㄈㄞ",
        sheng       : "f",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_AI }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 136 */
        text        : "famg",
        bopomofo    : L"",
        sheng       : "f",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_ANG }, { PINYIN_ID_H, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 137 */
        text        : "fan",
        bopomofo    : L"ㄈㄢ",
        sheng       : "f",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_AN }, { PINYIN_ID_H, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 138 */
        text        : "fang",
        bopomofo    : L"ㄈㄤ",
        sheng       : "f",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_ANG }, { PINYIN_ID_H, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 139 */
        text        : "fao",
        bopomofo    : L"ㄈㄠ",
        sheng       : "f",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_AO }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 140 */
        text        : "fe",
        bopomofo    : L"ㄈㄜ",
        sheng       : "f",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_E }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 141 */
        text        : "fegn",
        bopomofo    : L"",
        sheng       : "f",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_ENG }, { PINYIN_ID_H, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 142 */
        text        : "fei",
        bopomofo    : L"ㄈㄟ",
        sheng       : "f",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_EI }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 143 */
        text        : "femg",
        bopomofo    : L"",
        sheng       : "f",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_ENG }, { PINYIN_ID_H, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 144 */
        text        : "fen",
        bopomofo    : L"ㄈㄣ",
        sheng       : "f",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_EN }, { PINYIN_ID_H, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 145 */
        text        : "feng",
        bopomofo    : L"ㄈㄥ",
        sheng       : "f",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_ENG }, { PINYIN_ID_H, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 146 */
        text        : "fo",
        bopomofo    : L"ㄈㄛ",
        sheng       : "f",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_O }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 147 */
        text        : "fon",
        bopomofo    : L"",
        sheng       : "f",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_ONG }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_F_H | PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 148 */
        text        : "fong",
        bopomofo    : L"ㄈㄨㄥ",
        sheng       : "f",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_ONG }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 149 */
        text        : "fou",
        bopomofo    : L"ㄈㄡ",
        sheng       : "f",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_OU }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 150 */
        text        : "fu",
        bopomofo    : L"ㄈㄨ",
        sheng       : "f",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_U }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 151 */
        text        : "fua",
        bopomofo    : L"ㄈㄨㄚ",
        sheng       : "f",
        yun         : "ua",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UA }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 152 */
        text        : "fuai",
        bopomofo    : L"ㄈㄨㄞ",
        sheng       : "f",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UAI }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 153 */
        text        : "fuan",
        bopomofo    : L"ㄈㄨㄢ",
        sheng       : "f",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UAN }, { PINYIN_ID_H, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 154 */
        text        : "fuang",
        bopomofo    : L"ㄈㄨㄤ",
        sheng       : "f",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UANG }, { PINYIN_ID_H, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 155 */
        text        : "fuei",
        bopomofo    : L"",
        sheng       : "f",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UI }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_F_H | PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 156 */
        text        : "fuen",
        bopomofo    : L"",
        sheng       : "f",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UN }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_F_H | PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 157 */
        text        : "fui",
        bopomofo    : L"ㄈㄨㄟ",
        sheng       : "f",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UI }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 158 */
        text        : "fun",
        bopomofo    : L"ㄈㄨㄣ",
        sheng       : "f",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UN }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 159 */
        text        : "fuo",
        bopomofo    : L"ㄈㄨㄛ",
        sheng       : "f",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UO }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 160 */
        text        : "g",
        bopomofo    : L"ㄍ",
        sheng       : "g",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 161 */
        text        : "ga",
        bopomofo    : L"ㄍㄚ",
        sheng       : "g",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_A }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 162 */
        text        : "gagn",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ANG }, { PINYIN_ID_K, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 163 */
        text        : "gai",
        bopomofo    : L"ㄍㄞ",
        sheng       : "g",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_AI }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 164 */
        text        : "gamg",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ANG }, { PINYIN_ID_K, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 165 */
        text        : "gan",
        bopomofo    : L"ㄍㄢ",
        sheng       : "g",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_AN }, { PINYIN_ID_K, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 166 */
        text        : "gang",
        bopomofo    : L"ㄍㄤ",
        sheng       : "g",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ANG }, { PINYIN_ID_K, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 167 */
        text        : "gao",
        bopomofo    : L"ㄍㄠ",
        sheng       : "g",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_AO }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 168 */
        text        : "ge",
        bopomofo    : L"ㄍㄜ",
        sheng       : "g",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_E }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 169 */
        text        : "gegn",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ENG }, { PINYIN_ID_K, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 170 */
        text        : "gei",
        bopomofo    : L"ㄍㄟ",
        sheng       : "g",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_EI }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 171 */
        text        : "gemg",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ENG }, { PINYIN_ID_K, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 172 */
        text        : "gen",
        bopomofo    : L"ㄍㄣ",
        sheng       : "g",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_EN }, { PINYIN_ID_K, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 173 */
        text        : "geng",
        bopomofo    : L"ㄍㄥ",
        sheng       : "g",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ENG }, { PINYIN_ID_K, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 174 */
        text        : "gogn",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ONG }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 175 */
        text        : "gomg",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ONG }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 176 */
        text        : "gon",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ONG }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 177 */
        text        : "gong",
        bopomofo    : L"ㄍㄨㄥ",
        sheng       : "g",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ONG }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 178 */
        text        : "gou",
        bopomofo    : L"ㄍㄡ",
        sheng       : "g",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_OU }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 179 */
        text        : "gu",
        bopomofo    : L"ㄍㄨ",
        sheng       : "g",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_U }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 180 */
        text        : "gua",
        bopomofo    : L"ㄍㄨㄚ",
        sheng       : "g",
        yun         : "ua",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UA }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 181 */
        text        : "guagn",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UANG }, { PINYIN_ID_K, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 182 */
        text        : "guai",
        bopomofo    : L"ㄍㄨㄞ",
        sheng       : "g",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UAI }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 183 */
        text        : "guamg",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UANG }, { PINYIN_ID_K, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 184 */
        text        : "guan",
        bopomofo    : L"ㄍㄨㄢ",
        sheng       : "g",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UAN }, { PINYIN_ID_K, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 185 */
        text        : "guang",
        bopomofo    : L"ㄍㄨㄤ",
        sheng       : "g",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UANG }, { PINYIN_ID_K, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 186 */
        text        : "guei",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UI }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 187 */
        text        : "guen",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UN }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 188 */
        text        : "gui",
        bopomofo    : L"ㄍㄨㄟ",
        sheng       : "g",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UI }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 189 */
        text        : "gun",
        bopomofo    : L"ㄍㄨㄣ",
        sheng       : "g",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UN }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 190 */
        text        : "guo",
        bopomofo    : L"ㄍㄨㄛ",
        sheng       : "g",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UO }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 191 */
        text        : "h",
        bopomofo    : L"ㄏ",
        sheng       : "h",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 192 */
        text        : "ha",
        bopomofo    : L"ㄏㄚ",
        sheng       : "h",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_A }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 193 */
        text        : "hagn",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ANG }, { PINYIN_ID_F, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 194 */
        text        : "hai",
        bopomofo    : L"ㄏㄞ",
        sheng       : "h",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_AI }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 195 */
        text        : "hamg",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ANG }, { PINYIN_ID_F, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 196 */
        text        : "han",
        bopomofo    : L"ㄏㄢ",
        sheng       : "h",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_AN }, { PINYIN_ID_F, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 197 */
        text        : "hang",
        bopomofo    : L"ㄏㄤ",
        sheng       : "h",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ANG }, { PINYIN_ID_F, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 198 */
        text        : "hao",
        bopomofo    : L"ㄏㄠ",
        sheng       : "h",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_AO }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 199 */
        text        : "he",
        bopomofo    : L"ㄏㄜ",
        sheng       : "h",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_E }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 200 */
        text        : "hegn",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ENG }, { PINYIN_ID_F, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 201 */
        text        : "hei",
        bopomofo    : L"ㄏㄟ",
        sheng       : "h",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_EI }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 202 */
        text        : "hemg",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ENG }, { PINYIN_ID_F, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 203 */
        text        : "hen",
        bopomofo    : L"ㄏㄣ",
        sheng       : "h",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_EN }, { PINYIN_ID_F, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 204 */
        text        : "heng",
        bopomofo    : L"ㄏㄥ",
        sheng       : "h",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ENG }, { PINYIN_ID_F, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 205 */
        text        : "ho",
        bopomofo    : L"ㄏㄛ",
        sheng       : "h",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_O }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_FUZZY_H_F
    },
    {  /* 206 */
        text        : "hogn",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ONG }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 207 */
        text        : "homg",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ONG }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 208 */
        text        : "hon",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ONG }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 209 */
        text        : "hong",
        bopomofo    : L"ㄏㄨㄥ",
        sheng       : "h",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ONG }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 210 */
        text        : "hou",
        bopomofo    : L"ㄏㄡ",
        sheng       : "h",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_OU }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 211 */
        text        : "hu",
        bopomofo    : L"ㄏㄨ",
        sheng       : "h",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_U }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 212 */
        text        : "hua",
        bopomofo    : L"ㄏㄨㄚ",
        sheng       : "h",
        yun         : "ua",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UA }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 213 */
        text        : "huagn",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UANG }, { PINYIN_ID_F, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 214 */
        text        : "huai",
        bopomofo    : L"ㄏㄨㄞ",
        sheng       : "h",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UAI }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 215 */
        text        : "huamg",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UANG }, { PINYIN_ID_F, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 216 */
        text        : "huan",
        bopomofo    : L"ㄏㄨㄢ",
        sheng       : "h",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UAN }, { PINYIN_ID_F, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 217 */
        text        : "huang",
        bopomofo    : L"ㄏㄨㄤ",
        sheng       : "h",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UANG }, { PINYIN_ID_F, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 218 */
        text        : "huei",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UI }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 219 */
        text        : "huen",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UN }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 220 */
        text        : "hui",
        bopomofo    : L"ㄏㄨㄟ",
        sheng       : "h",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UI }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 221 */
        text        : "hun",
        bopomofo    : L"ㄏㄨㄣ",
        sheng       : "h",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UN }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 222 */
        text        : "huo",
        bopomofo    : L"ㄏㄨㄛ",
        sheng       : "h",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UO }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 223 */
        text        : "j",
        bopomofo    : L"ㄐ",
        sheng       : "j",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 224 */
        text        : "ji",
        bopomofo    : L"ㄐㄧ",
        sheng       : "j",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_I }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 225 */
        text        : "jia",
        bopomofo    : L"ㄐㄧㄚ",
        sheng       : "j",
        yun         : "ia",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IA }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 226 */
        text        : "jiagn",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 227 */
        text        : "jiamg",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 228 */
        text        : "jian",
        bopomofo    : L"ㄐㄧㄢ",
        sheng       : "j",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 229 */
        text        : "jiang",
        bopomofo    : L"ㄐㄧㄤ",
        sheng       : "j",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 230 */
        text        : "jiao",
        bopomofo    : L"ㄐㄧㄠ",
        sheng       : "j",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IAO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 231 */
        text        : "jie",
        bopomofo    : L"ㄐㄧㄝ",
        sheng       : "j",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 232 */
        text        : "jign",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 233 */
        text        : "jimg",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 234 */
        text        : "jin",
        bopomofo    : L"ㄐㄧㄣ",
        sheng       : "j",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 235 */
        text        : "jing",
        bopomofo    : L"ㄐㄧㄥ",
        sheng       : "j",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 236 */
        text        : "jiogn",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 237 */
        text        : "jiomg",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 238 */
        text        : "jion",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 239 */
        text        : "jiong",
        bopomofo    : L"ㄐㄩㄥ",
        sheng       : "j",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 240 */
        text        : "jiou",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_IOU_TO_IU
    },
    {  /* 241 */
        text        : "jiu",
        bopomofo    : L"ㄐㄧㄡ",
        sheng       : "j",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 242 */
        text        : "ju",
        bopomofo    : L"ㄐㄩ",
        sheng       : "j",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 243 */
        text        : "juan",
        bopomofo    : L"ㄐㄩㄢ",
        sheng       : "j",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 244 */
        text        : "juang",
        bopomofo    : L"ㄐㄩㄤ",
        sheng       : "j",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 245 */
        text        : "jue",
        bopomofo    : L"ㄐㄩㄝ",
        sheng       : "j",
        yun         : "ue",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 246 */
        text        : "juen",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 247 */
        text        : "jun",
        bopomofo    : L"ㄐㄩㄣ",
        sheng       : "j",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 248 */
        text        : "jv",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 249 */
        text        : "jvan",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 250 */
        text        : "jvang",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN | PINYIN_CORRECT_V_TO_U
    },
    {  /* 251 */
        text        : "jve",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "ue",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 252 */
        text        : "jven",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN | PINYIN_CORRECT_V_TO_U
    },
    {  /* 253 */
        text        : "jvn",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 254 */
        text        : "k",
        bopomofo    : L"ㄎ",
        sheng       : "k",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 255 */
        text        : "ka",
        bopomofo    : L"ㄎㄚ",
        sheng       : "k",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_A }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 256 */
        text        : "kagn",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ANG }, { PINYIN_ID_G, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 257 */
        text        : "kai",
        bopomofo    : L"ㄎㄞ",
        sheng       : "k",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_AI }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 258 */
        text        : "kamg",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ANG }, { PINYIN_ID_G, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 259 */
        text        : "kan",
        bopomofo    : L"ㄎㄢ",
        sheng       : "k",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_AN }, { PINYIN_ID_G, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 260 */
        text        : "kang",
        bopomofo    : L"ㄎㄤ",
        sheng       : "k",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ANG }, { PINYIN_ID_G, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 261 */
        text        : "kao",
        bopomofo    : L"ㄎㄠ",
        sheng       : "k",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_AO }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 262 */
        text        : "ke",
        bopomofo    : L"ㄎㄜ",
        sheng       : "k",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_E }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 263 */
        text        : "kegn",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ENG }, { PINYIN_ID_G, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 264 */
        text        : "kei",
        bopomofo    : L"ㄎㄟ",
        sheng       : "k",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_EI }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_K_G
    },
    {  /* 265 */
        text        : "kemg",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ENG }, { PINYIN_ID_G, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 266 */
        text        : "ken",
        bopomofo    : L"ㄎㄣ",
        sheng       : "k",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_EN }, { PINYIN_ID_G, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 267 */
        text        : "keng",
        bopomofo    : L"ㄎㄥ",
        sheng       : "k",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ENG }, { PINYIN_ID_G, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 268 */
        text        : "kogn",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ONG }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 269 */
        text        : "komg",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ONG }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 270 */
        text        : "kon",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ONG }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 271 */
        text        : "kong",
        bopomofo    : L"ㄎㄨㄥ",
        sheng       : "k",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ONG }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 272 */
        text        : "kou",
        bopomofo    : L"ㄎㄡ",
        sheng       : "k",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_OU }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 273 */
        text        : "ku",
        bopomofo    : L"ㄎㄨ",
        sheng       : "k",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_U }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 274 */
        text        : "kua",
        bopomofo    : L"ㄎㄨㄚ",
        sheng       : "k",
        yun         : "ua",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UA }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 275 */
        text        : "kuagn",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UANG }, { PINYIN_ID_G, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 276 */
        text        : "kuai",
        bopomofo    : L"ㄎㄨㄞ",
        sheng       : "k",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UAI }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 277 */
        text        : "kuamg",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UANG }, { PINYIN_ID_G, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 278 */
        text        : "kuan",
        bopomofo    : L"ㄎㄨㄢ",
        sheng       : "k",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UAN }, { PINYIN_ID_G, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 279 */
        text        : "kuang",
        bopomofo    : L"ㄎㄨㄤ",
        sheng       : "k",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UANG }, { PINYIN_ID_G, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 280 */
        text        : "kuei",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UI }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 281 */
        text        : "kuen",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UN }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 282 */
        text        : "kui",
        bopomofo    : L"ㄎㄨㄟ",
        sheng       : "k",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UI }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 283 */
        text        : "kun",
        bopomofo    : L"ㄎㄨㄣ",
        sheng       : "k",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UN }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 284 */
        text        : "kuo",
        bopomofo    : L"ㄎㄨㄛ",
        sheng       : "k",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UO }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 285 */
        text        : "l",
        bopomofo    : L"ㄌ",
        sheng       : "l",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 286 */
        text        : "la",
        bopomofo    : L"ㄌㄚ",
        sheng       : "l",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_A }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 287 */
        text        : "lagn",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ANG }, { PINYIN_ID_N, PINYIN_ID_AN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 288 */
        text        : "lai",
        bopomofo    : L"ㄌㄞ",
        sheng       : "l",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_AI }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 289 */
        text        : "lamg",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ANG }, { PINYIN_ID_N, PINYIN_ID_AN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 290 */
        text        : "lan",
        bopomofo    : L"ㄌㄢ",
        sheng       : "l",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_AN }, { PINYIN_ID_N, PINYIN_ID_ANG }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 291 */
        text        : "lang",
        bopomofo    : L"ㄌㄤ",
        sheng       : "l",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ANG }, { PINYIN_ID_N, PINYIN_ID_AN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 292 */
        text        : "lao",
        bopomofo    : L"ㄌㄠ",
        sheng       : "l",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_AO }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 293 */
        text        : "le",
        bopomofo    : L"ㄌㄜ",
        sheng       : "l",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_E }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 294 */
        text        : "legn",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ENG }, { PINYIN_ID_N, PINYIN_ID_EN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 295 */
        text        : "lei",
        bopomofo    : L"ㄌㄟ",
        sheng       : "l",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_EI }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 296 */
        text        : "lemg",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ENG }, { PINYIN_ID_N, PINYIN_ID_EN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 297 */
        text        : "len",
        bopomofo    : L"ㄌㄣ",
        sheng       : "l",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_EN }, { PINYIN_ID_N, PINYIN_ID_ENG }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_L_N | PINYIN_FUZZY_L_R | PINYIN_FUZZY_EN_ENG
    },
    {  /* 298 */
        text        : "leng",
        bopomofo    : L"ㄌㄥ",
        sheng       : "l",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ENG }, { PINYIN_ID_N, PINYIN_ID_EN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 299 */
        text        : "li",
        bopomofo    : L"ㄌㄧ",
        sheng       : "l",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_I }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 300 */
        text        : "lia",
        bopomofo    : L"ㄌㄧㄚ",
        sheng       : "l",
        yun         : "ia",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IA }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 301 */
        text        : "liagn",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IANG }, { PINYIN_ID_N, PINYIN_ID_IAN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 302 */
        text        : "liamg",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IANG }, { PINYIN_ID_N, PINYIN_ID_IAN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 303 */
        text        : "lian",
        bopomofo    : L"ㄌㄧㄢ",
        sheng       : "l",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IAN }, { PINYIN_ID_N, PINYIN_ID_IANG }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 304 */
        text        : "liang",
        bopomofo    : L"ㄌㄧㄤ",
        sheng       : "l",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IANG }, { PINYIN_ID_N, PINYIN_ID_IAN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 305 */
        text        : "liao",
        bopomofo    : L"ㄌㄧㄠ",
        sheng       : "l",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IAO }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 306 */
        text        : "lie",
        bopomofo    : L"ㄌㄧㄝ",
        sheng       : "l",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IE }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 307 */
        text        : "lign",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ING }, { PINYIN_ID_N, PINYIN_ID_IN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 308 */
        text        : "limg",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ING }, { PINYIN_ID_N, PINYIN_ID_IN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 309 */
        text        : "lin",
        bopomofo    : L"ㄌㄧㄣ",
        sheng       : "l",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IN }, { PINYIN_ID_N, PINYIN_ID_ING }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 310 */
        text        : "ling",
        bopomofo    : L"ㄌㄧㄥ",
        sheng       : "l",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ING }, { PINYIN_ID_N, PINYIN_ID_IN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 311 */
        text        : "liou",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IU }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_IOU_TO_IU
    },
    {  /* 312 */
        text        : "liu",
        bopomofo    : L"ㄌㄧㄡ",
        sheng       : "l",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IU }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 313 */
        text        : "lo",
        bopomofo    : L"ㄌㄛ",
        sheng       : "l",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_O }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 314 */
        text        : "logn",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ONG }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 315 */
        text        : "lomg",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ONG }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 316 */
        text        : "lon",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ONG }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 317 */
        text        : "long",
        bopomofo    : L"ㄌㄨㄥ",
        sheng       : "l",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ONG }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 318 */
        text        : "lou",
        bopomofo    : L"ㄌㄡ",
        sheng       : "l",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_OU }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 319 */
        text        : "lu",
        bopomofo    : L"ㄌㄨ",
        sheng       : "l",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_U }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 320 */
        text        : "luan",
        bopomofo    : L"ㄌㄨㄢ",
        sheng       : "l",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_UAN }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 321 */
        text        : "luang",
        bopomofo    : L"ㄌㄨㄤ",
        sheng       : "l",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_UANG }, { PINYIN_ID_N, PINYIN_ID_UAN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 322 */
        text        : "lue",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "üe",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_VE }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_UE_TO_VE
    },
    {  /* 323 */
        text        : "luei",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_UI }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_L_R | PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 324 */
        text        : "luen",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_UN }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 325 */
        text        : "lui",
        bopomofo    : L"ㄌㄨㄟ",
        sheng       : "l",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_UI }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_L_R
    },
    {  /* 326 */
        text        : "lun",
        bopomofo    : L"ㄌㄨㄣ",
        sheng       : "l",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_UN }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 327 */
        text        : "luo",
        bopomofo    : L"ㄌㄨㄛ",
        sheng       : "l",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_UO }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 328 */
        text        : "lv",
        bopomofo    : L"ㄌㄩ",
        sheng       : "l",
        yun         : "ü",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_V }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 329 */
        text        : "lve",
        bopomofo    : L"ㄌㄩㄝ",
        sheng       : "l",
        yun         : "üe",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_VE }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 330 */
        text        : "m",
        bopomofo    : L"ㄇ",
        sheng       : "m",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 331 */
        text        : "ma",
        bopomofo    : L"ㄇㄚ",
        sheng       : "m",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_A }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 332 */
        text        : "magn",
        bopomofo    : L"",
        sheng       : "m",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 333 */
        text        : "mai",
        bopomofo    : L"ㄇㄞ",
        sheng       : "m",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_AI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 334 */
        text        : "mamg",
        bopomofo    : L"",
        sheng       : "m",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 335 */
        text        : "man",
        bopomofo    : L"ㄇㄢ",
        sheng       : "m",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 336 */
        text        : "mang",
        bopomofo    : L"ㄇㄤ",
        sheng       : "m",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 337 */
        text        : "mao",
        bopomofo    : L"ㄇㄠ",
        sheng       : "m",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_AO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 338 */
        text        : "me",
        bopomofo    : L"ㄇㄜ",
        sheng       : "m",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_E }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 339 */
        text        : "megn",
        bopomofo    : L"",
        sheng       : "m",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 340 */
        text        : "mei",
        bopomofo    : L"ㄇㄟ",
        sheng       : "m",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_EI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 341 */
        text        : "memg",
        bopomofo    : L"",
        sheng       : "m",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 342 */
        text        : "men",
        bopomofo    : L"ㄇㄣ",
        sheng       : "m",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 343 */
        text        : "meng",
        bopomofo    : L"ㄇㄥ",
        sheng       : "m",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 344 */
        text        : "mi",
        bopomofo    : L"ㄇㄧ",
        sheng       : "m",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_I }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 345 */
        text        : "mian",
        bopomofo    : L"ㄇㄧㄢ",
        sheng       : "m",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 346 */
        text        : "miang",
        bopomofo    : L"ㄇㄧㄤ",
        sheng       : "m",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_IANG_IAN
    },
    {  /* 347 */
        text        : "miao",
        bopomofo    : L"ㄇㄧㄠ",
        sheng       : "m",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_IAO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 348 */
        text        : "mie",
        bopomofo    : L"ㄇㄧㄝ",
        sheng       : "m",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_IE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 349 */
        text        : "mign",
        bopomofo    : L"",
        sheng       : "m",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 350 */
        text        : "mimg",
        bopomofo    : L"",
        sheng       : "m",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 351 */
        text        : "min",
        bopomofo    : L"ㄇㄧㄣ",
        sheng       : "m",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 352 */
        text        : "ming",
        bopomofo    : L"ㄇㄧㄥ",
        sheng       : "m",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 353 */
        text        : "miou",
        bopomofo    : L"",
        sheng       : "m",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_IOU_TO_IU
    },
    {  /* 354 */
        text        : "miu",
        bopomofo    : L"ㄇㄧㄡ",
        sheng       : "m",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 355 */
        text        : "mo",
        bopomofo    : L"ㄇㄛ",
        sheng       : "m",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_O }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 356 */
        text        : "mou",
        bopomofo    : L"ㄇㄡ",
        sheng       : "m",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_OU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 357 */
        text        : "mu",
        bopomofo    : L"ㄇㄨ",
        sheng       : "m",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 358 */
        text        : "n",
        bopomofo    : L"ㄋ",
        sheng       : "n",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 359 */
        text        : "na",
        bopomofo    : L"ㄋㄚ",
        sheng       : "n",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_A }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 360 */
        text        : "nagn",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ANG }, { PINYIN_ID_L, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 361 */
        text        : "nai",
        bopomofo    : L"ㄋㄞ",
        sheng       : "n",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_AI }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 362 */
        text        : "namg",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ANG }, { PINYIN_ID_L, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 363 */
        text        : "nan",
        bopomofo    : L"ㄋㄢ",
        sheng       : "n",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_AN }, { PINYIN_ID_L, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 364 */
        text        : "nang",
        bopomofo    : L"ㄋㄤ",
        sheng       : "n",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ANG }, { PINYIN_ID_L, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 365 */
        text        : "nao",
        bopomofo    : L"ㄋㄠ",
        sheng       : "n",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_AO }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 366 */
        text        : "ne",
        bopomofo    : L"ㄋㄜ",
        sheng       : "n",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_E }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 367 */
        text        : "negn",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ENG }, { PINYIN_ID_L, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 368 */
        text        : "nei",
        bopomofo    : L"ㄋㄟ",
        sheng       : "n",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_EI }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 369 */
        text        : "nemg",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ENG }, { PINYIN_ID_L, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 370 */
        text        : "nen",
        bopomofo    : L"ㄋㄣ",
        sheng       : "n",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_EN }, { PINYIN_ID_L, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 371 */
        text        : "neng",
        bopomofo    : L"ㄋㄥ",
        sheng       : "n",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ENG }, { PINYIN_ID_L, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 372 */
        text        : "ni",
        bopomofo    : L"ㄋㄧ",
        sheng       : "n",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_I }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 373 */
        text        : "nia",
        bopomofo    : L"ㄋㄧㄚ",
        sheng       : "n",
        yun         : "ia",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IA }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_N_L
    },
    {  /* 374 */
        text        : "niagn",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IANG }, { PINYIN_ID_L, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 375 */
        text        : "niamg",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IANG }, { PINYIN_ID_L, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 376 */
        text        : "nian",
        bopomofo    : L"ㄋㄧㄢ",
        sheng       : "n",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IAN }, { PINYIN_ID_L, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 377 */
        text        : "niang",
        bopomofo    : L"ㄋㄧㄤ",
        sheng       : "n",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IANG }, { PINYIN_ID_L, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 378 */
        text        : "niao",
        bopomofo    : L"ㄋㄧㄠ",
        sheng       : "n",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IAO }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 379 */
        text        : "nie",
        bopomofo    : L"ㄋㄧㄝ",
        sheng       : "n",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IE }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 380 */
        text        : "nign",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ING }, { PINYIN_ID_L, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 381 */
        text        : "nimg",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ING }, { PINYIN_ID_L, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 382 */
        text        : "nin",
        bopomofo    : L"ㄋㄧㄣ",
        sheng       : "n",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IN }, { PINYIN_ID_L, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 383 */
        text        : "ning",
        bopomofo    : L"ㄋㄧㄥ",
        sheng       : "n",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ING }, { PINYIN_ID_L, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 384 */
        text        : "niou",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IU }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_IOU_TO_IU
    },
    {  /* 385 */
        text        : "niu",
        bopomofo    : L"ㄋㄧㄡ",
        sheng       : "n",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IU }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 386 */
        text        : "no",
        bopomofo    : L"ㄋㄛ",
        sheng       : "n",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_O }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_FUZZY_N_L
    },
    {  /* 387 */
        text        : "nogn",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ONG }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 388 */
        text        : "nomg",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ONG }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 389 */
        text        : "non",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ONG }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 390 */
        text        : "nong",
        bopomofo    : L"ㄋㄨㄥ",
        sheng       : "n",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ONG }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 391 */
        text        : "nou",
        bopomofo    : L"ㄋㄡ",
        sheng       : "n",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_OU }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 392 */
        text        : "nu",
        bopomofo    : L"ㄋㄨ",
        sheng       : "n",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_U }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 393 */
        text        : "nuan",
        bopomofo    : L"ㄋㄨㄢ",
        sheng       : "n",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_UAN }, { PINYIN_ID_L, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 394 */
        text        : "nuang",
        bopomofo    : L"ㄋㄨㄤ",
        sheng       : "n",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_UANG }, { PINYIN_ID_L, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 395 */
        text        : "nue",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "üe",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_VE }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_UE_TO_VE
    },
    {  /* 396 */
        text        : "nuen",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_UN }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_N_L | PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 397 */
        text        : "nun",
        bopomofo    : L"ㄋㄨㄣ",
        sheng       : "n",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_UN }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_N_L
    },
    {  /* 398 */
        text        : "nuo",
        bopomofo    : L"ㄋㄨㄛ",
        sheng       : "n",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_UO }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 399 */
        text        : "nv",
        bopomofo    : L"ㄋㄩ",
        sheng       : "n",
        yun         : "ü",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_V }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 400 */
        text        : "nve",
        bopomofo    : L"ㄋㄩㄝ",
        sheng       : "n",
        yun         : "üe",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_VE }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 401 */
        text        : "o",
        bopomofo    : L"ㄛ",
        sheng       : "",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_O }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : 0
    },
    {  /* 402 */
        text        : "ou",
        bopomofo    : L"ㄡ",
        sheng       : "",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_OU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 403 */
        text        : "p",
        bopomofo    : L"ㄆ",
        sheng       : "p",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 404 */
        text        : "pa",
        bopomofo    : L"ㄆㄚ",
        sheng       : "p",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_A }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 405 */
        text        : "pagn",
        bopomofo    : L"",
        sheng       : "p",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 406 */
        text        : "pai",
        bopomofo    : L"ㄆㄞ",
        sheng       : "p",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_AI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 407 */
        text        : "pamg",
        bopomofo    : L"",
        sheng       : "p",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 408 */
        text        : "pan",
        bopomofo    : L"ㄆㄢ",
        sheng       : "p",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 409 */
        text        : "pang",
        bopomofo    : L"ㄆㄤ",
        sheng       : "p",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 410 */
        text        : "pao",
        bopomofo    : L"ㄆㄠ",
        sheng       : "p",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_AO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 411 */
        text        : "pegn",
        bopomofo    : L"",
        sheng       : "p",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 412 */
        text        : "pei",
        bopomofo    : L"ㄆㄟ",
        sheng       : "p",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_EI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 413 */
        text        : "pemg",
        bopomofo    : L"",
        sheng       : "p",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 414 */
        text        : "pen",
        bopomofo    : L"ㄆㄣ",
        sheng       : "p",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 415 */
        text        : "peng",
        bopomofo    : L"ㄆㄥ",
        sheng       : "p",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 416 */
        text        : "pi",
        bopomofo    : L"ㄆㄧ",
        sheng       : "p",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_I }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 417 */
        text        : "pian",
        bopomofo    : L"ㄆㄧㄢ",
        sheng       : "p",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 418 */
        text        : "piang",
        bopomofo    : L"ㄆㄧㄤ",
        sheng       : "p",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_IANG_IAN
    },
    {  /* 419 */
        text        : "piao",
        bopomofo    : L"ㄆㄧㄠ",
        sheng       : "p",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_IAO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 420 */
        text        : "pie",
        bopomofo    : L"ㄆㄧㄝ",
        sheng       : "p",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_IE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 421 */
        text        : "pign",
        bopomofo    : L"",
        sheng       : "p",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 422 */
        text        : "pimg",
        bopomofo    : L"",
        sheng       : "p",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 423 */
        text        : "pin",
        bopomofo    : L"ㄆㄧㄣ",
        sheng       : "p",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 424 */
        text        : "ping",
        bopomofo    : L"ㄆㄧㄥ",
        sheng       : "p",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 425 */
        text        : "po",
        bopomofo    : L"ㄆㄛ",
        sheng       : "p",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_O }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 426 */
        text        : "pou",
        bopomofo    : L"ㄆㄡ",
        sheng       : "p",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_OU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 427 */
        text        : "pu",
        bopomofo    : L"ㄆㄨ",
        sheng       : "p",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 428 */
        text        : "q",
        bopomofo    : L"ㄑ",
        sheng       : "q",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 429 */
        text        : "qi",
        bopomofo    : L"ㄑㄧ",
        sheng       : "q",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_I }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 430 */
        text        : "qia",
        bopomofo    : L"ㄑㄧㄚ",
        sheng       : "q",
        yun         : "ia",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IA }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 431 */
        text        : "qiagn",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 432 */
        text        : "qiamg",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 433 */
        text        : "qian",
        bopomofo    : L"ㄑㄧㄢ",
        sheng       : "q",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 434 */
        text        : "qiang",
        bopomofo    : L"ㄑㄧㄤ",
        sheng       : "q",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 435 */
        text        : "qiao",
        bopomofo    : L"ㄑㄧㄠ",
        sheng       : "q",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IAO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 436 */
        text        : "qie",
        bopomofo    : L"ㄑㄧㄝ",
        sheng       : "q",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 437 */
        text        : "qign",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 438 */
        text        : "qimg",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 439 */
        text        : "qin",
        bopomofo    : L"ㄑㄧㄣ",
        sheng       : "q",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 440 */
        text        : "qing",
        bopomofo    : L"ㄑㄧㄥ",
        sheng       : "q",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 441 */
        text        : "qiogn",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 442 */
        text        : "qiomg",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 443 */
        text        : "qion",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 444 */
        text        : "qiong",
        bopomofo    : L"ㄑㄩㄥ",
        sheng       : "q",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 445 */
        text        : "qiou",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_IOU_TO_IU
    },
    {  /* 446 */
        text        : "qiu",
        bopomofo    : L"ㄑㄧㄡ",
        sheng       : "q",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 447 */
        text        : "qu",
        bopomofo    : L"ㄑㄩ",
        sheng       : "q",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 448 */
        text        : "quan",
        bopomofo    : L"ㄑㄩㄢ",
        sheng       : "q",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 449 */
        text        : "quang",
        bopomofo    : L"ㄑㄩㄤ",
        sheng       : "q",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 450 */
        text        : "que",
        bopomofo    : L"ㄑㄩㄝ",
        sheng       : "q",
        yun         : "ue",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 451 */
        text        : "quen",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 452 */
        text        : "qun",
        bopomofo    : L"ㄑㄩㄣ",
        sheng       : "q",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 453 */
        text        : "qv",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 454 */
        text        : "qvan",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 455 */
        text        : "qvang",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN | PINYIN_CORRECT_V_TO_U
    },
    {  /* 456 */
        text        : "qve",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "ue",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 457 */
        text        : "qven",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN | PINYIN_CORRECT_V_TO_U
    },
    {  /* 458 */
        text        : "qvn",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 459 */
        text        : "r",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ZERO }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 460 */
        text        : "ra",
        bopomofo    : L"ㄖㄚ",
        sheng       : "r",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_A }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 461 */
        text        : "ragn",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ANG }, { PINYIN_ID_L, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 462 */
        text        : "rai",
        bopomofo    : L"ㄖㄞ",
        sheng       : "r",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_AI }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 463 */
        text        : "ramg",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ANG }, { PINYIN_ID_L, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 464 */
        text        : "ran",
        bopomofo    : L"ㄖㄢ",
        sheng       : "r",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_AN }, { PINYIN_ID_L, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 465 */
        text        : "rang",
        bopomofo    : L"ㄖㄤ",
        sheng       : "r",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ANG }, { PINYIN_ID_L, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 466 */
        text        : "rao",
        bopomofo    : L"ㄖㄠ",
        sheng       : "r",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_AO }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 467 */
        text        : "re",
        bopomofo    : L"ㄖㄜ",
        sheng       : "r",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_E }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 468 */
        text        : "regn",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ENG }, { PINYIN_ID_L, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 469 */
        text        : "rei",
        bopomofo    : L"ㄖㄟ",
        sheng       : "r",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_EI }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 470 */
        text        : "remg",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ENG }, { PINYIN_ID_L, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 471 */
        text        : "ren",
        bopomofo    : L"ㄖㄣ",
        sheng       : "r",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_EN }, { PINYIN_ID_L, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 472 */
        text        : "reng",
        bopomofo    : L"ㄖㄥ",
        sheng       : "r",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ENG }, { PINYIN_ID_L, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 473 */
        text        : "ri",
        bopomofo    : L"ㄖ",
        sheng       : "r",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_I }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 474 */
        text        : "ria",
        bopomofo    : L"ㄖㄧㄚ",
        sheng       : "r",
        yun         : "ia",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_IA }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 475 */
        text        : "rian",
        bopomofo    : L"ㄖㄧㄢ",
        sheng       : "r",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_IAN }, { PINYIN_ID_L, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 476 */
        text        : "riang",
        bopomofo    : L"ㄖㄧㄤ",
        sheng       : "r",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_IANG }, { PINYIN_ID_L, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 477 */
        text        : "riao",
        bopomofo    : L"ㄖㄧㄠ",
        sheng       : "r",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_IAO }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 478 */
        text        : "rie",
        bopomofo    : L"ㄖㄧㄝ",
        sheng       : "r",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_IE }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 479 */
        text        : "rin",
        bopomofo    : L"ㄖㄧㄣ",
        sheng       : "r",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_IN }, { PINYIN_ID_L, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 480 */
        text        : "ring",
        bopomofo    : L"ㄖㄧㄥ",
        sheng       : "r",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ING }, { PINYIN_ID_L, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 481 */
        text        : "riou",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_IU }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_R_L | PINYIN_CORRECT_IOU_TO_IU
    },
    {  /* 482 */
        text        : "riu",
        bopomofo    : L"ㄖㄧㄡ",
        sheng       : "r",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_IU }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 483 */
        text        : "ro",
        bopomofo    : L"ㄖㄛ",
        sheng       : "r",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_O }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 484 */
        text        : "rogn",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ONG }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 485 */
        text        : "romg",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ONG }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 486 */
        text        : "ron",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ONG }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 487 */
        text        : "rong",
        bopomofo    : L"ㄖㄨㄥ",
        sheng       : "r",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ONG }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 488 */
        text        : "rou",
        bopomofo    : L"ㄖㄡ",
        sheng       : "r",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_OU }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 489 */
        text        : "ru",
        bopomofo    : L"ㄖㄨ",
        sheng       : "r",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_U }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 490 */
        text        : "ruan",
        bopomofo    : L"ㄖㄨㄢ",
        sheng       : "r",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_UAN }, { PINYIN_ID_L, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 491 */
        text        : "ruang",
        bopomofo    : L"ㄖㄨㄤ",
        sheng       : "r",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_UANG }, { PINYIN_ID_L, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 492 */
        text        : "rue",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "üe",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_VE }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_R_L | PINYIN_CORRECT_UE_TO_VE
    },
    {  /* 493 */
        text        : "ruei",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_UI }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 494 */
        text        : "ruen",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_UN }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 495 */
        text        : "rui",
        bopomofo    : L"ㄖㄨㄟ",
        sheng       : "r",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_UI }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 496 */
        text        : "run",
        bopomofo    : L"ㄖㄨㄣ",
        sheng       : "r",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_UN }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 497 */
        text        : "ruo",
        bopomofo    : L"ㄖㄨㄛ",
        sheng       : "r",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_UO }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 498 */
        text        : "rv",
        bopomofo    : L"ㄖㄩ",
        sheng       : "r",
        yun         : "ü",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_V }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 499 */
        text        : "rve",
        bopomofo    : L"ㄖㄩㄝ",
        sheng       : "r",
        yun         : "üe",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_VE }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 500 */
        text        : "s",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 501 */
        text        : "sa",
        bopomofo    : L"ㄙㄚ",
        sheng       : "s",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_A }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 502 */
        text        : "sagn",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ANG }, { PINYIN_ID_SH, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 503 */
        text        : "sai",
        bopomofo    : L"ㄙㄞ",
        sheng       : "s",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_AI }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 504 */
        text        : "samg",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ANG }, { PINYIN_ID_SH, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 505 */
        text        : "san",
        bopomofo    : L"ㄙㄢ",
        sheng       : "s",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_AN }, { PINYIN_ID_SH, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 506 */
        text        : "sang",
        bopomofo    : L"ㄙㄤ",
        sheng       : "s",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ANG }, { PINYIN_ID_SH, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 507 */
        text        : "sao",
        bopomofo    : L"ㄙㄠ",
        sheng       : "s",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_AO }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 508 */
        text        : "se",
        bopomofo    : L"ㄙㄜ",
        sheng       : "s",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_E }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 509 */
        text        : "segn",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ENG }, { PINYIN_ID_SH, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 510 */
        text        : "sei",
        bopomofo    : L"ㄙㄟ",
        sheng       : "s",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_EI }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_S_SH
    },
    {  /* 511 */
        text        : "semg",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ENG }, { PINYIN_ID_SH, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 512 */
        text        : "sen",
        bopomofo    : L"ㄙㄣ",
        sheng       : "s",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_EN }, { PINYIN_ID_SH, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 513 */
        text        : "seng",
        bopomofo    : L"ㄙㄥ",
        sheng       : "s",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ENG }, { PINYIN_ID_SH, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 514 */
        text        : "sh",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 515 */
        text        : "sha",
        bopomofo    : L"ㄕㄚ",
        sheng       : "sh",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_A }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 516 */
        text        : "shagn",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_ANG }, { PINYIN_ID_S, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 517 */
        text        : "shai",
        bopomofo    : L"ㄕㄞ",
        sheng       : "sh",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_AI }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 518 */
        text        : "shamg",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_ANG }, { PINYIN_ID_S, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 519 */
        text        : "shan",
        bopomofo    : L"ㄕㄢ",
        sheng       : "sh",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_AN }, { PINYIN_ID_S, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 520 */
        text        : "shang",
        bopomofo    : L"ㄕㄤ",
        sheng       : "sh",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_ANG }, { PINYIN_ID_S, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 521 */
        text        : "shao",
        bopomofo    : L"ㄕㄠ",
        sheng       : "sh",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_AO }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 522 */
        text        : "she",
        bopomofo    : L"ㄕㄜ",
        sheng       : "sh",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_E }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 523 */
        text        : "shegn",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_ENG }, { PINYIN_ID_S, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 524 */
        text        : "shei",
        bopomofo    : L"ㄕㄟ",
        sheng       : "sh",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_EI }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 525 */
        text        : "shemg",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_ENG }, { PINYIN_ID_S, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 526 */
        text        : "shen",
        bopomofo    : L"ㄕㄣ",
        sheng       : "sh",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_EN }, { PINYIN_ID_S, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 527 */
        text        : "sheng",
        bopomofo    : L"ㄕㄥ",
        sheng       : "sh",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_ENG }, { PINYIN_ID_S, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 528 */
        text        : "shi",
        bopomofo    : L"ㄕ",
        sheng       : "sh",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_I }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 529 */
        text        : "shon",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_ONG }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_SH_S | PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 530 */
        text        : "shong",
        bopomofo    : L"ㄕㄨㄥ",
        sheng       : "sh",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_ONG }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_SH_S
    },
    {  /* 531 */
        text        : "shou",
        bopomofo    : L"ㄕㄡ",
        sheng       : "sh",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_OU }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 532 */
        text        : "shu",
        bopomofo    : L"ㄕㄨ",
        sheng       : "sh",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_U }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 533 */
        text        : "shua",
        bopomofo    : L"ㄕㄨㄚ",
        sheng       : "sh",
        yun         : "ua",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UA }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 534 */
        text        : "shuagn",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UANG }, { PINYIN_ID_S, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 535 */
        text        : "shuai",
        bopomofo    : L"ㄕㄨㄞ",
        sheng       : "sh",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UAI }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 536 */
        text        : "shuamg",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UANG }, { PINYIN_ID_S, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 537 */
        text        : "shuan",
        bopomofo    : L"ㄕㄨㄢ",
        sheng       : "sh",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UAN }, { PINYIN_ID_S, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 538 */
        text        : "shuang",
        bopomofo    : L"ㄕㄨㄤ",
        sheng       : "sh",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UANG }, { PINYIN_ID_S, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : 0
    },
    {  /* 539 */
        text        : "shuei",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UI }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 540 */
        text        : "shuen",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UN }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 541 */
        text        : "shui",
        bopomofo    : L"ㄕㄨㄟ",
        sheng       : "sh",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UI }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 542 */
        text        : "shun",
        bopomofo    : L"ㄕㄨㄣ",
        sheng       : "sh",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UN }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 543 */
        text        : "shuo",
        bopomofo    : L"ㄕㄨㄛ",
        sheng       : "sh",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UO }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 544 */
        text        : "si",
        bopomofo    : L"ㄙ",
        sheng       : "s",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_I }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 545 */
        text        : "sogn",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ONG }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 546 */
        text        : "somg",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ONG }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 547 */
        text        : "son",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ONG }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 548 */
        text        : "song",
        bopomofo    : L"ㄙㄨㄥ",
        sheng       : "s",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ONG }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 549 */
        text        : "sou",
        bopomofo    : L"ㄙㄡ",
        sheng       : "s",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_OU }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 550 */
        text        : "su",
        bopomofo    : L"ㄙㄨ",
        sheng       : "s",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_U }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 551 */
        text        : "sua",
        bopomofo    : L"ㄙㄨㄚ",
        sheng       : "s",
        yun         : "ua",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UA }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_S_SH
    },
    {  /* 552 */
        text        : "suai",
        bopomofo    : L"ㄙㄨㄞ",
        sheng       : "s",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UAI }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_S_SH
    },
    {  /* 553 */
        text        : "suan",
        bopomofo    : L"ㄙㄨㄢ",
        sheng       : "s",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UAN }, { PINYIN_ID_SH, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 554 */
        text        : "suang",
        bopomofo    : L"ㄙㄨㄤ",
        sheng       : "s",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UANG }, { PINYIN_ID_SH, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_S_SH | PINYIN_FUZZY_UANG_UAN
    },
    {  /* 555 */
        text        : "suei",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UI }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 556 */
        text        : "suen",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UN }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 557 */
        text        : "sui",
        bopomofo    : L"ㄙㄨㄟ",
        sheng       : "s",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UI }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 558 */
        text        : "sun",
        bopomofo    : L"ㄙㄨㄣ",
        sheng       : "s",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UN }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 559 */
        text        : "suo",
        bopomofo    : L"ㄙㄨㄛ",
        sheng       : "s",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UO }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 560 */
        text        : "t",
        bopomofo    : L"ㄊ",
        sheng       : "t",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 561 */
        text        : "ta",
        bopomofo    : L"ㄊㄚ",
        sheng       : "t",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_A }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 562 */
        text        : "tagn",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 563 */
        text        : "tai",
        bopomofo    : L"ㄊㄞ",
        sheng       : "t",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_AI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 564 */
        text        : "tamg",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 565 */
        text        : "tan",
        bopomofo    : L"ㄊㄢ",
        sheng       : "t",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 566 */
        text        : "tang",
        bopomofo    : L"ㄊㄤ",
        sheng       : "t",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 567 */
        text        : "tao",
        bopomofo    : L"ㄊㄠ",
        sheng       : "t",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_AO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 568 */
        text        : "te",
        bopomofo    : L"ㄊㄜ",
        sheng       : "t",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_E }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 569 */
        text        : "tegn",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 570 */
        text        : "temg",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 571 */
        text        : "ten",
        bopomofo    : L"ㄊㄣ",
        sheng       : "t",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_EN_ENG
    },
    {  /* 572 */
        text        : "teng",
        bopomofo    : L"ㄊㄥ",
        sheng       : "t",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 573 */
        text        : "ti",
        bopomofo    : L"ㄊㄧ",
        sheng       : "t",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_I }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 574 */
        text        : "tian",
        bopomofo    : L"ㄊㄧㄢ",
        sheng       : "t",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 575 */
        text        : "tiang",
        bopomofo    : L"ㄊㄧㄤ",
        sheng       : "t",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_IANG_IAN
    },
    {  /* 576 */
        text        : "tiao",
        bopomofo    : L"ㄊㄧㄠ",
        sheng       : "t",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_IAO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 577 */
        text        : "tie",
        bopomofo    : L"ㄊㄧㄝ",
        sheng       : "t",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_IE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 578 */
        text        : "tign",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 579 */
        text        : "timg",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 580 */
        text        : "tin",
        bopomofo    : L"ㄊㄧㄣ",
        sheng       : "t",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_IN_ING
    },
    {  /* 581 */
        text        : "ting",
        bopomofo    : L"ㄊㄧㄥ",
        sheng       : "t",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 582 */
        text        : "togn",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 583 */
        text        : "tomg",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 584 */
        text        : "ton",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 585 */
        text        : "tong",
        bopomofo    : L"ㄊㄨㄥ",
        sheng       : "t",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 586 */
        text        : "tou",
        bopomofo    : L"ㄊㄡ",
        sheng       : "t",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_OU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 587 */
        text        : "tu",
        bopomofo    : L"ㄊㄨ",
        sheng       : "t",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 588 */
        text        : "tuan",
        bopomofo    : L"ㄊㄨㄢ",
        sheng       : "t",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 589 */
        text        : "tuang",
        bopomofo    : L"ㄊㄨㄤ",
        sheng       : "t",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 590 */
        text        : "tuei",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_UI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 591 */
        text        : "tuen",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 592 */
        text        : "tui",
        bopomofo    : L"ㄊㄨㄟ",
        sheng       : "t",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_UI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 593 */
        text        : "tun",
        bopomofo    : L"ㄊㄨㄣ",
        sheng       : "t",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 594 */
        text        : "tuo",
        bopomofo    : L"ㄊㄨㄛ",
        sheng       : "t",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_UO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 595 */
        text        : "w",
        bopomofo    : L"",
        sheng       : "w",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 596 */
        text        : "wa",
        bopomofo    : L"ㄨㄚ",
        sheng       : "w",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_A }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 597 */
        text        : "wagn",
        bopomofo    : L"",
        sheng       : "w",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 598 */
        text        : "wai",
        bopomofo    : L"ㄨㄞ",
        sheng       : "w",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_AI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 599 */
        text        : "wamg",
        bopomofo    : L"",
        sheng       : "w",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 600 */
        text        : "wan",
        bopomofo    : L"ㄨㄢ",
        sheng       : "w",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 601 */
        text        : "wang",
        bopomofo    : L"ㄨㄤ",
        sheng       : "w",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 602 */
        text        : "wegn",
        bopomofo    : L"",
        sheng       : "w",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 603 */
        text        : "wei",
        bopomofo    : L"ㄨㄟ",
        sheng       : "w",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_EI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 604 */
        text        : "wemg",
        bopomofo    : L"",
        sheng       : "w",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 605 */
        text        : "wen",
        bopomofo    : L"ㄨㄣ",
        sheng       : "w",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 606 */
        text        : "weng",
        bopomofo    : L"ㄨㄥ",
        sheng       : "w",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 607 */
        text        : "wo",
        bopomofo    : L"ㄨㄛ",
        sheng       : "w",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_O }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 608 */
        text        : "wu",
        bopomofo    : L"ㄨ",
        sheng       : "w",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 609 */
        text        : "x",
        bopomofo    : L"ㄒ",
        sheng       : "x",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 610 */
        text        : "xi",
        bopomofo    : L"ㄒㄧ",
        sheng       : "x",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_I }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 611 */
        text        : "xia",
        bopomofo    : L"ㄒㄧㄚ",
        sheng       : "x",
        yun         : "ia",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IA }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 612 */
        text        : "xiagn",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 613 */
        text        : "xiamg",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 614 */
        text        : "xian",
        bopomofo    : L"ㄒㄧㄢ",
        sheng       : "x",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 615 */
        text        : "xiang",
        bopomofo    : L"ㄒㄧㄤ",
        sheng       : "x",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 616 */
        text        : "xiao",
        bopomofo    : L"ㄒㄧㄠ",
        sheng       : "x",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IAO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 617 */
        text        : "xie",
        bopomofo    : L"ㄒㄧㄝ",
        sheng       : "x",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 618 */
        text        : "xign",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 619 */
        text        : "ximg",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 620 */
        text        : "xin",
        bopomofo    : L"ㄒㄧㄣ",
        sheng       : "x",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 621 */
        text        : "xing",
        bopomofo    : L"ㄒㄧㄥ",
        sheng       : "x",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 622 */
        text        : "xiogn",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 623 */
        text        : "xiomg",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 624 */
        text        : "xion",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 625 */
        text        : "xiong",
        bopomofo    : L"ㄒㄩㄥ",
        sheng       : "x",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 626 */
        text        : "xiou",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_IOU_TO_IU
    },
    {  /* 627 */
        text        : "xiu",
        bopomofo    : L"ㄒㄧㄡ",
        sheng       : "x",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 628 */
        text        : "xu",
        bopomofo    : L"ㄒㄩ",
        sheng       : "x",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 629 */
        text        : "xuan",
        bopomofo    : L"ㄒㄩㄢ",
        sheng       : "x",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 630 */
        text        : "xuang",
        bopomofo    : L"ㄒㄩㄤ",
        sheng       : "x",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 631 */
        text        : "xue",
        bopomofo    : L"ㄒㄩㄝ",
        sheng       : "x",
        yun         : "ue",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 632 */
        text        : "xuen",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 633 */
        text        : "xun",
        bopomofo    : L"ㄒㄩㄣ",
        sheng       : "x",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 634 */
        text        : "xv",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 635 */
        text        : "xvan",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 636 */
        text        : "xvang",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN | PINYIN_CORRECT_V_TO_U
    },
    {  /* 637 */
        text        : "xve",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "ue",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 638 */
        text        : "xven",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN | PINYIN_CORRECT_V_TO_U
    },
    {  /* 639 */
        text        : "xvn",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 640 */
        text        : "y",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 641 */
        text        : "ya",
        bopomofo    : L"ㄧㄚ",
        sheng       : "y",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_A }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 642 */
        text        : "yagn",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 643 */
        text        : "yamg",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 644 */
        text        : "yan",
        bopomofo    : L"ㄧㄢ",
        sheng       : "y",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 645 */
        text        : "yang",
        bopomofo    : L"ㄧㄤ",
        sheng       : "y",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 646 */
        text        : "yao",
        bopomofo    : L"ㄧㄠ",
        sheng       : "y",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_AO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 647 */
        text        : "ye",
        bopomofo    : L"ㄧㄝ",
        sheng       : "y",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_E }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 648 */
        text        : "yi",
        bopomofo    : L"ㄧ",
        sheng       : "y",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_I }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 649 */
        text        : "yign",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 650 */
        text        : "yimg",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 651 */
        text        : "yin",
        bopomofo    : L"ㄧㄣ",
        sheng       : "y",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 652 */
        text        : "ying",
        bopomofo    : L"ㄧㄥ",
        sheng       : "y",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 653 */
        text        : "yo",
        bopomofo    : L"ㄧㄛ",
        sheng       : "y",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_O }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 654 */
        text        : "yogn",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 655 */
        text        : "yomg",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 656 */
        text        : "yon",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 657 */
        text        : "yong",
        bopomofo    : L"ㄩㄥ",
        sheng       : "y",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 658 */
        text        : "you",
        bopomofo    : L"ㄧㄡ",
        sheng       : "y",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_OU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 659 */
        text        : "yu",
        bopomofo    : L"ㄩ",
        sheng       : "y",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 660 */
        text        : "yuan",
        bopomofo    : L"ㄩㄢ",
        sheng       : "y",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 661 */
        text        : "yuang",
        bopomofo    : L"ㄧㄩㄤ",
        sheng       : "y",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 662 */
        text        : "yue",
        bopomofo    : L"ㄩㄝ",
        sheng       : "y",
        yun         : "ue",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 663 */
        text        : "yuen",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 664 */
        text        : "yun",
        bopomofo    : L"ㄩㄣ",
        sheng       : "y",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 665 */
        text        : "yv",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 666 */
        text        : "yvan",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 667 */
        text        : "yvang",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN | PINYIN_CORRECT_V_TO_U
    },
    {  /* 668 */
        text        : "yve",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "ue",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 669 */
        text        : "yven",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN | PINYIN_CORRECT_V_TO_U
    },
    {  /* 670 */
        text        : "yvn",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 671 */
        text        : "z",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 672 */
        text        : "za",
        bopomofo    : L"ㄗㄚ",
        sheng       : "z",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_A }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 673 */
        text        : "zagn",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ANG }, { PINYIN_ID_ZH, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 674 */
        text        : "zai",
        bopomofo    : L"ㄗㄞ",
        sheng       : "z",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_AI }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 675 */
        text        : "zamg",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ANG }, { PINYIN_ID_ZH, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 676 */
        text        : "zan",
        bopomofo    : L"ㄗㄢ",
        sheng       : "z",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_AN }, { PINYIN_ID_ZH, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 677 */
        text        : "zang",
        bopomofo    : L"ㄗㄤ",
        sheng       : "z",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ANG }, { PINYIN_ID_ZH, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 678 */
        text        : "zao",
        bopomofo    : L"ㄗㄠ",
        sheng       : "z",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_AO }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 679 */
        text        : "ze",
        bopomofo    : L"ㄗㄜ",
        sheng       : "z",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_E }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 680 */
        text        : "zegn",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ENG }, { PINYIN_ID_ZH, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 681 */
        text        : "zei",
        bopomofo    : L"ㄗㄟ",
        sheng       : "z",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_EI }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 682 */
        text        : "zemg",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ENG }, { PINYIN_ID_ZH, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 683 */
        text        : "zen",
        bopomofo    : L"ㄗㄣ",
        sheng       : "z",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_EN }, { PINYIN_ID_ZH, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 684 */
        text        : "zeng",
        bopomofo    : L"ㄗㄥ",
        sheng       : "z",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ENG }, { PINYIN_ID_ZH, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 685 */
        text        : "zh",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 686 */
        text        : "zha",
        bopomofo    : L"ㄓㄚ",
        sheng       : "zh",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_A }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 687 */
        text        : "zhagn",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ANG }, { PINYIN_ID_Z, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 688 */
        text        : "zhai",
        bopomofo    : L"ㄓㄞ",
        sheng       : "zh",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_AI }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 689 */
        text        : "zhamg",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ANG }, { PINYIN_ID_Z, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 690 */
        text        : "zhan",
        bopomofo    : L"ㄓㄢ",
        sheng       : "zh",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_AN }, { PINYIN_ID_Z, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 691 */
        text        : "zhang",
        bopomofo    : L"ㄓㄤ",
        sheng       : "zh",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ANG }, { PINYIN_ID_Z, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 692 */
        text        : "zhao",
        bopomofo    : L"ㄓㄠ",
        sheng       : "zh",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_AO }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 693 */
        text        : "zhe",
        bopomofo    : L"ㄓㄜ",
        sheng       : "zh",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_E }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 694 */
        text        : "zhegn",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ENG }, { PINYIN_ID_Z, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 695 */
        text        : "zhei",
        bopomofo    : L"ㄓㄟ",
        sheng       : "zh",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_EI }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_ZH_Z
    },
    {  /* 696 */
        text        : "zhemg",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ENG }, { PINYIN_ID_Z, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 697 */
        text        : "zhen",
        bopomofo    : L"ㄓㄣ",
        sheng       : "zh",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_EN }, { PINYIN_ID_Z, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 698 */
        text        : "zheng",
        bopomofo    : L"ㄓㄥ",
        sheng       : "zh",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ENG }, { PINYIN_ID_Z, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 699 */
        text        : "zhi",
        bopomofo    : L"ㄓ",
        sheng       : "zh",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_I }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 700 */
        text        : "zhogn",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ONG }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 701 */
        text        : "zhomg",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ONG }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 702 */
        text        : "zhon",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ONG }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 703 */
        text        : "zhong",
        bopomofo    : L"ㄓㄨㄥ",
        sheng       : "zh",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ONG }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 704 */
        text        : "zhou",
        bopomofo    : L"ㄓㄡ",
        sheng       : "zh",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_OU }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 705 */
        text        : "zhu",
        bopomofo    : L"ㄓㄨ",
        sheng       : "zh",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_U }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 706 */
        text        : "zhua",
        bopomofo    : L"ㄓㄨㄚ",
        sheng       : "zh",
        yun         : "ua",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UA }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 707 */
        text        : "zhuagn",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UANG }, { PINYIN_ID_Z, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 708 */
        text        : "zhuai",
        bopomofo    : L"ㄓㄨㄞ",
        sheng       : "zh",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UAI }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 709 */
        text        : "zhuamg",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UANG }, { PINYIN_ID_Z, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 710 */
        text        : "zhuan",
        bopomofo    : L"ㄓㄨㄢ",
        sheng       : "zh",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UAN }, { PINYIN_ID_Z, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 711 */
        text        : "zhuang",
        bopomofo    : L"ㄓㄨㄤ",
        sheng       : "zh",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UANG }, { PINYIN_ID_Z, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : 0
    },
    {  /* 712 */
        text        : "zhuei",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UI }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 713 */
        text        : "zhuen",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UN }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 714 */
        text        : "zhui",
        bopomofo    : L"ㄓㄨㄟ",
        sheng       : "zh",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UI }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 715 */
        text        : "zhun",
        bopomofo    : L"ㄓㄨㄣ",
        sheng       : "zh",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UN }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 716 */
        text        : "zhuo",
        bopomofo    : L"ㄓㄨㄛ",
        sheng       : "zh",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UO }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 717 */
        text        : "zi",
        bopomofo    : L"ㄗ",
        sheng       : "z",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_I }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 718 */
        text        : "zogn",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ONG }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 719 */
        text        : "zomg",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ONG }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 720 */
        text        : "zon",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ONG }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_ON_TO_ONG
    },
    {  /* 721 */
        text        : "zong",
        bopomofo    : L"ㄗㄨㄥ",
        sheng       : "z",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ONG }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 722 */
        text        : "zou",
        bopomofo    : L"ㄗㄡ",
        sheng       : "z",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_OU }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 723 */
        text        : "zu",
        bopomofo    : L"ㄗㄨ",
        sheng       : "z",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_U }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 724 */
        text        : "zua",
        bopomofo    : L"ㄗㄨㄚ",
        sheng       : "z",
        yun         : "ua",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_UA }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_Z_ZH
    },
    {  /* 725 */
        text        : "zuai",
        bopomofo    : L"ㄗㄨㄞ",
        sheng       : "z",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_UAI }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_Z_ZH
    },
    {  /* 726 */
        text        : "zuan",
        bopomofo    : L"ㄗㄨㄢ",
        sheng       : "z",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_UAN }, { PINYIN_ID_ZH, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 727 */
        text        : "zuang",
        bopomofo    : L"ㄗㄨㄤ",
        sheng       : "z",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_UANG }, { PINYIN_ID_ZH, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_Z_ZH | PINYIN_FUZZY_UANG_UAN
    },
    {  /* 728 */
        text        : "zuei",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_UI }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 729 */
        text        : "zuen",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_UN }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 730 */
        text        : "zui",
        bopomofo    : L"ㄗㄨㄟ",
        sheng       : "z",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_UI }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 731 */
        text        : "zun",
        bopomofo    : L"ㄗㄨㄣ",
        sheng       : "z",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_UN }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 732 */
        text        : "zuo",
        bopomofo    : L"ㄗㄨㄛ",
        sheng       : "z",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_UO }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
};

static const Pinyin *bopomofo_table[] = {
    &pinyin_table[7],    // "ㄅ" => "b"
    &pinyin_table[8],    // "ㄅㄚ" => "ba"
    &pinyin_table[29],   // "ㄅㄛ" => "bo"
    &pinyin_table[10],   // "ㄅㄞ" => "bai"
    &pinyin_table[16],   // "ㄅㄟ" => "bei"
    &pinyin_table[14],   // "ㄅㄠ" => "bao"
    &pinyin_table[12],   // "ㄅㄢ" => "ban"
    &pinyin_table[18],   // "ㄅㄣ" => "ben"
    &pinyin_table[13],   // "ㄅㄤ" => "bang"
    &pinyin_table[19],   // "ㄅㄥ" => "beng"
    &pinyin_table[20],   // "ㄅㄧ" => "bi"
    &pinyin_table[24],   // "ㄅㄧㄝ" => "bie"
    &pinyin_table[23],   // "ㄅㄧㄠ" => "biao"
    &pinyin_table[21],   // "ㄅㄧㄢ" => "bian"
    &pinyin_table[27],   // "ㄅㄧㄣ" => "bin"
    &pinyin_table[22],   // "ㄅㄧㄤ" => "biang"
    &pinyin_table[28],   // "ㄅㄧㄥ" => "bing"
    &pinyin_table[30],   // "ㄅㄨ" => "bu"
    &pinyin_table[403],  // "ㄆ" => "p"
    &pinyin_table[404],  // "ㄆㄚ" => "pa"
    &pinyin_table[425],  // "ㄆㄛ" => "po"
    &pinyin_table[406],  // "ㄆㄞ" => "pai"
    &pinyin_table[412],  // "ㄆㄟ" => "pei"
    &pinyin_table[410],  // "ㄆㄠ" => "pao"
    &pinyin_table[426],  // "ㄆㄡ" => "pou"
    &pinyin_table[408],  // "ㄆㄢ" => "pan"
    &pinyin_table[414],  // "ㄆㄣ" => "pen"
    &pinyin_table[409],  // "ㄆㄤ" => "pang"
    &pinyin_table[415],  // "ㄆㄥ" => "peng"
    &pinyin_table[416],  // "ㄆㄧ" => "pi"
    &pinyin_table[420],  // "ㄆㄧㄝ" => "pie"
    &pinyin_table[419],  // "ㄆㄧㄠ" => "piao"
    &pinyin_table[417],  // "ㄆㄧㄢ" => "pian"
    &pinyin_table[423],  // "ㄆㄧㄣ" => "pin"
    &pinyin_table[418],  // "ㄆㄧㄤ" => "piang"
    &pinyin_table[424],  // "ㄆㄧㄥ" => "ping"
    &pinyin_table[427],  // "ㄆㄨ" => "pu"
    &pinyin_table[330],  // "ㄇ" => "m"
    &pinyin_table[331],  // "ㄇㄚ" => "ma"
    &pinyin_table[355],  // "ㄇㄛ" => "mo"
    &pinyin_table[338],  // "ㄇㄜ" => "me"
    &pinyin_table[333],  // "ㄇㄞ" => "mai"
    &pinyin_table[340],  // "ㄇㄟ" => "mei"
    &pinyin_table[337],  // "ㄇㄠ" => "mao"
    &pinyin_table[356],  // "ㄇㄡ" => "mou"
    &pinyin_table[335],  // "ㄇㄢ" => "man"
    &pinyin_table[342],  // "ㄇㄣ" => "men"
    &pinyin_table[336],  // "ㄇㄤ" => "mang"
    &pinyin_table[343],  // "ㄇㄥ" => "meng"
    &pinyin_table[344],  // "ㄇㄧ" => "mi"
    &pinyin_table[348],  // "ㄇㄧㄝ" => "mie"
    &pinyin_table[347],  // "ㄇㄧㄠ" => "miao"
    &pinyin_table[354],  // "ㄇㄧㄡ" => "miu"
    &pinyin_table[345],  // "ㄇㄧㄢ" => "mian"
    &pinyin_table[351],  // "ㄇㄧㄣ" => "min"
    &pinyin_table[346],  // "ㄇㄧㄤ" => "miang"
    &pinyin_table[352],  // "ㄇㄧㄥ" => "ming"
    &pinyin_table[357],  // "ㄇㄨ" => "mu"
    &pinyin_table[132],  // "ㄈ" => "f"
    &pinyin_table[133],  // "ㄈㄚ" => "fa"
    &pinyin_table[146],  // "ㄈㄛ" => "fo"
    &pinyin_table[140],  // "ㄈㄜ" => "fe"
    &pinyin_table[135],  // "ㄈㄞ" => "fai"
    &pinyin_table[142],  // "ㄈㄟ" => "fei"
    &pinyin_table[139],  // "ㄈㄠ" => "fao"
    &pinyin_table[149],  // "ㄈㄡ" => "fou"
    &pinyin_table[137],  // "ㄈㄢ" => "fan"
    &pinyin_table[144],  // "ㄈㄣ" => "fen"
    &pinyin_table[138],  // "ㄈㄤ" => "fang"
    &pinyin_table[145],  // "ㄈㄥ" => "feng"
    &pinyin_table[150],  // "ㄈㄨ" => "fu"
    &pinyin_table[151],  // "ㄈㄨㄚ" => "fua"
    &pinyin_table[159],  // "ㄈㄨㄛ" => "fuo"
    &pinyin_table[152],  // "ㄈㄨㄞ" => "fuai"
    &pinyin_table[157],  // "ㄈㄨㄟ" => "fui"
    &pinyin_table[153],  // "ㄈㄨㄢ" => "fuan"
    &pinyin_table[158],  // "ㄈㄨㄣ" => "fun"
    &pinyin_table[154],  // "ㄈㄨㄤ" => "fuang"
    &pinyin_table[148],  // "ㄈㄨㄥ" => "fong"
    &pinyin_table[89],   // "ㄉ" => "d"
    &pinyin_table[90],   // "ㄉㄚ" => "da"
    &pinyin_table[97],   // "ㄉㄜ" => "de"
    &pinyin_table[92],   // "ㄉㄞ" => "dai"
    &pinyin_table[99],   // "ㄉㄟ" => "dei"
    &pinyin_table[96],   // "ㄉㄠ" => "dao"
    &pinyin_table[119],  // "ㄉㄡ" => "dou"
    &pinyin_table[94],   // "ㄉㄢ" => "dan"
    &pinyin_table[101],  // "ㄉㄣ" => "den"
    &pinyin_table[95],   // "ㄉㄤ" => "dang"
    &pinyin_table[102],  // "ㄉㄥ" => "deng"
    &pinyin_table[103],  // "ㄉㄧ" => "di"
    &pinyin_table[104],  // "ㄉㄧㄚ" => "dia"
    &pinyin_table[108],  // "ㄉㄧㄝ" => "die"
    &pinyin_table[107],  // "ㄉㄧㄠ" => "diao"
    &pinyin_table[114],  // "ㄉㄧㄡ" => "diu"
    &pinyin_table[105],  // "ㄉㄧㄢ" => "dian"
    &pinyin_table[111],  // "ㄉㄧㄣ" => "din"
    &pinyin_table[106],  // "ㄉㄧㄤ" => "diang"
    &pinyin_table[112],  // "ㄉㄧㄥ" => "ding"
    &pinyin_table[120],  // "ㄉㄨ" => "du"
    &pinyin_table[127],  // "ㄉㄨㄛ" => "duo"
    &pinyin_table[125],  // "ㄉㄨㄟ" => "dui"
    &pinyin_table[121],  // "ㄉㄨㄢ" => "duan"
    &pinyin_table[126],  // "ㄉㄨㄣ" => "dun"
    &pinyin_table[122],  // "ㄉㄨㄤ" => "duang"
    &pinyin_table[118],  // "ㄉㄨㄥ" => "dong"
    &pinyin_table[560],  // "ㄊ" => "t"
    &pinyin_table[561],  // "ㄊㄚ" => "ta"
    &pinyin_table[568],  // "ㄊㄜ" => "te"
    &pinyin_table[563],  // "ㄊㄞ" => "tai"
    &pinyin_table[567],  // "ㄊㄠ" => "tao"
    &pinyin_table[586],  // "ㄊㄡ" => "tou"
    &pinyin_table[565],  // "ㄊㄢ" => "tan"
    &pinyin_table[571],  // "ㄊㄣ" => "ten"
    &pinyin_table[566],  // "ㄊㄤ" => "tang"
    &pinyin_table[572],  // "ㄊㄥ" => "teng"
    &pinyin_table[573],  // "ㄊㄧ" => "ti"
    &pinyin_table[577],  // "ㄊㄧㄝ" => "tie"
    &pinyin_table[576],  // "ㄊㄧㄠ" => "tiao"
    &pinyin_table[574],  // "ㄊㄧㄢ" => "tian"
    &pinyin_table[580],  // "ㄊㄧㄣ" => "tin"
    &pinyin_table[575],  // "ㄊㄧㄤ" => "tiang"
    &pinyin_table[581],  // "ㄊㄧㄥ" => "ting"
    &pinyin_table[587],  // "ㄊㄨ" => "tu"
    &pinyin_table[594],  // "ㄊㄨㄛ" => "tuo"
    &pinyin_table[592],  // "ㄊㄨㄟ" => "tui"
    &pinyin_table[588],  // "ㄊㄨㄢ" => "tuan"
    &pinyin_table[593],  // "ㄊㄨㄣ" => "tun"
    &pinyin_table[589],  // "ㄊㄨㄤ" => "tuang"
    &pinyin_table[585],  // "ㄊㄨㄥ" => "tong"
    &pinyin_table[358],  // "ㄋ" => "n"
    &pinyin_table[359],  // "ㄋㄚ" => "na"
    &pinyin_table[386],  // "ㄋㄛ" => "no"
    &pinyin_table[366],  // "ㄋㄜ" => "ne"
    &pinyin_table[361],  // "ㄋㄞ" => "nai"
    &pinyin_table[368],  // "ㄋㄟ" => "nei"
    &pinyin_table[365],  // "ㄋㄠ" => "nao"
    &pinyin_table[391],  // "ㄋㄡ" => "nou"
    &pinyin_table[363],  // "ㄋㄢ" => "nan"
    &pinyin_table[370],  // "ㄋㄣ" => "nen"
    &pinyin_table[364],  // "ㄋㄤ" => "nang"
    &pinyin_table[371],  // "ㄋㄥ" => "neng"
    &pinyin_table[372],  // "ㄋㄧ" => "ni"
    &pinyin_table[373],  // "ㄋㄧㄚ" => "nia"
    &pinyin_table[379],  // "ㄋㄧㄝ" => "nie"
    &pinyin_table[378],  // "ㄋㄧㄠ" => "niao"
    &pinyin_table[385],  // "ㄋㄧㄡ" => "niu"
    &pinyin_table[376],  // "ㄋㄧㄢ" => "nian"
    &pinyin_table[382],  // "ㄋㄧㄣ" => "nin"
    &pinyin_table[377],  // "ㄋㄧㄤ" => "niang"
    &pinyin_table[383],  // "ㄋㄧㄥ" => "ning"
    &pinyin_table[392],  // "ㄋㄨ" => "nu"
    &pinyin_table[398],  // "ㄋㄨㄛ" => "nuo"
    &pinyin_table[393],  // "ㄋㄨㄢ" => "nuan"
    &pinyin_table[397],  // "ㄋㄨㄣ" => "nun"
    &pinyin_table[394],  // "ㄋㄨㄤ" => "nuang"
    &pinyin_table[390],  // "ㄋㄨㄥ" => "nong"
    &pinyin_table[399],  // "ㄋㄩ" => "nv"
    &pinyin_table[400],  // "ㄋㄩㄝ" => "nve"
    &pinyin_table[285],  // "ㄌ" => "l"
    &pinyin_table[286],  // "ㄌㄚ" => "la"
    &pinyin_table[313],  // "ㄌㄛ" => "lo"
    &pinyin_table[293],  // "ㄌㄜ" => "le"
    &pinyin_table[288],  // "ㄌㄞ" => "lai"
    &pinyin_table[295],  // "ㄌㄟ" => "lei"
    &pinyin_table[292],  // "ㄌㄠ" => "lao"
    &pinyin_table[318],  // "ㄌㄡ" => "lou"
    &pinyin_table[290],  // "ㄌㄢ" => "lan"
    &pinyin_table[297],  // "ㄌㄣ" => "len"
    &pinyin_table[291],  // "ㄌㄤ" => "lang"
    &pinyin_table[298],  // "ㄌㄥ" => "leng"
    &pinyin_table[299],  // "ㄌㄧ" => "li"
    &pinyin_table[300],  // "ㄌㄧㄚ" => "lia"
    &pinyin_table[306],  // "ㄌㄧㄝ" => "lie"
    &pinyin_table[305],  // "ㄌㄧㄠ" => "liao"
    &pinyin_table[312],  // "ㄌㄧㄡ" => "liu"
    &pinyin_table[303],  // "ㄌㄧㄢ" => "lian"
    &pinyin_table[309],  // "ㄌㄧㄣ" => "lin"
    &pinyin_table[304],  // "ㄌㄧㄤ" => "liang"
    &pinyin_table[310],  // "ㄌㄧㄥ" => "ling"
    &pinyin_table[319],  // "ㄌㄨ" => "lu"
    &pinyin_table[327],  // "ㄌㄨㄛ" => "luo"
    &pinyin_table[325],  // "ㄌㄨㄟ" => "lui"
    &pinyin_table[320],  // "ㄌㄨㄢ" => "luan"
    &pinyin_table[326],  // "ㄌㄨㄣ" => "lun"
    &pinyin_table[321],  // "ㄌㄨㄤ" => "luang"
    &pinyin_table[317],  // "ㄌㄨㄥ" => "long"
    &pinyin_table[328],  // "ㄌㄩ" => "lv"
    &pinyin_table[329],  // "ㄌㄩㄝ" => "lve"
    &pinyin_table[160],  // "ㄍ" => "g"
    &pinyin_table[161],  // "ㄍㄚ" => "ga"
    &pinyin_table[168],  // "ㄍㄜ" => "ge"
    &pinyin_table[163],  // "ㄍㄞ" => "gai"
    &pinyin_table[170],  // "ㄍㄟ" => "gei"
    &pinyin_table[167],  // "ㄍㄠ" => "gao"
    &pinyin_table[178],  // "ㄍㄡ" => "gou"
    &pinyin_table[165],  // "ㄍㄢ" => "gan"
    &pinyin_table[172],  // "ㄍㄣ" => "gen"
    &pinyin_table[166],  // "ㄍㄤ" => "gang"
    &pinyin_table[173],  // "ㄍㄥ" => "geng"
    &pinyin_table[179],  // "ㄍㄨ" => "gu"
    &pinyin_table[180],  // "ㄍㄨㄚ" => "gua"
    &pinyin_table[190],  // "ㄍㄨㄛ" => "guo"
    &pinyin_table[182],  // "ㄍㄨㄞ" => "guai"
    &pinyin_table[188],  // "ㄍㄨㄟ" => "gui"
    &pinyin_table[184],  // "ㄍㄨㄢ" => "guan"
    &pinyin_table[189],  // "ㄍㄨㄣ" => "gun"
    &pinyin_table[185],  // "ㄍㄨㄤ" => "guang"
    &pinyin_table[177],  // "ㄍㄨㄥ" => "gong"
    &pinyin_table[254],  // "ㄎ" => "k"
    &pinyin_table[255],  // "ㄎㄚ" => "ka"
    &pinyin_table[262],  // "ㄎㄜ" => "ke"
    &pinyin_table[257],  // "ㄎㄞ" => "kai"
    &pinyin_table[264],  // "ㄎㄟ" => "kei"
    &pinyin_table[261],  // "ㄎㄠ" => "kao"
    &pinyin_table[272],  // "ㄎㄡ" => "kou"
    &pinyin_table[259],  // "ㄎㄢ" => "kan"
    &pinyin_table[266],  // "ㄎㄣ" => "ken"
    &pinyin_table[260],  // "ㄎㄤ" => "kang"
    &pinyin_table[267],  // "ㄎㄥ" => "keng"
    &pinyin_table[273],  // "ㄎㄨ" => "ku"
    &pinyin_table[274],  // "ㄎㄨㄚ" => "kua"
    &pinyin_table[284],  // "ㄎㄨㄛ" => "kuo"
    &pinyin_table[276],  // "ㄎㄨㄞ" => "kuai"
    &pinyin_table[282],  // "ㄎㄨㄟ" => "kui"
    &pinyin_table[278],  // "ㄎㄨㄢ" => "kuan"
    &pinyin_table[283],  // "ㄎㄨㄣ" => "kun"
    &pinyin_table[279],  // "ㄎㄨㄤ" => "kuang"
    &pinyin_table[271],  // "ㄎㄨㄥ" => "kong"
    &pinyin_table[191],  // "ㄏ" => "h"
    &pinyin_table[192],  // "ㄏㄚ" => "ha"
    &pinyin_table[205],  // "ㄏㄛ" => "ho"
    &pinyin_table[199],  // "ㄏㄜ" => "he"
    &pinyin_table[194],  // "ㄏㄞ" => "hai"
    &pinyin_table[201],  // "ㄏㄟ" => "hei"
    &pinyin_table[198],  // "ㄏㄠ" => "hao"
    &pinyin_table[210],  // "ㄏㄡ" => "hou"
    &pinyin_table[196],  // "ㄏㄢ" => "han"
    &pinyin_table[203],  // "ㄏㄣ" => "hen"
    &pinyin_table[197],  // "ㄏㄤ" => "hang"
    &pinyin_table[204],  // "ㄏㄥ" => "heng"
    &pinyin_table[211],  // "ㄏㄨ" => "hu"
    &pinyin_table[212],  // "ㄏㄨㄚ" => "hua"
    &pinyin_table[222],  // "ㄏㄨㄛ" => "huo"
    &pinyin_table[214],  // "ㄏㄨㄞ" => "huai"
    &pinyin_table[220],  // "ㄏㄨㄟ" => "hui"
    &pinyin_table[216],  // "ㄏㄨㄢ" => "huan"
    &pinyin_table[221],  // "ㄏㄨㄣ" => "hun"
    &pinyin_table[217],  // "ㄏㄨㄤ" => "huang"
    &pinyin_table[209],  // "ㄏㄨㄥ" => "hong"
    &pinyin_table[223],  // "ㄐ" => "j"
    &pinyin_table[224],  // "ㄐㄧ" => "ji"
    &pinyin_table[225],  // "ㄐㄧㄚ" => "jia"
    &pinyin_table[231],  // "ㄐㄧㄝ" => "jie"
    &pinyin_table[230],  // "ㄐㄧㄠ" => "jiao"
    &pinyin_table[241],  // "ㄐㄧㄡ" => "jiu"
    &pinyin_table[228],  // "ㄐㄧㄢ" => "jian"
    &pinyin_table[234],  // "ㄐㄧㄣ" => "jin"
    &pinyin_table[229],  // "ㄐㄧㄤ" => "jiang"
    &pinyin_table[235],  // "ㄐㄧㄥ" => "jing"
    &pinyin_table[242],  // "ㄐㄩ" => "ju"
    &pinyin_table[245],  // "ㄐㄩㄝ" => "jue"
    &pinyin_table[243],  // "ㄐㄩㄢ" => "juan"
    &pinyin_table[247],  // "ㄐㄩㄣ" => "jun"
    &pinyin_table[244],  // "ㄐㄩㄤ" => "juang"
    &pinyin_table[239],  // "ㄐㄩㄥ" => "jiong"
    &pinyin_table[428],  // "ㄑ" => "q"
    &pinyin_table[429],  // "ㄑㄧ" => "qi"
    &pinyin_table[430],  // "ㄑㄧㄚ" => "qia"
    &pinyin_table[436],  // "ㄑㄧㄝ" => "qie"
    &pinyin_table[435],  // "ㄑㄧㄠ" => "qiao"
    &pinyin_table[446],  // "ㄑㄧㄡ" => "qiu"
    &pinyin_table[433],  // "ㄑㄧㄢ" => "qian"
    &pinyin_table[439],  // "ㄑㄧㄣ" => "qin"
    &pinyin_table[434],  // "ㄑㄧㄤ" => "qiang"
    &pinyin_table[440],  // "ㄑㄧㄥ" => "qing"
    &pinyin_table[447],  // "ㄑㄩ" => "qu"
    &pinyin_table[450],  // "ㄑㄩㄝ" => "que"
    &pinyin_table[448],  // "ㄑㄩㄢ" => "quan"
    &pinyin_table[452],  // "ㄑㄩㄣ" => "qun"
    &pinyin_table[449],  // "ㄑㄩㄤ" => "quang"
    &pinyin_table[444],  // "ㄑㄩㄥ" => "qiong"
    &pinyin_table[609],  // "ㄒ" => "x"
    &pinyin_table[610],  // "ㄒㄧ" => "xi"
    &pinyin_table[611],  // "ㄒㄧㄚ" => "xia"
    &pinyin_table[617],  // "ㄒㄧㄝ" => "xie"
    &pinyin_table[616],  // "ㄒㄧㄠ" => "xiao"
    &pinyin_table[627],  // "ㄒㄧㄡ" => "xiu"
    &pinyin_table[614],  // "ㄒㄧㄢ" => "xian"
    &pinyin_table[620],  // "ㄒㄧㄣ" => "xin"
    &pinyin_table[615],  // "ㄒㄧㄤ" => "xiang"
    &pinyin_table[621],  // "ㄒㄧㄥ" => "xing"
    &pinyin_table[628],  // "ㄒㄩ" => "xu"
    &pinyin_table[631],  // "ㄒㄩㄝ" => "xue"
    &pinyin_table[629],  // "ㄒㄩㄢ" => "xuan"
    &pinyin_table[633],  // "ㄒㄩㄣ" => "xun"
    &pinyin_table[630],  // "ㄒㄩㄤ" => "xuang"
    &pinyin_table[625],  // "ㄒㄩㄥ" => "xiong"
    &pinyin_table[699],  // "ㄓ" => "zhi"
    &pinyin_table[686],  // "ㄓㄚ" => "zha"
    &pinyin_table[693],  // "ㄓㄜ" => "zhe"
    &pinyin_table[688],  // "ㄓㄞ" => "zhai"
    &pinyin_table[695],  // "ㄓㄟ" => "zhei"
    &pinyin_table[692],  // "ㄓㄠ" => "zhao"
    &pinyin_table[704],  // "ㄓㄡ" => "zhou"
    &pinyin_table[690],  // "ㄓㄢ" => "zhan"
    &pinyin_table[697],  // "ㄓㄣ" => "zhen"
    &pinyin_table[691],  // "ㄓㄤ" => "zhang"
    &pinyin_table[698],  // "ㄓㄥ" => "zheng"
    &pinyin_table[705],  // "ㄓㄨ" => "zhu"
    &pinyin_table[706],  // "ㄓㄨㄚ" => "zhua"
    &pinyin_table[716],  // "ㄓㄨㄛ" => "zhuo"
    &pinyin_table[708],  // "ㄓㄨㄞ" => "zhuai"
    &pinyin_table[714],  // "ㄓㄨㄟ" => "zhui"
    &pinyin_table[710],  // "ㄓㄨㄢ" => "zhuan"
    &pinyin_table[715],  // "ㄓㄨㄣ" => "zhun"
    &pinyin_table[711],  // "ㄓㄨㄤ" => "zhuang"
    &pinyin_table[703],  // "ㄓㄨㄥ" => "zhong"
    &pinyin_table[57],   // "ㄔ" => "chi"
    &pinyin_table[45],   // "ㄔㄚ" => "cha"
    &pinyin_table[52],   // "ㄔㄜ" => "che"
    &pinyin_table[47],   // "ㄔㄞ" => "chai"
    &pinyin_table[51],   // "ㄔㄠ" => "chao"
    &pinyin_table[62],   // "ㄔㄡ" => "chou"
    &pinyin_table[49],   // "ㄔㄢ" => "chan"
    &pinyin_table[55],   // "ㄔㄣ" => "chen"
    &pinyin_table[50],   // "ㄔㄤ" => "chang"
    &pinyin_table[56],   // "ㄔㄥ" => "cheng"
    &pinyin_table[63],   // "ㄔㄨ" => "chu"
    &pinyin_table[73],   // "ㄔㄨㄛ" => "chuo"
    &pinyin_table[65],   // "ㄔㄨㄞ" => "chuai"
    &pinyin_table[71],   // "ㄔㄨㄟ" => "chui"
    &pinyin_table[67],   // "ㄔㄨㄢ" => "chuan"
    &pinyin_table[72],   // "ㄔㄨㄣ" => "chun"
    &pinyin_table[68],   // "ㄔㄨㄤ" => "chuang"
    &pinyin_table[61],   // "ㄔㄨㄥ" => "chong"
    &pinyin_table[528],  // "ㄕ" => "shi"
    &pinyin_table[515],  // "ㄕㄚ" => "sha"
    &pinyin_table[522],  // "ㄕㄜ" => "she"
    &pinyin_table[517],  // "ㄕㄞ" => "shai"
    &pinyin_table[524],  // "ㄕㄟ" => "shei"
    &pinyin_table[521],  // "ㄕㄠ" => "shao"
    &pinyin_table[531],  // "ㄕㄡ" => "shou"
    &pinyin_table[519],  // "ㄕㄢ" => "shan"
    &pinyin_table[526],  // "ㄕㄣ" => "shen"
    &pinyin_table[520],  // "ㄕㄤ" => "shang"
    &pinyin_table[527],  // "ㄕㄥ" => "sheng"
    &pinyin_table[532],  // "ㄕㄨ" => "shu"
    &pinyin_table[533],  // "ㄕㄨㄚ" => "shua"
    &pinyin_table[543],  // "ㄕㄨㄛ" => "shuo"
    &pinyin_table[535],  // "ㄕㄨㄞ" => "shuai"
    &pinyin_table[541],  // "ㄕㄨㄟ" => "shui"
    &pinyin_table[537],  // "ㄕㄨㄢ" => "shuan"
    &pinyin_table[542],  // "ㄕㄨㄣ" => "shun"
    &pinyin_table[538],  // "ㄕㄨㄤ" => "shuang"
    &pinyin_table[530],  // "ㄕㄨㄥ" => "shong"
    &pinyin_table[473],  // "ㄖ" => "ri"
    &pinyin_table[460],  // "ㄖㄚ" => "ra"
    &pinyin_table[483],  // "ㄖㄛ" => "ro"
    &pinyin_table[467],  // "ㄖㄜ" => "re"
    &pinyin_table[462],  // "ㄖㄞ" => "rai"
    &pinyin_table[469],  // "ㄖㄟ" => "rei"
    &pinyin_table[466],  // "ㄖㄠ" => "rao"
    &pinyin_table[488],  // "ㄖㄡ" => "rou"
    &pinyin_table[464],  // "ㄖㄢ" => "ran"
    &pinyin_table[471],  // "ㄖㄣ" => "ren"
    &pinyin_table[465],  // "ㄖㄤ" => "rang"
    &pinyin_table[472],  // "ㄖㄥ" => "reng"
    &pinyin_table[474],  // "ㄖㄧㄚ" => "ria"
    &pinyin_table[478],  // "ㄖㄧㄝ" => "rie"
    &pinyin_table[477],  // "ㄖㄧㄠ" => "riao"
    &pinyin_table[482],  // "ㄖㄧㄡ" => "riu"
    &pinyin_table[475],  // "ㄖㄧㄢ" => "rian"
    &pinyin_table[479],  // "ㄖㄧㄣ" => "rin"
    &pinyin_table[476],  // "ㄖㄧㄤ" => "riang"
    &pinyin_table[480],  // "ㄖㄧㄥ" => "ring"
    &pinyin_table[489],  // "ㄖㄨ" => "ru"
    &pinyin_table[497],  // "ㄖㄨㄛ" => "ruo"
    &pinyin_table[495],  // "ㄖㄨㄟ" => "rui"
    &pinyin_table[490],  // "ㄖㄨㄢ" => "ruan"
    &pinyin_table[496],  // "ㄖㄨㄣ" => "run"
    &pinyin_table[491],  // "ㄖㄨㄤ" => "ruang"
    &pinyin_table[487],  // "ㄖㄨㄥ" => "rong"
    &pinyin_table[498],  // "ㄖㄩ" => "rv"
    &pinyin_table[499],  // "ㄖㄩㄝ" => "rve"
    &pinyin_table[717],  // "ㄗ" => "zi"
    &pinyin_table[672],  // "ㄗㄚ" => "za"
    &pinyin_table[679],  // "ㄗㄜ" => "ze"
    &pinyin_table[674],  // "ㄗㄞ" => "zai"
    &pinyin_table[681],  // "ㄗㄟ" => "zei"
    &pinyin_table[678],  // "ㄗㄠ" => "zao"
    &pinyin_table[722],  // "ㄗㄡ" => "zou"
    &pinyin_table[676],  // "ㄗㄢ" => "zan"
    &pinyin_table[683],  // "ㄗㄣ" => "zen"
    &pinyin_table[677],  // "ㄗㄤ" => "zang"
    &pinyin_table[684],  // "ㄗㄥ" => "zeng"
    &pinyin_table[723],  // "ㄗㄨ" => "zu"
    &pinyin_table[724],  // "ㄗㄨㄚ" => "zua"
    &pinyin_table[732],  // "ㄗㄨㄛ" => "zuo"
    &pinyin_table[725],  // "ㄗㄨㄞ" => "zuai"
    &pinyin_table[730],  // "ㄗㄨㄟ" => "zui"
    &pinyin_table[726],  // "ㄗㄨㄢ" => "zuan"
    &pinyin_table[731],  // "ㄗㄨㄣ" => "zun"
    &pinyin_table[727],  // "ㄗㄨㄤ" => "zuang"
    &pinyin_table[721],  // "ㄗㄨㄥ" => "zong"
    &pinyin_table[74],   // "ㄘ" => "ci"
    &pinyin_table[32],   // "ㄘㄚ" => "ca"
    &pinyin_table[39],   // "ㄘㄜ" => "ce"
    &pinyin_table[34],   // "ㄘㄞ" => "cai"
    &pinyin_table[38],   // "ㄘㄠ" => "cao"
    &pinyin_table[79],   // "ㄘㄡ" => "cou"
    &pinyin_table[36],   // "ㄘㄢ" => "can"
    &pinyin_table[42],   // "ㄘㄣ" => "cen"
    &pinyin_table[37],   // "ㄘㄤ" => "cang"
    &pinyin_table[43],   // "ㄘㄥ" => "ceng"
    &pinyin_table[80],   // "ㄘㄨ" => "cu"
    &pinyin_table[88],   // "ㄘㄨㄛ" => "cuo"
    &pinyin_table[81],   // "ㄘㄨㄞ" => "cuai"
    &pinyin_table[86],   // "ㄘㄨㄟ" => "cui"
    &pinyin_table[82],   // "ㄘㄨㄢ" => "cuan"
    &pinyin_table[87],   // "ㄘㄨㄣ" => "cun"
    &pinyin_table[83],   // "ㄘㄨㄤ" => "cuang"
    &pinyin_table[78],   // "ㄘㄨㄥ" => "cong"
    &pinyin_table[544],  // "ㄙ" => "si"
    &pinyin_table[501],  // "ㄙㄚ" => "sa"
    &pinyin_table[508],  // "ㄙㄜ" => "se"
    &pinyin_table[503],  // "ㄙㄞ" => "sai"
    &pinyin_table[510],  // "ㄙㄟ" => "sei"
    &pinyin_table[507],  // "ㄙㄠ" => "sao"
    &pinyin_table[549],  // "ㄙㄡ" => "sou"
    &pinyin_table[505],  // "ㄙㄢ" => "san"
    &pinyin_table[512],  // "ㄙㄣ" => "sen"
    &pinyin_table[506],  // "ㄙㄤ" => "sang"
    &pinyin_table[513],  // "ㄙㄥ" => "seng"
    &pinyin_table[550],  // "ㄙㄨ" => "su"
    &pinyin_table[551],  // "ㄙㄨㄚ" => "sua"
    &pinyin_table[559],  // "ㄙㄨㄛ" => "suo"
    &pinyin_table[552],  // "ㄙㄨㄞ" => "suai"
    &pinyin_table[557],  // "ㄙㄨㄟ" => "sui"
    &pinyin_table[553],  // "ㄙㄨㄢ" => "suan"
    &pinyin_table[558],  // "ㄙㄨㄣ" => "sun"
    &pinyin_table[554],  // "ㄙㄨㄤ" => "suang"
    &pinyin_table[548],  // "ㄙㄨㄥ" => "song"
    &pinyin_table[0],    // "ㄚ" => "a"
    &pinyin_table[401],  // "ㄛ" => "o"
    &pinyin_table[128],  // "ㄜ" => "e"
    &pinyin_table[2],    // "ㄞ" => "ai"
    &pinyin_table[129],  // "ㄟ" => "ei"
    &pinyin_table[6],    // "ㄠ" => "ao"
    &pinyin_table[402],  // "ㄡ" => "ou"
    &pinyin_table[4],    // "ㄢ" => "an"
    &pinyin_table[130],  // "ㄣ" => "en"
    &pinyin_table[5],    // "ㄤ" => "ang"
    &pinyin_table[131],  // "ㄦ" => "er"
    &pinyin_table[648],  // "ㄧ" => "yi"
    &pinyin_table[641],  // "ㄧㄚ" => "ya"
    &pinyin_table[653],  // "ㄧㄛ" => "yo"
    &pinyin_table[647],  // "ㄧㄝ" => "ye"
    &pinyin_table[646],  // "ㄧㄠ" => "yao"
    &pinyin_table[658],  // "ㄧㄡ" => "you"
    &pinyin_table[644],  // "ㄧㄢ" => "yan"
    &pinyin_table[651],  // "ㄧㄣ" => "yin"
    &pinyin_table[645],  // "ㄧㄤ" => "yang"
    &pinyin_table[652],  // "ㄧㄥ" => "ying"
    &pinyin_table[661],  // "ㄧㄩㄤ" => "yuang"
    &pinyin_table[608],  // "ㄨ" => "wu"
    &pinyin_table[596],  // "ㄨㄚ" => "wa"
    &pinyin_table[607],  // "ㄨㄛ" => "wo"
    &pinyin_table[598],  // "ㄨㄞ" => "wai"
    &pinyin_table[603],  // "ㄨㄟ" => "wei"
    &pinyin_table[600],  // "ㄨㄢ" => "wan"
    &pinyin_table[605],  // "ㄨㄣ" => "wen"
    &pinyin_table[601],  // "ㄨㄤ" => "wang"
    &pinyin_table[606],  // "ㄨㄥ" => "weng"
    &pinyin_table[659],  // "ㄩ" => "yu"
    &pinyin_table[662],  // "ㄩㄝ" => "yue"
    &pinyin_table[660],  // "ㄩㄢ" => "yuan"
    &pinyin_table[664],  // "ㄩㄣ" => "yun"
    &pinyin_table[657],  // "ㄩㄥ" => "yong"
};

static const Pinyin *special_table[][4] = {
    { &pinyin_table[4],    &pinyin_table[0],    &pinyin_table[0],    &pinyin_table[359],  }, /* an a => a na */
    { &pinyin_table[4],    &pinyin_table[2],    &pinyin_table[0],    &pinyin_table[361],  }, /* an ai => a nai */
    { &pinyin_table[4],    &pinyin_table[6],    &pinyin_table[0],    &pinyin_table[365],  }, /* an ao => a nao */
    { &pinyin_table[4],    &pinyin_table[128],  &pinyin_table[0],    &pinyin_table[366],  }, /* an e => a ne */
    { &pinyin_table[4],    &pinyin_table[129],  &pinyin_table[0],    &pinyin_table[368],  }, /* an ei => a nei */
    { &pinyin_table[5],    &pinyin_table[0],    &pinyin_table[4],    &pinyin_table[161],  }, /* ang a => an ga */
    { &pinyin_table[5],    &pinyin_table[2],    &pinyin_table[4],    &pinyin_table[163],  }, /* ang ai => an gai */
    { &pinyin_table[5],    &pinyin_table[4],    &pinyin_table[4],    &pinyin_table[165],  }, /* ang an => an gan */
    { &pinyin_table[5],    &pinyin_table[5],    &pinyin_table[4],    &pinyin_table[166],  }, /* ang ang => an gang */
    { &pinyin_table[5],    &pinyin_table[6],    &pinyin_table[4],    &pinyin_table[167],  }, /* ang ao => an gao */
    { &pinyin_table[5],    &pinyin_table[128],  &pinyin_table[4],    &pinyin_table[168],  }, /* ang e => an ge */
    { &pinyin_table[5],    &pinyin_table[129],  &pinyin_table[4],    &pinyin_table[170],  }, /* ang ei => an gei */
    { &pinyin_table[5],    &pinyin_table[130],  &pinyin_table[4],    &pinyin_table[172],  }, /* ang en => an gen */
    { &pinyin_table[5],    &pinyin_table[402],  &pinyin_table[4],    &pinyin_table[178],  }, /* ang ou => an gou */
    { &pinyin_table[12],   &pinyin_table[0],    &pinyin_table[8],    &pinyin_table[359],  }, /* ban a => ba na */
    { &pinyin_table[12],   &pinyin_table[5],    &pinyin_table[8],    &pinyin_table[364],  }, /* ban ang => ba nang */
    { &pinyin_table[12],   &pinyin_table[6],    &pinyin_table[8],    &pinyin_table[365],  }, /* ban ao => ba nao */
    { &pinyin_table[12],   &pinyin_table[128],  &pinyin_table[8],    &pinyin_table[366],  }, /* ban e => ba ne */
    { &pinyin_table[12],   &pinyin_table[129],  &pinyin_table[8],    &pinyin_table[368],  }, /* ban ei => ba nei */
    { &pinyin_table[13],   &pinyin_table[2],    &pinyin_table[12],   &pinyin_table[163],  }, /* bang ai => ban gai */
    { &pinyin_table[13],   &pinyin_table[5],    &pinyin_table[12],   &pinyin_table[166],  }, /* bang ang => ban gang */
    { &pinyin_table[13],   &pinyin_table[6],    &pinyin_table[12],   &pinyin_table[167],  }, /* bang ao => ban gao */
    { &pinyin_table[13],   &pinyin_table[128],  &pinyin_table[12],   &pinyin_table[168],  }, /* bang e => ban ge */
    { &pinyin_table[13],   &pinyin_table[129],  &pinyin_table[12],   &pinyin_table[170],  }, /* bang ei => ban gei */
    { &pinyin_table[13],   &pinyin_table[130],  &pinyin_table[12],   &pinyin_table[172],  }, /* bang en => ban gen */
    { &pinyin_table[19],   &pinyin_table[0],    &pinyin_table[18],   &pinyin_table[161],  }, /* beng a => ben ga */
    { &pinyin_table[19],   &pinyin_table[2],    &pinyin_table[18],   &pinyin_table[163],  }, /* beng ai => ben gai */
    { &pinyin_table[19],   &pinyin_table[4],    &pinyin_table[18],   &pinyin_table[165],  }, /* beng an => ben gan */
    { &pinyin_table[19],   &pinyin_table[5],    &pinyin_table[18],   &pinyin_table[166],  }, /* beng ang => ben gang */
    { &pinyin_table[19],   &pinyin_table[6],    &pinyin_table[18],   &pinyin_table[167],  }, /* beng ao => ben gao */
    { &pinyin_table[19],   &pinyin_table[128],  &pinyin_table[18],   &pinyin_table[168],  }, /* beng e => ben ge */
    { &pinyin_table[19],   &pinyin_table[129],  &pinyin_table[18],   &pinyin_table[170],  }, /* beng ei => ben gei */
    { &pinyin_table[19],   &pinyin_table[130],  &pinyin_table[18],   &pinyin_table[172],  }, /* beng en => ben gen */
    { &pinyin_table[19],   &pinyin_table[402],  &pinyin_table[18],   &pinyin_table[178],  }, /* beng ou => ben gou */
    { &pinyin_table[22],   &pinyin_table[0],    &pinyin_table[21],   &pinyin_table[161],  }, /* biang a => bian ga */
    { &pinyin_table[22],   &pinyin_table[2],    &pinyin_table[21],   &pinyin_table[163],  }, /* biang ai => bian gai */
    { &pinyin_table[22],   &pinyin_table[4],    &pinyin_table[21],   &pinyin_table[165],  }, /* biang an => bian gan */
    { &pinyin_table[22],   &pinyin_table[5],    &pinyin_table[21],   &pinyin_table[166],  }, /* biang ang => bian gang */
    { &pinyin_table[22],   &pinyin_table[6],    &pinyin_table[21],   &pinyin_table[167],  }, /* biang ao => bian gao */
    { &pinyin_table[22],   &pinyin_table[128],  &pinyin_table[21],   &pinyin_table[168],  }, /* biang e => bian ge */
    { &pinyin_table[22],   &pinyin_table[129],  &pinyin_table[21],   &pinyin_table[170],  }, /* biang ei => bian gei */
    { &pinyin_table[22],   &pinyin_table[130],  &pinyin_table[21],   &pinyin_table[172],  }, /* biang en => bian gen */
    { &pinyin_table[22],   &pinyin_table[402],  &pinyin_table[21],   &pinyin_table[178],  }, /* biang ou => bian gou */
    { &pinyin_table[24],   &pinyin_table[459],  &pinyin_table[20],   &pinyin_table[131],  }, /* bie r => bi er */
    { &pinyin_table[27],   &pinyin_table[0],    &pinyin_table[20],   &pinyin_table[359],  }, /* bin a => bi na */
    { &pinyin_table[27],   &pinyin_table[2],    &pinyin_table[20],   &pinyin_table[361],  }, /* bin ai => bi nai */
    { &pinyin_table[27],   &pinyin_table[4],    &pinyin_table[20],   &pinyin_table[363],  }, /* bin an => bi nan */
    { &pinyin_table[27],   &pinyin_table[5],    &pinyin_table[20],   &pinyin_table[364],  }, /* bin ang => bi nang */
    { &pinyin_table[27],   &pinyin_table[6],    &pinyin_table[20],   &pinyin_table[365],  }, /* bin ao => bi nao */
    { &pinyin_table[27],   &pinyin_table[128],  &pinyin_table[20],   &pinyin_table[366],  }, /* bin e => bi ne */
    { &pinyin_table[27],   &pinyin_table[129],  &pinyin_table[20],   &pinyin_table[368],  }, /* bin ei => bi nei */
    { &pinyin_table[27],   &pinyin_table[130],  &pinyin_table[20],   &pinyin_table[370],  }, /* bin en => bi nen */
    { &pinyin_table[28],   &pinyin_table[128],  &pinyin_table[27],   &pinyin_table[168],  }, /* bing e => bin ge */
    { &pinyin_table[28],   &pinyin_table[129],  &pinyin_table[27],   &pinyin_table[170],  }, /* bing ei => bin gei */
    { &pinyin_table[36],   &pinyin_table[129],  &pinyin_table[32],   &pinyin_table[368],  }, /* can ei => ca nei */
    { &pinyin_table[37],   &pinyin_table[4],    &pinyin_table[36],   &pinyin_table[165],  }, /* cang an => can gan */
    { &pinyin_table[37],   &pinyin_table[5],    &pinyin_table[36],   &pinyin_table[166],  }, /* cang ang => can gang */
    { &pinyin_table[37],   &pinyin_table[128],  &pinyin_table[36],   &pinyin_table[168],  }, /* cang e => can ge */
    { &pinyin_table[37],   &pinyin_table[129],  &pinyin_table[36],   &pinyin_table[170],  }, /* cang ei => can gei */
    { &pinyin_table[37],   &pinyin_table[130],  &pinyin_table[36],   &pinyin_table[172],  }, /* cang en => can gen */
    { &pinyin_table[37],   &pinyin_table[402],  &pinyin_table[36],   &pinyin_table[178],  }, /* cang ou => can gou */
    { &pinyin_table[42],   &pinyin_table[0],    &pinyin_table[39],   &pinyin_table[359],  }, /* cen a => ce na */
    { &pinyin_table[42],   &pinyin_table[2],    &pinyin_table[39],   &pinyin_table[361],  }, /* cen ai => ce nai */
    { &pinyin_table[42],   &pinyin_table[4],    &pinyin_table[39],   &pinyin_table[363],  }, /* cen an => ce nan */
    { &pinyin_table[42],   &pinyin_table[5],    &pinyin_table[39],   &pinyin_table[364],  }, /* cen ang => ce nang */
    { &pinyin_table[42],   &pinyin_table[6],    &pinyin_table[39],   &pinyin_table[365],  }, /* cen ao => ce nao */
    { &pinyin_table[42],   &pinyin_table[128],  &pinyin_table[39],   &pinyin_table[366],  }, /* cen e => ce ne */
    { &pinyin_table[42],   &pinyin_table[129],  &pinyin_table[39],   &pinyin_table[368],  }, /* cen ei => ce nei */
    { &pinyin_table[42],   &pinyin_table[130],  &pinyin_table[39],   &pinyin_table[370],  }, /* cen en => ce nen */
    { &pinyin_table[43],   &pinyin_table[129],  &pinyin_table[42],   &pinyin_table[170],  }, /* ceng ei => cen gei */
    { &pinyin_table[49],   &pinyin_table[0],    &pinyin_table[45],   &pinyin_table[359],  }, /* chan a => cha na */
    { &pinyin_table[49],   &pinyin_table[6],    &pinyin_table[45],   &pinyin_table[365],  }, /* chan ao => cha nao */
    { &pinyin_table[49],   &pinyin_table[128],  &pinyin_table[45],   &pinyin_table[366],  }, /* chan e => cha ne */
    { &pinyin_table[49],   &pinyin_table[129],  &pinyin_table[45],   &pinyin_table[368],  }, /* chan ei => cha nei */
    { &pinyin_table[50],   &pinyin_table[5],    &pinyin_table[49],   &pinyin_table[166],  }, /* chang ang => chan gang */
    { &pinyin_table[50],   &pinyin_table[6],    &pinyin_table[49],   &pinyin_table[167],  }, /* chang ao => chan gao */
    { &pinyin_table[50],   &pinyin_table[129],  &pinyin_table[49],   &pinyin_table[170],  }, /* chang ei => chan gei */
    { &pinyin_table[50],   &pinyin_table[130],  &pinyin_table[49],   &pinyin_table[172],  }, /* chang en => chan gen */
    { &pinyin_table[50],   &pinyin_table[402],  &pinyin_table[49],   &pinyin_table[178],  }, /* chang ou => chan gou */
    { &pinyin_table[55],   &pinyin_table[0],    &pinyin_table[52],   &pinyin_table[359],  }, /* chen a => che na */
    { &pinyin_table[55],   &pinyin_table[4],    &pinyin_table[52],   &pinyin_table[363],  }, /* chen an => che nan */
    { &pinyin_table[55],   &pinyin_table[5],    &pinyin_table[52],   &pinyin_table[364],  }, /* chen ang => che nang */
    { &pinyin_table[55],   &pinyin_table[6],    &pinyin_table[52],   &pinyin_table[365],  }, /* chen ao => che nao */
    { &pinyin_table[55],   &pinyin_table[128],  &pinyin_table[52],   &pinyin_table[366],  }, /* chen e => che ne */
    { &pinyin_table[55],   &pinyin_table[129],  &pinyin_table[52],   &pinyin_table[368],  }, /* chen ei => che nei */
    { &pinyin_table[56],   &pinyin_table[5],    &pinyin_table[55],   &pinyin_table[166],  }, /* cheng ang => chen gang */
    { &pinyin_table[56],   &pinyin_table[6],    &pinyin_table[55],   &pinyin_table[167],  }, /* cheng ao => chen gao */
    { &pinyin_table[56],   &pinyin_table[129],  &pinyin_table[55],   &pinyin_table[170],  }, /* cheng ei => chen gei */
    { &pinyin_table[56],   &pinyin_table[402],  &pinyin_table[55],   &pinyin_table[178],  }, /* cheng ou => chen gou */
    { &pinyin_table[68],   &pinyin_table[4],    &pinyin_table[67],   &pinyin_table[165],  }, /* chuang an => chuan gan */
    { &pinyin_table[68],   &pinyin_table[5],    &pinyin_table[67],   &pinyin_table[166],  }, /* chuang ang => chuan gang */
    { &pinyin_table[68],   &pinyin_table[6],    &pinyin_table[67],   &pinyin_table[167],  }, /* chuang ao => chuan gao */
    { &pinyin_table[68],   &pinyin_table[128],  &pinyin_table[67],   &pinyin_table[168],  }, /* chuang e => chuan ge */
    { &pinyin_table[68],   &pinyin_table[129],  &pinyin_table[67],   &pinyin_table[170],  }, /* chuang ei => chuan gei */
    { &pinyin_table[68],   &pinyin_table[130],  &pinyin_table[67],   &pinyin_table[172],  }, /* chuang en => chuan gen */
    { &pinyin_table[68],   &pinyin_table[402],  &pinyin_table[67],   &pinyin_table[178],  }, /* chuang ou => chuan gou */
    { &pinyin_table[72],   &pinyin_table[0],    &pinyin_table[63],   &pinyin_table[359],  }, /* chun a => chu na */
    { &pinyin_table[72],   &pinyin_table[4],    &pinyin_table[63],   &pinyin_table[363],  }, /* chun an => chu nan */
    { &pinyin_table[72],   &pinyin_table[5],    &pinyin_table[63],   &pinyin_table[364],  }, /* chun ang => chu nang */
    { &pinyin_table[72],   &pinyin_table[6],    &pinyin_table[63],   &pinyin_table[365],  }, /* chun ao => chu nao */
    { &pinyin_table[72],   &pinyin_table[128],  &pinyin_table[63],   &pinyin_table[366],  }, /* chun e => chu ne */
    { &pinyin_table[72],   &pinyin_table[129],  &pinyin_table[63],   &pinyin_table[368],  }, /* chun ei => chu nei */
    { &pinyin_table[83],   &pinyin_table[0],    &pinyin_table[82],   &pinyin_table[161],  }, /* cuang a => cuan ga */
    { &pinyin_table[83],   &pinyin_table[2],    &pinyin_table[82],   &pinyin_table[163],  }, /* cuang ai => cuan gai */
    { &pinyin_table[83],   &pinyin_table[4],    &pinyin_table[82],   &pinyin_table[165],  }, /* cuang an => cuan gan */
    { &pinyin_table[83],   &pinyin_table[5],    &pinyin_table[82],   &pinyin_table[166],  }, /* cuang ang => cuan gang */
    { &pinyin_table[83],   &pinyin_table[6],    &pinyin_table[82],   &pinyin_table[167],  }, /* cuang ao => cuan gao */
    { &pinyin_table[83],   &pinyin_table[128],  &pinyin_table[82],   &pinyin_table[168],  }, /* cuang e => cuan ge */
    { &pinyin_table[83],   &pinyin_table[129],  &pinyin_table[82],   &pinyin_table[170],  }, /* cuang ei => cuan gei */
    { &pinyin_table[83],   &pinyin_table[130],  &pinyin_table[82],   &pinyin_table[172],  }, /* cuang en => cuan gen */
    { &pinyin_table[83],   &pinyin_table[402],  &pinyin_table[82],   &pinyin_table[178],  }, /* cuang ou => cuan gou */
    { &pinyin_table[87],   &pinyin_table[128],  &pinyin_table[80],   &pinyin_table[366],  }, /* cun e => cu ne */
    { &pinyin_table[87],   &pinyin_table[129],  &pinyin_table[80],   &pinyin_table[368],  }, /* cun ei => cu nei */
    { &pinyin_table[94],   &pinyin_table[0],    &pinyin_table[90],   &pinyin_table[359],  }, /* dan a => da na */
    { &pinyin_table[94],   &pinyin_table[2],    &pinyin_table[90],   &pinyin_table[361],  }, /* dan ai => da nai */
    { &pinyin_table[94],   &pinyin_table[4],    &pinyin_table[90],   &pinyin_table[363],  }, /* dan an => da nan */
    { &pinyin_table[94],   &pinyin_table[5],    &pinyin_table[90],   &pinyin_table[364],  }, /* dan ang => da nang */
    { &pinyin_table[94],   &pinyin_table[6],    &pinyin_table[90],   &pinyin_table[365],  }, /* dan ao => da nao */
    { &pinyin_table[94],   &pinyin_table[128],  &pinyin_table[90],   &pinyin_table[366],  }, /* dan e => da ne */
    { &pinyin_table[94],   &pinyin_table[129],  &pinyin_table[90],   &pinyin_table[368],  }, /* dan ei => da nei */
    { &pinyin_table[95],   &pinyin_table[2],    &pinyin_table[94],   &pinyin_table[163],  }, /* dang ai => dan gai */
    { &pinyin_table[95],   &pinyin_table[5],    &pinyin_table[94],   &pinyin_table[166],  }, /* dang ang => dan gang */
    { &pinyin_table[95],   &pinyin_table[6],    &pinyin_table[94],   &pinyin_table[167],  }, /* dang ao => dan gao */
    { &pinyin_table[95],   &pinyin_table[128],  &pinyin_table[94],   &pinyin_table[168],  }, /* dang e => dan ge */
    { &pinyin_table[95],   &pinyin_table[129],  &pinyin_table[94],   &pinyin_table[170],  }, /* dang ei => dan gei */
    { &pinyin_table[95],   &pinyin_table[130],  &pinyin_table[94],   &pinyin_table[172],  }, /* dang en => dan gen */
    { &pinyin_table[101],  &pinyin_table[0],    &pinyin_table[97],   &pinyin_table[359],  }, /* den a => de na */
    { &pinyin_table[101],  &pinyin_table[2],    &pinyin_table[97],   &pinyin_table[361],  }, /* den ai => de nai */
    { &pinyin_table[101],  &pinyin_table[4],    &pinyin_table[97],   &pinyin_table[363],  }, /* den an => de nan */
    { &pinyin_table[101],  &pinyin_table[5],    &pinyin_table[97],   &pinyin_table[364],  }, /* den ang => de nang */
    { &pinyin_table[101],  &pinyin_table[6],    &pinyin_table[97],   &pinyin_table[365],  }, /* den ao => de nao */
    { &pinyin_table[101],  &pinyin_table[128],  &pinyin_table[97],   &pinyin_table[366],  }, /* den e => de ne */
    { &pinyin_table[101],  &pinyin_table[129],  &pinyin_table[97],   &pinyin_table[368],  }, /* den ei => de nei */
    { &pinyin_table[101],  &pinyin_table[130],  &pinyin_table[97],   &pinyin_table[370],  }, /* den en => de nen */
    { &pinyin_table[101],  &pinyin_table[402],  &pinyin_table[97],   &pinyin_table[391],  }, /* den ou => de nou */
    { &pinyin_table[106],  &pinyin_table[0],    &pinyin_table[105],  &pinyin_table[161],  }, /* diang a => dian ga */
    { &pinyin_table[106],  &pinyin_table[2],    &pinyin_table[105],  &pinyin_table[163],  }, /* diang ai => dian gai */
    { &pinyin_table[106],  &pinyin_table[4],    &pinyin_table[105],  &pinyin_table[165],  }, /* diang an => dian gan */
    { &pinyin_table[106],  &pinyin_table[5],    &pinyin_table[105],  &pinyin_table[166],  }, /* diang ang => dian gang */
    { &pinyin_table[106],  &pinyin_table[6],    &pinyin_table[105],  &pinyin_table[167],  }, /* diang ao => dian gao */
    { &pinyin_table[106],  &pinyin_table[128],  &pinyin_table[105],  &pinyin_table[168],  }, /* diang e => dian ge */
    { &pinyin_table[106],  &pinyin_table[129],  &pinyin_table[105],  &pinyin_table[170],  }, /* diang ei => dian gei */
    { &pinyin_table[106],  &pinyin_table[130],  &pinyin_table[105],  &pinyin_table[172],  }, /* diang en => dian gen */
    { &pinyin_table[106],  &pinyin_table[402],  &pinyin_table[105],  &pinyin_table[178],  }, /* diang ou => dian gou */
    { &pinyin_table[108],  &pinyin_table[459],  &pinyin_table[103],  &pinyin_table[131],  }, /* die r => di er */
    { &pinyin_table[111],  &pinyin_table[0],    &pinyin_table[103],  &pinyin_table[359],  }, /* din a => di na */
    { &pinyin_table[111],  &pinyin_table[2],    &pinyin_table[103],  &pinyin_table[361],  }, /* din ai => di nai */
    { &pinyin_table[111],  &pinyin_table[4],    &pinyin_table[103],  &pinyin_table[363],  }, /* din an => di nan */
    { &pinyin_table[111],  &pinyin_table[5],    &pinyin_table[103],  &pinyin_table[364],  }, /* din ang => di nang */
    { &pinyin_table[111],  &pinyin_table[6],    &pinyin_table[103],  &pinyin_table[365],  }, /* din ao => di nao */
    { &pinyin_table[111],  &pinyin_table[128],  &pinyin_table[103],  &pinyin_table[366],  }, /* din e => di ne */
    { &pinyin_table[111],  &pinyin_table[129],  &pinyin_table[103],  &pinyin_table[368],  }, /* din ei => di nei */
    { &pinyin_table[111],  &pinyin_table[130],  &pinyin_table[103],  &pinyin_table[370],  }, /* din en => di nen */
    { &pinyin_table[111],  &pinyin_table[402],  &pinyin_table[103],  &pinyin_table[391],  }, /* din ou => di nou */
    { &pinyin_table[122],  &pinyin_table[0],    &pinyin_table[121],  &pinyin_table[161],  }, /* duang a => duan ga */
    { &pinyin_table[122],  &pinyin_table[2],    &pinyin_table[121],  &pinyin_table[163],  }, /* duang ai => duan gai */
    { &pinyin_table[122],  &pinyin_table[4],    &pinyin_table[121],  &pinyin_table[165],  }, /* duang an => duan gan */
    { &pinyin_table[122],  &pinyin_table[5],    &pinyin_table[121],  &pinyin_table[166],  }, /* duang ang => duan gang */
    { &pinyin_table[122],  &pinyin_table[6],    &pinyin_table[121],  &pinyin_table[167],  }, /* duang ao => duan gao */
    { &pinyin_table[122],  &pinyin_table[128],  &pinyin_table[121],  &pinyin_table[168],  }, /* duang e => duan ge */
    { &pinyin_table[122],  &pinyin_table[129],  &pinyin_table[121],  &pinyin_table[170],  }, /* duang ei => duan gei */
    { &pinyin_table[122],  &pinyin_table[130],  &pinyin_table[121],  &pinyin_table[172],  }, /* duang en => duan gen */
    { &pinyin_table[122],  &pinyin_table[402],  &pinyin_table[121],  &pinyin_table[178],  }, /* duang ou => duan gou */
    { &pinyin_table[126],  &pinyin_table[0],    &pinyin_table[120],  &pinyin_table[359],  }, /* dun a => du na */
    { &pinyin_table[126],  &pinyin_table[4],    &pinyin_table[120],  &pinyin_table[363],  }, /* dun an => du nan */
    { &pinyin_table[126],  &pinyin_table[5],    &pinyin_table[120],  &pinyin_table[364],  }, /* dun ang => du nang */
    { &pinyin_table[126],  &pinyin_table[6],    &pinyin_table[120],  &pinyin_table[365],  }, /* dun ao => du nao */
    { &pinyin_table[126],  &pinyin_table[128],  &pinyin_table[120],  &pinyin_table[366],  }, /* dun e => du ne */
    { &pinyin_table[126],  &pinyin_table[129],  &pinyin_table[120],  &pinyin_table[368],  }, /* dun ei => du nei */
    { &pinyin_table[130],  &pinyin_table[4],    &pinyin_table[128],  &pinyin_table[363],  }, /* en an => e nan */
    { &pinyin_table[130],  &pinyin_table[5],    &pinyin_table[128],  &pinyin_table[364],  }, /* en ang => e nang */
    { &pinyin_table[130],  &pinyin_table[6],    &pinyin_table[128],  &pinyin_table[365],  }, /* en ao => e nao */
    { &pinyin_table[130],  &pinyin_table[128],  &pinyin_table[128],  &pinyin_table[366],  }, /* en e => e ne */
    { &pinyin_table[130],  &pinyin_table[129],  &pinyin_table[128],  &pinyin_table[368],  }, /* en ei => e nei */
    { &pinyin_table[131],  &pinyin_table[4],    &pinyin_table[128],  &pinyin_table[464],  }, /* er an => e ran */
    { &pinyin_table[131],  &pinyin_table[5],    &pinyin_table[128],  &pinyin_table[465],  }, /* er ang => e rang */
    { &pinyin_table[131],  &pinyin_table[130],  &pinyin_table[128],  &pinyin_table[471],  }, /* er en => e ren */
    { &pinyin_table[131],  &pinyin_table[402],  &pinyin_table[128],  &pinyin_table[488],  }, /* er ou => e rou */
    { &pinyin_table[137],  &pinyin_table[5],    &pinyin_table[133],  &pinyin_table[364],  }, /* fan ang => fa nang */
    { &pinyin_table[137],  &pinyin_table[6],    &pinyin_table[133],  &pinyin_table[365],  }, /* fan ao => fa nao */
    { &pinyin_table[137],  &pinyin_table[129],  &pinyin_table[133],  &pinyin_table[368],  }, /* fan ei => fa nei */
    { &pinyin_table[138],  &pinyin_table[5],    &pinyin_table[137],  &pinyin_table[166],  }, /* fang ang => fan gang */
    { &pinyin_table[138],  &pinyin_table[6],    &pinyin_table[137],  &pinyin_table[167],  }, /* fang ao => fan gao */
    { &pinyin_table[138],  &pinyin_table[128],  &pinyin_table[137],  &pinyin_table[168],  }, /* fang e => fan ge */
    { &pinyin_table[138],  &pinyin_table[129],  &pinyin_table[137],  &pinyin_table[170],  }, /* fang ei => fan gei */
    { &pinyin_table[138],  &pinyin_table[130],  &pinyin_table[137],  &pinyin_table[172],  }, /* fang en => fan gen */
    { &pinyin_table[145],  &pinyin_table[5],    &pinyin_table[144],  &pinyin_table[166],  }, /* feng ang => fen gang */
    { &pinyin_table[145],  &pinyin_table[6],    &pinyin_table[144],  &pinyin_table[167],  }, /* feng ao => fen gao */
    { &pinyin_table[145],  &pinyin_table[128],  &pinyin_table[144],  &pinyin_table[168],  }, /* feng e => fen ge */
    { &pinyin_table[145],  &pinyin_table[129],  &pinyin_table[144],  &pinyin_table[170],  }, /* feng ei => fen gei */
    { &pinyin_table[145],  &pinyin_table[130],  &pinyin_table[144],  &pinyin_table[172],  }, /* feng en => fen gen */
    { &pinyin_table[145],  &pinyin_table[402],  &pinyin_table[144],  &pinyin_table[178],  }, /* feng ou => fen gou */
    { &pinyin_table[147],  &pinyin_table[0],    &pinyin_table[146],  &pinyin_table[359],  }, /* fon a => fo na */
    { &pinyin_table[147],  &pinyin_table[2],    &pinyin_table[146],  &pinyin_table[361],  }, /* fon ai => fo nai */
    { &pinyin_table[147],  &pinyin_table[4],    &pinyin_table[146],  &pinyin_table[363],  }, /* fon an => fo nan */
    { &pinyin_table[147],  &pinyin_table[5],    &pinyin_table[146],  &pinyin_table[364],  }, /* fon ang => fo nang */
    { &pinyin_table[147],  &pinyin_table[6],    &pinyin_table[146],  &pinyin_table[365],  }, /* fon ao => fo nao */
    { &pinyin_table[147],  &pinyin_table[128],  &pinyin_table[146],  &pinyin_table[366],  }, /* fon e => fo ne */
    { &pinyin_table[147],  &pinyin_table[129],  &pinyin_table[146],  &pinyin_table[368],  }, /* fon ei => fo nei */
    { &pinyin_table[147],  &pinyin_table[130],  &pinyin_table[146],  &pinyin_table[370],  }, /* fon en => fo nen */
    { &pinyin_table[147],  &pinyin_table[402],  &pinyin_table[146],  &pinyin_table[391],  }, /* fon ou => fo nou */
    { &pinyin_table[158],  &pinyin_table[0],    &pinyin_table[150],  &pinyin_table[359],  }, /* fun a => fu na */
    { &pinyin_table[158],  &pinyin_table[2],    &pinyin_table[150],  &pinyin_table[361],  }, /* fun ai => fu nai */
    { &pinyin_table[158],  &pinyin_table[4],    &pinyin_table[150],  &pinyin_table[363],  }, /* fun an => fu nan */
    { &pinyin_table[158],  &pinyin_table[5],    &pinyin_table[150],  &pinyin_table[364],  }, /* fun ang => fu nang */
    { &pinyin_table[158],  &pinyin_table[6],    &pinyin_table[150],  &pinyin_table[365],  }, /* fun ao => fu nao */
    { &pinyin_table[158],  &pinyin_table[128],  &pinyin_table[150],  &pinyin_table[366],  }, /* fun e => fu ne */
    { &pinyin_table[158],  &pinyin_table[129],  &pinyin_table[150],  &pinyin_table[368],  }, /* fun ei => fu nei */
    { &pinyin_table[158],  &pinyin_table[130],  &pinyin_table[150],  &pinyin_table[370],  }, /* fun en => fu nen */
    { &pinyin_table[158],  &pinyin_table[402],  &pinyin_table[150],  &pinyin_table[391],  }, /* fun ou => fu nou */
    { &pinyin_table[165],  &pinyin_table[128],  &pinyin_table[161],  &pinyin_table[366],  }, /* gan e => ga ne */
    { &pinyin_table[165],  &pinyin_table[129],  &pinyin_table[161],  &pinyin_table[368],  }, /* gan ei => ga nei */
    { &pinyin_table[166],  &pinyin_table[0],    &pinyin_table[165],  &pinyin_table[161],  }, /* gang a => gan ga */
    { &pinyin_table[166],  &pinyin_table[2],    &pinyin_table[165],  &pinyin_table[163],  }, /* gang ai => gan gai */
    { &pinyin_table[166],  &pinyin_table[4],    &pinyin_table[165],  &pinyin_table[165],  }, /* gang an => gan gan */
    { &pinyin_table[166],  &pinyin_table[5],    &pinyin_table[165],  &pinyin_table[166],  }, /* gang ang => gan gang */
    { &pinyin_table[166],  &pinyin_table[128],  &pinyin_table[165],  &pinyin_table[168],  }, /* gang e => gan ge */
    { &pinyin_table[166],  &pinyin_table[129],  &pinyin_table[165],  &pinyin_table[170],  }, /* gang ei => gan gei */
    { &pinyin_table[166],  &pinyin_table[130],  &pinyin_table[165],  &pinyin_table[172],  }, /* gang en => gan gen */
    { &pinyin_table[166],  &pinyin_table[402],  &pinyin_table[165],  &pinyin_table[178],  }, /* gang ou => gan gou */
    { &pinyin_table[172],  &pinyin_table[0],    &pinyin_table[168],  &pinyin_table[359],  }, /* gen a => ge na */
    { &pinyin_table[172],  &pinyin_table[4],    &pinyin_table[168],  &pinyin_table[363],  }, /* gen an => ge nan */
    { &pinyin_table[172],  &pinyin_table[5],    &pinyin_table[168],  &pinyin_table[364],  }, /* gen ang => ge nang */
    { &pinyin_table[172],  &pinyin_table[6],    &pinyin_table[168],  &pinyin_table[365],  }, /* gen ao => ge nao */
    { &pinyin_table[172],  &pinyin_table[128],  &pinyin_table[168],  &pinyin_table[366],  }, /* gen e => ge ne */
    { &pinyin_table[172],  &pinyin_table[129],  &pinyin_table[168],  &pinyin_table[368],  }, /* gen ei => ge nei */
    { &pinyin_table[173],  &pinyin_table[5],    &pinyin_table[172],  &pinyin_table[166],  }, /* geng ang => gen gang */
    { &pinyin_table[173],  &pinyin_table[6],    &pinyin_table[172],  &pinyin_table[167],  }, /* geng ao => gen gao */
    { &pinyin_table[173],  &pinyin_table[128],  &pinyin_table[172],  &pinyin_table[168],  }, /* geng e => gen ge */
    { &pinyin_table[173],  &pinyin_table[129],  &pinyin_table[172],  &pinyin_table[170],  }, /* geng ei => gen gei */
    { &pinyin_table[173],  &pinyin_table[130],  &pinyin_table[172],  &pinyin_table[172],  }, /* geng en => gen gen */
    { &pinyin_table[173],  &pinyin_table[402],  &pinyin_table[172],  &pinyin_table[178],  }, /* geng ou => gen gou */
    { &pinyin_table[184],  &pinyin_table[129],  &pinyin_table[180],  &pinyin_table[368],  }, /* guan ei => gua nei */
    { &pinyin_table[185],  &pinyin_table[2],    &pinyin_table[184],  &pinyin_table[163],  }, /* guang ai => guan gai */
    { &pinyin_table[185],  &pinyin_table[5],    &pinyin_table[184],  &pinyin_table[166],  }, /* guang ang => guan gang */
    { &pinyin_table[185],  &pinyin_table[6],    &pinyin_table[184],  &pinyin_table[167],  }, /* guang ao => guan gao */
    { &pinyin_table[185],  &pinyin_table[128],  &pinyin_table[184],  &pinyin_table[168],  }, /* guang e => guan ge */
    { &pinyin_table[185],  &pinyin_table[129],  &pinyin_table[184],  &pinyin_table[170],  }, /* guang ei => guan gei */
    { &pinyin_table[185],  &pinyin_table[130],  &pinyin_table[184],  &pinyin_table[172],  }, /* guang en => guan gen */
    { &pinyin_table[189],  &pinyin_table[4],    &pinyin_table[179],  &pinyin_table[363],  }, /* gun an => gu nan */
    { &pinyin_table[189],  &pinyin_table[5],    &pinyin_table[179],  &pinyin_table[364],  }, /* gun ang => gu nang */
    { &pinyin_table[189],  &pinyin_table[6],    &pinyin_table[179],  &pinyin_table[365],  }, /* gun ao => gu nao */
    { &pinyin_table[189],  &pinyin_table[128],  &pinyin_table[179],  &pinyin_table[366],  }, /* gun e => gu ne */
    { &pinyin_table[189],  &pinyin_table[129],  &pinyin_table[179],  &pinyin_table[368],  }, /* gun ei => gu nei */
    { &pinyin_table[196],  &pinyin_table[5],    &pinyin_table[192],  &pinyin_table[364],  }, /* han ang => ha nang */
    { &pinyin_table[196],  &pinyin_table[6],    &pinyin_table[192],  &pinyin_table[365],  }, /* han ao => ha nao */
    { &pinyin_table[196],  &pinyin_table[129],  &pinyin_table[192],  &pinyin_table[368],  }, /* han ei => ha nei */
    { &pinyin_table[197],  &pinyin_table[2],    &pinyin_table[196],  &pinyin_table[163],  }, /* hang ai => han gai */
    { &pinyin_table[197],  &pinyin_table[5],    &pinyin_table[196],  &pinyin_table[166],  }, /* hang ang => han gang */
    { &pinyin_table[197],  &pinyin_table[6],    &pinyin_table[196],  &pinyin_table[167],  }, /* hang ao => han gao */
    { &pinyin_table[197],  &pinyin_table[128],  &pinyin_table[196],  &pinyin_table[168],  }, /* hang e => han ge */
    { &pinyin_table[197],  &pinyin_table[129],  &pinyin_table[196],  &pinyin_table[170],  }, /* hang ei => han gei */
    { &pinyin_table[197],  &pinyin_table[130],  &pinyin_table[196],  &pinyin_table[172],  }, /* hang en => han gen */
    { &pinyin_table[197],  &pinyin_table[402],  &pinyin_table[196],  &pinyin_table[178],  }, /* hang ou => han gou */
    { &pinyin_table[203],  &pinyin_table[0],    &pinyin_table[199],  &pinyin_table[359],  }, /* hen a => he na */
    { &pinyin_table[203],  &pinyin_table[4],    &pinyin_table[199],  &pinyin_table[363],  }, /* hen an => he nan */
    { &pinyin_table[203],  &pinyin_table[5],    &pinyin_table[199],  &pinyin_table[364],  }, /* hen ang => he nang */
    { &pinyin_table[203],  &pinyin_table[6],    &pinyin_table[199],  &pinyin_table[365],  }, /* hen ao => he nao */
    { &pinyin_table[203],  &pinyin_table[129],  &pinyin_table[199],  &pinyin_table[368],  }, /* hen ei => he nei */
    { &pinyin_table[204],  &pinyin_table[2],    &pinyin_table[203],  &pinyin_table[163],  }, /* heng ai => hen gai */
    { &pinyin_table[204],  &pinyin_table[4],    &pinyin_table[203],  &pinyin_table[165],  }, /* heng an => hen gan */
    { &pinyin_table[204],  &pinyin_table[5],    &pinyin_table[203],  &pinyin_table[166],  }, /* heng ang => hen gang */
    { &pinyin_table[204],  &pinyin_table[6],    &pinyin_table[203],  &pinyin_table[167],  }, /* heng ao => hen gao */
    { &pinyin_table[204],  &pinyin_table[129],  &pinyin_table[203],  &pinyin_table[170],  }, /* heng ei => hen gei */
    { &pinyin_table[204],  &pinyin_table[130],  &pinyin_table[203],  &pinyin_table[172],  }, /* heng en => hen gen */
    { &pinyin_table[204],  &pinyin_table[402],  &pinyin_table[203],  &pinyin_table[178],  }, /* heng ou => hen gou */
    { &pinyin_table[216],  &pinyin_table[0],    &pinyin_table[212],  &pinyin_table[359],  }, /* huan a => hua na */
    { &pinyin_table[216],  &pinyin_table[4],    &pinyin_table[212],  &pinyin_table[363],  }, /* huan an => hua nan */
    { &pinyin_table[216],  &pinyin_table[5],    &pinyin_table[212],  &pinyin_table[364],  }, /* huan ang => hua nang */
    { &pinyin_table[216],  &pinyin_table[6],    &pinyin_table[212],  &pinyin_table[365],  }, /* huan ao => hua nao */
    { &pinyin_table[216],  &pinyin_table[128],  &pinyin_table[212],  &pinyin_table[366],  }, /* huan e => hua ne */
    { &pinyin_table[216],  &pinyin_table[129],  &pinyin_table[212],  &pinyin_table[368],  }, /* huan ei => hua nei */
    { &pinyin_table[216],  &pinyin_table[130],  &pinyin_table[212],  &pinyin_table[370],  }, /* huan en => hua nen */
    { &pinyin_table[217],  &pinyin_table[2],    &pinyin_table[216],  &pinyin_table[163],  }, /* huang ai => huan gai */
    { &pinyin_table[217],  &pinyin_table[5],    &pinyin_table[216],  &pinyin_table[166],  }, /* huang ang => huan gang */
    { &pinyin_table[217],  &pinyin_table[6],    &pinyin_table[216],  &pinyin_table[167],  }, /* huang ao => huan gao */
    { &pinyin_table[217],  &pinyin_table[128],  &pinyin_table[216],  &pinyin_table[168],  }, /* huang e => huan ge */
    { &pinyin_table[217],  &pinyin_table[129],  &pinyin_table[216],  &pinyin_table[170],  }, /* huang ei => huan gei */
    { &pinyin_table[217],  &pinyin_table[402],  &pinyin_table[216],  &pinyin_table[178],  }, /* huang ou => huan gou */
    { &pinyin_table[221],  &pinyin_table[4],    &pinyin_table[211],  &pinyin_table[363],  }, /* hun an => hu nan */
    { &pinyin_table[221],  &pinyin_table[5],    &pinyin_table[211],  &pinyin_table[364],  }, /* hun ang => hu nang */
    { &pinyin_table[221],  &pinyin_table[6],    &pinyin_table[211],  &pinyin_table[365],  }, /* hun ao => hu nao */
    { &pinyin_table[221],  &pinyin_table[129],  &pinyin_table[211],  &pinyin_table[368],  }, /* hun ei => hu nei */
    { &pinyin_table[228],  &pinyin_table[0],    &pinyin_table[225],  &pinyin_table[359],  }, /* jian a => jia na */
    { &pinyin_table[228],  &pinyin_table[2],    &pinyin_table[225],  &pinyin_table[361],  }, /* jian ai => jia nai */
    { &pinyin_table[228],  &pinyin_table[5],    &pinyin_table[225],  &pinyin_table[364],  }, /* jian ang => jia nang */
    { &pinyin_table[228],  &pinyin_table[128],  &pinyin_table[225],  &pinyin_table[366],  }, /* jian e => jia ne */
    { &pinyin_table[228],  &pinyin_table[129],  &pinyin_table[225],  &pinyin_table[368],  }, /* jian ei => jia nei */
    { &pinyin_table[229],  &pinyin_table[5],    &pinyin_table[228],  &pinyin_table[166],  }, /* jiang ang => jian gang */
    { &pinyin_table[229],  &pinyin_table[6],    &pinyin_table[228],  &pinyin_table[167],  }, /* jiang ao => jian gao */
    { &pinyin_table[229],  &pinyin_table[128],  &pinyin_table[228],  &pinyin_table[168],  }, /* jiang e => jian ge */
    { &pinyin_table[229],  &pinyin_table[129],  &pinyin_table[228],  &pinyin_table[170],  }, /* jiang ei => jian gei */
    { &pinyin_table[229],  &pinyin_table[402],  &pinyin_table[228],  &pinyin_table[178],  }, /* jiang ou => jian gou */
    { &pinyin_table[231],  &pinyin_table[459],  &pinyin_table[224],  &pinyin_table[131],  }, /* jie r => ji er */
    { &pinyin_table[234],  &pinyin_table[0],    &pinyin_table[224],  &pinyin_table[359],  }, /* jin a => ji na */
    { &pinyin_table[234],  &pinyin_table[4],    &pinyin_table[224],  &pinyin_table[363],  }, /* jin an => ji nan */
    { &pinyin_table[234],  &pinyin_table[5],    &pinyin_table[224],  &pinyin_table[364],  }, /* jin ang => ji nang */
    { &pinyin_table[234],  &pinyin_table[6],    &pinyin_table[224],  &pinyin_table[365],  }, /* jin ao => ji nao */
    { &pinyin_table[234],  &pinyin_table[129],  &pinyin_table[224],  &pinyin_table[368],  }, /* jin ei => ji nei */
    { &pinyin_table[235],  &pinyin_table[5],    &pinyin_table[234],  &pinyin_table[166],  }, /* jing ang => jin gang */
    { &pinyin_table[235],  &pinyin_table[6],    &pinyin_table[234],  &pinyin_table[167],  }, /* jing ao => jin gao */
    { &pinyin_table[235],  &pinyin_table[129],  &pinyin_table[234],  &pinyin_table[170],  }, /* jing ei => jin gei */
    { &pinyin_table[235],  &pinyin_table[130],  &pinyin_table[234],  &pinyin_table[172],  }, /* jing en => jin gen */
    { &pinyin_table[235],  &pinyin_table[402],  &pinyin_table[234],  &pinyin_table[178],  }, /* jing ou => jin gou */
    { &pinyin_table[244],  &pinyin_table[0],    &pinyin_table[243],  &pinyin_table[161],  }, /* juang a => juan ga */
    { &pinyin_table[244],  &pinyin_table[2],    &pinyin_table[243],  &pinyin_table[163],  }, /* juang ai => juan gai */
    { &pinyin_table[244],  &pinyin_table[4],    &pinyin_table[243],  &pinyin_table[165],  }, /* juang an => juan gan */
    { &pinyin_table[244],  &pinyin_table[5],    &pinyin_table[243],  &pinyin_table[166],  }, /* juang ang => juan gang */
    { &pinyin_table[244],  &pinyin_table[6],    &pinyin_table[243],  &pinyin_table[167],  }, /* juang ao => juan gao */
    { &pinyin_table[244],  &pinyin_table[128],  &pinyin_table[243],  &pinyin_table[168],  }, /* juang e => juan ge */
    { &pinyin_table[244],  &pinyin_table[129],  &pinyin_table[243],  &pinyin_table[170],  }, /* juang ei => juan gei */
    { &pinyin_table[244],  &pinyin_table[130],  &pinyin_table[243],  &pinyin_table[172],  }, /* juang en => juan gen */
    { &pinyin_table[244],  &pinyin_table[402],  &pinyin_table[243],  &pinyin_table[178],  }, /* juang ou => juan gou */
    { &pinyin_table[245],  &pinyin_table[459],  &pinyin_table[242],  &pinyin_table[131],  }, /* jue r => ju er */
    { &pinyin_table[246],  &pinyin_table[0],    &pinyin_table[245],  &pinyin_table[359],  }, /* juen a => jue na */
    { &pinyin_table[246],  &pinyin_table[2],    &pinyin_table[245],  &pinyin_table[361],  }, /* juen ai => jue nai */
    { &pinyin_table[246],  &pinyin_table[4],    &pinyin_table[245],  &pinyin_table[363],  }, /* juen an => jue nan */
    { &pinyin_table[246],  &pinyin_table[5],    &pinyin_table[245],  &pinyin_table[364],  }, /* juen ang => jue nang */
    { &pinyin_table[246],  &pinyin_table[6],    &pinyin_table[245],  &pinyin_table[365],  }, /* juen ao => jue nao */
    { &pinyin_table[246],  &pinyin_table[128],  &pinyin_table[245],  &pinyin_table[366],  }, /* juen e => jue ne */
    { &pinyin_table[246],  &pinyin_table[129],  &pinyin_table[245],  &pinyin_table[368],  }, /* juen ei => jue nei */
    { &pinyin_table[246],  &pinyin_table[130],  &pinyin_table[245],  &pinyin_table[370],  }, /* juen en => jue nen */
    { &pinyin_table[246],  &pinyin_table[402],  &pinyin_table[245],  &pinyin_table[391],  }, /* juen ou => jue nou */
    { &pinyin_table[247],  &pinyin_table[0],    &pinyin_table[242],  &pinyin_table[359],  }, /* jun a => ju na */
    { &pinyin_table[247],  &pinyin_table[2],    &pinyin_table[242],  &pinyin_table[361],  }, /* jun ai => ju nai */
    { &pinyin_table[247],  &pinyin_table[128],  &pinyin_table[242],  &pinyin_table[366],  }, /* jun e => ju ne */
    { &pinyin_table[247],  &pinyin_table[129],  &pinyin_table[242],  &pinyin_table[368],  }, /* jun ei => ju nei */
    { &pinyin_table[259],  &pinyin_table[129],  &pinyin_table[255],  &pinyin_table[368],  }, /* kan ei => ka nei */
    { &pinyin_table[260],  &pinyin_table[4],    &pinyin_table[259],  &pinyin_table[165],  }, /* kang an => kan gan */
    { &pinyin_table[260],  &pinyin_table[5],    &pinyin_table[259],  &pinyin_table[166],  }, /* kang ang => kan gang */
    { &pinyin_table[260],  &pinyin_table[6],    &pinyin_table[259],  &pinyin_table[167],  }, /* kang ao => kan gao */
    { &pinyin_table[260],  &pinyin_table[128],  &pinyin_table[259],  &pinyin_table[168],  }, /* kang e => kan ge */
    { &pinyin_table[260],  &pinyin_table[129],  &pinyin_table[259],  &pinyin_table[170],  }, /* kang ei => kan gei */
    { &pinyin_table[260],  &pinyin_table[130],  &pinyin_table[259],  &pinyin_table[172],  }, /* kang en => kan gen */
    { &pinyin_table[260],  &pinyin_table[402],  &pinyin_table[259],  &pinyin_table[178],  }, /* kang ou => kan gou */
    { &pinyin_table[266],  &pinyin_table[0],    &pinyin_table[262],  &pinyin_table[359],  }, /* ken a => ke na */
    { &pinyin_table[266],  &pinyin_table[2],    &pinyin_table[262],  &pinyin_table[361],  }, /* ken ai => ke nai */
    { &pinyin_table[266],  &pinyin_table[4],    &pinyin_table[262],  &pinyin_table[363],  }, /* ken an => ke nan */
    { &pinyin_table[266],  &pinyin_table[5],    &pinyin_table[262],  &pinyin_table[364],  }, /* ken ang => ke nang */
    { &pinyin_table[266],  &pinyin_table[6],    &pinyin_table[262],  &pinyin_table[365],  }, /* ken ao => ke nao */
    { &pinyin_table[266],  &pinyin_table[128],  &pinyin_table[262],  &pinyin_table[366],  }, /* ken e => ke ne */
    { &pinyin_table[266],  &pinyin_table[129],  &pinyin_table[262],  &pinyin_table[368],  }, /* ken ei => ke nei */
    { &pinyin_table[267],  &pinyin_table[2],    &pinyin_table[266],  &pinyin_table[163],  }, /* keng ai => ken gai */
    { &pinyin_table[267],  &pinyin_table[4],    &pinyin_table[266],  &pinyin_table[165],  }, /* keng an => ken gan */
    { &pinyin_table[267],  &pinyin_table[5],    &pinyin_table[266],  &pinyin_table[166],  }, /* keng ang => ken gang */
    { &pinyin_table[267],  &pinyin_table[6],    &pinyin_table[266],  &pinyin_table[167],  }, /* keng ao => ken gao */
    { &pinyin_table[267],  &pinyin_table[128],  &pinyin_table[266],  &pinyin_table[168],  }, /* keng e => ken ge */
    { &pinyin_table[267],  &pinyin_table[129],  &pinyin_table[266],  &pinyin_table[170],  }, /* keng ei => ken gei */
    { &pinyin_table[267],  &pinyin_table[130],  &pinyin_table[266],  &pinyin_table[172],  }, /* keng en => ken gen */
    { &pinyin_table[267],  &pinyin_table[402],  &pinyin_table[266],  &pinyin_table[178],  }, /* keng ou => ken gou */
    { &pinyin_table[278],  &pinyin_table[0],    &pinyin_table[274],  &pinyin_table[359],  }, /* kuan a => kua na */
    { &pinyin_table[278],  &pinyin_table[129],  &pinyin_table[274],  &pinyin_table[368],  }, /* kuan ei => kua nei */
    { &pinyin_table[279],  &pinyin_table[5],    &pinyin_table[278],  &pinyin_table[166],  }, /* kuang ang => kuan gang */
    { &pinyin_table[279],  &pinyin_table[128],  &pinyin_table[278],  &pinyin_table[168],  }, /* kuang e => kuan ge */
    { &pinyin_table[279],  &pinyin_table[129],  &pinyin_table[278],  &pinyin_table[170],  }, /* kuang ei => kuan gei */
    { &pinyin_table[279],  &pinyin_table[130],  &pinyin_table[278],  &pinyin_table[172],  }, /* kuang en => kuan gen */
    { &pinyin_table[283],  &pinyin_table[4],    &pinyin_table[273],  &pinyin_table[363],  }, /* kun an => ku nan */
    { &pinyin_table[283],  &pinyin_table[5],    &pinyin_table[273],  &pinyin_table[364],  }, /* kun ang => ku nang */
    { &pinyin_table[283],  &pinyin_table[6],    &pinyin_table[273],  &pinyin_table[365],  }, /* kun ao => ku nao */
    { &pinyin_table[283],  &pinyin_table[128],  &pinyin_table[273],  &pinyin_table[366],  }, /* kun e => ku ne */
    { &pinyin_table[283],  &pinyin_table[129],  &pinyin_table[273],  &pinyin_table[368],  }, /* kun ei => ku nei */
    { &pinyin_table[290],  &pinyin_table[0],    &pinyin_table[286],  &pinyin_table[359],  }, /* lan a => la na */
    { &pinyin_table[290],  &pinyin_table[4],    &pinyin_table[286],  &pinyin_table[363],  }, /* lan an => la nan */
    { &pinyin_table[290],  &pinyin_table[5],    &pinyin_table[286],  &pinyin_table[364],  }, /* lan ang => la nang */
    { &pinyin_table[290],  &pinyin_table[6],    &pinyin_table[286],  &pinyin_table[365],  }, /* lan ao => la nao */
    { &pinyin_table[290],  &pinyin_table[128],  &pinyin_table[286],  &pinyin_table[366],  }, /* lan e => la ne */
    { &pinyin_table[290],  &pinyin_table[129],  &pinyin_table[286],  &pinyin_table[368],  }, /* lan ei => la nei */
    { &pinyin_table[291],  &pinyin_table[4],    &pinyin_table[290],  &pinyin_table[165],  }, /* lang an => lan gan */
    { &pinyin_table[291],  &pinyin_table[5],    &pinyin_table[290],  &pinyin_table[166],  }, /* lang ang => lan gang */
    { &pinyin_table[291],  &pinyin_table[6],    &pinyin_table[290],  &pinyin_table[167],  }, /* lang ao => lan gao */
    { &pinyin_table[291],  &pinyin_table[128],  &pinyin_table[290],  &pinyin_table[168],  }, /* lang e => lan ge */
    { &pinyin_table[291],  &pinyin_table[129],  &pinyin_table[290],  &pinyin_table[170],  }, /* lang ei => lan gei */
    { &pinyin_table[291],  &pinyin_table[130],  &pinyin_table[290],  &pinyin_table[172],  }, /* lang en => lan gen */
    { &pinyin_table[291],  &pinyin_table[402],  &pinyin_table[290],  &pinyin_table[178],  }, /* lang ou => lan gou */
    { &pinyin_table[297],  &pinyin_table[0],    &pinyin_table[293],  &pinyin_table[359],  }, /* len a => le na */
    { &pinyin_table[297],  &pinyin_table[2],    &pinyin_table[293],  &pinyin_table[361],  }, /* len ai => le nai */
    { &pinyin_table[297],  &pinyin_table[4],    &pinyin_table[293],  &pinyin_table[363],  }, /* len an => le nan */
    { &pinyin_table[297],  &pinyin_table[5],    &pinyin_table[293],  &pinyin_table[364],  }, /* len ang => le nang */
    { &pinyin_table[297],  &pinyin_table[6],    &pinyin_table[293],  &pinyin_table[365],  }, /* len ao => le nao */
    { &pinyin_table[297],  &pinyin_table[128],  &pinyin_table[293],  &pinyin_table[366],  }, /* len e => le ne */
    { &pinyin_table[297],  &pinyin_table[129],  &pinyin_table[293],  &pinyin_table[368],  }, /* len ei => le nei */
    { &pinyin_table[297],  &pinyin_table[130],  &pinyin_table[293],  &pinyin_table[370],  }, /* len en => le nen */
    { &pinyin_table[297],  &pinyin_table[402],  &pinyin_table[293],  &pinyin_table[391],  }, /* len ou => le nou */
    { &pinyin_table[303],  &pinyin_table[129],  &pinyin_table[300],  &pinyin_table[368],  }, /* lian ei => lia nei */
    { &pinyin_table[304],  &pinyin_table[5],    &pinyin_table[303],  &pinyin_table[166],  }, /* liang ang => lian gang */
    { &pinyin_table[304],  &pinyin_table[6],    &pinyin_table[303],  &pinyin_table[167],  }, /* liang ao => lian gao */
    { &pinyin_table[304],  &pinyin_table[128],  &pinyin_table[303],  &pinyin_table[168],  }, /* liang e => lian ge */
    { &pinyin_table[304],  &pinyin_table[129],  &pinyin_table[303],  &pinyin_table[170],  }, /* liang ei => lian gei */
    { &pinyin_table[304],  &pinyin_table[130],  &pinyin_table[303],  &pinyin_table[172],  }, /* liang en => lian gen */
    { &pinyin_table[304],  &pinyin_table[402],  &pinyin_table[303],  &pinyin_table[178],  }, /* liang ou => lian gou */
    { &pinyin_table[306],  &pinyin_table[459],  &pinyin_table[299],  &pinyin_table[131],  }, /* lie r => li er */
    { &pinyin_table[309],  &pinyin_table[0],    &pinyin_table[299],  &pinyin_table[359],  }, /* lin a => li na */
    { &pinyin_table[309],  &pinyin_table[4],    &pinyin_table[299],  &pinyin_table[363],  }, /* lin an => li nan */
    { &pinyin_table[309],  &pinyin_table[5],    &pinyin_table[299],  &pinyin_table[364],  }, /* lin ang => li nang */
    { &pinyin_table[309],  &pinyin_table[6],    &pinyin_table[299],  &pinyin_table[365],  }, /* lin ao => li nao */
    { &pinyin_table[309],  &pinyin_table[128],  &pinyin_table[299],  &pinyin_table[366],  }, /* lin e => li ne */
    { &pinyin_table[309],  &pinyin_table[129],  &pinyin_table[299],  &pinyin_table[368],  }, /* lin ei => li nei */
    { &pinyin_table[310],  &pinyin_table[5],    &pinyin_table[309],  &pinyin_table[166],  }, /* ling ang => lin gang */
    { &pinyin_table[310],  &pinyin_table[6],    &pinyin_table[309],  &pinyin_table[167],  }, /* ling ao => lin gao */
    { &pinyin_table[310],  &pinyin_table[128],  &pinyin_table[309],  &pinyin_table[168],  }, /* ling e => lin ge */
    { &pinyin_table[310],  &pinyin_table[129],  &pinyin_table[309],  &pinyin_table[170],  }, /* ling ei => lin gei */
    { &pinyin_table[310],  &pinyin_table[130],  &pinyin_table[309],  &pinyin_table[172],  }, /* ling en => lin gen */
    { &pinyin_table[310],  &pinyin_table[402],  &pinyin_table[309],  &pinyin_table[178],  }, /* ling ou => lin gou */
    { &pinyin_table[316],  &pinyin_table[0],    &pinyin_table[313],  &pinyin_table[359],  }, /* lon a => lo na */
    { &pinyin_table[316],  &pinyin_table[2],    &pinyin_table[313],  &pinyin_table[361],  }, /* lon ai => lo nai */
    { &pinyin_table[316],  &pinyin_table[4],    &pinyin_table[313],  &pinyin_table[363],  }, /* lon an => lo nan */
    { &pinyin_table[316],  &pinyin_table[5],    &pinyin_table[313],  &pinyin_table[364],  }, /* lon ang => lo nang */
    { &pinyin_table[316],  &pinyin_table[6],    &pinyin_table[313],  &pinyin_table[365],  }, /* lon ao => lo nao */
    { &pinyin_table[316],  &pinyin_table[128],  &pinyin_table[313],  &pinyin_table[366],  }, /* lon e => lo ne */
    { &pinyin_table[316],  &pinyin_table[129],  &pinyin_table[313],  &pinyin_table[368],  }, /* lon ei => lo nei */
    { &pinyin_table[316],  &pinyin_table[130],  &pinyin_table[313],  &pinyin_table[370],  }, /* lon en => lo nen */
    { &pinyin_table[316],  &pinyin_table[402],  &pinyin_table[313],  &pinyin_table[391],  }, /* lon ou => lo nou */
    { &pinyin_table[321],  &pinyin_table[0],    &pinyin_table[320],  &pinyin_table[161],  }, /* luang a => luan ga */
    { &pinyin_table[321],  &pinyin_table[2],    &pinyin_table[320],  &pinyin_table[163],  }, /* luang ai => luan gai */
    { &pinyin_table[321],  &pinyin_table[4],    &pinyin_table[320],  &pinyin_table[165],  }, /* luang an => luan gan */
    { &pinyin_table[321],  &pinyin_table[5],    &pinyin_table[320],  &pinyin_table[166],  }, /* luang ang => luan gang */
    { &pinyin_table[321],  &pinyin_table[6],    &pinyin_table[320],  &pinyin_table[167],  }, /* luang ao => luan gao */
    { &pinyin_table[321],  &pinyin_table[128],  &pinyin_table[320],  &pinyin_table[168],  }, /* luang e => luan ge */
    { &pinyin_table[321],  &pinyin_table[129],  &pinyin_table[320],  &pinyin_table[170],  }, /* luang ei => luan gei */
    { &pinyin_table[321],  &pinyin_table[130],  &pinyin_table[320],  &pinyin_table[172],  }, /* luang en => luan gen */
    { &pinyin_table[321],  &pinyin_table[402],  &pinyin_table[320],  &pinyin_table[178],  }, /* luang ou => luan gou */
    { &pinyin_table[322],  &pinyin_table[459],  &pinyin_table[319],  &pinyin_table[131],  }, /* lue r => lu er */
    { &pinyin_table[326],  &pinyin_table[0],    &pinyin_table[319],  &pinyin_table[359],  }, /* lun a => lu na */
    { &pinyin_table[326],  &pinyin_table[2],    &pinyin_table[319],  &pinyin_table[361],  }, /* lun ai => lu nai */
    { &pinyin_table[326],  &pinyin_table[4],    &pinyin_table[319],  &pinyin_table[363],  }, /* lun an => lu nan */
    { &pinyin_table[326],  &pinyin_table[5],    &pinyin_table[319],  &pinyin_table[364],  }, /* lun ang => lu nang */
    { &pinyin_table[326],  &pinyin_table[6],    &pinyin_table[319],  &pinyin_table[365],  }, /* lun ao => lu nao */
    { &pinyin_table[326],  &pinyin_table[128],  &pinyin_table[319],  &pinyin_table[366],  }, /* lun e => lu ne */
    { &pinyin_table[326],  &pinyin_table[129],  &pinyin_table[319],  &pinyin_table[368],  }, /* lun ei => lu nei */
    { &pinyin_table[329],  &pinyin_table[459],  &pinyin_table[328],  &pinyin_table[131],  }, /* lve r => lv er */
    { &pinyin_table[335],  &pinyin_table[2],    &pinyin_table[331],  &pinyin_table[361],  }, /* man ai => ma nai */
    { &pinyin_table[335],  &pinyin_table[4],    &pinyin_table[331],  &pinyin_table[363],  }, /* man an => ma nan */
    { &pinyin_table[335],  &pinyin_table[5],    &pinyin_table[331],  &pinyin_table[364],  }, /* man ang => ma nang */
    { &pinyin_table[335],  &pinyin_table[6],    &pinyin_table[331],  &pinyin_table[365],  }, /* man ao => ma nao */
    { &pinyin_table[335],  &pinyin_table[128],  &pinyin_table[331],  &pinyin_table[366],  }, /* man e => ma ne */
    { &pinyin_table[335],  &pinyin_table[129],  &pinyin_table[331],  &pinyin_table[368],  }, /* man ei => ma nei */
    { &pinyin_table[336],  &pinyin_table[2],    &pinyin_table[335],  &pinyin_table[163],  }, /* mang ai => man gai */
    { &pinyin_table[336],  &pinyin_table[4],    &pinyin_table[335],  &pinyin_table[165],  }, /* mang an => man gan */
    { &pinyin_table[336],  &pinyin_table[5],    &pinyin_table[335],  &pinyin_table[166],  }, /* mang ang => man gang */
    { &pinyin_table[336],  &pinyin_table[6],    &pinyin_table[335],  &pinyin_table[167],  }, /* mang ao => man gao */
    { &pinyin_table[336],  &pinyin_table[128],  &pinyin_table[335],  &pinyin_table[168],  }, /* mang e => man ge */
    { &pinyin_table[336],  &pinyin_table[129],  &pinyin_table[335],  &pinyin_table[170],  }, /* mang ei => man gei */
    { &pinyin_table[336],  &pinyin_table[130],  &pinyin_table[335],  &pinyin_table[172],  }, /* mang en => man gen */
    { &pinyin_table[336],  &pinyin_table[402],  &pinyin_table[335],  &pinyin_table[178],  }, /* mang ou => man gou */
    { &pinyin_table[342],  &pinyin_table[5],    &pinyin_table[338],  &pinyin_table[364],  }, /* men ang => me nang */
    { &pinyin_table[342],  &pinyin_table[6],    &pinyin_table[338],  &pinyin_table[365],  }, /* men ao => me nao */
    { &pinyin_table[342],  &pinyin_table[128],  &pinyin_table[338],  &pinyin_table[366],  }, /* men e => me ne */
    { &pinyin_table[342],  &pinyin_table[129],  &pinyin_table[338],  &pinyin_table[368],  }, /* men ei => me nei */
    { &pinyin_table[343],  &pinyin_table[2],    &pinyin_table[342],  &pinyin_table[163],  }, /* meng ai => men gai */
    { &pinyin_table[343],  &pinyin_table[5],    &pinyin_table[342],  &pinyin_table[166],  }, /* meng ang => men gang */
    { &pinyin_table[343],  &pinyin_table[6],    &pinyin_table[342],  &pinyin_table[167],  }, /* meng ao => men gao */
    { &pinyin_table[343],  &pinyin_table[128],  &pinyin_table[342],  &pinyin_table[168],  }, /* meng e => men ge */
    { &pinyin_table[343],  &pinyin_table[129],  &pinyin_table[342],  &pinyin_table[170],  }, /* meng ei => men gei */
    { &pinyin_table[343],  &pinyin_table[402],  &pinyin_table[342],  &pinyin_table[178],  }, /* meng ou => men gou */
    { &pinyin_table[346],  &pinyin_table[0],    &pinyin_table[345],  &pinyin_table[161],  }, /* miang a => mian ga */
    { &pinyin_table[346],  &pinyin_table[2],    &pinyin_table[345],  &pinyin_table[163],  }, /* miang ai => mian gai */
    { &pinyin_table[346],  &pinyin_table[4],    &pinyin_table[345],  &pinyin_table[165],  }, /* miang an => mian gan */
    { &pinyin_table[346],  &pinyin_table[5],    &pinyin_table[345],  &pinyin_table[166],  }, /* miang ang => mian gang */
    { &pinyin_table[346],  &pinyin_table[6],    &pinyin_table[345],  &pinyin_table[167],  }, /* miang ao => mian gao */
    { &pinyin_table[346],  &pinyin_table[128],  &pinyin_table[345],  &pinyin_table[168],  }, /* miang e => mian ge */
    { &pinyin_table[346],  &pinyin_table[129],  &pinyin_table[345],  &pinyin_table[170],  }, /* miang ei => mian gei */
    { &pinyin_table[346],  &pinyin_table[130],  &pinyin_table[345],  &pinyin_table[172],  }, /* miang en => mian gen */
    { &pinyin_table[346],  &pinyin_table[402],  &pinyin_table[345],  &pinyin_table[178],  }, /* miang ou => mian gou */
    { &pinyin_table[348],  &pinyin_table[459],  &pinyin_table[344],  &pinyin_table[131],  }, /* mie r => mi er */
    { &pinyin_table[351],  &pinyin_table[0],    &pinyin_table[344],  &pinyin_table[359],  }, /* min a => mi na */
    { &pinyin_table[351],  &pinyin_table[128],  &pinyin_table[344],  &pinyin_table[366],  }, /* min e => mi ne */
    { &pinyin_table[351],  &pinyin_table[129],  &pinyin_table[344],  &pinyin_table[368],  }, /* min ei => mi nei */
    { &pinyin_table[352],  &pinyin_table[4],    &pinyin_table[351],  &pinyin_table[165],  }, /* ming an => min gan */
    { &pinyin_table[352],  &pinyin_table[5],    &pinyin_table[351],  &pinyin_table[166],  }, /* ming ang => min gang */
    { &pinyin_table[352],  &pinyin_table[6],    &pinyin_table[351],  &pinyin_table[167],  }, /* ming ao => min gao */
    { &pinyin_table[352],  &pinyin_table[128],  &pinyin_table[351],  &pinyin_table[168],  }, /* ming e => min ge */
    { &pinyin_table[352],  &pinyin_table[129],  &pinyin_table[351],  &pinyin_table[170],  }, /* ming ei => min gei */
    { &pinyin_table[352],  &pinyin_table[402],  &pinyin_table[351],  &pinyin_table[178],  }, /* ming ou => min gou */
    { &pinyin_table[363],  &pinyin_table[0],    &pinyin_table[359],  &pinyin_table[359],  }, /* nan a => na na */
    { &pinyin_table[363],  &pinyin_table[5],    &pinyin_table[359],  &pinyin_table[364],  }, /* nan ang => na nang */
    { &pinyin_table[363],  &pinyin_table[128],  &pinyin_table[359],  &pinyin_table[366],  }, /* nan e => na ne */
    { &pinyin_table[363],  &pinyin_table[129],  &pinyin_table[359],  &pinyin_table[368],  }, /* nan ei => na nei */
    { &pinyin_table[364],  &pinyin_table[0],    &pinyin_table[363],  &pinyin_table[161],  }, /* nang a => nan ga */
    { &pinyin_table[364],  &pinyin_table[2],    &pinyin_table[363],  &pinyin_table[163],  }, /* nang ai => nan gai */
    { &pinyin_table[364],  &pinyin_table[4],    &pinyin_table[363],  &pinyin_table[165],  }, /* nang an => nan gan */
    { &pinyin_table[364],  &pinyin_table[5],    &pinyin_table[363],  &pinyin_table[166],  }, /* nang ang => nan gang */
    { &pinyin_table[364],  &pinyin_table[6],    &pinyin_table[363],  &pinyin_table[167],  }, /* nang ao => nan gao */
    { &pinyin_table[364],  &pinyin_table[128],  &pinyin_table[363],  &pinyin_table[168],  }, /* nang e => nan ge */
    { &pinyin_table[364],  &pinyin_table[129],  &pinyin_table[363],  &pinyin_table[170],  }, /* nang ei => nan gei */
    { &pinyin_table[364],  &pinyin_table[130],  &pinyin_table[363],  &pinyin_table[172],  }, /* nang en => nan gen */
    { &pinyin_table[364],  &pinyin_table[402],  &pinyin_table[363],  &pinyin_table[178],  }, /* nang ou => nan gou */
    { &pinyin_table[370],  &pinyin_table[0],    &pinyin_table[366],  &pinyin_table[359],  }, /* nen a => ne na */
    { &pinyin_table[370],  &pinyin_table[2],    &pinyin_table[366],  &pinyin_table[361],  }, /* nen ai => ne nai */
    { &pinyin_table[370],  &pinyin_table[4],    &pinyin_table[366],  &pinyin_table[363],  }, /* nen an => ne nan */
    { &pinyin_table[370],  &pinyin_table[5],    &pinyin_table[366],  &pinyin_table[364],  }, /* nen ang => ne nang */
    { &pinyin_table[370],  &pinyin_table[6],    &pinyin_table[366],  &pinyin_table[365],  }, /* nen ao => ne nao */
    { &pinyin_table[370],  &pinyin_table[128],  &pinyin_table[366],  &pinyin_table[366],  }, /* nen e => ne ne */
    { &pinyin_table[370],  &pinyin_table[129],  &pinyin_table[366],  &pinyin_table[368],  }, /* nen ei => ne nei */
    { &pinyin_table[370],  &pinyin_table[130],  &pinyin_table[366],  &pinyin_table[370],  }, /* nen en => ne nen */
    { &pinyin_table[371],  &pinyin_table[128],  &pinyin_table[370],  &pinyin_table[168],  }, /* neng e => nen ge */
    { &pinyin_table[371],  &pinyin_table[129],  &pinyin_table[370],  &pinyin_table[170],  }, /* neng ei => nen gei */
    { &pinyin_table[377],  &pinyin_table[2],    &pinyin_table[376],  &pinyin_table[163],  }, /* niang ai => nian gai */
    { &pinyin_table[377],  &pinyin_table[4],    &pinyin_table[376],  &pinyin_table[165],  }, /* niang an => nian gan */
    { &pinyin_table[377],  &pinyin_table[5],    &pinyin_table[376],  &pinyin_table[166],  }, /* niang ang => nian gang */
    { &pinyin_table[377],  &pinyin_table[6],    &pinyin_table[376],  &pinyin_table[167],  }, /* niang ao => nian gao */
    { &pinyin_table[377],  &pinyin_table[128],  &pinyin_table[376],  &pinyin_table[168],  }, /* niang e => nian ge */
    { &pinyin_table[377],  &pinyin_table[129],  &pinyin_table[376],  &pinyin_table[170],  }, /* niang ei => nian gei */
    { &pinyin_table[377],  &pinyin_table[130],  &pinyin_table[376],  &pinyin_table[172],  }, /* niang en => nian gen */
    { &pinyin_table[377],  &pinyin_table[402],  &pinyin_table[376],  &pinyin_table[178],  }, /* niang ou => nian gou */
    { &pinyin_table[379],  &pinyin_table[459],  &pinyin_table[372],  &pinyin_table[131],  }, /* nie r => ni er */
    { &pinyin_table[382],  &pinyin_table[0],    &pinyin_table[372],  &pinyin_table[359],  }, /* nin a => ni na */
    { &pinyin_table[382],  &pinyin_table[4],    &pinyin_table[372],  &pinyin_table[363],  }, /* nin an => ni nan */
    { &pinyin_table[382],  &pinyin_table[5],    &pinyin_table[372],  &pinyin_table[364],  }, /* nin ang => ni nang */
    { &pinyin_table[382],  &pinyin_table[6],    &pinyin_table[372],  &pinyin_table[365],  }, /* nin ao => ni nao */
    { &pinyin_table[382],  &pinyin_table[128],  &pinyin_table[372],  &pinyin_table[366],  }, /* nin e => ni ne */
    { &pinyin_table[382],  &pinyin_table[129],  &pinyin_table[372],  &pinyin_table[368],  }, /* nin ei => ni nei */
    { &pinyin_table[383],  &pinyin_table[2],    &pinyin_table[382],  &pinyin_table[163],  }, /* ning ai => nin gai */
    { &pinyin_table[383],  &pinyin_table[5],    &pinyin_table[382],  &pinyin_table[166],  }, /* ning ang => nin gang */
    { &pinyin_table[383],  &pinyin_table[6],    &pinyin_table[382],  &pinyin_table[167],  }, /* ning ao => nin gao */
    { &pinyin_table[383],  &pinyin_table[129],  &pinyin_table[382],  &pinyin_table[170],  }, /* ning ei => nin gei */
    { &pinyin_table[383],  &pinyin_table[130],  &pinyin_table[382],  &pinyin_table[172],  }, /* ning en => nin gen */
    { &pinyin_table[383],  &pinyin_table[402],  &pinyin_table[382],  &pinyin_table[178],  }, /* ning ou => nin gou */
    { &pinyin_table[394],  &pinyin_table[0],    &pinyin_table[393],  &pinyin_table[161],  }, /* nuang a => nuan ga */
    { &pinyin_table[394],  &pinyin_table[2],    &pinyin_table[393],  &pinyin_table[163],  }, /* nuang ai => nuan gai */
    { &pinyin_table[394],  &pinyin_table[4],    &pinyin_table[393],  &pinyin_table[165],  }, /* nuang an => nuan gan */
    { &pinyin_table[394],  &pinyin_table[5],    &pinyin_table[393],  &pinyin_table[166],  }, /* nuang ang => nuan gang */
    { &pinyin_table[394],  &pinyin_table[6],    &pinyin_table[393],  &pinyin_table[167],  }, /* nuang ao => nuan gao */
    { &pinyin_table[394],  &pinyin_table[128],  &pinyin_table[393],  &pinyin_table[168],  }, /* nuang e => nuan ge */
    { &pinyin_table[394],  &pinyin_table[129],  &pinyin_table[393],  &pinyin_table[170],  }, /* nuang ei => nuan gei */
    { &pinyin_table[394],  &pinyin_table[130],  &pinyin_table[393],  &pinyin_table[172],  }, /* nuang en => nuan gen */
    { &pinyin_table[394],  &pinyin_table[402],  &pinyin_table[393],  &pinyin_table[178],  }, /* nuang ou => nuan gou */
    { &pinyin_table[395],  &pinyin_table[459],  &pinyin_table[392],  &pinyin_table[131],  }, /* nue r => nu er */
    { &pinyin_table[397],  &pinyin_table[0],    &pinyin_table[392],  &pinyin_table[359],  }, /* nun a => nu na */
    { &pinyin_table[397],  &pinyin_table[2],    &pinyin_table[392],  &pinyin_table[361],  }, /* nun ai => nu nai */
    { &pinyin_table[397],  &pinyin_table[4],    &pinyin_table[392],  &pinyin_table[363],  }, /* nun an => nu nan */
    { &pinyin_table[397],  &pinyin_table[5],    &pinyin_table[392],  &pinyin_table[364],  }, /* nun ang => nu nang */
    { &pinyin_table[397],  &pinyin_table[6],    &pinyin_table[392],  &pinyin_table[365],  }, /* nun ao => nu nao */
    { &pinyin_table[397],  &pinyin_table[128],  &pinyin_table[392],  &pinyin_table[366],  }, /* nun e => nu ne */
    { &pinyin_table[397],  &pinyin_table[129],  &pinyin_table[392],  &pinyin_table[368],  }, /* nun ei => nu nei */
    { &pinyin_table[397],  &pinyin_table[130],  &pinyin_table[392],  &pinyin_table[370],  }, /* nun en => nu nen */
    { &pinyin_table[397],  &pinyin_table[402],  &pinyin_table[392],  &pinyin_table[391],  }, /* nun ou => nu nou */
    { &pinyin_table[400],  &pinyin_table[459],  &pinyin_table[399],  &pinyin_table[131],  }, /* nve r => nv er */
    { &pinyin_table[408],  &pinyin_table[0],    &pinyin_table[404],  &pinyin_table[359],  }, /* pan a => pa na */
    { &pinyin_table[408],  &pinyin_table[5],    &pinyin_table[404],  &pinyin_table[364],  }, /* pan ang => pa nang */
    { &pinyin_table[408],  &pinyin_table[6],    &pinyin_table[404],  &pinyin_table[365],  }, /* pan ao => pa nao */
    { &pinyin_table[408],  &pinyin_table[128],  &pinyin_table[404],  &pinyin_table[366],  }, /* pan e => pa ne */
    { &pinyin_table[408],  &pinyin_table[129],  &pinyin_table[404],  &pinyin_table[368],  }, /* pan ei => pa nei */
    { &pinyin_table[409],  &pinyin_table[5],    &pinyin_table[408],  &pinyin_table[166],  }, /* pang ang => pan gang */
    { &pinyin_table[409],  &pinyin_table[6],    &pinyin_table[408],  &pinyin_table[167],  }, /* pang ao => pan gao */
    { &pinyin_table[409],  &pinyin_table[128],  &pinyin_table[408],  &pinyin_table[168],  }, /* pang e => pan ge */
    { &pinyin_table[409],  &pinyin_table[129],  &pinyin_table[408],  &pinyin_table[170],  }, /* pang ei => pan gei */
    { &pinyin_table[409],  &pinyin_table[130],  &pinyin_table[408],  &pinyin_table[172],  }, /* pang en => pan gen */
    { &pinyin_table[409],  &pinyin_table[402],  &pinyin_table[408],  &pinyin_table[178],  }, /* pang ou => pan gou */
    { &pinyin_table[415],  &pinyin_table[5],    &pinyin_table[414],  &pinyin_table[166],  }, /* peng ang => pen gang */
    { &pinyin_table[415],  &pinyin_table[6],    &pinyin_table[414],  &pinyin_table[167],  }, /* peng ao => pen gao */
    { &pinyin_table[415],  &pinyin_table[128],  &pinyin_table[414],  &pinyin_table[168],  }, /* peng e => pen ge */
    { &pinyin_table[415],  &pinyin_table[129],  &pinyin_table[414],  &pinyin_table[170],  }, /* peng ei => pen gei */
    { &pinyin_table[418],  &pinyin_table[0],    &pinyin_table[417],  &pinyin_table[161],  }, /* piang a => pian ga */
    { &pinyin_table[418],  &pinyin_table[2],    &pinyin_table[417],  &pinyin_table[163],  }, /* piang ai => pian gai */
    { &pinyin_table[418],  &pinyin_table[4],    &pinyin_table[417],  &pinyin_table[165],  }, /* piang an => pian gan */
    { &pinyin_table[418],  &pinyin_table[5],    &pinyin_table[417],  &pinyin_table[166],  }, /* piang ang => pian gang */
    { &pinyin_table[418],  &pinyin_table[6],    &pinyin_table[417],  &pinyin_table[167],  }, /* piang ao => pian gao */
    { &pinyin_table[418],  &pinyin_table[128],  &pinyin_table[417],  &pinyin_table[168],  }, /* piang e => pian ge */
    { &pinyin_table[418],  &pinyin_table[129],  &pinyin_table[417],  &pinyin_table[170],  }, /* piang ei => pian gei */
    { &pinyin_table[418],  &pinyin_table[130],  &pinyin_table[417],  &pinyin_table[172],  }, /* piang en => pian gen */
    { &pinyin_table[418],  &pinyin_table[402],  &pinyin_table[417],  &pinyin_table[178],  }, /* piang ou => pian gou */
    { &pinyin_table[420],  &pinyin_table[459],  &pinyin_table[416],  &pinyin_table[131],  }, /* pie r => pi er */
    { &pinyin_table[423],  &pinyin_table[0],    &pinyin_table[416],  &pinyin_table[359],  }, /* pin a => pi na */
    { &pinyin_table[423],  &pinyin_table[5],    &pinyin_table[416],  &pinyin_table[364],  }, /* pin ang => pi nang */
    { &pinyin_table[423],  &pinyin_table[6],    &pinyin_table[416],  &pinyin_table[365],  }, /* pin ao => pi nao */
    { &pinyin_table[423],  &pinyin_table[128],  &pinyin_table[416],  &pinyin_table[366],  }, /* pin e => pi ne */
    { &pinyin_table[423],  &pinyin_table[129],  &pinyin_table[416],  &pinyin_table[368],  }, /* pin ei => pi nei */
    { &pinyin_table[424],  &pinyin_table[5],    &pinyin_table[423],  &pinyin_table[166],  }, /* ping ang => pin gang */
    { &pinyin_table[424],  &pinyin_table[6],    &pinyin_table[423],  &pinyin_table[167],  }, /* ping ao => pin gao */
    { &pinyin_table[424],  &pinyin_table[128],  &pinyin_table[423],  &pinyin_table[168],  }, /* ping e => pin ge */
    { &pinyin_table[424],  &pinyin_table[129],  &pinyin_table[423],  &pinyin_table[170],  }, /* ping ei => pin gei */
    { &pinyin_table[424],  &pinyin_table[130],  &pinyin_table[423],  &pinyin_table[172],  }, /* ping en => pin gen */
    { &pinyin_table[424],  &pinyin_table[402],  &pinyin_table[423],  &pinyin_table[178],  }, /* ping ou => pin gou */
    { &pinyin_table[433],  &pinyin_table[129],  &pinyin_table[430],  &pinyin_table[368],  }, /* qian ei => qia nei */
    { &pinyin_table[434],  &pinyin_table[2],    &pinyin_table[433],  &pinyin_table[163],  }, /* qiang ai => qian gai */
    { &pinyin_table[434],  &pinyin_table[4],    &pinyin_table[433],  &pinyin_table[165],  }, /* qiang an => qian gan */
    { &pinyin_table[434],  &pinyin_table[5],    &pinyin_table[433],  &pinyin_table[166],  }, /* qiang ang => qian gang */
    { &pinyin_table[434],  &pinyin_table[6],    &pinyin_table[433],  &pinyin_table[167],  }, /* qiang ao => qian gao */
    { &pinyin_table[434],  &pinyin_table[128],  &pinyin_table[433],  &pinyin_table[168],  }, /* qiang e => qian ge */
    { &pinyin_table[434],  &pinyin_table[129],  &pinyin_table[433],  &pinyin_table[170],  }, /* qiang ei => qian gei */
    { &pinyin_table[434],  &pinyin_table[130],  &pinyin_table[433],  &pinyin_table[172],  }, /* qiang en => qian gen */
    { &pinyin_table[434],  &pinyin_table[402],  &pinyin_table[433],  &pinyin_table[178],  }, /* qiang ou => qian gou */
    { &pinyin_table[436],  &pinyin_table[459],  &pinyin_table[429],  &pinyin_table[131],  }, /* qie r => qi er */
    { &pinyin_table[439],  &pinyin_table[0],    &pinyin_table[429],  &pinyin_table[359],  }, /* qin a => qi na */
    { &pinyin_table[439],  &pinyin_table[5],    &pinyin_table[429],  &pinyin_table[364],  }, /* qin ang => qi nang */
    { &pinyin_table[439],  &pinyin_table[6],    &pinyin_table[429],  &pinyin_table[365],  }, /* qin ao => qi nao */
    { &pinyin_table[439],  &pinyin_table[128],  &pinyin_table[429],  &pinyin_table[366],  }, /* qin e => qi ne */
    { &pinyin_table[439],  &pinyin_table[129],  &pinyin_table[429],  &pinyin_table[368],  }, /* qin ei => qi nei */
    { &pinyin_table[440],  &pinyin_table[5],    &pinyin_table[439],  &pinyin_table[166],  }, /* qing ang => qin gang */
    { &pinyin_table[440],  &pinyin_table[6],    &pinyin_table[439],  &pinyin_table[167],  }, /* qing ao => qin gao */
    { &pinyin_table[440],  &pinyin_table[128],  &pinyin_table[439],  &pinyin_table[168],  }, /* qing e => qin ge */
    { &pinyin_table[440],  &pinyin_table[129],  &pinyin_table[439],  &pinyin_table[170],  }, /* qing ei => qin gei */
    { &pinyin_table[440],  &pinyin_table[130],  &pinyin_table[439],  &pinyin_table[172],  }, /* qing en => qin gen */
    { &pinyin_table[440],  &pinyin_table[402],  &pinyin_table[439],  &pinyin_table[178],  }, /* qing ou => qin gou */
    { &pinyin_table[449],  &pinyin_table[0],    &pinyin_table[448],  &pinyin_table[161],  }, /* quang a => quan ga */
    { &pinyin_table[449],  &pinyin_table[2],    &pinyin_table[448],  &pinyin_table[163],  }, /* quang ai => quan gai */
    { &pinyin_table[449],  &pinyin_table[4],    &pinyin_table[448],  &pinyin_table[165],  }, /* quang an => quan gan */
    { &pinyin_table[449],  &pinyin_table[5],    &pinyin_table[448],  &pinyin_table[166],  }, /* quang ang => quan gang */
    { &pinyin_table[449],  &pinyin_table[6],    &pinyin_table[448],  &pinyin_table[167],  }, /* quang ao => quan gao */
    { &pinyin_table[449],  &pinyin_table[128],  &pinyin_table[448],  &pinyin_table[168],  }, /* quang e => quan ge */
    { &pinyin_table[449],  &pinyin_table[129],  &pinyin_table[448],  &pinyin_table[170],  }, /* quang ei => quan gei */
    { &pinyin_table[449],  &pinyin_table[130],  &pinyin_table[448],  &pinyin_table[172],  }, /* quang en => quan gen */
    { &pinyin_table[449],  &pinyin_table[402],  &pinyin_table[448],  &pinyin_table[178],  }, /* quang ou => quan gou */
    { &pinyin_table[450],  &pinyin_table[459],  &pinyin_table[447],  &pinyin_table[131],  }, /* que r => qu er */
    { &pinyin_table[451],  &pinyin_table[0],    &pinyin_table[450],  &pinyin_table[359],  }, /* quen a => que na */
    { &pinyin_table[451],  &pinyin_table[2],    &pinyin_table[450],  &pinyin_table[361],  }, /* quen ai => que nai */
    { &pinyin_table[451],  &pinyin_table[4],    &pinyin_table[450],  &pinyin_table[363],  }, /* quen an => que nan */
    { &pinyin_table[451],  &pinyin_table[5],    &pinyin_table[450],  &pinyin_table[364],  }, /* quen ang => que nang */
    { &pinyin_table[451],  &pinyin_table[6],    &pinyin_table[450],  &pinyin_table[365],  }, /* quen ao => que nao */
    { &pinyin_table[451],  &pinyin_table[128],  &pinyin_table[450],  &pinyin_table[366],  }, /* quen e => que ne */
    { &pinyin_table[451],  &pinyin_table[129],  &pinyin_table[450],  &pinyin_table[368],  }, /* quen ei => que nei */
    { &pinyin_table[451],  &pinyin_table[130],  &pinyin_table[450],  &pinyin_table[370],  }, /* quen en => que nen */
    { &pinyin_table[451],  &pinyin_table[402],  &pinyin_table[450],  &pinyin_table[391],  }, /* quen ou => que nou */
    { &pinyin_table[452],  &pinyin_table[0],    &pinyin_table[447],  &pinyin_table[359],  }, /* qun a => qu na */
    { &pinyin_table[452],  &pinyin_table[4],    &pinyin_table[447],  &pinyin_table[363],  }, /* qun an => qu nan */
    { &pinyin_table[452],  &pinyin_table[5],    &pinyin_table[447],  &pinyin_table[364],  }, /* qun ang => qu nang */
    { &pinyin_table[452],  &pinyin_table[6],    &pinyin_table[447],  &pinyin_table[365],  }, /* qun ao => qu nao */
    { &pinyin_table[452],  &pinyin_table[128],  &pinyin_table[447],  &pinyin_table[366],  }, /* qun e => qu ne */
    { &pinyin_table[452],  &pinyin_table[129],  &pinyin_table[447],  &pinyin_table[368],  }, /* qun ei => qu nei */
    { &pinyin_table[465],  &pinyin_table[5],    &pinyin_table[464],  &pinyin_table[166],  }, /* rang ang => ran gang */
    { &pinyin_table[465],  &pinyin_table[6],    &pinyin_table[464],  &pinyin_table[167],  }, /* rang ao => ran gao */
    { &pinyin_table[465],  &pinyin_table[129],  &pinyin_table[464],  &pinyin_table[170],  }, /* rang ei => ran gei */
    { &pinyin_table[465],  &pinyin_table[130],  &pinyin_table[464],  &pinyin_table[172],  }, /* rang en => ran gen */
    { &pinyin_table[471],  &pinyin_table[6],    &pinyin_table[467],  &pinyin_table[365],  }, /* ren ao => re nao */
    { &pinyin_table[471],  &pinyin_table[128],  &pinyin_table[467],  &pinyin_table[366],  }, /* ren e => re ne */
    { &pinyin_table[471],  &pinyin_table[129],  &pinyin_table[467],  &pinyin_table[368],  }, /* ren ei => re nei */
    { &pinyin_table[472],  &pinyin_table[0],    &pinyin_table[471],  &pinyin_table[161],  }, /* reng a => ren ga */
    { &pinyin_table[472],  &pinyin_table[2],    &pinyin_table[471],  &pinyin_table[163],  }, /* reng ai => ren gai */
    { &pinyin_table[472],  &pinyin_table[4],    &pinyin_table[471],  &pinyin_table[165],  }, /* reng an => ren gan */
    { &pinyin_table[472],  &pinyin_table[5],    &pinyin_table[471],  &pinyin_table[166],  }, /* reng ang => ren gang */
    { &pinyin_table[472],  &pinyin_table[6],    &pinyin_table[471],  &pinyin_table[167],  }, /* reng ao => ren gao */
    { &pinyin_table[472],  &pinyin_table[128],  &pinyin_table[471],  &pinyin_table[168],  }, /* reng e => ren ge */
    { &pinyin_table[472],  &pinyin_table[129],  &pinyin_table[471],  &pinyin_table[170],  }, /* reng ei => ren gei */
    { &pinyin_table[472],  &pinyin_table[130],  &pinyin_table[471],  &pinyin_table[172],  }, /* reng en => ren gen */
    { &pinyin_table[472],  &pinyin_table[402],  &pinyin_table[471],  &pinyin_table[178],  }, /* reng ou => ren gou */
    { &pinyin_table[478],  &pinyin_table[459],  &pinyin_table[473],  &pinyin_table[131],  }, /* rie r => ri er */
    { &pinyin_table[479],  &pinyin_table[0],    &pinyin_table[473],  &pinyin_table[359],  }, /* rin a => ri na */
    { &pinyin_table[479],  &pinyin_table[2],    &pinyin_table[473],  &pinyin_table[361],  }, /* rin ai => ri nai */
    { &pinyin_table[479],  &pinyin_table[4],    &pinyin_table[473],  &pinyin_table[363],  }, /* rin an => ri nan */
    { &pinyin_table[479],  &pinyin_table[5],    &pinyin_table[473],  &pinyin_table[364],  }, /* rin ang => ri nang */
    { &pinyin_table[479],  &pinyin_table[6],    &pinyin_table[473],  &pinyin_table[365],  }, /* rin ao => ri nao */
    { &pinyin_table[479],  &pinyin_table[128],  &pinyin_table[473],  &pinyin_table[366],  }, /* rin e => ri ne */
    { &pinyin_table[479],  &pinyin_table[129],  &pinyin_table[473],  &pinyin_table[368],  }, /* rin ei => ri nei */
    { &pinyin_table[479],  &pinyin_table[130],  &pinyin_table[473],  &pinyin_table[370],  }, /* rin en => ri nen */
    { &pinyin_table[479],  &pinyin_table[402],  &pinyin_table[473],  &pinyin_table[391],  }, /* rin ou => ri nou */
    { &pinyin_table[491],  &pinyin_table[0],    &pinyin_table[490],  &pinyin_table[161],  }, /* ruang a => ruan ga */
    { &pinyin_table[491],  &pinyin_table[2],    &pinyin_table[490],  &pinyin_table[163],  }, /* ruang ai => ruan gai */
    { &pinyin_table[491],  &pinyin_table[4],    &pinyin_table[490],  &pinyin_table[165],  }, /* ruang an => ruan gan */
    { &pinyin_table[491],  &pinyin_table[5],    &pinyin_table[490],  &pinyin_table[166],  }, /* ruang ang => ruan gang */
    { &pinyin_table[491],  &pinyin_table[6],    &pinyin_table[490],  &pinyin_table[167],  }, /* ruang ao => ruan gao */
    { &pinyin_table[491],  &pinyin_table[128],  &pinyin_table[490],  &pinyin_table[168],  }, /* ruang e => ruan ge */
    { &pinyin_table[491],  &pinyin_table[129],  &pinyin_table[490],  &pinyin_table[170],  }, /* ruang ei => ruan gei */
    { &pinyin_table[491],  &pinyin_table[130],  &pinyin_table[490],  &pinyin_table[172],  }, /* ruang en => ruan gen */
    { &pinyin_table[491],  &pinyin_table[402],  &pinyin_table[490],  &pinyin_table[178],  }, /* ruang ou => ruan gou */
    { &pinyin_table[492],  &pinyin_table[459],  &pinyin_table[489],  &pinyin_table[131],  }, /* rue r => ru er */
    { &pinyin_table[496],  &pinyin_table[0],    &pinyin_table[489],  &pinyin_table[359],  }, /* run a => ru na */
    { &pinyin_table[496],  &pinyin_table[2],    &pinyin_table[489],  &pinyin_table[361],  }, /* run ai => ru nai */
    { &pinyin_table[496],  &pinyin_table[4],    &pinyin_table[489],  &pinyin_table[363],  }, /* run an => ru nan */
    { &pinyin_table[496],  &pinyin_table[5],    &pinyin_table[489],  &pinyin_table[364],  }, /* run ang => ru nang */
    { &pinyin_table[496],  &pinyin_table[6],    &pinyin_table[489],  &pinyin_table[365],  }, /* run ao => ru nao */
    { &pinyin_table[496],  &pinyin_table[128],  &pinyin_table[489],  &pinyin_table[366],  }, /* run e => ru ne */
    { &pinyin_table[496],  &pinyin_table[129],  &pinyin_table[489],  &pinyin_table[368],  }, /* run ei => ru nei */
    { &pinyin_table[496],  &pinyin_table[130],  &pinyin_table[489],  &pinyin_table[370],  }, /* run en => ru nen */
    { &pinyin_table[505],  &pinyin_table[0],    &pinyin_table[501],  &pinyin_table[359],  }, /* san a => sa na */
    { &pinyin_table[505],  &pinyin_table[129],  &pinyin_table[501],  &pinyin_table[368],  }, /* san ei => sa nei */
    { &pinyin_table[506],  &pinyin_table[2],    &pinyin_table[505],  &pinyin_table[163],  }, /* sang ai => san gai */
    { &pinyin_table[506],  &pinyin_table[4],    &pinyin_table[505],  &pinyin_table[165],  }, /* sang an => san gan */
    { &pinyin_table[506],  &pinyin_table[5],    &pinyin_table[505],  &pinyin_table[166],  }, /* sang ang => san gang */
    { &pinyin_table[506],  &pinyin_table[6],    &pinyin_table[505],  &pinyin_table[167],  }, /* sang ao => san gao */
    { &pinyin_table[506],  &pinyin_table[128],  &pinyin_table[505],  &pinyin_table[168],  }, /* sang e => san ge */
    { &pinyin_table[506],  &pinyin_table[129],  &pinyin_table[505],  &pinyin_table[170],  }, /* sang ei => san gei */
    { &pinyin_table[506],  &pinyin_table[130],  &pinyin_table[505],  &pinyin_table[172],  }, /* sang en => san gen */
    { &pinyin_table[512],  &pinyin_table[0],    &pinyin_table[508],  &pinyin_table[359],  }, /* sen a => se na */
    { &pinyin_table[512],  &pinyin_table[2],    &pinyin_table[508],  &pinyin_table[361],  }, /* sen ai => se nai */
    { &pinyin_table[512],  &pinyin_table[4],    &pinyin_table[508],  &pinyin_table[363],  }, /* sen an => se nan */
    { &pinyin_table[512],  &pinyin_table[5],    &pinyin_table[508],  &pinyin_table[364],  }, /* sen ang => se nang */
    { &pinyin_table[512],  &pinyin_table[6],    &pinyin_table[508],  &pinyin_table[365],  }, /* sen ao => se nao */
    { &pinyin_table[512],  &pinyin_table[128],  &pinyin_table[508],  &pinyin_table[366],  }, /* sen e => se ne */
    { &pinyin_table[512],  &pinyin_table[129],  &pinyin_table[508],  &pinyin_table[368],  }, /* sen ei => se nei */
    { &pinyin_table[513],  &pinyin_table[2],    &pinyin_table[512],  &pinyin_table[163],  }, /* seng ai => sen gai */
    { &pinyin_table[513],  &pinyin_table[4],    &pinyin_table[512],  &pinyin_table[165],  }, /* seng an => sen gan */
    { &pinyin_table[513],  &pinyin_table[5],    &pinyin_table[512],  &pinyin_table[166],  }, /* seng ang => sen gang */
    { &pinyin_table[513],  &pinyin_table[6],    &pinyin_table[512],  &pinyin_table[167],  }, /* seng ao => sen gao */
    { &pinyin_table[513],  &pinyin_table[128],  &pinyin_table[512],  &pinyin_table[168],  }, /* seng e => sen ge */
    { &pinyin_table[513],  &pinyin_table[129],  &pinyin_table[512],  &pinyin_table[170],  }, /* seng ei => sen gei */
    { &pinyin_table[513],  &pinyin_table[130],  &pinyin_table[512],  &pinyin_table[172],  }, /* seng en => sen gen */
    { &pinyin_table[513],  &pinyin_table[402],  &pinyin_table[512],  &pinyin_table[178],  }, /* seng ou => sen gou */
    { &pinyin_table[519],  &pinyin_table[0],    &pinyin_table[515],  &pinyin_table[359],  }, /* shan a => sha na */
    { &pinyin_table[519],  &pinyin_table[4],    &pinyin_table[515],  &pinyin_table[363],  }, /* shan an => sha nan */
    { &pinyin_table[519],  &pinyin_table[129],  &pinyin_table[515],  &pinyin_table[368],  }, /* shan ei => sha nei */
    { &pinyin_table[520],  &pinyin_table[2],    &pinyin_table[519],  &pinyin_table[163],  }, /* shang ai => shan gai */
    { &pinyin_table[520],  &pinyin_table[5],    &pinyin_table[519],  &pinyin_table[166],  }, /* shang ang => shan gang */
    { &pinyin_table[520],  &pinyin_table[6],    &pinyin_table[519],  &pinyin_table[167],  }, /* shang ao => shan gao */
    { &pinyin_table[520],  &pinyin_table[128],  &pinyin_table[519],  &pinyin_table[168],  }, /* shang e => shan ge */
    { &pinyin_table[520],  &pinyin_table[129],  &pinyin_table[519],  &pinyin_table[170],  }, /* shang ei => shan gei */
    { &pinyin_table[520],  &pinyin_table[130],  &pinyin_table[519],  &pinyin_table[172],  }, /* shang en => shan gen */
    { &pinyin_table[520],  &pinyin_table[402],  &pinyin_table[519],  &pinyin_table[178],  }, /* shang ou => shan gou */
    { &pinyin_table[526],  &pinyin_table[129],  &pinyin_table[522],  &pinyin_table[368],  }, /* shen ei => she nei */
    { &pinyin_table[527],  &pinyin_table[4],    &pinyin_table[526],  &pinyin_table[165],  }, /* sheng an => shen gan */
    { &pinyin_table[527],  &pinyin_table[5],    &pinyin_table[526],  &pinyin_table[166],  }, /* sheng ang => shen gang */
    { &pinyin_table[527],  &pinyin_table[6],    &pinyin_table[526],  &pinyin_table[167],  }, /* sheng ao => shen gao */
    { &pinyin_table[527],  &pinyin_table[128],  &pinyin_table[526],  &pinyin_table[168],  }, /* sheng e => shen ge */
    { &pinyin_table[527],  &pinyin_table[129],  &pinyin_table[526],  &pinyin_table[170],  }, /* sheng ei => shen gei */
    { &pinyin_table[527],  &pinyin_table[402],  &pinyin_table[526],  &pinyin_table[178],  }, /* sheng ou => shen gou */
    { &pinyin_table[537],  &pinyin_table[0],    &pinyin_table[533],  &pinyin_table[359],  }, /* shuan a => shua na */
    { &pinyin_table[537],  &pinyin_table[2],    &pinyin_table[533],  &pinyin_table[361],  }, /* shuan ai => shua nai */
    { &pinyin_table[537],  &pinyin_table[4],    &pinyin_table[533],  &pinyin_table[363],  }, /* shuan an => shua nan */
    { &pinyin_table[537],  &pinyin_table[5],    &pinyin_table[533],  &pinyin_table[364],  }, /* shuan ang => shua nang */
    { &pinyin_table[537],  &pinyin_table[6],    &pinyin_table[533],  &pinyin_table[365],  }, /* shuan ao => shua nao */
    { &pinyin_table[537],  &pinyin_table[128],  &pinyin_table[533],  &pinyin_table[366],  }, /* shuan e => shua ne */
    { &pinyin_table[537],  &pinyin_table[129],  &pinyin_table[533],  &pinyin_table[368],  }, /* shuan ei => shua nei */
    { &pinyin_table[538],  &pinyin_table[129],  &pinyin_table[537],  &pinyin_table[170],  }, /* shuang ei => shuan gei */
    { &pinyin_table[542],  &pinyin_table[4],    &pinyin_table[532],  &pinyin_table[363],  }, /* shun an => shu nan */
    { &pinyin_table[542],  &pinyin_table[5],    &pinyin_table[532],  &pinyin_table[364],  }, /* shun ang => shu nang */
    { &pinyin_table[542],  &pinyin_table[6],    &pinyin_table[532],  &pinyin_table[365],  }, /* shun ao => shu nao */
    { &pinyin_table[542],  &pinyin_table[128],  &pinyin_table[532],  &pinyin_table[366],  }, /* shun e => shu ne */
    { &pinyin_table[542],  &pinyin_table[129],  &pinyin_table[532],  &pinyin_table[368],  }, /* shun ei => shu nei */
    { &pinyin_table[554],  &pinyin_table[0],    &pinyin_table[553],  &pinyin_table[161],  }, /* suang a => suan ga */
    { &pinyin_table[554],  &pinyin_table[2],    &pinyin_table[553],  &pinyin_table[163],  }, /* suang ai => suan gai */
    { &pinyin_table[554],  &pinyin_table[4],    &pinyin_table[553],  &pinyin_table[165],  }, /* suang an => suan gan */
    { &pinyin_table[554],  &pinyin_table[5],    &pinyin_table[553],  &pinyin_table[166],  }, /* suang ang => suan gang */
    { &pinyin_table[554],  &pinyin_table[6],    &pinyin_table[553],  &pinyin_table[167],  }, /* suang ao => suan gao */
    { &pinyin_table[554],  &pinyin_table[128],  &pinyin_table[553],  &pinyin_table[168],  }, /* suang e => suan ge */
    { &pinyin_table[554],  &pinyin_table[129],  &pinyin_table[553],  &pinyin_table[170],  }, /* suang ei => suan gei */
    { &pinyin_table[554],  &pinyin_table[130],  &pinyin_table[553],  &pinyin_table[172],  }, /* suang en => suan gen */
    { &pinyin_table[554],  &pinyin_table[402],  &pinyin_table[553],  &pinyin_table[178],  }, /* suang ou => suan gou */
    { &pinyin_table[558],  &pinyin_table[0],    &pinyin_table[550],  &pinyin_table[359],  }, /* sun a => su na */
    { &pinyin_table[558],  &pinyin_table[4],    &pinyin_table[550],  &pinyin_table[363],  }, /* sun an => su nan */
    { &pinyin_table[558],  &pinyin_table[5],    &pinyin_table[550],  &pinyin_table[364],  }, /* sun ang => su nang */
    { &pinyin_table[558],  &pinyin_table[6],    &pinyin_table[550],  &pinyin_table[365],  }, /* sun ao => su nao */
    { &pinyin_table[558],  &pinyin_table[128],  &pinyin_table[550],  &pinyin_table[366],  }, /* sun e => su ne */
    { &pinyin_table[558],  &pinyin_table[129],  &pinyin_table[550],  &pinyin_table[368],  }, /* sun ei => su nei */
    { &pinyin_table[565],  &pinyin_table[0],    &pinyin_table[561],  &pinyin_table[359],  }, /* tan a => ta na */
    { &pinyin_table[565],  &pinyin_table[5],    &pinyin_table[561],  &pinyin_table[364],  }, /* tan ang => ta nang */
    { &pinyin_table[565],  &pinyin_table[6],    &pinyin_table[561],  &pinyin_table[365],  }, /* tan ao => ta nao */
    { &pinyin_table[565],  &pinyin_table[128],  &pinyin_table[561],  &pinyin_table[366],  }, /* tan e => ta ne */
    { &pinyin_table[565],  &pinyin_table[129],  &pinyin_table[561],  &pinyin_table[368],  }, /* tan ei => ta nei */
    { &pinyin_table[566],  &pinyin_table[2],    &pinyin_table[565],  &pinyin_table[163],  }, /* tang ai => tan gai */
    { &pinyin_table[566],  &pinyin_table[4],    &pinyin_table[565],  &pinyin_table[165],  }, /* tang an => tan gan */
    { &pinyin_table[566],  &pinyin_table[5],    &pinyin_table[565],  &pinyin_table[166],  }, /* tang ang => tan gang */
    { &pinyin_table[566],  &pinyin_table[128],  &pinyin_table[565],  &pinyin_table[168],  }, /* tang e => tan ge */
    { &pinyin_table[566],  &pinyin_table[129],  &pinyin_table[565],  &pinyin_table[170],  }, /* tang ei => tan gei */
    { &pinyin_table[566],  &pinyin_table[402],  &pinyin_table[565],  &pinyin_table[178],  }, /* tang ou => tan gou */
    { &pinyin_table[571],  &pinyin_table[0],    &pinyin_table[568],  &pinyin_table[359],  }, /* ten a => te na */
    { &pinyin_table[571],  &pinyin_table[2],    &pinyin_table[568],  &pinyin_table[361],  }, /* ten ai => te nai */
    { &pinyin_table[571],  &pinyin_table[4],    &pinyin_table[568],  &pinyin_table[363],  }, /* ten an => te nan */
    { &pinyin_table[571],  &pinyin_table[5],    &pinyin_table[568],  &pinyin_table[364],  }, /* ten ang => te nang */
    { &pinyin_table[571],  &pinyin_table[6],    &pinyin_table[568],  &pinyin_table[365],  }, /* ten ao => te nao */
    { &pinyin_table[571],  &pinyin_table[128],  &pinyin_table[568],  &pinyin_table[366],  }, /* ten e => te ne */
    { &pinyin_table[571],  &pinyin_table[129],  &pinyin_table[568],  &pinyin_table[368],  }, /* ten ei => te nei */
    { &pinyin_table[571],  &pinyin_table[130],  &pinyin_table[568],  &pinyin_table[370],  }, /* ten en => te nen */
    { &pinyin_table[571],  &pinyin_table[402],  &pinyin_table[568],  &pinyin_table[391],  }, /* ten ou => te nou */
    { &pinyin_table[575],  &pinyin_table[0],    &pinyin_table[574],  &pinyin_table[161],  }, /* tiang a => tian ga */
    { &pinyin_table[575],  &pinyin_table[2],    &pinyin_table[574],  &pinyin_table[163],  }, /* tiang ai => tian gai */
    { &pinyin_table[575],  &pinyin_table[4],    &pinyin_table[574],  &pinyin_table[165],  }, /* tiang an => tian gan */
    { &pinyin_table[575],  &pinyin_table[5],    &pinyin_table[574],  &pinyin_table[166],  }, /* tiang ang => tian gang */
    { &pinyin_table[575],  &pinyin_table[6],    &pinyin_table[574],  &pinyin_table[167],  }, /* tiang ao => tian gao */
    { &pinyin_table[575],  &pinyin_table[128],  &pinyin_table[574],  &pinyin_table[168],  }, /* tiang e => tian ge */
    { &pinyin_table[575],  &pinyin_table[129],  &pinyin_table[574],  &pinyin_table[170],  }, /* tiang ei => tian gei */
    { &pinyin_table[575],  &pinyin_table[130],  &pinyin_table[574],  &pinyin_table[172],  }, /* tiang en => tian gen */
    { &pinyin_table[575],  &pinyin_table[402],  &pinyin_table[574],  &pinyin_table[178],  }, /* tiang ou => tian gou */
    { &pinyin_table[577],  &pinyin_table[459],  &pinyin_table[573],  &pinyin_table[131],  }, /* tie r => ti er */
    { &pinyin_table[580],  &pinyin_table[0],    &pinyin_table[573],  &pinyin_table[359],  }, /* tin a => ti na */
    { &pinyin_table[580],  &pinyin_table[2],    &pinyin_table[573],  &pinyin_table[361],  }, /* tin ai => ti nai */
    { &pinyin_table[580],  &pinyin_table[4],    &pinyin_table[573],  &pinyin_table[363],  }, /* tin an => ti nan */
    { &pinyin_table[580],  &pinyin_table[5],    &pinyin_table[573],  &pinyin_table[364],  }, /* tin ang => ti nang */
    { &pinyin_table[580],  &pinyin_table[6],    &pinyin_table[573],  &pinyin_table[365],  }, /* tin ao => ti nao */
    { &pinyin_table[580],  &pinyin_table[128],  &pinyin_table[573],  &pinyin_table[366],  }, /* tin e => ti ne */
    { &pinyin_table[580],  &pinyin_table[129],  &pinyin_table[573],  &pinyin_table[368],  }, /* tin ei => ti nei */
    { &pinyin_table[580],  &pinyin_table[130],  &pinyin_table[573],  &pinyin_table[370],  }, /* tin en => ti nen */
    { &pinyin_table[580],  &pinyin_table[402],  &pinyin_table[573],  &pinyin_table[391],  }, /* tin ou => ti nou */
    { &pinyin_table[589],  &pinyin_table[0],    &pinyin_table[588],  &pinyin_table[161],  }, /* tuang a => tuan ga */
    { &pinyin_table[589],  &pinyin_table[2],    &pinyin_table[588],  &pinyin_table[163],  }, /* tuang ai => tuan gai */
    { &pinyin_table[589],  &pinyin_table[4],    &pinyin_table[588],  &pinyin_table[165],  }, /* tuang an => tuan gan */
    { &pinyin_table[589],  &pinyin_table[5],    &pinyin_table[588],  &pinyin_table[166],  }, /* tuang ang => tuan gang */
    { &pinyin_table[589],  &pinyin_table[6],    &pinyin_table[588],  &pinyin_table[167],  }, /* tuang ao => tuan gao */
    { &pinyin_table[589],  &pinyin_table[128],  &pinyin_table[588],  &pinyin_table[168],  }, /* tuang e => tuan ge */
    { &pinyin_table[589],  &pinyin_table[129],  &pinyin_table[588],  &pinyin_table[170],  }, /* tuang ei => tuan gei */
    { &pinyin_table[589],  &pinyin_table[130],  &pinyin_table[588],  &pinyin_table[172],  }, /* tuang en => tuan gen */
    { &pinyin_table[589],  &pinyin_table[402],  &pinyin_table[588],  &pinyin_table[178],  }, /* tuang ou => tuan gou */
    { &pinyin_table[593],  &pinyin_table[0],    &pinyin_table[587],  &pinyin_table[359],  }, /* tun a => tu na */
    { &pinyin_table[593],  &pinyin_table[2],    &pinyin_table[587],  &pinyin_table[361],  }, /* tun ai => tu nai */
    { &pinyin_table[593],  &pinyin_table[4],    &pinyin_table[587],  &pinyin_table[363],  }, /* tun an => tu nan */
    { &pinyin_table[593],  &pinyin_table[5],    &pinyin_table[587],  &pinyin_table[364],  }, /* tun ang => tu nang */
    { &pinyin_table[593],  &pinyin_table[6],    &pinyin_table[587],  &pinyin_table[365],  }, /* tun ao => tu nao */
    { &pinyin_table[593],  &pinyin_table[128],  &pinyin_table[587],  &pinyin_table[366],  }, /* tun e => tu ne */
    { &pinyin_table[593],  &pinyin_table[129],  &pinyin_table[587],  &pinyin_table[368],  }, /* tun ei => tu nei */
    { &pinyin_table[593],  &pinyin_table[130],  &pinyin_table[587],  &pinyin_table[370],  }, /* tun en => tu nen */
    { &pinyin_table[600],  &pinyin_table[129],  &pinyin_table[596],  &pinyin_table[368],  }, /* wan ei => wa nei */
    { &pinyin_table[601],  &pinyin_table[5],    &pinyin_table[600],  &pinyin_table[166],  }, /* wang ang => wan gang */
    { &pinyin_table[601],  &pinyin_table[6],    &pinyin_table[600],  &pinyin_table[167],  }, /* wang ao => wan gao */
    { &pinyin_table[601],  &pinyin_table[128],  &pinyin_table[600],  &pinyin_table[168],  }, /* wang e => wan ge */
    { &pinyin_table[601],  &pinyin_table[129],  &pinyin_table[600],  &pinyin_table[170],  }, /* wang ei => wan gei */
    { &pinyin_table[601],  &pinyin_table[402],  &pinyin_table[600],  &pinyin_table[178],  }, /* wang ou => wan gou */
    { &pinyin_table[606],  &pinyin_table[0],    &pinyin_table[605],  &pinyin_table[161],  }, /* weng a => wen ga */
    { &pinyin_table[606],  &pinyin_table[2],    &pinyin_table[605],  &pinyin_table[163],  }, /* weng ai => wen gai */
    { &pinyin_table[606],  &pinyin_table[4],    &pinyin_table[605],  &pinyin_table[165],  }, /* weng an => wen gan */
    { &pinyin_table[606],  &pinyin_table[5],    &pinyin_table[605],  &pinyin_table[166],  }, /* weng ang => wen gang */
    { &pinyin_table[606],  &pinyin_table[6],    &pinyin_table[605],  &pinyin_table[167],  }, /* weng ao => wen gao */
    { &pinyin_table[606],  &pinyin_table[128],  &pinyin_table[605],  &pinyin_table[168],  }, /* weng e => wen ge */
    { &pinyin_table[606],  &pinyin_table[129],  &pinyin_table[605],  &pinyin_table[170],  }, /* weng ei => wen gei */
    { &pinyin_table[606],  &pinyin_table[130],  &pinyin_table[605],  &pinyin_table[172],  }, /* weng en => wen gen */
    { &pinyin_table[606],  &pinyin_table[402],  &pinyin_table[605],  &pinyin_table[178],  }, /* weng ou => wen gou */
    { &pinyin_table[614],  &pinyin_table[0],    &pinyin_table[611],  &pinyin_table[359],  }, /* xian a => xia na */
    { &pinyin_table[614],  &pinyin_table[5],    &pinyin_table[611],  &pinyin_table[364],  }, /* xian ang => xia nang */
    { &pinyin_table[614],  &pinyin_table[6],    &pinyin_table[611],  &pinyin_table[365],  }, /* xian ao => xia nao */
    { &pinyin_table[614],  &pinyin_table[129],  &pinyin_table[611],  &pinyin_table[368],  }, /* xian ei => xia nei */
    { &pinyin_table[615],  &pinyin_table[5],    &pinyin_table[614],  &pinyin_table[166],  }, /* xiang ang => xian gang */
    { &pinyin_table[615],  &pinyin_table[6],    &pinyin_table[614],  &pinyin_table[167],  }, /* xiang ao => xian gao */
    { &pinyin_table[615],  &pinyin_table[129],  &pinyin_table[614],  &pinyin_table[170],  }, /* xiang ei => xian gei */
    { &pinyin_table[615],  &pinyin_table[130],  &pinyin_table[614],  &pinyin_table[172],  }, /* xiang en => xian gen */
    { &pinyin_table[615],  &pinyin_table[402],  &pinyin_table[614],  &pinyin_table[178],  }, /* xiang ou => xian gou */
    { &pinyin_table[617],  &pinyin_table[459],  &pinyin_table[610],  &pinyin_table[131],  }, /* xie r => xi er */
    { &pinyin_table[620],  &pinyin_table[0],    &pinyin_table[610],  &pinyin_table[359],  }, /* xin a => xi na */
    { &pinyin_table[620],  &pinyin_table[4],    &pinyin_table[610],  &pinyin_table[363],  }, /* xin an => xi nan */
    { &pinyin_table[620],  &pinyin_table[128],  &pinyin_table[610],  &pinyin_table[366],  }, /* xin e => xi ne */
    { &pinyin_table[620],  &pinyin_table[129],  &pinyin_table[610],  &pinyin_table[368],  }, /* xin ei => xi nei */
    { &pinyin_table[620],  &pinyin_table[130],  &pinyin_table[610],  &pinyin_table[370],  }, /* xin en => xi nen */
    { &pinyin_table[621],  &pinyin_table[4],    &pinyin_table[620],  &pinyin_table[165],  }, /* xing an => xin gan */
    { &pinyin_table[621],  &pinyin_table[5],    &pinyin_table[620],  &pinyin_table[166],  }, /* xing ang => xin gang */
    { &pinyin_table[621],  &pinyin_table[6],    &pinyin_table[620],  &pinyin_table[167],  }, /* xing ao => xin gao */
    { &pinyin_table[621],  &pinyin_table[128],  &pinyin_table[620],  &pinyin_table[168],  }, /* xing e => xin ge */
    { &pinyin_table[621],  &pinyin_table[129],  &pinyin_table[620],  &pinyin_table[170],  }, /* xing ei => xin gei */
    { &pinyin_table[621],  &pinyin_table[130],  &pinyin_table[620],  &pinyin_table[172],  }, /* xing en => xin gen */
    { &pinyin_table[621],  &pinyin_table[402],  &pinyin_table[620],  &pinyin_table[178],  }, /* xing ou => xin gou */
    { &pinyin_table[630],  &pinyin_table[0],    &pinyin_table[629],  &pinyin_table[161],  }, /* xuang a => xuan ga */
    { &pinyin_table[630],  &pinyin_table[2],    &pinyin_table[629],  &pinyin_table[163],  }, /* xuang ai => xuan gai */
    { &pinyin_table[630],  &pinyin_table[4],    &pinyin_table[629],  &pinyin_table[165],  }, /* xuang an => xuan gan */
    { &pinyin_table[630],  &pinyin_table[5],    &pinyin_table[629],  &pinyin_table[166],  }, /* xuang ang => xuan gang */
    { &pinyin_table[630],  &pinyin_table[6],    &pinyin_table[629],  &pinyin_table[167],  }, /* xuang ao => xuan gao */
    { &pinyin_table[630],  &pinyin_table[128],  &pinyin_table[629],  &pinyin_table[168],  }, /* xuang e => xuan ge */
    { &pinyin_table[630],  &pinyin_table[129],  &pinyin_table[629],  &pinyin_table[170],  }, /* xuang ei => xuan gei */
    { &pinyin_table[630],  &pinyin_table[130],  &pinyin_table[629],  &pinyin_table[172],  }, /* xuang en => xuan gen */
    { &pinyin_table[630],  &pinyin_table[402],  &pinyin_table[629],  &pinyin_table[178],  }, /* xuang ou => xuan gou */
    { &pinyin_table[631],  &pinyin_table[459],  &pinyin_table[628],  &pinyin_table[131],  }, /* xue r => xu er */
    { &pinyin_table[632],  &pinyin_table[0],    &pinyin_table[631],  &pinyin_table[359],  }, /* xuen a => xue na */
    { &pinyin_table[632],  &pinyin_table[2],    &pinyin_table[631],  &pinyin_table[361],  }, /* xuen ai => xue nai */
    { &pinyin_table[632],  &pinyin_table[4],    &pinyin_table[631],  &pinyin_table[363],  }, /* xuen an => xue nan */
    { &pinyin_table[632],  &pinyin_table[5],    &pinyin_table[631],  &pinyin_table[364],  }, /* xuen ang => xue nang */
    { &pinyin_table[632],  &pinyin_table[6],    &pinyin_table[631],  &pinyin_table[365],  }, /* xuen ao => xue nao */
    { &pinyin_table[632],  &pinyin_table[128],  &pinyin_table[631],  &pinyin_table[366],  }, /* xuen e => xue ne */
    { &pinyin_table[632],  &pinyin_table[129],  &pinyin_table[631],  &pinyin_table[368],  }, /* xuen ei => xue nei */
    { &pinyin_table[632],  &pinyin_table[130],  &pinyin_table[631],  &pinyin_table[370],  }, /* xuen en => xue nen */
    { &pinyin_table[632],  &pinyin_table[402],  &pinyin_table[631],  &pinyin_table[391],  }, /* xuen ou => xue nou */
    { &pinyin_table[633],  &pinyin_table[5],    &pinyin_table[628],  &pinyin_table[364],  }, /* xun ang => xu nang */
    { &pinyin_table[633],  &pinyin_table[6],    &pinyin_table[628],  &pinyin_table[365],  }, /* xun ao => xu nao */
    { &pinyin_table[633],  &pinyin_table[128],  &pinyin_table[628],  &pinyin_table[366],  }, /* xun e => xu ne */
    { &pinyin_table[633],  &pinyin_table[129],  &pinyin_table[628],  &pinyin_table[368],  }, /* xun ei => xu nei */
    { &pinyin_table[644],  &pinyin_table[0],    &pinyin_table[641],  &pinyin_table[359],  }, /* yan a => ya na */
    { &pinyin_table[644],  &pinyin_table[128],  &pinyin_table[641],  &pinyin_table[366],  }, /* yan e => ya ne */
    { &pinyin_table[644],  &pinyin_table[129],  &pinyin_table[641],  &pinyin_table[368],  }, /* yan ei => ya nei */
    { &pinyin_table[645],  &pinyin_table[2],    &pinyin_table[644],  &pinyin_table[163],  }, /* yang ai => yan gai */
    { &pinyin_table[645],  &pinyin_table[4],    &pinyin_table[644],  &pinyin_table[165],  }, /* yang an => yan gan */
    { &pinyin_table[645],  &pinyin_table[5],    &pinyin_table[644],  &pinyin_table[166],  }, /* yang ang => yan gang */
    { &pinyin_table[645],  &pinyin_table[6],    &pinyin_table[644],  &pinyin_table[167],  }, /* yang ao => yan gao */
    { &pinyin_table[645],  &pinyin_table[128],  &pinyin_table[644],  &pinyin_table[168],  }, /* yang e => yan ge */
    { &pinyin_table[645],  &pinyin_table[129],  &pinyin_table[644],  &pinyin_table[170],  }, /* yang ei => yan gei */
    { &pinyin_table[645],  &pinyin_table[402],  &pinyin_table[644],  &pinyin_table[178],  }, /* yang ou => yan gou */
    { &pinyin_table[651],  &pinyin_table[0],    &pinyin_table[648],  &pinyin_table[359],  }, /* yin a => yi na */
    { &pinyin_table[651],  &pinyin_table[2],    &pinyin_table[648],  &pinyin_table[361],  }, /* yin ai => yi nai */
    { &pinyin_table[651],  &pinyin_table[4],    &pinyin_table[648],  &pinyin_table[363],  }, /* yin an => yi nan */
    { &pinyin_table[651],  &pinyin_table[5],    &pinyin_table[648],  &pinyin_table[364],  }, /* yin ang => yi nang */
    { &pinyin_table[651],  &pinyin_table[6],    &pinyin_table[648],  &pinyin_table[365],  }, /* yin ao => yi nao */
    { &pinyin_table[651],  &pinyin_table[129],  &pinyin_table[648],  &pinyin_table[368],  }, /* yin ei => yi nei */
    { &pinyin_table[652],  &pinyin_table[2],    &pinyin_table[651],  &pinyin_table[163],  }, /* ying ai => yin gai */
    { &pinyin_table[652],  &pinyin_table[5],    &pinyin_table[651],  &pinyin_table[166],  }, /* ying ang => yin gang */
    { &pinyin_table[652],  &pinyin_table[6],    &pinyin_table[651],  &pinyin_table[167],  }, /* ying ao => yin gao */
    { &pinyin_table[652],  &pinyin_table[129],  &pinyin_table[651],  &pinyin_table[170],  }, /* ying ei => yin gei */
    { &pinyin_table[652],  &pinyin_table[130],  &pinyin_table[651],  &pinyin_table[172],  }, /* ying en => yin gen */
    { &pinyin_table[652],  &pinyin_table[402],  &pinyin_table[651],  &pinyin_table[178],  }, /* ying ou => yin gou */
    { &pinyin_table[656],  &pinyin_table[0],    &pinyin_table[653],  &pinyin_table[359],  }, /* yon a => yo na */
    { &pinyin_table[656],  &pinyin_table[2],    &pinyin_table[653],  &pinyin_table[361],  }, /* yon ai => yo nai */
    { &pinyin_table[656],  &pinyin_table[4],    &pinyin_table[653],  &pinyin_table[363],  }, /* yon an => yo nan */
    { &pinyin_table[656],  &pinyin_table[5],    &pinyin_table[653],  &pinyin_table[364],  }, /* yon ang => yo nang */
    { &pinyin_table[656],  &pinyin_table[6],    &pinyin_table[653],  &pinyin_table[365],  }, /* yon ao => yo nao */
    { &pinyin_table[656],  &pinyin_table[128],  &pinyin_table[653],  &pinyin_table[366],  }, /* yon e => yo ne */
    { &pinyin_table[656],  &pinyin_table[129],  &pinyin_table[653],  &pinyin_table[368],  }, /* yon ei => yo nei */
    { &pinyin_table[656],  &pinyin_table[130],  &pinyin_table[653],  &pinyin_table[370],  }, /* yon en => yo nen */
    { &pinyin_table[656],  &pinyin_table[402],  &pinyin_table[653],  &pinyin_table[391],  }, /* yon ou => yo nou */
    { &pinyin_table[661],  &pinyin_table[0],    &pinyin_table[660],  &pinyin_table[161],  }, /* yuang a => yuan ga */
    { &pinyin_table[661],  &pinyin_table[2],    &pinyin_table[660],  &pinyin_table[163],  }, /* yuang ai => yuan gai */
    { &pinyin_table[661],  &pinyin_table[4],    &pinyin_table[660],  &pinyin_table[165],  }, /* yuang an => yuan gan */
    { &pinyin_table[661],  &pinyin_table[5],    &pinyin_table[660],  &pinyin_table[166],  }, /* yuang ang => yuan gang */
    { &pinyin_table[661],  &pinyin_table[6],    &pinyin_table[660],  &pinyin_table[167],  }, /* yuang ao => yuan gao */
    { &pinyin_table[661],  &pinyin_table[128],  &pinyin_table[660],  &pinyin_table[168],  }, /* yuang e => yuan ge */
    { &pinyin_table[661],  &pinyin_table[129],  &pinyin_table[660],  &pinyin_table[170],  }, /* yuang ei => yuan gei */
    { &pinyin_table[661],  &pinyin_table[130],  &pinyin_table[660],  &pinyin_table[172],  }, /* yuang en => yuan gen */
    { &pinyin_table[661],  &pinyin_table[402],  &pinyin_table[660],  &pinyin_table[178],  }, /* yuang ou => yuan gou */
    { &pinyin_table[662],  &pinyin_table[459],  &pinyin_table[659],  &pinyin_table[131],  }, /* yue r => yu er */
    { &pinyin_table[663],  &pinyin_table[0],    &pinyin_table[662],  &pinyin_table[359],  }, /* yuen a => yue na */
    { &pinyin_table[663],  &pinyin_table[2],    &pinyin_table[662],  &pinyin_table[361],  }, /* yuen ai => yue nai */
    { &pinyin_table[663],  &pinyin_table[4],    &pinyin_table[662],  &pinyin_table[363],  }, /* yuen an => yue nan */
    { &pinyin_table[663],  &pinyin_table[5],    &pinyin_table[662],  &pinyin_table[364],  }, /* yuen ang => yue nang */
    { &pinyin_table[663],  &pinyin_table[6],    &pinyin_table[662],  &pinyin_table[365],  }, /* yuen ao => yue nao */
    { &pinyin_table[663],  &pinyin_table[128],  &pinyin_table[662],  &pinyin_table[366],  }, /* yuen e => yue ne */
    { &pinyin_table[663],  &pinyin_table[129],  &pinyin_table[662],  &pinyin_table[368],  }, /* yuen ei => yue nei */
    { &pinyin_table[663],  &pinyin_table[130],  &pinyin_table[662],  &pinyin_table[370],  }, /* yuen en => yue nen */
    { &pinyin_table[663],  &pinyin_table[402],  &pinyin_table[662],  &pinyin_table[391],  }, /* yuen ou => yue nou */
    { &pinyin_table[664],  &pinyin_table[0],    &pinyin_table[659],  &pinyin_table[359],  }, /* yun a => yu na */
    { &pinyin_table[664],  &pinyin_table[2],    &pinyin_table[659],  &pinyin_table[361],  }, /* yun ai => yu nai */
    { &pinyin_table[664],  &pinyin_table[4],    &pinyin_table[659],  &pinyin_table[363],  }, /* yun an => yu nan */
    { &pinyin_table[664],  &pinyin_table[5],    &pinyin_table[659],  &pinyin_table[364],  }, /* yun ang => yu nang */
    { &pinyin_table[664],  &pinyin_table[6],    &pinyin_table[659],  &pinyin_table[365],  }, /* yun ao => yu nao */
    { &pinyin_table[664],  &pinyin_table[128],  &pinyin_table[659],  &pinyin_table[366],  }, /* yun e => yu ne */
    { &pinyin_table[664],  &pinyin_table[129],  &pinyin_table[659],  &pinyin_table[368],  }, /* yun ei => yu nei */
    { &pinyin_table[676],  &pinyin_table[0],    &pinyin_table[672],  &pinyin_table[359],  }, /* zan a => za na */
    { &pinyin_table[676],  &pinyin_table[4],    &pinyin_table[672],  &pinyin_table[363],  }, /* zan an => za nan */
    { &pinyin_table[676],  &pinyin_table[5],    &pinyin_table[672],  &pinyin_table[364],  }, /* zan ang => za nang */
    { &pinyin_table[676],  &pinyin_table[6],    &pinyin_table[672],  &pinyin_table[365],  }, /* zan ao => za nao */
    { &pinyin_table[676],  &pinyin_table[128],  &pinyin_table[672],  &pinyin_table[366],  }, /* zan e => za ne */
    { &pinyin_table[676],  &pinyin_table[129],  &pinyin_table[672],  &pinyin_table[368],  }, /* zan ei => za nei */
    { &pinyin_table[677],  &pinyin_table[4],    &pinyin_table[676],  &pinyin_table[165],  }, /* zang an => zan gan */
    { &pinyin_table[677],  &pinyin_table[5],    &pinyin_table[676],  &pinyin_table[166],  }, /* zang ang => zan gang */
    { &pinyin_table[677],  &pinyin_table[6],    &pinyin_table[676],  &pinyin_table[167],  }, /* zang ao => zan gao */
    { &pinyin_table[677],  &pinyin_table[128],  &pinyin_table[676],  &pinyin_table[168],  }, /* zang e => zan ge */
    { &pinyin_table[677],  &pinyin_table[129],  &pinyin_table[676],  &pinyin_table[170],  }, /* zang ei => zan gei */
    { &pinyin_table[677],  &pinyin_table[130],  &pinyin_table[676],  &pinyin_table[172],  }, /* zang en => zan gen */
    { &pinyin_table[677],  &pinyin_table[402],  &pinyin_table[676],  &pinyin_table[178],  }, /* zang ou => zan gou */
    { &pinyin_table[683],  &pinyin_table[0],    &pinyin_table[679],  &pinyin_table[359],  }, /* zen a => ze na */
    { &pinyin_table[683],  &pinyin_table[4],    &pinyin_table[679],  &pinyin_table[363],  }, /* zen an => ze nan */
    { &pinyin_table[683],  &pinyin_table[6],    &pinyin_table[679],  &pinyin_table[365],  }, /* zen ao => ze nao */
    { &pinyin_table[683],  &pinyin_table[128],  &pinyin_table[679],  &pinyin_table[366],  }, /* zen e => ze ne */
    { &pinyin_table[683],  &pinyin_table[129],  &pinyin_table[679],  &pinyin_table[368],  }, /* zen ei => ze nei */
    { &pinyin_table[684],  &pinyin_table[2],    &pinyin_table[683],  &pinyin_table[163],  }, /* zeng ai => zen gai */
    { &pinyin_table[684],  &pinyin_table[4],    &pinyin_table[683],  &pinyin_table[165],  }, /* zeng an => zen gan */
    { &pinyin_table[684],  &pinyin_table[5],    &pinyin_table[683],  &pinyin_table[166],  }, /* zeng ang => zen gang */
    { &pinyin_table[684],  &pinyin_table[6],    &pinyin_table[683],  &pinyin_table[167],  }, /* zeng ao => zen gao */
    { &pinyin_table[684],  &pinyin_table[129],  &pinyin_table[683],  &pinyin_table[170],  }, /* zeng ei => zen gei */
    { &pinyin_table[684],  &pinyin_table[130],  &pinyin_table[683],  &pinyin_table[172],  }, /* zeng en => zen gen */
    { &pinyin_table[684],  &pinyin_table[402],  &pinyin_table[683],  &pinyin_table[178],  }, /* zeng ou => zen gou */
    { &pinyin_table[690],  &pinyin_table[129],  &pinyin_table[686],  &pinyin_table[368],  }, /* zhan ei => zha nei */
    { &pinyin_table[691],  &pinyin_table[4],    &pinyin_table[690],  &pinyin_table[165],  }, /* zhang an => zhan gan */
    { &pinyin_table[691],  &pinyin_table[5],    &pinyin_table[690],  &pinyin_table[166],  }, /* zhang ang => zhan gang */
    { &pinyin_table[691],  &pinyin_table[6],    &pinyin_table[690],  &pinyin_table[167],  }, /* zhang ao => zhan gao */
    { &pinyin_table[691],  &pinyin_table[128],  &pinyin_table[690],  &pinyin_table[168],  }, /* zhang e => zhan ge */
    { &pinyin_table[691],  &pinyin_table[129],  &pinyin_table[690],  &pinyin_table[170],  }, /* zhang ei => zhan gei */
    { &pinyin_table[691],  &pinyin_table[130],  &pinyin_table[690],  &pinyin_table[172],  }, /* zhang en => zhan gen */
    { &pinyin_table[691],  &pinyin_table[402],  &pinyin_table[690],  &pinyin_table[178],  }, /* zhang ou => zhan gou */
    { &pinyin_table[697],  &pinyin_table[0],    &pinyin_table[693],  &pinyin_table[359],  }, /* zhen a => zhe na */
    { &pinyin_table[697],  &pinyin_table[4],    &pinyin_table[693],  &pinyin_table[363],  }, /* zhen an => zhe nan */
    { &pinyin_table[697],  &pinyin_table[5],    &pinyin_table[693],  &pinyin_table[364],  }, /* zhen ang => zhe nang */
    { &pinyin_table[697],  &pinyin_table[6],    &pinyin_table[693],  &pinyin_table[365],  }, /* zhen ao => zhe nao */
    { &pinyin_table[697],  &pinyin_table[128],  &pinyin_table[693],  &pinyin_table[366],  }, /* zhen e => zhe ne */
    { &pinyin_table[697],  &pinyin_table[129],  &pinyin_table[693],  &pinyin_table[368],  }, /* zhen ei => zhe nei */
    { &pinyin_table[698],  &pinyin_table[2],    &pinyin_table[697],  &pinyin_table[163],  }, /* zheng ai => zhen gai */
    { &pinyin_table[698],  &pinyin_table[4],    &pinyin_table[697],  &pinyin_table[165],  }, /* zheng an => zhen gan */
    { &pinyin_table[698],  &pinyin_table[5],    &pinyin_table[697],  &pinyin_table[166],  }, /* zheng ang => zhen gang */
    { &pinyin_table[698],  &pinyin_table[6],    &pinyin_table[697],  &pinyin_table[167],  }, /* zheng ao => zhen gao */
    { &pinyin_table[698],  &pinyin_table[128],  &pinyin_table[697],  &pinyin_table[168],  }, /* zheng e => zhen ge */
    { &pinyin_table[698],  &pinyin_table[129],  &pinyin_table[697],  &pinyin_table[170],  }, /* zheng ei => zhen gei */
    { &pinyin_table[698],  &pinyin_table[130],  &pinyin_table[697],  &pinyin_table[172],  }, /* zheng en => zhen gen */
    { &pinyin_table[698],  &pinyin_table[402],  &pinyin_table[697],  &pinyin_table[178],  }, /* zheng ou => zhen gou */
    { &pinyin_table[710],  &pinyin_table[6],    &pinyin_table[706],  &pinyin_table[365],  }, /* zhuan ao => zhua nao */
    { &pinyin_table[710],  &pinyin_table[128],  &pinyin_table[706],  &pinyin_table[366],  }, /* zhuan e => zhua ne */
    { &pinyin_table[710],  &pinyin_table[129],  &pinyin_table[706],  &pinyin_table[368],  }, /* zhuan ei => zhua nei */
    { &pinyin_table[711],  &pinyin_table[2],    &pinyin_table[710],  &pinyin_table[163],  }, /* zhuang ai => zhuan gai */
    { &pinyin_table[711],  &pinyin_table[4],    &pinyin_table[710],  &pinyin_table[165],  }, /* zhuang an => zhuan gan */
    { &pinyin_table[711],  &pinyin_table[5],    &pinyin_table[710],  &pinyin_table[166],  }, /* zhuang ang => zhuan gang */
    { &pinyin_table[711],  &pinyin_table[6],    &pinyin_table[710],  &pinyin_table[167],  }, /* zhuang ao => zhuan gao */
    { &pinyin_table[711],  &pinyin_table[128],  &pinyin_table[710],  &pinyin_table[168],  }, /* zhuang e => zhuan ge */
    { &pinyin_table[711],  &pinyin_table[129],  &pinyin_table[710],  &pinyin_table[170],  }, /* zhuang ei => zhuan gei */
    { &pinyin_table[711],  &pinyin_table[130],  &pinyin_table[710],  &pinyin_table[172],  }, /* zhuang en => zhuan gen */
    { &pinyin_table[711],  &pinyin_table[402],  &pinyin_table[710],  &pinyin_table[178],  }, /* zhuang ou => zhuan gou */
    { &pinyin_table[715],  &pinyin_table[0],    &pinyin_table[705],  &pinyin_table[359],  }, /* zhun a => zhu na */
    { &pinyin_table[715],  &pinyin_table[4],    &pinyin_table[705],  &pinyin_table[363],  }, /* zhun an => zhu nan */
    { &pinyin_table[715],  &pinyin_table[5],    &pinyin_table[705],  &pinyin_table[364],  }, /* zhun ang => zhu nang */
    { &pinyin_table[715],  &pinyin_table[6],    &pinyin_table[705],  &pinyin_table[365],  }, /* zhun ao => zhu nao */
    { &pinyin_table[715],  &pinyin_table[128],  &pinyin_table[705],  &pinyin_table[366],  }, /* zhun e => zhu ne */
    { &pinyin_table[715],  &pinyin_table[129],  &pinyin_table[705],  &pinyin_table[368],  }, /* zhun ei => zhu nei */
    { &pinyin_table[727],  &pinyin_table[0],    &pinyin_table[726],  &pinyin_table[161],  }, /* zuang a => zuan ga */
    { &pinyin_table[727],  &pinyin_table[2],    &pinyin_table[726],  &pinyin_table[163],  }, /* zuang ai => zuan gai */
    { &pinyin_table[727],  &pinyin_table[4],    &pinyin_table[726],  &pinyin_table[165],  }, /* zuang an => zuan gan */
    { &pinyin_table[727],  &pinyin_table[5],    &pinyin_table[726],  &pinyin_table[166],  }, /* zuang ang => zuan gang */
    { &pinyin_table[727],  &pinyin_table[6],    &pinyin_table[726],  &pinyin_table[167],  }, /* zuang ao => zuan gao */
    { &pinyin_table[727],  &pinyin_table[128],  &pinyin_table[726],  &pinyin_table[168],  }, /* zuang e => zuan ge */
    { &pinyin_table[727],  &pinyin_table[129],  &pinyin_table[726],  &pinyin_table[170],  }, /* zuang ei => zuan gei */
    { &pinyin_table[727],  &pinyin_table[130],  &pinyin_table[726],  &pinyin_table[172],  }, /* zuang en => zuan gen */
    { &pinyin_table[727],  &pinyin_table[402],  &pinyin_table[726],  &pinyin_table[178],  }, /* zuang ou => zuan gou */
    { &pinyin_table[731],  &pinyin_table[0],    &pinyin_table[723],  &pinyin_table[359],  }, /* zun a => zu na */
    { &pinyin_table[731],  &pinyin_table[4],    &pinyin_table[723],  &pinyin_table[363],  }, /* zun an => zu nan */
    { &pinyin_table[731],  &pinyin_table[5],    &pinyin_table[723],  &pinyin_table[364],  }, /* zun ang => zu nang */
    { &pinyin_table[731],  &pinyin_table[6],    &pinyin_table[723],  &pinyin_table[365],  }, /* zun ao => zu nao */
    { &pinyin_table[731],  &pinyin_table[128],  &pinyin_table[723],  &pinyin_table[366],  }, /* zun e => zu ne */
    { &pinyin_table[731],  &pinyin_table[129],  &pinyin_table[723],  &pinyin_table[368],  }, /* zun ei => zu nei */
};

