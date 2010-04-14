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
#if 0
;       $(year)         年(4位)         2006、2008
;       $(year_yy)      年(2位)         06、08
;       $(month)        月              12、8、3
;       $(month_mm)     月              12、08、03
;       $(day)          日              3、13、22
;       $(day_dd)       日              03、13、22
;       $(weekday)      星期            0、1、2、5、6
;       $(fullhour)     时(24小时制)    02、08、13、23
;       $(halfhour)     时(12小时制)    02、08、01、11
;       $(ampm)         AM、PM(英)      AM、PM（大写）
;       $(minute)       分              02、08、15、28
;       $(second)       秒              02、08、15、28
;       $(year_cn)      年(中文4位)     二〇〇六
;       $(year_yy_cn)   年(中文2位)     〇六
;       $(month_cn)     月(中文)        十二、八、三
;       $(day_cn)       日(中文)        三、十三、二十二
;       $(weekday_cn)   星期(中文)      日、一、二、五、六
;       $(fullhour_cn)  月(中文24时制)  二、八、十三、二十三
;       $(halfhour_cn)  时(中文12时制)  二、八、一、十一
;       $(ampm_cn)      上午下午(中文)  上午、下午
;       $(minute_cn)    分(中文)        零二、零八、十五、二十八
;       $(second_cn)    秒(中文)        零二、零八、十五、二十八
#endif
    const std::string variable (const std::string &name) {
        if (name == "year")
            return dec (localtime (&m_time)->tm_year + 1900);
        if (name == "year_yy")
            return dec ((localtime (&m_time)->tm_year + 1900) % 100, "%02d");
        if (name == "month")
            return dec (localtime (&m_time)->tm_mon + 1);
        if (name == "month_mm")
            return dec (localtime (&m_time)->tm_mon + 1, "%02d");
        if (name == "day")
            return dec (localtime (&m_time)->tm_mday + 1);
        if (name == "day_dd")
            return dec (localtime (&m_time)->tm_mday + 1, "%02d");
        if (name == "week")
            return dec (localtime (&m_time)->tm_wday + 1);
        if (name == "fullhour")
            return dec (localtime (&m_time)->tm_hour + 1, "%02d");
        if (name == "falfhour")
            return dec ((localtime (&m_time)->tm_hour + 1) % 12, "%02d");
        if (name == "ampm")
            return localtime (&m_time)->tm_hour < 12 ? "AM" : "PM";
        if (name == "minute")
            return dec (localtime (&m_time)->tm_min + 1, "%02d");
        if (name == "second")
            return dec (localtime (&m_time)->tm_sec + 1, "%02d");
        return name;
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
    load ("special_phrases");
}

gboolean
SpecialTable::load (const gchar *file)
{
    try {
        std::ifstream in (file);
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
            insert (command, new DynamicPhrase (phrase, 0));
        }


    } catch (...) {
        std::cerr << "error" << std::endl;
        return FALSE;
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

