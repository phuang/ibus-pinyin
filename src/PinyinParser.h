/* vim:set et sts=4: */
#ifndef __PY_PARSER_H__
#define __PY_PARSER_H__

#include <glib.h>
#include "String.h"
#include "PinyinArray.h"

namespace PY {

class PinyinParser {
public:
    static guint parse (const String &pinyin,      // pinyin string
                        gint          len,         // length of pinyin string
                        guint         option,      // option
                        PinyinArray  &result,      // store pinyin in result
                        guint         max);        // max length of the result
    static const Pinyin * isPinyin (gint sheng, gint yun, guint option);
    static guint parse_bopomofo (const std::wstring   &bopomofo,
                                 gint            len,
                                 guint           option,
                                 PinyinArray    &result,
                                 guint           max);
    static gboolean isBopomofoToneChar (const wchar_t ch);

};
};
#endif
