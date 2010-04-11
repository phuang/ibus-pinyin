#ifndef LUA_PLUGIN_H
#define LUA_PLUGIN_H

#include <glib-object.h>

#define LUA_IMELIBNAME   "ime"
LUALIB_API int (luaopen_ime) (lua_State * L);

void lua_plugin_openlibs (lua_State *L);

typedef struct{
  const char * command_name;
  const char * lua_function_name;
  const char * description;
  const char * leading; /* optional, default "digit". */
  const char * help; /* optional. */
} lua_command_t;

/*
 * Type macros.
 */

#define IBUS_TYPE_ENGINE_PLUGIN                 (ibus_engine_plugin_get_type ())
#define IBUS_ENGINE_PLUGIN(obj)                 (G_TYPE_CHECK_INSTANCE_CAST ((obj), IBUS_TYPE_ENGINE_PLUGIN, IBusEnginePlugin))
#define IBUS_IS_ENGINE_PLUGIN(obj)              (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IBUS_TYPE_ENGINE_PLUGIN))
#define IBUS_ENGINE_PLUGIN_CLASS(klass)         (G_TYPE_CHECK_CLASS_CAST ((klass), IBUS_TYPE_ENGINE_PLUGIN, IBusEnginePluginClass))
#define IBUS_IS_ENGINE_PLUGIN_CLASS(klass)      (G_TYPE_CHECK_CLASS ((klass), IBUS_TYPE_ENGINE_PLUGIN))
#define IBUS_ENGINE_PLUGIN_GET_CLASS(obj)       (G_TYPE_INSTANCE_GET_CLASS ((obj), IBUS_TYPE_ENGINE_PLUGIN, IBusEnginePluginClass))

typedef struct _IBusEnginePlugin IBusEnginePlugin;
typedef struct _IBusEnginePluginClass IBusEnginePluginClass;
typedef struct _IBusEnginePluginPrivate IBusEnginePluginPrivate;

struct _IBusEnginePlugin
{
  GObject parent_instance;

  /*< private >*/
  IBusEnginePluginPrivate *priv;  
};

struct _IBusEnginePluginClass
{
  GObjectClass parent_class;
};

GType ibus_engine_plugin_get_type(void);

/**
 * retrieve all available lua plugin commands.
 * return array of command informations of type lua_command_t.
 */
GArray * lua_plugin_ime_get_available_commands(IBusEnginePlugin * plugin);

/**
 * retval int: only support string or string array.
 */
int lua_plugin_ime_call(IBusEnginePlugin * plugin, const lua_command_t * command, const char * argument /*optional, maybe NULL.*/);

/**
 * retrieve the retval string value. (value has been copied.)
 */
const char * lua_plugin_ime_get_retval(IBusEnginePlugin * plugin);
/**
 * retrieve the array of string values. (string values have been copied.)
 */
GArray * lua_plugin_ime_get_retvals(IBusEnginePlugin * plugin);

#endif
