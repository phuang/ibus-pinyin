#include <string.h>
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
      g_free((gpointer)command->command_name);
      g_free((gpointer)command->lua_function_name);
      g_free((gpointer)command->description);
      g_free((gpointer)command->leading);
      g_free((gpointer)command->help);
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
}

IBusEnginePlugin * ibus_engine_plugin_new(){
  IBusEnginePlugin * plugin;

  plugin = (IBusEnginePlugin *) g_object_new (IBUS_TYPE_ENGINE_PLUGIN,
                                              NULL);

  return plugin;
}

/* will drop this function soon. */
lua_State * ibus_engine_plugin_get_lua_State(IBusEnginePlugin * plugin){
  return plugin->priv->L;
}

