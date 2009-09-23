#ifndef __PY_STRING_H_
#define __PY_STRING_H_
#include <glib.h>
#include <stdarg.h>

namespace PY {

class String {
public:
    String (const gchar *init) {
        m_string = g_string_new (init);
    }

    String (const gchar *init, gssize len) {
        m_string = g_string_new_len (init, len);
    }

    String (gsize init_size = 0) {
        m_string = g_string_sized_new (init_size);
    }

    ~String (void) {
        g_string_free (m_string, TRUE);
    }

    gsize length (void) const {
        return m_string->len;
    }

    gsize utf8Length (void) const {
        return g_utf8_strlen (m_string->str, m_string->len);
    }

    gboolean isEmpty (void) const {
        return m_string->len == 0;
    }

    String & assign (const gchar *str) {
        g_string_assign (m_string, str);
        return *this;
    }

    String & assign (const String &str) {
        return assign ((const gchar *) str);
    }

    String & insert (gint pos, gchar ch) {
        g_string_insert_c (m_string, pos, ch);
        return *this;
    }

    String & append (const gchar *str) {
        g_string_append (m_string, str);
        return *this;
    }

    String & appendUnichar (gunichar ch) {
        g_string_append_unichar (m_string, ch);
        return *this;
    }

    String & append (const gchar *str, gint len) {
        g_string_append_len (m_string, str, len);
        return *this;
    }

    String & printf (const gchar *fmt, ...) {
        va_list args;

        va_start (args, fmt);
        g_string_vprintf (m_string, fmt, args);
        va_end (args);

        return *this;
    }

    String & appendPrintf (const gchar *fmt, ...) {
        va_list args;

        va_start (args, fmt);
        g_string_append_vprintf (m_string, fmt, args);
        va_end (args);

        return *this;
    }

    String & truncate (gint len) {
        g_string_truncate (m_string, len);
        return *this;
    }

    String & erase (gint pos, gint len) {
        g_string_erase (m_string, pos, len);
        return *this;
    }

    String & operator = (const gchar *str) {
        return assign (str);
    }

    String & operator = (const String &str) {
        return assign (str);
    }

    String & operator += (const gchar *str) {
        return append (str);
    }

    String & operator << (const gchar *str) {
        return append (str);
    }

    String & operator << (const String &str) {
        return append ((const gchar *) str);
    }

    String & operator << (gint d) {
        g_string_append_printf (m_string, "%d", d);
        return *this;
    }

    String & operator << (guint d) {
        g_string_append_printf (m_string, "%u", d);
        return *this;
    }

    String & operator << (gchar ch) {
        g_string_append_c (m_string, ch);
        return *this;
    }

    gchar operator[] (guint i) {
        if (i >= length ())
            return 0;
        return m_string->str[i];
    }

    operator const gchar *() const {
        return m_string->str;
    }

    operator gboolean () const {
        return m_string->len != 0;
    }

private:
    GString *m_string;
};
};
#endif
