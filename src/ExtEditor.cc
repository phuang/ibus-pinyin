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
ExtEditor::updateStateFromInput(){
  return true;
}

};


