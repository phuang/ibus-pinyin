#ifndef __PY_PINYIN_ARRAY_H_
#define __PY_PINYIN_ARRAY_H_

#include <vector>
#include "Types.h"

namespace PY {

struct PinyinSegment {
    const Pinyin *pinyin;
    guint begin;
    guint len;

    PinyinSegment (const Pinyin *pinyin = NULL, guint begin = 0, guint len = 0)
        : pinyin (pinyin), begin (begin), len (len) {}

    operator const Pinyin * (void) const {
        return pinyin;
    }

    const Pinyin * operator-> (void) const {
        return pinyin;
    }

    gboolean operator == (const PinyinSegment & p) const {
        return (pinyin == p.pinyin) && (begin == p.begin) && (len == p.len);
    }

    gboolean operator == (const Pinyin *p) const {
        return pinyin == p;
    }
};

class PinyinArray: public std::vector<PinyinSegment> {
public:
    PinyinArray (guint init_size = 0) {
        std::vector<PinyinSegment>::reserve (init_size);
    }

    void append (const Pinyin *pinyin, guint begin, guint len) {
        push_back (PinyinSegment (pinyin, begin, len));
    }
};

};

#endif
