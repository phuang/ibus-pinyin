#include "ExtEditor.h"

namespace PY {

/* Write digit/alpha/none Label generator here.
 * foreach (results): 1, from get_retval; 2..n from get_retvals.
 */

ExtEditor::ExtEditor (PinyinProperties & props)
    : Editor (props),
      m_mode(LABEL_NONE)
{
    m_lua_plugin = ibus_engine_plugin_new();

    loadLuaScript("../lua/base.lua");

    m_text = "";
    m_cursor = 0;
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

    m_cursor = std::min(m_cursor, (guint)m_text.length());

    /* Remember the input string. */
    switch(m_cursor){
    case 0: //Empty input string.
        {
            g_return_val_if_fail( 'i' == keyval, FALSE);
            if ( 'i' == keyval ) {
                m_text.insert(m_cursor, keyval);
                m_cursor++;
            }
        }
        break;
    case 1 ... 2: // Only contains 'i' in input string.
        {      
            g_return_val_if_fail( 'i' == m_text[0], FALSE);
            if ( isalnum(keyval) ) {
                m_text.insert(m_cursor, keyval);
                m_cursor++;
            }
        }
        break;
    default: //Here is the appended argment.
        {
            g_return_val_if_fail( 'i' == m_text[0], FALSE);
            if (isprint(keyval)){
                m_text.insert(m_cursor, keyval);
                m_cursor++;
            }
        }
        break;
    }
    /* Deal other staff with updateStateFromInput(). */
    updateStateFromInput();
    return TRUE;
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
    if ( !m_text.length() )
        return false;
    if ( ! 'i' == m_text[0] ){
        g_warning("i is expected in m_input string.\n");
        return false;
    }

    m_auxiliary_text = "i";

    m_mode = LABEL_LIST_COMMANDS;
    if ( 1 == m_text.length() ){
        fillCommandCandidates();
        updateAuxiliaryText();
        return true;
    }
    /* Check m_text len, and update auxiliary string meanwhile.
     * 1. only "i", dispatch to fillCommandCandidates(void).
     * 2. "i" with one charactor,
     *      dispatch to fillCommandCandidates(std::string).
     * 3. "i" with two charactor or more,
     *      dispatch to fillCommand(std::string, const char * argument).
     */

    if ( isalpha(m_text[1])){
        m_mode = LABEL_LIST_COMMANDS;
        if ( m_text.length() == 2){
            fillCommandCandidates(m_text.substr(1,1).c_str());

            m_auxiliary_text += " ";
            m_auxiliary_text += m_text.substr(1, 1);
            updateAuxiliaryText();
            return true;
        } else if ( m_text.length() >= 3) {
            std::string command_name = m_text.substr(1,2);

            m_auxiliary_text += " ";
            m_auxiliary_text += m_text.substr(1,2);

            const lua_command_t * command = ibus_engine_plugin_lookup_command(m_lua_plugin, command_name.c_str());
            if ( NULL == command) {
                m_mode = LABEL_NONE;
                clearLookupTable();
                m_lookup_table.clear();
                sendLookupTable();
                updateAuxiliaryText();
                return false;
            }

            std::string label = command->leading;

            if ( "digit" == label )
                m_mode = LABEL_LIST_DIGIT;
            else if ( "alpha" == label )
                m_mode = LABEL_LIST_ALPHA;
            else
                m_mode = LABEL_LIST_NONE;

            const char * argment = NULL;
            std::string arg = "";
            if (m_text.length() > 3) {
                arg = m_text.substr(3);
                argment = arg.c_str();
                m_auxiliary_text += "";
                m_auxiliary_text += argment;
            }

            fillCommand(command_name, argment);
            updateAuxiliaryText();
        }
    }
    else if ( isdigit(m_text[1]) ){
        m_mode = LABEL_LIST_NUMBERS;
        //Generate Chinese number.
        //fillChineseNumber(). (Label use digit.)
    }

    return true;
}

bool
ExtEditor::fillCommandCandidates()
{
    return fillCommandCandidates("");
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

    if ( 1 == result_num )
        m_mode = LABEL_LIST_SINGLE;

    clearLookupTable();

    //Generate labels according to m_mode
    if ( LABEL_LIST_DIGIT == m_mode ) {
        //skip codes, as this is the default behavior of lookup table.
    }

    if ( LABEL_LIST_ALPHA == m_mode) {
        for ( int i = 1; i <= 10; ++i )
            m_lookup_table.appendLabel( Text(i - 1 + 'a') );
    }

    if ( LABEL_LIST_NONE == m_mode || LABEL_LIST_SINGLE == m_mode) {
        for ( int i = 1; i <= 10; ++i)
            m_lookup_table.appendLabel(Text(""));
    }

    //Generate candidates
    const lua_command_candidate_t * candidate = NULL;
    std::string result;
    if ( 1 == result_num ){
        candidate = ibus_engine_plugin_get_retval(m_lua_plugin);
        result = "";
        if ( candidate->content ){
            result = candidate->content;
        }
        if ( candidate->suggest && candidate-> help ){
            result += candidate->suggest;
            result += " ";
            result += "[";
            result += candidate->help;
            result += "]";
        }

        ibus_engine_plugin_free((lua_command_candidate_t *)candidate);
        m_lookup_table.appendCandidate(Text(result));
    }else if (result_num > 1){
        GArray * candidates = ibus_engine_plugin_get_retvals(m_lua_plugin);
        for ( int i = 0; i < result_num; ++i){
            candidate = g_array_index(candidates, lua_command_candidate_t *, i);
            result = "";
            if ( candidate->content ){
                result = candidate->content;
            }
            if ( candidate->suggest && candidate-> help ){
                result += candidate->suggest;
                result += " ";
                result += "[";
                result += candidate->help;
                result += "]";
            }
            ibus_engine_plugin_free((lua_command_candidate_t *)candidate);
            m_lookup_table.appendCandidate(Text(result));
        }
        g_array_free(candidates, TRUE);
    }

    sendLookupTable();
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

void
ExtEditor::updatePreeditText(){
    if( G_UNLIKELY(m_preedit_text.empty()) ){
        hidePreeditText ();
        return;
    }

    StaticText preedit_text(m_preedit_text);
    Editor::updatePreeditText(preedit_text, m_cursor, TRUE);
}

void
ExtEditor::updateAuxiliaryText(){
    if( G_UNLIKELY(m_auxiliary_text.empty()) ){
        hideAuxiliaryText ();
        return;
    }

    StaticText aux_text (m_auxiliary_text);
    Editor::updateAuxiliaryText (aux_text, TRUE);
}


};


