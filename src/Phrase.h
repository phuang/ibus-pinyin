/* vim:set et sts=4: */
#ifndef __PY_PHRASE_H_
#define __PY_PHRASE_H_

#include <cstring>
#include "Types.h"

namespace PY {

#define PHRASE_LEN_IN_BYTE (MAX_UTF8_LEN * (MAX_PHRASE_LEN + 1))

struct Phrase {
    gchar phrase[PHRASE_LEN_IN_BYTE];
    guint freq;
    guint user_freq;
    guint8 pinyin_id[MAX_PHRASE_LEN][2];
    guint len;

    void reset (void) {
        phrase[0] = 0;
        freq = 0;
        user_freq = 0;
        len = 0;
    }

    gboolean empty (void) const {
        return len == 0;
    }

    Phrase & operator += (const Phrase & a) {
        g_assert (len + a.len <= MAX_PHRASE_LEN);
        g_strlcat (phrase, a.phrase, sizeof (phrase));
        std::memcpy (pinyin_id + len, a.pinyin_id, a.len << 1);
        len += a.len;
        return *this;
    }

    operator const gchar * (void) const {
        return phrase;
    }

};

};

#endif
