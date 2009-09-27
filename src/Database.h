/* vim:set et sts=4: */
#ifndef __PY_DATABASE_H__
#define __PY_DATABASE_H__

#include <sqlite3.h>
#include "Types.h"
#include "Array.h"
#include "String.h"
#include "PinyinArray.h"
#include "PhraseArray.h"

namespace PY {

class Conditions : public Array<String *> {
public:
    Conditions (void)
        : Array<String *> (32),
          m_length (0) {
        reset ();
    }
    ~Conditions (void) {
        for (guint i = 0; i < Array<String *>::length (); i++) {
            delete get (i);
        }
    }
    guint length (void) { return m_length; }
    void reset (void) {
        m_length = 0;
        newString ();
    }
    void _double (void) {
        for (guint i = m_length - 1; i >= 0; i--) {
            String *str = newString ();
            *str = *get (i);
        }
    }
    void triple (void) {
        for (guint i = m_length - 1; i >= 0; i--) {
            String *str1 = newString ();
            String *str2 = newString ();
            *str1 = *str2 = *get (i);
        }
    }
    void appendVPrintf (gint begin, gint end, const gchar *fmt, va_list args) {
        gchar str[64];
        g_vsnprintf (str, sizeof(str), fmt, args);
        for (gint i = begin; i < end; i++) {
            (*get (i)) << str;
        }
    }
    void appendPrintf (gint begin, gint end, const gchar *fmt, ...) {
        va_list args;
        va_start (args, fmt);
        appendVPrintf (begin, end, fmt, args);
        va_end (args);
    }
private:
    String *newString (void) {
        String *newstr;
        if (m_length < Array<String *>::length ()) {
            newstr = get (m_length);
            newstr->truncate (0);
        }
        else {
            newstr = new String (256);
            append (newstr);
        }
        m_length ++;
        return newstr;
    }
private:
    guint m_length;
};

class Database {
public:
    Database ();
    ~Database ();
    gint query (const PinyinArray   & pinyin,
                guint                 m,
                guint                 option,
                PhraseArray         & result);

    gint query (const PinyinArray   & pinyin,
                guint                 pinyin_begin,
                guint                 pinyin_len,
                gint                  m,
                guint                 option,
                PhraseArray         & result);
    void commit (const PhraseArray  & phrases);
    void remove (const Phrase & phrase);

    void conditionsDouble (void);
    void conditionsTriple (void);

private:
    gboolean init (void);
    gboolean initUserDatabase (const gchar *userdb);
    void prefetch (void);
    void phraseSql (const Phrase & p, String & sql);
    void phraseWhereSql (const Phrase & p, String & sql);

private:
private:
    sqlite3 *m_db;                  /* sqlite3 database */
    String   m_sql;                 /* sql stmt */
    String   m_buffer;              /* temp buffer */
    Conditions m_conditions;        /* select conditions */
};


};

#endif
