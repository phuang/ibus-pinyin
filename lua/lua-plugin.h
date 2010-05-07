#ifndef LUA_PLUGIN_H
#define LUA_PLUGIN_H

#include <glib-object.h>

#define LUA_IMELIBNAME   "ime"
LUALIB_API int (luaopen_ime) (lua_State * L);
#define LUA_IMELIB_CONTEXT "__context"

typedef struct{
  const char * command_name;
  const char * lua_function_name;
  const char * description;
  const char * leading; /* optional, default "digit". */
  const char * help; /* optional. */
} lua_command_t;

typedef struct{
  const char * suggest;
  const char * help;
  const char * content;
} lua_command_candidate_t;

typedef struct{
  const char * lua_function_name;
  const char * description;
  /*< private, skip it, and register it into Special Table directly with * wildcard. >*/
  /*
   * list of input_trigger_strings;
   * list of candidate_trigger_strings;
   */
} lua_trigger_t;

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

void lua_plugin_openlibs (lua_State *L);
void lua_plugin_store_plugin(lua_State * L, IBusEnginePlugin * plugin);

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
 * create a new ibus engine plugin.
 */
IBusEnginePlugin * ibus_engine_plugin_new();

/**
 * load a new lua script for ibus engine plugin.
 */
int ibus_engine_plugin_load_lua_script(IBusEnginePlugin * plugin, const char * filename);

/**
 * add a lua_command_t to plugin.
 */
gboolean ibus_engine_plugin_add_command(IBusEnginePlugin * plugin, lua_command_t * command);

/**
 * retrieve all available lua plugin commands.
 * return array of command informations of type lua_command_t without copies.
 */
const GArray * ibus_engine_plugin_get_available_commands(IBusEnginePlugin * plugin);

/**
 * Lookup a special command in ime lua extension.
 * command must be an 2-char long string.
 * return the matched command.
 */
lua_command_t * ibus_engine_plugin_lookup_command(IBusEnginePlugin * plugin, const char * command_name);

/**
 * retval int: returns the number of results,
 *              only support string or string array.
 * the consequence call of ibus_engine_plugin_get_retval* must follow this call immediately.
 */
int ibus_engine_plugin_call(IBusEnginePlugin * plugin, const char * lua_function_name, const char * argument /*optional, maybe NULL.*/);

/**
 * retrieve the retval string value. (value has been copied.)
 */
const char * ibus_engine_plugin_get_retval(IBusEnginePlugin * plugin);

/**
 * retrieve the array of string values. (string values have been copied.)
 */
GArray * ibus_engine_plugin_get_retvals(IBusEnginePlugin * plugin);

#endif
