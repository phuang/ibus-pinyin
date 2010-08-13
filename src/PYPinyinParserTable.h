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
        text        : "chong",
        bopomofo    : L"ㄔㄨㄥ",
        sheng       : "ch",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_ONG }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 61 */
        text        : "chou",
        bopomofo    : L"ㄔㄡ",
        sheng       : "ch",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_OU }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 62 */
        text        : "chu",
        bopomofo    : L"ㄔㄨ",
        sheng       : "ch",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_U }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 63 */
        text        : "chuagn",
        bopomofo    : L"",
        sheng       : "ch",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UANG }, { PINYIN_ID_C, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 64 */
        text        : "chuai",
        bopomofo    : L"ㄔㄨㄞ",
        sheng       : "ch",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UAI }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 65 */
        text        : "chuamg",
        bopomofo    : L"",
        sheng       : "ch",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UANG }, { PINYIN_ID_C, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 66 */
        text        : "chuan",
        bopomofo    : L"ㄔㄨㄢ",
        sheng       : "ch",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UAN }, { PINYIN_ID_C, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 67 */
        text        : "chuang",
        bopomofo    : L"ㄔㄨㄤ",
        sheng       : "ch",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UANG }, { PINYIN_ID_C, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : 0
    },
    {  /* 68 */
        text        : "chuei",
        bopomofo    : L"",
        sheng       : "ch",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UI }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 69 */
        text        : "chuen",
        bopomofo    : L"",
        sheng       : "ch",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UN }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 70 */
        text        : "chui",
        bopomofo    : L"ㄔㄨㄟ",
        sheng       : "ch",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UI }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 71 */
        text        : "chun",
        bopomofo    : L"ㄔㄨㄣ",
        sheng       : "ch",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UN }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 72 */
        text        : "chuo",
        bopomofo    : L"ㄔㄨㄛ",
        sheng       : "ch",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_CH, PINYIN_ID_UO }, { PINYIN_ID_C, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 73 */
        text        : "ci",
        bopomofo    : L"ㄘ",
        sheng       : "c",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_I }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 74 */
        text        : "cogn",
        bopomofo    : L"",
        sheng       : "c",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_ONG }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 75 */
        text        : "comg",
        bopomofo    : L"",
        sheng       : "c",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_ONG }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 76 */
        text        : "cong",
        bopomofo    : L"ㄘㄨㄥ",
        sheng       : "c",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_ONG }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 77 */
        text        : "cou",
        bopomofo    : L"ㄘㄡ",
        sheng       : "c",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_OU }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 78 */
        text        : "cu",
        bopomofo    : L"ㄘㄨ",
        sheng       : "c",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_U }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 79 */
        text        : "cuai",
        bopomofo    : L"ㄘㄨㄞ",
        sheng       : "c",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_UAI }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_C_CH
    },
    {  /* 80 */
        text        : "cuan",
        bopomofo    : L"ㄘㄨㄢ",
        sheng       : "c",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_UAN }, { PINYIN_ID_CH, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 81 */
        text        : "cuang",
        bopomofo    : L"ㄘㄨㄤ",
        sheng       : "c",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_UANG }, { PINYIN_ID_CH, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_C_CH | PINYIN_FUZZY_UANG_UAN
    },
    {  /* 82 */
        text        : "cuei",
        bopomofo    : L"",
        sheng       : "c",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_UI }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 83 */
        text        : "cuen",
        bopomofo    : L"",
        sheng       : "c",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_UN }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 84 */
        text        : "cui",
        bopomofo    : L"ㄘㄨㄟ",
        sheng       : "c",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_UI }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 85 */
        text        : "cun",
        bopomofo    : L"ㄘㄨㄣ",
        sheng       : "c",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_UN }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 86 */
        text        : "cuo",
        bopomofo    : L"ㄘㄨㄛ",
        sheng       : "c",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_C, PINYIN_ID_UO }, { PINYIN_ID_CH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 87 */
        text        : "d",
        bopomofo    : L"ㄉ",
        sheng       : "d",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 88 */
        text        : "da",
        bopomofo    : L"ㄉㄚ",
        sheng       : "d",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_A }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 89 */
        text        : "dagn",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 90 */
        text        : "dai",
        bopomofo    : L"ㄉㄞ",
        sheng       : "d",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_AI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 91 */
        text        : "damg",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 92 */
        text        : "dan",
        bopomofo    : L"ㄉㄢ",
        sheng       : "d",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 93 */
        text        : "dang",
        bopomofo    : L"ㄉㄤ",
        sheng       : "d",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 94 */
        text        : "dao",
        bopomofo    : L"ㄉㄠ",
        sheng       : "d",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_AO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 95 */
        text        : "de",
        bopomofo    : L"ㄉㄜ",
        sheng       : "d",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_E }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 96 */
        text        : "degn",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 97 */
        text        : "dei",
        bopomofo    : L"ㄉㄟ",
        sheng       : "d",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_EI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 98 */
        text        : "demg",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 99 */
        text        : "den",
        bopomofo    : L"ㄉㄣ",
        sheng       : "d",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_EN_ENG
    },
    {  /* 100 */
        text        : "deng",
        bopomofo    : L"ㄉㄥ",
        sheng       : "d",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 101 */
        text        : "di",
        bopomofo    : L"ㄉㄧ",
        sheng       : "d",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_I }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 102 */
        text        : "dia",
        bopomofo    : L"ㄉㄧㄚ",
        sheng       : "d",
        yun         : "ia",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_IA }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 103 */
        text        : "dian",
        bopomofo    : L"ㄉㄧㄢ",
        sheng       : "d",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 104 */
        text        : "diang",
        bopomofo    : L"ㄉㄧㄤ",
        sheng       : "d",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_IANG_IAN
    },
    {  /* 105 */
        text        : "diao",
        bopomofo    : L"ㄉㄧㄠ",
        sheng       : "d",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_IAO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 106 */
        text        : "die",
        bopomofo    : L"ㄉㄧㄝ",
        sheng       : "d",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_IE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 107 */
        text        : "dign",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 108 */
        text        : "dimg",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 109 */
        text        : "din",
        bopomofo    : L"ㄉㄧㄣ",
        sheng       : "d",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_IN_ING
    },
    {  /* 110 */
        text        : "ding",
        bopomofo    : L"ㄉㄧㄥ",
        sheng       : "d",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 111 */
        text        : "diou",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_IOU_TO_IU
    },
    {  /* 112 */
        text        : "diu",
        bopomofo    : L"ㄉㄧㄡ",
        sheng       : "d",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 113 */
        text        : "dogn",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 114 */
        text        : "domg",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 115 */
        text        : "dong",
        bopomofo    : L"ㄉㄨㄥ",
        sheng       : "d",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 116 */
        text        : "dou",
        bopomofo    : L"ㄉㄡ",
        sheng       : "d",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_OU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 117 */
        text        : "du",
        bopomofo    : L"ㄉㄨ",
        sheng       : "d",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 118 */
        text        : "duan",
        bopomofo    : L"ㄉㄨㄢ",
        sheng       : "d",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 119 */
        text        : "duang",
        bopomofo    : L"ㄉㄨㄤ",
        sheng       : "d",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 120 */
        text        : "duei",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_UI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 121 */
        text        : "duen",
        bopomofo    : L"",
        sheng       : "d",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 122 */
        text        : "dui",
        bopomofo    : L"ㄉㄨㄟ",
        sheng       : "d",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_UI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 123 */
        text        : "dun",
        bopomofo    : L"ㄉㄨㄣ",
        sheng       : "d",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 124 */
        text        : "duo",
        bopomofo    : L"ㄉㄨㄛ",
        sheng       : "d",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_D, PINYIN_ID_UO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 125 */
        text        : "e",
        bopomofo    : L"ㄜ",
        sheng       : "",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_E }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : 0
    },
    {  /* 126 */
        text        : "ei",
        bopomofo    : L"ㄟ",
        sheng       : "",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_EI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 127 */
        text        : "en",
        bopomofo    : L"ㄣ",
        sheng       : "",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 128 */
        text        : "er",
        bopomofo    : L"ㄦ",
        sheng       : "",
        yun         : "er",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_ER }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 129 */
        text        : "f",
        bopomofo    : L"ㄈ",
        sheng       : "f",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 130 */
        text        : "fa",
        bopomofo    : L"ㄈㄚ",
        sheng       : "f",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_A }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 131 */
        text        : "fagn",
        bopomofo    : L"",
        sheng       : "f",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_ANG }, { PINYIN_ID_H, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 132 */
        text        : "fai",
        bopomofo    : L"ㄈㄞ",
        sheng       : "f",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_AI }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 133 */
        text        : "famg",
        bopomofo    : L"",
        sheng       : "f",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_ANG }, { PINYIN_ID_H, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 134 */
        text        : "fan",
        bopomofo    : L"ㄈㄢ",
        sheng       : "f",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_AN }, { PINYIN_ID_H, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 135 */
        text        : "fang",
        bopomofo    : L"ㄈㄤ",
        sheng       : "f",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_ANG }, { PINYIN_ID_H, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 136 */
        text        : "fao",
        bopomofo    : L"ㄈㄠ",
        sheng       : "f",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_AO }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 137 */
        text        : "fe",
        bopomofo    : L"ㄈㄜ",
        sheng       : "f",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_E }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 138 */
        text        : "fegn",
        bopomofo    : L"",
        sheng       : "f",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_ENG }, { PINYIN_ID_H, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 139 */
        text        : "fei",
        bopomofo    : L"ㄈㄟ",
        sheng       : "f",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_EI }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 140 */
        text        : "femg",
        bopomofo    : L"",
        sheng       : "f",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_ENG }, { PINYIN_ID_H, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 141 */
        text        : "fen",
        bopomofo    : L"ㄈㄣ",
        sheng       : "f",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_EN }, { PINYIN_ID_H, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 142 */
        text        : "feng",
        bopomofo    : L"ㄈㄥ",
        sheng       : "f",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_ENG }, { PINYIN_ID_H, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 143 */
        text        : "fo",
        bopomofo    : L"ㄈㄛ",
        sheng       : "f",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_O }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 144 */
        text        : "fong",
        bopomofo    : L"ㄈㄨㄥ",
        sheng       : "f",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_ONG }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 145 */
        text        : "fou",
        bopomofo    : L"ㄈㄡ",
        sheng       : "f",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_OU }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 146 */
        text        : "fu",
        bopomofo    : L"ㄈㄨ",
        sheng       : "f",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_U }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 147 */
        text        : "fua",
        bopomofo    : L"ㄈㄨㄚ",
        sheng       : "f",
        yun         : "ua",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UA }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 148 */
        text        : "fuai",
        bopomofo    : L"ㄈㄨㄞ",
        sheng       : "f",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UAI }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 149 */
        text        : "fuan",
        bopomofo    : L"ㄈㄨㄢ",
        sheng       : "f",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UAN }, { PINYIN_ID_H, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 150 */
        text        : "fuang",
        bopomofo    : L"ㄈㄨㄤ",
        sheng       : "f",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UANG }, { PINYIN_ID_H, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 151 */
        text        : "fuei",
        bopomofo    : L"",
        sheng       : "f",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UI }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_F_H | PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 152 */
        text        : "fuen",
        bopomofo    : L"",
        sheng       : "f",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UN }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_F_H | PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 153 */
        text        : "fui",
        bopomofo    : L"ㄈㄨㄟ",
        sheng       : "f",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UI }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 154 */
        text        : "fun",
        bopomofo    : L"ㄈㄨㄣ",
        sheng       : "f",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UN }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 155 */
        text        : "fuo",
        bopomofo    : L"ㄈㄨㄛ",
        sheng       : "f",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_F, PINYIN_ID_UO }, { PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_F_H
    },
    {  /* 156 */
        text        : "g",
        bopomofo    : L"ㄍ",
        sheng       : "g",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 157 */
        text        : "ga",
        bopomofo    : L"ㄍㄚ",
        sheng       : "g",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_A }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 158 */
        text        : "gagn",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ANG }, { PINYIN_ID_K, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 159 */
        text        : "gai",
        bopomofo    : L"ㄍㄞ",
        sheng       : "g",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_AI }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 160 */
        text        : "gamg",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ANG }, { PINYIN_ID_K, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 161 */
        text        : "gan",
        bopomofo    : L"ㄍㄢ",
        sheng       : "g",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_AN }, { PINYIN_ID_K, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 162 */
        text        : "gang",
        bopomofo    : L"ㄍㄤ",
        sheng       : "g",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ANG }, { PINYIN_ID_K, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 163 */
        text        : "gao",
        bopomofo    : L"ㄍㄠ",
        sheng       : "g",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_AO }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 164 */
        text        : "ge",
        bopomofo    : L"ㄍㄜ",
        sheng       : "g",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_E }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 165 */
        text        : "gegn",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ENG }, { PINYIN_ID_K, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 166 */
        text        : "gei",
        bopomofo    : L"ㄍㄟ",
        sheng       : "g",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_EI }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 167 */
        text        : "gemg",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ENG }, { PINYIN_ID_K, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 168 */
        text        : "gen",
        bopomofo    : L"ㄍㄣ",
        sheng       : "g",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_EN }, { PINYIN_ID_K, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 169 */
        text        : "geng",
        bopomofo    : L"ㄍㄥ",
        sheng       : "g",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ENG }, { PINYIN_ID_K, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 170 */
        text        : "gogn",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ONG }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 171 */
        text        : "gomg",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ONG }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 172 */
        text        : "gong",
        bopomofo    : L"ㄍㄨㄥ",
        sheng       : "g",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_ONG }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 173 */
        text        : "gou",
        bopomofo    : L"ㄍㄡ",
        sheng       : "g",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_OU }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 174 */
        text        : "gu",
        bopomofo    : L"ㄍㄨ",
        sheng       : "g",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_U }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 175 */
        text        : "gua",
        bopomofo    : L"ㄍㄨㄚ",
        sheng       : "g",
        yun         : "ua",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UA }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 176 */
        text        : "guagn",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UANG }, { PINYIN_ID_K, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 177 */
        text        : "guai",
        bopomofo    : L"ㄍㄨㄞ",
        sheng       : "g",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UAI }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 178 */
        text        : "guamg",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UANG }, { PINYIN_ID_K, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 179 */
        text        : "guan",
        bopomofo    : L"ㄍㄨㄢ",
        sheng       : "g",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UAN }, { PINYIN_ID_K, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 180 */
        text        : "guang",
        bopomofo    : L"ㄍㄨㄤ",
        sheng       : "g",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UANG }, { PINYIN_ID_K, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 181 */
        text        : "guei",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UI }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 182 */
        text        : "guen",
        bopomofo    : L"",
        sheng       : "g",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UN }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 183 */
        text        : "gui",
        bopomofo    : L"ㄍㄨㄟ",
        sheng       : "g",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UI }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 184 */
        text        : "gun",
        bopomofo    : L"ㄍㄨㄣ",
        sheng       : "g",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UN }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 185 */
        text        : "guo",
        bopomofo    : L"ㄍㄨㄛ",
        sheng       : "g",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_G, PINYIN_ID_UO }, { PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 186 */
        text        : "h",
        bopomofo    : L"ㄏ",
        sheng       : "h",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ZERO }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 187 */
        text        : "ha",
        bopomofo    : L"ㄏㄚ",
        sheng       : "h",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_A }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 188 */
        text        : "hagn",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ANG }, { PINYIN_ID_F, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 189 */
        text        : "hai",
        bopomofo    : L"ㄏㄞ",
        sheng       : "h",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_AI }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 190 */
        text        : "hamg",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ANG }, { PINYIN_ID_F, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 191 */
        text        : "han",
        bopomofo    : L"ㄏㄢ",
        sheng       : "h",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_AN }, { PINYIN_ID_F, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 192 */
        text        : "hang",
        bopomofo    : L"ㄏㄤ",
        sheng       : "h",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ANG }, { PINYIN_ID_F, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 193 */
        text        : "hao",
        bopomofo    : L"ㄏㄠ",
        sheng       : "h",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_AO }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 194 */
        text        : "he",
        bopomofo    : L"ㄏㄜ",
        sheng       : "h",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_E }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 195 */
        text        : "hegn",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ENG }, { PINYIN_ID_F, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 196 */
        text        : "hei",
        bopomofo    : L"ㄏㄟ",
        sheng       : "h",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_EI }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 197 */
        text        : "hemg",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ENG }, { PINYIN_ID_F, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 198 */
        text        : "hen",
        bopomofo    : L"ㄏㄣ",
        sheng       : "h",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_EN }, { PINYIN_ID_F, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 199 */
        text        : "heng",
        bopomofo    : L"ㄏㄥ",
        sheng       : "h",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ENG }, { PINYIN_ID_F, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 200 */
        text        : "ho",
        bopomofo    : L"ㄏㄛ",
        sheng       : "h",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_O }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_FUZZY_H_F
    },
    {  /* 201 */
        text        : "hogn",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ONG }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 202 */
        text        : "homg",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ONG }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 203 */
        text        : "hong",
        bopomofo    : L"ㄏㄨㄥ",
        sheng       : "h",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_ONG }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 204 */
        text        : "hou",
        bopomofo    : L"ㄏㄡ",
        sheng       : "h",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_OU }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 205 */
        text        : "hu",
        bopomofo    : L"ㄏㄨ",
        sheng       : "h",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_U }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 206 */
        text        : "hua",
        bopomofo    : L"ㄏㄨㄚ",
        sheng       : "h",
        yun         : "ua",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UA }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 207 */
        text        : "huagn",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UANG }, { PINYIN_ID_F, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 208 */
        text        : "huai",
        bopomofo    : L"ㄏㄨㄞ",
        sheng       : "h",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UAI }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 209 */
        text        : "huamg",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UANG }, { PINYIN_ID_F, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 210 */
        text        : "huan",
        bopomofo    : L"ㄏㄨㄢ",
        sheng       : "h",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UAN }, { PINYIN_ID_F, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 211 */
        text        : "huang",
        bopomofo    : L"ㄏㄨㄤ",
        sheng       : "h",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UANG }, { PINYIN_ID_F, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 212 */
        text        : "huei",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UI }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 213 */
        text        : "huen",
        bopomofo    : L"",
        sheng       : "h",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UN }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 214 */
        text        : "hui",
        bopomofo    : L"ㄏㄨㄟ",
        sheng       : "h",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UI }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 215 */
        text        : "hun",
        bopomofo    : L"ㄏㄨㄣ",
        sheng       : "h",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UN }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 216 */
        text        : "huo",
        bopomofo    : L"ㄏㄨㄛ",
        sheng       : "h",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_H, PINYIN_ID_UO }, { PINYIN_ID_F, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 217 */
        text        : "j",
        bopomofo    : L"ㄐ",
        sheng       : "j",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 218 */
        text        : "ji",
        bopomofo    : L"ㄐㄧ",
        sheng       : "j",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_I }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 219 */
        text        : "jia",
        bopomofo    : L"ㄐㄧㄚ",
        sheng       : "j",
        yun         : "ia",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IA }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 220 */
        text        : "jiagn",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 221 */
        text        : "jiamg",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 222 */
        text        : "jian",
        bopomofo    : L"ㄐㄧㄢ",
        sheng       : "j",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 223 */
        text        : "jiang",
        bopomofo    : L"ㄐㄧㄤ",
        sheng       : "j",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 224 */
        text        : "jiao",
        bopomofo    : L"ㄐㄧㄠ",
        sheng       : "j",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IAO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 225 */
        text        : "jie",
        bopomofo    : L"ㄐㄧㄝ",
        sheng       : "j",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 226 */
        text        : "jign",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 227 */
        text        : "jimg",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 228 */
        text        : "jin",
        bopomofo    : L"ㄐㄧㄣ",
        sheng       : "j",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 229 */
        text        : "jing",
        bopomofo    : L"ㄐㄧㄥ",
        sheng       : "j",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 230 */
        text        : "jiogn",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 231 */
        text        : "jiomg",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 232 */
        text        : "jiong",
        bopomofo    : L"ㄐㄩㄥ",
        sheng       : "j",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 233 */
        text        : "jiou",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_IOU_TO_IU
    },
    {  /* 234 */
        text        : "jiu",
        bopomofo    : L"ㄐㄧㄡ",
        sheng       : "j",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 235 */
        text        : "ju",
        bopomofo    : L"ㄐㄩ",
        sheng       : "j",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 236 */
        text        : "juan",
        bopomofo    : L"ㄐㄩㄢ",
        sheng       : "j",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 237 */
        text        : "juang",
        bopomofo    : L"ㄐㄩㄤ",
        sheng       : "j",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 238 */
        text        : "jue",
        bopomofo    : L"ㄐㄩㄝ",
        sheng       : "j",
        yun         : "ue",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 239 */
        text        : "juen",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 240 */
        text        : "jun",
        bopomofo    : L"ㄐㄩㄣ",
        sheng       : "j",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 241 */
        text        : "jv",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 242 */
        text        : "jvan",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 243 */
        text        : "jvang",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN | PINYIN_CORRECT_V_TO_U
    },
    {  /* 244 */
        text        : "jve",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "ue",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 245 */
        text        : "jven",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN | PINYIN_CORRECT_V_TO_U
    },
    {  /* 246 */
        text        : "jvn",
        bopomofo    : L"",
        sheng       : "j",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_J, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 247 */
        text        : "k",
        bopomofo    : L"ㄎ",
        sheng       : "k",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ZERO }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 248 */
        text        : "ka",
        bopomofo    : L"ㄎㄚ",
        sheng       : "k",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_A }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 249 */
        text        : "kagn",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ANG }, { PINYIN_ID_G, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 250 */
        text        : "kai",
        bopomofo    : L"ㄎㄞ",
        sheng       : "k",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_AI }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 251 */
        text        : "kamg",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ANG }, { PINYIN_ID_G, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 252 */
        text        : "kan",
        bopomofo    : L"ㄎㄢ",
        sheng       : "k",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_AN }, { PINYIN_ID_G, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 253 */
        text        : "kang",
        bopomofo    : L"ㄎㄤ",
        sheng       : "k",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ANG }, { PINYIN_ID_G, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 254 */
        text        : "kao",
        bopomofo    : L"ㄎㄠ",
        sheng       : "k",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_AO }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 255 */
        text        : "ke",
        bopomofo    : L"ㄎㄜ",
        sheng       : "k",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_E }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 256 */
        text        : "kegn",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ENG }, { PINYIN_ID_G, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 257 */
        text        : "kei",
        bopomofo    : L"ㄎㄟ",
        sheng       : "k",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_EI }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_K_G
    },
    {  /* 258 */
        text        : "kemg",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ENG }, { PINYIN_ID_G, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 259 */
        text        : "ken",
        bopomofo    : L"ㄎㄣ",
        sheng       : "k",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_EN }, { PINYIN_ID_G, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 260 */
        text        : "keng",
        bopomofo    : L"ㄎㄥ",
        sheng       : "k",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ENG }, { PINYIN_ID_G, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 261 */
        text        : "kogn",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ONG }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 262 */
        text        : "komg",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ONG }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 263 */
        text        : "kong",
        bopomofo    : L"ㄎㄨㄥ",
        sheng       : "k",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_ONG }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 264 */
        text        : "kou",
        bopomofo    : L"ㄎㄡ",
        sheng       : "k",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_OU }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 265 */
        text        : "ku",
        bopomofo    : L"ㄎㄨ",
        sheng       : "k",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_U }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 266 */
        text        : "kua",
        bopomofo    : L"ㄎㄨㄚ",
        sheng       : "k",
        yun         : "ua",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UA }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 267 */
        text        : "kuagn",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UANG }, { PINYIN_ID_G, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 268 */
        text        : "kuai",
        bopomofo    : L"ㄎㄨㄞ",
        sheng       : "k",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UAI }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 269 */
        text        : "kuamg",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UANG }, { PINYIN_ID_G, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 270 */
        text        : "kuan",
        bopomofo    : L"ㄎㄨㄢ",
        sheng       : "k",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UAN }, { PINYIN_ID_G, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 271 */
        text        : "kuang",
        bopomofo    : L"ㄎㄨㄤ",
        sheng       : "k",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UANG }, { PINYIN_ID_G, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 272 */
        text        : "kuei",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UI }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 273 */
        text        : "kuen",
        bopomofo    : L"",
        sheng       : "k",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UN }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 274 */
        text        : "kui",
        bopomofo    : L"ㄎㄨㄟ",
        sheng       : "k",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UI }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 275 */
        text        : "kun",
        bopomofo    : L"ㄎㄨㄣ",
        sheng       : "k",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UN }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 276 */
        text        : "kuo",
        bopomofo    : L"ㄎㄨㄛ",
        sheng       : "k",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_K, PINYIN_ID_UO }, { PINYIN_ID_G, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 277 */
        text        : "l",
        bopomofo    : L"ㄌ",
        sheng       : "l",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 278 */
        text        : "la",
        bopomofo    : L"ㄌㄚ",
        sheng       : "l",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_A }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 279 */
        text        : "lagn",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ANG }, { PINYIN_ID_N, PINYIN_ID_AN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 280 */
        text        : "lai",
        bopomofo    : L"ㄌㄞ",
        sheng       : "l",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_AI }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 281 */
        text        : "lamg",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ANG }, { PINYIN_ID_N, PINYIN_ID_AN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 282 */
        text        : "lan",
        bopomofo    : L"ㄌㄢ",
        sheng       : "l",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_AN }, { PINYIN_ID_N, PINYIN_ID_ANG }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 283 */
        text        : "lang",
        bopomofo    : L"ㄌㄤ",
        sheng       : "l",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ANG }, { PINYIN_ID_N, PINYIN_ID_AN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 284 */
        text        : "lao",
        bopomofo    : L"ㄌㄠ",
        sheng       : "l",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_AO }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 285 */
        text        : "le",
        bopomofo    : L"ㄌㄜ",
        sheng       : "l",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_E }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 286 */
        text        : "legn",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ENG }, { PINYIN_ID_N, PINYIN_ID_EN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 287 */
        text        : "lei",
        bopomofo    : L"ㄌㄟ",
        sheng       : "l",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_EI }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 288 */
        text        : "lemg",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ENG }, { PINYIN_ID_N, PINYIN_ID_EN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 289 */
        text        : "len",
        bopomofo    : L"ㄌㄣ",
        sheng       : "l",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_EN }, { PINYIN_ID_N, PINYIN_ID_ENG }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_L_N | PINYIN_FUZZY_L_R | PINYIN_FUZZY_EN_ENG
    },
    {  /* 290 */
        text        : "leng",
        bopomofo    : L"ㄌㄥ",
        sheng       : "l",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ENG }, { PINYIN_ID_N, PINYIN_ID_EN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 291 */
        text        : "li",
        bopomofo    : L"ㄌㄧ",
        sheng       : "l",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_I }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 292 */
        text        : "lia",
        bopomofo    : L"ㄌㄧㄚ",
        sheng       : "l",
        yun         : "ia",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IA }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 293 */
        text        : "liagn",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IANG }, { PINYIN_ID_N, PINYIN_ID_IAN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 294 */
        text        : "liamg",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IANG }, { PINYIN_ID_N, PINYIN_ID_IAN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 295 */
        text        : "lian",
        bopomofo    : L"ㄌㄧㄢ",
        sheng       : "l",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IAN }, { PINYIN_ID_N, PINYIN_ID_IANG }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 296 */
        text        : "liang",
        bopomofo    : L"ㄌㄧㄤ",
        sheng       : "l",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IANG }, { PINYIN_ID_N, PINYIN_ID_IAN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 297 */
        text        : "liao",
        bopomofo    : L"ㄌㄧㄠ",
        sheng       : "l",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IAO }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 298 */
        text        : "lie",
        bopomofo    : L"ㄌㄧㄝ",
        sheng       : "l",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IE }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 299 */
        text        : "lign",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ING }, { PINYIN_ID_N, PINYIN_ID_IN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 300 */
        text        : "limg",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ING }, { PINYIN_ID_N, PINYIN_ID_IN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 301 */
        text        : "lin",
        bopomofo    : L"ㄌㄧㄣ",
        sheng       : "l",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IN }, { PINYIN_ID_N, PINYIN_ID_ING }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 302 */
        text        : "ling",
        bopomofo    : L"ㄌㄧㄥ",
        sheng       : "l",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ING }, { PINYIN_ID_N, PINYIN_ID_IN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 303 */
        text        : "liou",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IU }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_IOU_TO_IU
    },
    {  /* 304 */
        text        : "liu",
        bopomofo    : L"ㄌㄧㄡ",
        sheng       : "l",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_IU }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 305 */
        text        : "lo",
        bopomofo    : L"ㄌㄛ",
        sheng       : "l",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_O }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 306 */
        text        : "logn",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ONG }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 307 */
        text        : "lomg",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ONG }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 308 */
        text        : "long",
        bopomofo    : L"ㄌㄨㄥ",
        sheng       : "l",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_ONG }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 309 */
        text        : "lou",
        bopomofo    : L"ㄌㄡ",
        sheng       : "l",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_OU }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 310 */
        text        : "lu",
        bopomofo    : L"ㄌㄨ",
        sheng       : "l",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_U }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 311 */
        text        : "luan",
        bopomofo    : L"ㄌㄨㄢ",
        sheng       : "l",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_UAN }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 312 */
        text        : "luang",
        bopomofo    : L"ㄌㄨㄤ",
        sheng       : "l",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_UANG }, { PINYIN_ID_N, PINYIN_ID_UAN }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 313 */
        text        : "lue",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "üe",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_VE }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_UE_TO_VE
    },
    {  /* 314 */
        text        : "luei",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_UI }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_L_R | PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 315 */
        text        : "luen",
        bopomofo    : L"",
        sheng       : "l",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_UN }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 316 */
        text        : "lui",
        bopomofo    : L"ㄌㄨㄟ",
        sheng       : "l",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_UI }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_L_R
    },
    {  /* 317 */
        text        : "lun",
        bopomofo    : L"ㄌㄨㄣ",
        sheng       : "l",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_UN }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 318 */
        text        : "luo",
        bopomofo    : L"ㄌㄨㄛ",
        sheng       : "l",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_UO }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 319 */
        text        : "lv",
        bopomofo    : L"ㄌㄩ",
        sheng       : "l",
        yun         : "ü",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_V }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 320 */
        text        : "lve",
        bopomofo    : L"ㄌㄩㄝ",
        sheng       : "l",
        yun         : "üe",
        pinyin_id   : {{ PINYIN_ID_L, PINYIN_ID_VE }, { PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_R, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 321 */
        text        : "m",
        bopomofo    : L"ㄇ",
        sheng       : "m",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 322 */
        text        : "ma",
        bopomofo    : L"ㄇㄚ",
        sheng       : "m",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_A }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 323 */
        text        : "magn",
        bopomofo    : L"",
        sheng       : "m",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 324 */
        text        : "mai",
        bopomofo    : L"ㄇㄞ",
        sheng       : "m",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_AI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 325 */
        text        : "mamg",
        bopomofo    : L"",
        sheng       : "m",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 326 */
        text        : "man",
        bopomofo    : L"ㄇㄢ",
        sheng       : "m",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 327 */
        text        : "mang",
        bopomofo    : L"ㄇㄤ",
        sheng       : "m",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 328 */
        text        : "mao",
        bopomofo    : L"ㄇㄠ",
        sheng       : "m",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_AO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 329 */
        text        : "me",
        bopomofo    : L"ㄇㄜ",
        sheng       : "m",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_E }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 330 */
        text        : "megn",
        bopomofo    : L"",
        sheng       : "m",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 331 */
        text        : "mei",
        bopomofo    : L"ㄇㄟ",
        sheng       : "m",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_EI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 332 */
        text        : "memg",
        bopomofo    : L"",
        sheng       : "m",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 333 */
        text        : "men",
        bopomofo    : L"ㄇㄣ",
        sheng       : "m",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 334 */
        text        : "meng",
        bopomofo    : L"ㄇㄥ",
        sheng       : "m",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 335 */
        text        : "mi",
        bopomofo    : L"ㄇㄧ",
        sheng       : "m",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_I }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 336 */
        text        : "mian",
        bopomofo    : L"ㄇㄧㄢ",
        sheng       : "m",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 337 */
        text        : "miang",
        bopomofo    : L"ㄇㄧㄤ",
        sheng       : "m",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_IANG_IAN
    },
    {  /* 338 */
        text        : "miao",
        bopomofo    : L"ㄇㄧㄠ",
        sheng       : "m",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_IAO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 339 */
        text        : "mie",
        bopomofo    : L"ㄇㄧㄝ",
        sheng       : "m",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_IE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 340 */
        text        : "mign",
        bopomofo    : L"",
        sheng       : "m",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 341 */
        text        : "mimg",
        bopomofo    : L"",
        sheng       : "m",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 342 */
        text        : "min",
        bopomofo    : L"ㄇㄧㄣ",
        sheng       : "m",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 343 */
        text        : "ming",
        bopomofo    : L"ㄇㄧㄥ",
        sheng       : "m",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 344 */
        text        : "miou",
        bopomofo    : L"",
        sheng       : "m",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_IOU_TO_IU
    },
    {  /* 345 */
        text        : "miu",
        bopomofo    : L"ㄇㄧㄡ",
        sheng       : "m",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 346 */
        text        : "mo",
        bopomofo    : L"ㄇㄛ",
        sheng       : "m",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_O }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 347 */
        text        : "mou",
        bopomofo    : L"ㄇㄡ",
        sheng       : "m",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_OU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 348 */
        text        : "mu",
        bopomofo    : L"ㄇㄨ",
        sheng       : "m",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_M, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 349 */
        text        : "n",
        bopomofo    : L"ㄋ",
        sheng       : "n",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ZERO }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 350 */
        text        : "na",
        bopomofo    : L"ㄋㄚ",
        sheng       : "n",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_A }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 351 */
        text        : "nagn",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ANG }, { PINYIN_ID_L, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 352 */
        text        : "nai",
        bopomofo    : L"ㄋㄞ",
        sheng       : "n",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_AI }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 353 */
        text        : "namg",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ANG }, { PINYIN_ID_L, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 354 */
        text        : "nan",
        bopomofo    : L"ㄋㄢ",
        sheng       : "n",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_AN }, { PINYIN_ID_L, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 355 */
        text        : "nang",
        bopomofo    : L"ㄋㄤ",
        sheng       : "n",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ANG }, { PINYIN_ID_L, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 356 */
        text        : "nao",
        bopomofo    : L"ㄋㄠ",
        sheng       : "n",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_AO }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 357 */
        text        : "ne",
        bopomofo    : L"ㄋㄜ",
        sheng       : "n",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_E }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 358 */
        text        : "negn",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ENG }, { PINYIN_ID_L, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 359 */
        text        : "nei",
        bopomofo    : L"ㄋㄟ",
        sheng       : "n",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_EI }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 360 */
        text        : "nemg",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ENG }, { PINYIN_ID_L, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 361 */
        text        : "nen",
        bopomofo    : L"ㄋㄣ",
        sheng       : "n",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_EN }, { PINYIN_ID_L, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 362 */
        text        : "neng",
        bopomofo    : L"ㄋㄥ",
        sheng       : "n",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ENG }, { PINYIN_ID_L, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 363 */
        text        : "ni",
        bopomofo    : L"ㄋㄧ",
        sheng       : "n",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_I }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 364 */
        text        : "nia",
        bopomofo    : L"ㄋㄧㄚ",
        sheng       : "n",
        yun         : "ia",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IA }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_N_L
    },
    {  /* 365 */
        text        : "niagn",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IANG }, { PINYIN_ID_L, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 366 */
        text        : "niamg",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IANG }, { PINYIN_ID_L, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 367 */
        text        : "nian",
        bopomofo    : L"ㄋㄧㄢ",
        sheng       : "n",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IAN }, { PINYIN_ID_L, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 368 */
        text        : "niang",
        bopomofo    : L"ㄋㄧㄤ",
        sheng       : "n",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IANG }, { PINYIN_ID_L, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 369 */
        text        : "niao",
        bopomofo    : L"ㄋㄧㄠ",
        sheng       : "n",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IAO }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 370 */
        text        : "nie",
        bopomofo    : L"ㄋㄧㄝ",
        sheng       : "n",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IE }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 371 */
        text        : "nign",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ING }, { PINYIN_ID_L, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 372 */
        text        : "nimg",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ING }, { PINYIN_ID_L, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 373 */
        text        : "nin",
        bopomofo    : L"ㄋㄧㄣ",
        sheng       : "n",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IN }, { PINYIN_ID_L, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 374 */
        text        : "ning",
        bopomofo    : L"ㄋㄧㄥ",
        sheng       : "n",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ING }, { PINYIN_ID_L, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 375 */
        text        : "niou",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IU }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_IOU_TO_IU
    },
    {  /* 376 */
        text        : "niu",
        bopomofo    : L"ㄋㄧㄡ",
        sheng       : "n",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_IU }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 377 */
        text        : "no",
        bopomofo    : L"ㄋㄛ",
        sheng       : "n",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_O }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_FUZZY_N_L
    },
    {  /* 378 */
        text        : "nogn",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ONG }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 379 */
        text        : "nomg",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ONG }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 380 */
        text        : "nong",
        bopomofo    : L"ㄋㄨㄥ",
        sheng       : "n",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_ONG }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 381 */
        text        : "nou",
        bopomofo    : L"ㄋㄡ",
        sheng       : "n",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_OU }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 382 */
        text        : "nu",
        bopomofo    : L"ㄋㄨ",
        sheng       : "n",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_U }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 383 */
        text        : "nuan",
        bopomofo    : L"ㄋㄨㄢ",
        sheng       : "n",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_UAN }, { PINYIN_ID_L, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 384 */
        text        : "nuang",
        bopomofo    : L"ㄋㄨㄤ",
        sheng       : "n",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_UANG }, { PINYIN_ID_L, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 385 */
        text        : "nue",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "üe",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_VE }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_UE_TO_VE
    },
    {  /* 386 */
        text        : "nuen",
        bopomofo    : L"",
        sheng       : "n",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_UN }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_N_L | PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 387 */
        text        : "nun",
        bopomofo    : L"ㄋㄨㄣ",
        sheng       : "n",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_UN }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_N_L
    },
    {  /* 388 */
        text        : "nuo",
        bopomofo    : L"ㄋㄨㄛ",
        sheng       : "n",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_UO }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 389 */
        text        : "nv",
        bopomofo    : L"ㄋㄩ",
        sheng       : "n",
        yun         : "ü",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_V }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 390 */
        text        : "nve",
        bopomofo    : L"ㄋㄩㄝ",
        sheng       : "n",
        yun         : "üe",
        pinyin_id   : {{ PINYIN_ID_N, PINYIN_ID_VE }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 391 */
        text        : "o",
        bopomofo    : L"ㄛ",
        sheng       : "",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_O }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : 0
    },
    {  /* 392 */
        text        : "ou",
        bopomofo    : L"ㄡ",
        sheng       : "",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_ZERO, PINYIN_ID_OU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 393 */
        text        : "p",
        bopomofo    : L"ㄆ",
        sheng       : "p",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 394 */
        text        : "pa",
        bopomofo    : L"ㄆㄚ",
        sheng       : "p",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_A }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 395 */
        text        : "pagn",
        bopomofo    : L"",
        sheng       : "p",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 396 */
        text        : "pai",
        bopomofo    : L"ㄆㄞ",
        sheng       : "p",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_AI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 397 */
        text        : "pamg",
        bopomofo    : L"",
        sheng       : "p",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 398 */
        text        : "pan",
        bopomofo    : L"ㄆㄢ",
        sheng       : "p",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 399 */
        text        : "pang",
        bopomofo    : L"ㄆㄤ",
        sheng       : "p",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 400 */
        text        : "pao",
        bopomofo    : L"ㄆㄠ",
        sheng       : "p",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_AO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 401 */
        text        : "pegn",
        bopomofo    : L"",
        sheng       : "p",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 402 */
        text        : "pei",
        bopomofo    : L"ㄆㄟ",
        sheng       : "p",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_EI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 403 */
        text        : "pemg",
        bopomofo    : L"",
        sheng       : "p",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 404 */
        text        : "pen",
        bopomofo    : L"ㄆㄣ",
        sheng       : "p",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 405 */
        text        : "peng",
        bopomofo    : L"ㄆㄥ",
        sheng       : "p",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 406 */
        text        : "pi",
        bopomofo    : L"ㄆㄧ",
        sheng       : "p",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_I }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 407 */
        text        : "pian",
        bopomofo    : L"ㄆㄧㄢ",
        sheng       : "p",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 408 */
        text        : "piang",
        bopomofo    : L"ㄆㄧㄤ",
        sheng       : "p",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_IANG_IAN
    },
    {  /* 409 */
        text        : "piao",
        bopomofo    : L"ㄆㄧㄠ",
        sheng       : "p",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_IAO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 410 */
        text        : "pie",
        bopomofo    : L"ㄆㄧㄝ",
        sheng       : "p",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_IE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 411 */
        text        : "pign",
        bopomofo    : L"",
        sheng       : "p",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 412 */
        text        : "pimg",
        bopomofo    : L"",
        sheng       : "p",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 413 */
        text        : "pin",
        bopomofo    : L"ㄆㄧㄣ",
        sheng       : "p",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 414 */
        text        : "ping",
        bopomofo    : L"ㄆㄧㄥ",
        sheng       : "p",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 415 */
        text        : "po",
        bopomofo    : L"ㄆㄛ",
        sheng       : "p",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_O }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 416 */
        text        : "pou",
        bopomofo    : L"ㄆㄡ",
        sheng       : "p",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_OU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 417 */
        text        : "pu",
        bopomofo    : L"ㄆㄨ",
        sheng       : "p",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_P, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 418 */
        text        : "q",
        bopomofo    : L"ㄑ",
        sheng       : "q",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 419 */
        text        : "qi",
        bopomofo    : L"ㄑㄧ",
        sheng       : "q",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_I }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 420 */
        text        : "qia",
        bopomofo    : L"ㄑㄧㄚ",
        sheng       : "q",
        yun         : "ia",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IA }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 421 */
        text        : "qiagn",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 422 */
        text        : "qiamg",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 423 */
        text        : "qian",
        bopomofo    : L"ㄑㄧㄢ",
        sheng       : "q",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 424 */
        text        : "qiang",
        bopomofo    : L"ㄑㄧㄤ",
        sheng       : "q",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 425 */
        text        : "qiao",
        bopomofo    : L"ㄑㄧㄠ",
        sheng       : "q",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IAO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 426 */
        text        : "qie",
        bopomofo    : L"ㄑㄧㄝ",
        sheng       : "q",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 427 */
        text        : "qign",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 428 */
        text        : "qimg",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 429 */
        text        : "qin",
        bopomofo    : L"ㄑㄧㄣ",
        sheng       : "q",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 430 */
        text        : "qing",
        bopomofo    : L"ㄑㄧㄥ",
        sheng       : "q",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 431 */
        text        : "qiogn",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 432 */
        text        : "qiomg",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 433 */
        text        : "qiong",
        bopomofo    : L"ㄑㄩㄥ",
        sheng       : "q",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 434 */
        text        : "qiou",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_IOU_TO_IU
    },
    {  /* 435 */
        text        : "qiu",
        bopomofo    : L"ㄑㄧㄡ",
        sheng       : "q",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 436 */
        text        : "qu",
        bopomofo    : L"ㄑㄩ",
        sheng       : "q",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 437 */
        text        : "quan",
        bopomofo    : L"ㄑㄩㄢ",
        sheng       : "q",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 438 */
        text        : "quang",
        bopomofo    : L"ㄑㄩㄤ",
        sheng       : "q",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 439 */
        text        : "que",
        bopomofo    : L"ㄑㄩㄝ",
        sheng       : "q",
        yun         : "ue",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 440 */
        text        : "quen",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 441 */
        text        : "qun",
        bopomofo    : L"ㄑㄩㄣ",
        sheng       : "q",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 442 */
        text        : "qv",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 443 */
        text        : "qvan",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 444 */
        text        : "qvang",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN | PINYIN_CORRECT_V_TO_U
    },
    {  /* 445 */
        text        : "qve",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "ue",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 446 */
        text        : "qven",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN | PINYIN_CORRECT_V_TO_U
    },
    {  /* 447 */
        text        : "qvn",
        bopomofo    : L"",
        sheng       : "q",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Q, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 448 */
        text        : "r",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ZERO }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 449 */
        text        : "ra",
        bopomofo    : L"ㄖㄚ",
        sheng       : "r",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_A }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 450 */
        text        : "ragn",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ANG }, { PINYIN_ID_L, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 451 */
        text        : "rai",
        bopomofo    : L"ㄖㄞ",
        sheng       : "r",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_AI }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 452 */
        text        : "ramg",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ANG }, { PINYIN_ID_L, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 453 */
        text        : "ran",
        bopomofo    : L"ㄖㄢ",
        sheng       : "r",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_AN }, { PINYIN_ID_L, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 454 */
        text        : "rang",
        bopomofo    : L"ㄖㄤ",
        sheng       : "r",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ANG }, { PINYIN_ID_L, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 455 */
        text        : "rao",
        bopomofo    : L"ㄖㄠ",
        sheng       : "r",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_AO }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 456 */
        text        : "re",
        bopomofo    : L"ㄖㄜ",
        sheng       : "r",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_E }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 457 */
        text        : "regn",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ENG }, { PINYIN_ID_L, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 458 */
        text        : "rei",
        bopomofo    : L"ㄖㄟ",
        sheng       : "r",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_EI }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 459 */
        text        : "remg",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ENG }, { PINYIN_ID_L, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 460 */
        text        : "ren",
        bopomofo    : L"ㄖㄣ",
        sheng       : "r",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_EN }, { PINYIN_ID_L, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 461 */
        text        : "reng",
        bopomofo    : L"ㄖㄥ",
        sheng       : "r",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ENG }, { PINYIN_ID_L, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 462 */
        text        : "ri",
        bopomofo    : L"ㄖ",
        sheng       : "r",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_I }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 463 */
        text        : "ria",
        bopomofo    : L"ㄖㄧㄚ",
        sheng       : "r",
        yun         : "ia",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_IA }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 464 */
        text        : "rian",
        bopomofo    : L"ㄖㄧㄢ",
        sheng       : "r",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_IAN }, { PINYIN_ID_L, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 465 */
        text        : "riang",
        bopomofo    : L"ㄖㄧㄤ",
        sheng       : "r",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_IANG }, { PINYIN_ID_L, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 466 */
        text        : "riao",
        bopomofo    : L"ㄖㄧㄠ",
        sheng       : "r",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_IAO }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 467 */
        text        : "rie",
        bopomofo    : L"ㄖㄧㄝ",
        sheng       : "r",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_IE }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 468 */
        text        : "rin",
        bopomofo    : L"ㄖㄧㄣ",
        sheng       : "r",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_IN }, { PINYIN_ID_L, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 469 */
        text        : "ring",
        bopomofo    : L"ㄖㄧㄥ",
        sheng       : "r",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ING }, { PINYIN_ID_L, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 470 */
        text        : "riou",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_IU }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_R_L | PINYIN_CORRECT_IOU_TO_IU
    },
    {  /* 471 */
        text        : "riu",
        bopomofo    : L"ㄖㄧㄡ",
        sheng       : "r",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_IU }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 472 */
        text        : "ro",
        bopomofo    : L"ㄖㄛ",
        sheng       : "r",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_O }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 473 */
        text        : "rogn",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ONG }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 474 */
        text        : "romg",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ONG }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 475 */
        text        : "rong",
        bopomofo    : L"ㄖㄨㄥ",
        sheng       : "r",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_ONG }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 476 */
        text        : "rou",
        bopomofo    : L"ㄖㄡ",
        sheng       : "r",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_OU }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 477 */
        text        : "ru",
        bopomofo    : L"ㄖㄨ",
        sheng       : "r",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_U }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 478 */
        text        : "ruan",
        bopomofo    : L"ㄖㄨㄢ",
        sheng       : "r",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_UAN }, { PINYIN_ID_L, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 479 */
        text        : "ruang",
        bopomofo    : L"ㄖㄨㄤ",
        sheng       : "r",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_UANG }, { PINYIN_ID_L, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 480 */
        text        : "rue",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "üe",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_VE }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_R_L | PINYIN_CORRECT_UE_TO_VE
    },
    {  /* 481 */
        text        : "ruei",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_UI }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 482 */
        text        : "ruen",
        bopomofo    : L"",
        sheng       : "r",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_UN }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 483 */
        text        : "rui",
        bopomofo    : L"ㄖㄨㄟ",
        sheng       : "r",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_UI }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 484 */
        text        : "run",
        bopomofo    : L"ㄖㄨㄣ",
        sheng       : "r",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_UN }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 485 */
        text        : "ruo",
        bopomofo    : L"ㄖㄨㄛ",
        sheng       : "r",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_UO }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 486 */
        text        : "rv",
        bopomofo    : L"ㄖㄩ",
        sheng       : "r",
        yun         : "ü",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_V }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 487 */
        text        : "rve",
        bopomofo    : L"ㄖㄩㄝ",
        sheng       : "r",
        yun         : "üe",
        pinyin_id   : {{ PINYIN_ID_R, PINYIN_ID_VE }, { PINYIN_ID_L, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_R_L
    },
    {  /* 488 */
        text        : "s",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 489 */
        text        : "sa",
        bopomofo    : L"ㄙㄚ",
        sheng       : "s",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_A }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 490 */
        text        : "sagn",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ANG }, { PINYIN_ID_SH, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 491 */
        text        : "sai",
        bopomofo    : L"ㄙㄞ",
        sheng       : "s",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_AI }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 492 */
        text        : "samg",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ANG }, { PINYIN_ID_SH, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 493 */
        text        : "san",
        bopomofo    : L"ㄙㄢ",
        sheng       : "s",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_AN }, { PINYIN_ID_SH, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 494 */
        text        : "sang",
        bopomofo    : L"ㄙㄤ",
        sheng       : "s",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ANG }, { PINYIN_ID_SH, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 495 */
        text        : "sao",
        bopomofo    : L"ㄙㄠ",
        sheng       : "s",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_AO }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 496 */
        text        : "se",
        bopomofo    : L"ㄙㄜ",
        sheng       : "s",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_E }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 497 */
        text        : "segn",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ENG }, { PINYIN_ID_SH, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 498 */
        text        : "sei",
        bopomofo    : L"ㄙㄟ",
        sheng       : "s",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_EI }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_S_SH
    },
    {  /* 499 */
        text        : "semg",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ENG }, { PINYIN_ID_SH, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 500 */
        text        : "sen",
        bopomofo    : L"ㄙㄣ",
        sheng       : "s",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_EN }, { PINYIN_ID_SH, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 501 */
        text        : "seng",
        bopomofo    : L"ㄙㄥ",
        sheng       : "s",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ENG }, { PINYIN_ID_SH, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 502 */
        text        : "sh",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 503 */
        text        : "sha",
        bopomofo    : L"ㄕㄚ",
        sheng       : "sh",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_A }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 504 */
        text        : "shagn",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_ANG }, { PINYIN_ID_S, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 505 */
        text        : "shai",
        bopomofo    : L"ㄕㄞ",
        sheng       : "sh",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_AI }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 506 */
        text        : "shamg",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_ANG }, { PINYIN_ID_S, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 507 */
        text        : "shan",
        bopomofo    : L"ㄕㄢ",
        sheng       : "sh",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_AN }, { PINYIN_ID_S, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 508 */
        text        : "shang",
        bopomofo    : L"ㄕㄤ",
        sheng       : "sh",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_ANG }, { PINYIN_ID_S, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 509 */
        text        : "shao",
        bopomofo    : L"ㄕㄠ",
        sheng       : "sh",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_AO }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 510 */
        text        : "she",
        bopomofo    : L"ㄕㄜ",
        sheng       : "sh",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_E }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 511 */
        text        : "shegn",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_ENG }, { PINYIN_ID_S, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 512 */
        text        : "shei",
        bopomofo    : L"ㄕㄟ",
        sheng       : "sh",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_EI }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 513 */
        text        : "shemg",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_ENG }, { PINYIN_ID_S, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 514 */
        text        : "shen",
        bopomofo    : L"ㄕㄣ",
        sheng       : "sh",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_EN }, { PINYIN_ID_S, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 515 */
        text        : "sheng",
        bopomofo    : L"ㄕㄥ",
        sheng       : "sh",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_ENG }, { PINYIN_ID_S, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 516 */
        text        : "shi",
        bopomofo    : L"ㄕ",
        sheng       : "sh",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_I }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 517 */
        text        : "shong",
        bopomofo    : L"ㄕㄨㄥ",
        sheng       : "sh",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_ONG }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_SH_S
    },
    {  /* 518 */
        text        : "shou",
        bopomofo    : L"ㄕㄡ",
        sheng       : "sh",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_OU }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 519 */
        text        : "shu",
        bopomofo    : L"ㄕㄨ",
        sheng       : "sh",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_U }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 520 */
        text        : "shua",
        bopomofo    : L"ㄕㄨㄚ",
        sheng       : "sh",
        yun         : "ua",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UA }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 521 */
        text        : "shuagn",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UANG }, { PINYIN_ID_S, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 522 */
        text        : "shuai",
        bopomofo    : L"ㄕㄨㄞ",
        sheng       : "sh",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UAI }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 523 */
        text        : "shuamg",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UANG }, { PINYIN_ID_S, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 524 */
        text        : "shuan",
        bopomofo    : L"ㄕㄨㄢ",
        sheng       : "sh",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UAN }, { PINYIN_ID_S, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 525 */
        text        : "shuang",
        bopomofo    : L"ㄕㄨㄤ",
        sheng       : "sh",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UANG }, { PINYIN_ID_S, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : 0
    },
    {  /* 526 */
        text        : "shuei",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UI }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 527 */
        text        : "shuen",
        bopomofo    : L"",
        sheng       : "sh",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UN }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 528 */
        text        : "shui",
        bopomofo    : L"ㄕㄨㄟ",
        sheng       : "sh",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UI }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 529 */
        text        : "shun",
        bopomofo    : L"ㄕㄨㄣ",
        sheng       : "sh",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UN }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 530 */
        text        : "shuo",
        bopomofo    : L"ㄕㄨㄛ",
        sheng       : "sh",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_SH, PINYIN_ID_UO }, { PINYIN_ID_S, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 531 */
        text        : "si",
        bopomofo    : L"ㄙ",
        sheng       : "s",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_I }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 532 */
        text        : "sogn",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ONG }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 533 */
        text        : "somg",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ONG }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 534 */
        text        : "song",
        bopomofo    : L"ㄙㄨㄥ",
        sheng       : "s",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_ONG }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 535 */
        text        : "sou",
        bopomofo    : L"ㄙㄡ",
        sheng       : "s",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_OU }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 536 */
        text        : "su",
        bopomofo    : L"ㄙㄨ",
        sheng       : "s",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_U }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 537 */
        text        : "sua",
        bopomofo    : L"ㄙㄨㄚ",
        sheng       : "s",
        yun         : "ua",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UA }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_S_SH
    },
    {  /* 538 */
        text        : "suai",
        bopomofo    : L"ㄙㄨㄞ",
        sheng       : "s",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UAI }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_S_SH
    },
    {  /* 539 */
        text        : "suan",
        bopomofo    : L"ㄙㄨㄢ",
        sheng       : "s",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UAN }, { PINYIN_ID_SH, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 540 */
        text        : "suang",
        bopomofo    : L"ㄙㄨㄤ",
        sheng       : "s",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UANG }, { PINYIN_ID_SH, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_S_SH | PINYIN_FUZZY_UANG_UAN
    },
    {  /* 541 */
        text        : "suei",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UI }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 542 */
        text        : "suen",
        bopomofo    : L"",
        sheng       : "s",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UN }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 543 */
        text        : "sui",
        bopomofo    : L"ㄙㄨㄟ",
        sheng       : "s",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UI }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 544 */
        text        : "sun",
        bopomofo    : L"ㄙㄨㄣ",
        sheng       : "s",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UN }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 545 */
        text        : "suo",
        bopomofo    : L"ㄙㄨㄛ",
        sheng       : "s",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_S, PINYIN_ID_UO }, { PINYIN_ID_SH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 546 */
        text        : "t",
        bopomofo    : L"ㄊ",
        sheng       : "t",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 547 */
        text        : "ta",
        bopomofo    : L"ㄊㄚ",
        sheng       : "t",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_A }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 548 */
        text        : "tagn",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 549 */
        text        : "tai",
        bopomofo    : L"ㄊㄞ",
        sheng       : "t",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_AI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 550 */
        text        : "tamg",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 551 */
        text        : "tan",
        bopomofo    : L"ㄊㄢ",
        sheng       : "t",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 552 */
        text        : "tang",
        bopomofo    : L"ㄊㄤ",
        sheng       : "t",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 553 */
        text        : "tao",
        bopomofo    : L"ㄊㄠ",
        sheng       : "t",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_AO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 554 */
        text        : "te",
        bopomofo    : L"ㄊㄜ",
        sheng       : "t",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_E }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 555 */
        text        : "tegn",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 556 */
        text        : "temg",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 557 */
        text        : "ten",
        bopomofo    : L"ㄊㄣ",
        sheng       : "t",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_EN_ENG
    },
    {  /* 558 */
        text        : "teng",
        bopomofo    : L"ㄊㄥ",
        sheng       : "t",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 559 */
        text        : "ti",
        bopomofo    : L"ㄊㄧ",
        sheng       : "t",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_I }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 560 */
        text        : "tian",
        bopomofo    : L"ㄊㄧㄢ",
        sheng       : "t",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 561 */
        text        : "tiang",
        bopomofo    : L"ㄊㄧㄤ",
        sheng       : "t",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_IANG_IAN
    },
    {  /* 562 */
        text        : "tiao",
        bopomofo    : L"ㄊㄧㄠ",
        sheng       : "t",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_IAO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 563 */
        text        : "tie",
        bopomofo    : L"ㄊㄧㄝ",
        sheng       : "t",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_IE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 564 */
        text        : "tign",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 565 */
        text        : "timg",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 566 */
        text        : "tin",
        bopomofo    : L"ㄊㄧㄣ",
        sheng       : "t",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_IN_ING
    },
    {  /* 567 */
        text        : "ting",
        bopomofo    : L"ㄊㄧㄥ",
        sheng       : "t",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 568 */
        text        : "togn",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 569 */
        text        : "tomg",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 570 */
        text        : "tong",
        bopomofo    : L"ㄊㄨㄥ",
        sheng       : "t",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 571 */
        text        : "tou",
        bopomofo    : L"ㄊㄡ",
        sheng       : "t",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_OU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 572 */
        text        : "tu",
        bopomofo    : L"ㄊㄨ",
        sheng       : "t",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 573 */
        text        : "tuan",
        bopomofo    : L"ㄊㄨㄢ",
        sheng       : "t",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 574 */
        text        : "tuang",
        bopomofo    : L"ㄊㄨㄤ",
        sheng       : "t",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 575 */
        text        : "tuei",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_UI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 576 */
        text        : "tuen",
        bopomofo    : L"",
        sheng       : "t",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 577 */
        text        : "tui",
        bopomofo    : L"ㄊㄨㄟ",
        sheng       : "t",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_UI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 578 */
        text        : "tun",
        bopomofo    : L"ㄊㄨㄣ",
        sheng       : "t",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 579 */
        text        : "tuo",
        bopomofo    : L"ㄊㄨㄛ",
        sheng       : "t",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_T, PINYIN_ID_UO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 580 */
        text        : "w",
        bopomofo    : L"",
        sheng       : "w",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 581 */
        text        : "wa",
        bopomofo    : L"ㄨㄚ",
        sheng       : "w",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_A }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 582 */
        text        : "wagn",
        bopomofo    : L"",
        sheng       : "w",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 583 */
        text        : "wai",
        bopomofo    : L"ㄨㄞ",
        sheng       : "w",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_AI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 584 */
        text        : "wamg",
        bopomofo    : L"",
        sheng       : "w",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 585 */
        text        : "wan",
        bopomofo    : L"ㄨㄢ",
        sheng       : "w",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 586 */
        text        : "wang",
        bopomofo    : L"ㄨㄤ",
        sheng       : "w",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 587 */
        text        : "wegn",
        bopomofo    : L"",
        sheng       : "w",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 588 */
        text        : "wei",
        bopomofo    : L"ㄨㄟ",
        sheng       : "w",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_EI }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 589 */
        text        : "wemg",
        bopomofo    : L"",
        sheng       : "w",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 590 */
        text        : "wen",
        bopomofo    : L"ㄨㄣ",
        sheng       : "w",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 591 */
        text        : "weng",
        bopomofo    : L"ㄨㄥ",
        sheng       : "w",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 592 */
        text        : "wo",
        bopomofo    : L"ㄨㄛ",
        sheng       : "w",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_O }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 593 */
        text        : "wu",
        bopomofo    : L"ㄨ",
        sheng       : "w",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_W, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 594 */
        text        : "x",
        bopomofo    : L"ㄒ",
        sheng       : "x",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 595 */
        text        : "xi",
        bopomofo    : L"ㄒㄧ",
        sheng       : "x",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_I }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 596 */
        text        : "xia",
        bopomofo    : L"ㄒㄧㄚ",
        sheng       : "x",
        yun         : "ia",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IA }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 597 */
        text        : "xiagn",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 598 */
        text        : "xiamg",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 599 */
        text        : "xian",
        bopomofo    : L"ㄒㄧㄢ",
        sheng       : "x",
        yun         : "ian",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 600 */
        text        : "xiang",
        bopomofo    : L"ㄒㄧㄤ",
        sheng       : "x",
        yun         : "iang",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IANG }, { PINYIN_ID_ZERO, PINYIN_ID_IAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 601 */
        text        : "xiao",
        bopomofo    : L"ㄒㄧㄠ",
        sheng       : "x",
        yun         : "iao",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IAO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 602 */
        text        : "xie",
        bopomofo    : L"ㄒㄧㄝ",
        sheng       : "x",
        yun         : "ie",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 603 */
        text        : "xign",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 604 */
        text        : "ximg",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 605 */
        text        : "xin",
        bopomofo    : L"ㄒㄧㄣ",
        sheng       : "x",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 606 */
        text        : "xing",
        bopomofo    : L"ㄒㄧㄥ",
        sheng       : "x",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 607 */
        text        : "xiogn",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 608 */
        text        : "xiomg",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 609 */
        text        : "xiong",
        bopomofo    : L"ㄒㄩㄥ",
        sheng       : "x",
        yun         : "iong",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 610 */
        text        : "xiou",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_IOU_TO_IU
    },
    {  /* 611 */
        text        : "xiu",
        bopomofo    : L"ㄒㄧㄡ",
        sheng       : "x",
        yun         : "iu",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_IU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 612 */
        text        : "xu",
        bopomofo    : L"ㄒㄩ",
        sheng       : "x",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 613 */
        text        : "xuan",
        bopomofo    : L"ㄒㄩㄢ",
        sheng       : "x",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 614 */
        text        : "xuang",
        bopomofo    : L"ㄒㄩㄤ",
        sheng       : "x",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 615 */
        text        : "xue",
        bopomofo    : L"ㄒㄩㄝ",
        sheng       : "x",
        yun         : "ue",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 616 */
        text        : "xuen",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 617 */
        text        : "xun",
        bopomofo    : L"ㄒㄩㄣ",
        sheng       : "x",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 618 */
        text        : "xv",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 619 */
        text        : "xvan",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 620 */
        text        : "xvang",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN | PINYIN_CORRECT_V_TO_U
    },
    {  /* 621 */
        text        : "xve",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "ue",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 622 */
        text        : "xven",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN | PINYIN_CORRECT_V_TO_U
    },
    {  /* 623 */
        text        : "xvn",
        bopomofo    : L"",
        sheng       : "x",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_X, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 624 */
        text        : "y",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 625 */
        text        : "ya",
        bopomofo    : L"ㄧㄚ",
        sheng       : "y",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_A }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 626 */
        text        : "yagn",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 627 */
        text        : "yamg",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 628 */
        text        : "yan",
        bopomofo    : L"ㄧㄢ",
        sheng       : "y",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 629 */
        text        : "yang",
        bopomofo    : L"ㄧㄤ",
        sheng       : "y",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 630 */
        text        : "yao",
        bopomofo    : L"ㄧㄠ",
        sheng       : "y",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_AO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 631 */
        text        : "ye",
        bopomofo    : L"ㄧㄝ",
        sheng       : "y",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_E }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 632 */
        text        : "yi",
        bopomofo    : L"ㄧ",
        sheng       : "y",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_I }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 633 */
        text        : "yign",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 634 */
        text        : "yimg",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 635 */
        text        : "yin",
        bopomofo    : L"ㄧㄣ",
        sheng       : "y",
        yun         : "in",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 636 */
        text        : "ying",
        bopomofo    : L"ㄧㄥ",
        sheng       : "y",
        yun         : "ing",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ING }, { PINYIN_ID_ZERO, PINYIN_ID_IN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 637 */
        text        : "yo",
        bopomofo    : L"ㄧㄛ",
        sheng       : "y",
        yun         : "o",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_O }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 638 */
        text        : "yogn",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 639 */
        text        : "yomg",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 640 */
        text        : "yong",
        bopomofo    : L"ㄩㄥ",
        sheng       : "y",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_ONG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 641 */
        text        : "you",
        bopomofo    : L"ㄧㄡ",
        sheng       : "y",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_OU }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 642 */
        text        : "yu",
        bopomofo    : L"ㄩ",
        sheng       : "y",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 643 */
        text        : "yuan",
        bopomofo    : L"ㄩㄢ",
        sheng       : "y",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 644 */
        text        : "yuang",
        bopomofo    : L"ㄧㄩㄤ",
        sheng       : "y",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN
    },
    {  /* 645 */
        text        : "yue",
        bopomofo    : L"ㄩㄝ",
        sheng       : "y",
        yun         : "ue",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 646 */
        text        : "yuen",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 647 */
        text        : "yun",
        bopomofo    : L"ㄩㄣ",
        sheng       : "y",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 648 */
        text        : "yv",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_U }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 649 */
        text        : "yvan",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 650 */
        text        : "yvang",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_UANG_UAN | PINYIN_CORRECT_V_TO_U
    },
    {  /* 651 */
        text        : "yve",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "ue",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UE }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 652 */
        text        : "yven",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN | PINYIN_CORRECT_V_TO_U
    },
    {  /* 653 */
        text        : "yvn",
        bopomofo    : L"",
        sheng       : "y",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Y, PINYIN_ID_UN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_CORRECT_V_TO_U
    },
    {  /* 654 */
        text        : "z",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 1,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 655 */
        text        : "za",
        bopomofo    : L"ㄗㄚ",
        sheng       : "z",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_A }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 656 */
        text        : "zagn",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ANG }, { PINYIN_ID_ZH, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 657 */
        text        : "zai",
        bopomofo    : L"ㄗㄞ",
        sheng       : "z",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_AI }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 658 */
        text        : "zamg",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ANG }, { PINYIN_ID_ZH, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 659 */
        text        : "zan",
        bopomofo    : L"ㄗㄢ",
        sheng       : "z",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_AN }, { PINYIN_ID_ZH, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 660 */
        text        : "zang",
        bopomofo    : L"ㄗㄤ",
        sheng       : "z",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ANG }, { PINYIN_ID_ZH, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 661 */
        text        : "zao",
        bopomofo    : L"ㄗㄠ",
        sheng       : "z",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_AO }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 662 */
        text        : "ze",
        bopomofo    : L"ㄗㄜ",
        sheng       : "z",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_E }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 663 */
        text        : "zegn",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ENG }, { PINYIN_ID_ZH, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 664 */
        text        : "zei",
        bopomofo    : L"ㄗㄟ",
        sheng       : "z",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_EI }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 665 */
        text        : "zemg",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ENG }, { PINYIN_ID_ZH, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 666 */
        text        : "zen",
        bopomofo    : L"ㄗㄣ",
        sheng       : "z",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_EN }, { PINYIN_ID_ZH, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 667 */
        text        : "zeng",
        bopomofo    : L"ㄗㄥ",
        sheng       : "z",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ENG }, { PINYIN_ID_ZH, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 668 */
        text        : "zh",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : PINYIN_INCOMPLETE_PINYIN
    },
    {  /* 669 */
        text        : "zha",
        bopomofo    : L"ㄓㄚ",
        sheng       : "zh",
        yun         : "a",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_A }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 670 */
        text        : "zhagn",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ANG }, { PINYIN_ID_Z, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 671 */
        text        : "zhai",
        bopomofo    : L"ㄓㄞ",
        sheng       : "zh",
        yun         : "ai",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_AI }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 672 */
        text        : "zhamg",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ANG }, { PINYIN_ID_Z, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 673 */
        text        : "zhan",
        bopomofo    : L"ㄓㄢ",
        sheng       : "zh",
        yun         : "an",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_AN }, { PINYIN_ID_Z, PINYIN_ID_ANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 674 */
        text        : "zhang",
        bopomofo    : L"ㄓㄤ",
        sheng       : "zh",
        yun         : "ang",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ANG }, { PINYIN_ID_Z, PINYIN_ID_AN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 675 */
        text        : "zhao",
        bopomofo    : L"ㄓㄠ",
        sheng       : "zh",
        yun         : "ao",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_AO }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 676 */
        text        : "zhe",
        bopomofo    : L"ㄓㄜ",
        sheng       : "zh",
        yun         : "e",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_E }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 677 */
        text        : "zhegn",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ENG }, { PINYIN_ID_Z, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 678 */
        text        : "zhei",
        bopomofo    : L"ㄓㄟ",
        sheng       : "zh",
        yun         : "ei",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_EI }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_ZH_Z
    },
    {  /* 679 */
        text        : "zhemg",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ENG }, { PINYIN_ID_Z, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 680 */
        text        : "zhen",
        bopomofo    : L"ㄓㄣ",
        sheng       : "zh",
        yun         : "en",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_EN }, { PINYIN_ID_Z, PINYIN_ID_ENG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 681 */
        text        : "zheng",
        bopomofo    : L"ㄓㄥ",
        sheng       : "zh",
        yun         : "eng",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ENG }, { PINYIN_ID_Z, PINYIN_ID_EN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 682 */
        text        : "zhi",
        bopomofo    : L"ㄓ",
        sheng       : "zh",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_I }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 683 */
        text        : "zhogn",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ONG }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 684 */
        text        : "zhomg",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ONG }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 685 */
        text        : "zhong",
        bopomofo    : L"ㄓㄨㄥ",
        sheng       : "zh",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_ONG }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 686 */
        text        : "zhou",
        bopomofo    : L"ㄓㄡ",
        sheng       : "zh",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_OU }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 687 */
        text        : "zhu",
        bopomofo    : L"ㄓㄨ",
        sheng       : "zh",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_U }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 688 */
        text        : "zhua",
        bopomofo    : L"ㄓㄨㄚ",
        sheng       : "zh",
        yun         : "ua",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UA }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 689 */
        text        : "zhuagn",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UANG }, { PINYIN_ID_Z, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 690 */
        text        : "zhuai",
        bopomofo    : L"ㄓㄨㄞ",
        sheng       : "zh",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UAI }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 691 */
        text        : "zhuamg",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UANG }, { PINYIN_ID_Z, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 692 */
        text        : "zhuan",
        bopomofo    : L"ㄓㄨㄢ",
        sheng       : "zh",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UAN }, { PINYIN_ID_Z, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : 0
    },
    {  /* 693 */
        text        : "zhuang",
        bopomofo    : L"ㄓㄨㄤ",
        sheng       : "zh",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UANG }, { PINYIN_ID_Z, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 6,
        flags       : 0
    },
    {  /* 694 */
        text        : "zhuei",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UI }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 695 */
        text        : "zhuen",
        bopomofo    : L"",
        sheng       : "zh",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UN }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 696 */
        text        : "zhui",
        bopomofo    : L"ㄓㄨㄟ",
        sheng       : "zh",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UI }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 697 */
        text        : "zhun",
        bopomofo    : L"ㄓㄨㄣ",
        sheng       : "zh",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UN }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 698 */
        text        : "zhuo",
        bopomofo    : L"ㄓㄨㄛ",
        sheng       : "zh",
        yun         : "uo",
        pinyin_id   : {{ PINYIN_ID_ZH, PINYIN_ID_UO }, { PINYIN_ID_Z, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 699 */
        text        : "zi",
        bopomofo    : L"ㄗ",
        sheng       : "z",
        yun         : "i",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_I }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 700 */
        text        : "zogn",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ONG }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_GN_TO_NG
    },
    {  /* 701 */
        text        : "zomg",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ONG }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_MG_TO_NG
    },
    {  /* 702 */
        text        : "zong",
        bopomofo    : L"ㄗㄨㄥ",
        sheng       : "z",
        yun         : "ong",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_ONG }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 703 */
        text        : "zou",
        bopomofo    : L"ㄗㄡ",
        sheng       : "z",
        yun         : "ou",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_OU }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 704 */
        text        : "zu",
        bopomofo    : L"ㄗㄨ",
        sheng       : "z",
        yun         : "u",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_U }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 2,
        flags       : 0
    },
    {  /* 705 */
        text        : "zua",
        bopomofo    : L"ㄗㄨㄚ",
        sheng       : "z",
        yun         : "ua",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_UA }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : PINYIN_FUZZY_Z_ZH
    },
    {  /* 706 */
        text        : "zuai",
        bopomofo    : L"ㄗㄨㄞ",
        sheng       : "z",
        yun         : "uai",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_UAI }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_FUZZY_Z_ZH
    },
    {  /* 707 */
        text        : "zuan",
        bopomofo    : L"ㄗㄨㄢ",
        sheng       : "z",
        yun         : "uan",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_UAN }, { PINYIN_ID_ZH, PINYIN_ID_UANG }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : 0
    },
    {  /* 708 */
        text        : "zuang",
        bopomofo    : L"ㄗㄨㄤ",
        sheng       : "z",
        yun         : "uang",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_UANG }, { PINYIN_ID_ZH, PINYIN_ID_UAN }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 5,
        flags       : PINYIN_FUZZY_Z_ZH | PINYIN_FUZZY_UANG_UAN
    },
    {  /* 709 */
        text        : "zuei",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_UI }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEI_TO_UI
    },
    {  /* 710 */
        text        : "zuen",
        bopomofo    : L"",
        sheng       : "z",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_UN }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 4,
        flags       : PINYIN_CORRECT_UEN_TO_UN
    },
    {  /* 711 */
        text        : "zui",
        bopomofo    : L"ㄗㄨㄟ",
        sheng       : "z",
        yun         : "ui",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_UI }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 712 */
        text        : "zun",
        bopomofo    : L"ㄗㄨㄣ",
        sheng       : "z",
        yun         : "un",
        pinyin_id   : {{ PINYIN_ID_Z, PINYIN_ID_UN }, { PINYIN_ID_ZH, PINYIN_ID_ZERO }, { PINYIN_ID_ZERO, PINYIN_ID_ZERO }},
        len         : 3,
        flags       : 0
    },
    {  /* 713 */
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
    &pinyin_table[393],  // "ㄆ" => "p"
    &pinyin_table[394],  // "ㄆㄚ" => "pa"
    &pinyin_table[415],  // "ㄆㄛ" => "po"
    &pinyin_table[396],  // "ㄆㄞ" => "pai"
    &pinyin_table[402],  // "ㄆㄟ" => "pei"
    &pinyin_table[400],  // "ㄆㄠ" => "pao"
    &pinyin_table[416],  // "ㄆㄡ" => "pou"
    &pinyin_table[398],  // "ㄆㄢ" => "pan"
    &pinyin_table[404],  // "ㄆㄣ" => "pen"
    &pinyin_table[399],  // "ㄆㄤ" => "pang"
    &pinyin_table[405],  // "ㄆㄥ" => "peng"
    &pinyin_table[406],  // "ㄆㄧ" => "pi"
    &pinyin_table[410],  // "ㄆㄧㄝ" => "pie"
    &pinyin_table[409],  // "ㄆㄧㄠ" => "piao"
    &pinyin_table[407],  // "ㄆㄧㄢ" => "pian"
    &pinyin_table[413],  // "ㄆㄧㄣ" => "pin"
    &pinyin_table[408],  // "ㄆㄧㄤ" => "piang"
    &pinyin_table[414],  // "ㄆㄧㄥ" => "ping"
    &pinyin_table[417],  // "ㄆㄨ" => "pu"
    &pinyin_table[321],  // "ㄇ" => "m"
    &pinyin_table[322],  // "ㄇㄚ" => "ma"
    &pinyin_table[346],  // "ㄇㄛ" => "mo"
    &pinyin_table[329],  // "ㄇㄜ" => "me"
    &pinyin_table[324],  // "ㄇㄞ" => "mai"
    &pinyin_table[331],  // "ㄇㄟ" => "mei"
    &pinyin_table[328],  // "ㄇㄠ" => "mao"
    &pinyin_table[347],  // "ㄇㄡ" => "mou"
    &pinyin_table[326],  // "ㄇㄢ" => "man"
    &pinyin_table[333],  // "ㄇㄣ" => "men"
    &pinyin_table[327],  // "ㄇㄤ" => "mang"
    &pinyin_table[334],  // "ㄇㄥ" => "meng"
    &pinyin_table[335],  // "ㄇㄧ" => "mi"
    &pinyin_table[339],  // "ㄇㄧㄝ" => "mie"
    &pinyin_table[338],  // "ㄇㄧㄠ" => "miao"
    &pinyin_table[345],  // "ㄇㄧㄡ" => "miu"
    &pinyin_table[336],  // "ㄇㄧㄢ" => "mian"
    &pinyin_table[342],  // "ㄇㄧㄣ" => "min"
    &pinyin_table[337],  // "ㄇㄧㄤ" => "miang"
    &pinyin_table[343],  // "ㄇㄧㄥ" => "ming"
    &pinyin_table[348],  // "ㄇㄨ" => "mu"
    &pinyin_table[129],  // "ㄈ" => "f"
    &pinyin_table[130],  // "ㄈㄚ" => "fa"
    &pinyin_table[143],  // "ㄈㄛ" => "fo"
    &pinyin_table[137],  // "ㄈㄜ" => "fe"
    &pinyin_table[132],  // "ㄈㄞ" => "fai"
    &pinyin_table[139],  // "ㄈㄟ" => "fei"
    &pinyin_table[136],  // "ㄈㄠ" => "fao"
    &pinyin_table[145],  // "ㄈㄡ" => "fou"
    &pinyin_table[134],  // "ㄈㄢ" => "fan"
    &pinyin_table[141],  // "ㄈㄣ" => "fen"
    &pinyin_table[135],  // "ㄈㄤ" => "fang"
    &pinyin_table[142],  // "ㄈㄥ" => "feng"
    &pinyin_table[146],  // "ㄈㄨ" => "fu"
    &pinyin_table[147],  // "ㄈㄨㄚ" => "fua"
    &pinyin_table[155],  // "ㄈㄨㄛ" => "fuo"
    &pinyin_table[148],  // "ㄈㄨㄞ" => "fuai"
    &pinyin_table[153],  // "ㄈㄨㄟ" => "fui"
    &pinyin_table[149],  // "ㄈㄨㄢ" => "fuan"
    &pinyin_table[154],  // "ㄈㄨㄣ" => "fun"
    &pinyin_table[150],  // "ㄈㄨㄤ" => "fuang"
    &pinyin_table[144],  // "ㄈㄨㄥ" => "fong"
    &pinyin_table[87],   // "ㄉ" => "d"
    &pinyin_table[88],   // "ㄉㄚ" => "da"
    &pinyin_table[95],   // "ㄉㄜ" => "de"
    &pinyin_table[90],   // "ㄉㄞ" => "dai"
    &pinyin_table[97],   // "ㄉㄟ" => "dei"
    &pinyin_table[94],   // "ㄉㄠ" => "dao"
    &pinyin_table[116],  // "ㄉㄡ" => "dou"
    &pinyin_table[92],   // "ㄉㄢ" => "dan"
    &pinyin_table[99],   // "ㄉㄣ" => "den"
    &pinyin_table[93],   // "ㄉㄤ" => "dang"
    &pinyin_table[100],  // "ㄉㄥ" => "deng"
    &pinyin_table[101],  // "ㄉㄧ" => "di"
    &pinyin_table[102],  // "ㄉㄧㄚ" => "dia"
    &pinyin_table[106],  // "ㄉㄧㄝ" => "die"
    &pinyin_table[105],  // "ㄉㄧㄠ" => "diao"
    &pinyin_table[112],  // "ㄉㄧㄡ" => "diu"
    &pinyin_table[103],  // "ㄉㄧㄢ" => "dian"
    &pinyin_table[109],  // "ㄉㄧㄣ" => "din"
    &pinyin_table[104],  // "ㄉㄧㄤ" => "diang"
    &pinyin_table[110],  // "ㄉㄧㄥ" => "ding"
    &pinyin_table[117],  // "ㄉㄨ" => "du"
    &pinyin_table[124],  // "ㄉㄨㄛ" => "duo"
    &pinyin_table[122],  // "ㄉㄨㄟ" => "dui"
    &pinyin_table[118],  // "ㄉㄨㄢ" => "duan"
    &pinyin_table[123],  // "ㄉㄨㄣ" => "dun"
    &pinyin_table[119],  // "ㄉㄨㄤ" => "duang"
    &pinyin_table[115],  // "ㄉㄨㄥ" => "dong"
    &pinyin_table[546],  // "ㄊ" => "t"
    &pinyin_table[547],  // "ㄊㄚ" => "ta"
    &pinyin_table[554],  // "ㄊㄜ" => "te"
    &pinyin_table[549],  // "ㄊㄞ" => "tai"
    &pinyin_table[553],  // "ㄊㄠ" => "tao"
    &pinyin_table[571],  // "ㄊㄡ" => "tou"
    &pinyin_table[551],  // "ㄊㄢ" => "tan"
    &pinyin_table[557],  // "ㄊㄣ" => "ten"
    &pinyin_table[552],  // "ㄊㄤ" => "tang"
    &pinyin_table[558],  // "ㄊㄥ" => "teng"
    &pinyin_table[559],  // "ㄊㄧ" => "ti"
    &pinyin_table[563],  // "ㄊㄧㄝ" => "tie"
    &pinyin_table[562],  // "ㄊㄧㄠ" => "tiao"
    &pinyin_table[560],  // "ㄊㄧㄢ" => "tian"
    &pinyin_table[566],  // "ㄊㄧㄣ" => "tin"
    &pinyin_table[561],  // "ㄊㄧㄤ" => "tiang"
    &pinyin_table[567],  // "ㄊㄧㄥ" => "ting"
    &pinyin_table[572],  // "ㄊㄨ" => "tu"
    &pinyin_table[579],  // "ㄊㄨㄛ" => "tuo"
    &pinyin_table[577],  // "ㄊㄨㄟ" => "tui"
    &pinyin_table[573],  // "ㄊㄨㄢ" => "tuan"
    &pinyin_table[578],  // "ㄊㄨㄣ" => "tun"
    &pinyin_table[574],  // "ㄊㄨㄤ" => "tuang"
    &pinyin_table[570],  // "ㄊㄨㄥ" => "tong"
    &pinyin_table[349],  // "ㄋ" => "n"
    &pinyin_table[350],  // "ㄋㄚ" => "na"
    &pinyin_table[377],  // "ㄋㄛ" => "no"
    &pinyin_table[357],  // "ㄋㄜ" => "ne"
    &pinyin_table[352],  // "ㄋㄞ" => "nai"
    &pinyin_table[359],  // "ㄋㄟ" => "nei"
    &pinyin_table[356],  // "ㄋㄠ" => "nao"
    &pinyin_table[381],  // "ㄋㄡ" => "nou"
    &pinyin_table[354],  // "ㄋㄢ" => "nan"
    &pinyin_table[361],  // "ㄋㄣ" => "nen"
    &pinyin_table[355],  // "ㄋㄤ" => "nang"
    &pinyin_table[362],  // "ㄋㄥ" => "neng"
    &pinyin_table[363],  // "ㄋㄧ" => "ni"
    &pinyin_table[364],  // "ㄋㄧㄚ" => "nia"
    &pinyin_table[370],  // "ㄋㄧㄝ" => "nie"
    &pinyin_table[369],  // "ㄋㄧㄠ" => "niao"
    &pinyin_table[376],  // "ㄋㄧㄡ" => "niu"
    &pinyin_table[367],  // "ㄋㄧㄢ" => "nian"
    &pinyin_table[373],  // "ㄋㄧㄣ" => "nin"
    &pinyin_table[368],  // "ㄋㄧㄤ" => "niang"
    &pinyin_table[374],  // "ㄋㄧㄥ" => "ning"
    &pinyin_table[382],  // "ㄋㄨ" => "nu"
    &pinyin_table[388],  // "ㄋㄨㄛ" => "nuo"
    &pinyin_table[383],  // "ㄋㄨㄢ" => "nuan"
    &pinyin_table[387],  // "ㄋㄨㄣ" => "nun"
    &pinyin_table[384],  // "ㄋㄨㄤ" => "nuang"
    &pinyin_table[380],  // "ㄋㄨㄥ" => "nong"
    &pinyin_table[389],  // "ㄋㄩ" => "nv"
    &pinyin_table[390],  // "ㄋㄩㄝ" => "nve"
    &pinyin_table[277],  // "ㄌ" => "l"
    &pinyin_table[278],  // "ㄌㄚ" => "la"
    &pinyin_table[305],  // "ㄌㄛ" => "lo"
    &pinyin_table[285],  // "ㄌㄜ" => "le"
    &pinyin_table[280],  // "ㄌㄞ" => "lai"
    &pinyin_table[287],  // "ㄌㄟ" => "lei"
    &pinyin_table[284],  // "ㄌㄠ" => "lao"
    &pinyin_table[309],  // "ㄌㄡ" => "lou"
    &pinyin_table[282],  // "ㄌㄢ" => "lan"
    &pinyin_table[289],  // "ㄌㄣ" => "len"
    &pinyin_table[283],  // "ㄌㄤ" => "lang"
    &pinyin_table[290],  // "ㄌㄥ" => "leng"
    &pinyin_table[291],  // "ㄌㄧ" => "li"
    &pinyin_table[292],  // "ㄌㄧㄚ" => "lia"
    &pinyin_table[298],  // "ㄌㄧㄝ" => "lie"
    &pinyin_table[297],  // "ㄌㄧㄠ" => "liao"
    &pinyin_table[304],  // "ㄌㄧㄡ" => "liu"
    &pinyin_table[295],  // "ㄌㄧㄢ" => "lian"
    &pinyin_table[301],  // "ㄌㄧㄣ" => "lin"
    &pinyin_table[296],  // "ㄌㄧㄤ" => "liang"
    &pinyin_table[302],  // "ㄌㄧㄥ" => "ling"
    &pinyin_table[310],  // "ㄌㄨ" => "lu"
    &pinyin_table[318],  // "ㄌㄨㄛ" => "luo"
    &pinyin_table[316],  // "ㄌㄨㄟ" => "lui"
    &pinyin_table[311],  // "ㄌㄨㄢ" => "luan"
    &pinyin_table[317],  // "ㄌㄨㄣ" => "lun"
    &pinyin_table[312],  // "ㄌㄨㄤ" => "luang"
    &pinyin_table[308],  // "ㄌㄨㄥ" => "long"
    &pinyin_table[319],  // "ㄌㄩ" => "lv"
    &pinyin_table[320],  // "ㄌㄩㄝ" => "lve"
    &pinyin_table[156],  // "ㄍ" => "g"
    &pinyin_table[157],  // "ㄍㄚ" => "ga"
    &pinyin_table[164],  // "ㄍㄜ" => "ge"
    &pinyin_table[159],  // "ㄍㄞ" => "gai"
    &pinyin_table[166],  // "ㄍㄟ" => "gei"
    &pinyin_table[163],  // "ㄍㄠ" => "gao"
    &pinyin_table[173],  // "ㄍㄡ" => "gou"
    &pinyin_table[161],  // "ㄍㄢ" => "gan"
    &pinyin_table[168],  // "ㄍㄣ" => "gen"
    &pinyin_table[162],  // "ㄍㄤ" => "gang"
    &pinyin_table[169],  // "ㄍㄥ" => "geng"
    &pinyin_table[174],  // "ㄍㄨ" => "gu"
    &pinyin_table[175],  // "ㄍㄨㄚ" => "gua"
    &pinyin_table[185],  // "ㄍㄨㄛ" => "guo"
    &pinyin_table[177],  // "ㄍㄨㄞ" => "guai"
    &pinyin_table[183],  // "ㄍㄨㄟ" => "gui"
    &pinyin_table[179],  // "ㄍㄨㄢ" => "guan"
    &pinyin_table[184],  // "ㄍㄨㄣ" => "gun"
    &pinyin_table[180],  // "ㄍㄨㄤ" => "guang"
    &pinyin_table[172],  // "ㄍㄨㄥ" => "gong"
    &pinyin_table[247],  // "ㄎ" => "k"
    &pinyin_table[248],  // "ㄎㄚ" => "ka"
    &pinyin_table[255],  // "ㄎㄜ" => "ke"
    &pinyin_table[250],  // "ㄎㄞ" => "kai"
    &pinyin_table[257],  // "ㄎㄟ" => "kei"
    &pinyin_table[254],  // "ㄎㄠ" => "kao"
    &pinyin_table[264],  // "ㄎㄡ" => "kou"
    &pinyin_table[252],  // "ㄎㄢ" => "kan"
    &pinyin_table[259],  // "ㄎㄣ" => "ken"
    &pinyin_table[253],  // "ㄎㄤ" => "kang"
    &pinyin_table[260],  // "ㄎㄥ" => "keng"
    &pinyin_table[265],  // "ㄎㄨ" => "ku"
    &pinyin_table[266],  // "ㄎㄨㄚ" => "kua"
    &pinyin_table[276],  // "ㄎㄨㄛ" => "kuo"
    &pinyin_table[268],  // "ㄎㄨㄞ" => "kuai"
    &pinyin_table[274],  // "ㄎㄨㄟ" => "kui"
    &pinyin_table[270],  // "ㄎㄨㄢ" => "kuan"
    &pinyin_table[275],  // "ㄎㄨㄣ" => "kun"
    &pinyin_table[271],  // "ㄎㄨㄤ" => "kuang"
    &pinyin_table[263],  // "ㄎㄨㄥ" => "kong"
    &pinyin_table[186],  // "ㄏ" => "h"
    &pinyin_table[187],  // "ㄏㄚ" => "ha"
    &pinyin_table[200],  // "ㄏㄛ" => "ho"
    &pinyin_table[194],  // "ㄏㄜ" => "he"
    &pinyin_table[189],  // "ㄏㄞ" => "hai"
    &pinyin_table[196],  // "ㄏㄟ" => "hei"
    &pinyin_table[193],  // "ㄏㄠ" => "hao"
    &pinyin_table[204],  // "ㄏㄡ" => "hou"
    &pinyin_table[191],  // "ㄏㄢ" => "han"
    &pinyin_table[198],  // "ㄏㄣ" => "hen"
    &pinyin_table[192],  // "ㄏㄤ" => "hang"
    &pinyin_table[199],  // "ㄏㄥ" => "heng"
    &pinyin_table[205],  // "ㄏㄨ" => "hu"
    &pinyin_table[206],  // "ㄏㄨㄚ" => "hua"
    &pinyin_table[216],  // "ㄏㄨㄛ" => "huo"
    &pinyin_table[208],  // "ㄏㄨㄞ" => "huai"
    &pinyin_table[214],  // "ㄏㄨㄟ" => "hui"
    &pinyin_table[210],  // "ㄏㄨㄢ" => "huan"
    &pinyin_table[215],  // "ㄏㄨㄣ" => "hun"
    &pinyin_table[211],  // "ㄏㄨㄤ" => "huang"
    &pinyin_table[203],  // "ㄏㄨㄥ" => "hong"
    &pinyin_table[217],  // "ㄐ" => "j"
    &pinyin_table[218],  // "ㄐㄧ" => "ji"
    &pinyin_table[219],  // "ㄐㄧㄚ" => "jia"
    &pinyin_table[225],  // "ㄐㄧㄝ" => "jie"
    &pinyin_table[224],  // "ㄐㄧㄠ" => "jiao"
    &pinyin_table[234],  // "ㄐㄧㄡ" => "jiu"
    &pinyin_table[222],  // "ㄐㄧㄢ" => "jian"
    &pinyin_table[228],  // "ㄐㄧㄣ" => "jin"
    &pinyin_table[223],  // "ㄐㄧㄤ" => "jiang"
    &pinyin_table[229],  // "ㄐㄧㄥ" => "jing"
    &pinyin_table[235],  // "ㄐㄩ" => "ju"
    &pinyin_table[238],  // "ㄐㄩㄝ" => "jue"
    &pinyin_table[236],  // "ㄐㄩㄢ" => "juan"
    &pinyin_table[240],  // "ㄐㄩㄣ" => "jun"
    &pinyin_table[237],  // "ㄐㄩㄤ" => "juang"
    &pinyin_table[232],  // "ㄐㄩㄥ" => "jiong"
    &pinyin_table[418],  // "ㄑ" => "q"
    &pinyin_table[419],  // "ㄑㄧ" => "qi"
    &pinyin_table[420],  // "ㄑㄧㄚ" => "qia"
    &pinyin_table[426],  // "ㄑㄧㄝ" => "qie"
    &pinyin_table[425],  // "ㄑㄧㄠ" => "qiao"
    &pinyin_table[435],  // "ㄑㄧㄡ" => "qiu"
    &pinyin_table[423],  // "ㄑㄧㄢ" => "qian"
    &pinyin_table[429],  // "ㄑㄧㄣ" => "qin"
    &pinyin_table[424],  // "ㄑㄧㄤ" => "qiang"
    &pinyin_table[430],  // "ㄑㄧㄥ" => "qing"
    &pinyin_table[436],  // "ㄑㄩ" => "qu"
    &pinyin_table[439],  // "ㄑㄩㄝ" => "que"
    &pinyin_table[437],  // "ㄑㄩㄢ" => "quan"
    &pinyin_table[441],  // "ㄑㄩㄣ" => "qun"
    &pinyin_table[438],  // "ㄑㄩㄤ" => "quang"
    &pinyin_table[433],  // "ㄑㄩㄥ" => "qiong"
    &pinyin_table[594],  // "ㄒ" => "x"
    &pinyin_table[595],  // "ㄒㄧ" => "xi"
    &pinyin_table[596],  // "ㄒㄧㄚ" => "xia"
    &pinyin_table[602],  // "ㄒㄧㄝ" => "xie"
    &pinyin_table[601],  // "ㄒㄧㄠ" => "xiao"
    &pinyin_table[611],  // "ㄒㄧㄡ" => "xiu"
    &pinyin_table[599],  // "ㄒㄧㄢ" => "xian"
    &pinyin_table[605],  // "ㄒㄧㄣ" => "xin"
    &pinyin_table[600],  // "ㄒㄧㄤ" => "xiang"
    &pinyin_table[606],  // "ㄒㄧㄥ" => "xing"
    &pinyin_table[612],  // "ㄒㄩ" => "xu"
    &pinyin_table[615],  // "ㄒㄩㄝ" => "xue"
    &pinyin_table[613],  // "ㄒㄩㄢ" => "xuan"
    &pinyin_table[617],  // "ㄒㄩㄣ" => "xun"
    &pinyin_table[614],  // "ㄒㄩㄤ" => "xuang"
    &pinyin_table[609],  // "ㄒㄩㄥ" => "xiong"
    &pinyin_table[682],  // "ㄓ" => "zhi"
    &pinyin_table[669],  // "ㄓㄚ" => "zha"
    &pinyin_table[676],  // "ㄓㄜ" => "zhe"
    &pinyin_table[671],  // "ㄓㄞ" => "zhai"
    &pinyin_table[678],  // "ㄓㄟ" => "zhei"
    &pinyin_table[675],  // "ㄓㄠ" => "zhao"
    &pinyin_table[686],  // "ㄓㄡ" => "zhou"
    &pinyin_table[673],  // "ㄓㄢ" => "zhan"
    &pinyin_table[680],  // "ㄓㄣ" => "zhen"
    &pinyin_table[674],  // "ㄓㄤ" => "zhang"
    &pinyin_table[681],  // "ㄓㄥ" => "zheng"
    &pinyin_table[687],  // "ㄓㄨ" => "zhu"
    &pinyin_table[688],  // "ㄓㄨㄚ" => "zhua"
    &pinyin_table[698],  // "ㄓㄨㄛ" => "zhuo"
    &pinyin_table[690],  // "ㄓㄨㄞ" => "zhuai"
    &pinyin_table[696],  // "ㄓㄨㄟ" => "zhui"
    &pinyin_table[692],  // "ㄓㄨㄢ" => "zhuan"
    &pinyin_table[697],  // "ㄓㄨㄣ" => "zhun"
    &pinyin_table[693],  // "ㄓㄨㄤ" => "zhuang"
    &pinyin_table[685],  // "ㄓㄨㄥ" => "zhong"
    &pinyin_table[57],   // "ㄔ" => "chi"
    &pinyin_table[45],   // "ㄔㄚ" => "cha"
    &pinyin_table[52],   // "ㄔㄜ" => "che"
    &pinyin_table[47],   // "ㄔㄞ" => "chai"
    &pinyin_table[51],   // "ㄔㄠ" => "chao"
    &pinyin_table[61],   // "ㄔㄡ" => "chou"
    &pinyin_table[49],   // "ㄔㄢ" => "chan"
    &pinyin_table[55],   // "ㄔㄣ" => "chen"
    &pinyin_table[50],   // "ㄔㄤ" => "chang"
    &pinyin_table[56],   // "ㄔㄥ" => "cheng"
    &pinyin_table[62],   // "ㄔㄨ" => "chu"
    &pinyin_table[72],   // "ㄔㄨㄛ" => "chuo"
    &pinyin_table[64],   // "ㄔㄨㄞ" => "chuai"
    &pinyin_table[70],   // "ㄔㄨㄟ" => "chui"
    &pinyin_table[66],   // "ㄔㄨㄢ" => "chuan"
    &pinyin_table[71],   // "ㄔㄨㄣ" => "chun"
    &pinyin_table[67],   // "ㄔㄨㄤ" => "chuang"
    &pinyin_table[60],   // "ㄔㄨㄥ" => "chong"
    &pinyin_table[516],  // "ㄕ" => "shi"
    &pinyin_table[503],  // "ㄕㄚ" => "sha"
    &pinyin_table[510],  // "ㄕㄜ" => "she"
    &pinyin_table[505],  // "ㄕㄞ" => "shai"
    &pinyin_table[512],  // "ㄕㄟ" => "shei"
    &pinyin_table[509],  // "ㄕㄠ" => "shao"
    &pinyin_table[518],  // "ㄕㄡ" => "shou"
    &pinyin_table[507],  // "ㄕㄢ" => "shan"
    &pinyin_table[514],  // "ㄕㄣ" => "shen"
    &pinyin_table[508],  // "ㄕㄤ" => "shang"
    &pinyin_table[515],  // "ㄕㄥ" => "sheng"
    &pinyin_table[519],  // "ㄕㄨ" => "shu"
    &pinyin_table[520],  // "ㄕㄨㄚ" => "shua"
    &pinyin_table[530],  // "ㄕㄨㄛ" => "shuo"
    &pinyin_table[522],  // "ㄕㄨㄞ" => "shuai"
    &pinyin_table[528],  // "ㄕㄨㄟ" => "shui"
    &pinyin_table[524],  // "ㄕㄨㄢ" => "shuan"
    &pinyin_table[529],  // "ㄕㄨㄣ" => "shun"
    &pinyin_table[525],  // "ㄕㄨㄤ" => "shuang"
    &pinyin_table[517],  // "ㄕㄨㄥ" => "shong"
    &pinyin_table[462],  // "ㄖ" => "ri"
    &pinyin_table[449],  // "ㄖㄚ" => "ra"
    &pinyin_table[472],  // "ㄖㄛ" => "ro"
    &pinyin_table[456],  // "ㄖㄜ" => "re"
    &pinyin_table[451],  // "ㄖㄞ" => "rai"
    &pinyin_table[458],  // "ㄖㄟ" => "rei"
    &pinyin_table[455],  // "ㄖㄠ" => "rao"
    &pinyin_table[476],  // "ㄖㄡ" => "rou"
    &pinyin_table[453],  // "ㄖㄢ" => "ran"
    &pinyin_table[460],  // "ㄖㄣ" => "ren"
    &pinyin_table[454],  // "ㄖㄤ" => "rang"
    &pinyin_table[461],  // "ㄖㄥ" => "reng"
    &pinyin_table[463],  // "ㄖㄧㄚ" => "ria"
    &pinyin_table[467],  // "ㄖㄧㄝ" => "rie"
    &pinyin_table[466],  // "ㄖㄧㄠ" => "riao"
    &pinyin_table[471],  // "ㄖㄧㄡ" => "riu"
    &pinyin_table[464],  // "ㄖㄧㄢ" => "rian"
    &pinyin_table[468],  // "ㄖㄧㄣ" => "rin"
    &pinyin_table[465],  // "ㄖㄧㄤ" => "riang"
    &pinyin_table[469],  // "ㄖㄧㄥ" => "ring"
    &pinyin_table[477],  // "ㄖㄨ" => "ru"
    &pinyin_table[485],  // "ㄖㄨㄛ" => "ruo"
    &pinyin_table[483],  // "ㄖㄨㄟ" => "rui"
    &pinyin_table[478],  // "ㄖㄨㄢ" => "ruan"
    &pinyin_table[484],  // "ㄖㄨㄣ" => "run"
    &pinyin_table[479],  // "ㄖㄨㄤ" => "ruang"
    &pinyin_table[475],  // "ㄖㄨㄥ" => "rong"
    &pinyin_table[486],  // "ㄖㄩ" => "rv"
    &pinyin_table[487],  // "ㄖㄩㄝ" => "rve"
    &pinyin_table[699],  // "ㄗ" => "zi"
    &pinyin_table[655],  // "ㄗㄚ" => "za"
    &pinyin_table[662],  // "ㄗㄜ" => "ze"
    &pinyin_table[657],  // "ㄗㄞ" => "zai"
    &pinyin_table[664],  // "ㄗㄟ" => "zei"
    &pinyin_table[661],  // "ㄗㄠ" => "zao"
    &pinyin_table[703],  // "ㄗㄡ" => "zou"
    &pinyin_table[659],  // "ㄗㄢ" => "zan"
    &pinyin_table[666],  // "ㄗㄣ" => "zen"
    &pinyin_table[660],  // "ㄗㄤ" => "zang"
    &pinyin_table[667],  // "ㄗㄥ" => "zeng"
    &pinyin_table[704],  // "ㄗㄨ" => "zu"
    &pinyin_table[705],  // "ㄗㄨㄚ" => "zua"
    &pinyin_table[713],  // "ㄗㄨㄛ" => "zuo"
    &pinyin_table[706],  // "ㄗㄨㄞ" => "zuai"
    &pinyin_table[711],  // "ㄗㄨㄟ" => "zui"
    &pinyin_table[707],  // "ㄗㄨㄢ" => "zuan"
    &pinyin_table[712],  // "ㄗㄨㄣ" => "zun"
    &pinyin_table[708],  // "ㄗㄨㄤ" => "zuang"
    &pinyin_table[702],  // "ㄗㄨㄥ" => "zong"
    &pinyin_table[73],   // "ㄘ" => "ci"
    &pinyin_table[32],   // "ㄘㄚ" => "ca"
    &pinyin_table[39],   // "ㄘㄜ" => "ce"
    &pinyin_table[34],   // "ㄘㄞ" => "cai"
    &pinyin_table[38],   // "ㄘㄠ" => "cao"
    &pinyin_table[77],   // "ㄘㄡ" => "cou"
    &pinyin_table[36],   // "ㄘㄢ" => "can"
    &pinyin_table[42],   // "ㄘㄣ" => "cen"
    &pinyin_table[37],   // "ㄘㄤ" => "cang"
    &pinyin_table[43],   // "ㄘㄥ" => "ceng"
    &pinyin_table[78],   // "ㄘㄨ" => "cu"
    &pinyin_table[86],   // "ㄘㄨㄛ" => "cuo"
    &pinyin_table[79],   // "ㄘㄨㄞ" => "cuai"
    &pinyin_table[84],   // "ㄘㄨㄟ" => "cui"
    &pinyin_table[80],   // "ㄘㄨㄢ" => "cuan"
    &pinyin_table[85],   // "ㄘㄨㄣ" => "cun"
    &pinyin_table[81],   // "ㄘㄨㄤ" => "cuang"
    &pinyin_table[76],   // "ㄘㄨㄥ" => "cong"
    &pinyin_table[531],  // "ㄙ" => "si"
    &pinyin_table[489],  // "ㄙㄚ" => "sa"
    &pinyin_table[496],  // "ㄙㄜ" => "se"
    &pinyin_table[491],  // "ㄙㄞ" => "sai"
    &pinyin_table[498],  // "ㄙㄟ" => "sei"
    &pinyin_table[495],  // "ㄙㄠ" => "sao"
    &pinyin_table[535],  // "ㄙㄡ" => "sou"
    &pinyin_table[493],  // "ㄙㄢ" => "san"
    &pinyin_table[500],  // "ㄙㄣ" => "sen"
    &pinyin_table[494],  // "ㄙㄤ" => "sang"
    &pinyin_table[501],  // "ㄙㄥ" => "seng"
    &pinyin_table[536],  // "ㄙㄨ" => "su"
    &pinyin_table[537],  // "ㄙㄨㄚ" => "sua"
    &pinyin_table[545],  // "ㄙㄨㄛ" => "suo"
    &pinyin_table[538],  // "ㄙㄨㄞ" => "suai"
    &pinyin_table[543],  // "ㄙㄨㄟ" => "sui"
    &pinyin_table[539],  // "ㄙㄨㄢ" => "suan"
    &pinyin_table[544],  // "ㄙㄨㄣ" => "sun"
    &pinyin_table[540],  // "ㄙㄨㄤ" => "suang"
    &pinyin_table[534],  // "ㄙㄨㄥ" => "song"
    &pinyin_table[0],    // "ㄚ" => "a"
    &pinyin_table[391],  // "ㄛ" => "o"
    &pinyin_table[125],  // "ㄜ" => "e"
    &pinyin_table[2],    // "ㄞ" => "ai"
    &pinyin_table[126],  // "ㄟ" => "ei"
    &pinyin_table[6],    // "ㄠ" => "ao"
    &pinyin_table[392],  // "ㄡ" => "ou"
    &pinyin_table[4],    // "ㄢ" => "an"
    &pinyin_table[127],  // "ㄣ" => "en"
    &pinyin_table[5],    // "ㄤ" => "ang"
    &pinyin_table[128],  // "ㄦ" => "er"
    &pinyin_table[632],  // "ㄧ" => "yi"
    &pinyin_table[625],  // "ㄧㄚ" => "ya"
    &pinyin_table[637],  // "ㄧㄛ" => "yo"
    &pinyin_table[631],  // "ㄧㄝ" => "ye"
    &pinyin_table[630],  // "ㄧㄠ" => "yao"
    &pinyin_table[641],  // "ㄧㄡ" => "you"
    &pinyin_table[628],  // "ㄧㄢ" => "yan"
    &pinyin_table[635],  // "ㄧㄣ" => "yin"
    &pinyin_table[629],  // "ㄧㄤ" => "yang"
    &pinyin_table[636],  // "ㄧㄥ" => "ying"
    &pinyin_table[644],  // "ㄧㄩㄤ" => "yuang"
    &pinyin_table[593],  // "ㄨ" => "wu"
    &pinyin_table[581],  // "ㄨㄚ" => "wa"
    &pinyin_table[592],  // "ㄨㄛ" => "wo"
    &pinyin_table[583],  // "ㄨㄞ" => "wai"
    &pinyin_table[588],  // "ㄨㄟ" => "wei"
    &pinyin_table[585],  // "ㄨㄢ" => "wan"
    &pinyin_table[590],  // "ㄨㄣ" => "wen"
    &pinyin_table[586],  // "ㄨㄤ" => "wang"
    &pinyin_table[591],  // "ㄨㄥ" => "weng"
    &pinyin_table[642],  // "ㄩ" => "yu"
    &pinyin_table[645],  // "ㄩㄝ" => "yue"
    &pinyin_table[643],  // "ㄩㄢ" => "yuan"
    &pinyin_table[647],  // "ㄩㄣ" => "yun"
    &pinyin_table[640],  // "ㄩㄥ" => "yong"
};

static const Pinyin *special_table[][4] = {
    { &pinyin_table[4],    &pinyin_table[0],    &pinyin_table[0],    &pinyin_table[350],  }, /* an a => a na */
    { &pinyin_table[4],    &pinyin_table[2],    &pinyin_table[0],    &pinyin_table[352],  }, /* an ai => a nai */
    { &pinyin_table[4],    &pinyin_table[6],    &pinyin_table[0],    &pinyin_table[356],  }, /* an ao => a nao */
    { &pinyin_table[4],    &pinyin_table[125],  &pinyin_table[0],    &pinyin_table[357],  }, /* an e => a ne */
    { &pinyin_table[4],    &pinyin_table[126],  &pinyin_table[0],    &pinyin_table[359],  }, /* an ei => a nei */
    { &pinyin_table[5],    &pinyin_table[0],    &pinyin_table[4],    &pinyin_table[157],  }, /* ang a => an ga */
    { &pinyin_table[5],    &pinyin_table[2],    &pinyin_table[4],    &pinyin_table[159],  }, /* ang ai => an gai */
    { &pinyin_table[5],    &pinyin_table[4],    &pinyin_table[4],    &pinyin_table[161],  }, /* ang an => an gan */
    { &pinyin_table[5],    &pinyin_table[5],    &pinyin_table[4],    &pinyin_table[162],  }, /* ang ang => an gang */
    { &pinyin_table[5],    &pinyin_table[6],    &pinyin_table[4],    &pinyin_table[163],  }, /* ang ao => an gao */
    { &pinyin_table[5],    &pinyin_table[125],  &pinyin_table[4],    &pinyin_table[164],  }, /* ang e => an ge */
    { &pinyin_table[5],    &pinyin_table[126],  &pinyin_table[4],    &pinyin_table[166],  }, /* ang ei => an gei */
    { &pinyin_table[5],    &pinyin_table[127],  &pinyin_table[4],    &pinyin_table[168],  }, /* ang en => an gen */
    { &pinyin_table[5],    &pinyin_table[392],  &pinyin_table[4],    &pinyin_table[173],  }, /* ang ou => an gou */
    { &pinyin_table[12],   &pinyin_table[0],    &pinyin_table[8],    &pinyin_table[350],  }, /* ban a => ba na */
    { &pinyin_table[12],   &pinyin_table[5],    &pinyin_table[8],    &pinyin_table[355],  }, /* ban ang => ba nang */
    { &pinyin_table[12],   &pinyin_table[6],    &pinyin_table[8],    &pinyin_table[356],  }, /* ban ao => ba nao */
    { &pinyin_table[12],   &pinyin_table[125],  &pinyin_table[8],    &pinyin_table[357],  }, /* ban e => ba ne */
    { &pinyin_table[12],   &pinyin_table[126],  &pinyin_table[8],    &pinyin_table[359],  }, /* ban ei => ba nei */
    { &pinyin_table[13],   &pinyin_table[2],    &pinyin_table[12],   &pinyin_table[159],  }, /* bang ai => ban gai */
    { &pinyin_table[13],   &pinyin_table[5],    &pinyin_table[12],   &pinyin_table[162],  }, /* bang ang => ban gang */
    { &pinyin_table[13],   &pinyin_table[6],    &pinyin_table[12],   &pinyin_table[163],  }, /* bang ao => ban gao */
    { &pinyin_table[13],   &pinyin_table[125],  &pinyin_table[12],   &pinyin_table[164],  }, /* bang e => ban ge */
    { &pinyin_table[13],   &pinyin_table[126],  &pinyin_table[12],   &pinyin_table[166],  }, /* bang ei => ban gei */
    { &pinyin_table[13],   &pinyin_table[127],  &pinyin_table[12],   &pinyin_table[168],  }, /* bang en => ban gen */
    { &pinyin_table[19],   &pinyin_table[0],    &pinyin_table[18],   &pinyin_table[157],  }, /* beng a => ben ga */
    { &pinyin_table[19],   &pinyin_table[2],    &pinyin_table[18],   &pinyin_table[159],  }, /* beng ai => ben gai */
    { &pinyin_table[19],   &pinyin_table[4],    &pinyin_table[18],   &pinyin_table[161],  }, /* beng an => ben gan */
    { &pinyin_table[19],   &pinyin_table[5],    &pinyin_table[18],   &pinyin_table[162],  }, /* beng ang => ben gang */
    { &pinyin_table[19],   &pinyin_table[6],    &pinyin_table[18],   &pinyin_table[163],  }, /* beng ao => ben gao */
    { &pinyin_table[19],   &pinyin_table[125],  &pinyin_table[18],   &pinyin_table[164],  }, /* beng e => ben ge */
    { &pinyin_table[19],   &pinyin_table[126],  &pinyin_table[18],   &pinyin_table[166],  }, /* beng ei => ben gei */
    { &pinyin_table[19],   &pinyin_table[127],  &pinyin_table[18],   &pinyin_table[168],  }, /* beng en => ben gen */
    { &pinyin_table[19],   &pinyin_table[392],  &pinyin_table[18],   &pinyin_table[173],  }, /* beng ou => ben gou */
    { &pinyin_table[22],   &pinyin_table[0],    &pinyin_table[21],   &pinyin_table[157],  }, /* biang a => bian ga */
    { &pinyin_table[22],   &pinyin_table[2],    &pinyin_table[21],   &pinyin_table[159],  }, /* biang ai => bian gai */
    { &pinyin_table[22],   &pinyin_table[4],    &pinyin_table[21],   &pinyin_table[161],  }, /* biang an => bian gan */
    { &pinyin_table[22],   &pinyin_table[5],    &pinyin_table[21],   &pinyin_table[162],  }, /* biang ang => bian gang */
    { &pinyin_table[22],   &pinyin_table[6],    &pinyin_table[21],   &pinyin_table[163],  }, /* biang ao => bian gao */
    { &pinyin_table[22],   &pinyin_table[125],  &pinyin_table[21],   &pinyin_table[164],  }, /* biang e => bian ge */
    { &pinyin_table[22],   &pinyin_table[126],  &pinyin_table[21],   &pinyin_table[166],  }, /* biang ei => bian gei */
    { &pinyin_table[22],   &pinyin_table[127],  &pinyin_table[21],   &pinyin_table[168],  }, /* biang en => bian gen */
    { &pinyin_table[22],   &pinyin_table[392],  &pinyin_table[21],   &pinyin_table[173],  }, /* biang ou => bian gou */
    { &pinyin_table[24],   &pinyin_table[448],  &pinyin_table[20],   &pinyin_table[128],  }, /* bie r => bi er */
    { &pinyin_table[27],   &pinyin_table[0],    &pinyin_table[20],   &pinyin_table[350],  }, /* bin a => bi na */
    { &pinyin_table[27],   &pinyin_table[2],    &pinyin_table[20],   &pinyin_table[352],  }, /* bin ai => bi nai */
    { &pinyin_table[27],   &pinyin_table[4],    &pinyin_table[20],   &pinyin_table[354],  }, /* bin an => bi nan */
    { &pinyin_table[27],   &pinyin_table[5],    &pinyin_table[20],   &pinyin_table[355],  }, /* bin ang => bi nang */
    { &pinyin_table[27],   &pinyin_table[6],    &pinyin_table[20],   &pinyin_table[356],  }, /* bin ao => bi nao */
    { &pinyin_table[27],   &pinyin_table[125],  &pinyin_table[20],   &pinyin_table[357],  }, /* bin e => bi ne */
    { &pinyin_table[27],   &pinyin_table[126],  &pinyin_table[20],   &pinyin_table[359],  }, /* bin ei => bi nei */
    { &pinyin_table[27],   &pinyin_table[127],  &pinyin_table[20],   &pinyin_table[361],  }, /* bin en => bi nen */
    { &pinyin_table[28],   &pinyin_table[125],  &pinyin_table[27],   &pinyin_table[164],  }, /* bing e => bin ge */
    { &pinyin_table[28],   &pinyin_table[126],  &pinyin_table[27],   &pinyin_table[166],  }, /* bing ei => bin gei */
    { &pinyin_table[36],   &pinyin_table[126],  &pinyin_table[32],   &pinyin_table[359],  }, /* can ei => ca nei */
    { &pinyin_table[37],   &pinyin_table[4],    &pinyin_table[36],   &pinyin_table[161],  }, /* cang an => can gan */
    { &pinyin_table[37],   &pinyin_table[5],    &pinyin_table[36],   &pinyin_table[162],  }, /* cang ang => can gang */
    { &pinyin_table[37],   &pinyin_table[125],  &pinyin_table[36],   &pinyin_table[164],  }, /* cang e => can ge */
    { &pinyin_table[37],   &pinyin_table[126],  &pinyin_table[36],   &pinyin_table[166],  }, /* cang ei => can gei */
    { &pinyin_table[37],   &pinyin_table[127],  &pinyin_table[36],   &pinyin_table[168],  }, /* cang en => can gen */
    { &pinyin_table[37],   &pinyin_table[392],  &pinyin_table[36],   &pinyin_table[173],  }, /* cang ou => can gou */
    { &pinyin_table[42],   &pinyin_table[0],    &pinyin_table[39],   &pinyin_table[350],  }, /* cen a => ce na */
    { &pinyin_table[42],   &pinyin_table[2],    &pinyin_table[39],   &pinyin_table[352],  }, /* cen ai => ce nai */
    { &pinyin_table[42],   &pinyin_table[4],    &pinyin_table[39],   &pinyin_table[354],  }, /* cen an => ce nan */
    { &pinyin_table[42],   &pinyin_table[5],    &pinyin_table[39],   &pinyin_table[355],  }, /* cen ang => ce nang */
    { &pinyin_table[42],   &pinyin_table[6],    &pinyin_table[39],   &pinyin_table[356],  }, /* cen ao => ce nao */
    { &pinyin_table[42],   &pinyin_table[125],  &pinyin_table[39],   &pinyin_table[357],  }, /* cen e => ce ne */
    { &pinyin_table[42],   &pinyin_table[126],  &pinyin_table[39],   &pinyin_table[359],  }, /* cen ei => ce nei */
    { &pinyin_table[42],   &pinyin_table[127],  &pinyin_table[39],   &pinyin_table[361],  }, /* cen en => ce nen */
    { &pinyin_table[43],   &pinyin_table[126],  &pinyin_table[42],   &pinyin_table[166],  }, /* ceng ei => cen gei */
    { &pinyin_table[49],   &pinyin_table[0],    &pinyin_table[45],   &pinyin_table[350],  }, /* chan a => cha na */
    { &pinyin_table[49],   &pinyin_table[6],    &pinyin_table[45],   &pinyin_table[356],  }, /* chan ao => cha nao */
    { &pinyin_table[49],   &pinyin_table[125],  &pinyin_table[45],   &pinyin_table[357],  }, /* chan e => cha ne */
    { &pinyin_table[49],   &pinyin_table[126],  &pinyin_table[45],   &pinyin_table[359],  }, /* chan ei => cha nei */
    { &pinyin_table[50],   &pinyin_table[5],    &pinyin_table[49],   &pinyin_table[162],  }, /* chang ang => chan gang */
    { &pinyin_table[50],   &pinyin_table[6],    &pinyin_table[49],   &pinyin_table[163],  }, /* chang ao => chan gao */
    { &pinyin_table[50],   &pinyin_table[126],  &pinyin_table[49],   &pinyin_table[166],  }, /* chang ei => chan gei */
    { &pinyin_table[50],   &pinyin_table[127],  &pinyin_table[49],   &pinyin_table[168],  }, /* chang en => chan gen */
    { &pinyin_table[50],   &pinyin_table[392],  &pinyin_table[49],   &pinyin_table[173],  }, /* chang ou => chan gou */
    { &pinyin_table[55],   &pinyin_table[0],    &pinyin_table[52],   &pinyin_table[350],  }, /* chen a => che na */
    { &pinyin_table[55],   &pinyin_table[4],    &pinyin_table[52],   &pinyin_table[354],  }, /* chen an => che nan */
    { &pinyin_table[55],   &pinyin_table[5],    &pinyin_table[52],   &pinyin_table[355],  }, /* chen ang => che nang */
    { &pinyin_table[55],   &pinyin_table[6],    &pinyin_table[52],   &pinyin_table[356],  }, /* chen ao => che nao */
    { &pinyin_table[55],   &pinyin_table[125],  &pinyin_table[52],   &pinyin_table[357],  }, /* chen e => che ne */
    { &pinyin_table[55],   &pinyin_table[126],  &pinyin_table[52],   &pinyin_table[359],  }, /* chen ei => che nei */
    { &pinyin_table[56],   &pinyin_table[5],    &pinyin_table[55],   &pinyin_table[162],  }, /* cheng ang => chen gang */
    { &pinyin_table[56],   &pinyin_table[6],    &pinyin_table[55],   &pinyin_table[163],  }, /* cheng ao => chen gao */
    { &pinyin_table[56],   &pinyin_table[126],  &pinyin_table[55],   &pinyin_table[166],  }, /* cheng ei => chen gei */
    { &pinyin_table[56],   &pinyin_table[392],  &pinyin_table[55],   &pinyin_table[173],  }, /* cheng ou => chen gou */
    { &pinyin_table[67],   &pinyin_table[4],    &pinyin_table[66],   &pinyin_table[161],  }, /* chuang an => chuan gan */
    { &pinyin_table[67],   &pinyin_table[5],    &pinyin_table[66],   &pinyin_table[162],  }, /* chuang ang => chuan gang */
    { &pinyin_table[67],   &pinyin_table[6],    &pinyin_table[66],   &pinyin_table[163],  }, /* chuang ao => chuan gao */
    { &pinyin_table[67],   &pinyin_table[125],  &pinyin_table[66],   &pinyin_table[164],  }, /* chuang e => chuan ge */
    { &pinyin_table[67],   &pinyin_table[126],  &pinyin_table[66],   &pinyin_table[166],  }, /* chuang ei => chuan gei */
    { &pinyin_table[67],   &pinyin_table[127],  &pinyin_table[66],   &pinyin_table[168],  }, /* chuang en => chuan gen */
    { &pinyin_table[67],   &pinyin_table[392],  &pinyin_table[66],   &pinyin_table[173],  }, /* chuang ou => chuan gou */
    { &pinyin_table[71],   &pinyin_table[0],    &pinyin_table[62],   &pinyin_table[350],  }, /* chun a => chu na */
    { &pinyin_table[71],   &pinyin_table[4],    &pinyin_table[62],   &pinyin_table[354],  }, /* chun an => chu nan */
    { &pinyin_table[71],   &pinyin_table[5],    &pinyin_table[62],   &pinyin_table[355],  }, /* chun ang => chu nang */
    { &pinyin_table[71],   &pinyin_table[6],    &pinyin_table[62],   &pinyin_table[356],  }, /* chun ao => chu nao */
    { &pinyin_table[71],   &pinyin_table[125],  &pinyin_table[62],   &pinyin_table[357],  }, /* chun e => chu ne */
    { &pinyin_table[71],   &pinyin_table[126],  &pinyin_table[62],   &pinyin_table[359],  }, /* chun ei => chu nei */
    { &pinyin_table[81],   &pinyin_table[0],    &pinyin_table[80],   &pinyin_table[157],  }, /* cuang a => cuan ga */
    { &pinyin_table[81],   &pinyin_table[2],    &pinyin_table[80],   &pinyin_table[159],  }, /* cuang ai => cuan gai */
    { &pinyin_table[81],   &pinyin_table[4],    &pinyin_table[80],   &pinyin_table[161],  }, /* cuang an => cuan gan */
    { &pinyin_table[81],   &pinyin_table[5],    &pinyin_table[80],   &pinyin_table[162],  }, /* cuang ang => cuan gang */
    { &pinyin_table[81],   &pinyin_table[6],    &pinyin_table[80],   &pinyin_table[163],  }, /* cuang ao => cuan gao */
    { &pinyin_table[81],   &pinyin_table[125],  &pinyin_table[80],   &pinyin_table[164],  }, /* cuang e => cuan ge */
    { &pinyin_table[81],   &pinyin_table[126],  &pinyin_table[80],   &pinyin_table[166],  }, /* cuang ei => cuan gei */
    { &pinyin_table[81],   &pinyin_table[127],  &pinyin_table[80],   &pinyin_table[168],  }, /* cuang en => cuan gen */
    { &pinyin_table[81],   &pinyin_table[392],  &pinyin_table[80],   &pinyin_table[173],  }, /* cuang ou => cuan gou */
    { &pinyin_table[85],   &pinyin_table[125],  &pinyin_table[78],   &pinyin_table[357],  }, /* cun e => cu ne */
    { &pinyin_table[85],   &pinyin_table[126],  &pinyin_table[78],   &pinyin_table[359],  }, /* cun ei => cu nei */
    { &pinyin_table[92],   &pinyin_table[0],    &pinyin_table[88],   &pinyin_table[350],  }, /* dan a => da na */
    { &pinyin_table[92],   &pinyin_table[2],    &pinyin_table[88],   &pinyin_table[352],  }, /* dan ai => da nai */
    { &pinyin_table[92],   &pinyin_table[4],    &pinyin_table[88],   &pinyin_table[354],  }, /* dan an => da nan */
    { &pinyin_table[92],   &pinyin_table[5],    &pinyin_table[88],   &pinyin_table[355],  }, /* dan ang => da nang */
    { &pinyin_table[92],   &pinyin_table[6],    &pinyin_table[88],   &pinyin_table[356],  }, /* dan ao => da nao */
    { &pinyin_table[92],   &pinyin_table[125],  &pinyin_table[88],   &pinyin_table[357],  }, /* dan e => da ne */
    { &pinyin_table[92],   &pinyin_table[126],  &pinyin_table[88],   &pinyin_table[359],  }, /* dan ei => da nei */
    { &pinyin_table[93],   &pinyin_table[2],    &pinyin_table[92],   &pinyin_table[159],  }, /* dang ai => dan gai */
    { &pinyin_table[93],   &pinyin_table[5],    &pinyin_table[92],   &pinyin_table[162],  }, /* dang ang => dan gang */
    { &pinyin_table[93],   &pinyin_table[6],    &pinyin_table[92],   &pinyin_table[163],  }, /* dang ao => dan gao */
    { &pinyin_table[93],   &pinyin_table[125],  &pinyin_table[92],   &pinyin_table[164],  }, /* dang e => dan ge */
    { &pinyin_table[93],   &pinyin_table[126],  &pinyin_table[92],   &pinyin_table[166],  }, /* dang ei => dan gei */
    { &pinyin_table[93],   &pinyin_table[127],  &pinyin_table[92],   &pinyin_table[168],  }, /* dang en => dan gen */
    { &pinyin_table[99],   &pinyin_table[0],    &pinyin_table[95],   &pinyin_table[350],  }, /* den a => de na */
    { &pinyin_table[99],   &pinyin_table[2],    &pinyin_table[95],   &pinyin_table[352],  }, /* den ai => de nai */
    { &pinyin_table[99],   &pinyin_table[4],    &pinyin_table[95],   &pinyin_table[354],  }, /* den an => de nan */
    { &pinyin_table[99],   &pinyin_table[5],    &pinyin_table[95],   &pinyin_table[355],  }, /* den ang => de nang */
    { &pinyin_table[99],   &pinyin_table[6],    &pinyin_table[95],   &pinyin_table[356],  }, /* den ao => de nao */
    { &pinyin_table[99],   &pinyin_table[125],  &pinyin_table[95],   &pinyin_table[357],  }, /* den e => de ne */
    { &pinyin_table[99],   &pinyin_table[126],  &pinyin_table[95],   &pinyin_table[359],  }, /* den ei => de nei */
    { &pinyin_table[99],   &pinyin_table[127],  &pinyin_table[95],   &pinyin_table[361],  }, /* den en => de nen */
    { &pinyin_table[99],   &pinyin_table[392],  &pinyin_table[95],   &pinyin_table[381],  }, /* den ou => de nou */
    { &pinyin_table[104],  &pinyin_table[0],    &pinyin_table[103],  &pinyin_table[157],  }, /* diang a => dian ga */
    { &pinyin_table[104],  &pinyin_table[2],    &pinyin_table[103],  &pinyin_table[159],  }, /* diang ai => dian gai */
    { &pinyin_table[104],  &pinyin_table[4],    &pinyin_table[103],  &pinyin_table[161],  }, /* diang an => dian gan */
    { &pinyin_table[104],  &pinyin_table[5],    &pinyin_table[103],  &pinyin_table[162],  }, /* diang ang => dian gang */
    { &pinyin_table[104],  &pinyin_table[6],    &pinyin_table[103],  &pinyin_table[163],  }, /* diang ao => dian gao */
    { &pinyin_table[104],  &pinyin_table[125],  &pinyin_table[103],  &pinyin_table[164],  }, /* diang e => dian ge */
    { &pinyin_table[104],  &pinyin_table[126],  &pinyin_table[103],  &pinyin_table[166],  }, /* diang ei => dian gei */
    { &pinyin_table[104],  &pinyin_table[127],  &pinyin_table[103],  &pinyin_table[168],  }, /* diang en => dian gen */
    { &pinyin_table[104],  &pinyin_table[392],  &pinyin_table[103],  &pinyin_table[173],  }, /* diang ou => dian gou */
    { &pinyin_table[106],  &pinyin_table[448],  &pinyin_table[101],  &pinyin_table[128],  }, /* die r => di er */
    { &pinyin_table[109],  &pinyin_table[0],    &pinyin_table[101],  &pinyin_table[350],  }, /* din a => di na */
    { &pinyin_table[109],  &pinyin_table[2],    &pinyin_table[101],  &pinyin_table[352],  }, /* din ai => di nai */
    { &pinyin_table[109],  &pinyin_table[4],    &pinyin_table[101],  &pinyin_table[354],  }, /* din an => di nan */
    { &pinyin_table[109],  &pinyin_table[5],    &pinyin_table[101],  &pinyin_table[355],  }, /* din ang => di nang */
    { &pinyin_table[109],  &pinyin_table[6],    &pinyin_table[101],  &pinyin_table[356],  }, /* din ao => di nao */
    { &pinyin_table[109],  &pinyin_table[125],  &pinyin_table[101],  &pinyin_table[357],  }, /* din e => di ne */
    { &pinyin_table[109],  &pinyin_table[126],  &pinyin_table[101],  &pinyin_table[359],  }, /* din ei => di nei */
    { &pinyin_table[109],  &pinyin_table[127],  &pinyin_table[101],  &pinyin_table[361],  }, /* din en => di nen */
    { &pinyin_table[109],  &pinyin_table[392],  &pinyin_table[101],  &pinyin_table[381],  }, /* din ou => di nou */
    { &pinyin_table[119],  &pinyin_table[0],    &pinyin_table[118],  &pinyin_table[157],  }, /* duang a => duan ga */
    { &pinyin_table[119],  &pinyin_table[2],    &pinyin_table[118],  &pinyin_table[159],  }, /* duang ai => duan gai */
    { &pinyin_table[119],  &pinyin_table[4],    &pinyin_table[118],  &pinyin_table[161],  }, /* duang an => duan gan */
    { &pinyin_table[119],  &pinyin_table[5],    &pinyin_table[118],  &pinyin_table[162],  }, /* duang ang => duan gang */
    { &pinyin_table[119],  &pinyin_table[6],    &pinyin_table[118],  &pinyin_table[163],  }, /* duang ao => duan gao */
    { &pinyin_table[119],  &pinyin_table[125],  &pinyin_table[118],  &pinyin_table[164],  }, /* duang e => duan ge */
    { &pinyin_table[119],  &pinyin_table[126],  &pinyin_table[118],  &pinyin_table[166],  }, /* duang ei => duan gei */
    { &pinyin_table[119],  &pinyin_table[127],  &pinyin_table[118],  &pinyin_table[168],  }, /* duang en => duan gen */
    { &pinyin_table[119],  &pinyin_table[392],  &pinyin_table[118],  &pinyin_table[173],  }, /* duang ou => duan gou */
    { &pinyin_table[123],  &pinyin_table[0],    &pinyin_table[117],  &pinyin_table[350],  }, /* dun a => du na */
    { &pinyin_table[123],  &pinyin_table[4],    &pinyin_table[117],  &pinyin_table[354],  }, /* dun an => du nan */
    { &pinyin_table[123],  &pinyin_table[5],    &pinyin_table[117],  &pinyin_table[355],  }, /* dun ang => du nang */
    { &pinyin_table[123],  &pinyin_table[6],    &pinyin_table[117],  &pinyin_table[356],  }, /* dun ao => du nao */
    { &pinyin_table[123],  &pinyin_table[125],  &pinyin_table[117],  &pinyin_table[357],  }, /* dun e => du ne */
    { &pinyin_table[123],  &pinyin_table[126],  &pinyin_table[117],  &pinyin_table[359],  }, /* dun ei => du nei */
    { &pinyin_table[127],  &pinyin_table[4],    &pinyin_table[125],  &pinyin_table[354],  }, /* en an => e nan */
    { &pinyin_table[127],  &pinyin_table[5],    &pinyin_table[125],  &pinyin_table[355],  }, /* en ang => e nang */
    { &pinyin_table[127],  &pinyin_table[6],    &pinyin_table[125],  &pinyin_table[356],  }, /* en ao => e nao */
    { &pinyin_table[127],  &pinyin_table[125],  &pinyin_table[125],  &pinyin_table[357],  }, /* en e => e ne */
    { &pinyin_table[127],  &pinyin_table[126],  &pinyin_table[125],  &pinyin_table[359],  }, /* en ei => e nei */
    { &pinyin_table[128],  &pinyin_table[4],    &pinyin_table[125],  &pinyin_table[453],  }, /* er an => e ran */
    { &pinyin_table[128],  &pinyin_table[5],    &pinyin_table[125],  &pinyin_table[454],  }, /* er ang => e rang */
    { &pinyin_table[128],  &pinyin_table[127],  &pinyin_table[125],  &pinyin_table[460],  }, /* er en => e ren */
    { &pinyin_table[128],  &pinyin_table[392],  &pinyin_table[125],  &pinyin_table[476],  }, /* er ou => e rou */
    { &pinyin_table[134],  &pinyin_table[5],    &pinyin_table[130],  &pinyin_table[355],  }, /* fan ang => fa nang */
    { &pinyin_table[134],  &pinyin_table[6],    &pinyin_table[130],  &pinyin_table[356],  }, /* fan ao => fa nao */
    { &pinyin_table[134],  &pinyin_table[126],  &pinyin_table[130],  &pinyin_table[359],  }, /* fan ei => fa nei */
    { &pinyin_table[135],  &pinyin_table[5],    &pinyin_table[134],  &pinyin_table[162],  }, /* fang ang => fan gang */
    { &pinyin_table[135],  &pinyin_table[6],    &pinyin_table[134],  &pinyin_table[163],  }, /* fang ao => fan gao */
    { &pinyin_table[135],  &pinyin_table[125],  &pinyin_table[134],  &pinyin_table[164],  }, /* fang e => fan ge */
    { &pinyin_table[135],  &pinyin_table[126],  &pinyin_table[134],  &pinyin_table[166],  }, /* fang ei => fan gei */
    { &pinyin_table[135],  &pinyin_table[127],  &pinyin_table[134],  &pinyin_table[168],  }, /* fang en => fan gen */
    { &pinyin_table[142],  &pinyin_table[5],    &pinyin_table[141],  &pinyin_table[162],  }, /* feng ang => fen gang */
    { &pinyin_table[142],  &pinyin_table[6],    &pinyin_table[141],  &pinyin_table[163],  }, /* feng ao => fen gao */
    { &pinyin_table[142],  &pinyin_table[125],  &pinyin_table[141],  &pinyin_table[164],  }, /* feng e => fen ge */
    { &pinyin_table[142],  &pinyin_table[126],  &pinyin_table[141],  &pinyin_table[166],  }, /* feng ei => fen gei */
    { &pinyin_table[142],  &pinyin_table[127],  &pinyin_table[141],  &pinyin_table[168],  }, /* feng en => fen gen */
    { &pinyin_table[142],  &pinyin_table[392],  &pinyin_table[141],  &pinyin_table[173],  }, /* feng ou => fen gou */
    { &pinyin_table[154],  &pinyin_table[0],    &pinyin_table[146],  &pinyin_table[350],  }, /* fun a => fu na */
    { &pinyin_table[154],  &pinyin_table[2],    &pinyin_table[146],  &pinyin_table[352],  }, /* fun ai => fu nai */
    { &pinyin_table[154],  &pinyin_table[4],    &pinyin_table[146],  &pinyin_table[354],  }, /* fun an => fu nan */
    { &pinyin_table[154],  &pinyin_table[5],    &pinyin_table[146],  &pinyin_table[355],  }, /* fun ang => fu nang */
    { &pinyin_table[154],  &pinyin_table[6],    &pinyin_table[146],  &pinyin_table[356],  }, /* fun ao => fu nao */
    { &pinyin_table[154],  &pinyin_table[125],  &pinyin_table[146],  &pinyin_table[357],  }, /* fun e => fu ne */
    { &pinyin_table[154],  &pinyin_table[126],  &pinyin_table[146],  &pinyin_table[359],  }, /* fun ei => fu nei */
    { &pinyin_table[154],  &pinyin_table[127],  &pinyin_table[146],  &pinyin_table[361],  }, /* fun en => fu nen */
    { &pinyin_table[154],  &pinyin_table[392],  &pinyin_table[146],  &pinyin_table[381],  }, /* fun ou => fu nou */
    { &pinyin_table[161],  &pinyin_table[125],  &pinyin_table[157],  &pinyin_table[357],  }, /* gan e => ga ne */
    { &pinyin_table[161],  &pinyin_table[126],  &pinyin_table[157],  &pinyin_table[359],  }, /* gan ei => ga nei */
    { &pinyin_table[162],  &pinyin_table[0],    &pinyin_table[161],  &pinyin_table[157],  }, /* gang a => gan ga */
    { &pinyin_table[162],  &pinyin_table[2],    &pinyin_table[161],  &pinyin_table[159],  }, /* gang ai => gan gai */
    { &pinyin_table[162],  &pinyin_table[4],    &pinyin_table[161],  &pinyin_table[161],  }, /* gang an => gan gan */
    { &pinyin_table[162],  &pinyin_table[5],    &pinyin_table[161],  &pinyin_table[162],  }, /* gang ang => gan gang */
    { &pinyin_table[162],  &pinyin_table[125],  &pinyin_table[161],  &pinyin_table[164],  }, /* gang e => gan ge */
    { &pinyin_table[162],  &pinyin_table[126],  &pinyin_table[161],  &pinyin_table[166],  }, /* gang ei => gan gei */
    { &pinyin_table[162],  &pinyin_table[127],  &pinyin_table[161],  &pinyin_table[168],  }, /* gang en => gan gen */
    { &pinyin_table[162],  &pinyin_table[392],  &pinyin_table[161],  &pinyin_table[173],  }, /* gang ou => gan gou */
    { &pinyin_table[168],  &pinyin_table[0],    &pinyin_table[164],  &pinyin_table[350],  }, /* gen a => ge na */
    { &pinyin_table[168],  &pinyin_table[4],    &pinyin_table[164],  &pinyin_table[354],  }, /* gen an => ge nan */
    { &pinyin_table[168],  &pinyin_table[5],    &pinyin_table[164],  &pinyin_table[355],  }, /* gen ang => ge nang */
    { &pinyin_table[168],  &pinyin_table[6],    &pinyin_table[164],  &pinyin_table[356],  }, /* gen ao => ge nao */
    { &pinyin_table[168],  &pinyin_table[125],  &pinyin_table[164],  &pinyin_table[357],  }, /* gen e => ge ne */
    { &pinyin_table[168],  &pinyin_table[126],  &pinyin_table[164],  &pinyin_table[359],  }, /* gen ei => ge nei */
    { &pinyin_table[169],  &pinyin_table[5],    &pinyin_table[168],  &pinyin_table[162],  }, /* geng ang => gen gang */
    { &pinyin_table[169],  &pinyin_table[6],    &pinyin_table[168],  &pinyin_table[163],  }, /* geng ao => gen gao */
    { &pinyin_table[169],  &pinyin_table[125],  &pinyin_table[168],  &pinyin_table[164],  }, /* geng e => gen ge */
    { &pinyin_table[169],  &pinyin_table[126],  &pinyin_table[168],  &pinyin_table[166],  }, /* geng ei => gen gei */
    { &pinyin_table[169],  &pinyin_table[127],  &pinyin_table[168],  &pinyin_table[168],  }, /* geng en => gen gen */
    { &pinyin_table[169],  &pinyin_table[392],  &pinyin_table[168],  &pinyin_table[173],  }, /* geng ou => gen gou */
    { &pinyin_table[179],  &pinyin_table[126],  &pinyin_table[175],  &pinyin_table[359],  }, /* guan ei => gua nei */
    { &pinyin_table[180],  &pinyin_table[2],    &pinyin_table[179],  &pinyin_table[159],  }, /* guang ai => guan gai */
    { &pinyin_table[180],  &pinyin_table[5],    &pinyin_table[179],  &pinyin_table[162],  }, /* guang ang => guan gang */
    { &pinyin_table[180],  &pinyin_table[6],    &pinyin_table[179],  &pinyin_table[163],  }, /* guang ao => guan gao */
    { &pinyin_table[180],  &pinyin_table[125],  &pinyin_table[179],  &pinyin_table[164],  }, /* guang e => guan ge */
    { &pinyin_table[180],  &pinyin_table[126],  &pinyin_table[179],  &pinyin_table[166],  }, /* guang ei => guan gei */
    { &pinyin_table[180],  &pinyin_table[127],  &pinyin_table[179],  &pinyin_table[168],  }, /* guang en => guan gen */
    { &pinyin_table[184],  &pinyin_table[4],    &pinyin_table[174],  &pinyin_table[354],  }, /* gun an => gu nan */
    { &pinyin_table[184],  &pinyin_table[5],    &pinyin_table[174],  &pinyin_table[355],  }, /* gun ang => gu nang */
    { &pinyin_table[184],  &pinyin_table[6],    &pinyin_table[174],  &pinyin_table[356],  }, /* gun ao => gu nao */
    { &pinyin_table[184],  &pinyin_table[125],  &pinyin_table[174],  &pinyin_table[357],  }, /* gun e => gu ne */
    { &pinyin_table[184],  &pinyin_table[126],  &pinyin_table[174],  &pinyin_table[359],  }, /* gun ei => gu nei */
    { &pinyin_table[191],  &pinyin_table[5],    &pinyin_table[187],  &pinyin_table[355],  }, /* han ang => ha nang */
    { &pinyin_table[191],  &pinyin_table[6],    &pinyin_table[187],  &pinyin_table[356],  }, /* han ao => ha nao */
    { &pinyin_table[191],  &pinyin_table[126],  &pinyin_table[187],  &pinyin_table[359],  }, /* han ei => ha nei */
    { &pinyin_table[192],  &pinyin_table[2],    &pinyin_table[191],  &pinyin_table[159],  }, /* hang ai => han gai */
    { &pinyin_table[192],  &pinyin_table[5],    &pinyin_table[191],  &pinyin_table[162],  }, /* hang ang => han gang */
    { &pinyin_table[192],  &pinyin_table[6],    &pinyin_table[191],  &pinyin_table[163],  }, /* hang ao => han gao */
    { &pinyin_table[192],  &pinyin_table[125],  &pinyin_table[191],  &pinyin_table[164],  }, /* hang e => han ge */
    { &pinyin_table[192],  &pinyin_table[126],  &pinyin_table[191],  &pinyin_table[166],  }, /* hang ei => han gei */
    { &pinyin_table[192],  &pinyin_table[127],  &pinyin_table[191],  &pinyin_table[168],  }, /* hang en => han gen */
    { &pinyin_table[192],  &pinyin_table[392],  &pinyin_table[191],  &pinyin_table[173],  }, /* hang ou => han gou */
    { &pinyin_table[198],  &pinyin_table[0],    &pinyin_table[194],  &pinyin_table[350],  }, /* hen a => he na */
    { &pinyin_table[198],  &pinyin_table[4],    &pinyin_table[194],  &pinyin_table[354],  }, /* hen an => he nan */
    { &pinyin_table[198],  &pinyin_table[5],    &pinyin_table[194],  &pinyin_table[355],  }, /* hen ang => he nang */
    { &pinyin_table[198],  &pinyin_table[6],    &pinyin_table[194],  &pinyin_table[356],  }, /* hen ao => he nao */
    { &pinyin_table[198],  &pinyin_table[126],  &pinyin_table[194],  &pinyin_table[359],  }, /* hen ei => he nei */
    { &pinyin_table[199],  &pinyin_table[2],    &pinyin_table[198],  &pinyin_table[159],  }, /* heng ai => hen gai */
    { &pinyin_table[199],  &pinyin_table[4],    &pinyin_table[198],  &pinyin_table[161],  }, /* heng an => hen gan */
    { &pinyin_table[199],  &pinyin_table[5],    &pinyin_table[198],  &pinyin_table[162],  }, /* heng ang => hen gang */
    { &pinyin_table[199],  &pinyin_table[6],    &pinyin_table[198],  &pinyin_table[163],  }, /* heng ao => hen gao */
    { &pinyin_table[199],  &pinyin_table[126],  &pinyin_table[198],  &pinyin_table[166],  }, /* heng ei => hen gei */
    { &pinyin_table[199],  &pinyin_table[127],  &pinyin_table[198],  &pinyin_table[168],  }, /* heng en => hen gen */
    { &pinyin_table[199],  &pinyin_table[392],  &pinyin_table[198],  &pinyin_table[173],  }, /* heng ou => hen gou */
    { &pinyin_table[210],  &pinyin_table[0],    &pinyin_table[206],  &pinyin_table[350],  }, /* huan a => hua na */
    { &pinyin_table[210],  &pinyin_table[4],    &pinyin_table[206],  &pinyin_table[354],  }, /* huan an => hua nan */
    { &pinyin_table[210],  &pinyin_table[5],    &pinyin_table[206],  &pinyin_table[355],  }, /* huan ang => hua nang */
    { &pinyin_table[210],  &pinyin_table[6],    &pinyin_table[206],  &pinyin_table[356],  }, /* huan ao => hua nao */
    { &pinyin_table[210],  &pinyin_table[125],  &pinyin_table[206],  &pinyin_table[357],  }, /* huan e => hua ne */
    { &pinyin_table[210],  &pinyin_table[126],  &pinyin_table[206],  &pinyin_table[359],  }, /* huan ei => hua nei */
    { &pinyin_table[210],  &pinyin_table[127],  &pinyin_table[206],  &pinyin_table[361],  }, /* huan en => hua nen */
    { &pinyin_table[211],  &pinyin_table[2],    &pinyin_table[210],  &pinyin_table[159],  }, /* huang ai => huan gai */
    { &pinyin_table[211],  &pinyin_table[5],    &pinyin_table[210],  &pinyin_table[162],  }, /* huang ang => huan gang */
    { &pinyin_table[211],  &pinyin_table[6],    &pinyin_table[210],  &pinyin_table[163],  }, /* huang ao => huan gao */
    { &pinyin_table[211],  &pinyin_table[125],  &pinyin_table[210],  &pinyin_table[164],  }, /* huang e => huan ge */
    { &pinyin_table[211],  &pinyin_table[126],  &pinyin_table[210],  &pinyin_table[166],  }, /* huang ei => huan gei */
    { &pinyin_table[211],  &pinyin_table[392],  &pinyin_table[210],  &pinyin_table[173],  }, /* huang ou => huan gou */
    { &pinyin_table[215],  &pinyin_table[4],    &pinyin_table[205],  &pinyin_table[354],  }, /* hun an => hu nan */
    { &pinyin_table[215],  &pinyin_table[5],    &pinyin_table[205],  &pinyin_table[355],  }, /* hun ang => hu nang */
    { &pinyin_table[215],  &pinyin_table[6],    &pinyin_table[205],  &pinyin_table[356],  }, /* hun ao => hu nao */
    { &pinyin_table[215],  &pinyin_table[126],  &pinyin_table[205],  &pinyin_table[359],  }, /* hun ei => hu nei */
    { &pinyin_table[222],  &pinyin_table[0],    &pinyin_table[219],  &pinyin_table[350],  }, /* jian a => jia na */
    { &pinyin_table[222],  &pinyin_table[2],    &pinyin_table[219],  &pinyin_table[352],  }, /* jian ai => jia nai */
    { &pinyin_table[222],  &pinyin_table[5],    &pinyin_table[219],  &pinyin_table[355],  }, /* jian ang => jia nang */
    { &pinyin_table[222],  &pinyin_table[125],  &pinyin_table[219],  &pinyin_table[357],  }, /* jian e => jia ne */
    { &pinyin_table[222],  &pinyin_table[126],  &pinyin_table[219],  &pinyin_table[359],  }, /* jian ei => jia nei */
    { &pinyin_table[223],  &pinyin_table[5],    &pinyin_table[222],  &pinyin_table[162],  }, /* jiang ang => jian gang */
    { &pinyin_table[223],  &pinyin_table[6],    &pinyin_table[222],  &pinyin_table[163],  }, /* jiang ao => jian gao */
    { &pinyin_table[223],  &pinyin_table[125],  &pinyin_table[222],  &pinyin_table[164],  }, /* jiang e => jian ge */
    { &pinyin_table[223],  &pinyin_table[126],  &pinyin_table[222],  &pinyin_table[166],  }, /* jiang ei => jian gei */
    { &pinyin_table[223],  &pinyin_table[392],  &pinyin_table[222],  &pinyin_table[173],  }, /* jiang ou => jian gou */
    { &pinyin_table[225],  &pinyin_table[448],  &pinyin_table[218],  &pinyin_table[128],  }, /* jie r => ji er */
    { &pinyin_table[228],  &pinyin_table[0],    &pinyin_table[218],  &pinyin_table[350],  }, /* jin a => ji na */
    { &pinyin_table[228],  &pinyin_table[4],    &pinyin_table[218],  &pinyin_table[354],  }, /* jin an => ji nan */
    { &pinyin_table[228],  &pinyin_table[5],    &pinyin_table[218],  &pinyin_table[355],  }, /* jin ang => ji nang */
    { &pinyin_table[228],  &pinyin_table[6],    &pinyin_table[218],  &pinyin_table[356],  }, /* jin ao => ji nao */
    { &pinyin_table[228],  &pinyin_table[126],  &pinyin_table[218],  &pinyin_table[359],  }, /* jin ei => ji nei */
    { &pinyin_table[229],  &pinyin_table[5],    &pinyin_table[228],  &pinyin_table[162],  }, /* jing ang => jin gang */
    { &pinyin_table[229],  &pinyin_table[6],    &pinyin_table[228],  &pinyin_table[163],  }, /* jing ao => jin gao */
    { &pinyin_table[229],  &pinyin_table[126],  &pinyin_table[228],  &pinyin_table[166],  }, /* jing ei => jin gei */
    { &pinyin_table[229],  &pinyin_table[127],  &pinyin_table[228],  &pinyin_table[168],  }, /* jing en => jin gen */
    { &pinyin_table[229],  &pinyin_table[392],  &pinyin_table[228],  &pinyin_table[173],  }, /* jing ou => jin gou */
    { &pinyin_table[237],  &pinyin_table[0],    &pinyin_table[236],  &pinyin_table[157],  }, /* juang a => juan ga */
    { &pinyin_table[237],  &pinyin_table[2],    &pinyin_table[236],  &pinyin_table[159],  }, /* juang ai => juan gai */
    { &pinyin_table[237],  &pinyin_table[4],    &pinyin_table[236],  &pinyin_table[161],  }, /* juang an => juan gan */
    { &pinyin_table[237],  &pinyin_table[5],    &pinyin_table[236],  &pinyin_table[162],  }, /* juang ang => juan gang */
    { &pinyin_table[237],  &pinyin_table[6],    &pinyin_table[236],  &pinyin_table[163],  }, /* juang ao => juan gao */
    { &pinyin_table[237],  &pinyin_table[125],  &pinyin_table[236],  &pinyin_table[164],  }, /* juang e => juan ge */
    { &pinyin_table[237],  &pinyin_table[126],  &pinyin_table[236],  &pinyin_table[166],  }, /* juang ei => juan gei */
    { &pinyin_table[237],  &pinyin_table[127],  &pinyin_table[236],  &pinyin_table[168],  }, /* juang en => juan gen */
    { &pinyin_table[237],  &pinyin_table[392],  &pinyin_table[236],  &pinyin_table[173],  }, /* juang ou => juan gou */
    { &pinyin_table[238],  &pinyin_table[448],  &pinyin_table[235],  &pinyin_table[128],  }, /* jue r => ju er */
    { &pinyin_table[239],  &pinyin_table[0],    &pinyin_table[238],  &pinyin_table[350],  }, /* juen a => jue na */
    { &pinyin_table[239],  &pinyin_table[2],    &pinyin_table[238],  &pinyin_table[352],  }, /* juen ai => jue nai */
    { &pinyin_table[239],  &pinyin_table[4],    &pinyin_table[238],  &pinyin_table[354],  }, /* juen an => jue nan */
    { &pinyin_table[239],  &pinyin_table[5],    &pinyin_table[238],  &pinyin_table[355],  }, /* juen ang => jue nang */
    { &pinyin_table[239],  &pinyin_table[6],    &pinyin_table[238],  &pinyin_table[356],  }, /* juen ao => jue nao */
    { &pinyin_table[239],  &pinyin_table[125],  &pinyin_table[238],  &pinyin_table[357],  }, /* juen e => jue ne */
    { &pinyin_table[239],  &pinyin_table[126],  &pinyin_table[238],  &pinyin_table[359],  }, /* juen ei => jue nei */
    { &pinyin_table[239],  &pinyin_table[127],  &pinyin_table[238],  &pinyin_table[361],  }, /* juen en => jue nen */
    { &pinyin_table[239],  &pinyin_table[392],  &pinyin_table[238],  &pinyin_table[381],  }, /* juen ou => jue nou */
    { &pinyin_table[240],  &pinyin_table[0],    &pinyin_table[235],  &pinyin_table[350],  }, /* jun a => ju na */
    { &pinyin_table[240],  &pinyin_table[2],    &pinyin_table[235],  &pinyin_table[352],  }, /* jun ai => ju nai */
    { &pinyin_table[240],  &pinyin_table[125],  &pinyin_table[235],  &pinyin_table[357],  }, /* jun e => ju ne */
    { &pinyin_table[240],  &pinyin_table[126],  &pinyin_table[235],  &pinyin_table[359],  }, /* jun ei => ju nei */
    { &pinyin_table[252],  &pinyin_table[126],  &pinyin_table[248],  &pinyin_table[359],  }, /* kan ei => ka nei */
    { &pinyin_table[253],  &pinyin_table[4],    &pinyin_table[252],  &pinyin_table[161],  }, /* kang an => kan gan */
    { &pinyin_table[253],  &pinyin_table[5],    &pinyin_table[252],  &pinyin_table[162],  }, /* kang ang => kan gang */
    { &pinyin_table[253],  &pinyin_table[6],    &pinyin_table[252],  &pinyin_table[163],  }, /* kang ao => kan gao */
    { &pinyin_table[253],  &pinyin_table[125],  &pinyin_table[252],  &pinyin_table[164],  }, /* kang e => kan ge */
    { &pinyin_table[253],  &pinyin_table[126],  &pinyin_table[252],  &pinyin_table[166],  }, /* kang ei => kan gei */
    { &pinyin_table[253],  &pinyin_table[127],  &pinyin_table[252],  &pinyin_table[168],  }, /* kang en => kan gen */
    { &pinyin_table[253],  &pinyin_table[392],  &pinyin_table[252],  &pinyin_table[173],  }, /* kang ou => kan gou */
    { &pinyin_table[259],  &pinyin_table[0],    &pinyin_table[255],  &pinyin_table[350],  }, /* ken a => ke na */
    { &pinyin_table[259],  &pinyin_table[2],    &pinyin_table[255],  &pinyin_table[352],  }, /* ken ai => ke nai */
    { &pinyin_table[259],  &pinyin_table[4],    &pinyin_table[255],  &pinyin_table[354],  }, /* ken an => ke nan */
    { &pinyin_table[259],  &pinyin_table[5],    &pinyin_table[255],  &pinyin_table[355],  }, /* ken ang => ke nang */
    { &pinyin_table[259],  &pinyin_table[6],    &pinyin_table[255],  &pinyin_table[356],  }, /* ken ao => ke nao */
    { &pinyin_table[259],  &pinyin_table[125],  &pinyin_table[255],  &pinyin_table[357],  }, /* ken e => ke ne */
    { &pinyin_table[259],  &pinyin_table[126],  &pinyin_table[255],  &pinyin_table[359],  }, /* ken ei => ke nei */
    { &pinyin_table[260],  &pinyin_table[2],    &pinyin_table[259],  &pinyin_table[159],  }, /* keng ai => ken gai */
    { &pinyin_table[260],  &pinyin_table[4],    &pinyin_table[259],  &pinyin_table[161],  }, /* keng an => ken gan */
    { &pinyin_table[260],  &pinyin_table[5],    &pinyin_table[259],  &pinyin_table[162],  }, /* keng ang => ken gang */
    { &pinyin_table[260],  &pinyin_table[6],    &pinyin_table[259],  &pinyin_table[163],  }, /* keng ao => ken gao */
    { &pinyin_table[260],  &pinyin_table[125],  &pinyin_table[259],  &pinyin_table[164],  }, /* keng e => ken ge */
    { &pinyin_table[260],  &pinyin_table[126],  &pinyin_table[259],  &pinyin_table[166],  }, /* keng ei => ken gei */
    { &pinyin_table[260],  &pinyin_table[127],  &pinyin_table[259],  &pinyin_table[168],  }, /* keng en => ken gen */
    { &pinyin_table[260],  &pinyin_table[392],  &pinyin_table[259],  &pinyin_table[173],  }, /* keng ou => ken gou */
    { &pinyin_table[270],  &pinyin_table[0],    &pinyin_table[266],  &pinyin_table[350],  }, /* kuan a => kua na */
    { &pinyin_table[270],  &pinyin_table[126],  &pinyin_table[266],  &pinyin_table[359],  }, /* kuan ei => kua nei */
    { &pinyin_table[271],  &pinyin_table[5],    &pinyin_table[270],  &pinyin_table[162],  }, /* kuang ang => kuan gang */
    { &pinyin_table[271],  &pinyin_table[125],  &pinyin_table[270],  &pinyin_table[164],  }, /* kuang e => kuan ge */
    { &pinyin_table[271],  &pinyin_table[126],  &pinyin_table[270],  &pinyin_table[166],  }, /* kuang ei => kuan gei */
    { &pinyin_table[271],  &pinyin_table[127],  &pinyin_table[270],  &pinyin_table[168],  }, /* kuang en => kuan gen */
    { &pinyin_table[275],  &pinyin_table[4],    &pinyin_table[265],  &pinyin_table[354],  }, /* kun an => ku nan */
    { &pinyin_table[275],  &pinyin_table[5],    &pinyin_table[265],  &pinyin_table[355],  }, /* kun ang => ku nang */
    { &pinyin_table[275],  &pinyin_table[6],    &pinyin_table[265],  &pinyin_table[356],  }, /* kun ao => ku nao */
    { &pinyin_table[275],  &pinyin_table[125],  &pinyin_table[265],  &pinyin_table[357],  }, /* kun e => ku ne */
    { &pinyin_table[275],  &pinyin_table[126],  &pinyin_table[265],  &pinyin_table[359],  }, /* kun ei => ku nei */
    { &pinyin_table[282],  &pinyin_table[0],    &pinyin_table[278],  &pinyin_table[350],  }, /* lan a => la na */
    { &pinyin_table[282],  &pinyin_table[4],    &pinyin_table[278],  &pinyin_table[354],  }, /* lan an => la nan */
    { &pinyin_table[282],  &pinyin_table[5],    &pinyin_table[278],  &pinyin_table[355],  }, /* lan ang => la nang */
    { &pinyin_table[282],  &pinyin_table[6],    &pinyin_table[278],  &pinyin_table[356],  }, /* lan ao => la nao */
    { &pinyin_table[282],  &pinyin_table[125],  &pinyin_table[278],  &pinyin_table[357],  }, /* lan e => la ne */
    { &pinyin_table[282],  &pinyin_table[126],  &pinyin_table[278],  &pinyin_table[359],  }, /* lan ei => la nei */
    { &pinyin_table[283],  &pinyin_table[4],    &pinyin_table[282],  &pinyin_table[161],  }, /* lang an => lan gan */
    { &pinyin_table[283],  &pinyin_table[5],    &pinyin_table[282],  &pinyin_table[162],  }, /* lang ang => lan gang */
    { &pinyin_table[283],  &pinyin_table[6],    &pinyin_table[282],  &pinyin_table[163],  }, /* lang ao => lan gao */
    { &pinyin_table[283],  &pinyin_table[125],  &pinyin_table[282],  &pinyin_table[164],  }, /* lang e => lan ge */
    { &pinyin_table[283],  &pinyin_table[126],  &pinyin_table[282],  &pinyin_table[166],  }, /* lang ei => lan gei */
    { &pinyin_table[283],  &pinyin_table[127],  &pinyin_table[282],  &pinyin_table[168],  }, /* lang en => lan gen */
    { &pinyin_table[283],  &pinyin_table[392],  &pinyin_table[282],  &pinyin_table[173],  }, /* lang ou => lan gou */
    { &pinyin_table[289],  &pinyin_table[0],    &pinyin_table[285],  &pinyin_table[350],  }, /* len a => le na */
    { &pinyin_table[289],  &pinyin_table[2],    &pinyin_table[285],  &pinyin_table[352],  }, /* len ai => le nai */
    { &pinyin_table[289],  &pinyin_table[4],    &pinyin_table[285],  &pinyin_table[354],  }, /* len an => le nan */
    { &pinyin_table[289],  &pinyin_table[5],    &pinyin_table[285],  &pinyin_table[355],  }, /* len ang => le nang */
    { &pinyin_table[289],  &pinyin_table[6],    &pinyin_table[285],  &pinyin_table[356],  }, /* len ao => le nao */
    { &pinyin_table[289],  &pinyin_table[125],  &pinyin_table[285],  &pinyin_table[357],  }, /* len e => le ne */
    { &pinyin_table[289],  &pinyin_table[126],  &pinyin_table[285],  &pinyin_table[359],  }, /* len ei => le nei */
    { &pinyin_table[289],  &pinyin_table[127],  &pinyin_table[285],  &pinyin_table[361],  }, /* len en => le nen */
    { &pinyin_table[289],  &pinyin_table[392],  &pinyin_table[285],  &pinyin_table[381],  }, /* len ou => le nou */
    { &pinyin_table[295],  &pinyin_table[126],  &pinyin_table[292],  &pinyin_table[359],  }, /* lian ei => lia nei */
    { &pinyin_table[296],  &pinyin_table[5],    &pinyin_table[295],  &pinyin_table[162],  }, /* liang ang => lian gang */
    { &pinyin_table[296],  &pinyin_table[6],    &pinyin_table[295],  &pinyin_table[163],  }, /* liang ao => lian gao */
    { &pinyin_table[296],  &pinyin_table[125],  &pinyin_table[295],  &pinyin_table[164],  }, /* liang e => lian ge */
    { &pinyin_table[296],  &pinyin_table[126],  &pinyin_table[295],  &pinyin_table[166],  }, /* liang ei => lian gei */
    { &pinyin_table[296],  &pinyin_table[127],  &pinyin_table[295],  &pinyin_table[168],  }, /* liang en => lian gen */
    { &pinyin_table[296],  &pinyin_table[392],  &pinyin_table[295],  &pinyin_table[173],  }, /* liang ou => lian gou */
    { &pinyin_table[298],  &pinyin_table[448],  &pinyin_table[291],  &pinyin_table[128],  }, /* lie r => li er */
    { &pinyin_table[301],  &pinyin_table[0],    &pinyin_table[291],  &pinyin_table[350],  }, /* lin a => li na */
    { &pinyin_table[301],  &pinyin_table[4],    &pinyin_table[291],  &pinyin_table[354],  }, /* lin an => li nan */
    { &pinyin_table[301],  &pinyin_table[5],    &pinyin_table[291],  &pinyin_table[355],  }, /* lin ang => li nang */
    { &pinyin_table[301],  &pinyin_table[6],    &pinyin_table[291],  &pinyin_table[356],  }, /* lin ao => li nao */
    { &pinyin_table[301],  &pinyin_table[125],  &pinyin_table[291],  &pinyin_table[357],  }, /* lin e => li ne */
    { &pinyin_table[301],  &pinyin_table[126],  &pinyin_table[291],  &pinyin_table[359],  }, /* lin ei => li nei */
    { &pinyin_table[302],  &pinyin_table[5],    &pinyin_table[301],  &pinyin_table[162],  }, /* ling ang => lin gang */
    { &pinyin_table[302],  &pinyin_table[6],    &pinyin_table[301],  &pinyin_table[163],  }, /* ling ao => lin gao */
    { &pinyin_table[302],  &pinyin_table[125],  &pinyin_table[301],  &pinyin_table[164],  }, /* ling e => lin ge */
    { &pinyin_table[302],  &pinyin_table[126],  &pinyin_table[301],  &pinyin_table[166],  }, /* ling ei => lin gei */
    { &pinyin_table[302],  &pinyin_table[127],  &pinyin_table[301],  &pinyin_table[168],  }, /* ling en => lin gen */
    { &pinyin_table[302],  &pinyin_table[392],  &pinyin_table[301],  &pinyin_table[173],  }, /* ling ou => lin gou */
    { &pinyin_table[312],  &pinyin_table[0],    &pinyin_table[311],  &pinyin_table[157],  }, /* luang a => luan ga */
    { &pinyin_table[312],  &pinyin_table[2],    &pinyin_table[311],  &pinyin_table[159],  }, /* luang ai => luan gai */
    { &pinyin_table[312],  &pinyin_table[4],    &pinyin_table[311],  &pinyin_table[161],  }, /* luang an => luan gan */
    { &pinyin_table[312],  &pinyin_table[5],    &pinyin_table[311],  &pinyin_table[162],  }, /* luang ang => luan gang */
    { &pinyin_table[312],  &pinyin_table[6],    &pinyin_table[311],  &pinyin_table[163],  }, /* luang ao => luan gao */
    { &pinyin_table[312],  &pinyin_table[125],  &pinyin_table[311],  &pinyin_table[164],  }, /* luang e => luan ge */
    { &pinyin_table[312],  &pinyin_table[126],  &pinyin_table[311],  &pinyin_table[166],  }, /* luang ei => luan gei */
    { &pinyin_table[312],  &pinyin_table[127],  &pinyin_table[311],  &pinyin_table[168],  }, /* luang en => luan gen */
    { &pinyin_table[312],  &pinyin_table[392],  &pinyin_table[311],  &pinyin_table[173],  }, /* luang ou => luan gou */
    { &pinyin_table[313],  &pinyin_table[448],  &pinyin_table[310],  &pinyin_table[128],  }, /* lue r => lu er */
    { &pinyin_table[317],  &pinyin_table[0],    &pinyin_table[310],  &pinyin_table[350],  }, /* lun a => lu na */
    { &pinyin_table[317],  &pinyin_table[2],    &pinyin_table[310],  &pinyin_table[352],  }, /* lun ai => lu nai */
    { &pinyin_table[317],  &pinyin_table[4],    &pinyin_table[310],  &pinyin_table[354],  }, /* lun an => lu nan */
    { &pinyin_table[317],  &pinyin_table[5],    &pinyin_table[310],  &pinyin_table[355],  }, /* lun ang => lu nang */
    { &pinyin_table[317],  &pinyin_table[6],    &pinyin_table[310],  &pinyin_table[356],  }, /* lun ao => lu nao */
    { &pinyin_table[317],  &pinyin_table[125],  &pinyin_table[310],  &pinyin_table[357],  }, /* lun e => lu ne */
    { &pinyin_table[317],  &pinyin_table[126],  &pinyin_table[310],  &pinyin_table[359],  }, /* lun ei => lu nei */
    { &pinyin_table[320],  &pinyin_table[448],  &pinyin_table[319],  &pinyin_table[128],  }, /* lve r => lv er */
    { &pinyin_table[326],  &pinyin_table[2],    &pinyin_table[322],  &pinyin_table[352],  }, /* man ai => ma nai */
    { &pinyin_table[326],  &pinyin_table[4],    &pinyin_table[322],  &pinyin_table[354],  }, /* man an => ma nan */
    { &pinyin_table[326],  &pinyin_table[5],    &pinyin_table[322],  &pinyin_table[355],  }, /* man ang => ma nang */
    { &pinyin_table[326],  &pinyin_table[6],    &pinyin_table[322],  &pinyin_table[356],  }, /* man ao => ma nao */
    { &pinyin_table[326],  &pinyin_table[125],  &pinyin_table[322],  &pinyin_table[357],  }, /* man e => ma ne */
    { &pinyin_table[326],  &pinyin_table[126],  &pinyin_table[322],  &pinyin_table[359],  }, /* man ei => ma nei */
    { &pinyin_table[327],  &pinyin_table[2],    &pinyin_table[326],  &pinyin_table[159],  }, /* mang ai => man gai */
    { &pinyin_table[327],  &pinyin_table[4],    &pinyin_table[326],  &pinyin_table[161],  }, /* mang an => man gan */
    { &pinyin_table[327],  &pinyin_table[5],    &pinyin_table[326],  &pinyin_table[162],  }, /* mang ang => man gang */
    { &pinyin_table[327],  &pinyin_table[6],    &pinyin_table[326],  &pinyin_table[163],  }, /* mang ao => man gao */
    { &pinyin_table[327],  &pinyin_table[125],  &pinyin_table[326],  &pinyin_table[164],  }, /* mang e => man ge */
    { &pinyin_table[327],  &pinyin_table[126],  &pinyin_table[326],  &pinyin_table[166],  }, /* mang ei => man gei */
    { &pinyin_table[327],  &pinyin_table[127],  &pinyin_table[326],  &pinyin_table[168],  }, /* mang en => man gen */
    { &pinyin_table[327],  &pinyin_table[392],  &pinyin_table[326],  &pinyin_table[173],  }, /* mang ou => man gou */
    { &pinyin_table[333],  &pinyin_table[5],    &pinyin_table[329],  &pinyin_table[355],  }, /* men ang => me nang */
    { &pinyin_table[333],  &pinyin_table[6],    &pinyin_table[329],  &pinyin_table[356],  }, /* men ao => me nao */
    { &pinyin_table[333],  &pinyin_table[125],  &pinyin_table[329],  &pinyin_table[357],  }, /* men e => me ne */
    { &pinyin_table[333],  &pinyin_table[126],  &pinyin_table[329],  &pinyin_table[359],  }, /* men ei => me nei */
    { &pinyin_table[334],  &pinyin_table[2],    &pinyin_table[333],  &pinyin_table[159],  }, /* meng ai => men gai */
    { &pinyin_table[334],  &pinyin_table[5],    &pinyin_table[333],  &pinyin_table[162],  }, /* meng ang => men gang */
    { &pinyin_table[334],  &pinyin_table[6],    &pinyin_table[333],  &pinyin_table[163],  }, /* meng ao => men gao */
    { &pinyin_table[334],  &pinyin_table[125],  &pinyin_table[333],  &pinyin_table[164],  }, /* meng e => men ge */
    { &pinyin_table[334],  &pinyin_table[126],  &pinyin_table[333],  &pinyin_table[166],  }, /* meng ei => men gei */
    { &pinyin_table[334],  &pinyin_table[392],  &pinyin_table[333],  &pinyin_table[173],  }, /* meng ou => men gou */
    { &pinyin_table[337],  &pinyin_table[0],    &pinyin_table[336],  &pinyin_table[157],  }, /* miang a => mian ga */
    { &pinyin_table[337],  &pinyin_table[2],    &pinyin_table[336],  &pinyin_table[159],  }, /* miang ai => mian gai */
    { &pinyin_table[337],  &pinyin_table[4],    &pinyin_table[336],  &pinyin_table[161],  }, /* miang an => mian gan */
    { &pinyin_table[337],  &pinyin_table[5],    &pinyin_table[336],  &pinyin_table[162],  }, /* miang ang => mian gang */
    { &pinyin_table[337],  &pinyin_table[6],    &pinyin_table[336],  &pinyin_table[163],  }, /* miang ao => mian gao */
    { &pinyin_table[337],  &pinyin_table[125],  &pinyin_table[336],  &pinyin_table[164],  }, /* miang e => mian ge */
    { &pinyin_table[337],  &pinyin_table[126],  &pinyin_table[336],  &pinyin_table[166],  }, /* miang ei => mian gei */
    { &pinyin_table[337],  &pinyin_table[127],  &pinyin_table[336],  &pinyin_table[168],  }, /* miang en => mian gen */
    { &pinyin_table[337],  &pinyin_table[392],  &pinyin_table[336],  &pinyin_table[173],  }, /* miang ou => mian gou */
    { &pinyin_table[339],  &pinyin_table[448],  &pinyin_table[335],  &pinyin_table[128],  }, /* mie r => mi er */
    { &pinyin_table[342],  &pinyin_table[0],    &pinyin_table[335],  &pinyin_table[350],  }, /* min a => mi na */
    { &pinyin_table[342],  &pinyin_table[125],  &pinyin_table[335],  &pinyin_table[357],  }, /* min e => mi ne */
    { &pinyin_table[342],  &pinyin_table[126],  &pinyin_table[335],  &pinyin_table[359],  }, /* min ei => mi nei */
    { &pinyin_table[343],  &pinyin_table[4],    &pinyin_table[342],  &pinyin_table[161],  }, /* ming an => min gan */
    { &pinyin_table[343],  &pinyin_table[5],    &pinyin_table[342],  &pinyin_table[162],  }, /* ming ang => min gang */
    { &pinyin_table[343],  &pinyin_table[6],    &pinyin_table[342],  &pinyin_table[163],  }, /* ming ao => min gao */
    { &pinyin_table[343],  &pinyin_table[125],  &pinyin_table[342],  &pinyin_table[164],  }, /* ming e => min ge */
    { &pinyin_table[343],  &pinyin_table[126],  &pinyin_table[342],  &pinyin_table[166],  }, /* ming ei => min gei */
    { &pinyin_table[343],  &pinyin_table[392],  &pinyin_table[342],  &pinyin_table[173],  }, /* ming ou => min gou */
    { &pinyin_table[354],  &pinyin_table[0],    &pinyin_table[350],  &pinyin_table[350],  }, /* nan a => na na */
    { &pinyin_table[354],  &pinyin_table[5],    &pinyin_table[350],  &pinyin_table[355],  }, /* nan ang => na nang */
    { &pinyin_table[354],  &pinyin_table[125],  &pinyin_table[350],  &pinyin_table[357],  }, /* nan e => na ne */
    { &pinyin_table[354],  &pinyin_table[126],  &pinyin_table[350],  &pinyin_table[359],  }, /* nan ei => na nei */
    { &pinyin_table[355],  &pinyin_table[0],    &pinyin_table[354],  &pinyin_table[157],  }, /* nang a => nan ga */
    { &pinyin_table[355],  &pinyin_table[2],    &pinyin_table[354],  &pinyin_table[159],  }, /* nang ai => nan gai */
    { &pinyin_table[355],  &pinyin_table[4],    &pinyin_table[354],  &pinyin_table[161],  }, /* nang an => nan gan */
    { &pinyin_table[355],  &pinyin_table[5],    &pinyin_table[354],  &pinyin_table[162],  }, /* nang ang => nan gang */
    { &pinyin_table[355],  &pinyin_table[6],    &pinyin_table[354],  &pinyin_table[163],  }, /* nang ao => nan gao */
    { &pinyin_table[355],  &pinyin_table[125],  &pinyin_table[354],  &pinyin_table[164],  }, /* nang e => nan ge */
    { &pinyin_table[355],  &pinyin_table[126],  &pinyin_table[354],  &pinyin_table[166],  }, /* nang ei => nan gei */
    { &pinyin_table[355],  &pinyin_table[127],  &pinyin_table[354],  &pinyin_table[168],  }, /* nang en => nan gen */
    { &pinyin_table[355],  &pinyin_table[392],  &pinyin_table[354],  &pinyin_table[173],  }, /* nang ou => nan gou */
    { &pinyin_table[361],  &pinyin_table[0],    &pinyin_table[357],  &pinyin_table[350],  }, /* nen a => ne na */
    { &pinyin_table[361],  &pinyin_table[2],    &pinyin_table[357],  &pinyin_table[352],  }, /* nen ai => ne nai */
    { &pinyin_table[361],  &pinyin_table[4],    &pinyin_table[357],  &pinyin_table[354],  }, /* nen an => ne nan */
    { &pinyin_table[361],  &pinyin_table[5],    &pinyin_table[357],  &pinyin_table[355],  }, /* nen ang => ne nang */
    { &pinyin_table[361],  &pinyin_table[6],    &pinyin_table[357],  &pinyin_table[356],  }, /* nen ao => ne nao */
    { &pinyin_table[361],  &pinyin_table[125],  &pinyin_table[357],  &pinyin_table[357],  }, /* nen e => ne ne */
    { &pinyin_table[361],  &pinyin_table[126],  &pinyin_table[357],  &pinyin_table[359],  }, /* nen ei => ne nei */
    { &pinyin_table[361],  &pinyin_table[127],  &pinyin_table[357],  &pinyin_table[361],  }, /* nen en => ne nen */
    { &pinyin_table[362],  &pinyin_table[125],  &pinyin_table[361],  &pinyin_table[164],  }, /* neng e => nen ge */
    { &pinyin_table[362],  &pinyin_table[126],  &pinyin_table[361],  &pinyin_table[166],  }, /* neng ei => nen gei */
    { &pinyin_table[368],  &pinyin_table[2],    &pinyin_table[367],  &pinyin_table[159],  }, /* niang ai => nian gai */
    { &pinyin_table[368],  &pinyin_table[4],    &pinyin_table[367],  &pinyin_table[161],  }, /* niang an => nian gan */
    { &pinyin_table[368],  &pinyin_table[5],    &pinyin_table[367],  &pinyin_table[162],  }, /* niang ang => nian gang */
    { &pinyin_table[368],  &pinyin_table[6],    &pinyin_table[367],  &pinyin_table[163],  }, /* niang ao => nian gao */
    { &pinyin_table[368],  &pinyin_table[125],  &pinyin_table[367],  &pinyin_table[164],  }, /* niang e => nian ge */
    { &pinyin_table[368],  &pinyin_table[126],  &pinyin_table[367],  &pinyin_table[166],  }, /* niang ei => nian gei */
    { &pinyin_table[368],  &pinyin_table[127],  &pinyin_table[367],  &pinyin_table[168],  }, /* niang en => nian gen */
    { &pinyin_table[368],  &pinyin_table[392],  &pinyin_table[367],  &pinyin_table[173],  }, /* niang ou => nian gou */
    { &pinyin_table[370],  &pinyin_table[448],  &pinyin_table[363],  &pinyin_table[128],  }, /* nie r => ni er */
    { &pinyin_table[373],  &pinyin_table[0],    &pinyin_table[363],  &pinyin_table[350],  }, /* nin a => ni na */
    { &pinyin_table[373],  &pinyin_table[4],    &pinyin_table[363],  &pinyin_table[354],  }, /* nin an => ni nan */
    { &pinyin_table[373],  &pinyin_table[5],    &pinyin_table[363],  &pinyin_table[355],  }, /* nin ang => ni nang */
    { &pinyin_table[373],  &pinyin_table[6],    &pinyin_table[363],  &pinyin_table[356],  }, /* nin ao => ni nao */
    { &pinyin_table[373],  &pinyin_table[125],  &pinyin_table[363],  &pinyin_table[357],  }, /* nin e => ni ne */
    { &pinyin_table[373],  &pinyin_table[126],  &pinyin_table[363],  &pinyin_table[359],  }, /* nin ei => ni nei */
    { &pinyin_table[374],  &pinyin_table[2],    &pinyin_table[373],  &pinyin_table[159],  }, /* ning ai => nin gai */
    { &pinyin_table[374],  &pinyin_table[5],    &pinyin_table[373],  &pinyin_table[162],  }, /* ning ang => nin gang */
    { &pinyin_table[374],  &pinyin_table[6],    &pinyin_table[373],  &pinyin_table[163],  }, /* ning ao => nin gao */
    { &pinyin_table[374],  &pinyin_table[126],  &pinyin_table[373],  &pinyin_table[166],  }, /* ning ei => nin gei */
    { &pinyin_table[374],  &pinyin_table[127],  &pinyin_table[373],  &pinyin_table[168],  }, /* ning en => nin gen */
    { &pinyin_table[374],  &pinyin_table[392],  &pinyin_table[373],  &pinyin_table[173],  }, /* ning ou => nin gou */
    { &pinyin_table[384],  &pinyin_table[0],    &pinyin_table[383],  &pinyin_table[157],  }, /* nuang a => nuan ga */
    { &pinyin_table[384],  &pinyin_table[2],    &pinyin_table[383],  &pinyin_table[159],  }, /* nuang ai => nuan gai */
    { &pinyin_table[384],  &pinyin_table[4],    &pinyin_table[383],  &pinyin_table[161],  }, /* nuang an => nuan gan */
    { &pinyin_table[384],  &pinyin_table[5],    &pinyin_table[383],  &pinyin_table[162],  }, /* nuang ang => nuan gang */
    { &pinyin_table[384],  &pinyin_table[6],    &pinyin_table[383],  &pinyin_table[163],  }, /* nuang ao => nuan gao */
    { &pinyin_table[384],  &pinyin_table[125],  &pinyin_table[383],  &pinyin_table[164],  }, /* nuang e => nuan ge */
    { &pinyin_table[384],  &pinyin_table[126],  &pinyin_table[383],  &pinyin_table[166],  }, /* nuang ei => nuan gei */
    { &pinyin_table[384],  &pinyin_table[127],  &pinyin_table[383],  &pinyin_table[168],  }, /* nuang en => nuan gen */
    { &pinyin_table[384],  &pinyin_table[392],  &pinyin_table[383],  &pinyin_table[173],  }, /* nuang ou => nuan gou */
    { &pinyin_table[385],  &pinyin_table[448],  &pinyin_table[382],  &pinyin_table[128],  }, /* nue r => nu er */
    { &pinyin_table[387],  &pinyin_table[0],    &pinyin_table[382],  &pinyin_table[350],  }, /* nun a => nu na */
    { &pinyin_table[387],  &pinyin_table[2],    &pinyin_table[382],  &pinyin_table[352],  }, /* nun ai => nu nai */
    { &pinyin_table[387],  &pinyin_table[4],    &pinyin_table[382],  &pinyin_table[354],  }, /* nun an => nu nan */
    { &pinyin_table[387],  &pinyin_table[5],    &pinyin_table[382],  &pinyin_table[355],  }, /* nun ang => nu nang */
    { &pinyin_table[387],  &pinyin_table[6],    &pinyin_table[382],  &pinyin_table[356],  }, /* nun ao => nu nao */
    { &pinyin_table[387],  &pinyin_table[125],  &pinyin_table[382],  &pinyin_table[357],  }, /* nun e => nu ne */
    { &pinyin_table[387],  &pinyin_table[126],  &pinyin_table[382],  &pinyin_table[359],  }, /* nun ei => nu nei */
    { &pinyin_table[387],  &pinyin_table[127],  &pinyin_table[382],  &pinyin_table[361],  }, /* nun en => nu nen */
    { &pinyin_table[387],  &pinyin_table[392],  &pinyin_table[382],  &pinyin_table[381],  }, /* nun ou => nu nou */
    { &pinyin_table[390],  &pinyin_table[448],  &pinyin_table[389],  &pinyin_table[128],  }, /* nve r => nv er */
    { &pinyin_table[398],  &pinyin_table[0],    &pinyin_table[394],  &pinyin_table[350],  }, /* pan a => pa na */
    { &pinyin_table[398],  &pinyin_table[5],    &pinyin_table[394],  &pinyin_table[355],  }, /* pan ang => pa nang */
    { &pinyin_table[398],  &pinyin_table[6],    &pinyin_table[394],  &pinyin_table[356],  }, /* pan ao => pa nao */
    { &pinyin_table[398],  &pinyin_table[125],  &pinyin_table[394],  &pinyin_table[357],  }, /* pan e => pa ne */
    { &pinyin_table[398],  &pinyin_table[126],  &pinyin_table[394],  &pinyin_table[359],  }, /* pan ei => pa nei */
    { &pinyin_table[399],  &pinyin_table[5],    &pinyin_table[398],  &pinyin_table[162],  }, /* pang ang => pan gang */
    { &pinyin_table[399],  &pinyin_table[6],    &pinyin_table[398],  &pinyin_table[163],  }, /* pang ao => pan gao */
    { &pinyin_table[399],  &pinyin_table[125],  &pinyin_table[398],  &pinyin_table[164],  }, /* pang e => pan ge */
    { &pinyin_table[399],  &pinyin_table[126],  &pinyin_table[398],  &pinyin_table[166],  }, /* pang ei => pan gei */
    { &pinyin_table[399],  &pinyin_table[127],  &pinyin_table[398],  &pinyin_table[168],  }, /* pang en => pan gen */
    { &pinyin_table[399],  &pinyin_table[392],  &pinyin_table[398],  &pinyin_table[173],  }, /* pang ou => pan gou */
    { &pinyin_table[405],  &pinyin_table[5],    &pinyin_table[404],  &pinyin_table[162],  }, /* peng ang => pen gang */
    { &pinyin_table[405],  &pinyin_table[6],    &pinyin_table[404],  &pinyin_table[163],  }, /* peng ao => pen gao */
    { &pinyin_table[405],  &pinyin_table[125],  &pinyin_table[404],  &pinyin_table[164],  }, /* peng e => pen ge */
    { &pinyin_table[405],  &pinyin_table[126],  &pinyin_table[404],  &pinyin_table[166],  }, /* peng ei => pen gei */
    { &pinyin_table[408],  &pinyin_table[0],    &pinyin_table[407],  &pinyin_table[157],  }, /* piang a => pian ga */
    { &pinyin_table[408],  &pinyin_table[2],    &pinyin_table[407],  &pinyin_table[159],  }, /* piang ai => pian gai */
    { &pinyin_table[408],  &pinyin_table[4],    &pinyin_table[407],  &pinyin_table[161],  }, /* piang an => pian gan */
    { &pinyin_table[408],  &pinyin_table[5],    &pinyin_table[407],  &pinyin_table[162],  }, /* piang ang => pian gang */
    { &pinyin_table[408],  &pinyin_table[6],    &pinyin_table[407],  &pinyin_table[163],  }, /* piang ao => pian gao */
    { &pinyin_table[408],  &pinyin_table[125],  &pinyin_table[407],  &pinyin_table[164],  }, /* piang e => pian ge */
    { &pinyin_table[408],  &pinyin_table[126],  &pinyin_table[407],  &pinyin_table[166],  }, /* piang ei => pian gei */
    { &pinyin_table[408],  &pinyin_table[127],  &pinyin_table[407],  &pinyin_table[168],  }, /* piang en => pian gen */
    { &pinyin_table[408],  &pinyin_table[392],  &pinyin_table[407],  &pinyin_table[173],  }, /* piang ou => pian gou */
    { &pinyin_table[410],  &pinyin_table[448],  &pinyin_table[406],  &pinyin_table[128],  }, /* pie r => pi er */
    { &pinyin_table[413],  &pinyin_table[0],    &pinyin_table[406],  &pinyin_table[350],  }, /* pin a => pi na */
    { &pinyin_table[413],  &pinyin_table[5],    &pinyin_table[406],  &pinyin_table[355],  }, /* pin ang => pi nang */
    { &pinyin_table[413],  &pinyin_table[6],    &pinyin_table[406],  &pinyin_table[356],  }, /* pin ao => pi nao */
    { &pinyin_table[413],  &pinyin_table[125],  &pinyin_table[406],  &pinyin_table[357],  }, /* pin e => pi ne */
    { &pinyin_table[413],  &pinyin_table[126],  &pinyin_table[406],  &pinyin_table[359],  }, /* pin ei => pi nei */
    { &pinyin_table[414],  &pinyin_table[5],    &pinyin_table[413],  &pinyin_table[162],  }, /* ping ang => pin gang */
    { &pinyin_table[414],  &pinyin_table[6],    &pinyin_table[413],  &pinyin_table[163],  }, /* ping ao => pin gao */
    { &pinyin_table[414],  &pinyin_table[125],  &pinyin_table[413],  &pinyin_table[164],  }, /* ping e => pin ge */
    { &pinyin_table[414],  &pinyin_table[126],  &pinyin_table[413],  &pinyin_table[166],  }, /* ping ei => pin gei */
    { &pinyin_table[414],  &pinyin_table[127],  &pinyin_table[413],  &pinyin_table[168],  }, /* ping en => pin gen */
    { &pinyin_table[414],  &pinyin_table[392],  &pinyin_table[413],  &pinyin_table[173],  }, /* ping ou => pin gou */
    { &pinyin_table[423],  &pinyin_table[126],  &pinyin_table[420],  &pinyin_table[359],  }, /* qian ei => qia nei */
    { &pinyin_table[424],  &pinyin_table[2],    &pinyin_table[423],  &pinyin_table[159],  }, /* qiang ai => qian gai */
    { &pinyin_table[424],  &pinyin_table[4],    &pinyin_table[423],  &pinyin_table[161],  }, /* qiang an => qian gan */
    { &pinyin_table[424],  &pinyin_table[5],    &pinyin_table[423],  &pinyin_table[162],  }, /* qiang ang => qian gang */
    { &pinyin_table[424],  &pinyin_table[6],    &pinyin_table[423],  &pinyin_table[163],  }, /* qiang ao => qian gao */
    { &pinyin_table[424],  &pinyin_table[125],  &pinyin_table[423],  &pinyin_table[164],  }, /* qiang e => qian ge */
    { &pinyin_table[424],  &pinyin_table[126],  &pinyin_table[423],  &pinyin_table[166],  }, /* qiang ei => qian gei */
    { &pinyin_table[424],  &pinyin_table[127],  &pinyin_table[423],  &pinyin_table[168],  }, /* qiang en => qian gen */
    { &pinyin_table[424],  &pinyin_table[392],  &pinyin_table[423],  &pinyin_table[173],  }, /* qiang ou => qian gou */
    { &pinyin_table[426],  &pinyin_table[448],  &pinyin_table[419],  &pinyin_table[128],  }, /* qie r => qi er */
    { &pinyin_table[429],  &pinyin_table[0],    &pinyin_table[419],  &pinyin_table[350],  }, /* qin a => qi na */
    { &pinyin_table[429],  &pinyin_table[5],    &pinyin_table[419],  &pinyin_table[355],  }, /* qin ang => qi nang */
    { &pinyin_table[429],  &pinyin_table[6],    &pinyin_table[419],  &pinyin_table[356],  }, /* qin ao => qi nao */
    { &pinyin_table[429],  &pinyin_table[125],  &pinyin_table[419],  &pinyin_table[357],  }, /* qin e => qi ne */
    { &pinyin_table[429],  &pinyin_table[126],  &pinyin_table[419],  &pinyin_table[359],  }, /* qin ei => qi nei */
    { &pinyin_table[430],  &pinyin_table[5],    &pinyin_table[429],  &pinyin_table[162],  }, /* qing ang => qin gang */
    { &pinyin_table[430],  &pinyin_table[6],    &pinyin_table[429],  &pinyin_table[163],  }, /* qing ao => qin gao */
    { &pinyin_table[430],  &pinyin_table[125],  &pinyin_table[429],  &pinyin_table[164],  }, /* qing e => qin ge */
    { &pinyin_table[430],  &pinyin_table[126],  &pinyin_table[429],  &pinyin_table[166],  }, /* qing ei => qin gei */
    { &pinyin_table[430],  &pinyin_table[127],  &pinyin_table[429],  &pinyin_table[168],  }, /* qing en => qin gen */
    { &pinyin_table[430],  &pinyin_table[392],  &pinyin_table[429],  &pinyin_table[173],  }, /* qing ou => qin gou */
    { &pinyin_table[438],  &pinyin_table[0],    &pinyin_table[437],  &pinyin_table[157],  }, /* quang a => quan ga */
    { &pinyin_table[438],  &pinyin_table[2],    &pinyin_table[437],  &pinyin_table[159],  }, /* quang ai => quan gai */
    { &pinyin_table[438],  &pinyin_table[4],    &pinyin_table[437],  &pinyin_table[161],  }, /* quang an => quan gan */
    { &pinyin_table[438],  &pinyin_table[5],    &pinyin_table[437],  &pinyin_table[162],  }, /* quang ang => quan gang */
    { &pinyin_table[438],  &pinyin_table[6],    &pinyin_table[437],  &pinyin_table[163],  }, /* quang ao => quan gao */
    { &pinyin_table[438],  &pinyin_table[125],  &pinyin_table[437],  &pinyin_table[164],  }, /* quang e => quan ge */
    { &pinyin_table[438],  &pinyin_table[126],  &pinyin_table[437],  &pinyin_table[166],  }, /* quang ei => quan gei */
    { &pinyin_table[438],  &pinyin_table[127],  &pinyin_table[437],  &pinyin_table[168],  }, /* quang en => quan gen */
    { &pinyin_table[438],  &pinyin_table[392],  &pinyin_table[437],  &pinyin_table[173],  }, /* quang ou => quan gou */
    { &pinyin_table[439],  &pinyin_table[448],  &pinyin_table[436],  &pinyin_table[128],  }, /* que r => qu er */
    { &pinyin_table[440],  &pinyin_table[0],    &pinyin_table[439],  &pinyin_table[350],  }, /* quen a => que na */
    { &pinyin_table[440],  &pinyin_table[2],    &pinyin_table[439],  &pinyin_table[352],  }, /* quen ai => que nai */
    { &pinyin_table[440],  &pinyin_table[4],    &pinyin_table[439],  &pinyin_table[354],  }, /* quen an => que nan */
    { &pinyin_table[440],  &pinyin_table[5],    &pinyin_table[439],  &pinyin_table[355],  }, /* quen ang => que nang */
    { &pinyin_table[440],  &pinyin_table[6],    &pinyin_table[439],  &pinyin_table[356],  }, /* quen ao => que nao */
    { &pinyin_table[440],  &pinyin_table[125],  &pinyin_table[439],  &pinyin_table[357],  }, /* quen e => que ne */
    { &pinyin_table[440],  &pinyin_table[126],  &pinyin_table[439],  &pinyin_table[359],  }, /* quen ei => que nei */
    { &pinyin_table[440],  &pinyin_table[127],  &pinyin_table[439],  &pinyin_table[361],  }, /* quen en => que nen */
    { &pinyin_table[440],  &pinyin_table[392],  &pinyin_table[439],  &pinyin_table[381],  }, /* quen ou => que nou */
    { &pinyin_table[441],  &pinyin_table[0],    &pinyin_table[436],  &pinyin_table[350],  }, /* qun a => qu na */
    { &pinyin_table[441],  &pinyin_table[4],    &pinyin_table[436],  &pinyin_table[354],  }, /* qun an => qu nan */
    { &pinyin_table[441],  &pinyin_table[5],    &pinyin_table[436],  &pinyin_table[355],  }, /* qun ang => qu nang */
    { &pinyin_table[441],  &pinyin_table[6],    &pinyin_table[436],  &pinyin_table[356],  }, /* qun ao => qu nao */
    { &pinyin_table[441],  &pinyin_table[125],  &pinyin_table[436],  &pinyin_table[357],  }, /* qun e => qu ne */
    { &pinyin_table[441],  &pinyin_table[126],  &pinyin_table[436],  &pinyin_table[359],  }, /* qun ei => qu nei */
    { &pinyin_table[454],  &pinyin_table[5],    &pinyin_table[453],  &pinyin_table[162],  }, /* rang ang => ran gang */
    { &pinyin_table[454],  &pinyin_table[6],    &pinyin_table[453],  &pinyin_table[163],  }, /* rang ao => ran gao */
    { &pinyin_table[454],  &pinyin_table[126],  &pinyin_table[453],  &pinyin_table[166],  }, /* rang ei => ran gei */
    { &pinyin_table[454],  &pinyin_table[127],  &pinyin_table[453],  &pinyin_table[168],  }, /* rang en => ran gen */
    { &pinyin_table[460],  &pinyin_table[6],    &pinyin_table[456],  &pinyin_table[356],  }, /* ren ao => re nao */
    { &pinyin_table[460],  &pinyin_table[125],  &pinyin_table[456],  &pinyin_table[357],  }, /* ren e => re ne */
    { &pinyin_table[460],  &pinyin_table[126],  &pinyin_table[456],  &pinyin_table[359],  }, /* ren ei => re nei */
    { &pinyin_table[461],  &pinyin_table[0],    &pinyin_table[460],  &pinyin_table[157],  }, /* reng a => ren ga */
    { &pinyin_table[461],  &pinyin_table[2],    &pinyin_table[460],  &pinyin_table[159],  }, /* reng ai => ren gai */
    { &pinyin_table[461],  &pinyin_table[4],    &pinyin_table[460],  &pinyin_table[161],  }, /* reng an => ren gan */
    { &pinyin_table[461],  &pinyin_table[5],    &pinyin_table[460],  &pinyin_table[162],  }, /* reng ang => ren gang */
    { &pinyin_table[461],  &pinyin_table[6],    &pinyin_table[460],  &pinyin_table[163],  }, /* reng ao => ren gao */
    { &pinyin_table[461],  &pinyin_table[125],  &pinyin_table[460],  &pinyin_table[164],  }, /* reng e => ren ge */
    { &pinyin_table[461],  &pinyin_table[126],  &pinyin_table[460],  &pinyin_table[166],  }, /* reng ei => ren gei */
    { &pinyin_table[461],  &pinyin_table[127],  &pinyin_table[460],  &pinyin_table[168],  }, /* reng en => ren gen */
    { &pinyin_table[461],  &pinyin_table[392],  &pinyin_table[460],  &pinyin_table[173],  }, /* reng ou => ren gou */
    { &pinyin_table[467],  &pinyin_table[448],  &pinyin_table[462],  &pinyin_table[128],  }, /* rie r => ri er */
    { &pinyin_table[468],  &pinyin_table[0],    &pinyin_table[462],  &pinyin_table[350],  }, /* rin a => ri na */
    { &pinyin_table[468],  &pinyin_table[2],    &pinyin_table[462],  &pinyin_table[352],  }, /* rin ai => ri nai */
    { &pinyin_table[468],  &pinyin_table[4],    &pinyin_table[462],  &pinyin_table[354],  }, /* rin an => ri nan */
    { &pinyin_table[468],  &pinyin_table[5],    &pinyin_table[462],  &pinyin_table[355],  }, /* rin ang => ri nang */
    { &pinyin_table[468],  &pinyin_table[6],    &pinyin_table[462],  &pinyin_table[356],  }, /* rin ao => ri nao */
    { &pinyin_table[468],  &pinyin_table[125],  &pinyin_table[462],  &pinyin_table[357],  }, /* rin e => ri ne */
    { &pinyin_table[468],  &pinyin_table[126],  &pinyin_table[462],  &pinyin_table[359],  }, /* rin ei => ri nei */
    { &pinyin_table[468],  &pinyin_table[127],  &pinyin_table[462],  &pinyin_table[361],  }, /* rin en => ri nen */
    { &pinyin_table[468],  &pinyin_table[392],  &pinyin_table[462],  &pinyin_table[381],  }, /* rin ou => ri nou */
    { &pinyin_table[479],  &pinyin_table[0],    &pinyin_table[478],  &pinyin_table[157],  }, /* ruang a => ruan ga */
    { &pinyin_table[479],  &pinyin_table[2],    &pinyin_table[478],  &pinyin_table[159],  }, /* ruang ai => ruan gai */
    { &pinyin_table[479],  &pinyin_table[4],    &pinyin_table[478],  &pinyin_table[161],  }, /* ruang an => ruan gan */
    { &pinyin_table[479],  &pinyin_table[5],    &pinyin_table[478],  &pinyin_table[162],  }, /* ruang ang => ruan gang */
    { &pinyin_table[479],  &pinyin_table[6],    &pinyin_table[478],  &pinyin_table[163],  }, /* ruang ao => ruan gao */
    { &pinyin_table[479],  &pinyin_table[125],  &pinyin_table[478],  &pinyin_table[164],  }, /* ruang e => ruan ge */
    { &pinyin_table[479],  &pinyin_table[126],  &pinyin_table[478],  &pinyin_table[166],  }, /* ruang ei => ruan gei */
    { &pinyin_table[479],  &pinyin_table[127],  &pinyin_table[478],  &pinyin_table[168],  }, /* ruang en => ruan gen */
    { &pinyin_table[479],  &pinyin_table[392],  &pinyin_table[478],  &pinyin_table[173],  }, /* ruang ou => ruan gou */
    { &pinyin_table[480],  &pinyin_table[448],  &pinyin_table[477],  &pinyin_table[128],  }, /* rue r => ru er */
    { &pinyin_table[484],  &pinyin_table[0],    &pinyin_table[477],  &pinyin_table[350],  }, /* run a => ru na */
    { &pinyin_table[484],  &pinyin_table[2],    &pinyin_table[477],  &pinyin_table[352],  }, /* run ai => ru nai */
    { &pinyin_table[484],  &pinyin_table[4],    &pinyin_table[477],  &pinyin_table[354],  }, /* run an => ru nan */
    { &pinyin_table[484],  &pinyin_table[5],    &pinyin_table[477],  &pinyin_table[355],  }, /* run ang => ru nang */
    { &pinyin_table[484],  &pinyin_table[6],    &pinyin_table[477],  &pinyin_table[356],  }, /* run ao => ru nao */
    { &pinyin_table[484],  &pinyin_table[125],  &pinyin_table[477],  &pinyin_table[357],  }, /* run e => ru ne */
    { &pinyin_table[484],  &pinyin_table[126],  &pinyin_table[477],  &pinyin_table[359],  }, /* run ei => ru nei */
    { &pinyin_table[484],  &pinyin_table[127],  &pinyin_table[477],  &pinyin_table[361],  }, /* run en => ru nen */
    { &pinyin_table[493],  &pinyin_table[0],    &pinyin_table[489],  &pinyin_table[350],  }, /* san a => sa na */
    { &pinyin_table[493],  &pinyin_table[126],  &pinyin_table[489],  &pinyin_table[359],  }, /* san ei => sa nei */
    { &pinyin_table[494],  &pinyin_table[2],    &pinyin_table[493],  &pinyin_table[159],  }, /* sang ai => san gai */
    { &pinyin_table[494],  &pinyin_table[4],    &pinyin_table[493],  &pinyin_table[161],  }, /* sang an => san gan */
    { &pinyin_table[494],  &pinyin_table[5],    &pinyin_table[493],  &pinyin_table[162],  }, /* sang ang => san gang */
    { &pinyin_table[494],  &pinyin_table[6],    &pinyin_table[493],  &pinyin_table[163],  }, /* sang ao => san gao */
    { &pinyin_table[494],  &pinyin_table[125],  &pinyin_table[493],  &pinyin_table[164],  }, /* sang e => san ge */
    { &pinyin_table[494],  &pinyin_table[126],  &pinyin_table[493],  &pinyin_table[166],  }, /* sang ei => san gei */
    { &pinyin_table[494],  &pinyin_table[127],  &pinyin_table[493],  &pinyin_table[168],  }, /* sang en => san gen */
    { &pinyin_table[500],  &pinyin_table[0],    &pinyin_table[496],  &pinyin_table[350],  }, /* sen a => se na */
    { &pinyin_table[500],  &pinyin_table[2],    &pinyin_table[496],  &pinyin_table[352],  }, /* sen ai => se nai */
    { &pinyin_table[500],  &pinyin_table[4],    &pinyin_table[496],  &pinyin_table[354],  }, /* sen an => se nan */
    { &pinyin_table[500],  &pinyin_table[5],    &pinyin_table[496],  &pinyin_table[355],  }, /* sen ang => se nang */
    { &pinyin_table[500],  &pinyin_table[6],    &pinyin_table[496],  &pinyin_table[356],  }, /* sen ao => se nao */
    { &pinyin_table[500],  &pinyin_table[125],  &pinyin_table[496],  &pinyin_table[357],  }, /* sen e => se ne */
    { &pinyin_table[500],  &pinyin_table[126],  &pinyin_table[496],  &pinyin_table[359],  }, /* sen ei => se nei */
    { &pinyin_table[501],  &pinyin_table[2],    &pinyin_table[500],  &pinyin_table[159],  }, /* seng ai => sen gai */
    { &pinyin_table[501],  &pinyin_table[4],    &pinyin_table[500],  &pinyin_table[161],  }, /* seng an => sen gan */
    { &pinyin_table[501],  &pinyin_table[5],    &pinyin_table[500],  &pinyin_table[162],  }, /* seng ang => sen gang */
    { &pinyin_table[501],  &pinyin_table[6],    &pinyin_table[500],  &pinyin_table[163],  }, /* seng ao => sen gao */
    { &pinyin_table[501],  &pinyin_table[125],  &pinyin_table[500],  &pinyin_table[164],  }, /* seng e => sen ge */
    { &pinyin_table[501],  &pinyin_table[126],  &pinyin_table[500],  &pinyin_table[166],  }, /* seng ei => sen gei */
    { &pinyin_table[501],  &pinyin_table[127],  &pinyin_table[500],  &pinyin_table[168],  }, /* seng en => sen gen */
    { &pinyin_table[501],  &pinyin_table[392],  &pinyin_table[500],  &pinyin_table[173],  }, /* seng ou => sen gou */
    { &pinyin_table[507],  &pinyin_table[0],    &pinyin_table[503],  &pinyin_table[350],  }, /* shan a => sha na */
    { &pinyin_table[507],  &pinyin_table[4],    &pinyin_table[503],  &pinyin_table[354],  }, /* shan an => sha nan */
    { &pinyin_table[507],  &pinyin_table[126],  &pinyin_table[503],  &pinyin_table[359],  }, /* shan ei => sha nei */
    { &pinyin_table[508],  &pinyin_table[2],    &pinyin_table[507],  &pinyin_table[159],  }, /* shang ai => shan gai */
    { &pinyin_table[508],  &pinyin_table[5],    &pinyin_table[507],  &pinyin_table[162],  }, /* shang ang => shan gang */
    { &pinyin_table[508],  &pinyin_table[6],    &pinyin_table[507],  &pinyin_table[163],  }, /* shang ao => shan gao */
    { &pinyin_table[508],  &pinyin_table[125],  &pinyin_table[507],  &pinyin_table[164],  }, /* shang e => shan ge */
    { &pinyin_table[508],  &pinyin_table[126],  &pinyin_table[507],  &pinyin_table[166],  }, /* shang ei => shan gei */
    { &pinyin_table[508],  &pinyin_table[127],  &pinyin_table[507],  &pinyin_table[168],  }, /* shang en => shan gen */
    { &pinyin_table[508],  &pinyin_table[392],  &pinyin_table[507],  &pinyin_table[173],  }, /* shang ou => shan gou */
    { &pinyin_table[514],  &pinyin_table[126],  &pinyin_table[510],  &pinyin_table[359],  }, /* shen ei => she nei */
    { &pinyin_table[515],  &pinyin_table[4],    &pinyin_table[514],  &pinyin_table[161],  }, /* sheng an => shen gan */
    { &pinyin_table[515],  &pinyin_table[5],    &pinyin_table[514],  &pinyin_table[162],  }, /* sheng ang => shen gang */
    { &pinyin_table[515],  &pinyin_table[6],    &pinyin_table[514],  &pinyin_table[163],  }, /* sheng ao => shen gao */
    { &pinyin_table[515],  &pinyin_table[125],  &pinyin_table[514],  &pinyin_table[164],  }, /* sheng e => shen ge */
    { &pinyin_table[515],  &pinyin_table[126],  &pinyin_table[514],  &pinyin_table[166],  }, /* sheng ei => shen gei */
    { &pinyin_table[515],  &pinyin_table[392],  &pinyin_table[514],  &pinyin_table[173],  }, /* sheng ou => shen gou */
    { &pinyin_table[524],  &pinyin_table[0],    &pinyin_table[520],  &pinyin_table[350],  }, /* shuan a => shua na */
    { &pinyin_table[524],  &pinyin_table[2],    &pinyin_table[520],  &pinyin_table[352],  }, /* shuan ai => shua nai */
    { &pinyin_table[524],  &pinyin_table[4],    &pinyin_table[520],  &pinyin_table[354],  }, /* shuan an => shua nan */
    { &pinyin_table[524],  &pinyin_table[5],    &pinyin_table[520],  &pinyin_table[355],  }, /* shuan ang => shua nang */
    { &pinyin_table[524],  &pinyin_table[6],    &pinyin_table[520],  &pinyin_table[356],  }, /* shuan ao => shua nao */
    { &pinyin_table[524],  &pinyin_table[125],  &pinyin_table[520],  &pinyin_table[357],  }, /* shuan e => shua ne */
    { &pinyin_table[524],  &pinyin_table[126],  &pinyin_table[520],  &pinyin_table[359],  }, /* shuan ei => shua nei */
    { &pinyin_table[525],  &pinyin_table[126],  &pinyin_table[524],  &pinyin_table[166],  }, /* shuang ei => shuan gei */
    { &pinyin_table[529],  &pinyin_table[4],    &pinyin_table[519],  &pinyin_table[354],  }, /* shun an => shu nan */
    { &pinyin_table[529],  &pinyin_table[5],    &pinyin_table[519],  &pinyin_table[355],  }, /* shun ang => shu nang */
    { &pinyin_table[529],  &pinyin_table[6],    &pinyin_table[519],  &pinyin_table[356],  }, /* shun ao => shu nao */
    { &pinyin_table[529],  &pinyin_table[125],  &pinyin_table[519],  &pinyin_table[357],  }, /* shun e => shu ne */
    { &pinyin_table[529],  &pinyin_table[126],  &pinyin_table[519],  &pinyin_table[359],  }, /* shun ei => shu nei */
    { &pinyin_table[540],  &pinyin_table[0],    &pinyin_table[539],  &pinyin_table[157],  }, /* suang a => suan ga */
    { &pinyin_table[540],  &pinyin_table[2],    &pinyin_table[539],  &pinyin_table[159],  }, /* suang ai => suan gai */
    { &pinyin_table[540],  &pinyin_table[4],    &pinyin_table[539],  &pinyin_table[161],  }, /* suang an => suan gan */
    { &pinyin_table[540],  &pinyin_table[5],    &pinyin_table[539],  &pinyin_table[162],  }, /* suang ang => suan gang */
    { &pinyin_table[540],  &pinyin_table[6],    &pinyin_table[539],  &pinyin_table[163],  }, /* suang ao => suan gao */
    { &pinyin_table[540],  &pinyin_table[125],  &pinyin_table[539],  &pinyin_table[164],  }, /* suang e => suan ge */
    { &pinyin_table[540],  &pinyin_table[126],  &pinyin_table[539],  &pinyin_table[166],  }, /* suang ei => suan gei */
    { &pinyin_table[540],  &pinyin_table[127],  &pinyin_table[539],  &pinyin_table[168],  }, /* suang en => suan gen */
    { &pinyin_table[540],  &pinyin_table[392],  &pinyin_table[539],  &pinyin_table[173],  }, /* suang ou => suan gou */
    { &pinyin_table[544],  &pinyin_table[0],    &pinyin_table[536],  &pinyin_table[350],  }, /* sun a => su na */
    { &pinyin_table[544],  &pinyin_table[4],    &pinyin_table[536],  &pinyin_table[354],  }, /* sun an => su nan */
    { &pinyin_table[544],  &pinyin_table[5],    &pinyin_table[536],  &pinyin_table[355],  }, /* sun ang => su nang */
    { &pinyin_table[544],  &pinyin_table[6],    &pinyin_table[536],  &pinyin_table[356],  }, /* sun ao => su nao */
    { &pinyin_table[544],  &pinyin_table[125],  &pinyin_table[536],  &pinyin_table[357],  }, /* sun e => su ne */
    { &pinyin_table[544],  &pinyin_table[126],  &pinyin_table[536],  &pinyin_table[359],  }, /* sun ei => su nei */
    { &pinyin_table[551],  &pinyin_table[0],    &pinyin_table[547],  &pinyin_table[350],  }, /* tan a => ta na */
    { &pinyin_table[551],  &pinyin_table[5],    &pinyin_table[547],  &pinyin_table[355],  }, /* tan ang => ta nang */
    { &pinyin_table[551],  &pinyin_table[6],    &pinyin_table[547],  &pinyin_table[356],  }, /* tan ao => ta nao */
    { &pinyin_table[551],  &pinyin_table[125],  &pinyin_table[547],  &pinyin_table[357],  }, /* tan e => ta ne */
    { &pinyin_table[551],  &pinyin_table[126],  &pinyin_table[547],  &pinyin_table[359],  }, /* tan ei => ta nei */
    { &pinyin_table[552],  &pinyin_table[2],    &pinyin_table[551],  &pinyin_table[159],  }, /* tang ai => tan gai */
    { &pinyin_table[552],  &pinyin_table[4],    &pinyin_table[551],  &pinyin_table[161],  }, /* tang an => tan gan */
    { &pinyin_table[552],  &pinyin_table[5],    &pinyin_table[551],  &pinyin_table[162],  }, /* tang ang => tan gang */
    { &pinyin_table[552],  &pinyin_table[125],  &pinyin_table[551],  &pinyin_table[164],  }, /* tang e => tan ge */
    { &pinyin_table[552],  &pinyin_table[126],  &pinyin_table[551],  &pinyin_table[166],  }, /* tang ei => tan gei */
    { &pinyin_table[552],  &pinyin_table[392],  &pinyin_table[551],  &pinyin_table[173],  }, /* tang ou => tan gou */
    { &pinyin_table[557],  &pinyin_table[0],    &pinyin_table[554],  &pinyin_table[350],  }, /* ten a => te na */
    { &pinyin_table[557],  &pinyin_table[2],    &pinyin_table[554],  &pinyin_table[352],  }, /* ten ai => te nai */
    { &pinyin_table[557],  &pinyin_table[4],    &pinyin_table[554],  &pinyin_table[354],  }, /* ten an => te nan */
    { &pinyin_table[557],  &pinyin_table[5],    &pinyin_table[554],  &pinyin_table[355],  }, /* ten ang => te nang */
    { &pinyin_table[557],  &pinyin_table[6],    &pinyin_table[554],  &pinyin_table[356],  }, /* ten ao => te nao */
    { &pinyin_table[557],  &pinyin_table[125],  &pinyin_table[554],  &pinyin_table[357],  }, /* ten e => te ne */
    { &pinyin_table[557],  &pinyin_table[126],  &pinyin_table[554],  &pinyin_table[359],  }, /* ten ei => te nei */
    { &pinyin_table[557],  &pinyin_table[127],  &pinyin_table[554],  &pinyin_table[361],  }, /* ten en => te nen */
    { &pinyin_table[557],  &pinyin_table[392],  &pinyin_table[554],  &pinyin_table[381],  }, /* ten ou => te nou */
    { &pinyin_table[561],  &pinyin_table[0],    &pinyin_table[560],  &pinyin_table[157],  }, /* tiang a => tian ga */
    { &pinyin_table[561],  &pinyin_table[2],    &pinyin_table[560],  &pinyin_table[159],  }, /* tiang ai => tian gai */
    { &pinyin_table[561],  &pinyin_table[4],    &pinyin_table[560],  &pinyin_table[161],  }, /* tiang an => tian gan */
    { &pinyin_table[561],  &pinyin_table[5],    &pinyin_table[560],  &pinyin_table[162],  }, /* tiang ang => tian gang */
    { &pinyin_table[561],  &pinyin_table[6],    &pinyin_table[560],  &pinyin_table[163],  }, /* tiang ao => tian gao */
    { &pinyin_table[561],  &pinyin_table[125],  &pinyin_table[560],  &pinyin_table[164],  }, /* tiang e => tian ge */
    { &pinyin_table[561],  &pinyin_table[126],  &pinyin_table[560],  &pinyin_table[166],  }, /* tiang ei => tian gei */
    { &pinyin_table[561],  &pinyin_table[127],  &pinyin_table[560],  &pinyin_table[168],  }, /* tiang en => tian gen */
    { &pinyin_table[561],  &pinyin_table[392],  &pinyin_table[560],  &pinyin_table[173],  }, /* tiang ou => tian gou */
    { &pinyin_table[563],  &pinyin_table[448],  &pinyin_table[559],  &pinyin_table[128],  }, /* tie r => ti er */
    { &pinyin_table[566],  &pinyin_table[0],    &pinyin_table[559],  &pinyin_table[350],  }, /* tin a => ti na */
    { &pinyin_table[566],  &pinyin_table[2],    &pinyin_table[559],  &pinyin_table[352],  }, /* tin ai => ti nai */
    { &pinyin_table[566],  &pinyin_table[4],    &pinyin_table[559],  &pinyin_table[354],  }, /* tin an => ti nan */
    { &pinyin_table[566],  &pinyin_table[5],    &pinyin_table[559],  &pinyin_table[355],  }, /* tin ang => ti nang */
    { &pinyin_table[566],  &pinyin_table[6],    &pinyin_table[559],  &pinyin_table[356],  }, /* tin ao => ti nao */
    { &pinyin_table[566],  &pinyin_table[125],  &pinyin_table[559],  &pinyin_table[357],  }, /* tin e => ti ne */
    { &pinyin_table[566],  &pinyin_table[126],  &pinyin_table[559],  &pinyin_table[359],  }, /* tin ei => ti nei */
    { &pinyin_table[566],  &pinyin_table[127],  &pinyin_table[559],  &pinyin_table[361],  }, /* tin en => ti nen */
    { &pinyin_table[566],  &pinyin_table[392],  &pinyin_table[559],  &pinyin_table[381],  }, /* tin ou => ti nou */
    { &pinyin_table[574],  &pinyin_table[0],    &pinyin_table[573],  &pinyin_table[157],  }, /* tuang a => tuan ga */
    { &pinyin_table[574],  &pinyin_table[2],    &pinyin_table[573],  &pinyin_table[159],  }, /* tuang ai => tuan gai */
    { &pinyin_table[574],  &pinyin_table[4],    &pinyin_table[573],  &pinyin_table[161],  }, /* tuang an => tuan gan */
    { &pinyin_table[574],  &pinyin_table[5],    &pinyin_table[573],  &pinyin_table[162],  }, /* tuang ang => tuan gang */
    { &pinyin_table[574],  &pinyin_table[6],    &pinyin_table[573],  &pinyin_table[163],  }, /* tuang ao => tuan gao */
    { &pinyin_table[574],  &pinyin_table[125],  &pinyin_table[573],  &pinyin_table[164],  }, /* tuang e => tuan ge */
    { &pinyin_table[574],  &pinyin_table[126],  &pinyin_table[573],  &pinyin_table[166],  }, /* tuang ei => tuan gei */
    { &pinyin_table[574],  &pinyin_table[127],  &pinyin_table[573],  &pinyin_table[168],  }, /* tuang en => tuan gen */
    { &pinyin_table[574],  &pinyin_table[392],  &pinyin_table[573],  &pinyin_table[173],  }, /* tuang ou => tuan gou */
    { &pinyin_table[578],  &pinyin_table[0],    &pinyin_table[572],  &pinyin_table[350],  }, /* tun a => tu na */
    { &pinyin_table[578],  &pinyin_table[2],    &pinyin_table[572],  &pinyin_table[352],  }, /* tun ai => tu nai */
    { &pinyin_table[578],  &pinyin_table[4],    &pinyin_table[572],  &pinyin_table[354],  }, /* tun an => tu nan */
    { &pinyin_table[578],  &pinyin_table[5],    &pinyin_table[572],  &pinyin_table[355],  }, /* tun ang => tu nang */
    { &pinyin_table[578],  &pinyin_table[6],    &pinyin_table[572],  &pinyin_table[356],  }, /* tun ao => tu nao */
    { &pinyin_table[578],  &pinyin_table[125],  &pinyin_table[572],  &pinyin_table[357],  }, /* tun e => tu ne */
    { &pinyin_table[578],  &pinyin_table[126],  &pinyin_table[572],  &pinyin_table[359],  }, /* tun ei => tu nei */
    { &pinyin_table[578],  &pinyin_table[127],  &pinyin_table[572],  &pinyin_table[361],  }, /* tun en => tu nen */
    { &pinyin_table[585],  &pinyin_table[126],  &pinyin_table[581],  &pinyin_table[359],  }, /* wan ei => wa nei */
    { &pinyin_table[586],  &pinyin_table[5],    &pinyin_table[585],  &pinyin_table[162],  }, /* wang ang => wan gang */
    { &pinyin_table[586],  &pinyin_table[6],    &pinyin_table[585],  &pinyin_table[163],  }, /* wang ao => wan gao */
    { &pinyin_table[586],  &pinyin_table[125],  &pinyin_table[585],  &pinyin_table[164],  }, /* wang e => wan ge */
    { &pinyin_table[586],  &pinyin_table[126],  &pinyin_table[585],  &pinyin_table[166],  }, /* wang ei => wan gei */
    { &pinyin_table[586],  &pinyin_table[392],  &pinyin_table[585],  &pinyin_table[173],  }, /* wang ou => wan gou */
    { &pinyin_table[591],  &pinyin_table[0],    &pinyin_table[590],  &pinyin_table[157],  }, /* weng a => wen ga */
    { &pinyin_table[591],  &pinyin_table[2],    &pinyin_table[590],  &pinyin_table[159],  }, /* weng ai => wen gai */
    { &pinyin_table[591],  &pinyin_table[4],    &pinyin_table[590],  &pinyin_table[161],  }, /* weng an => wen gan */
    { &pinyin_table[591],  &pinyin_table[5],    &pinyin_table[590],  &pinyin_table[162],  }, /* weng ang => wen gang */
    { &pinyin_table[591],  &pinyin_table[6],    &pinyin_table[590],  &pinyin_table[163],  }, /* weng ao => wen gao */
    { &pinyin_table[591],  &pinyin_table[125],  &pinyin_table[590],  &pinyin_table[164],  }, /* weng e => wen ge */
    { &pinyin_table[591],  &pinyin_table[126],  &pinyin_table[590],  &pinyin_table[166],  }, /* weng ei => wen gei */
    { &pinyin_table[591],  &pinyin_table[127],  &pinyin_table[590],  &pinyin_table[168],  }, /* weng en => wen gen */
    { &pinyin_table[591],  &pinyin_table[392],  &pinyin_table[590],  &pinyin_table[173],  }, /* weng ou => wen gou */
    { &pinyin_table[599],  &pinyin_table[0],    &pinyin_table[596],  &pinyin_table[350],  }, /* xian a => xia na */
    { &pinyin_table[599],  &pinyin_table[5],    &pinyin_table[596],  &pinyin_table[355],  }, /* xian ang => xia nang */
    { &pinyin_table[599],  &pinyin_table[6],    &pinyin_table[596],  &pinyin_table[356],  }, /* xian ao => xia nao */
    { &pinyin_table[599],  &pinyin_table[126],  &pinyin_table[596],  &pinyin_table[359],  }, /* xian ei => xia nei */
    { &pinyin_table[600],  &pinyin_table[5],    &pinyin_table[599],  &pinyin_table[162],  }, /* xiang ang => xian gang */
    { &pinyin_table[600],  &pinyin_table[6],    &pinyin_table[599],  &pinyin_table[163],  }, /* xiang ao => xian gao */
    { &pinyin_table[600],  &pinyin_table[126],  &pinyin_table[599],  &pinyin_table[166],  }, /* xiang ei => xian gei */
    { &pinyin_table[600],  &pinyin_table[127],  &pinyin_table[599],  &pinyin_table[168],  }, /* xiang en => xian gen */
    { &pinyin_table[600],  &pinyin_table[392],  &pinyin_table[599],  &pinyin_table[173],  }, /* xiang ou => xian gou */
    { &pinyin_table[602],  &pinyin_table[448],  &pinyin_table[595],  &pinyin_table[128],  }, /* xie r => xi er */
    { &pinyin_table[605],  &pinyin_table[0],    &pinyin_table[595],  &pinyin_table[350],  }, /* xin a => xi na */
    { &pinyin_table[605],  &pinyin_table[4],    &pinyin_table[595],  &pinyin_table[354],  }, /* xin an => xi nan */
    { &pinyin_table[605],  &pinyin_table[125],  &pinyin_table[595],  &pinyin_table[357],  }, /* xin e => xi ne */
    { &pinyin_table[605],  &pinyin_table[126],  &pinyin_table[595],  &pinyin_table[359],  }, /* xin ei => xi nei */
    { &pinyin_table[605],  &pinyin_table[127],  &pinyin_table[595],  &pinyin_table[361],  }, /* xin en => xi nen */
    { &pinyin_table[606],  &pinyin_table[4],    &pinyin_table[605],  &pinyin_table[161],  }, /* xing an => xin gan */
    { &pinyin_table[606],  &pinyin_table[5],    &pinyin_table[605],  &pinyin_table[162],  }, /* xing ang => xin gang */
    { &pinyin_table[606],  &pinyin_table[6],    &pinyin_table[605],  &pinyin_table[163],  }, /* xing ao => xin gao */
    { &pinyin_table[606],  &pinyin_table[125],  &pinyin_table[605],  &pinyin_table[164],  }, /* xing e => xin ge */
    { &pinyin_table[606],  &pinyin_table[126],  &pinyin_table[605],  &pinyin_table[166],  }, /* xing ei => xin gei */
    { &pinyin_table[606],  &pinyin_table[127],  &pinyin_table[605],  &pinyin_table[168],  }, /* xing en => xin gen */
    { &pinyin_table[606],  &pinyin_table[392],  &pinyin_table[605],  &pinyin_table[173],  }, /* xing ou => xin gou */
    { &pinyin_table[614],  &pinyin_table[0],    &pinyin_table[613],  &pinyin_table[157],  }, /* xuang a => xuan ga */
    { &pinyin_table[614],  &pinyin_table[2],    &pinyin_table[613],  &pinyin_table[159],  }, /* xuang ai => xuan gai */
    { &pinyin_table[614],  &pinyin_table[4],    &pinyin_table[613],  &pinyin_table[161],  }, /* xuang an => xuan gan */
    { &pinyin_table[614],  &pinyin_table[5],    &pinyin_table[613],  &pinyin_table[162],  }, /* xuang ang => xuan gang */
    { &pinyin_table[614],  &pinyin_table[6],    &pinyin_table[613],  &pinyin_table[163],  }, /* xuang ao => xuan gao */
    { &pinyin_table[614],  &pinyin_table[125],  &pinyin_table[613],  &pinyin_table[164],  }, /* xuang e => xuan ge */
    { &pinyin_table[614],  &pinyin_table[126],  &pinyin_table[613],  &pinyin_table[166],  }, /* xuang ei => xuan gei */
    { &pinyin_table[614],  &pinyin_table[127],  &pinyin_table[613],  &pinyin_table[168],  }, /* xuang en => xuan gen */
    { &pinyin_table[614],  &pinyin_table[392],  &pinyin_table[613],  &pinyin_table[173],  }, /* xuang ou => xuan gou */
    { &pinyin_table[615],  &pinyin_table[448],  &pinyin_table[612],  &pinyin_table[128],  }, /* xue r => xu er */
    { &pinyin_table[616],  &pinyin_table[0],    &pinyin_table[615],  &pinyin_table[350],  }, /* xuen a => xue na */
    { &pinyin_table[616],  &pinyin_table[2],    &pinyin_table[615],  &pinyin_table[352],  }, /* xuen ai => xue nai */
    { &pinyin_table[616],  &pinyin_table[4],    &pinyin_table[615],  &pinyin_table[354],  }, /* xuen an => xue nan */
    { &pinyin_table[616],  &pinyin_table[5],    &pinyin_table[615],  &pinyin_table[355],  }, /* xuen ang => xue nang */
    { &pinyin_table[616],  &pinyin_table[6],    &pinyin_table[615],  &pinyin_table[356],  }, /* xuen ao => xue nao */
    { &pinyin_table[616],  &pinyin_table[125],  &pinyin_table[615],  &pinyin_table[357],  }, /* xuen e => xue ne */
    { &pinyin_table[616],  &pinyin_table[126],  &pinyin_table[615],  &pinyin_table[359],  }, /* xuen ei => xue nei */
    { &pinyin_table[616],  &pinyin_table[127],  &pinyin_table[615],  &pinyin_table[361],  }, /* xuen en => xue nen */
    { &pinyin_table[616],  &pinyin_table[392],  &pinyin_table[615],  &pinyin_table[381],  }, /* xuen ou => xue nou */
    { &pinyin_table[617],  &pinyin_table[5],    &pinyin_table[612],  &pinyin_table[355],  }, /* xun ang => xu nang */
    { &pinyin_table[617],  &pinyin_table[6],    &pinyin_table[612],  &pinyin_table[356],  }, /* xun ao => xu nao */
    { &pinyin_table[617],  &pinyin_table[125],  &pinyin_table[612],  &pinyin_table[357],  }, /* xun e => xu ne */
    { &pinyin_table[617],  &pinyin_table[126],  &pinyin_table[612],  &pinyin_table[359],  }, /* xun ei => xu nei */
    { &pinyin_table[628],  &pinyin_table[0],    &pinyin_table[625],  &pinyin_table[350],  }, /* yan a => ya na */
    { &pinyin_table[628],  &pinyin_table[125],  &pinyin_table[625],  &pinyin_table[357],  }, /* yan e => ya ne */
    { &pinyin_table[628],  &pinyin_table[126],  &pinyin_table[625],  &pinyin_table[359],  }, /* yan ei => ya nei */
    { &pinyin_table[629],  &pinyin_table[2],    &pinyin_table[628],  &pinyin_table[159],  }, /* yang ai => yan gai */
    { &pinyin_table[629],  &pinyin_table[4],    &pinyin_table[628],  &pinyin_table[161],  }, /* yang an => yan gan */
    { &pinyin_table[629],  &pinyin_table[5],    &pinyin_table[628],  &pinyin_table[162],  }, /* yang ang => yan gang */
    { &pinyin_table[629],  &pinyin_table[6],    &pinyin_table[628],  &pinyin_table[163],  }, /* yang ao => yan gao */
    { &pinyin_table[629],  &pinyin_table[125],  &pinyin_table[628],  &pinyin_table[164],  }, /* yang e => yan ge */
    { &pinyin_table[629],  &pinyin_table[126],  &pinyin_table[628],  &pinyin_table[166],  }, /* yang ei => yan gei */
    { &pinyin_table[629],  &pinyin_table[392],  &pinyin_table[628],  &pinyin_table[173],  }, /* yang ou => yan gou */
    { &pinyin_table[635],  &pinyin_table[0],    &pinyin_table[632],  &pinyin_table[350],  }, /* yin a => yi na */
    { &pinyin_table[635],  &pinyin_table[2],    &pinyin_table[632],  &pinyin_table[352],  }, /* yin ai => yi nai */
    { &pinyin_table[635],  &pinyin_table[4],    &pinyin_table[632],  &pinyin_table[354],  }, /* yin an => yi nan */
    { &pinyin_table[635],  &pinyin_table[5],    &pinyin_table[632],  &pinyin_table[355],  }, /* yin ang => yi nang */
    { &pinyin_table[635],  &pinyin_table[6],    &pinyin_table[632],  &pinyin_table[356],  }, /* yin ao => yi nao */
    { &pinyin_table[635],  &pinyin_table[126],  &pinyin_table[632],  &pinyin_table[359],  }, /* yin ei => yi nei */
    { &pinyin_table[636],  &pinyin_table[2],    &pinyin_table[635],  &pinyin_table[159],  }, /* ying ai => yin gai */
    { &pinyin_table[636],  &pinyin_table[5],    &pinyin_table[635],  &pinyin_table[162],  }, /* ying ang => yin gang */
    { &pinyin_table[636],  &pinyin_table[6],    &pinyin_table[635],  &pinyin_table[163],  }, /* ying ao => yin gao */
    { &pinyin_table[636],  &pinyin_table[126],  &pinyin_table[635],  &pinyin_table[166],  }, /* ying ei => yin gei */
    { &pinyin_table[636],  &pinyin_table[127],  &pinyin_table[635],  &pinyin_table[168],  }, /* ying en => yin gen */
    { &pinyin_table[636],  &pinyin_table[392],  &pinyin_table[635],  &pinyin_table[173],  }, /* ying ou => yin gou */
    { &pinyin_table[644],  &pinyin_table[0],    &pinyin_table[643],  &pinyin_table[157],  }, /* yuang a => yuan ga */
    { &pinyin_table[644],  &pinyin_table[2],    &pinyin_table[643],  &pinyin_table[159],  }, /* yuang ai => yuan gai */
    { &pinyin_table[644],  &pinyin_table[4],    &pinyin_table[643],  &pinyin_table[161],  }, /* yuang an => yuan gan */
    { &pinyin_table[644],  &pinyin_table[5],    &pinyin_table[643],  &pinyin_table[162],  }, /* yuang ang => yuan gang */
    { &pinyin_table[644],  &pinyin_table[6],    &pinyin_table[643],  &pinyin_table[163],  }, /* yuang ao => yuan gao */
    { &pinyin_table[644],  &pinyin_table[125],  &pinyin_table[643],  &pinyin_table[164],  }, /* yuang e => yuan ge */
    { &pinyin_table[644],  &pinyin_table[126],  &pinyin_table[643],  &pinyin_table[166],  }, /* yuang ei => yuan gei */
    { &pinyin_table[644],  &pinyin_table[127],  &pinyin_table[643],  &pinyin_table[168],  }, /* yuang en => yuan gen */
    { &pinyin_table[644],  &pinyin_table[392],  &pinyin_table[643],  &pinyin_table[173],  }, /* yuang ou => yuan gou */
    { &pinyin_table[645],  &pinyin_table[448],  &pinyin_table[642],  &pinyin_table[128],  }, /* yue r => yu er */
    { &pinyin_table[646],  &pinyin_table[0],    &pinyin_table[645],  &pinyin_table[350],  }, /* yuen a => yue na */
    { &pinyin_table[646],  &pinyin_table[2],    &pinyin_table[645],  &pinyin_table[352],  }, /* yuen ai => yue nai */
    { &pinyin_table[646],  &pinyin_table[4],    &pinyin_table[645],  &pinyin_table[354],  }, /* yuen an => yue nan */
    { &pinyin_table[646],  &pinyin_table[5],    &pinyin_table[645],  &pinyin_table[355],  }, /* yuen ang => yue nang */
    { &pinyin_table[646],  &pinyin_table[6],    &pinyin_table[645],  &pinyin_table[356],  }, /* yuen ao => yue nao */
    { &pinyin_table[646],  &pinyin_table[125],  &pinyin_table[645],  &pinyin_table[357],  }, /* yuen e => yue ne */
    { &pinyin_table[646],  &pinyin_table[126],  &pinyin_table[645],  &pinyin_table[359],  }, /* yuen ei => yue nei */
    { &pinyin_table[646],  &pinyin_table[127],  &pinyin_table[645],  &pinyin_table[361],  }, /* yuen en => yue nen */
    { &pinyin_table[646],  &pinyin_table[392],  &pinyin_table[645],  &pinyin_table[381],  }, /* yuen ou => yue nou */
    { &pinyin_table[647],  &pinyin_table[0],    &pinyin_table[642],  &pinyin_table[350],  }, /* yun a => yu na */
    { &pinyin_table[647],  &pinyin_table[2],    &pinyin_table[642],  &pinyin_table[352],  }, /* yun ai => yu nai */
    { &pinyin_table[647],  &pinyin_table[4],    &pinyin_table[642],  &pinyin_table[354],  }, /* yun an => yu nan */
    { &pinyin_table[647],  &pinyin_table[5],    &pinyin_table[642],  &pinyin_table[355],  }, /* yun ang => yu nang */
    { &pinyin_table[647],  &pinyin_table[6],    &pinyin_table[642],  &pinyin_table[356],  }, /* yun ao => yu nao */
    { &pinyin_table[647],  &pinyin_table[125],  &pinyin_table[642],  &pinyin_table[357],  }, /* yun e => yu ne */
    { &pinyin_table[647],  &pinyin_table[126],  &pinyin_table[642],  &pinyin_table[359],  }, /* yun ei => yu nei */
    { &pinyin_table[659],  &pinyin_table[0],    &pinyin_table[655],  &pinyin_table[350],  }, /* zan a => za na */
    { &pinyin_table[659],  &pinyin_table[4],    &pinyin_table[655],  &pinyin_table[354],  }, /* zan an => za nan */
    { &pinyin_table[659],  &pinyin_table[5],    &pinyin_table[655],  &pinyin_table[355],  }, /* zan ang => za nang */
    { &pinyin_table[659],  &pinyin_table[6],    &pinyin_table[655],  &pinyin_table[356],  }, /* zan ao => za nao */
    { &pinyin_table[659],  &pinyin_table[125],  &pinyin_table[655],  &pinyin_table[357],  }, /* zan e => za ne */
    { &pinyin_table[659],  &pinyin_table[126],  &pinyin_table[655],  &pinyin_table[359],  }, /* zan ei => za nei */
    { &pinyin_table[660],  &pinyin_table[4],    &pinyin_table[659],  &pinyin_table[161],  }, /* zang an => zan gan */
    { &pinyin_table[660],  &pinyin_table[5],    &pinyin_table[659],  &pinyin_table[162],  }, /* zang ang => zan gang */
    { &pinyin_table[660],  &pinyin_table[6],    &pinyin_table[659],  &pinyin_table[163],  }, /* zang ao => zan gao */
    { &pinyin_table[660],  &pinyin_table[125],  &pinyin_table[659],  &pinyin_table[164],  }, /* zang e => zan ge */
    { &pinyin_table[660],  &pinyin_table[126],  &pinyin_table[659],  &pinyin_table[166],  }, /* zang ei => zan gei */
    { &pinyin_table[660],  &pinyin_table[127],  &pinyin_table[659],  &pinyin_table[168],  }, /* zang en => zan gen */
    { &pinyin_table[660],  &pinyin_table[392],  &pinyin_table[659],  &pinyin_table[173],  }, /* zang ou => zan gou */
    { &pinyin_table[666],  &pinyin_table[0],    &pinyin_table[662],  &pinyin_table[350],  }, /* zen a => ze na */
    { &pinyin_table[666],  &pinyin_table[4],    &pinyin_table[662],  &pinyin_table[354],  }, /* zen an => ze nan */
    { &pinyin_table[666],  &pinyin_table[6],    &pinyin_table[662],  &pinyin_table[356],  }, /* zen ao => ze nao */
    { &pinyin_table[666],  &pinyin_table[125],  &pinyin_table[662],  &pinyin_table[357],  }, /* zen e => ze ne */
    { &pinyin_table[666],  &pinyin_table[126],  &pinyin_table[662],  &pinyin_table[359],  }, /* zen ei => ze nei */
    { &pinyin_table[667],  &pinyin_table[2],    &pinyin_table[666],  &pinyin_table[159],  }, /* zeng ai => zen gai */
    { &pinyin_table[667],  &pinyin_table[4],    &pinyin_table[666],  &pinyin_table[161],  }, /* zeng an => zen gan */
    { &pinyin_table[667],  &pinyin_table[5],    &pinyin_table[666],  &pinyin_table[162],  }, /* zeng ang => zen gang */
    { &pinyin_table[667],  &pinyin_table[6],    &pinyin_table[666],  &pinyin_table[163],  }, /* zeng ao => zen gao */
    { &pinyin_table[667],  &pinyin_table[126],  &pinyin_table[666],  &pinyin_table[166],  }, /* zeng ei => zen gei */
    { &pinyin_table[667],  &pinyin_table[127],  &pinyin_table[666],  &pinyin_table[168],  }, /* zeng en => zen gen */
    { &pinyin_table[667],  &pinyin_table[392],  &pinyin_table[666],  &pinyin_table[173],  }, /* zeng ou => zen gou */
    { &pinyin_table[673],  &pinyin_table[126],  &pinyin_table[669],  &pinyin_table[359],  }, /* zhan ei => zha nei */
    { &pinyin_table[674],  &pinyin_table[4],    &pinyin_table[673],  &pinyin_table[161],  }, /* zhang an => zhan gan */
    { &pinyin_table[674],  &pinyin_table[5],    &pinyin_table[673],  &pinyin_table[162],  }, /* zhang ang => zhan gang */
    { &pinyin_table[674],  &pinyin_table[6],    &pinyin_table[673],  &pinyin_table[163],  }, /* zhang ao => zhan gao */
    { &pinyin_table[674],  &pinyin_table[125],  &pinyin_table[673],  &pinyin_table[164],  }, /* zhang e => zhan ge */
    { &pinyin_table[674],  &pinyin_table[126],  &pinyin_table[673],  &pinyin_table[166],  }, /* zhang ei => zhan gei */
    { &pinyin_table[674],  &pinyin_table[127],  &pinyin_table[673],  &pinyin_table[168],  }, /* zhang en => zhan gen */
    { &pinyin_table[674],  &pinyin_table[392],  &pinyin_table[673],  &pinyin_table[173],  }, /* zhang ou => zhan gou */
    { &pinyin_table[680],  &pinyin_table[0],    &pinyin_table[676],  &pinyin_table[350],  }, /* zhen a => zhe na */
    { &pinyin_table[680],  &pinyin_table[4],    &pinyin_table[676],  &pinyin_table[354],  }, /* zhen an => zhe nan */
    { &pinyin_table[680],  &pinyin_table[5],    &pinyin_table[676],  &pinyin_table[355],  }, /* zhen ang => zhe nang */
    { &pinyin_table[680],  &pinyin_table[6],    &pinyin_table[676],  &pinyin_table[356],  }, /* zhen ao => zhe nao */
    { &pinyin_table[680],  &pinyin_table[125],  &pinyin_table[676],  &pinyin_table[357],  }, /* zhen e => zhe ne */
    { &pinyin_table[680],  &pinyin_table[126],  &pinyin_table[676],  &pinyin_table[359],  }, /* zhen ei => zhe nei */
    { &pinyin_table[681],  &pinyin_table[2],    &pinyin_table[680],  &pinyin_table[159],  }, /* zheng ai => zhen gai */
    { &pinyin_table[681],  &pinyin_table[4],    &pinyin_table[680],  &pinyin_table[161],  }, /* zheng an => zhen gan */
    { &pinyin_table[681],  &pinyin_table[5],    &pinyin_table[680],  &pinyin_table[162],  }, /* zheng ang => zhen gang */
    { &pinyin_table[681],  &pinyin_table[6],    &pinyin_table[680],  &pinyin_table[163],  }, /* zheng ao => zhen gao */
    { &pinyin_table[681],  &pinyin_table[125],  &pinyin_table[680],  &pinyin_table[164],  }, /* zheng e => zhen ge */
    { &pinyin_table[681],  &pinyin_table[126],  &pinyin_table[680],  &pinyin_table[166],  }, /* zheng ei => zhen gei */
    { &pinyin_table[681],  &pinyin_table[127],  &pinyin_table[680],  &pinyin_table[168],  }, /* zheng en => zhen gen */
    { &pinyin_table[681],  &pinyin_table[392],  &pinyin_table[680],  &pinyin_table[173],  }, /* zheng ou => zhen gou */
    { &pinyin_table[692],  &pinyin_table[6],    &pinyin_table[688],  &pinyin_table[356],  }, /* zhuan ao => zhua nao */
    { &pinyin_table[692],  &pinyin_table[125],  &pinyin_table[688],  &pinyin_table[357],  }, /* zhuan e => zhua ne */
    { &pinyin_table[692],  &pinyin_table[126],  &pinyin_table[688],  &pinyin_table[359],  }, /* zhuan ei => zhua nei */
    { &pinyin_table[693],  &pinyin_table[2],    &pinyin_table[692],  &pinyin_table[159],  }, /* zhuang ai => zhuan gai */
    { &pinyin_table[693],  &pinyin_table[4],    &pinyin_table[692],  &pinyin_table[161],  }, /* zhuang an => zhuan gan */
    { &pinyin_table[693],  &pinyin_table[5],    &pinyin_table[692],  &pinyin_table[162],  }, /* zhuang ang => zhuan gang */
    { &pinyin_table[693],  &pinyin_table[6],    &pinyin_table[692],  &pinyin_table[163],  }, /* zhuang ao => zhuan gao */
    { &pinyin_table[693],  &pinyin_table[125],  &pinyin_table[692],  &pinyin_table[164],  }, /* zhuang e => zhuan ge */
    { &pinyin_table[693],  &pinyin_table[126],  &pinyin_table[692],  &pinyin_table[166],  }, /* zhuang ei => zhuan gei */
    { &pinyin_table[693],  &pinyin_table[127],  &pinyin_table[692],  &pinyin_table[168],  }, /* zhuang en => zhuan gen */
    { &pinyin_table[693],  &pinyin_table[392],  &pinyin_table[692],  &pinyin_table[173],  }, /* zhuang ou => zhuan gou */
    { &pinyin_table[697],  &pinyin_table[0],    &pinyin_table[687],  &pinyin_table[350],  }, /* zhun a => zhu na */
    { &pinyin_table[697],  &pinyin_table[4],    &pinyin_table[687],  &pinyin_table[354],  }, /* zhun an => zhu nan */
    { &pinyin_table[697],  &pinyin_table[5],    &pinyin_table[687],  &pinyin_table[355],  }, /* zhun ang => zhu nang */
    { &pinyin_table[697],  &pinyin_table[6],    &pinyin_table[687],  &pinyin_table[356],  }, /* zhun ao => zhu nao */
    { &pinyin_table[697],  &pinyin_table[125],  &pinyin_table[687],  &pinyin_table[357],  }, /* zhun e => zhu ne */
    { &pinyin_table[697],  &pinyin_table[126],  &pinyin_table[687],  &pinyin_table[359],  }, /* zhun ei => zhu nei */
    { &pinyin_table[708],  &pinyin_table[0],    &pinyin_table[707],  &pinyin_table[157],  }, /* zuang a => zuan ga */
    { &pinyin_table[708],  &pinyin_table[2],    &pinyin_table[707],  &pinyin_table[159],  }, /* zuang ai => zuan gai */
    { &pinyin_table[708],  &pinyin_table[4],    &pinyin_table[707],  &pinyin_table[161],  }, /* zuang an => zuan gan */
    { &pinyin_table[708],  &pinyin_table[5],    &pinyin_table[707],  &pinyin_table[162],  }, /* zuang ang => zuan gang */
    { &pinyin_table[708],  &pinyin_table[6],    &pinyin_table[707],  &pinyin_table[163],  }, /* zuang ao => zuan gao */
    { &pinyin_table[708],  &pinyin_table[125],  &pinyin_table[707],  &pinyin_table[164],  }, /* zuang e => zuan ge */
    { &pinyin_table[708],  &pinyin_table[126],  &pinyin_table[707],  &pinyin_table[166],  }, /* zuang ei => zuan gei */
    { &pinyin_table[708],  &pinyin_table[127],  &pinyin_table[707],  &pinyin_table[168],  }, /* zuang en => zuan gen */
    { &pinyin_table[708],  &pinyin_table[392],  &pinyin_table[707],  &pinyin_table[173],  }, /* zuang ou => zuan gou */
    { &pinyin_table[712],  &pinyin_table[0],    &pinyin_table[704],  &pinyin_table[350],  }, /* zun a => zu na */
    { &pinyin_table[712],  &pinyin_table[4],    &pinyin_table[704],  &pinyin_table[354],  }, /* zun an => zu nan */
    { &pinyin_table[712],  &pinyin_table[5],    &pinyin_table[704],  &pinyin_table[355],  }, /* zun ang => zu nang */
    { &pinyin_table[712],  &pinyin_table[6],    &pinyin_table[704],  &pinyin_table[356],  }, /* zun ao => zu nao */
    { &pinyin_table[712],  &pinyin_table[125],  &pinyin_table[704],  &pinyin_table[357],  }, /* zun e => zu ne */
    { &pinyin_table[712],  &pinyin_table[126],  &pinyin_table[704],  &pinyin_table[359],  }, /* zun ei => zu nei */
};

