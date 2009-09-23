/* vim:set et sts=4: */
#ifndef __PY_TYPE_H_
#define __PY_TYPE_H_

#include <glib.h>

namespace PY {

#define PINYIN_ID_VOID  (-1)
#define PINYIN_ID_ZERO  (0)
#define PINYIN_ID_B     (1)
#define PINYIN_ID_C     (2)
#define PINYIN_ID_CH    (3)
#define PINYIN_ID_D     (4)
#define PINYIN_ID_F     (5)
#define PINYIN_ID_G     (6)
#define PINYIN_ID_H     (7)
#define PINYIN_ID_J     (8)
#define PINYIN_ID_K     (9)
#define PINYIN_ID_L     (10)
#define PINYIN_ID_M     (11)
#define PINYIN_ID_N     (12)
#define PINYIN_ID_P     (13)
#define PINYIN_ID_Q     (14)
#define PINYIN_ID_R     (15)
#define PINYIN_ID_S     (16)
#define PINYIN_ID_SH    (17)
#define PINYIN_ID_T     (18)
#define PINYIN_ID_W     (19)
#define PINYIN_ID_X     (20)
#define PINYIN_ID_Y     (21)
#define PINYIN_ID_Z     (22)
#define PINYIN_ID_ZH    (23)
#define PINYIN_ID_A     (24)
#define PINYIN_ID_AI    (25)
#define PINYIN_ID_AN    (26)
#define PINYIN_ID_ANG   (27)
#define PINYIN_ID_AO    (28)
#define PINYIN_ID_E     (29)
#define PINYIN_ID_EI    (30)
#define PINYIN_ID_EN    (31)
#define PINYIN_ID_ENG   (32)
#define PINYIN_ID_ER    (33)
#define PINYIN_ID_I     (34)
#define PINYIN_ID_IA    (35)
#define PINYIN_ID_IAN   (36)
#define PINYIN_ID_IANG  (37)
#define PINYIN_ID_IAO   (38)
#define PINYIN_ID_IE    (39)
#define PINYIN_ID_IN    (40)
#define PINYIN_ID_ING   (41)
#define PINYIN_ID_IONG  (42)
#define PINYIN_ID_IU    (43)
#define PINYIN_ID_O     (44)
#define PINYIN_ID_ONG   (45)
#define PINYIN_ID_OU    (46)
#define PINYIN_ID_U     (47)
#define PINYIN_ID_UA    (48)
#define PINYIN_ID_UAI   (49)
#define PINYIN_ID_UAN   (50)
#define PINYIN_ID_UANG  (51)
#define PINYIN_ID_UE    (52)
#define PINYIN_ID_UI    (53)
#define PINYIN_ID_UN    (54)
#define PINYIN_ID_UO    (55)
#define PINYIN_ID_V     (56)
#define PINYIN_ID_NG    PINYIN_ID_VOID

#define PINYIN_SIMPLE_PINYIN        (1 << 0)

#define PINYIN_CORRECT_GN_TO_NG     (1 << 1)
#define PINYIN_CORRECT_MG_TO_NG     (1 << 2)
#define PINYIN_CORRECT_IOU_TO_IU    (1 << 3)
#define PINYIN_CORRECT_UEI_TO_UI    (1 << 4)
#define PINYIN_CORRECT_UEN_TO_UN    (1 << 5)
#define PINYIN_CORRECT_VE_TO_UE     (1 << 6)
#define PINYIN_CORRECT_ALL          (0x0000007e)

#define PINYIN_FUZZY_C_CH           (1 << 7)
#define PINYIN_FUZZY_CH_C           (1 << 8)
#define PINYIN_FUZZY_Z_ZH           (1 << 9)
#define PINYIN_FUZZY_ZH_Z           (1 << 10)
#define PINYIN_FUZZY_S_SH           (1 << 11)
#define PINYIN_FUZZY_SH_S           (1 << 12)
#define PINYIN_FUZZY_L_N            (1 << 13)
#define PINYIN_FUZZY_N_L            (1 << 14)
#define PINYIN_FUZZY_F_H            (1 << 15)
#define PINYIN_FUZZY_H_F            (1 << 16)
#define PINYIN_FUZZY_L_R            (1 << 17)
#define PINYIN_FUZZY_R_L            (1 << 18)
#define PINYIN_FUZZY_K_G            (1 << 19)
#define PINYIN_FUZZY_G_K            (1 << 20)

#define PINYIN_FUZZY_AN_ANG         (1 << 21)
#define PINYIN_FUZZY_ANG_AN         (1 << 22)
#define PINYIN_FUZZY_EN_ENG         (1 << 23)
#define PINYIN_FUZZY_ENG_EN         (1 << 24)
#define PINYIN_FUZZY_IN_ING         (1 << 25)
#define PINYIN_FUZZY_ING_IN         (1 << 26)
#define PINYIN_FUZZY_IAN_IANG       (1 << 27)
#define PINYIN_FUZZY_IANG_IAN       (1 << 28)
#define PINYIN_FUZZY_UAN_UANG       (1 << 29)
#define PINYIN_FUZZY_UANG_UAN       (1 << 30)
#define PINYIN_FUZZY_ALL            (0x7fffff10)

typedef struct _Pinyin Pinyin;
struct _Pinyin {
    const char *text;
    const char *sheng;
    const char *yun;
    const char  sheng_id;
    const char  yun_id;
    const char  fsheng_id;
    const char  fyun_id;
    const char  fsheng_id_2;
    const char  fyun_id_2;
    const int   len;
    const int   flags;
};

#define MAX_UTF8_LEN 6
#define MAX_PHRASE_LEN 16

typedef struct _Phrase Phrase;
struct _Phrase {
    gchar phrase[(MAX_PHRASE_LEN + 1) * MAX_UTF8_LEN];
    guint  freq;
    guint  user_freq;
    guint  pinyin_id[MAX_PHRASE_LEN][2];
    guint  len;
};

};

#endif
