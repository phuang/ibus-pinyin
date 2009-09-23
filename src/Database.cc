/* vim:set et sts=4: */
#include <string.h>
#include <glib.h>
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
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

Database::Database (void)
    : m_db (NULL),
      m_sql (1024),
      m_buffer (1024),
      m_conditions (32),
      m_strings (32)
{
    init ();
}

Database::~Database (void)
{
    for (guint i = 0; i < m_strings.length (); i++) {
        delete m_strings[i];
    }

    if (m_db) {
        sqlite3_close (m_db);
        m_db = NULL;
    }
}

gboolean
Database::init (void)
{
    gchar *errmsg;
    gchar *userdb;
    gboolean retval;

    sqlite3_initialize ();

    if (sqlite3_open_v2 (PKGDATADIR"/db/main.db", &m_db,
            SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL) != SQLITE_OK) {
        if (sqlite3_open_v2 ("main.db", &m_db,
                SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL) != SQLITE_OK)
            goto _failed;
    }
    
    if (sqlite3_exec (m_db, "PRAGMA cache_size=" DB_CACHE_SIZE, NULL, NULL, &errmsg) != SQLITE_OK) {
        g_debug ("%s", errmsg);
        sqlite3_free (errmsg);
        goto _failed;
    }

    userdb = g_build_path (G_DIR_SEPARATOR_S, g_get_home_dir (), ".ibus", "pinyin", NULL);
    g_mkdir_with_parents (userdb, 0750);
    g_free (userdb);
    userdb = g_build_path (G_DIR_SEPARATOR_S, g_get_home_dir (), ".ibus", "pinyin", "user-1.3.db", NULL);
    retval = initUserDatabase (userdb);
    if (!retval) {
        g_free (userdb);
        g_warning ("can not open user database %s", userdb);
        if (!initUserDatabase (":memory:"))
            goto _failed;
    }
    g_free (userdb);

    prefetch ();

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
    gchar *errmsg;

    m_sql.printf ("ATTACH DATABASE \"%s\" AS userdb;", userdb);
    if (sqlite3_exec (m_db, m_sql, NULL, NULL, &errmsg) != SQLITE_OK) {
        g_debug ("%s", errmsg);
        sqlite3_free (errmsg);
        return FALSE;
    }

    m_sql = "BEGIN TRANSACTION;\n";
    /* create desc table*/
    m_sql << "CREATE TABLE IF NOT EXISTS userdb.desc (name PRIMARY KEY, value TEXT);\n";
    m_sql << "INSERT OR IGNORE INTO userdb.desc VALUES " << "('version', '1.2.0');\n"
          << "INSERT OR IGNORE INTO userdb.desc VALUES " << "('uuid', '" << UUID () << "');\n"
          << "INSERT OR IGNORE INTO userdb.desc VALUES " << "('hostname', '" << Hostname () << "');\n"
          << "INSERT OR IGNORE INTO userdb.desc VALUES " << "('username', '" << getenv ("USERNAME") << "');\n"
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
    m_sql << "COMMIT;\n";

    if (sqlite3_exec (m_db, m_sql, NULL, NULL, &errmsg) != SQLITE_OK) {
        g_debug ("%s", errmsg);
        sqlite3_free (errmsg);
        goto _failed;
    }

    m_sql  = "UPDATE userdb.desc SET value=datetime() WHERE name='attach-time';\n";

    if (sqlite3_exec (m_db, m_sql, NULL, NULL, &errmsg) != SQLITE_OK) {
        g_debug ("%s", errmsg);
        sqlite3_free (errmsg);
        goto _failed;
    }
    return TRUE;

_failed:
    m_sql = "DETACH DATABASE userdb;\n";
    if (sqlite3_exec (m_db, m_sql, NULL, NULL, &errmsg) != SQLITE_OK) {
        g_debug ("%s", errmsg);
        sqlite3_free (errmsg);
    }
    return FALSE;
}

void
Database::prefetch (void)
{
    for (guint i = 0; i < DB_PREFETCH_LEN; i++) {
        gchar *errmsg;
        m_sql = "SELECT * FROM py_phrase_";
        m_sql << i;
        if (sqlite3_exec (m_db, m_sql, NULL, NULL, &errmsg) != SQLITE_OK) {
            g_debug ("%s", errmsg);
            sqlite3_free (errmsg);
        }
    }
}

gint
Database::query (const PinyinArray &pinyin,
                 guint              m,
                 guint              option,
                 PhraseArray       &result)
{
    gint len;
    gint i;
    gint row;
    gint ret;

    len = MIN (pinyin.length (), MAX_PHRASE_LEN);

    row = 0;
    for (i = len; i > 0; i--) {
        if (m < 0) {
            ret = query (pinyin, 0, i, -1, option, result);
            if (ret < 0)
                return ret;
            row += ret;
        }
        else {
            ret = query (pinyin, 0, i, m - result.length (), option, result);
            if (ret < 0)
                return ret;
            row += ret;
            if (result.length () >= m)
                break;
        }
    }
    return row;
}



inline static void
_conditions_append_vprintf (Array<String *> &array,
                            gint             begin,
                            gint             end,
                            const gchar     *fmt,
                            va_list          args)
{
    gchar str[64];
    g_vsnprintf (str, sizeof(str), fmt, args);

    for (gint i = begin; i < end; i++) {
        (*array[i]) << str;
    }
}

inline static void
_conditions_append_printf (Array<String *> &array,
                           gint             begin,
                           gint             end,
                           const gchar     *fmt,
                           ...)
{
    va_list args;
    va_start (args, fmt);
    _conditions_append_vprintf (array, begin, end, fmt, args);
    va_end (args);
}

#define CONDITION_INIT_SIZE (256)

inline void
Database::conditionsDouble (void)
{
    gint i, len;

    len = m_conditions.length ();

    for (i = 0; i < len; i++) {
        String *new_str;
        new_str = string (len + i);
        *new_str = *m_conditions[i];
        m_conditions << new_str;
    }
}

inline void
Database::conditionsTriple (void)
{
    gint i, len;

    len = m_conditions.length ();

    for (i = 0; i < len; i++) {
        String *new_str;
        new_str = string ((i << 1) + len);
        *new_str = *m_conditions[i];
        m_conditions << new_str;
        new_str = string ((i << 1) + len + 1);
        *new_str = *m_conditions[i];
        m_conditions << new_str;
    }
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

gint
Database::query (const PinyinArray &pinyin,
                 guint              pinyin_begin,
                 guint              pinyin_len,
                 gint               m,
                 guint              option,
                 PhraseArray       &result)
{
    if (G_UNLIKELY (pinyin_begin > pinyin.length ()))
        pinyin_begin = pinyin.length ();

    if (G_UNLIKELY (pinyin_len > pinyin.length () - pinyin_begin))
        pinyin_len = pinyin.length () - pinyin_begin;

    if (G_UNLIKELY (pinyin_len > MAX_PHRASE_LEN))
        return -1;

    /* prepare sql */
    m_conditions.setSize (1);
    m_conditions[0] = this->string (0);

    for (guint i = 0; i < pinyin_len; i++) {
        const Pinyin *p;
        gboolean fs1, fs2;
        p = pinyin[i + pinyin_begin];

        fs1 = pinyin_option_check_sheng (option, p->sheng_id, p->fsheng_id);
        fs2 = pinyin_option_check_sheng (option, p->sheng_id, p->fsheng_id_2);

        if (G_LIKELY (i > 0))
            _conditions_append_printf (m_conditions,
                                       0, m_conditions.length (),
                                       " AND ");

        if (fs1 || fs2) {
            if (G_LIKELY (i < DB_INDEX_SIZE)) {
                if (fs1 && fs2 == 0) {
                    conditionsDouble ();
                    _conditions_append_printf (m_conditions,
                                               0, m_conditions.length ()  >> 1,
                                               "s%d=%d", i, p->sheng_id);
                    _conditions_append_printf (m_conditions,
                                               m_conditions.length () >> 1, m_conditions.length (),
                                               "s%d=%d", i, p->fsheng_id);
                }
                else if (fs1 == 0 && fs2) {
                    conditionsDouble ();
                    _conditions_append_printf (m_conditions,
                                               0, m_conditions.length ()  >> 1,
                                               "s%d=%d", i, p->sheng_id);
                    _conditions_append_printf (m_conditions,
                                               m_conditions.length () >> 1, m_conditions.length (),
                                               "s%d=%d", i, p->fsheng_id_2);
                }
                else {
                    gint len = m_conditions.length ();
                    conditionsTriple ();
                    _conditions_append_printf (m_conditions,
                                               0, len,
                                               "s%d=%d", i, p->sheng_id);
                    _conditions_append_printf (m_conditions,
                                               len, len << 1,
                                               "s%d=%d", i, p->fsheng_id);
                    _conditions_append_printf (m_conditions,
                                               len << 1, m_conditions.length (),
                                               "s%d=%d", i, p->fsheng_id_2);
                }
            }
            else {
                if (fs1 && fs2 == 0) {
                    _conditions_append_printf (m_conditions,
                                               0, m_conditions.length (),
                                               "s%d IN (%d,%d)", i, p->sheng_id, p->fsheng_id);
                }
                else if (fs1 == 0 && fs2) {
                    _conditions_append_printf (m_conditions,
                                               0, m_conditions.length (),
                                               "s%d IN (%d,%d)", i, p->sheng_id, p->fsheng_id_2);
                }
                else {
                    _conditions_append_printf (m_conditions,
                                               0, m_conditions.length (),
                                               "s%d IN (%d,%d,%d)", i, p->sheng_id, p->fsheng_id, p->fsheng_id_2);
                }
            }
        }
        else {
            _conditions_append_printf (m_conditions,
                                       0, m_conditions.length (),
                                       "s%d=%d", i, p->sheng_id);
        }

        if (p->yun_id != PINYIN_ID_ZERO) {
            if (pinyin_option_check_yun (option, p->yun_id, p->fyun_id)) {
                if (G_LIKELY (i < DB_INDEX_SIZE)) {
                    conditionsDouble ();
                    _conditions_append_printf (m_conditions,
                                               0, m_conditions.length ()  >> 1,
                                               " AND y%d=%d", i, p->yun_id);
                    _conditions_append_printf (m_conditions,
                                               m_conditions.length () >> 1, m_conditions.length (),
                                               " and y%d=%d", i, p->fyun_id);
                }
                else {
                    _conditions_append_printf (m_conditions,
                                               0, m_conditions.length (),
                                               " AND y%d IN (%d,%d)", i, p->yun_id, p->fyun_id);
                }
            }
            else {
                _conditions_append_printf (m_conditions,
                                           0, m_conditions.length (),
                                           " AND y%d=%d", i, p->yun_id);
            }
        }
    }


    m_buffer.truncate (0);
    for (guint i = 0; i < m_conditions.length (); i++) {
        if (G_UNLIKELY (i == 0))
            m_buffer << "  (" << (*m_conditions[i]) << ")\n";
        else
            m_buffer << "  OR (" << (*m_conditions[i]) << ")\n";
    }
    m_conditions.removeAll ();

    m_sql.printf ("SELECT * FROM ("
                  "SELECT 0 AS user_freq, * FROM main.py_phrase_%d WHERE %s UNION ALL "
                  "SELECT * FROM userdb.py_phrase_%d WHERE %s) "
                  "GROUP BY phrase ORDER BY user_freq DESC, freq DESC ",
                  pinyin_len - 1, (const gchar *) m_buffer, pinyin_len - 1, (const gchar *)m_buffer);
    if (m > 0)
        m_sql << "LIMIT " << m;
#if 0
    g_debug ("sql =\n%s", (const gchar *)m_sql);
#endif

    /* query database */
    sqlite3_stmt *stmt;
    if (sqlite3_prepare (m_db,
                         (const gchar *) m_sql,
                         -1,
                         &stmt,
                         NULL) != SQLITE_OK) {
        g_debug ("parse sql failed!\n %s", (const gchar *)m_sql);
        return -1;
    }

    gint row = 0;
    while (sqlite3_step (stmt) == SQLITE_ROW) {
        result.setSize (result.length () + 1);
        Phrase &p = result[result.length() - 1];

        strcpy (p.phrase, (gchar *) sqlite3_column_text (stmt, DB_COLUMN_PHRASE));
        p.freq = sqlite3_column_int (stmt, DB_COLUMN_FREQ);
        p.user_freq = sqlite3_column_int (stmt, DB_COLUMN_USER_FREQ);
        p.len = pinyin_len;

        for (guint i = 0; i < pinyin_len; i++) {
            p.pinyin_id[i][0] = sqlite3_column_int (stmt, (i << 1) + DB_COLUMN_S0);
            p.pinyin_id[i][1] = sqlite3_column_int (stmt, (i << 1) + DB_COLUMN_S0 + 1);
        }
        row ++;
    }

    sqlite3_finalize (stmt);
    return row;
}

inline void
Database::phraseWhereSql (const Phrase & p, String & sql)
{
    sql << " WHERE";
    sql << " s0=" << p.pinyin_id[0][0]
        << " AND y0=" << p.pinyin_id[0][1];
    for (guint i = 1; i < p.len; i++) {
        sql << " AND s" << i << '=' << p.pinyin_id[i][0]
            << " AND y" << i << '=' << p.pinyin_id[i][1];
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
            sql << ',' << p.pinyin_id[i][0] << ',' << p.pinyin_id[i][1];
        }
    sql << ");\n";

    sql << "UPDATE userdb.py_phrase_" << p.len - 1
        << " SET user_freq=user_freq+1";

    phraseWhereSql (p, sql);
    sql << "\n;";
}

void
Database::commit (const PhraseArray  &phrases)
{
    gchar *errmsg;
    Phrase phrase = {""};

    m_sql = "BEGIN TRANSACTION;\n";
    for (guint i = 0; i < phrases.length (); i++) {
        strcat (phrase.phrase, phrases[i].phrase);
        for (guint j = 0; j < phrases[i].len; j++) {
            phrase.pinyin_id[phrase.len + j][0] = phrases[i].pinyin_id[j][0];
            phrase.pinyin_id[phrase.len + j][1] = phrases[i].pinyin_id[j][1];
        }
        phrase.len += phrases[i].len;
        phraseSql (phrases[i], m_sql);
    }
    if (phrases.length () > 1)
        phraseSql (phrase, m_sql);
    m_sql << "COMMIT;";

    if (sqlite3_exec (m_db, m_sql, NULL, NULL, &errmsg) != SQLITE_OK) {
        g_debug ("%s", errmsg);
        g_debug ("m_sql = %s", (const gchar *)m_sql);
        sqlite3_free (errmsg);
    }
}

void
Database::remove (const Phrase & phrase)
{
    gchar *errmsg;
    m_sql = "BEGIN TRANSACTION;\n";
    m_sql << "DELETE FROM userdb.py_phrase_" << phrase.len - 1;
    phraseWhereSql (phrase, m_sql);
    m_sql << ";\n";
    m_sql << "COMMIT;\n";

    if (sqlite3_exec (m_db, m_sql, NULL, NULL, &errmsg) != SQLITE_OK) {
        g_debug ("%s", errmsg);
        sqlite3_free (errmsg);
    }

}

};
