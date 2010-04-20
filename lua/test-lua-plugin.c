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

  ibus_engine_plugin_load_lua_script(plugin, "test.lua");
  
  g_object_unref(plugin);

  printf("done.\n");
  return 0;
}
