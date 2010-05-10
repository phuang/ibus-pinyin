/* vim:set et sts=4: */
#ifndef __PY_EXT_EDITOR__
#define __PY_EXT_EDITOR__

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
    LABEL_LAST,
};

class ExtEditor : public Editor {
public:
    ExtEditor (PinyinProperties &props);

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
    void sendLookupTable();

    void updatePreeditText();
    void updateAuxiliaryText();

    ExtEditorLabelMode m_mode;
    Pointer<IBusEnginePlugin> m_lua_plugin;

    std::string m_input;
    std::string m_preedit_text;
    std::string m_auxiliary_text;

    LookupTable m_lookup_table;
};

};
#endif
