#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include "SpecialTable.h"

namespace PY {

SpecialTable SpecialTable::m_instance;

class StaticPhrase : public SpecialPhrase {
public:
    StaticPhrase (const std::string &text, guint pos) :
        SpecialPhrase (pos), m_text (text) { }

    std::string text (void) { return m_text; }

private:
    std::string m_text;
};

class DynamicPhrase : public SpecialPhrase {
public:
    DynamicPhrase (const std::string &text, guint pos) :
        SpecialPhrase (pos), m_text (text) { }

    std::string text (void) {
        /* get the current time */
        std::time (&m_time);

        std::string result;

        size_t pos = 0;
        size_t pnext;
        gint s = 0;
        while (s != 2) {
            switch (s) {
            case 0:
                pnext = m_text.find ("${", pos);
                if (pnext == m_text.npos) {
                    result += m_text.substr (pos);
                    s = 2;
                }
                else {
                    result += m_text.substr (pos, pnext - pos);
                    pos = pnext + 2;
                    s = 1;
                }
                break;
            case 1:
                pnext = m_text.find ("}", pos);
                if (pnext == m_text.npos) {
                    result += "${";
                    result += m_text.substr (pos);
                    s = 2;
                }
                else {
                    result += variable (m_text.substr(pos, pnext - pos));
                    pos = pnext + 1;
                    s = 0;
                }
                break;
            default:
                g_assert_not_reached ();
            }
        }
        return result;
    }

    const std::string dec (gint d, const gchar *fmt = "%d") {
        char string [32];
        std::snprintf (string, sizeof (string), fmt, d);
        return string;
    }

    const std::string year_cn (gboolean yy = FALSE) {
        static const gchar * digits[] = {
            "〇", "一", "二", "三", "四",
            "五", "六", "七", "八", "九"
        };

        gint year = localtime (&m_time)->tm_year + 1900;
        gint bit = 0;
        if (yy) {
            year %= 100;
            bit = 2;
        }

        std::string result;
        while (year != 0 || bit > 0) {
            result.insert(0, digits[year % 10]);
            year /= 10;
            bit -= 1;
        }
        return result;
    }

    const std::string month_cn (void) {
        static const gchar *month_num[] = {
            "一", "二", "三", "四", "五", "六", "七", "八",
            "九", "十", "十一", "十二"
        };
        return month_num[localtime (&m_time)->tm_mon];
    }

    const std::string weekday_cn (void) {
        static const gchar *week_num[] = {
            "一", "二", "三", "四", "五", "六", "日",
        };
        return week_num[localtime (&m_time)->tm_wday];
    }

    const std::string hour_cn (guint i) {
        static const gchar *hour_num[] = {
            "一", "二", "三", "四", "五",
            "六", "七", "八", "九", "十",
            "十一", "十二", "十三", "十四", "十五",
            "十六", "十七", "十八", "十九", "二十",
            "二十一", "二十二", "二十三", "零"
        };
        return hour_num[i];
    }

    const std::string fullhour_cn (void) {
        return hour_cn (localtime (&m_time)->tm_hour);
    }

    const std::string halfhour_cn (void) {
        return hour_cn (localtime (&m_time)->tm_hour % 12);
    }

    const std::string day_cn (void) {
        static const gchar *day_num[] = {
            "", "一", "二", "三", "四",
            "五", "六", "七", "八", "九",
            "", "十","二十", "三十"
        };
        guint day = localtime (&m_time)->tm_mday + 1;
        return std::string () + day_num[day / 10 + 10] + day_num[day % 10];
    }

    const std::string minsec_cn (guint i) {
        static const gchar *num[] = {
            "", "一", "二", "三", "四",
            "五", "六", "七", "八", "九",
            "零", "十","二十", "三十", "四十"
            "五十", "六十"
        };
        return std::string () + num[i / 10 + 10] + num[i % 10];
    }

    const std::string variable (const std::string &name) {
        if (name == "year")     return dec (localtime (&m_time)->tm_year + 1900);
        if (name == "year_yy")  return dec ((localtime (&m_time)->tm_year + 1900) % 100, "%02d");
        if (name == "month")    return dec (localtime (&m_time)->tm_mon + 1);
        if (name == "month_mm") return dec (localtime (&m_time)->tm_mon + 1, "%02d");
        if (name == "day")      return dec (localtime (&m_time)->tm_mday + 1);
        if (name == "day_dd")   return dec (localtime (&m_time)->tm_mday + 1, "%02d");
        if (name == "weekday")  return dec (localtime (&m_time)->tm_wday + 1);
        if (name == "fullhour") return dec (localtime (&m_time)->tm_hour + 1, "%02d");
        if (name == "falfhour") return dec ((localtime (&m_time)->tm_hour + 1) % 12, "%02d");
        if (name == "ampm")     return localtime (&m_time)->tm_hour < 12 ? "AM" : "PM";
        if (name == "minute")   return dec (localtime (&m_time)->tm_min + 1, "%02d");
        if (name == "second")   return dec (localtime (&m_time)->tm_sec + 1, "%02d");
        if (name == "year_cn")      return year_cn ();
        if (name == "year_yy_cn")   return year_cn (TRUE);
        if (name == "month_cn")     return month_cn ();
        if (name == "day_cn")       return day_cn ();
        if (name == "weekday_cn")   return weekday_cn ();
        if (name == "fullhour_cn")  return fullhour_cn ();
        if (name == "halfhour_cn")  return halfhour_cn ();
        if (name == "ampm_cn")      return localtime (&m_time)->tm_hour < 12 ? "上午" : "下午";
        if (name == "minute_cn")    return minsec_cn (localtime (&m_time)->tm_min + 1);
        if (name == "second_cn")    return minsec_cn (localtime (&m_time)->tm_sec + 1);

        return "${" + name + "}";
    }

private:
    std::string m_text;
    time_t m_time;

};

SpecialTable::SpecialTable (void)
{
#if 0
    insert ("hehe", new StaticPhrase (":-)", 0));
    insert ("haha", new StaticPhrase ("^_^", 0));
    insert ("haha", new StaticPhrase ("o(∩∩)o...哈哈", 1));
    insert ("xixi", new StaticPhrase ("(*^__^*) 嘻嘻……", 0));
    insert ("bsn", new StaticPhrase ("╭∩╮（︶︿︶）╭∩╮鄙视你！", 0));
    insert ("rq", new DynamicPhrase ("%(year)年%(month)月%(day)日", 0));
    insert ("rq", new DynamicPhrase ("%(year)-%(month)-%(day)", 1));
    insert ("sj", new DynamicPhrase ("%(hour_24)时%(minute)分%(second)秒", 0));
    insert ("sj", new DynamicPhrase ("%(hour_24):%(minute):%(second)", 1));
#endif
    gchar * path = g_build_filename (g_get_user_config_dir (),
                        "ibus", "ibus-pinyin", "phrases.txt", NULL);
    load (path) ||
    load (PKGDATADIR G_DIR_SEPARATOR_S "phrases.txt") ||
    load ("phrases.txt");
    g_free (path);
}

gboolean
SpecialTable::load (const gchar *file)
{
    std::ifstream in (file);
    if (in.fail ())
        return FALSE;

    std::string line;
    while (!in.eof ()) {
        getline (in, line);
        if (line.size () == 0 || line[0] == ';')
            continue;
        size_t pos = line.find ('=');
        if (pos == line.npos)
            continue;

        std::string command = line.substr(0, pos);
        std::string phrase = line.substr(pos + 1);
        if (command.empty () || phrase.empty ())
            continue;

        if (phrase[0] != '#') {
            insert (command, new StaticPhrase (phrase, 0));
        }
        else if (phrase.size () > 1) {
            insert (command, new DynamicPhrase (phrase.substr (1), 0));
        }
    }
    return TRUE;
}

#if 0
static bool
phraseCmp (const SpecialPhrase *first,
           const SpecialPhrase *second)
{
    return first->position () <= second->position ();
}
#endif

void
SpecialTable::insert (const std::string   &command,
                      SpecialPhrase       *phrase)
{
    if (m_map.find (command) == m_map.end ()) {
        m_map[command] = List ();
    }
    List & list = m_map[command];
    list.push_back (phrase);
#if 0
    list.sort (phraseCmp);
#endif
}

gboolean
SpecialTable::lookup (const std::string         &command,
                      std::vector<std::string>  &result)
{
    result.clear ();

    if (m_map.find (command) == m_map.end ())
        return FALSE;

    List list = m_map[command];
    for (List::iterator it = list.begin (); it != list.end (); it ++) {
        result.push_back ((*it)->text ());
    }

    return result.size () > 0;
}

};

