#ifndef __PY_PINYIN_EDITOR_H_
#define __PY_PINYIN_EDITOR_H_

#include <glib.h>
#include "Editor.h"
#include "Database.h"
#include "PinyinParser.h"
#include "PhraseEditor.h"

namespace PY {

#define MAX_PINYIN_LEN 64

class PinyinEditor : public Editor {
public:
    PinyinEditor (PinyinProperties & props);

public:
    /* virtual functions */
    virtual gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    virtual void pageUp (void);
    virtual void pageDown (void);
    virtual void cursorUp (void);
    virtual void cursorDown (void);
    virtual void update (void);
    virtual void candidateClicked (guint index, guint button, guint state);
#if 0
    virtual void reset (void);
#endif
protected:

    gboolean processPinyin (guint keyval, guint keycode, guint modifiers);
    gboolean processCapitalLetter (guint keyval, guint keycode, guint modifiers);
    gboolean processNumber (guint keyval, guint keycode, guint modifiers);
    gboolean processPunct (guint keyval, guint keycode, guint modifiers);
    gboolean processSpace (guint keyval, guint keycode, guint modifiers);
    gboolean processOthers (guint keyval, guint keycode, guint modifiers);

    void updatePreeditText (void);
    void updatePreeditTextInTypingMode (void);
    void updatePreeditTextInEditingMode (void);
    void updateAuxiliaryText (void);
    void updateLookupTable (void);

    void updatePhraseEditor (void);

    gboolean selectCandidate (guint i);
    gboolean selectCandidateInPage (guint i);
    gboolean resetCandidate (guint i);
    gboolean resetCandidateInPage (guint i);

    void commit (void);
    void commit (const gchar *str);

    const String & text (void) const { return m_text; }
    const gchar * textAfterPinyin (void) const { return (const gchar *)m_text + m_pinyin_len; }
    const gchar * textAfterPinyin (guint i) const {
        g_assert (i <= m_pinyin.length ());
        if ( G_UNLIKELY (i == 0))
            return m_text;
        i--;
        return (const gchar *)m_text + m_pinyin[i].begin + m_pinyin[i].len;
    }
    const gchar * textAfterCursor (void) const { return (const gchar *)m_text + m_cursor; }
    guint cursor (void) const { return m_cursor; }
    gboolean isEmpty (void) const { return m_buffer.isEmpty (); }
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

protected:
    PinyinArray m_pinyin;       // pinyin array
    guint       m_pinyin_len;   // pinyin length in char
    String      m_buffer;       // temp buffer
    PhraseEditor m_phrase_editor;
    LookupTable m_lookup_table;

protected:
    static PinyinParser m_parser;
};
};

#endif
