/* vim:set et sts=4: */

#include <cstring>
#include <cstdlib>
#include <glib.h>
#include "PinyinParser.h"

namespace PY {

#include "Bopomofo.h"
#include "PinyinParserTable.h"

static gboolean
check_flags (const Pinyin *pinyin, guint option)
{
    if (pinyin == NULL)
        return FALSE;

    if (pinyin->flags != 0) {
        guint flags;
        flags = pinyin->flags & option;
        if (flags == 0)
            return FALSE;
        if ((flags != pinyin->flags) && ((pinyin->flags & PINYIN_CORRECT_ALL) != 0))
            return FALSE;
    }
    return TRUE;
}

static int
py_cmp (const void *p1, const void *p2)
{
    const gchar *str = (const gchar *) p1;
    const Pinyin *py = (const Pinyin *) p2;

    return std::strcmp (str, py->text);
}

static const Pinyin *
is_pinyin (const gchar *p,
           const gchar *end,
           gint         len,
           guint        option)
{
    gchar buf[8];
    const Pinyin *result;

    if (G_UNLIKELY (len > 6))
        return NULL;

    if (G_UNLIKELY (len > end - p))
        return NULL;

    if (G_LIKELY (len > 0)) {
        std::strncpy (buf, p, len);
        buf[len] = 0;
        result = (const Pinyin *) std::bsearch (buf, pinyin_table, G_N_ELEMENTS (pinyin_table),
                                            sizeof (Pinyin), py_cmp);
        if (check_flags (result, option))
            return result;
        return NULL;
    }

    /* len < 0 */
    len = MIN (6, end - p);
    std::strncpy (buf, p, len);

    for (; len > 0; len --) {
        buf[len] = 0;
        result = (const Pinyin *) std::bsearch (buf, pinyin_table, G_N_ELEMENTS (pinyin_table),
                                            sizeof (Pinyin), py_cmp);
        if (G_UNLIKELY (check_flags (result, option))) {
            return result;
        }
    }

    return NULL;
}

static int
sp_cmp (const void *p1,
        const void *p2)
{
    const Pinyin **pys = (const Pinyin **) p1;
    const Pinyin **e = (const Pinyin **) p2;

    int retval = pys[0] - e[0];

    if (retval != 0)
        return retval;
    return pys[1] - e[1];
}

static const Pinyin **
need_resplit(const Pinyin *p1,
             const Pinyin *p2)
{
    const Pinyin * pys[] = {p1, p2};

    return (const Pinyin **) std::bsearch (pys, special_table, G_N_ELEMENTS (special_table),
                                        sizeof (special_table[0]), sp_cmp);
}

guint
PinyinParser::parse (const String   &pinyin,
                     gint            len,
                     guint           option,
                     PinyinArray    &result,
                     guint           max)
{

    const gchar *p;
    const gchar *end;
    const Pinyin *py;
    const Pinyin *prev_py;
    gchar prev_c;

    result.clear ();

    if (G_UNLIKELY (len < 0))
        len = pinyin.size ();

    p = pinyin;
    end = p + len;

    prev_py = NULL;

    prev_c = 0;
    for (; p < end && result.size () < max; ) {
        switch (prev_c) {
        case 'r':
        case 'n':
        case 'g':
        case 'e':
            switch (*p) {
            case 'i':
            case 'u':
            case 'v':
            case 'a':
            case 'e':
            case 'o':
            case 'r':
                {
                    const Pinyin **pp;
                    const Pinyin *new_py1;
                    const Pinyin *new_py2;

                    py = is_pinyin (p, end, -1, option);

                    if ((new_py1 = is_pinyin (prev_py->text,
                                              prev_py->text + prev_py->len,
                                              prev_py->len - 1,
                                              option)) != NULL) {
                        new_py2 = is_pinyin (p -1, end, -1, option);

                        if (((new_py2 != NULL) && (new_py2->len > 1 )) &&
                            (py == NULL || new_py2->len > py->len + 1)) {
                            PinyinSegment & segment = result[result.size () - 1];
                            segment.pinyin = new_py1;
                            segment.len = new_py1->len;
                            py = new_py2;
                            p --;
                            break;
                        }
                    }

                    if ( py == NULL)
                        break;

                    pp = need_resplit (prev_py, py);
                    if (pp != NULL) {
                        PinyinSegment & segment = result[result.size () - 1];
                        segment.pinyin = pp[2];
                        segment.len = pp[2]->len;
                        py = pp[3];
                        p --;
                        break;
                    }
                }
            default:
                py = is_pinyin (p, end, -1, option);
                break;
            }
            break;
        default:
            py = is_pinyin (p, end, -1, option);
            break;
        }

        if (G_UNLIKELY (py == NULL))
            break;

        result.append (py, p - (const gchar *) pinyin, py->len);
        p += py->len;
        prev_c = py->text[py->len - 1];
        prev_py = py;

        if (G_UNLIKELY (*p == '\'')) {
            prev_c = '\'';
            p++;
        }
    }

    if (G_UNLIKELY (p == (const gchar *)pinyin))
        return 0;
#if 0
    if (G_UNLIKELY (*(p - 1) == '\''))
        p --;
#endif
    return p - (const gchar *)pinyin;
}

static const gchar * const
id_map[] = {
    "", "b", "c", "ch",
    "d", "f", "g", "h",
    "j", "k", "l", "m",
    "n", "p", "q", "r",
    "s", "sh", "t", "w",
    "x", "y", "z", "zh",
    "a", "ai", "an", "ang", "ao",
    "e", "ei", "en", "eng", "er",
    "i", "ia", "ian", "iang", "iao",
    "ie", "in", "ing", "iong", "iu",
    "o", "ong", "ou",
    "u", "ua", "uai", "uan", "uang",
    0, /* it should be ue or ve */
    "ui", "un", "uo", "v"
};

const Pinyin *
PinyinParser::isPinyin (gint sheng, gint yun, guint option)
{
    const Pinyin *result;
    gchar buf[16];

    std::strcpy (buf, id_map[sheng]);

    if (yun == PINYIN_ID_UE) {
        /* append ue or ve base on sheng */
        switch (sheng) {
        case PINYIN_ID_J:
        case PINYIN_ID_Q:
        case PINYIN_ID_X:
        case PINYIN_ID_Y:
            std::strcat (buf, "ue");
            break;
        default:
            std::strcat (buf, "ve");
            break;
        }
    }
    else {
        std::strcat (buf, id_map[yun]);
    }

    result = (const Pinyin *) bsearch (buf, pinyin_table, G_N_ELEMENTS (pinyin_table),
                                            sizeof (Pinyin), py_cmp);
    if (check_flags (result, option))
        return result;
    return NULL;
}

static int
bopomofo_cmp (const void *p1, const void *p2)
{
    const wchar_t *s1 = (wchar_t *) p1;
    const Pinyin *s2 = *(const Pinyin **) p2;

    return std::wcscmp (s1,s2->bopomofo);
}

gboolean
PinyinParser::isBopomofoToneChar (const wchar_t ch)
{
    return ch == bopomofo_char[BOPOMOFO_TONE_2]
        || ch == bopomofo_char[BOPOMOFO_TONE_3]
        || ch == bopomofo_char[BOPOMOFO_TONE_4]
        || ch == bopomofo_char[BOPOMOFO_TONE_5];
}

guint
PinyinParser::parseBopomofo (const std::wstring   &bopomofo,
                             gint            len,
                             guint           option,
                             PinyinArray    &result,
                             guint           max)
{
    std::wstring::const_iterator bpmf = bopomofo.begin();
    const std::wstring::const_iterator end = bpmf + len;
    const Pinyin **bs_res;
    wchar_t buf[MAX_BOPOMOFO_LEN + 1];
    gint i,j;

    result.clear ();

    if (G_UNLIKELY (len < 0))
        len = bopomofo.length();

    for (; bpmf < end && result.size () < max; ) {
        for (i = MAX_BOPOMOFO_LEN; i>0; i--){
            if (bpmf + i > end)
                continue;

            for (j=0;j<i;j++){
                wchar_t key = *(bpmf+j);

                if (j == i-1 && isBopomofoToneChar(key)) {
                    break; /* ignore tone */
                }

                buf[j] = key;
            }

            buf[j] = '\0';
            bs_res = (const Pinyin **) std::bsearch (buf, bopomofo_table,
                                                  G_N_ELEMENTS (bopomofo_table),
                                                  sizeof(bopomofo_table[0]),
                                                  bopomofo_cmp);
            if (bs_res != NULL && check_flags (*bs_res, option))
                break;
        }
        if (!(bs_res != NULL && check_flags (*bs_res, option)))
            break;
        result.append(*bs_res,bpmf - bopomofo.begin() ,(*bs_res)->len);
        bpmf += i;
    }

    return bpmf - bopomofo.begin();
};

};
