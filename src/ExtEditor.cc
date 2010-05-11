#include "ExtEditor.h"

namespace PY {

/* Write digit/alpha/none Label generator here.
 * foreach (results): 1, from get_retval; 2..n from get_retvals.
 */

ExtEditor::ExtEditor (PinyinProperties & props)
    : Editor (props),
      m_mode(LABEL_NONE),
      m_cursor_pos(0)
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

    //handle backspace here.
    //handle page/cursor up/down here.
    //handle label key select here.

    m_cursor_pos = std::min(m_cursor_pos, m_input.length());

    /* Remember the input string. */
    switch(m_cursor_pos){
    case 0: //Empty input string.
        {
            g_return_val_if_fail( 'i' == keyval, FALSE);
            if ( 'i' == keyval ) {
                m_input.insert(m_cursor_pos, 1, keyval);
                m_cursor_pos++;
            }
        }
        break;
    case 1 ... 2: // Only contains 'i' in input string.
        {      
            g_return_val_if_fail( 'i' == m_input[0], FALSE);
            if ( isalnum(keyval) ) {
                m_input.insert(m_cursor_pos, 1, keyval);
                m_cursor_pos++;
            }
        }
        break;
    default: //Here is the appended argment.
        {
            g_return_val_if_fail( 'i' == m_input[0], FALSE);
            if (isprint(keyval)){
                m_input.insert(m_cursor_pos, 1, keyval);
                m_cursor_pos++;
            }
        }
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
    if ( !m_input.length() )
        return false;
    if ( ! 'i' == m_input[0] ){
        g_warning("i is expected in m_input string.\n");
        return false;
    }

    m_mode = LABEL_LIST_COMMANDS;
    if ( 1 == m_input.length() ){
        fillCommandCandidates();
        return true;
    }
    /* Check m_input len, and update auxiliary string meanwhile.
     * 1. only "i", dispatch to fillCommandCandidates(void).
     * 2. "i" with one charactor,
     *      dispatch to fillCommandCandidates(std::string).
     * 3. "i" with two charactor or more,
     *      dispatch to fillCommand(std::string, const char * argument).
     */

    if ( isalpha(m_input[1])){
        m_mode = LABEL_LIST_COMMANDS;
        if ( m_input.length() == 2){
            fillCommandCandidates(m_input.substr(1,1).c_str());
            return true;
        } else if ( m_input.length() == 3) {
            std::string command_name = m_input.substr(1,2);

            const lua_command_t * command = ibus_engine_plugin_lookup_command(m_lua_plugin, command_name.c_str());
            if ( NULL == command) {
                m_mode = LABEL_NONE;
                clearLookupTable();
                m_lookup_table.clear();
                sendLookupTable();
                return false;
            }

            std::string label = command->leading;

            if ( "digit" == label )
                m_mode = LABEL_LIST_DIGIT;
            else if ( "alpha" == label )
                m_mode = LABEL_LIST_ALPHA;
            else
                m_mode = LABEL_LIST_NONE;

            //fillCommandCandidates(...).(list or single value.)
        }
    }
    else if ( isdigit(m_input[1]) ){
        m_mode = LABEL_LIST_NUMBERS;
        //Generate Chinese number.
        //fillChineseNumber(). (Label use digit.)
    }

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


