/* vim:set et sts=4: */
#ifndef __PY_PHRASE_H_
#define __PY_PHRASE_H_

#include "Types.h"

namespace PY {

typedef struct _Phrase Phrase;
struct _Phrase {
    gchar phrase[MAX_UTF8_LEN * (MAX_PHRASE_LEN + 1)];
    guint  freq;
    guint  user_freq;
    guint  pinyin_id[MAX_PHRASE_LEN][2];
    guint  len;

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
        for (guint i = 0; i < a.len; i++) {
            pinyin_id[len + i][0] = a.pinyin_id[i][0];
            pinyin_id[len + i][1] = a.pinyin_id[i][1];
        }
        len += a.len;
        return *this;
    }

    operator const gchar * (void) const {
        return phrase;
    }

};

};

#endif
