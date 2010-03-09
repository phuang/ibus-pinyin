#include <stdio.h>
#include <glib.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

/* the Lua interpreter */
static lua_State * L = NULL;

static int lua_plugin_init(){
  /* initialize Lua */
  L = lua_open();
  
  /* enable libs in sandbox */
  luaopen_base(L);
  luaopen_io(L);
  luaopen_string(L);
  luaopen_math(L);
  luaopen_table(L);
  
  
}

static const luaL_Reg imelib[] = {
  {"get_last_commit", ime_get_last_commit},
  {"get_version", ime_get_version},
#if 0
  {"join_string"}, ime_join_string},
  {"parse_mapping", ime_parse_mapping},
  {"register_command", ime_register_command},
  /* Note: the register_trigger function is dropped for ibus-pinyin. */
  {"register_trigger", ime_register_trigger},
  {"split_string", ime_split_string},
  {"trim_string_left", ime_trim_string_left},
  {"trim_string_right", ime_trim_string_right},
  {"trim_string", ime_trim_string},
#endif
  {NULL, NULL}
};

static int ime_get_last_commit(lua_State* L){
  /*TODO: not implemented. */
  g_assert_not_reached();
  lua_pushstring(L, "");
  return 1;
}

static int ime_get_version(lua_State* L){
  /* TODO: replace this with C macros. */
  lua_pushstring(L, "ibus-pinyin 1.2.99");
  return 1;
}
