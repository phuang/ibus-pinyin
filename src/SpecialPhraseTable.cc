#include <iostream>
#include <fstream>
#include <string>
#include "Config.h"
#include "DynamicSpecialPhrase.h"
#include "SpecialPhraseTable.h"

namespace PY {

SpecialPhraseTable SpecialPhraseTable::m_instance;

class StaticSpecialPhrase : public SpecialPhrase {
public:
    StaticSpecialPhrase (const std::string &text, guint pos) :
        SpecialPhrase (pos), m_text (text) { }
    ~StaticSpecialPhrase (void) { }

    std::string text (void) { return m_text; }

private:
    std::string m_text;
};

SpecialPhraseTable::SpecialPhraseTable (void)
{
    gchar * path = g_build_filename (g_get_user_config_dir (),
                        "ibus", "pinyin", "phrases.txt", NULL);

    load ("phrases.txt") ||
    load (path) ||
    load (PKGDATADIR G_DIR_SEPARATOR_S "phrases.txt");
    g_free (path);
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
SpecialPhraseTable::insert (const std::string   &command,
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
SpecialPhraseTable::lookup (const std::string         &command,
                            std::vector<std::string>  &result)
{
    result.clear ();

    if (!Config::specialPhrases ())
        return FALSE;
    if (m_map.find (command) == m_map.end ())
        return FALSE;

    List list = m_map[command];
    for (List::iterator it = list.begin (); it != list.end (); it ++) {
        result.push_back ((*it)->text ());
    }

    return result.size () > 0;
}

gboolean
SpecialPhraseTable::load (const gchar *file)
{
    clear ();
    
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
            insert (command, new StaticSpecialPhrase (phrase, 0));
        }
        else if (phrase.size () > 1) {
            insert (command, new DynamicSpecialPhrase (phrase.substr (1), 0));
        }
    }
    return TRUE;
}

void
SpecialPhraseTable::clear (void)
{
    Map::iterator it;

    for (it = m_map.begin (); it != m_map.end (); it ++) {
        std::list<SpecialPhrase *>::iterator pit;
        for (pit = (*it).second.begin (); pit != (*it).second.end (); pit ++) {
            delete *pit;
        }
    }

    m_map.clear ();
}

};

