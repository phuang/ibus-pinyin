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
};


};

#endif
