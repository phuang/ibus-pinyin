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
  size_t vec_len; size_t i;
  const char * sep;
  const char * str;

  if ( !lua_istable(L, 1) )
    return 0;

  sep = luaL_checklstring(L, 2, NULL);
  vec_len = lua_objlen(L, 1);

  if ( 0 == vec_len ){
    lua_pop(L, 2);
    lua_pushnil(L);
    return 1;
  }

  luaL_buffinit(L, &buf);

  for ( i = 1; i < vec_len; ++i){
    lua_pushinteger(L, i);
    lua_gettable(L, 1);
    str = luaL_checklstring(L, 3, NULL);
    luaL_addstring(&buf, str);
    lua_pop(L, 1);
    luaL_addstring(&buf, sep);
  }

  /* add tail of string list */
  lua_pushinteger(L, i);
  lua_gettable(L, 1);
  str = luaL_checklstring(L, 3, NULL);
  luaL_addstring(&buf, str);
  lua_pop(L, 1);
  /* remove the args. */
  lua_pop(L, 2);
  luaL_pushresult(&buf);

  return 1;
}

static int ime_parse_mapping(lua_State * L){
  const char * src_string, * line_sep, * key_value_sep, * values_sep;
  int m, n;
  gchar** lines = NULL; size_t lines_no = 0; const char * line;
  gchar** key_value = NULL; const char * key = NULL;
  gchar** values = NULL; size_t values_no = 0; const char * value = NULL;

  src_string = luaL_checklstring(L, 1, NULL);
  line_sep = luaL_checklstring(L, 2, NULL);
  key_value_sep = luaL_checklstring(L, 3, NULL);
  values_sep = luaL_checklstring(L, 4, NULL);
  
  lines = g_strsplit(src_string, line_sep, 0);
  lines_no = g_strv_length(lines);
  lua_createtable(L, 0, lines_no);
  for( m = 0; m < lines_no; ++m){
    line = lines[m];
    if ( NULL == line || '\0' == line[0])
      continue;
    key_value = g_strsplit(line, key_value_sep, 2);
    key = key_value[0]; /* value = key_value[1]; */
    if ( NULL == key || '\0' == key[0])
      continue;
    {
      values = g_strsplit(key_value[1], values_sep, 0);
      values_no = g_strv_length(values);
      lua_createtable(L, values_no, 0);
      for ( n = 0; n < values_no; ++n){
        value = values[n];
        if ( NULL == value || '\0' == value[0] )
          continue;
        lua_pushinteger(L, n + 1);
        lua_pushstring(L, value);
        lua_settable(L, 6);
      }
      g_strfreev(values);
    }

    lua_pushstring(L, key);
    lua_insert(L, 6);
    lua_settable(L, 5);
    g_strfreev(key_value);
  }

  g_strfreev(lines);
  /*remove args */
  lua_remove(L, 4);
  lua_remove(L, 3);
  lua_remove(L, 2);
  lua_remove(L, 1);
  return 1;
}

static int ime_split_string(lua_State * L){
  gchar ** str_vec;
  guint str_vec_len = 0; int i;
  const char * sep;
  const char * str = luaL_checklstring(L, 1, NULL);

  sep = luaL_checklstring(L, 2, NULL);

  str_vec = g_strsplit(str, sep, 0);
  str_vec_len = g_strv_length(str_vec);

  lua_createtable(L, str_vec_len, 0);
  for ( i = 0; i < str_vec_len; ++i){
    lua_pushinteger(L, i + 1);
    lua_pushstring(L, str_vec[i]);
    lua_settable(L, 3);
  }

  g_strfreev(str_vec);
  lua_remove(L, 2); /* remove sep from stack */
  lua_remove(L, 1); /* remove str from stack */
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
  const char * s = luaL_checklstring(L, 1, &l);

  start = 0; end = l;
  while( ime_is_white_space(s[start])){
    start++;
  }

  return ime_push_string(L, s, start, end);
}

static int ime_trim_string_right(lua_State* L){
  size_t l; int start, end;
  const char * s = luaL_checklstring(L, 1, &l);

  start = 0; end = l;
  while( ime_is_white_space(s[end - 1]) && end > 0){
    end--;
  }

  return ime_push_string(L, s, start, end);
}

static int ime_trim_string(lua_State* L){
  size_t l; int start, end;
  const char * s = luaL_checklstring(L, 1, &l);

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
  {"parse_mapping", ime_parse_mapping},
#if 0
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

