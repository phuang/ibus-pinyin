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
    void insert (const std::string & command, SpecialPhrase *phrase);
    gboolean lookup (const std::string &command, std::vector<std::string> &result);

private:
    gboolean load (const gchar *file);

public:
    static SpecialPhraseTable & instance (void) { return m_instance; }

private:
    typedef std::list<SpecialPhrase *> List;
    typedef std::map<std::string, List> Map;
    Map m_map;

private:
    static SpecialPhraseTable m_instance;
};

};

#endif
