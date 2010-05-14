/* vim:set et sts=4: */
#ifndef __PY_ENGINE_H__
#define __PY_ENGINE_H__

#include <ibus.h>

#include "Pointer.h"
#include "Database.h"
#include "LookupTable.h"
#include "Property.h"
#include "Config.h"
#include "Editor.h"
#include "FallbackEditor.h"
#include "PinyinProperties.h"

namespace PY {

#define IBUS_TYPE_PINYIN_ENGINE	\
	(PY::ibus_pinyin_engine_get_type ())

GType   ibus_pinyin_engine_get_type    (void);

class Engine {
public:
    Engine (IBusEngine *engine) : m_engine (engine) {
    }

    virtual ~Engine (void);

    virtual gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers) = 0;
    virtual void focusIn (void) = 0;
    virtual void focusOut (void) = 0;
    virtual void reset (void) = 0;

    virtual void enable (void) = 0;
    virtual void disable (void) = 0;
    virtual void pageUp (void) = 0;
    virtual void pageDown (void) = 0;
    virtual void cursorUp (void) = 0;
    virtual void cursorDown (void) = 0;

    virtual gboolean propertyActivate (const gchar *prop_name, guint prop_state) = 0;
    virtual void candidateClicked (guint index, guint button, guint state) = 0;

protected:
    void commitText (Text & text) {
        ibus_engine_commit_text (m_engine, text);
    }

    void updatePreeditText (Text & text, guint cursor, gboolean visible) {
        ibus_engine_update_preedit_text (m_engine, text, cursor, visible);
    }

    void showPreeditText (void) {
        ibus_engine_show_preedit_text (m_engine);
    }

    void hidePreeditText (void) {
        ibus_engine_hide_preedit_text (m_engine);
    }

    void updateAuxiliaryText (Text & text, gboolean visible) {
        ibus_engine_update_auxiliary_text (m_engine, text, visible);
    }

    void showAuxiliaryText (void) {
        ibus_engine_show_auxiliary_text (m_engine);
    }

    void hideAuxiliaryText (void) {
        ibus_engine_hide_auxiliary_text (m_engine);
    }

    void updateLookupTable (LookupTable &table, gboolean visible) {
        ibus_engine_update_lookup_table (m_engine, table, visible);
    }

    void updateLookupTableFast (LookupTable &table, gboolean visible) {
        ibus_engine_update_lookup_table_fast (m_engine, table, visible);
    }

    void showLookupTable (void) {
        ibus_engine_show_lookup_table (m_engine);
    }

    void hideLookupTable (void) {
        ibus_engine_hide_lookup_table (m_engine);
    }

    void registerProperties (PropList & props) {
        ibus_engine_register_properties (m_engine, props);
    }

    void updateProperty (Property & prop) {
        ibus_engine_update_property (m_engine, prop);
    }

protected:
    Pointer<IBusEngine>  m_engine;      // engine pointer
};

};
#endif
