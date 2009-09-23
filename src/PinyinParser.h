/* vim:set et sts=4: */
#ifndef __PY_PARSER_H__
#define __PY_PARSER_H__

#include <glib.h>
#include "String.h"
#include "PinyinArray.h"

namespace PY {

class PinyinParser {

public:
    PinyinParser (void) {}
    ~PinyinParser (void) {}

    guint parse (const String &pinyin,      // pinyin string
                 gint          len,         // length of pinyin string
                 guint         option,      // option
                 PinyinArray  &result,      // store pinyin in result
                 guint         max);        // max length of the result
    const Pinyin * isPinyin (gint sheng, gint yun, guint option);
};

};
#endif
