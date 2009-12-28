#ifndef __PY_STRING_H_
#define __PY_STRING_H_
#include <glib.h>
#include <stdarg.h>
#include <string>


namespace PY {

class String : public std::string {
public:
    String () : std::string () {}
    String (gint len) : std::string () {}
    String & printf (const gchar *fmt, ...) {
        gchar *str;
        va_list args;

        va_start (args, fmt);
        str = g_strdup_vprintf (fmt, args);
        va_end (args);

        assign (str);
        g_free (str);
        return *this;
    }

    String & appendUnichar (gunichar ch) {
        gchar str[10];
        g_unichar_to_utf8 (ch, str);
        append (str);
        return *this;
    }

    String & appendPrintf (const gchar *fmt, ...) {
        gchar *str;
        va_list args;

        va_start (args, fmt);
        str = g_strdup_vprintf (fmt, args);
        va_end (args);

        append (str);
        g_free (str);

        return *this;
    }

    String & insert (gint i, gchar ch) {
        std::string::insert (i, 1, ch);
        return *this;
    }

    String & truncate (guint len) {
        erase(len);
        return *this;
    }

    gboolean isEmpty (void) const {
        return empty ();
    }

    gsize utf8Length (void) const {
        return g_utf8_strlen (c_str(), -1);
    }

    String & operator<< (gint i) {
        return appendPrintf ("%d", i);
    }

    String & operator<< (guint i) {
        return appendPrintf ("%u", i);
    }

    String & operator<< (const gchar ch) {
        append (1, ch);
        return *this;
    }

    String & operator<< (const gchar * str) {
        append (str);
        return *this;
    }

    String & operator << (const gunichar *wstr) {
        for (gint i = 0; wstr[i] != 0; i++)
            operator << (wstr[i]);
        return *this;
    }

    String & operator<< (const String &str) {
        return operator<< ((const gchar *)str);
    }

    String & operator= (const gchar * str) {
        assign (str);
        return *this;
    }

    operator const gchar *(void) const {
        return this->c_str ();
    }

    operator gboolean (void) const {
        return ! isEmpty ();
    }
};
#if 0
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

    String (const String &str) {
        m_string = g_string_sized_new (str.length () + 1);
        assign (str);
    }

    String (const WideString &wstr) {
        m_string = g_string_sized_new (wstr.length() * 6);
        assign (wstr);
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

    String & assign (const WideString &wstr) {
        truncate (0);
        return append (wstr);
    }

    String & insert (gint pos, gchar ch) {
        g_string_insert_c (m_string, pos, ch);
        return *this;
    }

    String & append (const gchar *str) {
        g_string_append (m_string, str);
        return *this;
    }

    String & append (const gunichar *wstr) {
        for (const gunichar *p = wstr; *p != 0; p++)
            appendUnichar (*p);
        return *this;
    }

    String & append (const WideString &wstr) {
        for (guint i = 0; i < wstr.length (); i++) {
            appendUnichar (wstr[i]);
        }
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

    String & operator = (const WideString &wstr) {
        return assign (wstr);
    }

    String & operator += (const gchar *str) {
        return append (str);
    }

    String & operator << (const gchar *str) {
        return append (str);
    }

    String & operator << (const gunichar *wstr) {
        return append (wstr);
    }

    String & operator << (const String &str) {
        return append ((const gchar *) str);
    }

    String & operator << (const WideString &wstr) {
        return append (wstr);
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
#endif
};
#endif
