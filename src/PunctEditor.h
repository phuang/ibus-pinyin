/* vim:set et sts=4: */
#ifndef __PY_PUNCT_EDITOR__
#define __PY_PUNCT_EDITOR__

#include <glib.h>
#include "Editor.h"
#include "PhraseEditor.h"

namespace PY {

class PunctEditor : public Editor {
public:
    PunctEditor (PinyinProperties &props);

    virtual gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    virtual void pageUp (void);
    virtual void pageDown (void);
    virtual void cursorUp (void);
    virtual void cursorDown (void);
    virtual void update (void);
    virtual void reset (void);
    virtual void candidateClicked (guint index, guint button, guint state);

    virtual gboolean processPunct (guint keyval, guint keycode, guint modifiers);
    virtual gboolean processSpace (guint keyval, guint keycode, guint modifiers);
    virtual gboolean insert (gchar ch);
    virtual void updateLookupTable (void);
    virtual void updateAuxiliaryText (void);
    virtual void updatePreeditText (void);
    virtual gboolean selectCandidate (guint i);
    virtual gboolean selectCandidateInPage (guint i);
    virtual void commit (const gchar *str);
    virtual void commit (void);
    virtual gboolean removeCharBefore (void);
    virtual gboolean removeCharAfter (void);
    virtual gboolean moveCursorLeft (void);
    virtual gboolean moveCursorRight (void);
    virtual gboolean moveCursorToBegin (void);
    virtual gboolean moveCursorToEnd (void);

    void fillLookupTable (void);
    void updatePunctCandidates (gchar ch);
protected:
    enum {
        MODE_DISABLE,
        MODE_INIT,
        MODE_NORMAL,
    } m_punct_mode;
    LookupTable m_lookup_table;
    String m_buffer;
    std::vector<const gchar *> m_selected_puncts;
    std::vector<const gchar *> m_punct_candidates;

};

};
#endif
