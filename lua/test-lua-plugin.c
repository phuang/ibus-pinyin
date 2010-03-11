#include <stdio.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "lua-plugin.h"

static lua_State * L = NULL;

int main(int argc, char * argv[]){
  printf("starting test...\n");

  /* initialize Lua */
  L = lua_open();

  lua_plugin_init(L);
  luaL_dofile(L, "test.lua");
  lua_plugin_fini(L);
  return 0;
}
