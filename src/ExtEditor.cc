#include "ExtEditor.h"

namespace PY {

ExtEditor::ExtEditor (PinyinProperties & props)
    : Editor (props)
{
    m_lua_plugin = ibus_engine_plugin_new();

    loadLuaScript("./lua/base.lua");

    m_input = "";
    m_lookup_table.clear();
}

int
ExtEditor::loadLuaScript(std::string filename)
{
    return ibus_engine_plugin_load_lua_script(m_lua_plugin, filename.c_str());
}

void
ExtEditor::resetLuaState()
{
  g_object_unref(m_lua_plugin);
  m_lua_plugin = ibus_engine_plugin_new();
}


gboolean
ExtEditor::processKeyEvent (guint keyval, guint keycode, guint modifiers)
{
    /* Remember the input string. */
    /* Deal other staff with updateStateFromInput(). */
    return false;
}

void
ExtEditor::pageUp (void)
{
}

void
ExtEditor::pageDown (void)
{
}

void
ExtEditor::cursorUp (void)
{
}

void
ExtEditor::cursorDown (void)
{
}

void
ExtEditor::update (void)
{
}

void
ExtEditor::reset (void)
{
}

void
ExtEditor::candidateClicked (guint index, guint button, guint state)
{
}

bool
ExtEditor::updateStateFromInput()
{
    /* Do parse and candidates update here. */
    /* prefix i double check here. */
    /* Check m_input len, and update auxiliary string meanwhile.
     * 1. only "i", dispatch to fillCommandCandidates(void).
     * 2. "i" with one charactor,
     *      dispatch to fillCommandCandidates(std::string).
     * 3. "i" with two charactor or more,
     *      dispatch to fillCommand(std::string, const char * argument).
     */
    return true;
}

bool
ExtEditor::fillCommandCandidates()
{
    clearLookupTable();

    /* fill Candidates here. */
    const GArray * commands = ibus_engine_plugin_get_available_commands(m_lua_plugin);
    for ( int i = 0; i < commands->len; ++i){
        lua_command_t * command = &g_array_index(commands, lua_command_t, i);
        m_lookup_table.appendLabel(Text(command->command_name));
        m_lookup_table.appendCandidate(Text(command->description));
    }

    sendLookupTable();
    return true;
}

bool
ExtEditor::fillCommandCandidates(std::string prefix)
{
    return true;
}

void
ExtEditor::clearLookupTable()
{
    m_lookup_table.clear ();
    m_lookup_table.setPageSize (Config::pageSize ());
    m_lookup_table.setOrientation (Config::orientation ());
}

void
ExtEditor::sendLookupTable()
{
    if (m_lookup_table.size ()) {
        Editor::updateLookupTable (m_lookup_table, TRUE);
    }
    else {
        hideLookupTable ();
    }
}

};


