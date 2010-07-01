/* vim:set et ts=4 sts=4:
 *
 * ibus-pinyin - The Chinese PinYin engine for IBus
 *
 * Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
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
#include "PinyinEngine.h"
#include <string>
#include "Config.h"
#include "PunctEditor.h"
#include "RawEditor.h"
#ifdef IBUS_BUILD_LUA_EXTENSION
#include "ExtEditor.h"
#endif
#include "FullPinyinEditor.h"
#include "DoublePinyinEditor.h"
#include "FallbackEditor.h"

namespace PY {

/* constructor */
PinyinEngine::PinyinEngine (IBusEngine *engine)
    : Engine (engine),
      m_props (PinyinConfig::instance ()),
      m_prev_pressed_key (IBUS_VoidSymbol),
      m_input_mode (MODE_INIT),
      m_fallback_editor (new FallbackEditor (m_props, PinyinConfig::instance ()))
{
    gint i;

    if (PinyinConfig::instance ().doublePinyin ())
        m_editors[MODE_INIT].reset (new DoublePinyinEditor (m_props, PinyinConfig::instance ()));
    else
        m_editors[MODE_INIT].reset (new FullPinyinEditor (m_props, PinyinConfig::instance ()));

    m_editors[MODE_PUNCT].reset (new PunctEditor (m_props, PinyinConfig::instance ()));
    m_editors[MODE_RAW].reset (new RawEditor (m_props, PinyinConfig::instance ()));
#ifdef IBUS_BUILD_LUA_EXTENSION
    m_editors[MODE_EXTENSION].reset (new ExtEditor (m_props, PinyinConfig::instance ()));
#else
    m_editors[MODE_EXTENSION].reset (new Editor (m_props, PinyinConfig::instance ()));
#endif

    m_props.signalUpdateProperty ().connect (bind (&PinyinEngine::updateProperty, this, _1));

    for (i = MODE_INIT; i < MODE_LAST; i++) {
        connectEditorSignals (m_editors[i]);
    }

    connectEditorSignals (m_fallback_editor);
}

/* destructor */
PinyinEngine::~PinyinEngine (void)
{
}

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

    /* Toggle simp/trad Chinese Mode when hotkey Ctrl + Shift + F pressed */
    if (keyval == IBUS_F && scmshm_test (modifiers, (IBUS_SHIFT_MASK | IBUS_CONTROL_MASK))) {
        m_props.toggleModeSimp();
        m_prev_pressed_key = IBUS_F;
        return TRUE;
    }

    if (m_props.modeChinese ()) {
        if (m_input_mode == MODE_INIT &&
            ((cmshm_filter (modifiers)) == 0)) {
            const String & text = m_editors[MODE_INIT]->text ();
            if (text.empty ()) {
                switch (keyval) {
                case IBUS_grave:
                    m_input_mode = MODE_PUNCT;
                    break;
#ifdef IBUS_BUILD_LUA_EXTENSION
                case IBUS_i:
                    m_input_mode = MODE_EXTENSION;
                    break;
#endif
                }
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
    if (PinyinConfig::instance ().doublePinyin ()) {
        if (dynamic_cast <DoublePinyinEditor *> (m_editors[MODE_INIT].get ()) == NULL) {
            m_editors[MODE_INIT].reset (new DoublePinyinEditor (m_props, PinyinConfig::instance ()));
            connectEditorSignals (m_editors[MODE_INIT]);
        }
    }
    else {
        if (dynamic_cast <FullPinyinEditor *> (m_editors[MODE_INIT].get ()) == NULL) {
            m_editors[MODE_INIT].reset (new FullPinyinEditor (m_props, PinyinConfig::instance ()));
            connectEditorSignals (m_editors[MODE_INIT]);
        }
    }
    registerProperties (m_props.properties ());
}


void
PinyinEngine::focusOut (void)
{
    reset ();
}

void
PinyinEngine::reset (void)
{
    m_prev_pressed_key = IBUS_VoidSymbol;
    m_input_mode = MODE_INIT;
    for (gint i = 0; i < MODE_LAST; i++) {
        m_editors[i]->reset ();
    }
    m_fallback_editor->reset ();
}

void
PinyinEngine::enable (void)
{
    m_props.reset ();
}

void
PinyinEngine::disable (void)
{
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
    g_spawn_command_line_async (LIBEXECDIR"/ibus-setup-pinyin pinyin", NULL);
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
PinyinEngine::commitText (Text & text)
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
PinyinEngine::connectEditorSignals (EditorPtr editor)
{
    editor->signalCommitText ().connect (
        bind (&PinyinEngine::commitText, this, _1));

    editor->signalUpdatePreeditText ().connect (
        bind (&PinyinEngine::updatePreeditText, this, _1, _2, _3));
    editor->signalShowPreeditText ().connect (
        bind (&PinyinEngine::showPreeditText, this));
    editor->signalHidePreeditText ().connect (
        bind (&PinyinEngine::hidePreeditText, this));

    editor->signalUpdateAuxiliaryText ().connect (
        bind (&PinyinEngine::updateAuxiliaryText, this, _1, _2));
    editor->signalShowAuxiliaryText ().connect (
        bind (&PinyinEngine::showAuxiliaryText, this));
    editor->signalHideAuxiliaryText ().connect (
        bind (&PinyinEngine::hideAuxiliaryText, this));

    editor->signalUpdateLookupTable ().connect (
        bind (&PinyinEngine::updateLookupTable, this, _1, _2));
    editor->signalUpdateLookupTableFast ().connect (
        bind (&PinyinEngine::updateLookupTableFast, this, _1, _2));
    editor->signalShowLookupTable ().connect (
        bind (&PinyinEngine::showLookupTable, this));
    editor->signalHideLookupTable ().connect (
        bind (&PinyinEngine::hideLookupTable, this));
}

};

