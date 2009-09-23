#ifndef __PY_CONFIG_H_
#define __PY_CONFIG_H_

#include <glib.h>
#include <glib-object.h>
#include <ibus.h>
#include "Pointer.h"

namespace PY {

class Config {
public:
    Config (Pointer<IBusBus> & bus) {
        m_config = ibus_bus_get_config (bus);
        readDefaultValues ();
        g_signal_connect ((IBusConfig *) m_config, "value-changed", G_CALLBACK (valueChangedCallback), this);
    }

    static guint option (void) { return m_option & m_option_mask; }
    static guint pageSize (void) { return m_page_size; }
    static gboolean minusEqualPage (void) { return m_minus_equal_page; }
    static gboolean commaPeriodPage (void) { return m_comma_period_page; }
    static gboolean doublePinyin (void) { return m_double_pinyin; }
    static gint doublePinyinSchema (void) { return m_double_pinyin_schema; }
    static gboolean initChinese (void) { return m_init_chinese; }
    static gboolean initFull (void) { return m_init_full; }
    static gboolean initFullPunct (void) { return m_init_full_punct; }

private:
    bool read (const gchar *section, const gchar *name, bool defval);
    int read (const gchar *section, const gchar *name, int defval);
    void readDefaultValues (void);
    static void valueChangedCallback (IBusConfig    *config,
                                      const gchar   *section,
                                      const gchar   *name,
                                      const GValue  *value,
                                      Config        *self);

private:
    Pointer<IBusConfig> m_config;

private:
    static guint m_option;
    static guint m_option_mask;
    static guint m_page_size;
    static gboolean m_minus_equal_page;
    static gboolean m_comma_period_page;
    static gboolean m_double_pinyin;
    static gint m_double_pinyin_schema;
    static gboolean m_init_chinese;
    static gboolean m_init_full;
    static gboolean m_init_full_punct;
};

};
#endif
