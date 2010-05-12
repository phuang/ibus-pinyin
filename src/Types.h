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
#define PINYIN_ID_VE    PINYIN_ID_UE
#define PINYIN_ID_UI    (53)
#define PINYIN_ID_UN    (54)
#define PINYIN_ID_UO    (55)
#define PINYIN_ID_V     (56)
#define PINYIN_ID_NG    PINYIN_ID_VOID

#define PINYIN_INCOMPLETE_PINYIN    (1U << 0)

#define PINYIN_CORRECT_GN_TO_NG     (1U << 1)
#define PINYIN_CORRECT_MG_TO_NG     (1U << 2)
#define PINYIN_CORRECT_IOU_TO_IU    (1U << 3)
#define PINYIN_CORRECT_UEI_TO_UI    (1U << 4)
#define PINYIN_CORRECT_UEN_TO_UN    (1U << 5)
#define PINYIN_CORRECT_UE_TO_VE     (1U << 6)
#define PINYIN_CORRECT_V_TO_U       (1U << 7)
#define PINYIN_CORRECT_ALL          (0x000000fe)

#define PINYIN_FUZZY_C_CH           (1U << 8)
#define PINYIN_FUZZY_CH_C           (1U << 9)
#define PINYIN_FUZZY_Z_ZH           (1U << 10)
#define PINYIN_FUZZY_ZH_Z           (1U << 11)
#define PINYIN_FUZZY_S_SH           (1U << 12)
#define PINYIN_FUZZY_SH_S           (1U << 13)
#define PINYIN_FUZZY_L_N            (1U << 14)
#define PINYIN_FUZZY_N_L            (1U << 15)
#define PINYIN_FUZZY_F_H            (1U << 16)
#define PINYIN_FUZZY_H_F            (1U << 17)
#define PINYIN_FUZZY_L_R            (1U << 18)
#define PINYIN_FUZZY_R_L            (1U << 19)
#define PINYIN_FUZZY_K_G            (1U << 20)
#define PINYIN_FUZZY_G_K            (1U << 21)

#define PINYIN_FUZZY_AN_ANG         (1U << 22)
#define PINYIN_FUZZY_ANG_AN         (1U << 23)
#define PINYIN_FUZZY_EN_ENG         (1U << 24)
#define PINYIN_FUZZY_ENG_EN         (1U << 25)
#define PINYIN_FUZZY_IN_ING         (1U << 26)
#define PINYIN_FUZZY_ING_IN         (1U << 27)
#define PINYIN_FUZZY_IAN_IANG       (1U << 28)
#define PINYIN_FUZZY_IANG_IAN       (1U << 29)
#define PINYIN_FUZZY_UAN_UANG       (1U << 30)
#define PINYIN_FUZZY_UANG_UAN       (1U << 31)
#define PINYIN_FUZZY_ALL            (0xffffff00)

struct Pinyin {
    const gchar *text;
    const gchar *bopomofo;
    const gchar *sheng;
    const gchar *yun;
    const gchar  sheng_id;
    const gchar  yun_id;
    const gchar  fsheng_id;
    const gchar  fyun_id;
    const gchar  fsheng_id_2;
    const gchar  fyun_id_2;
    const guint  len;
    const guint  flags;
};

#define MAX_UTF8_LEN 6
#define MAX_PHRASE_LEN 16

};

#endif
