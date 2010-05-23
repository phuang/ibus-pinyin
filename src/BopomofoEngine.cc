/* vim:set et ts=4 sts=4:
 *
 * ibus-pinyin - The Chinese PinYin engine for IBus
 *
 * Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
 * Copyright (c) 2010 BYVoid <byvoid1@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <libintl.h>
#include <string>
#include <cstdlib>
#include "RawEditor.h"
#include "PunctEditor.h"
#include "ExtEditor.h"
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

    m_props.signalUpdateProperty ().connect (bind (&BopomofoEngine::updateProperty, this, _1));

    for (i = MODE_INIT; i < MODE_LAST; i++) {
        connectEditorSignals (m_editors[i]);
    }

    connectEditorSignals (m_fallback_editor);
}

/* destructor */
BopomofoEngine::~BopomofoEngine (void)
{
}

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
                        (CMSHM_FILTER (modifiers)) == 0) &&
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
    registerProperties (m_props.properties ());
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
BopomofoEngine::commitText (Text & text)
{
    Engine::commitText (text);
    if (m_input_mode != MODE_INIT)
        m_input_mode = MODE_INIT;
    if (text.text ())
        static_cast<FallbackEditor*> (m_fallback_editor.get ())->setPrevCommittedChar (*text.text ());
    else
        static_cast<FallbackEditor*> (m_fallback_editor.get ())->setPrevCommittedChar (0);
}

void
BopomofoEngine::connectEditorSignals (EditorPtr editor)
{
    editor->signalCommitText ().connect (
        bind (&BopomofoEngine::commitText, this, _1));

    editor->signalUpdatePreeditText ().connect (
        bind (&BopomofoEngine::updatePreeditText, this, _1, _2, _3));
    editor->signalShowPreeditText ().connect (
        bind (&BopomofoEngine::showPreeditText, this));
    editor->signalHidePreeditText ().connect (
        bind (&BopomofoEngine::hidePreeditText, this));

    editor->signalUpdateAuxiliaryText ().connect (
        bind (&BopomofoEngine::updateAuxiliaryText, this, _1, _2));
    editor->signalShowAuxiliaryText ().connect (
        bind (&BopomofoEngine::showAuxiliaryText, this));
    editor->signalHideAuxiliaryText ().connect (
        bind (&BopomofoEngine::hideAuxiliaryText, this));

    editor->signalUpdateLookupTable ().connect (
        bind (&BopomofoEngine::updateLookupTable, this, _1, _2));
    editor->signalUpdateLookupTableFast ().connect (
        bind (&BopomofoEngine::updateLookupTableFast, this, _1, _2));
    editor->signalShowLookupTable ().connect (
        bind (&BopomofoEngine::showLookupTable, this));
    editor->signalHideLookupTable ().connect (
        bind (&BopomofoEngine::hideLookupTable, this));
}

};

