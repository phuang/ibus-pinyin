/*
 * Bopomofo.h
 *
 *  Created on: 2010-5-12
 *      Author: byvoid
 */

#ifndef BOPOMOFO_H_
#define BOPOMOFO_H_

#define MAX_BOPOMOFO_LEN (4)

#define BOPOMOFO_ZERO               (0)
#define BOPOMOFO_B                  (1)
#define BOPOMOFO_P                  (2)
#define BOPOMOFO_M                  (3)
#define BOPOMOFO_F                  (4)
#define BOPOMOFO_D                  (5)
#define BOPOMOFO_T                  (6)
#define BOPOMOFO_N                  (7)
#define BOPOMOFO_L                  (8)
#define BOPOMOFO_G                  (9)
#define BOPOMOFO_K                  (10)
#define BOPOMOFO_H                  (11)
#define BOPOMOFO_J                  (12)
#define BOPOMOFO_Q                  (13)
#define BOPOMOFO_X                  (14)
#define BOPOMOFO_ZH                 (15)
#define BOPOMOFO_CH                 (16)
#define BOPOMOFO_SH                 (17)
#define BOPOMOFO_R                  (18)
#define BOPOMOFO_Z                  (19)
#define BOPOMOFO_C                  (20)
#define BOPOMOFO_S                  (21)
#define BOPOMOFO_I                  (22)
#define BOPOMOFO_U                  (23)
#define BOPOMOFO_V                  (24)
#define BOPOMOFO_A                  (25)
#define BOPOMOFO_O                  (26)
#define BOPOMOFO_E                  (27)
#define BOPOMOFO_E2                 (28)
#define BOPOMOFO_AI                 (29)
#define BOPOMOFO_EI                 (30)
#define BOPOMOFO_AO                 (31)
#define BOPOMOFO_OU                 (32)
#define BOPOMOFO_AN                 (33)
#define BOPOMOFO_EN                 (34)
#define BOPOMOFO_ANG                (35)
#define BOPOMOFO_ENG                (36)
#define BOPOMOFO_ER                 (37)
#define BOPOMOFO_TONE_2             (38)
#define BOPOMOFO_TONE_3             (39)
#define BOPOMOFO_TONE_4             (40)
#define BOPOMOFO_TONE_5             (41)

const static wchar_t bopomofo_char[] = {
    L'\0',L'ㄅ',L'ㄆ',L'ㄇ',L'ㄈ',L'ㄉ',L'ㄊ',L'ㄋ',L'ㄌ',L'ㄍ',L'ㄎ',
    L'ㄏ',L'ㄐ',L'ㄑ',L'ㄒ',L'ㄓ',L'ㄔ',L'ㄕ',L'ㄖ',L'ㄗ',L'ㄘ',L'ㄙ',

    L'ㄧ',L'ㄨ',L'ㄩ',L'ㄚ',L'ㄛ',L'ㄜ',L'ㄝ',L'ㄞ',L'ㄟ',L'ㄠ',L'ㄡ',
    L'ㄢ',L'ㄣ',L'ㄤ',L'ㄥ',L'ㄦ',

    L'ˊ',L'ˇ',L'ˋ',L'˙',
};

#endif /* BOPOMOFO_H_ */
