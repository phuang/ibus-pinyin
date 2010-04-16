#include <stdio.h>
#include <glib.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "lua-plugin.h"

int main(int argc, char * argv[]){
  printf("starting test...\n");

  g_type_init();
  
  IBusEnginePlugin * plugin;
  plugin = ibus_engine_plugin_new();

  lua_State * L = ibus_engine_plugin_get_lua_State(plugin);
  ibus_engine_plugin_load_lua_script(plugin, "test.lua");
  
  g_assert(lua_plugin_retrieve_plugin(L) == plugin);
  g_object_unref(plugin);

  printf("done.\n");
  return 0;
}
