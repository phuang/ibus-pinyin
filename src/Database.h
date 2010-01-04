/* vim:set et sts=4: */
#ifndef __PY_DATABASE_H__
#define __PY_DATABASE_H__

#include <sqlite3.h>
#include <string>
#include <vector>
#include <sstream>
#include "String.h"
#include "Types.h"
#include "PinyinArray.h"
#include "PhraseArray.h"

namespace PY {

using namespace std;

class Conditions : public vector<string> {
public:
    Conditions (void) :
        vector<string> (32),
        m_length (0) {
        reset ();
    }
    ~Conditions (void) {
    }
    guint length (void) { return m_length; }
    void reset (void) {
        m_length = 1;
        operator[](0) = "";
    }
    void _double (void) {
        for (gint i = m_length - 1; i >= 0; i--) {
            (*this)[m_length + i] = (*this)[i];
        }
        m_length = m_length + m_length;
    }
    void triple (void) {
        for (gint i = m_length - 1; i >= 0; i--) {
            operator[](m_length + i) = operator[]((m_length << 1) + i) = operator[](i);
        }
        m_length = m_length + m_length + m_length;
    }
    void appendVPrintf (gint begin, gint end, const gchar *fmt, va_list args) {
        gchar str[64];
        g_vsnprintf (str, sizeof(str), fmt, args);
        for (gint i = begin; i < end; i++) {
            operator[](i) += str;
        }
    }
    void appendPrintf (gint begin, gint end, const gchar *fmt, ...) {
        va_list args;
        va_start (args, fmt);
        appendVPrintf (begin, end, fmt, args);
        va_end (args);
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
    gboolean executeSQL (const gchar *sql);

private:
    sqlite3 *m_db;              /* sqlite3 database */
    String m_sql;               /* sql stmt */
    String m_buffer;            /* temp buffer */
    Conditions m_conditions;    /* select conditions */
};


};

#endif
