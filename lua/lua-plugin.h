#ifndef LUA_PLUGIN_H
#define LUA_PLUGIN_H

int lua_plugin_init(lua_State * L);
int lua_plugin_fini(lua_State * L);

#define LUA_IMELIBNAME   "ime"
LUALIB_API int (luaopen_ime) (lua_State *L);

#endif
