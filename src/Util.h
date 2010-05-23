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
#ifndef __PY_UTIL_H_
#define __PY_UTIL_H_

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#if defined(HAVE_UUID_CREATE)
#  include <uuid.h>
#elif defined(HAVE_LIBUUID)
#  include <uuid/uuid.h>
#endif

#include <sys/utsname.h>
#include <cstdlib>
#include <string>

namespace PY {

#define CMSHM_MASK              \
        (IBUS_CONTROL_MASK |    \
         IBUS_MOD1_MASK |       \
         IBUS_SUPER_MASK |      \
         IBUS_HYPER_MASK |      \
         IBUS_META_MASK)

#define CMSHM_FILTER(modifiers)  \
    (modifiers & (CMSHM_MASK))

class UUID {
public:
    UUID (void) {
        uuid_t u;
#if defined(HAVE_UUID_CREATE)
        gchar* uuid;
        uuid_create (&u, 0);
        uuid_to_string (&u, &uuid, 0);
        g_strlcpy (m_uuid, uuid, sizeof(m_uuid));
        free(uuid);
#elif defined(HAVE_LIBUUID)
        uuid_generate (u);
        uuid_unparse_lower (u, m_uuid);
#endif
    }

    operator const gchar * (void) const {
        return m_uuid;        
    }

private:
    gchar m_uuid[256];
};

class Uname {
public:
    Uname (void) {
        uname (&m_buf);
    }

    const gchar *hostname (void) const { return m_buf.nodename; }
private:
    struct utsname m_buf;
};

class Hostname : public Uname {
public:
    operator const gchar * (void) const {
        return hostname ();
    }
};

class Env : public std::string {
public:
    Env (const gchar *name) {
        gchar *str;
        str = std::getenv (name);
        assign (str != NULL ? str : "");
    }

    operator const gchar *(void) const {
        return c_str();
    }
};

};
#endif
