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
#ifndef __PY_WIDE_STRING_H_
#define __PY_WIDE_STRING_H_

#if 0
#include <glib.h>
#include <stdarg.h>
#include "Array.h"

namespace PY {

class WideString {
public:
    WideString (const gchar *init) : m_string (g_utf8_strlen (init, -1) + 1) {
        assign (init);
    }

    WideString (const gchar *init, gssize len) : m_string (len) {
        assign (init);
    }

    WideString (gsize init_size = 0) : m_string (init_size) {
    }

    ~WideString (void) {
    }

    guint length (void) const {
        return m_string.length ();
    }

    gboolean isEmpty (void) const {
        return length () == 0;
    }

    WideString & assign (const gchar *str) {
        truncate (0);
        for (const gchar *p = str; *p != '\0'; p = g_utf8_next_char (p)) {
            append (g_utf8_get_char (p));
        }
        return *this;
    }

    WideString & insert (gint pos, gunichar ch) {
        m_string.insert (pos, ch);
        return *this;
    }

    WideString & append (const gchar *str) {
        for (const gchar *p = str; *p != '\0'; p = g_utf8_next_char (p)) {
            append (g_utf8_get_char (p));
        }
        return *this;
    }

    WideString & append (gunichar ch) {
        m_string.append (ch);
        return *this;
    }

    WideString & truncate (gint len) {
        m_string.setSize (len);
        return *this;
    }

    WideString & erase (gint pos, gint len) {
        m_string.remove (pos, len);
        return *this;
    }

    WideString & operator = (const gchar *str) {
        return assign (str);
    }

    WideString & operator += (const gchar *str) {
        return append (str);
    }

    WideString & operator << (const gchar *str) {
        return append (str);
    }

    WideString & operator << (gunichar ch) {
        append (ch);
        return *this;
    }

    WideString & operator << (gchar ch) {
        append (ch);
        return *this;
    }

    gunichar operator[] (guint i) const {
        if (i >= length ())
            return 0;
        return m_string[i];
    }

    operator gboolean () const {
        return length() > 0;
    }

private:
    Array<gunichar> m_string;
};
};
#endif
#endif
