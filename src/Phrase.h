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
    struct {
        guint8 sheng;
        guint8 yun;
    } pinyin_id[MAX_PHRASE_LEN];
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
