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
#ifndef __PY_REGEX_H_
#define __PY_REGEX_H_

#include <sys/types.h>
#include <regex.h>
#include <glib.h>

namespace PY {

class Regex {
public:
    Regex (const gchar *regex, gint cflags = REG_EXTENDED)
    {
        int retval;
        retval = regcomp (&m_regex, regex, cflags);
        if (retval != 0) {
            gchar errorbuf[128];
            regerror (retval, &m_regex, errorbuf, sizeof (errorbuf));
            g_debug ("regex error: %s", errorbuf);
            g_assert_not_reached ();
        }
    }

    ~Regex (void)
    {
        regfree (&m_regex);
    }

    gboolean match (const gchar *str) const
    {
        int retval;
        regmatch_t match;
        retval = regexec (&m_regex, str, 1, &match, 0);
        return retval == 0;
    }

    gboolean operator & (const gchar *str) const
    {
        return match (str);
    }

private:
    regex_t m_regex;
};

};

#endif
