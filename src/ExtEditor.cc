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
#include "ExtEditor.h"

#define _(text) (dgettext (GETTEXT_PACKAGE, text))

namespace PY {

/* Write digit/alpha/none Label generator here.
 * foreach (results): 1, from get_retval; 2..n from get_retvals.
 */

ExtEditor::ExtEditor (PinyinProperties & props, Config & config)
    : Editor (props),
      m_mode(LABEL_NONE),
      m_result_num(0),
      m_candidate(NULL),
      m_candidates(NULL)
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
    //IBUS_SHIFT_MASK is removed.
    modifiers &= (IBUS_CONTROL_MASK |
                  IBUS_MOD1_MASK |
                  IBUS_SUPER_MASK |
                  IBUS_HYPER_MASK |
                  IBUS_META_MASK |
                  IBUS_LOCK_MASK);
    if ( modifiers )
        return FALSE;

    //handle backspace/delete here.
    if (processEditKey(keyval))
        return TRUE;

    //handle page/cursor up/down here.
    if (processPageKey(keyval))
        return TRUE;

    //handle label key select here.
    if (processLabelKey(keyval))
        return TRUE;

    if (processSpace(keyval))
        return TRUE;

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
    update();
    return TRUE;
}

gboolean
ExtEditor::processEditKey(guint keyval){
    switch (keyval){
    case IBUS_Delete:
    case IBUS_KP_Delete:
        removeCharAfter();
        updateStateFromInput();
        update();
        return TRUE;
    case IBUS_BackSpace:
        removeCharBefore();
        updateStateFromInput();
        update();
        return TRUE;
    }
    return FALSE;
}

gboolean
ExtEditor::processPageKey(guint keyval){
    switch (keyval) {
    //For 2000-10-10 16:30 input.
    case IBUS_comma:
        if (Config::commaPeriodPage ()) {
            pageUp ();
            return TRUE;
        }
        break;
#if 0
    case IBUS_minus:
        if (Config::minusEqualPage ()) {
            pageUp ();
            return TRUE;
        }
        break;
#endif
    case IBUS_period:
        if (Config::commaPeriodPage ()) {
            pageDown ();
            return TRUE;
        }
        break;
    case IBUS_equal:
        if (Config::minusEqualPage ()) {
            pageDown ();
            return TRUE;
        }
        break;
    case IBUS_Up:
    case IBUS_KP_Up:
        cursorUp ();
        return TRUE;

    case IBUS_Down:
    case IBUS_KP_Down:
        cursorDown ();
        return TRUE;

    case IBUS_Page_Up:
    case IBUS_KP_Page_Up:
        pageUp ();
        return TRUE;

    case IBUS_Page_Down:
    case IBUS_KP_Page_Down:
        pageDown ();
        return TRUE;

    case IBUS_Escape:
        reset ();
        return TRUE;
    }
    return FALSE;
}

gboolean
ExtEditor::processLabelKey(guint keyval){
    //According to enum ExtEditorLabelMode.

    switch(m_mode){
    case LABEL_LIST_DIGIT:
        switch(keyval){
        case 1 ... 9:
            selectCandidateInPage(keyval - '1');
            return TRUE;
            break;
        case 0:
            selectCandidateInPage(9);
            return TRUE;
            break;
        }
        break;
    case LABEL_LIST_ALPHA:
        switch(keyval){
        case 'a' ... 'k':
            selectCandidateInPage(keyval - 'a');
            return TRUE;
            break;
        case 'A' ... 'K':
            selectCandidateInPage(keyval - 'A');
            return TRUE;
            break;
        }
        break;
    }
    return FALSE;
}

gboolean
ExtEditor::processSpace(guint keyval){
    if (!(keyval == IBUS_space || keyval == IBUS_KP_Space))
        return FALSE;

    guint cursor_pos = m_lookup_table.cursorPos();

    switch(m_mode){
    case LABEL_LIST_NUMBERS:
        //TODO: implement number mode.
        break;
    case LABEL_LIST_COMMANDS:
    case LABEL_LIST_DIGIT:
    case LABEL_LIST_ALPHA:
        selectCandidateInPage(cursor_pos);
        break;
    case LABEL_LIST_SINGLE:
        g_return_val_if_fail(cursor_pos == 0 , FALSE);
        selectCandidateInPage(cursor_pos);
        break;
    }
    return TRUE;
}

void
ExtEditor::pageUp (void)
{
    if (G_LIKELY(m_lookup_table.pageUp())) {
        update();
    }
}

void
ExtEditor::pageDown (void)
{
    if (G_LIKELY(m_lookup_table.pageDown())) {
        update();
    }
}

gboolean
ExtEditor::removeCharBefore()
{
    if (G_UNLIKELY( m_cursor <= 0 )) {
        m_cursor = 0;
        return FALSE;
    }

    if (G_UNLIKELY( m_cursor > m_text.length() )) {
        m_cursor = m_text.length();
        return FALSE;
    }

    m_text.erase(m_cursor - 1, 1);
    m_cursor = std::max(0, (int)(m_cursor - 1));
}

gboolean
ExtEditor::removeCharAfter()
{
    if (G_UNLIKELY( m_cursor < 0 )) {
        m_cursor = 0;
        return FALSE;
    }

    if (G_UNLIKELY( m_cursor >= m_text.length() )) {
        m_cursor = m_text.length();
        return FALSE;
    }
    m_text.erase(m_cursor, 1);
    m_cursor = std::min(m_cursor, (guint)m_text.length());
}

void
ExtEditor::cursorUp (void)
{
    if (G_LIKELY (m_lookup_table.cursorUp ())) {
        update();
    }
}

void
ExtEditor::cursorDown (void)
{
    if (G_LIKELY (m_lookup_table.cursorDown ())) {
        update();
    }
}

void
ExtEditor::update (void)
{
    updateLookupTable();
    updatePreeditText();
    updateAuxiliaryText();
}

void
ExtEditor::reset (void)
{
    m_text = "";
    updateStateFromInput();
    update();
}

void
ExtEditor::candidateClicked (guint index, guint button, guint state)
{
    selectCandidateInPage (index);
}

gboolean
ExtEditor::selectCandidateInPage (guint index)
{
    guint page_size = m_lookup_table.pageSize();
    guint cursor_pos = m_lookup_table.cursorPos();

    if (G_UNLIKELY(index >= page_size))
        return FALSE;
    index += (cursor_pos / page_size) * page_size;

    return selectCandidate (index);
}

gboolean
ExtEditor::selectCandidate (guint index)
{
    switch(m_mode){
    case LABEL_LIST_NUMBERS:
        //TODO: implement pinyin extension i number mode.
        break;
    case LABEL_LIST_COMMANDS:
        {
            std::string prefix = m_text.substr(1, 2);
            int len = prefix.length();
            const char * prefix_str = prefix.c_str();
            const GArray * commands = ibus_engine_plugin_get_available_commands(m_lua_plugin);
            int match_count = -1;
            for (int i = 0; i < commands->len; ++i) {
                lua_command_t * command = &g_array_index(commands, lua_command_t, i);
                if ( strncmp(prefix_str, command->command_name, len) == 0 ){
                    match_count++;
                }
                if ( match_count == index ) {
                    m_text.clear();
                    m_text = "i";
                    m_text += command->command_name;
                    break;
                }
            }
            updateStateFromInput();
            update();
        }
        return TRUE;
        break;
    case LABEL_LIST_DIGIT:
    case LABEL_LIST_ALPHA:
        {
            g_return_val_if_fail(m_result_num > 1, FALSE);
            g_return_val_if_fail(index < m_result_num, FALSE);

            const lua_command_candidate_t * candidate = g_array_index(m_candidates, lua_command_candidate_t *, index);
            if ( candidate->content ){
                StaticText text(candidate->content);
                commitText(text);
                m_text.clear();
            } else if (candidate->suggest){
                m_text += candidate->suggest;
            }

            updateStateFromInput();
            update();
            return TRUE;
        }
        break;
    case LABEL_LIST_SINGLE:
        {
            g_return_val_if_fail(m_result_num == 1, FALSE);
            g_return_val_if_fail(index == 0, FALSE);
            if ( m_candidate->content ){
                StaticText text(m_candidate->content);
                commitText(text);
                m_text.clear();
            } else if (m_candidate->suggest){
                m_text += m_candidate->suggest;
            }

            updateStateFromInput();
            update();
            return TRUE;
        }
        break;
    }
    return FALSE;
}

bool
ExtEditor::updateStateFromInput()
{
    /* Do parse and candidates update here. */
    /* prefix i double check here. */
    if ( !m_text.length() ) {
        m_preedit_text = "";
        m_auxiliary_text = "";
        clearLookupTable();
        return false;
    }
    if ( ! 'i' == m_text[0] ){
        g_warning("i is expected in m_input string.\n");
        return false;
    }

    m_auxiliary_text = "i";

    m_mode = LABEL_LIST_COMMANDS;
    if ( 1 == m_text.length() ){
        fillCommandCandidates();
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
                m_auxiliary_text += " ";
                m_auxiliary_text += argment;
            }

            fillCommand(command_name, argment);
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
            std::string candidate = command->command_name;
            candidate += ".";
            candidate += command->description;
            m_lookup_table.appendLabel(Text(""));
            m_lookup_table.appendCandidate(Text(candidate));
        }
    }

    return true;
}

bool
ExtEditor::fillCommand(std::string command_name, const char * argument){
    const lua_command_t * command = ibus_engine_plugin_lookup_command(m_lua_plugin, command_name.c_str());
    if ( NULL == command )
        return false;

    if ( m_result_num != 0) {
        if ( m_result_num == 1) {
            ibus_engine_plugin_free_candidate((lua_command_candidate_t *)m_candidate);
            m_candidate = NULL;
        }else{
            for ( int i = 0; i < m_result_num; ++i){
                const lua_command_candidate_t * candidate = g_array_index(m_candidates, lua_command_candidate_t *, i);
                ibus_engine_plugin_free_candidate((lua_command_candidate_t *)candidate);
            }

            g_array_free(m_candidates, TRUE);
            m_candidates = NULL;
        }
        m_result_num = 0;
        g_assert(m_candidates == NULL && m_candidate == NULL);
    }

    m_result_num = ibus_engine_plugin_call(m_lua_plugin, command->lua_function_name, argument);

    if ( 1 == m_result_num )
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
    std::string result;
    if ( 1 == m_result_num ){
        m_candidate = ibus_engine_plugin_get_retval(m_lua_plugin);
        result = "";
        if ( m_candidate->content ){
            result = m_candidate->content;
            if (strstr(result.c_str(), "\n"))
                result = _("(Character Chart)");
        }
        if ( m_candidate->suggest && m_candidate-> help ){
            result += m_candidate->suggest;
            result += " ";
            result += "[";
            result += m_candidate->help;
            result += "]";
        }

        m_lookup_table.appendCandidate(Text(result));
    }else if (m_result_num > 1){
        m_candidates = ibus_engine_plugin_get_retvals(m_lua_plugin);
        for ( int i = 0; i < m_result_num; ++i){
            const lua_command_candidate_t * candidate = g_array_index(m_candidates, lua_command_candidate_t *, i);
            result = "";
            if ( candidate->content ){
                result = candidate->content;
                if (strstr(result.c_str(), "\n"))
                    result = _("(Character Chart)");
            }
            if ( candidate->suggest && candidate-> help ){
                result += candidate->suggest;
                result += " ";
                result += "[";
                result += candidate->help;
                result += "]";
            }

            m_lookup_table.appendCandidate(Text(result));
        }
    }

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
ExtEditor::updateLookupTable()
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


