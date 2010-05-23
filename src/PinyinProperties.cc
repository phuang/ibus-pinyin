/* vim:set et ts=4 sts=4:
 *
 * ibus-pinyin - The Chinese PinYin engine for IBus
 *
 * Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#include <string>
#include "PinyinProperties.h"

namespace PY {

#define _(text) (dgettext (GETTEXT_PACKAGE, text))

PinyinProperties::PinyinProperties (Config & config)
    : m_config (config),
      m_mode_chinese (m_config.initChinese ()),
      m_mode_full (m_config.initFull ()),
      m_mode_full_punct (m_config.initFullPunct ()),
      m_mode_simp (m_config.initSimpChinese ()),
      m_prop_chinese ("mode.chinese",
                PROP_TYPE_NORMAL,
                StaticText ("CN"),
                m_mode_chinese ?
                    PKGDATADIR"/icons/chinese.svg" :
                    PKGDATADIR"/icons/english.svg",
                StaticText (_("Chinese"))),
      m_prop_full ("mode.full",
                PROP_TYPE_NORMAL,
                StaticText (m_mode_full ? "Ａａ" : "Aa"),
                m_mode_full ?
                    PKGDATADIR"/icons/full.svg" :
                    PKGDATADIR"/icons/half.svg",
                StaticText (_("Full/Half width"))),
      m_prop_full_punct ("mode.full_punct",
                PROP_TYPE_NORMAL,
                StaticText (m_mode_full_punct ? "，。" : ",."),
                m_mode_full_punct ?
                    PKGDATADIR"/icons/full-punct.svg" :
                    PKGDATADIR"/icons/half-punct.svg",
                StaticText (_("Full/Half width punctuation"))),
      m_prop_simp ( "mode.simp",
                PROP_TYPE_NORMAL,
                StaticText (m_mode_simp ? "简" : "繁"),
                m_mode_simp ?
                    PKGDATADIR"/icons/simp-chinese.svg" :
                    PKGDATADIR"/icons/trad-chinese.svg",
                StaticText (_("Simplfied/Traditional Chinese"))),
      m_prop_setup ("setup",
                PROP_TYPE_NORMAL,
                StaticText (_("Pinyin preferences")),
                "ibus-setup",
                StaticText (_("Pinyin preferences")))
{
    m_props.append (m_prop_chinese);
    m_props.append (m_prop_full);
    m_props.append (m_prop_full_punct);
    m_props.append (m_prop_simp);
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
    const static std::string mode_chinese ("mode.chinese");
    const static std::string mode_full ("mode.full");
    const static std::string mode_full_punct ("mode.full_punct");
    const static std::string mode_simp ("mode.simp");

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
