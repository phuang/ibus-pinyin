/* vim:set et sts=4: */
#ifndef __PY_DATABASE_H__
#define __PY_DATABASE_H__

#include <sqlite3.h>
#include <boost/shared_ptr.hpp>
#include "String.h"
#include "Types.h"
#include "PinyinArray.h"
#include "PhraseArray.h"

namespace PY {

class SQLStmt;
typedef boost::shared_ptr<SQLStmt> SQLStmtPtr;

class Database;

class Query {
public:
    Query (const PinyinArray    & pinyin,
           guint                  pinyin_begin,
           guint                  pinyin_len,
           guint                  option);
    ~Query (void);
    gint fill (PhraseArray &phrases, gint count);

private:
    const PinyinArray & m_pinyin;
    guint m_pinyin_begin;
    guint m_pinyin_len;
    guint m_option;
    SQLStmtPtr m_stmt;
};
typedef boost::shared_ptr<Query> QueryPtr;

class Database {
private:
    Database ();
    ~Database ();

public:
    SQLStmtPtr query (const PinyinArray   & pinyin,
                      guint                 pinyin_begin,
                      guint                 pinyin_len,
                      gint                  m,
                      guint                 option);
    void commit (const PhraseArray  & phrases);
    void remove (const Phrase & phrase);

    void conditionsDouble (void);
    void conditionsTriple (void);

    static Database & instance (void) {return m_instance; }

private:
    gboolean init (void);
    gboolean initUserDatabase (const gchar *userdb);
    void prefetch (void);
    void phraseSql (const Phrase & p, String & sql);
    void phraseWhereSql (const Phrase & p, String & sql);
    gboolean executeSQL (const gchar *sql);

private:
    sqlite3 *m_db;              /* sqlite3 database */

    String m_sql;        /* sql stmt */
    String m_buffer;     /* temp buffer */

private:
    static Database m_instance;
};


};

#endif
