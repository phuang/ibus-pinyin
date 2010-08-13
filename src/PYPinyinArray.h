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
#ifndef __PY_PINYIN_ARRAY_H_
#define __PY_PINYIN_ARRAY_H_

#include <vector>
#include "PYTypes.h"

namespace PY {

struct PinyinSegment {
    const Pinyin *pinyin;
    guint begin;
    guint len;

    PinyinSegment (const Pinyin *pinyin = NULL, guint begin = 0, guint len = 0)
        : pinyin (pinyin), begin (begin), len (len) { }

    operator const Pinyin * (void) const
    {
        return pinyin;
    }

    const Pinyin * operator-> (void) const
    {
        return pinyin;
    }

    gboolean operator == (const PinyinSegment & p) const
    {
        return (pinyin == p.pinyin) && (begin == p.begin) && (len == p.len);
    }

    gboolean operator == (const Pinyin *p) const
    {
        return pinyin == p;
    }
};

class PinyinArray: public std::vector<PinyinSegment> {
public:
    PinyinArray (guint init_size = 0)
    {
        std::vector<PinyinSegment>::reserve (init_size);
    }

    void append (const Pinyin *pinyin, guint begin, guint len)
    {
        push_back (PinyinSegment (pinyin, begin, len));
    }
};

};

#endif
