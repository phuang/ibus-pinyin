#include "Util.h"
#include "PinyinProperties.h"

namespace PY {

PinyinProperties::PinyinProperties (void)
    : m_mode_chinese (Config::initChinese ()),
      m_mode_full (Config::initFull ()),
      m_mode_full_punct (Config::initFullPunct ()),
      m_mode_simp (Config::initSimpChinese ())
{
    /* create properties */
    m_prop_chinese = ibus_property_new ("mode.chinese",
                                        PROP_TYPE_NORMAL,
                                        StaticText ("CN"),
                                        m_mode_chinese ?
                                            PKGDATADIR"/icons/chinese.svg" :
                                            PKGDATADIR"/icons/english.svg",
                                        StaticText (_("Chinese")),
                                        TRUE,
                                        TRUE,
                                        PROP_STATE_UNCHECKED,
                                        NULL);
    m_props.append (m_prop_chinese);

    m_prop_full = ibus_property_new ("mode.full",
                                     PROP_TYPE_NORMAL,
                                     StaticText (m_mode_full? "Ａａ" : "Aa"),
                                     m_mode_full ?
                                        PKGDATADIR"/icons/full.svg" :
                                        PKGDATADIR"/icons/half.svg",
                                     StaticText (_("Full/Half width")),
                                     TRUE,
                                     TRUE,
                                     PROP_STATE_UNCHECKED,
                                     NULL);
    m_props.append (m_prop_full);

    m_prop_full_punct = ibus_property_new ("mode.full_punct",
                                           PROP_TYPE_NORMAL,
                                           StaticText (m_mode_full_punct ? "，。" : ",."),
                                           m_mode_full_punct ?
                                                PKGDATADIR"/icons/full-punct.svg" :
                                                PKGDATADIR"/icons/half-punct.svg",
                                           StaticText (_("Full/Half width punctuation")),
                                           TRUE,
                                           TRUE,
                                           PROP_STATE_UNCHECKED,
                                           NULL);
    m_props.append (m_prop_full_punct);

    m_prop_simp = ibus_property_new ("mode.simp",
                                      PROP_TYPE_NORMAL,
                                      StaticText (m_mode_simp ? "简" : "繁"),
                                      m_mode_simp ?
                                        PKGDATADIR"/icons/simp-chinese.svg" :
                                        PKGDATADIR"/icons/trad-chinese.svg",
                                      StaticText (_("Simplfied/Traditional Chinese")),
                                      TRUE,
                                      TRUE,
                                      PROP_STATE_UNCHECKED,
                                      NULL);
    m_props.append (m_prop_simp);

    m_prop_setup = ibus_property_new ("setup",
                                      PROP_TYPE_NORMAL,
                                      StaticText (_("Pinyin preferences")),
                                      "ibus-setup",
                                      StaticText (_("Pinyin preferences")),
                                      TRUE,
                                      TRUE,
                                      PROP_STATE_UNCHECKED,
                                      NULL);
    m_props.append (m_prop_setup);

}

void
PinyinProperties::toggleModeChinese (void)
{
    m_mode_chinese = ! m_mode_chinese;
    m_prop_chinese.setLabel (m_mode_chinese ? "CN" : "EN");
    m_prop_chinese.setIcon (m_mode_chinese ?
                                PKGDATADIR"/icons/chinese.svg" :
                                PKGDATADIR"/icons/english.svg");
    updateProperty (m_prop_chinese);
    
    m_prop_full_punct.setSensitive (m_mode_chinese);
    updateProperty (m_prop_full_punct);
}

void
PinyinProperties::toggleModeFull (void)
{
    m_mode_full = !m_mode_full;
    m_prop_full.setLabel (m_mode_full ? "Ａａ" : "Aa");
    m_prop_full.setIcon (m_mode_full ?
                            PKGDATADIR"/icons/full.svg" :
                            PKGDATADIR"/icons/half.svg");
    updateProperty (m_prop_full);
}

void
PinyinProperties::toggleModeFullPunct (void)
{
    m_mode_full_punct = !m_mode_full_punct;
    m_prop_full_punct.setLabel (m_mode_full_punct ? "，。" : ",.");
    m_prop_full_punct.setIcon (m_mode_full_punct ?
                                PKGDATADIR"/icons/full-punct.svg" :
                                PKGDATADIR"/icons/half-punct.svg");
    updateProperty (m_prop_full_punct);
}

void
PinyinProperties::toggleModeSimp (void)
{
    m_mode_simp = ! m_mode_simp;
    m_prop_simp.setLabel (m_mode_simp ? "简" : "繁");
    m_prop_simp.setIcon (m_mode_simp ?
                            PKGDATADIR"/icons/simp-chinese.svg" :
                            PKGDATADIR"/icons/trad-chinese.svg");
    updateProperty (m_prop_simp);
}

gboolean
PinyinProperties::propertyActivate (const gchar *prop_name, guint prop_state) {
    const static StaticString mode_chinese ("mode.chinese");
    const static StaticString mode_full ("mode.full");
    const static StaticString mode_full_punct ("mode.full_punct");
    const static StaticString mode_simp ("mode.simp");

    if (mode_chinese == prop_name) {
        toggleModeChinese ();
        return TRUE;
    }
    else if (mode_full == prop_name) {
        toggleModeFull ();
        return TRUE;
    }
    else if (mode_full_punct == prop_name) {
        toggleModeFullPunct ();
        return TRUE;
    }
    else if (mode_simp == prop_name) {
        toggleModeSimp ();
        return TRUE;
    }
    return FALSE;
}


};
