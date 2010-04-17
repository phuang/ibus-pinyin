#ifndef __PY_SPECIAL_PHRASE_H_
#define __PY_SPECIAL_PHRASE_H_

#include <string>
#include <boost/shared_ptr.hpp>
#include <glib.h>

namespace PY {

class SpecialPhrase {
public:
    SpecialPhrase (guint pos) : m_position (pos) { }
    virtual ~SpecialPhrase (void);

    guint position (void) const {
        return m_position;
    }

    virtual std::string text (void) = 0;

private:
    guint m_position;
};

typedef boost::shared_ptr<SpecialPhrase> SpecialPhrasePtr;

};

#endif
