#include <string.h>
#include <stdlib.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#include "lua-plugin.h"

#define IBUS_ENGINE_PLUGIN_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), IBUS_TYPE_ENGINE_PLUGIN, IBusEnginePluginPrivate))

struct _IBusEnginePluginPrivate{
  lua_State * L;
  GArray * lua_commands; /* Array of lua_command_t. */
};

G_DEFINE_TYPE (IBusEnginePlugin, ibus_engine_plugin, G_TYPE_OBJECT);

static void lua_command_clone(lua_command_t * command, lua_command_t * new_command){
  new_command->command_name = g_strdup(command->command_name);
  new_command->lua_function_name = g_strdup(command->command_name);
  new_command->description = g_strdup(command->description);
  new_command->leading = g_strdup(command->leading);
  new_command->help = g_strdup(command->help);
}

static void lua_command_reclaim(lua_command_t * command){
  g_free((gpointer)command->command_name);
  g_free((gpointer)command->lua_function_name);
  g_free((gpointer)command->description);
  g_free((gpointer)command->leading);
  g_free((gpointer)command->help);
}

static int
lua_plugin_init(IBusEnginePluginPrivate * plugin){
  g_assert(NULL == plugin->L);
  /* initialize Lua */
  plugin->L = lua_open();

  /* enable libs in sandbox */
  lua_plugin_openlibs(plugin->L);

  g_assert ( NULL == plugin->lua_commands );
  plugin->lua_commands = g_array_new(TRUE, TRUE, sizeof(lua_command_t));
  return 0;
}

static int
lua_plugin_fini(IBusEnginePluginPrivate * plugin){
  size_t i;
  lua_command_t * command;

  if ( plugin->lua_commands ){
    for ( i = 0; i < plugin->lua_commands->len; ++i){
      command = &g_array_index(plugin->lua_commands, lua_command_t, i);
      lua_command_reclaim(command);
    }
    g_array_free(plugin->lua_commands, TRUE);
    plugin->lua_commands = NULL;
  }

  lua_close(plugin->L);
  plugin->L = NULL;
  return 0;
}

static void
ibus_engine_plugin_finalize (GObject *gobject)
{
  IBusEnginePlugin *self = IBUS_ENGINE_PLUGIN (gobject);

  /* do some cleaning here. */
  lua_plugin_fini(self->priv);

  /* Chain up to the parent class */
  G_OBJECT_CLASS (ibus_engine_plugin_parent_class)->dispose(gobject);
}

static void
ibus_engine_plugin_class_init (IBusEnginePluginClass *klass)
{
  GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

  gobject_class->finalize = ibus_engine_plugin_finalize;

  g_type_class_add_private (klass, sizeof (IBusEnginePluginPrivate));
}

static void
ibus_engine_plugin_init (IBusEnginePlugin *self)
{
  IBusEnginePluginPrivate *priv;

  self->priv = priv = IBUS_ENGINE_PLUGIN_GET_PRIVATE (self);

  memset(priv, 0, sizeof(IBusEnginePluginPrivate));

  lua_plugin_init(priv);

  lua_plugin_store_plugin(priv->L, self);
}

IBusEnginePlugin * ibus_engine_plugin_new(){
  IBusEnginePlugin * plugin;

  plugin = (IBusEnginePlugin *) g_object_new (IBUS_TYPE_ENGINE_PLUGIN,
                                              NULL);

  return plugin;
}

static gint compare_command(gconstpointer a, gconstpointer b){
  lua_command_t * ca = (lua_command_t *) a;
  lua_command_t * cb = (lua_command_t *) b;
  return strcmp(ca->command_name, cb->command_name);
}

gboolean ibus_engine_plugin_add_command(IBusEnginePlugin * plugin, lua_command_t * command){
  IBusEnginePluginPrivate * priv = IBUS_ENGINE_PLUGIN_GET_PRIVATE(plugin);
  GArray * lua_commands = priv->lua_commands;

  if ( ibus_engine_plugin_lookup_command( plugin, command->command_name) )
    return FALSE;

  lua_command_t new_command;
  lua_command_clone(command, &new_command);

  g_array_append_val(priv->lua_commands, new_command);
  g_array_sort(priv->lua_commands, compare_command);

  return TRUE;
}

lua_command_t * ibus_engine_plugin_lookup_command(IBusEnginePlugin * plugin, const char * command){
  IBusEnginePluginPrivate * priv = IBUS_ENGINE_PLUGIN_GET_PRIVATE(plugin);
  GArray * lua_commands = priv->lua_commands;
  lua_command_t lookup_command = {.command_name = command, };

  lua_command_t * result = bsearch(&lookup_command, lua_commands->data, lua_commands->len, sizeof(lua_command_t), compare_command);
  return result;
}

const GArray * ibus_engine_plugin_get_available_commands(IBusEnginePlugin * plugin){
  IBusEnginePluginPrivate * priv = IBUS_ENGINE_PLUGIN_GET_PRIVATE(plugin);
  return priv->lua_commands;
}


/* will drop this function soon. */
lua_State * ibus_engine_plugin_get_lua_State(IBusEnginePlugin * plugin){
  return plugin->priv->L;
}

