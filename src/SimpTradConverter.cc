#include <stdlib.h>
#include <wchar.h>
#include <glib.h>
#include <glib-object.h>
#include "SimpTradConverter.h"

namespace PY {
#include "SimpTradConverterTable.h"

static int _cmp (const void *p1, const void *p2)
{
    const wchar_t *s1 = (const wchar_t *) p1;
    const wchar_t **s2 = (const wchar_t **) p2;

    return wcscmp (s1, s2[0]);
}

void
SimpTradConverter::simpToTrad (const gchar *in, String &out)
{
    gunichar *p;
    gunichar *in_ucs4;
    gunichar buf[SIMP_TO_TRAD_MAX_LEN + 1];

    if (!g_utf8_validate (in, -1 , NULL)) {
        g_warning ("\%s\" is not an utf8 string!", in);
        g_assert_not_reached ();
    }

    p = in_ucs4 = g_utf8_to_ucs4_fast (in, -1, NULL);

    while (*p != 0) {
        guint i;
        const gunichar **result;
        for (i = 0; i < SIMP_TO_TRAD_MAX_LEN && p[i] != 0; i++) {
            buf[i] = p[i];
        }
        for (; i > 0; i--) {
            buf[i] = 0;
            result = (const gunichar **) bsearch (buf, simp_to_trad,
                                            G_N_ELEMENTS (simp_to_trad), sizeof (simp_to_trad[0]),
                                            _cmp);
            if (G_UNLIKELY (result != NULL))
                break;
        }
        if (result != NULL) {
            out << result[1];
            p += i;
        }
        else {
            out.appendUnichar(p[0]);
            p += 1;
        }
    }

    g_free (in_ucs4);
}

}
