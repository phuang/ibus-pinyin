/* vim:set et sts=4: */
#ifndef __PY_PIN_YIN_ENGINE_H__
#define __PY_PIN_YIN_ENGINE_H__

#include <ibus.h>
#include "Pointer.h"
#include "Database.h"
#include "FullPinyinEditor.h"
#include "PhraseEditor.h"
#include "RawEditor.h"
#include "LookupTable.h"
#include "Property.h"
#include "Config.h"
#include "Editor.h"
#include "PinyinProperties.h"

namespace PY {

class PinyinEngine {
public:
    PinyinEngine (IBusEngine *engine);
    ~PinyinEngine (void);

    gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    void focusIn (void);
    void focusOut (void) {
        reset ();
    }

    void reset (gboolean need_update = TRUE) {
        resetQuote ();
        m_input_mode = MODE_INIT;
        for (gint i = 0; i < MODE_LAST; i++) {
            m_editors[i]->reset ();
        }
        updateUI (need_update);
    }

    void resetQuote (void) {
        m_quote = TRUE;
        m_double_quote = TRUE;
    }

    void enable (void) {}
    void disable (void) {}
    void pageUp (void);
    void pageDown (void);
    void cursorUp (void);
    void cursorDown (void);

    gboolean propertyActivate (const gchar *prop_name, guint prop_state);
    void candidateClicked (guint index, guint button, guint state);

    void updateUI (gboolean now = TRUE) {
    #if 0
        if (G_UNLIKELY (now || m_need_update >= 4)) {
            updateLookupTable ();
            updateAuxiliaryText ();
            updatePreeditText ();
            m_need_update = 0;
        } else {
            if (m_need_update == 0) {
                g_idle_add ((GSourceFunc) delayUpdateUIHandler, this);
            }
            m_need_update ++;
        }
    #endif
    }

private:
    gboolean processPunct (guint keyval, guint keycode, guint modifiers);
#if 0
    gboolean processPinyin (guint keyval, guint keycode, guint modifiers);
    gboolean processCapitalLetter (guint keyval, guint keycode, guint modifiers);
    gboolean processNumber (guint keyval, guint keycode, guint modifiers);
    gboolean processSpace (guint keyval, guint keycode, guint modifiers);
    gboolean processOthers (guint keyval, guint keycode, guint modifiers);
#endif

private:
    // gboolean isEmpty (void) { return m_pinyin_editor->isEmpty (); }

    void commit (void);
    void commit (gchar ch);
    void commit (gunichar ch);
    void commit (const gchar *str);
    void commit (const String &str);

    void toggleModeChinese (void);
    void toggleModeFull (void);
    void toggleModeFullPunct (void);
    void toggleModeSimp (void);
    void showSetupDialog (void);


    static gboolean delayUpdateUIHandler (PinyinEngine *pinyin) {
        if (pinyin->m_need_update > 0)
            pinyin->updateUI (TRUE);
        return FALSE;
    }

    void connectEditorSignals (Editor *editor);

private:
    void slotCommitText (Text & text);
    void slotUpdatePreeditText (Text & text, guint cursor, gboolean visible);
    void slotShowPreeditText (void);
    void slotHidePreeditText (void);
    void slotUpdateAuxiliaryText (Text & text, gboolean visible);
    void slotShowAuxiliaryText (void);
    void slotHideAuxiliaryText (void);
    void slotUpdateLookupTable (LookupTable &table, gboolean visible);
    void slotUpdateLookupTableFast (LookupTable &table, gboolean visible);
    void slotShowLookupTable (void);
    void slotHideLookupTable (void);
    void slotUpdateProperty (Property & prop);

private:
    Pointer<IBusEngine>  m_engine;      // engine pointer

    String m_buffer;                    // string buffer

    gint m_need_update;                 // need update preedit, aux, or lookup table

    LookupTable m_lookup_table;
    PinyinProperties m_props;

    gboolean m_quote;
    gboolean m_double_quote;

    guint    m_prev_pressed_key;
    gboolean m_prev_pressed_key_result;
    gunichar m_prev_commited_char;

    enum {
        MODE_INIT = 0,          // init mode
        MODE_RAW,               // raw mode
        MODE_ENGLISH,           // press v into English input mode
        MODE_STROKE,            // press u into stroke input mode
        MODE_EXTENSION,         // press i into extension input mode
        MODE_LAST,
    } m_input_mode;

    Editor *m_editors[MODE_LAST];
};

};

#endif
