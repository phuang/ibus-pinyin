/* vim:set et sts=4: */

#include <ibus.h>
#include <stdlib.h>
#include <locale.h>
#include "Engine.h"
#include "Pointer.h"
#include "Bus.h"
#include "Config.h"

using namespace PY;

#define N_(text) text

static Pointer<IBusFactory> factory;

/* options */
static gboolean ibus = FALSE;
static gboolean verbose = FALSE;

static const GOptionEntry entries[] =
{
    { "ibus", 'i', 0, G_OPTION_ARG_NONE, &ibus, "component is executed by ibus", NULL },
    { "verbose", 'v', 0, G_OPTION_ARG_NONE, &verbose, "verbose", NULL },
    { NULL },
};


static void
ibus_disconnected_cb (IBusBus  *bus,
                      gpointer  user_data)
{
    g_debug ("bus disconnected");
    ibus_quit ();
}


static void
start_component (void)
{
    Pointer<IBusComponent> component;

    ibus_init ();
    Bus bus;
    Config config (bus);

    g_signal_connect (bus, "disconnected", G_CALLBACK (ibus_disconnected_cb), NULL);

    component = ibus_component_new ("org.freedesktop.IBus.Pinyin",
                                    N_("Pinyin input method"),
                                    "0.1.0",
                                    "GPL",
                                    "Peng Huang <shawn.p.huang@gmail.com>",
                                    "http://code.google.com/p/ibus/",
                                    "",
                                    "ibus-pinyin");
    ibus_component_add_engine (component,
                               ibus_engine_desc_new ("pinyin",
                                                     N_("Pinyin input method"),
                                                     N_("Pinyin input method"),
                                                     "zh_CN",
                                                     "GPL",
                                                     "Peng Huang <shawn.p.huang@gmail.com>",
                                                     PKGDATADIR"/icons/ibus-pinyin.svg",
                                                     "us"));

    factory = ibus_factory_new (ibus_bus_get_connection (bus));

    ibus_factory_add_engine (factory, "pinyin", IBUS_TYPE_PINYIN_ENGINE);

    if (ibus) {
        ibus_bus_request_name (bus, "org.freedesktop.IBus.Pinyin", 0);
    }
    else {
        ibus_bus_register_component (bus, component);
    }

    ibus_main ();
}

int
main (gint argc, gchar **argv)
{
    GError *error = NULL;
    GOptionContext *context;

    setlocale (LC_ALL, "");

    context = g_option_context_new ("- ibus pinyin engine component");

    g_option_context_add_main_entries (context, entries, "ibus-pinyin");

    if (!g_option_context_parse (context, &argc, &argv, &error)) {
        g_print ("Option parsing failed: %s\n", error->message);
        exit (-1);
    }

    start_component ();
    return 0;
}
