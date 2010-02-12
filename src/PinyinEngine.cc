/* vim:set et sts=4: */

#include <ibus.h>
#include <string.h>
#include <libintl.h>
#include "RawEditor.h"
#include "ExtEditor.h"
#include "FullPinyinEditor.h"
#include "DoublePinyinEditor.h"
#include "PinyinEngine.h"
#include "HalfFullConverter.h"
#include "SimpTradConverter.h"
#include "Config.h"
#include "Text.h"
#include "Util.h"

#define _(text) (dgettext (GETTEXT_PACKAGE, text))

namespace PY {

/* constructor */
PinyinEngine::PinyinEngine (IBusEngine *engine)
    : m_engine (engine),
      m_need_update (0),
      m_prev_pressed_key (0),
      m_input_mode (MODE_INIT),
      m_fallback_editor (m_props)
{
    gint i;
    /* create editors */
    if (Config::doublePinyin ())
        m_editors[MODE_INIT] = new DoublePinyinEditor (m_props);
    else
        m_editors[MODE_INIT] = new FullPinyinEditor (m_props);

    m_editors[MODE_EXTENSION] = new ExtEditor (m_props);

    m_props.signalUpdateProperty ().connect (sigc::mem_fun (*this, &PinyinEngine::slotUpdateProperty));

    for (i = MODE_INIT; i < MODE_LAST; i++) {
        connectEditorSignals (m_editors[i]);
    }

    connectEditorSignals (&m_fallback_editor);
}

/* destructor */
PinyinEngine::~PinyinEngine (void)
{
    for (gint i = 0; i < MODE_LAST; i++) {
        delete m_editors[i];
    }
}

gboolean
PinyinEngine::processKeyEvent (guint keyval, guint keycode, guint modifiers)
{
    gboolean retval;

    if (modifiers & IBUS_RELEASE_MASK) {
        if (m_prev_pressed_key == keyval) {
            if (keyval == IBUS_Shift_L || keyval == IBUS_Shift_R) {
                m_props.toggleModeChinese ();
            }
        }
        m_prev_pressed_key = 0;
        return TRUE;
    }

    retval = m_props.modeChinese () && m_editors[m_input_mode]->processKeyEvent (keyval, keycode, modifiers);

    if (G_UNLIKELY (!retval))
        retval = m_fallback_editor.processKeyEvent (keyval, keycode, modifiers);

    m_prev_pressed_key = retval ? 0 : keyval;

    return retval;
}

void
PinyinEngine::focusIn (void)
{
    /* reset pinyin parser */
    if (Config::doublePinyin ()) {
        if (dynamic_cast <DoublePinyinEditor *> (m_editors[MODE_INIT]) == NULL)
            delete m_editors[MODE_INIT];
        m_editors[MODE_INIT] = new DoublePinyinEditor (m_props);
        connectEditorSignals (m_editors[MODE_INIT]);
    }
    else {
        if (dynamic_cast <FullPinyinEditor *> (m_editors[MODE_INIT]) == NULL)
            delete m_editors[MODE_INIT];
        m_editors[MODE_INIT] = new FullPinyinEditor (m_props);
        connectEditorSignals (m_editors[MODE_INIT]);
    }
    ibus_engine_register_properties (m_engine, m_props.properties ());
}


void
PinyinEngine::pageUp (void)
{
    m_editors[m_input_mode]->pageUp ();
}

void
PinyinEngine::pageDown (void)
{
    m_editors[m_input_mode]->pageDown ();
}

void
PinyinEngine::cursorUp (void)
{
    m_editors[m_input_mode]->cursorUp ();
}

void
PinyinEngine::cursorDown (void)
{
    m_editors[m_input_mode]->cursorDown ();
}

inline void
PinyinEngine::showSetupDialog (void)
{
    g_spawn_command_line_async (LIBEXECDIR"/ibus-setup-pinyin", NULL);
}

gboolean
PinyinEngine::propertyActivate (const gchar *prop_name, guint prop_state)
{
    const static StaticString setup ("setup");
    if (m_props.propertyActivate (prop_name, prop_state)) {
        return TRUE;
    }
    else if (setup == prop_name) {
        showSetupDialog ();
        return TRUE;
    }
    return FALSE;
}

void
PinyinEngine::candidateClicked (guint index, guint button, guint state)
{
    m_editors[m_input_mode]->candidateClicked (index, button, state);
}

void
PinyinEngine::slotCommitText (Text & text)
{
    ibus_engine_commit_text (m_engine, text);
}

void
PinyinEngine::slotUpdatePreeditText (Text & text, guint cursor, gboolean visible)
{
    ibus_engine_update_preedit_text (m_engine, text, cursor, visible);
}

void
PinyinEngine::slotShowPreeditText (void)
{
    ibus_engine_show_preedit_text (m_engine);
}

void
PinyinEngine::slotHidePreeditText (void)
{
    ibus_engine_hide_preedit_text (m_engine);
}

void
PinyinEngine::slotUpdateAuxiliaryText (Text & text, gboolean visible)
{
    ibus_engine_update_auxiliary_text (m_engine, text, visible);
}

void
PinyinEngine::slotShowAuxiliaryText (void)
{
    ibus_engine_show_auxiliary_text (m_engine);
}

void
PinyinEngine::slotHideAuxiliaryText (void)
{
    ibus_engine_hide_auxiliary_text (m_engine);
}

void
PinyinEngine::slotUpdateLookupTable (LookupTable & table, gboolean visible)
{
    ibus_engine_update_lookup_table (m_engine, table, visible);
}

void
PinyinEngine::slotUpdateLookupTableFast (LookupTable & table, gboolean visible)
{
    ibus_engine_update_lookup_table_fast (m_engine, table, visible);
}

void
PinyinEngine::slotShowLookupTable (void)
{
    ibus_engine_show_lookup_table (m_engine);
}

void
PinyinEngine::slotHideLookupTable (void)
{
    ibus_engine_hide_lookup_table (m_engine);
}

void
PinyinEngine::slotUpdateProperty (Property & prop)
{
    ibus_engine_update_property (m_engine, prop);
}

void
PinyinEngine::connectEditorSignals (Editor *editor)
{
    editor->signalCommitText ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotCommitText));

    editor->signalUpdatePreeditText ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotUpdatePreeditText));
    editor->signalShowPreeditText ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotShowPreeditText));
    editor->signalHidePreeditText ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotHidePreeditText));

    editor->signalUpdateAuxiliaryText ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotUpdateAuxiliaryText));
    editor->signalShowAuxiliaryText ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotShowAuxiliaryText));
    editor->signalHideAuxiliaryText ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotHideAuxiliaryText));

    editor->signalUpdateLookupTable ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotUpdateLookupTable));
    editor->signalUpdateLookupTableFast ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotUpdateLookupTableFast));
    editor->signalShowLookupTable ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotShowLookupTable));
    editor->signalHideLookupTable ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotHideLookupTable));

}

};

