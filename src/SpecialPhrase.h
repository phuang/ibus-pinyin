#ifndef __PY_SPECIAL_PHRASE_H_
#define __PY_SPECIAL_PHRASE_H_

#include <string>
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

};

#endif
