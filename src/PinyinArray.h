#ifndef __PY_PINYIN_ARRAY_H_
#define __PY_PINYIN_ARRAY_H_

#include "Types.h"
#include "Array.h"

namespace PY {

struct PinyinSegment {
    const Pinyin *pinyin;
    guint begin;
    guint len;

    PinyinSegment () : pinyin (NULL), begin (0), len (0) {}

    PinyinSegment (const PinyinSegment &segment) {
        pinyin = segment.pinyin;
        begin = segment.begin;
        len = segment.len;
    }

    void set (const Pinyin *pinyin, guint begin, guint len) {
        this->pinyin = pinyin;
        this->begin = begin;
        this->len = len;
    }

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

class PinyinArray: public Array<PinyinSegment> {
public:
    PinyinArray (guint init_size) : Array<PinyinSegment> (init_size) {}
    void append (const Pinyin *pinyin, guint begin, guint len) {
        PinyinSegment segment;
        segment.pinyin = pinyin;
        segment.begin = begin;
        segment.len = len;
        push_back (segment);
    }
};

};

#endif
