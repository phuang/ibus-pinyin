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
#ifndef __PY_POINTER_H_
#define __PY_POINTER_H_

#include <glib-object.h>

namespace PY {

template<typename T>
struct Pointer {
public:
    Pointer (T *p = NULL) : m_p (NULL) {
        set (p);
    }

    ~Pointer (void) {
        set (NULL);
    }

    void set (T * p) {
        if (m_p) {
            g_object_unref (m_p);
        }

        m_p = p;
        if (p) {
	#if 0
            g_debug ("%s, floating = %d",G_OBJECT_TYPE_NAME (p), g_object_is_floating (p));
	#endif
            g_object_ref_sink (p);
        }
    }

    Pointer<T> &operator = (T *p) {
        set (p);
        return *this;
    }

    Pointer<T> &operator = (const Pointer<T> & p) {
        set (p.m_p);
        return *this;
    }

    const T * operator-> (void) const {
        return m_p;
    }

    T * operator-> (void) {
        return m_p;
    }

    operator T * (void) const {
        return m_p;
    }

    operator gboolean (void) const {
        return m_p != NULL;
    }

private:
    T *m_p;
};

};

#endif
