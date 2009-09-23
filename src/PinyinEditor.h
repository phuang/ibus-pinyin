#ifndef __PY_PINYIN_EDITOR_H_
#define __PY_PINYIN_EDITOR_H_

#include <glib.h>
#include "String.h"
#include "PinyinParser.h"

#define MAX_PINYIN_LEN 64

namespace PY {

class PinyinEditor {
public:
    PinyinEditor (void);
    
    const String & text (void) const { return m_text; }
    const gchar * textAfterPinyin (void) const { return (const gchar *)m_text + m_pinyin_len; }
    const gchar * textAfterCursor (void) const { return (const gchar *)m_text + m_cursor; }
    guint cursor (void) const { return m_cursor; }
    gboolean isEmpty (void) const { return m_text.isEmpty (); }
    const PinyinArray & pinyin (void) const { return m_pinyin; }
    guint pinyinLength (void) const { return m_pinyin_len; }
    operator gboolean (void) const { return !isEmpty (); }

    /* virtual functions */
    virtual gboolean insert (gint ch) = 0;
    virtual gboolean removeCharBefore (void) = 0;
    virtual gboolean removeCharAfter (void) = 0;
    virtual gboolean removeWordBefore (void) = 0;
    virtual gboolean removeWordAfter (void) = 0;
    virtual gboolean moveCursorLeft (void) = 0;
    virtual gboolean moveCursorRight (void) = 0;
    virtual gboolean moveCursorLeftByWord (void) = 0;
    virtual gboolean moveCursorRightByWord (void) = 0;
    virtual gboolean moveCursorToBegin (void) = 0;
    virtual gboolean moveCursorToEnd (void) = 0;
    virtual gboolean reset (void) = 0;

protected:
    String      m_text;         // text buffer
    guint       m_cursor;       // cursor pos in char
    PinyinArray m_pinyin;       // pinyin array
    guint       m_pinyin_len;   // pinyin length in char

protected:
    static PinyinParser m_parser; 

};

};

#endif
