/* vim:set et sts=4: */

#include <libintl.h>
#include <string>
#include <cstdlib>
#include <ibus.h>
#include "RawEditor.h"
#include "ExtEditor.h"
#include "FullPinyinEditor.h"
#include "DoublePinyinEditor.h"
#include "BopomofoEditor.h"
#include "PinyinEngine.h"
#include "HalfFullConverter.h"
#include "Config.h"
#include "Text.h"
#include "Util.h"

#define _(text) (dgettext (GETTEXT_PACKAGE, text))

namespace PY {

/* constructor */
PinyinEngine::PinyinEngine (IBusEngine *engine)
    : Engine (engine),
      m_prev_pressed_key (IBUS_VoidSymbol),
      m_input_mode (MODE_INIT),
      m_fallback_editor (new FallbackEditor (m_props))
{
    gint i;

    if (Config::doublePinyin ())
        m_editors[MODE_INIT].reset (new DoublePinyinEditor (m_props));
    else
        m_editors[MODE_INIT].reset (new FullPinyinEditor (m_props));

    m_editors[MODE_RAW].reset (new RawEditor (m_props));
    m_editors[MODE_EXTENSION].reset (new ExtEditor (m_props));

    m_props.signalUpdateProperty ().connect (bind (&PinyinEngine::slotUpdateProperty, this, _1));

    for (i = MODE_INIT; i < MODE_LAST; i++) {
        connectEditorSignals (m_editors[i]);
    }

    connectEditorSignals (m_fallback_editor);
}

/* destructor */
PinyinEngine::~PinyinEngine (void)
{
}


#define CASHM_MASK       \
    (IBUS_CONTROL_MASK | \
    IBUS_MOD1_MASK |     \
    IBUS_SUPER_MASK |    \
    IBUS_HYPER_MASK |    \
    IBUS_META_MASK)

gboolean
PinyinEngine::processKeyEvent (guint keyval, guint keycode, guint modifiers)
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
        if (m_input_mode == MODE_INIT &&
            ((modifiers & CASHM_MASK) == 0)) {
            const String & text = m_editors[MODE_INIT]->text ();
            if (text.empty ()) {
            #if 1
                if (keyval == IBUS_i) {
                    m_input_mode = MODE_EXTENSION;
                }
            #endif
            }
            else {
                if (m_prev_pressed_key != IBUS_period) {
                    if ((keyval == IBUS_at || keyval == IBUS_colon)) {
                        m_input_mode = MODE_RAW;
                        m_editors[MODE_RAW]->setText (text, text.length ());
                        m_editors[MODE_INIT]->reset ();
                    }
                }
                else {
                    if ((keyval >= IBUS_a && keyval <= IBUS_z) ||
                        (keyval >= IBUS_A && keyval <= IBUS_Z)) {
                        String tmp = text;
                        tmp += ".";
                        m_input_mode = MODE_RAW;
                        m_editors[MODE_RAW]->setText (tmp, tmp.length ());
                        m_editors[MODE_INIT]->reset ();
                    }
                }
            }
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
PinyinEngine::focusIn (void)
{
    if (Config::doublePinyin ()) {
        if (dynamic_cast <DoublePinyinEditor *> (m_editors[MODE_INIT].get ()) == NULL) {
            m_editors[MODE_INIT].reset (new DoublePinyinEditor (m_props));
            connectEditorSignals (m_editors[MODE_INIT]);
        }
    }
    else {
        if (dynamic_cast <FullPinyinEditor *> (m_editors[MODE_INIT].get ()) == NULL) {
            m_editors[MODE_INIT].reset (new FullPinyinEditor (m_props));
            connectEditorSignals (m_editors[MODE_INIT]);
        }
    }
    registerProperties (m_props.properties ());
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
PinyinEngine::candidateClicked (guint index, guint button, guint state)
{
    m_editors[m_input_mode]->candidateClicked (index, button, state);
}

void
PinyinEngine::slotCommitText (Text & text)
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
PinyinEngine::slotUpdatePreeditText (Text & text, guint cursor, gboolean visible)
{
    updatePreeditText (text, cursor, visible);
}

void
PinyinEngine::slotShowPreeditText (void)
{
    showPreeditText ();
}

void
PinyinEngine::slotHidePreeditText (void)
{
    hidePreeditText ();
}

void
PinyinEngine::slotUpdateAuxiliaryText (Text & text, gboolean visible)
{
    updateAuxiliaryText (text, visible);
}

void
PinyinEngine::slotShowAuxiliaryText (void)
{
    showAuxiliaryText ();
}

void
PinyinEngine::slotHideAuxiliaryText (void)
{
    hideAuxiliaryText ();
}

void
PinyinEngine::slotUpdateLookupTable (LookupTable & table, gboolean visible)
{
    updateLookupTable (table, visible);
}

void
PinyinEngine::slotUpdateLookupTableFast (LookupTable & table, gboolean visible)
{
    updateLookupTableFast (table, visible);
}

void
PinyinEngine::slotShowLookupTable (void)
{
    showLookupTable ();
}

void
PinyinEngine::slotHideLookupTable (void)
{
    hideLookupTable ();
}

void
PinyinEngine::slotUpdateProperty (Property & prop)
{
    updateProperty (prop);
}

void
PinyinEngine::connectEditorSignals (EditorPtr editor)
{
    editor->signalCommitText ().connect (
        bind (&PinyinEngine::slotCommitText, this, _1));

    editor->signalUpdatePreeditText ().connect (
        bind (&PinyinEngine::slotUpdatePreeditText, this, _1, _2, _3));
    editor->signalShowPreeditText ().connect (
        bind (&PinyinEngine::slotShowPreeditText, this));
    editor->signalHidePreeditText ().connect (
        bind (&PinyinEngine::slotHidePreeditText, this));

    editor->signalUpdateAuxiliaryText ().connect (
        bind (&PinyinEngine::slotUpdateAuxiliaryText, this, _1, _2));
    editor->signalShowAuxiliaryText ().connect (
        bind (&PinyinEngine::slotShowAuxiliaryText, this));
    editor->signalHideAuxiliaryText ().connect (
        bind (&PinyinEngine::slotHideAuxiliaryText, this));

    editor->signalUpdateLookupTable ().connect (
        bind (&PinyinEngine::slotUpdateLookupTable, this, _1, _2));
    editor->signalUpdateLookupTableFast ().connect (
        bind (&PinyinEngine::slotUpdateLookupTableFast, this, _1, _2));
    editor->signalShowLookupTable ().connect (
        bind (&PinyinEngine::slotShowLookupTable, this));
    editor->signalHideLookupTable ().connect (
        bind (&PinyinEngine::slotHideLookupTable, this));
}

};

