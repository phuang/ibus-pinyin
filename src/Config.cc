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
#include <boost/bind.hpp>
#include "Types.h"
#include "Config.h"
#include "Util.h"

namespace PY {

#define STRING_CORRECT_PINYIN               ("CorrectPinyin")
#define STRING_FUZZY_PINYIN                 ("FuzzyPinyin")
#define STRING_ORIENTATION                  ("LookupTableOrientation")
#define STRING_PAGE_SIZE                    ("LookupTablePageSize")
#define STRING_SHIFT_SELECT_CANDIDATE       ("ShiftSelectCandidate")
#define STRING_MINUS_EQUAL_PAGE             ("MinusEqualPage")
#define STRING_COMMA_PERIOD_PAGE            ("CommaPeriodPage")
#define STRING_AUTO_COMMIT                  ("AutoCommit")
#define STRING_DOUBLE_PINYIN                ("DoublePinyin")
#define STRING_DOUBLE_PINYIN_SCHEMA         ("DoublePinyinSchema")
#define STRING_DOUBLE_PINYIN_SHOW_RAW       ("DoublePinyinShowRaw")
#define STRING_INIT_CHINESE                 ("InitChinese")
#define STRING_INIT_FULL                    ("InitFull")
#define STRING_INIT_FULL_PUNCT              ("InitFullPunct")
#define STRING_INIT_SIMP_CHINESE            ("InitSimplifiedChinese")
#define STRING_SPECIAL_PHRASES              ("SpecialPhrases")
#define STRING_BOPOMOFO_KEYBOARD_MAPPING    ("BopomofoKeyboardMapping")

boost::scoped_ptr<PinyinConfig> PinyinConfig::m_instance;
boost::scoped_ptr<BopomofoConfig> BopomofoConfig::m_instance;

Config::Config (Bus & bus, const std::string & name)
    : Object (ibus_bus_get_config (bus)),
      m_section ("engine/" + name)
{
    m_option = PINYIN_INCOMPLETE_PINYIN | PINYIN_CORRECT_ALL;
    m_option_mask = PINYIN_INCOMPLETE_PINYIN | PINYIN_CORRECT_ALL;

    m_orientation = IBUS_ORIENTATION_HORIZONTAL;
    m_page_size = 5;
    m_shift_select_candidate = FALSE;
    m_minus_equal_page = TRUE;
    m_comma_period_page = TRUE;
    m_auto_commit = FALSE;

    m_double_pinyin = FALSE;
    m_double_pinyin_schema = 0;
    m_double_pinyin_show_raw = FALSE;

    m_init_chinese = TRUE;
    m_init_full = FALSE;
    m_init_full_punct = TRUE;
    m_init_simp_chinese = TRUE;
    m_special_phrases = TRUE;

    readDefaultValues ();
    g_signal_connect (get<IBusConfig> (),
                      "value-changed",
                      G_CALLBACK (valueChangedCallback),
                      this);
}

static const struct {
    const gchar *name;
    guint option;
    bool defval;
} options [] = {
    { "IncompletePinyin",       PINYIN_INCOMPLETE_PINYIN,   TRUE },
    /* correct */
    { "CorrectPinyin_GN_NG",    PINYIN_CORRECT_GN_TO_NG,    TRUE },
    { "CorrectPinyin_GN_NG",    PINYIN_CORRECT_GN_TO_NG,    TRUE },
    { "CorrectPinyin_MG_NG",    PINYIN_CORRECT_MG_TO_NG,    TRUE },
    { "CorrectPinyin_IOU_IU",   PINYIN_CORRECT_IOU_TO_IU,   TRUE },
    { "CorrectPinyin_UEI_UI",   PINYIN_CORRECT_UEI_TO_UI,   TRUE },
    { "CorrectPinyin_UEN_UN",   PINYIN_CORRECT_UEN_TO_UN,   TRUE },
    { "CorrectPinyin_UE_VE",    PINYIN_CORRECT_UE_TO_VE,    TRUE },
    { "CorrectPinyin_V_U",      PINYIN_CORRECT_V_TO_U,      TRUE },
    { "CorrectPinyin_VE_UE",    PINYIN_CORRECT_V_TO_U,      TRUE },
    /* fuzzy pinyin */
    { "FuzzyPinyin_C_CH",       PINYIN_FUZZY_C_CH,          FALSE },
    { "FuzzyPinyin_CH_C",       PINYIN_FUZZY_CH_C,          FALSE },
    { "FuzzyPinyin_Z_ZH",       PINYIN_FUZZY_Z_ZH,          FALSE },
    { "FuzzyPinyin_ZH_Z",       PINYIN_FUZZY_ZH_Z,          FALSE },
    { "FuzzyPinyin_S_SH",       PINYIN_FUZZY_S_SH,          FALSE },
    { "FuzzyPinyin_SH_S",       PINYIN_FUZZY_SH_S,          FALSE },
    { "FuzzyPinyin_L_N",        PINYIN_FUZZY_L_N,           FALSE },
    { "FuzzyPinyin_N_L",        PINYIN_FUZZY_N_L,           FALSE },
    { "FuzzyPinyin_F_H",        PINYIN_FUZZY_F_H,           FALSE },
    { "FuzzyPinyin_H_F",        PINYIN_FUZZY_H_F,           FALSE },
    { "FuzzyPinyin_L_R",        PINYIN_FUZZY_L_R,           FALSE },
    { "FuzzyPinyin_R_L",        PINYIN_FUZZY_R_L,           FALSE },
    { "FuzzyPinyin_K_G",        PINYIN_FUZZY_K_G,           FALSE },
    { "FuzzyPinyin_G_K",        PINYIN_FUZZY_G_K,           FALSE },
    { "FuzzyPinyin_AN_ANG",     PINYIN_FUZZY_AN_ANG,        FALSE },
    { "FuzzyPinyin_ANG_AN",     PINYIN_FUZZY_ANG_AN,        FALSE },
    { "FuzzyPinyin_EN_ENG",     PINYIN_FUZZY_EN_ENG,        FALSE },
    { "FuzzyPinyin_ENG_EN",     PINYIN_FUZZY_ENG_EN,        FALSE },
    { "FuzzyPinyin_IN_ING",     PINYIN_FUZZY_IN_ING,        FALSE },
    { "FuzzyPinyin_ING_IN",     PINYIN_FUZZY_ING_IN,        FALSE },
    { "FuzzyPinyin_IAN_IANG",   PINYIN_FUZZY_IAN_IANG,      FALSE },
    { "FuzzyPinyin_IANG_IAN",   PINYIN_FUZZY_IANG_IAN,      FALSE },
    { "FuzzyPinyin_UAN_UANG",   PINYIN_FUZZY_UAN_UANG,      FALSE },
    { "FuzzyPinyin_UANG_UAN",   PINYIN_FUZZY_UANG_UAN,      FALSE },
};

void
Config::readDefaultValues (void)
{
    /* double pinyin */
    m_double_pinyin = read (STRING_DOUBLE_PINYIN, false);
    m_double_pinyin_schema = read (STRING_DOUBLE_PINYIN_SCHEMA, 0);
    if (m_double_pinyin_schema >= 5) {
        m_double_pinyin_schema = 0;
        g_warn_if_reached ();
    }
    m_double_pinyin_show_raw = read (STRING_DOUBLE_PINYIN_SHOW_RAW, false);

    /* init states */
    m_init_chinese = read (STRING_INIT_CHINESE, true);
    m_init_full = read (STRING_INIT_FULL, false);
    m_init_full_punct = read (STRING_INIT_FULL_PUNCT, true);
    m_init_simp_chinese = read (STRING_INIT_SIMP_CHINESE, true);

    m_special_phrases = read (STRING_SPECIAL_PHRASES, true);

    /* others */
    m_orientation = read (STRING_ORIENTATION, 0);
    if (m_orientation != IBUS_ORIENTATION_VERTICAL &&
        m_orientation != IBUS_ORIENTATION_HORIZONTAL) {
        m_orientation = IBUS_ORIENTATION_HORIZONTAL;
        g_warn_if_reached ();
    }
    m_page_size = read (STRING_PAGE_SIZE, 5);
    if (m_page_size > 10) {
        m_page_size = 5;
        g_warn_if_reached ();
    }
    m_shift_select_candidate = read (STRING_SHIFT_SELECT_CANDIDATE, false);
    m_minus_equal_page = read (STRING_MINUS_EQUAL_PAGE, true);
    m_comma_period_page = read (STRING_COMMA_PERIOD_PAGE, true);
    m_auto_commit = read (STRING_AUTO_COMMIT, false);

    /* correct pinyin */
    if (read (STRING_CORRECT_PINYIN, true))
        m_option_mask |= PINYIN_CORRECT_ALL;
    else
        m_option_mask &= ~PINYIN_CORRECT_ALL;

    /* fuzzy pinyin */
    if (read (STRING_FUZZY_PINYIN, false))
        m_option_mask |= PINYIN_FUZZY_ALL;
    else
        m_option_mask &= ~PINYIN_FUZZY_ALL;

    /* read values */
    for (guint i = 0; i < G_N_ELEMENTS (options); i++) {
        if (read (options[i].name, options[i].defval))
            m_option |= options[i].option;
        else
            m_option &= ~options[i].option;
    }

    m_bopomofoKeyboardMapping = read (STRING_BOPOMOFO_KEYBOARD_MAPPING, 0);
}

inline bool
Config::read (const std::string & name,
              bool                defval)
{
    GValue value = {0};
    if (ibus_config_get_value (get<IBusConfig> (), m_section.c_str (), name.c_str (), &value)) {
        if (G_VALUE_TYPE (&value) == G_TYPE_BOOLEAN)
            return g_value_get_boolean (&value);
    }
    return defval;
}

inline gint
Config::read (const std::string & name,
              gint                defval)
{
    GValue value = {0};
    if (ibus_config_get_value (get<IBusConfig> (), m_section.c_str (), name.c_str (), &value)) {
        if (G_VALUE_TYPE (&value) == G_TYPE_INT)
            return g_value_get_int (&value);
    }
    return defval;
}

static inline bool
normalizeGValue (const GValue *value, bool defval)
{
    if (value == NULL || G_VALUE_TYPE (value) != G_TYPE_BOOLEAN)
        return defval;
    return g_value_get_boolean (value);
}

static inline gint
normalizeGValue (const GValue *value, gint defval)
{
    if (value == NULL || G_VALUE_TYPE (value) != G_TYPE_INT)
        return defval;
    return g_value_get_int (value);
}


void
Config::valueChanged (const std::string & section,
                      const std::string & name,
                      const GValue  *value)
{
    if (m_section != section)
        return;

    /* double pinyin */
    if (STRING_DOUBLE_PINYIN == name)
        m_double_pinyin = normalizeGValue (value, false);
    else if (STRING_DOUBLE_PINYIN_SCHEMA == name) {
        m_double_pinyin_schema = normalizeGValue (value, 0);
        if (m_double_pinyin_schema >= 5) {
            m_double_pinyin_schema = 0;
            g_warn_if_reached ();
        }
    }
    else if (STRING_DOUBLE_PINYIN_SHOW_RAW == name)
        m_double_pinyin_show_raw = normalizeGValue (value, false);
    /* init states */
    else if (STRING_INIT_CHINESE == name)
        m_init_chinese = normalizeGValue (value, true);
    else if (STRING_INIT_FULL == name)
        m_init_full = normalizeGValue (value, true);
    else if (STRING_INIT_FULL_PUNCT == name)
        m_init_full_punct = normalizeGValue (value, true);
    else if (STRING_INIT_SIMP_CHINESE == name)
        m_init_simp_chinese = normalizeGValue (value, true);
    else if (STRING_SPECIAL_PHRASES == name)
        m_special_phrases = normalizeGValue (value, true);
    /* lookup table page size */
    else if (STRING_ORIENTATION == name) {
        m_orientation = normalizeGValue (value, 0);
        if (m_orientation != IBUS_ORIENTATION_VERTICAL &&
            m_orientation != IBUS_ORIENTATION_HORIZONTAL) {
            m_orientation = IBUS_ORIENTATION_HORIZONTAL;
            g_warn_if_reached ();
        }
    }
    else if (STRING_PAGE_SIZE == name) {
        m_page_size = normalizeGValue (value, 5);
        if (m_page_size > 10) {
            m_page_size = 5;
            g_warn_if_reached ();
        }
    }
    else if (STRING_SHIFT_SELECT_CANDIDATE == name)
        m_shift_select_candidate = normalizeGValue (value, false);
    else if (STRING_MINUS_EQUAL_PAGE == name)
        m_minus_equal_page = normalizeGValue (value, true);
    else if (STRING_COMMA_PERIOD_PAGE == name)
        m_comma_period_page = normalizeGValue (value, true);
    else if (STRING_AUTO_COMMIT == name)
        m_auto_commit = normalizeGValue (value, false);
    else if (STRING_BOPOMOFO_KEYBOARD_MAPPING == name)
        m_bopomofoKeyboardMapping = normalizeGValue (value, 0);
    /* correct pinyin */
    else if (STRING_CORRECT_PINYIN == name) {
        if (normalizeGValue (value, TRUE))
            m_option_mask |= PINYIN_CORRECT_ALL;
        else
            m_option_mask &= ~PINYIN_CORRECT_ALL;
    }
    /* fuzzy pinyin */
    else if (STRING_FUZZY_PINYIN == name) {
        if (normalizeGValue (value, TRUE))
            m_option_mask |= PINYIN_FUZZY_ALL;
        else
            m_option_mask &= ~PINYIN_FUZZY_ALL;
    }
    else {
        for (guint i = 0; i < G_N_ELEMENTS (options); i++) {
            if (G_LIKELY (options[i].name != name))
                continue;
            if (normalizeGValue (value, options[i].defval))
                m_option |= options[i].option;
            else
                m_option &= ~options[i].option;
            break;
        }
    }

}

void
Config::valueChangedCallback (IBusConfig    *config,
                              const gchar   *section,
                              const gchar   *name,
                              const GValue  *value,
                              Config        *self)
{
    self->valueChanged (section, name, value);
}

void
PinyinConfig::init (Bus & bus)
{
    if (PinyinConfig::m_instance == NULL) {
        PinyinConfig::m_instance.reset (new PinyinConfig (bus));
    }
}

void
BopomofoConfig::init (Bus & bus)
{
    if (BopomofoConfig::m_instance == NULL) {
        BopomofoConfig::m_instance.reset (new BopomofoConfig (bus));
    }
}

};
