/* vim:set et sts=4: */
#include <string.h>
#include <stdlib.h>
#include <glib.h>
#include "PinyinParser.h"

namespace PY {

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

    return strcmp (str, py->text);
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
        strncpy (buf, p, len);
        buf[len] = 0;
        result = (const Pinyin *) bsearch (buf, pinyin_table, PINYIN_TABLE_NR,
                                            sizeof (Pinyin), py_cmp);
        if (check_flags (result, option))
            return result;
        return NULL;
    }

    len = strnlen (p, 6);
    len = MIN (len, end - p);
    strncpy (buf, p, len);

    for (; len > 0; len --) {
        buf[len] = 0;
        result = (const Pinyin *) bsearch (buf, pinyin_table, PINYIN_TABLE_NR,
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

    return ((pys[0] - e[0]) << 16) + (pys[1] - e[1]);
}

static const Pinyin **
need_resplit(const Pinyin *p1,
             const Pinyin *p2)
{
    const Pinyin * pys[] = {p1, p2};

    return (const Pinyin **) bsearch (pys, special_table, SPECIAL_TABLE_NR,
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

    result.removeAll ();

    if (G_UNLIKELY (len < 0))
        len = pinyin.length ();

    p = pinyin;
    end = p + len;

    prev_py = NULL;

    prev_c = 0;
    for (; p < end && result.length () < max; ) {
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
                            PinyinSegment & segment = result[result.length () - 1];
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
                        PinyinSegment & segment = result[result.length () - 1];
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

static const gchar *id_map[] = {
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
    "ue", "ui", "un", "uo", "v"
};

const Pinyin *
PinyinParser::isPinyin (gint sheng, gint yun, guint option)
{
    const Pinyin *result;
    gchar buf[8];

    g_strlcpy (buf, id_map[sheng], sizeof (buf));
    g_strlcat (buf, id_map[yun], sizeof (buf));

    result = (const Pinyin *) bsearch (buf, pinyin_table, PINYIN_TABLE_NR,
                                            sizeof (Pinyin), py_cmp);
    if (check_flags (result, option))
        return result;
    return NULL;
}

};

