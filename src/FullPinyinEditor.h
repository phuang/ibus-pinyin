#ifndef __PY_FULL_PINYIN_EDITOR_H_
#define __PY_FULL_PINYIN_EDITOR_H_

#include "PinyinEditor.h"

namespace PY {

class FullPinyinEditor : public PinyinEditor {

public:
    FullPinyinEditor (void);

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

    gboolean reset (void) {
        gboolean retval = FALSE;
        if (m_cursor != 0) {
            m_cursor = 0;
            retval = TRUE;
        }

        if (m_text.length () != 0) {
            m_text.truncate (0);
            retval = TRUE;
        }

        if (retval)
            updatePinyin ();

        return retval;
    }

private:
    void updatePinyin (void);

};

};

#endif
