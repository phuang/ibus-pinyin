#include "SpecialTable.h"

namespace PY {

class StaticPhrase : public SpecialPhrase {
public:
    StaticPhrase (const std::string &text, guint pos) :
        SpecialPhrase (pos), m_text (text) {
    }

    std::string text (void) { return m_text; }

private:
    std::string m_text;
};

SpecialTable::SpecialTable (void)
{
    g_debug ("SpecialTable");
    insert ("xixi", new StaticPhrase ("(*^__^*) 嘻嘻……", 0));
    insert ("haha", new StaticPhrase ("o(∩∩)o...哈哈", 0));
    insert ("bsn", new StaticPhrase ("╭∩╮（︶︿︶）╭∩╮鄙视你！", 0));
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

