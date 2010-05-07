#include "ExtEditor.h"

namespace PY {

/* Write digit/alpha/none Label generator here.
 * foreach (results): 1, from get_retval; 2..n from get_retvals.
 */

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
    modifiers &= (IBUS_SHIFT_MASK |
                  IBUS_CONTROL_MASK |
                  IBUS_MOD1_MASK |
                  IBUS_SUPER_MASK |
                  IBUS_HYPER_MASK |
                  IBUS_META_MASK |
                  IBUS_LOCK_MASK);
    if ( modifiers )
        return FALSE;

    /* Remember the input string. */
    switch (keyval){
    case IBUS_a ... IBUS_z:
        break;
    case IBUS_0 ... IBUS_9:
    case IBUS_KP_0 ... IBUS_KP_9:
        break;
    }

    /* Deal other staff with updateStateFromInput(). */
    updateStateFromInput();
    return FALSE;
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

    /* try to replace this with fillCommandCandidates("") call. */
    clearLookupTable();

    /* fill candidates here. */
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
    clearLookupTable();

    /* fill candidates here. */
    int len = prefix.length();
    const char * prefix_str = prefix.c_str();
    const GArray * commands = ibus_engine_plugin_get_available_commands(m_lua_plugin);
    for ( int i = 0; i < commands->len; ++i){
        lua_command_t * command = &g_array_index(commands, lua_command_t, i);
        if ( strncmp(prefix_str, command->command_name, len) == 0){
            m_lookup_table.appendLabel(Text(command->command_name));
            m_lookup_table.appendCandidate(Text(command->description));
        }
    }

    sendLookupTable();
    return true;
}

bool
ExtEditor::fillCommand(std::string command_name, const char * argument){
    const lua_command_t * command = ibus_engine_plugin_lookup_command(m_lua_plugin, command_name.c_str());
    if ( NULL == command )
        return false;

    int result_num = ibus_engine_plugin_call(m_lua_plugin, command->lua_function_name, argument);


        

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


