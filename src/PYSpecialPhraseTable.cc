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
#include "PYSpecialPhraseTable.h"
#include <fstream>
#include "PYDynamicSpecialPhrase.h"
#include "PYSpecialPhrase.h"

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

gboolean
SpecialPhraseTable::lookup (const std::string         &command,
                            std::vector<std::string>  &result)
{
    result.clear ();

    std::pair<Map::iterator, Map::iterator> range = m_map.equal_range (command);
    for (Map::iterator it = range.first; it != range.second; it ++) {
        result.push_back ((*it).second->text ());
    }

    return result.size () > 0;
}

gboolean
SpecialPhraseTable::load (const gchar *file)
{
    m_map.clear ();

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
        std::string value = line.substr(pos + 1);
        if (command.empty () || value.empty ())
            continue;

        if (value[0] != '#') {
            SpecialPhrasePtr phrase (new StaticSpecialPhrase (value, 0));
            m_map.insert (Map::value_type (command, phrase));
        }
        else if (value.size () > 1) {
            SpecialPhrasePtr phrase (new DynamicSpecialPhrase (value.substr (1), 0));
            m_map.insert (Map::value_type (command, phrase));
        }
    }
    return TRUE;
}

};

