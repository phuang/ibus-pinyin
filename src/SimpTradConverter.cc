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
#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include "SimpTradConverter.h"

#include <cstdlib>
#include <glib-object.h>

#ifdef HAVE_OPENCC
#  include <opencc.h>
#else
#  include <cstring>
#endif

#include "Types.h"
#include "String.h"

namespace PY {
#ifndef HAVE_OPENCC
#include "SimpTradConverterTable.h"
#endif

#ifdef HAVE_OPENCC

void
SimpTradConverter::simpToTrad (const gchar *in, String &out)
{
    static opencc::converter conv (OPENCC_CONVERT_SIMP_TO_TRAD);
    static std::wstring outbuf;

    gunichar *in_ucs4 = g_utf8_to_ucs4_fast (in, -1, NULL);

    if (conv.convert ((wchar_t*) in_ucs4, outbuf) < 0)
    {
        g_warning ("An error occurs in SimpTradConverter:");
        conv.perror ();
        return;
    }

    out << (const gunichar *) outbuf.c_str ();
    g_free (in_ucs4);
}

#else

static gint _xcmp (const gchar *p1, const gchar *p2, const gchar *str)
{
    for (;;) {
        // both reach end
        if (p1 == p2 && *str == '\0')
            return 0;
        // p1 reaches end
        if (p1 == p2)
            return -1;
        // str reaches end
        if (*str == '\0')
            return 1;

        if (*p1 < *str)
            return -1;
        if (*p1 > *str)
            return 1;

        p1 ++; str ++;
    };
}

static gint _cmp (gconstpointer p1, gconstpointer p2)
{
    const gchar **pp = (const gchar **) p1;
    const gchar **s2 = (const gchar **) p2;

    return _xcmp (pp[0], pp[1], s2[0]);
}

void
SimpTradConverter::simpToTrad (const gchar *in, String &out)
{
    const gchar *pend;
    const gchar *pp[2];
    glong len;
    glong begin;

    if (!g_utf8_validate (in, -1 , NULL)) {
        g_warning ("\%s\" is not an utf8 string!", in);
        g_assert_not_reached ();
    }

    begin = 0;
    pend = in + std::strlen (in);
    len = g_utf8_strlen (in, -1);   // len in charactoers
    pp[0] = in;

    while (pp[0] != pend) {
        glong slen  = std::min (len - begin, (glong) SIMP_TO_TRAD_MAX_LEN); // the length of sub string in character
        pp[1] = g_utf8_offset_to_pointer (pp[0], slen);    // the end of sub string

        for (;;) {
            const gchar **result;
            result = (const gchar **) std::bsearch (pp, simp_to_trad,
                                            G_N_ELEMENTS (simp_to_trad), sizeof (simp_to_trad[0]),
                                            _cmp);

            if (result != NULL) {
                // found item in table,
                // append the trad to out and adjust pointers
                out << result[1];
                pp[0] = pp[1];
                begin += slen;
                break;
            }

            if (slen == 1) {
                // if only one character left,
                // append origin character to out and adjust pointers
                out.append (pp[0], pp[1] - pp[0]);
                pp[0] = pp[1];
                begin += 1;
                break;
            }

            // if more than on characters left,
            // adjust pp[1] to previous character
            pp[1] = g_utf8_prev_char (pp[1]);
            slen--;
        }
    }
}
#endif

}
