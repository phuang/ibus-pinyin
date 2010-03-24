#include <stdio.h>
#include <string.h>
#include <glib.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "lua-plugin.h"

static const luaL_Reg lualibs[] = {
  {"", luaopen_base},
  {LUA_TABLIBNAME, luaopen_table},
  {LUA_IOLIBNAME, luaopen_io},
  {LUA_OSLIBNAME, luaopen_os},
  {LUA_STRLIBNAME, luaopen_string},
  {LUA_MATHLIBNAME, luaopen_math},
  {LUA_IMELIBNAME, luaopen_ime},
  {NULL, NULL}
};


void lua_plugin_openlibs (lua_State *L) {
  const luaL_Reg *lib = lualibs;
  for (; lib->func; lib++) {
    lua_pushcfunction(L, lib->func);
    lua_pushstring(L, lib->name);
    lua_call(L, 1, 0);
  }
}


int lua_plugin_init(lua_State *L){
  /* enable libs in sandbox */
  lua_plugin_openlibs(L);

  return 0;
}

int lua_plugin_fini(lua_State *L){
  lua_close(L);
  
  return 0;
}

static int ime_get_last_commit(lua_State* L){
  /*TODO: not implemented. */
  g_assert_not_reached();
  lua_pushstring(L, "");
  return 1;
}

static int ime_get_version(lua_State* L){
  /* TODO: replace this with C macros. */
  lua_pushliteral(L, "ibus-pinyin 1.2.99");
  return 1;
}

static int ime_join_string(lua_State* L){
  luaL_Buffer buf;
  size_t arr_len; size_t i;
  const char * sep;
  const char * str;

  if ( !lua_istable(L, 1) )
    return 0;

  sep = lua_tolstring(L, 2, NULL); 

  luaL_buffinit(L, &buf);
  arr_len = lua_objlen(L, 1);
  for ( i = 1; i < arr_len; ++i){
    lua_pushinteger(L, i);
    lua_gettable(L, 1);
    str = lua_tolstring(L, 3, NULL);
    luaL_addstring(&buf, str);
    lua_pop(L, 1);
    luaL_addstring(&buf, sep);
  }

  /* add tail of string list */
  lua_pushinteger(L, i);
  lua_gettable(L, 1);
  str = lua_tolstring(L, 3, NULL);
  luaL_addstring(&buf, str);
  lua_pop(L, 1);
  luaL_pushresult(&buf);

  return 1;
}

static int ime_split_string(lua_State * L){
  
  return 1;
}

static gboolean ime_is_white_space(const char c){
  static const char * const white_space = " \t\n\r\v\f";
  int i;
  size_t len = strlen(white_space);
  
  for ( i = 0; i < len; ++i){
    if ( white_space[i] == c )
      return TRUE;
  }
  return FALSE;
}

#define IME_TRIM_PRECHECK                       \
  if (NULL == s || '\0' == s[0]){               \
  lua_pushliteral(L, "");                       \
  return 1;                                     \
  }


static int ime_push_string(lua_State* L, const char * s, 
                                int start, int end){
  if (start >= end ){
    lua_pushliteral(L, "");
    return 1;
  }
  lua_pushlstring(L, s + start, end -start);
  lua_remove(L, 1);
  return 1; 
}

static int ime_trim_string_left(lua_State* L){
  size_t l; int start, end;
  const char * s = lua_tolstring(L, 1, &l);

  IME_TRIM_PRECHECK;
  start = 0; end = l;
  while( ime_is_white_space(s[start])){
    start++;
  }

  return ime_push_string(L, s, start, end);
}

static int ime_trim_string_right(lua_State* L){
  size_t l; int start, end;
  const char * s = lua_tolstring(L, 1, &l);

  IME_TRIM_PRECHECK;
  start = 0; end = l;
  while( ime_is_white_space(s[end - 1]) && end > 0){
    end--;
  }

  return ime_push_string(L, s, start, end);
}

static int ime_trim_string(lua_State* L){
  size_t l; int start, end;
  const char * s = lua_tolstring(L, 1, &l);

  IME_TRIM_PRECHECK;
  start = 0; end = l;
  while( ime_is_white_space(s[start])){
    start++;
  }
  while( ime_is_white_space(s[end - 1]) && end > 0){
    end--;
  }

  return ime_push_string(L, s, start, end);
}


static const luaL_Reg imelib[] = {
  {"get_last_commit", ime_get_last_commit},
  {"get_version", ime_get_version},
  {"join_string", ime_join_string},
#if 0
  {"parse_mapping", ime_parse_mapping},
  {"register_command", ime_register_command},
  /* Note: the register_trigger function is dropped for ibus-pinyin. */
  {"register_trigger", ime_register_trigger},
#endif
  {"split_string", ime_split_string},
  {"trim_string_left", ime_trim_string_left},
  {"trim_string_right", ime_trim_string_right},
  {"trim_string", ime_trim_string},
  {NULL, NULL}
};

LUALIB_API int luaopen_ime (lua_State *L) {
  luaL_register(L, LUA_IMELIBNAME, imelib);
  return 1;
}

