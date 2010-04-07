#ifndef LUA_PLUGIN_H
#define LUA_PLUGIN_H

int lua_plugin_init(lua_State * L);
int lua_plugin_fini(lua_State * L);

#define LUA_IMELIBNAME   "ime"
LUALIB_API int (luaopen_ime) (lua_State * L);

typedef struct{
  const char * command_name;
  const char * lua_function_name;
  const char * description;
  const char * leading; /* optional, default "digit". */
  const char * help; /* optional. */
} lua_command_t;

typedef struct{
  lua_State * L;
  GArray * lua_commands; /* Array of lua_command_t. */
} lua_plugin_context_t;

/**
 * retrieve all available lua plugin commands.
 * return array of command informations of type lua_command_t.
 */
GArray * lua_plugin_ime_get_available_commands(lua_State * L);

/**
 * retval int: only support string or string array.
 */
int lua_plugin_ime_call(lua_State * L, const lua_command_t * command, const char * argument /*optional, maybe NULL.*/);

/**
 * retrieve the retval string value. (value has been copied.)
 */
const char * lua_plugin_ime_get_retval(lua_State * L);
/**
 * retrieve the array of string values. (string values have been copied.)
 */
GArray * lua_plugin_ime_get_retvals(lua_State * L);

#endif
