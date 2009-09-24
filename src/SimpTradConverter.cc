#include <stdlib.h>
#include <glib.h>
#include "SimpTradConverter.h"

namespace PY {
#include "SimpTradConverterTable.h"


static int _cmp (const void *p1, const void * p2) {
    const gunichar *s1 = (const gunichar *) p1;
    const gunichar *s2 = (const gunichar *) p2;

    return *s1 - *s2;
}

void
SimpTradConverter::simpToTrad (const gchar *in, String &out)
{
    if (!g_utf8_validate (in, -1 , NULL)) {
        g_debug ("\%s\" is not an utf8 string!", in);
        g_assert_not_reached ();
    }

    for (const gchar *p = in; *p != '\0'; p = g_utf8_next_char (p)) {
        gunichar s = g_utf8_get_char (p);
        const gunichar *result = (const gunichar *) bsearch (&s, simp_to_trad, SIMP_TO_TRAD_NR,
                                            sizeof (simp_to_trad[0]), _cmp);
        if (G_UNLIKELY (result == NULL))
            out.appendUnichar (s);
        else
            out.appendUnichar (result[1]);
    }

}

}
