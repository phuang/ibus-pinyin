/* vim:set et sts=4: */
#ifndef __PY_PIN_YIN_ENGINE_H__
#define __PY_PIN_YIN_ENGINE_H__

#include <ibus.h>
#include "Pointer.h"
#include "Database.h"
#include "FullPinyinEditor.h"
#include "PhraseEditor.h"
#include "LookupTable.h"
#include "Property.h"
#include "Config.h"

namespace PY {

class PinyinEngine {
public:
    PinyinEngine (IBusEngine *engine);
    ~PinyinEngine (void);

    gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    void focusIn (void);
    void focusOut (void) {}

    void reset (gboolean need_update = TRUE) {
        m_pinyin_editor->reset ();
        update (need_update);
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

    void propertyActivate (const gchar *prop_name, guint prop_state);

    void update (gboolean now = TRUE) {
        if (G_UNLIKELY (now || m_need_update >= 4)) {
            updatePhraseEditor ();
            updateLookupTable ();
            updateAuxiliaryText ();
            updatePreeditText ();
            m_need_update = 0;
        } else {
            if (m_need_update == 0) {
                g_idle_add ((GSourceFunc) delayUpdateHandler, this);
            }
            m_need_update ++;
        }
    }

private:
    gboolean processPinyin (guint keyval, guint keycode, guint modifiers);
    gboolean processNumber (guint keyval, guint keycode, guint modifiers);
    gboolean processPunct (guint keyval, guint keycode, guint modifiers);
    gboolean processOthers (guint keyval, guint keycode, guint modifiers);

private:
    gboolean isEmpty (void) { return m_pinyin_editor->isEmpty (); }

    void commit (void);
    void commit (gchar ch);
    void commit (gunichar ch);
    void commit (const gchar *str);
    void commit (const String &str);

    void toggleModeChinese (void);
    void toggleModeFull (void);
    void toggleModeFullPunct (void);
    void showSetupDialog (void);

    gboolean selectCandidate (guint i);
    gboolean resetCandidate (guint i);
    void updatePreeditText (void);
    void updateAuxiliaryText (void);
    void updateLookupTable (void);
    void updatePhraseEditor (void);

    static gboolean delayUpdateHandler (PinyinEngine *pinyin) {
        if (pinyin->m_need_update > 0)
            pinyin->update (TRUE);
        return FALSE;
    }

private:
    Pointer<IBusEngine>  m_engine;      // engine pointer

    PinyinEditor *m_pinyin_editor;      // pinyin editor
    PhraseEditor m_phrase_editor;       // phrase editor
    String m_buffer;                    // string buffer

    gint m_need_update;                 // need update preedit, aux, or lookup table

    LookupTable m_lookup_table;
    Property    m_prop_chinese;
    Property    m_prop_full;
    Property    m_prop_full_punct;
    Property    m_prop_setup;
    PropList    m_props;

    gboolean m_mode_chinese;
    gboolean m_mode_full;
    gboolean m_mode_full_punct;

    gboolean m_quote;
    gboolean m_double_quote;

    guint    m_prev_pressed_key;

};

};

#endif
