#include <ctime>
#include <cstdio>
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
        std::time (&m_time);
        std::string result;

        size_t pos = 0;
        size_t pnext;
        gint s = 0;
        while (s != 2) {
            switch (s) {
            case 0:
                pnext = m_text.find ("%(", pos);
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
                pnext = m_text.find (")", pos);
                if (pnext == m_text.npos) {
                    result += "%(";
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

    const std::string dec (gint d) {
        char string [32];
        std::snprintf (string, sizeof (string), "%d", d);
        return string;
    }

    const std::string variable (const std::string &name) {
        if (name == "year") {
            return dec (localtime (&m_time)->tm_year + 1900);
        }
        if (name == "month") {
            return dec (localtime (&m_time)->tm_mon + 1);
        }
        if (name == "day") {
            return dec (localtime (&m_time)->tm_mday + 1);
        }
        if (name == "hour_24") {
            return dec (localtime (&m_time)->tm_hour + 1);
        }
        if (name == "minute") {
            return dec (localtime (&m_time)->tm_min + 1);
        }
        if (name == "second") {
            return dec (localtime (&m_time)->tm_sec + 1);
        }
        return name;
    }

private:
    std::string m_text;
    time_t m_time;

};

SpecialTable::SpecialTable (void)
{
    insert ("hehe", new StaticPhrase (":-)", 0));
    insert ("haha", new StaticPhrase ("^_^", 0));
    insert ("haha", new StaticPhrase ("o(∩∩)o...哈哈", 1));
    insert ("xixi", new StaticPhrase ("(*^__^*) 嘻嘻……", 0));
    insert ("bsn", new StaticPhrase ("╭∩╮（︶︿︶）╭∩╮鄙视你！", 0));
    insert ("rq", new DynamicPhrase ("%(year)年%(month)月%(day)日", 0));
    insert ("rq", new DynamicPhrase ("%(year)-%(month)-%(day)", 1));
    insert ("sj", new DynamicPhrase ("%(hour_24)时%(minute)分%(second)秒", 0));
    insert ("sj", new DynamicPhrase ("%(hour_24):%(minute):%(second)", 1));
}

static bool
phraseCmp (const SpecialPhrase *first,
           const SpecialPhrase *second)
{
    return first->position () <= second->position ();
}

void
SpecialTable::insert (const std::string   &command,
                      SpecialPhrase       *phrase)
{
    if (m_map.find (command) == m_map.end ()) {
        m_map[command] = List ();
    }
    List & list = m_map[command];
    list.push_back (phrase);
    list.sort (phraseCmp);
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

