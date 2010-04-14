#ifndef __PY_REGEX_H_
#define __PY_REGEX_H_

#include <sys/types.h>
#include <regex.h>
#include <glib.h>

namespace PY {

class Regex {
public:
    Regex (const gchar *regex, gint cflags = REG_EXTENDED) {
        int retval;
        retval = regcomp (&m_regex, regex, cflags);
        if (retval != 0) {
            gchar errorbuf[128];
            regerror (retval, &m_regex, errorbuf, sizeof (errorbuf));
            g_debug ("regex error: %s", errorbuf);
            g_assert_not_reached ();
        }
    }

    ~Regex (void) {
        regfree (&m_regex);
    }

    gboolean match (const gchar *str) const {
        int retval;
        regmatch_t match;
        retval = regexec (&m_regex, str, 1, &match, 0);
        return retval == 0;
    }

    gboolean operator & (const gchar *str) const {
        return match (str);
    }

private:
    regex_t m_regex;
};

};

#endif
