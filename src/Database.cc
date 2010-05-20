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
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <glib.h>
#include <sqlite3.h>
#include "Database.h"
#include "Util.h"

namespace PY {

#define DB_CACHE_SIZE       "5000"
#define DB_INDEX_SIZE       (3)
/* define columns */
#define DB_COLUMN_USER_FREQ (0)
#define DB_COLUMN_PHRASE    (1)
#define DB_COLUMN_FREQ      (2)
#define DB_COLUMN_S0        (3)

#define DB_PREFETCH_LEN     (6)

Database Database::m_instance;

class Conditions : public std::vector<std::string> {
public:
    Conditions (void) : std::vector<std::string> (1) {}

    void double_ (void) {
        gint i = size ();
        do {
            push_back (at (--i));
        } while (i > 0);
    }

    void triple (void) {
        gint i = size ();
        do {
            const std::string & value = std::vector<std::string>::at (--i);
            push_back (value);
            push_back (value);
        } while (i > 0);
    }

    void appendVPrintf (gint begin, gint end, const gchar *fmt, va_list args) {
        gchar str[64];
        g_vsnprintf (str, sizeof(str), fmt, args);
        for (gint i = begin; i < end; i++) {
            at (i) += str;
        }
    }

    void appendPrintf (gint begin, gint end, const gchar *fmt, ...) {
        va_list args;
        va_start (args, fmt);
        appendVPrintf (begin, end, fmt, args);
        va_end (args);
    }
};

class SQLStmt {
public:
    SQLStmt (sqlite3 *db)
        : m_db (db), m_stmt (NULL) {
        g_assert (m_db != NULL);
    }

    ~SQLStmt () {
        if (m_stmt != NULL) {
            if (sqlite3_finalize (m_stmt) != SQLITE_OK) {
                g_warning ("destroy sqlite stmt failed!");
            }
        }
    }

    gboolean prepare (const String &sql) {
        if (sqlite3_prepare (m_db,
                             sql.c_str (),
                             sql.size (),
                             &m_stmt,
                             NULL) != SQLITE_OK) {
            g_warning ("parse sql failed!\n %s", sql.c_str ());
            return FALSE;
        }

        return TRUE;
    }

    gboolean step (void) {
        switch (sqlite3_step (m_stmt)) {
        case SQLITE_ROW:
            return TRUE;
        case SQLITE_DONE:
            return FALSE;
        default:
            g_warning ("sqlites step error!");
            return FALSE;
        }
    }

    const gchar *columnText (guint col) {
        return (const gchar *) sqlite3_column_text (m_stmt, col);
    }

    gint columnInt (guint col) {
        return sqlite3_column_int (m_stmt, col);
    }

private:
    sqlite3 *m_db;
    sqlite3_stmt *m_stmt;
};

Query::Query (const PinyinArray    & pinyin,
              guint                  pinyin_begin,
              guint                  pinyin_len,
              guint                  option)
    : m_pinyin (pinyin),
      m_pinyin_begin (pinyin_begin),
      m_pinyin_len (pinyin_len),
      m_option (option)
{
    g_assert (m_pinyin.size () >= pinyin_begin + pinyin_len);
}

Query::~Query (void)
{
}

gint
Query::fill (PhraseArray &phrases, gint count)
{
    gint row = 0;

    while (m_pinyin_len > 0) {
        if (G_LIKELY (m_stmt.get () == NULL)) {
            m_stmt = Database::instance ().query (m_pinyin, m_pinyin_begin, m_pinyin_len, -1, m_option);
            g_assert (m_stmt.get () != NULL);
        }

        while (m_stmt->step ()) {
            Phrase phrase;

            g_strlcpy (phrase.phrase,
                       m_stmt->columnText (DB_COLUMN_PHRASE),
                       sizeof (phrase.phrase));
            phrase.freq = m_stmt->columnInt (DB_COLUMN_FREQ);
            phrase.user_freq = m_stmt->columnInt (DB_COLUMN_USER_FREQ);
            phrase.len = m_pinyin_len;

            for (guint i = 0, column = DB_COLUMN_S0; i < m_pinyin_len; i++) {
                phrase.pinyin_id[i].sheng = m_stmt->columnInt (column++);
                phrase.pinyin_id[i].yun = m_stmt->columnInt (column++);
            }

            phrases.push_back (phrase);
            row ++;
            if (G_UNLIKELY (row == count)) {
                return row;
            }
        }

        m_stmt.reset ();
        m_pinyin_len --;
    }

    return row;
}

Database::Database (void)
    : m_db (NULL)
{
    init ();
}

Database::~Database (void)
{
    if (m_db) {
        if (sqlite3_close (m_db) != SQLITE_OK) {
            g_warning ("close sqlite database failed!");
        }
    }
}

inline gboolean
Database::executeSQL (const gchar *sql)
{
    gchar *errmsg;
    if (sqlite3_exec (m_db, sql, NULL, NULL, &errmsg) != SQLITE_OK) {
        g_warning ("%s: %s", errmsg, sql);
        sqlite3_free (errmsg);
        return FALSE;
    }
    return TRUE;
}

gboolean
Database::init (void)
{
    gboolean retval;

#if (SQLITE_VERSION_NUMBER >= 3006000)
    sqlite3_initialize ();
#endif

    static const gchar * maindb [] = {
        PKGDATADIR"/db/local.db",
        PKGDATADIR"/db/open-phrase.db",
        PKGDATADIR"/db/android.db",
        "main.db",
    };

    guint i;
    for (i = 0; i < G_N_ELEMENTS (maindb); i++) {
        if (!g_file_test(maindb[i], G_FILE_TEST_IS_REGULAR))
            continue;
        if (sqlite3_open_v2 (maindb[i], &m_db,
            SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL) == SQLITE_OK) {
            g_message ("Use database %s", maindb[i]);
            break;
        }
    }

    if (i == G_N_ELEMENTS (maindb)) {
        g_warning ("can not open main database");
        goto _failed;
    }

    m_sql.clear ();

#if 1
    /* Set synchronous=OFF, write user database will become much faster.
     * It will cause user database corrupted, if the operatering system
     * crashes or computer loses power.
     * */
    m_sql << "PRAGMA synchronous=NORMAL;\n";
#endif

    /* Set the cache size for better performance */
    m_sql << "PRAGMA cache_size=" DB_CACHE_SIZE ";\n";

    /* Using memory for temp store */
    m_sql << "PRAGMA temp_store=MEMORY;\n";

    /* Set journal mode */
    m_sql << "PRAGMA journal_mode=PERSIST;\n";

    /* Using EXCLUSIVE locking mode on databases
     * for better performance */
    m_sql << "PRAGMA locking_mode=EXCLUSIVE;\n";
    if (!executeSQL (m_sql))
        goto _failed;

    /* Attach user database */
    m_buffer = g_get_user_cache_dir ();
    m_buffer << G_DIR_SEPARATOR_S << "ibus"
             << G_DIR_SEPARATOR_S << "pinyin";
    g_mkdir_with_parents (m_buffer, 0750);
    m_buffer << G_DIR_SEPARATOR_S << "user-1.3.db";
    retval = initUserDatabase (m_buffer);
    if (!retval) {
        g_warning ("Can not open user database %s", m_buffer.c_str ());
        if (!initUserDatabase (":memory:"))
            goto _failed;
    }

    /* prefetch some tables */
    // prefetch ();

    return TRUE;

_failed:
    if (m_db) {
        sqlite3_close (m_db);
        m_db = NULL;
    }
    return FALSE;
}

gboolean
Database::initUserDatabase (const gchar *userdb)
{
    m_sql.printf ("ATTACH DATABASE \"%s\" AS userdb;", userdb);
    if (!executeSQL (m_sql))
        return FALSE;

    m_sql = "BEGIN TRANSACTION;\n";
    /* create desc table*/
    m_sql << "CREATE TABLE IF NOT EXISTS userdb.desc (name PRIMARY KEY, value TEXT);\n";
    m_sql << "INSERT OR IGNORE INTO userdb.desc VALUES " << "('version', '1.2.0');\n"
          << "INSERT OR IGNORE INTO userdb.desc VALUES " << "('uuid', '" << UUID () << "');\n"
          << "INSERT OR IGNORE INTO userdb.desc VALUES " << "('hostname', '" << Hostname () << "');\n"
          << "INSERT OR IGNORE INTO userdb.desc VALUES " << "('username', '" << Env ("USERNAME") << "');\n"
          << "INSERT OR IGNORE INTO userdb.desc VALUES " << "('create-time', datetime());\n"
          << "INSERT OR IGNORE INTO userdb.desc VALUES " << "('attach-time', datetime());\n";

    /* create phrase tables */
    for (guint i = 0; i < MAX_PHRASE_LEN; i++) {
        m_sql.appendPrintf ("CREATE TABLE IF NOT EXISTS userdb.py_phrase_%d (user_freq, phrase TEXT, freq INTEGER ", i);
        for (guint j = 0; j <= i; j++)
            m_sql.appendPrintf (",s%d INTEGER, y%d INTEGER", j, j);
        m_sql << ");\n";
    }

    /* create index */
    m_sql << "CREATE UNIQUE INDEX IF NOT EXISTS " << "userdb.index_0_0 ON py_phrase_0(s0,y0,phrase);\n";
    m_sql << "CREATE UNIQUE INDEX IF NOT EXISTS " << "userdb.index_1_0 ON py_phrase_1(s0,y0,s1,y1,phrase);\n";
    m_sql << "CREATE INDEX IF NOT EXISTS " << "userdb.index_1_1 ON py_phrase_1(s0,s1,y1);\n";
    for (guint i = 2; i < MAX_PHRASE_LEN; i++) {
        m_sql << "CREATE UNIQUE INDEX IF NOT EXISTS " << "userdb.index_" << i << "_0 ON py_phrase_" << i
              << "(s0,y0";
        for (guint j = 1; j <= i; j++)
            m_sql << ",s" << j << ",y" << j;
        m_sql << ",phrase);\n";
        m_sql << "CREATE INDEX IF NOT EXISTS " << "userdb.index_" << i << "_1 ON py_phrase_" << i << "(s0,s1,s2,y2);\n";
    }
    m_sql << "COMMIT;";

    if (!executeSQL (m_sql))
        goto _failed;

    m_sql  = "UPDATE userdb.desc SET value=datetime() WHERE name='attach-time';";

    if (!executeSQL (m_sql))
        goto _failed;

    return TRUE;

_failed:
    m_sql = "DETACH DATABASE userdb;";
    executeSQL (m_sql);
    return FALSE;
}

void
Database::prefetch (void)
{
    m_sql.clear ();
    for (guint i = 0; i < DB_PREFETCH_LEN; i++)
        m_sql << "SELECT * FROM py_phrase_" << i << ";\n";

    // g_debug ("prefetching ...");
    executeSQL (m_sql);
    // g_debug ("done");
}

inline static gboolean
pinyin_option_check_sheng (guint option, gint id, gint fid)
{
    switch ((id << 16) | fid) {
    case (PINYIN_ID_C << 16) | PINYIN_ID_CH:
        return (option & PINYIN_FUZZY_C_CH);
    case (PINYIN_ID_CH << 16) | PINYIN_ID_C:
        return (option & PINYIN_FUZZY_CH_C);
    case (PINYIN_ID_Z << 16) | PINYIN_ID_ZH:
        return (option & PINYIN_FUZZY_Z_ZH);
    case (PINYIN_ID_ZH << 16) | PINYIN_ID_Z:
        return (option & PINYIN_FUZZY_ZH_Z);
    case (PINYIN_ID_S << 16) | PINYIN_ID_SH:
        return (option & PINYIN_FUZZY_S_SH);
    case (PINYIN_ID_SH << 16) | PINYIN_ID_S:
        return (option & PINYIN_FUZZY_SH_S);
    case (PINYIN_ID_L << 16) | PINYIN_ID_N:
        return (option & PINYIN_FUZZY_L_N);
    case (PINYIN_ID_N << 16) | PINYIN_ID_L:
        return (option & PINYIN_FUZZY_N_L);
    case (PINYIN_ID_F << 16) | PINYIN_ID_H:
        return (option & PINYIN_FUZZY_F_H);
    case (PINYIN_ID_H << 16) | PINYIN_ID_F:
        return (option & PINYIN_FUZZY_H_F);
    case (PINYIN_ID_L << 16) | PINYIN_ID_R:
        return (option & PINYIN_FUZZY_L_R);
    case (PINYIN_ID_R << 16) | PINYIN_ID_L:
        return (option & PINYIN_FUZZY_R_L);
    case (PINYIN_ID_K << 16) | PINYIN_ID_G:
        return (option & PINYIN_FUZZY_K_G);
    case (PINYIN_ID_G << 16) | PINYIN_ID_K:
        return (option & PINYIN_FUZZY_G_K);
    default: return FALSE;
    }
}

inline static gboolean
pinyin_option_check_yun (guint option, gint id, gint fid)
{
    switch ((id << 16) | fid) {
    case (PINYIN_ID_AN << 16) | PINYIN_ID_ANG:
        return (option & PINYIN_FUZZY_AN_ANG);
    case (PINYIN_ID_ANG << 16) | PINYIN_ID_AN:
        return (option & PINYIN_FUZZY_ANG_AN);
    case (PINYIN_ID_EN << 16) | PINYIN_ID_ENG:
        return (option & PINYIN_FUZZY_EN_ENG);
    case (PINYIN_ID_ENG << 16) | PINYIN_ID_EN:
        return (option & PINYIN_FUZZY_ENG_EN);
    case (PINYIN_ID_IN << 16) | PINYIN_ID_ING:
        return (option & PINYIN_FUZZY_IN_ING);
    case (PINYIN_ID_ING << 16) | PINYIN_ID_IN:
        return (option & PINYIN_FUZZY_ING_IN);
    case (PINYIN_ID_IAN << 16) | PINYIN_ID_IANG:
        return (option & PINYIN_FUZZY_IAN_IANG);
    case (PINYIN_ID_IANG << 16) | PINYIN_ID_IAN:
        return (option & PINYIN_FUZZY_IANG_IAN);
    case (PINYIN_ID_UAN << 16) | PINYIN_ID_UANG:
        return (option & PINYIN_FUZZY_UAN_UANG);
    case (PINYIN_ID_UANG << 16) | PINYIN_ID_UAN:
        return (option & PINYIN_FUZZY_UANG_UAN);
    default: return FALSE;
    }
}

SQLStmtPtr
Database::query (const PinyinArray &pinyin,
                 guint              pinyin_begin,
                 guint              pinyin_len,
                 gint               m,
                 guint              option)
{
    g_assert (pinyin_begin < pinyin.size ());
    g_assert (pinyin_len <= pinyin.size () - pinyin_begin);
    g_assert (pinyin_len <= MAX_PHRASE_LEN);

    /* prepare sql */
    Conditions conditions;

    for (guint i = 0; i < pinyin_len; i++) {
        const Pinyin *p;
        gboolean fs1, fs2;
        p = pinyin[i + pinyin_begin];

        fs1 = pinyin_option_check_sheng (option, p->pinyin_id[0].sheng, p->pinyin_id[1].sheng);
        fs2 = pinyin_option_check_sheng (option, p->pinyin_id[0].sheng, p->pinyin_id[2].sheng);

        if (G_LIKELY (i > 0))
            conditions.appendPrintf (0, conditions.size (),
                                       " AND ");

        if (G_UNLIKELY (fs1 || fs2)) {
            if (G_LIKELY (i < DB_INDEX_SIZE)) {
                if (fs1 && fs2 == 0) {
                    conditions.double_ ();
                    conditions.appendPrintf (0, conditions.size ()  >> 1,
                                               "s%d=%d", i, p->pinyin_id[0].sheng);
                    conditions.appendPrintf (conditions.size () >> 1, conditions.size (),
                                               "s%d=%d", i, p->pinyin_id[1].sheng);
                }
                else if (fs1 == 0 && fs2) {
                    conditions.double_ ();
                    conditions.appendPrintf (0, conditions.size ()  >> 1,
                                               "s%d=%d", i, p->pinyin_id[0].sheng);
                    conditions.appendPrintf (conditions.size () >> 1, conditions.size (),
                                               "s%d=%d", i, p->pinyin_id[2].sheng);
                }
                else {
                    gint len = conditions.size ();
                    conditions.triple ();
                    conditions.appendPrintf (0, len,
                                               "s%d=%d", i, p->pinyin_id[0].sheng);
                    conditions.appendPrintf (len, len << 1,
                                               "s%d=%d", i, p->pinyin_id[1].sheng);
                    conditions.appendPrintf (len << 1, conditions.size (),
                                               "s%d=%d", i, p->pinyin_id[2].sheng);
                }
            }
            else {
                if (fs1 && fs2 == 0) {
                    conditions.appendPrintf (0, conditions.size (),
                                               "s%d IN (%d,%d)", i, p->pinyin_id[0].sheng, p->pinyin_id[1].sheng);
                }
                else if (fs1 == 0 && fs2) {
                    conditions.appendPrintf (0, conditions.size (),
                                               "s%d IN (%d,%d)", i, p->pinyin_id[0].sheng, p->pinyin_id[2].sheng);
                }
                else {
                    conditions.appendPrintf (0, conditions.size (),
                                               "s%d IN (%d,%d,%d)", i, p->pinyin_id[0].sheng, p->pinyin_id[1].sheng, p->pinyin_id[2].sheng);
                }
            }
        }
        else {
            conditions.appendPrintf (0, conditions.size (),
                                       "s%d=%d", i, p->pinyin_id[0].sheng);
        }

        if (p->pinyin_id[0].yun != PINYIN_ID_ZERO) {
            if (pinyin_option_check_yun (option, p->pinyin_id[0].yun, p->pinyin_id[1].yun)) {
                if (G_LIKELY (i < DB_INDEX_SIZE)) {
                    conditions.double_ ();
                    conditions.appendPrintf (0, conditions.size ()  >> 1,
                                               " AND y%d=%d", i, p->pinyin_id[0].yun);
                    conditions.appendPrintf (conditions.size () >> 1, conditions.size (),
                                               " and y%d=%d", i, p->pinyin_id[1].yun);
                }
                else {
                    conditions.appendPrintf (0, conditions.size (),
                                               " AND y%d IN (%d,%d)", i, p->pinyin_id[0].yun, p->pinyin_id[1].yun);
                }
            }
            else {
                conditions.appendPrintf (0, conditions.size (),
                                           " AND y%d=%d", i, p->pinyin_id[0].yun);
            }
        }
    }


    m_buffer.clear ();
    for (guint i = 0; i < conditions.size (); i++) {
        if (G_UNLIKELY (i == 0))
            m_buffer << "  (" << conditions[i] << ")\n";
        else
            m_buffer << "  OR (" << conditions[i] << ")\n";
    }

    m_sql.clear ();
    gint id = pinyin_len - 1;
    m_sql << "SELECT * FROM ("
                "SELECT 0 AS user_freq, * FROM main.py_phrase_" << id << " WHERE " << m_buffer << " UNION ALL "
                "SELECT * FROM userdb.py_phrase_" << id << " WHERE " << m_buffer << ") "
                    "GROUP BY phrase ORDER BY user_freq DESC, freq DESC";
    if (m > 0)
        m_sql << " LIMIT " << m;
#if 0
    g_debug ("sql =\n%s", m_sql.c_str ());
#endif

    /* query database */
    SQLStmtPtr stmt (new SQLStmt (m_db));

    if (!stmt->prepare (m_sql)) {
        stmt.reset ();
    }

    return stmt;
}

inline void
Database::phraseWhereSql (const Phrase & p, String & sql)
{
    sql << " WHERE";
    sql << " s0=" << p.pinyin_id[0].sheng
        << " AND y0=" << p.pinyin_id[0].yun;
    for (guint i = 1; i < p.len; i++) {
        sql << " AND s" << i << '=' << p.pinyin_id[i].sheng
            << " AND y" << i << '=' << p.pinyin_id[i].yun;
    }
    sql << " AND phrase=\"" << p.phrase << "\"";

}

inline void
Database::phraseSql (const Phrase & p, String & sql)
{
    sql << "INSERT OR IGNORE INTO userdb.py_phrase_" << p.len - 1
        << " VALUES(" << 0                  /* user_freq */
        << ",\"" << p.phrase << '"'         /* phrase */
        << ','   << p.freq;                 /* freq */

    for (guint i = 0; i < p.len; i++) {
        sql << ',' << p.pinyin_id[i].sheng << ',' << p.pinyin_id[i].yun;
    }

    sql << ");\n";

    sql << "UPDATE userdb.py_phrase_" << p.len - 1
        << " SET user_freq=user_freq+1";

    phraseWhereSql (p, sql);
    sql << ";\n";
}

void
Database::commit (const PhraseArray  &phrases)
{
    Phrase phrase = {""};

    m_sql = "BEGIN TRANSACTION;\n";
    for (guint i = 0; i < phrases.size (); i++) {
        phrase += phrases[i];
        phraseSql (phrases[i], m_sql);
    }
    if (phrases.size () > 1)
        phraseSql (phrase, m_sql);
    m_sql << "COMMIT;\n";

    executeSQL (m_sql);
}

void
Database::remove (const Phrase & phrase)
{
    m_sql = "BEGIN TRANSACTION;\n";
    m_sql << "DELETE FROM userdb.py_phrase_" << phrase.len - 1;
    phraseWhereSql (phrase, m_sql);
    m_sql << ";\n";
    m_sql << "COMMIT;\n";

    executeSQL (m_sql);
}

};
