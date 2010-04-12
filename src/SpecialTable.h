#ifndef __PY_SPECIAL_TABLE_H_
#define __PY_SPECIAL_TABLE_H_

#include <map>
#include <list>
#include <string>
#include <vector>
#include <glib.h>

namespace PY {

class SpecialPhrase {
public:
    SpecialPhrase (guint pos) : m_position (pos) { }

    guint position (void) const {
        return m_position;
    }

    virtual std::string text (void) = 0;
private:
    guint m_position;
};

class SpecialTable {
public:
    SpecialTable (void);
    void insert (const std::string & command, SpecialPhrase *phrase);
    gboolean lookup (const std::string &command, std::vector<std::string> &result);
private:
    gboolean load (const gchar *file);
private:
    typedef std::list<SpecialPhrase *> List;
    typedef std::map<std::string, List> Map;
    Map m_map;
};

};

#endif
