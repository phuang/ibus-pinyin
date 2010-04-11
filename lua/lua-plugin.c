#include <lua.h>

#include "lua-plugin.h"

#define IBUS_ENGINE_PLUGIN_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), IBUS_TYPE_ENGINE_PLUGIN, IBusEnginePluginPrivate))

G_DEFINE_TYPE (IBusEnginePlugin, ibus_engine_plugin, G_TYPE_OBJECT);

static void
ibus_engine_plugin_dispose (GObject *gobject)
{
  IBusEnginePlugin *self = IBUS_ENGINE_PLUGIN (gobject);
  
  /* do some cleaning here. */

  /* Chain up to the parent class */
  G_OBJECT_CLASS (ibus_engine_plugin_parent_class)->dispose(gobject);
}

static void
ibus_engine_plugin_finalize (GObject *gobject)
{
  IBusEnginePlugin *self = IBUS_ENGINE_PLUGIN (gobject);

  /* Chain up to the parent class */
  G_OBJECT_CLASS (ibus_engine_plugin_parent_class)->dispose(gobject);
}

static void
ibus_engine_plugin_class_init (IBusEnginePluginClass *klass)
{
  GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

  gobject_class->dispose = ibus_engine_plugin_dispose;
  gobject_class->finalize = ibus_engine_plugin_finalize;

  g_type_class_add_private (klass, sizeof (IBusEnginePluginPrivate));
}

static void
ibus_engine_plugin_init (IBusEnginePlugin *self)
{
  IBusEnginePluginPrivate *priv;

  self->priv = priv = IBUS_ENGINE_PLUGIN_GET_PRIVATE (self);

  priv->L = NULL;
  priv->lua_commands = NULL;
}

