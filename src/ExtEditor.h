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
#ifndef __PY_EXT_EDITOR_
#define __PY_EXT_EDITOR_

#include <glib.h>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include "lua-plugin.h"
}
#include <string>
#include "Editor.h"

namespace PY {

enum ExtEditorLabelMode{
    LABEL_NONE,
    LABEL_LIST_NUMBERS,
    LABEL_LIST_COMMANDS,
    LABEL_LIST_NONE,
    LABEL_LIST_DIGIT,
    LABEL_LIST_ALPHA,
    LABEL_LIST_SINGLE,
    LABEL_LAST,
};

class ExtEditor : public Editor {
public:
    ExtEditor (PinyinProperties & props, Config & config);

    virtual gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    virtual void pageUp (void);
    virtual void pageDown (void);
    virtual void cursorUp (void);
    virtual void cursorDown (void);
    virtual void update (void);
    virtual void reset (void);
    virtual void candidateClicked (guint index, guint button, guint state);

    int loadLuaScript(std::string filename);
    void resetLuaState();

private:
    bool updateStateFromInput();

    /* Fill lookup table, and update preedit string. */
    bool fillCommandCandidates();
    bool fillCommandCandidates(std::string prefix);
    bool fillCommand(std::string command_name, const char * argument);

    /* Auxiliary functions for lookup table */
    void clearLookupTable();
    void updateLookupTable();
    gboolean selectCandidateInPage (guint index);
    gboolean selectCandidate (guint index);

    void updatePreeditText();
    void updateAuxiliaryText();

    gboolean processEditKey(guint keyval);
    gboolean processPageKey(guint keyval);
    gboolean processLabelKey(guint keyval);

    gboolean processSpace(guint keyval);

    gboolean removeCharBefore();
    gboolean removeCharAfter();

    ExtEditorLabelMode m_mode;
    Pointer<IBusEnginePlugin> m_lua_plugin;

    std::string m_preedit_text;
    std::string m_auxiliary_text;

    LookupTable m_lookup_table;

    //saved lua extension call results.
    int m_result_num;
    const lua_command_candidate_t * m_candidate;
    GArray * m_candidates;
};

};
#endif
