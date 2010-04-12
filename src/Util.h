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
#include <stdlib.h>
#include "String.h"

namespace PY {

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

class Env : public String {
public:
    Env (const gchar *name) {
        gchar *str;
        str = getenv (name);
        assign (str != NULL ? str : "");
    }

    operator const gchar *(void) const {
        return c_str();
    }
};

class StaticString {
public:
    StaticString (const gchar *str) : m_string (str) {}

    gboolean equal (const gchar *str) const {
        return g_strcmp0 (m_string, str) == 0;
    }

    gboolean operator == (const gchar *str) const {
        return equal (str);
    }

    gboolean operator != (const gchar *str) const {
        return ! equal (str);
    }

    operator const gchar * (void) const {
        return m_string;
    }

private:
    const gchar *m_string;
};

};
#endif
