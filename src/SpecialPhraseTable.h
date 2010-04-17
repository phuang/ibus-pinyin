#ifndef __PY_SPECIAL_PHRASE_TABLE_H_
#define __PY_SPECIAL_PHRASE_TABLE_H_

#include <map>
#include <list>
#include <string>
#include <vector>
#include <glib.h>
#include "SpecialPhrase.h"

namespace PY {

class SpecialPhraseTable {
private:
    SpecialPhraseTable (void);

public:
    gboolean lookup (const std::string &command, std::vector<std::string> &result);

private:
    gboolean load (const gchar *file);

public:
    static SpecialPhraseTable & instance (void) { return m_instance; }

private:
    typedef std::multimap<std::string, SpecialPhrasePtr> Map;
    Map m_map;

private:
    static SpecialPhraseTable m_instance;
};

};

#endif
