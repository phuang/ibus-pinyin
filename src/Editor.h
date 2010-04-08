#ifndef __PY_EDITOR_H_
#define __PY_EDITOR_H_

#include <glib.h>
#include <sigc++/sigc++.h>
#include "Text.h"
#include "LookupTable.h"
#include "PinyinProperties.h"

namespace PY {

class Editor {
public:
    Editor (PinyinProperties & prop);
    virtual ~Editor (void);

    virtual gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    virtual void pageUp (void);
    virtual void pageDown (void);
    virtual void cursorUp (void);
    virtual void cursorDown (void);
    virtual void update (void);
    virtual void reset (void);
    virtual void candidateClicked (guint index, guint button, guint state);

    const String & text (void) const { return m_text; }
    void setText (const String & text, guint cursor) {
        m_text = text;
        m_cursor = cursor;
    }

    /* signals */
    sigc::signal <void, Text &> & signalCommitText (void) { return m_signal_commit_text; }
    sigc::signal <void, Text &, guint, gboolean> & signalUpdatePreeditText (void) { return m_signal_update_preedit_text; }
    sigc::signal <void> & signalShowPreeditText (void) { return m_signal_show_preedit_text; }
    sigc::signal <void> & signalHidePreeditText (void) { return m_signal_hide_preedit_text; }
    sigc::signal <void, Text &, gboolean> & signalUpdateAuxiliaryText (void) { return m_signal_update_auxiliary_text; }
    sigc::signal <void> & signalShowAuxiliaryText (void) { return m_signal_show_auxiliary_text; }
    sigc::signal <void> & signalHideAuxiliaryText (void) { return m_signal_hide_auxiliary_text; }
    sigc::signal <void, LookupTable &, gboolean> & signalUpdateLookupTable (void) { return m_signal_update_lookup_table; }
    sigc::signal <void, LookupTable &, gboolean> & signalUpdateLookupTableFast (void) { return m_signal_update_lookup_table_fast; }
    sigc::signal <void> & signalShowLookupTable (void) { return m_signal_show_lookup_table; }
    sigc::signal <void> & signalHideLookupTable (void) { return m_signal_hide_lookup_table; }

protected:
    /* methods */
    void commitText (Text & text) {
        m_signal_commit_text.emit (text);
    }

    void updatePreeditText (Text & text, guint cursor, gboolean visible) {
        m_signal_update_preedit_text.emit (text, cursor, visible);
    }

    void showPreeditText (void) {
        m_signal_show_preedit_text.emit ();
    }

    void hidePreeditText (void) {
        m_signal_hide_preedit_text.emit ();
    }

    void updateAuxiliaryText (Text & text, gboolean visible) {
        m_signal_update_auxiliary_text.emit (text, visible);
    }

    void showAuxiliaryText (void) {
        m_signal_show_auxiliary_text.emit ();
    }

    void hideAuxiliaryText (void) {
        m_signal_hide_auxiliary_text.emit ();
    }

    void updateLookupTable (LookupTable & table, gboolean visible) {
        m_signal_update_lookup_table.emit (table, visible);
    }

    void updateLookupTableFast (LookupTable & table, gboolean visible) {
        m_signal_update_lookup_table_fast.emit (table, visible);
    }

    void showLookupTable (void) {
        m_signal_show_lookup_table.emit ();
    }

    void hideLookupTable (void) {
        m_signal_hide_lookup_table.emit ();
    }

protected:
    /* signals */
    sigc::signal <void, Text &> m_signal_commit_text;
    sigc::signal <void, Text &, guint, gboolean> m_signal_update_preedit_text;
    sigc::signal <void> m_signal_show_preedit_text;
    sigc::signal <void> m_signal_hide_preedit_text;
    sigc::signal <void, Text &, gboolean> m_signal_update_auxiliary_text;
    sigc::signal <void> m_signal_show_auxiliary_text;
    sigc::signal <void> m_signal_hide_auxiliary_text;
    sigc::signal <void, LookupTable &, gboolean> m_signal_update_lookup_table;
    sigc::signal <void, LookupTable &, gboolean> m_signal_update_lookup_table_fast;
    sigc::signal <void> m_signal_show_lookup_table;
    sigc::signal <void> m_signal_hide_lookup_table;

protected:
    String m_text;
    guint  m_cursor;
    PinyinProperties & m_props;
};

};

#endif
