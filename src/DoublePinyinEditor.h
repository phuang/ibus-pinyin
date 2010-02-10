#ifndef __PY_DOUBLE_PINYIN_EDITOR_H_
#define __PY_DOUBLE_PINYIN_EDITOR_H_

#include "PinyinEditor.h"

namespace PY {

class DoublePinyinEditor : public PinyinEditor {

public:
    DoublePinyinEditor (PinyinProperties & props);

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

    /* override virtual functions */
    gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    void reset (void);

private:
    void updatePinyin (void);
    const Pinyin *isPinyin (gchar i, gchar j);

};

};

#endif
