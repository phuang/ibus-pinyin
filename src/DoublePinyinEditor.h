#ifndef __PY_DOUBLE_PINYIN_EDITOR_H_
#define __PY_DOUBLE_PINYIN_EDITOR_H_

#include "PinyinEditor.h"

namespace PY {

class DoublePinyinEditor : public PinyinEditor {

public:
    DoublePinyinEditor (void);

    gboolean insert (gint ch);

    gboolean removeCharBefore (void);
    gboolean removeCharAfter (void);
    gboolean removeWordBefore (void);
    gboolean removeWordAfter (void);

    gboolean moveCursorLeft (void);
    gboolean moveCursorRight (void);
    gboolean moveCursorLeftByWord (void);
    gboolean moveCursorRightByWord (void);
    gboolean moveCursorToBegin (void);
    gboolean moveCursorToEnd (void);

    gboolean reset (void);
private:
    void updatePinyin (void);
    const Pinyin *isPinyin (gchar i, gchar j);

};

};

#endif
