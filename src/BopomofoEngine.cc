/* vim:set et sts=4: */

#include <libintl.h>
#include <string>
#include <cstdlib>
#include <ibus.h>
#include "RawEditor.h"
#include "PunctEditor.h"
#include "ExtEditor.h"
#include "FullPinyinEditor.h"
#include "DoublePinyinEditor.h"
#include "BopomofoEditor.h"
#include "BopomofoEngine.h"
#include "HalfFullConverter.h"
#include "Config.h"
#include "Text.h"
#include "Util.h"

#define _(text) (dgettext (GETTEXT_PACKAGE, text))

namespace PY {

/* constructor */
BopomofoEngine::BopomofoEngine (IBusEngine *engine)
    : Engine (engine),
      m_prev_pressed_key (IBUS_VoidSymbol),
      m_input_mode (MODE_INIT),
      m_fallback_editor (new FallbackEditor (m_props))
{
    gint i;

    /* create editors */
    m_editors[MODE_INIT].reset (new BopomofoEditor (m_props));
    m_editors[MODE_PUNCT].reset (new PunctEditor (m_props));

    m_editors[MODE_RAW].reset (new RawEditor (m_props));
    m_editors[MODE_EXTENSION].reset (new ExtEditor (m_props));

    m_props.signalUpdateProperty ().connect (bind (&BopomofoEngine::slotUpdateProperty, this, _1));

    for (i = MODE_INIT; i < MODE_LAST; i++) {
        connectEditorSignals (m_editors[i]);
    }

    connectEditorSignals (m_fallback_editor);
}

/* destructor */
BopomofoEngine::~BopomofoEngine (void)
{
}


#define CASHM_MASK       \
    (IBUS_CONTROL_MASK | \
    IBUS_MOD1_MASK |     \
    IBUS_SUPER_MASK |    \
    IBUS_HYPER_MASK |    \
    IBUS_META_MASK)

gboolean
BopomofoEngine::processKeyEvent (guint keyval, guint keycode, guint modifiers)
{
    gboolean retval = FALSE;

    /* check Shift + Release hotkey,
     * and then ignore other Release key event */
    if (modifiers & IBUS_RELEASE_MASK) {
        /* press and release keyval are same,
         * and no other key event between the press and release ket event*/
        if (m_prev_pressed_key == keyval) {
            if (keyval == IBUS_Shift_L || keyval == IBUS_Shift_R) {
                if (!m_editors[MODE_INIT]->text ().empty ())
                    m_editors[MODE_INIT]->reset ();
                m_props.toggleModeChinese ();
            }
        }
        return TRUE;
    }

    if (m_props.modeChinese ()) {
        if (G_UNLIKELY (m_input_mode == MODE_INIT &&
                        m_editors[MODE_INIT]->text ().empty () &&
                        (modifiers & CASHM_MASK) == 0) &&
                        keyval == IBUS_grave) {
            /* if BopomofoEditor is empty and get a grave key,
             * switch current editor to PunctEditor */
            m_input_mode = MODE_PUNCT;
        }

        retval = m_editors[m_input_mode]->processKeyEvent (keyval, keycode, modifiers);
        if (G_UNLIKELY (retval &&
                        m_input_mode != MODE_INIT &&
                        m_editors[m_input_mode]->text ().empty ()))
            m_input_mode = MODE_INIT;
    }

    if (G_UNLIKELY (!retval))
        retval = m_fallback_editor->processKeyEvent (keyval, keycode, modifiers);

    /* store ignored key event by editors */
    m_prev_pressed_key = retval ? IBUS_VoidSymbol : keyval;

    return retval;
}

void
BopomofoEngine::focusIn (void)
{
}

void
BopomofoEngine::pageUp (void)
{
    m_editors[m_input_mode]->pageUp ();
}

void
BopomofoEngine::pageDown (void)
{
    m_editors[m_input_mode]->pageDown ();
}

void
BopomofoEngine::cursorUp (void)
{
    m_editors[m_input_mode]->cursorUp ();
}

void
BopomofoEngine::cursorDown (void)
{
    m_editors[m_input_mode]->cursorDown ();
}

inline void
BopomofoEngine::showSetupDialog (void)
{
    g_spawn_command_line_async (LIBEXECDIR"/ibus-setup-pinyin", NULL);
}

gboolean
BopomofoEngine::propertyActivate (const gchar *prop_name, guint prop_state)
{
    const static std::string setup ("setup");
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
BopomofoEngine::candidateClicked (guint index, guint button, guint state)
{
    m_editors[m_input_mode]->candidateClicked (index, button, state);
}

void
BopomofoEngine::slotCommitText (Text & text)
{
    commitText (text);
    if (m_input_mode != MODE_INIT)
        m_input_mode = MODE_INIT;
    if (text.text ())
        static_cast<FallbackEditor*> (m_fallback_editor.get ())->setPrevCommittedChar (*text.text ());
    else
        static_cast<FallbackEditor*> (m_fallback_editor.get ())->setPrevCommittedChar (0);
}

void
BopomofoEngine::slotUpdatePreeditText (Text & text, guint cursor, gboolean visible)
{
    updatePreeditText (text, cursor, visible);
}

void
BopomofoEngine::slotShowPreeditText (void)
{
    showPreeditText ();
}

void
BopomofoEngine::slotHidePreeditText (void)
{
    hidePreeditText ();
}

void
BopomofoEngine::slotUpdateAuxiliaryText (Text & text, gboolean visible)
{
    updateAuxiliaryText (text, visible);
}

void
BopomofoEngine::slotShowAuxiliaryText (void)
{
    showAuxiliaryText ();
}

void
BopomofoEngine::slotHideAuxiliaryText (void)
{
    hideAuxiliaryText ();
}

void
BopomofoEngine::slotUpdateLookupTable (LookupTable & table, gboolean visible)
{
    updateLookupTable (table, visible);
}

void
BopomofoEngine::slotUpdateLookupTableFast (LookupTable & table, gboolean visible)
{
    updateLookupTableFast (table, visible);
}

void
BopomofoEngine::slotShowLookupTable (void)
{
    showLookupTable ();
}

void
BopomofoEngine::slotHideLookupTable (void)
{
    hideLookupTable ();
}

void
BopomofoEngine::slotUpdateProperty (Property & prop)
{
    updateProperty (prop);
}

void
BopomofoEngine::connectEditorSignals (EditorPtr editor)
{
    editor->signalCommitText ().connect (
        bind (&BopomofoEngine::slotCommitText, this, _1));

    editor->signalUpdatePreeditText ().connect (
        bind (&BopomofoEngine::slotUpdatePreeditText, this, _1, _2, _3));
    editor->signalShowPreeditText ().connect (
        bind (&BopomofoEngine::slotShowPreeditText, this));
    editor->signalHidePreeditText ().connect (
        bind (&BopomofoEngine::slotHidePreeditText, this));

    editor->signalUpdateAuxiliaryText ().connect (
        bind (&BopomofoEngine::slotUpdateAuxiliaryText, this, _1, _2));
    editor->signalShowAuxiliaryText ().connect (
        bind (&BopomofoEngine::slotShowAuxiliaryText, this));
    editor->signalHideAuxiliaryText ().connect (
        bind (&BopomofoEngine::slotHideAuxiliaryText, this));

    editor->signalUpdateLookupTable ().connect (
        bind (&BopomofoEngine::slotUpdateLookupTable, this, _1, _2));
    editor->signalUpdateLookupTableFast ().connect (
        bind (&BopomofoEngine::slotUpdateLookupTableFast, this, _1, _2));
    editor->signalShowLookupTable ().connect (
        bind (&BopomofoEngine::slotShowLookupTable, this));
    editor->signalHideLookupTable ().connect (
        bind (&BopomofoEngine::slotHideLookupTable, this));
}

};

