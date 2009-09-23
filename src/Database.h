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

    String *string (guint i) {
        guint j;
        for (j = m_strings.length (); j <= i; j++) {
            m_strings.append (new String (256));
        }
        return &(m_strings[i]->truncate (0));
    }

    void conditionsDouble (void);
    void conditionsTriple (void);

private:
    gboolean init (void);
    gboolean initUserDatabase (const gchar *userdb);
    void prefetch (void);
    void phraseSql (const Phrase & p, String & sql);
    void phraseWhereSql (const Phrase & p, String & sql);

private:
    sqlite3 *m_db;                  /* sqlite3 database */
    String   m_sql;                 /* sql stmt */
    String   m_buffer;              /* temp buffer */
    Array<String *> m_conditions;   /* select conditions */
    Array<String *> m_strings;      /* strings */
};

};

#endif
