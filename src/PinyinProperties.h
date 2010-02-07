#ifndef __PY_PINYIN_PROPERTIES_H_
#define __PY_PINYIN_PROPERTIES_H_

#include <ibus.h>
#include <sigc++/sigc++.h>
#include <libintl.h>
#include "Text.h"
#include "Property.h"
#include "Config.h"

#define _(text) (dgettext (GETTEXT_PACKAGE, text))

namespace PY {

class PinyinProperties {
public:
    PinyinProperties (void);
    
    void toggleModeChinese (void);
    void toggleModeFull (void);
    void toggleModeFullPunct (void);
    void toggleModeSimp (void);
    gboolean propertyActivate (const gchar *prop_name, guint prop_state);

    gboolean modeChinese (void) { return m_mode_chinese; }
    gboolean modeFull (void) { return m_mode_full; }
    gboolean modeFullPunct (void) { return m_mode_full_punct; }
    gboolean modeSimp (void) { return m_mode_simp; }
    PropList & properties (void) { return m_props; }

    sigc::signal<void, Property &> signalUpdateProperty  (void) {
        return m_signal_update_property;
    }

private:
    sigc::signal<void, Property &> m_signal_update_property;
    void updateProperty (Property & prop) {
        m_signal_update_property.emit (prop);
    }

private:
    gboolean    m_mode_chinese;
    gboolean    m_mode_full;
    gboolean    m_mode_full_punct;
    gboolean    m_mode_simp;
    
    /* properties */
    Property    m_prop_chinese;
    Property    m_prop_full;
    Property    m_prop_full_punct;
    Property    m_prop_simp;
    Property    m_prop_setup;
    PropList    m_props;
};

};

#endif
