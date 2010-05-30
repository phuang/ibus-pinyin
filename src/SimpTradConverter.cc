/* vim:set et ts=4 sts=4:
 *
 * ibus-pinyin - The Chinese PinYin engine for IBus
 *
 * Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#include <cstdlib>
#include <cwchar>
#include <glib-object.h>
#include "SimpTradConverter.h"

namespace PY {
#include "SimpTradConverterTable.h"

static int _cmp (const void *p1, const void *p2)
{
    const wchar_t *s1 = (const wchar_t *) p1;
    const wchar_t **s2 = (const wchar_t **) p2;

    return std::wcscmp (s1, s2[0]);
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
            result = (const gunichar **) std::bsearch (buf, simp_to_trad,
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
