# vim:set et ts=4 sts=4:
# -*- coding: utf-8 -*-
#
# ibus-pinyin - The Chinese PinYin engine for IBus
#
# Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
# Copyright (c) 2010 BYVoid <byvoid1@gmail.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
import sys
import gtk
import ibus
import locale
import os
import version
import gettext
from xdg import BaseDirectory

_ = lambda a : gettext.dgettext("ibus-pinyin", a)

class PreferencesDialog:
    def __init__(self,engine):
        locale.setlocale(locale.LC_ALL, "")
        localedir = os.getenv("IBUS_LOCALEDIR")
        gettext.bindtextdomain("ibus-pinyin", localedir)
        gettext.bind_textdomain_codeset("ibus-pinyin", "UTF-8")

        self.__bus = ibus.Bus()
        self.__config = self.__bus.get_config()
        self.__builder = gtk.Builder()
        self.__builder.set_translation_domain("ibus-pinyin")
        self.__builder.add_from_file("ibus-pinyin-preferences.ui")
        self.__dialog = self.__builder.get_object("dialog")
        self.__init_pages()
        
        if engine == "pinyin":
            self.__config_namespace = "engine/Pinyin"
            self.__init_general()
            self.__init_pinyin()
            self.__init_fuzzy()
            self.__init_dictionary()
            self.__init_about()
        elif engine == "bopomofo":
            self.__config_namespace = "engine/Bopomofo"
            self.__init_general()
            self.__init_bopomofo()
            self.__init_fuzzy()
            self.__init_dictionary()
            self.__init_about()
            self.__convert_fuzzy_pinyin_to_bopomofo()
            
        else:
            print("Error: Unknown Engine")
            exit()
        
        self.__pages.set_current_page(0)

    def __init_pages(self):
        self.__pages = self.__builder.get_object("pages")
        self.__page_general = self.__builder.get_object("pageGeneral")
        self.__page_pinyin_mode = self.__builder.get_object("pagePinyinMode")
        self.__page_bopomofo_mode = self.__builder.get_object("pageBopomofoMode")
        self.__page_fuzzy = self.__builder.get_object("pageFuzzy")
        self.__page_dictionary = self.__builder.get_object("pageDictionary")
        self.__page_about = self.__builder.get_object("pageAbout")
        
        self.__page_general.hide()
        self.__page_pinyin_mode.hide()
        self.__page_bopomofo_mode.hide()
        self.__page_fuzzy.hide()
        self.__page_dictionary.hide()
        self.__page_about.hide()

    def __init_general(self):
        # page General
        self.__page_general.show()
        
        # init state
        self.__init_chinese = self.__builder.get_object("InitChinese")
        self.__init_english = self.__builder.get_object("InitEnglish")
        self.__init_full = self.__builder.get_object("InitFull")
        self.__init_half = self.__builder.get_object("InitHalf")
        self.__init_full_punct = self.__builder.get_object("InitFullPunct")
        self.__init_half_punct = self.__builder.get_object("InitHalfPunct")
        self.__init_simp = self.__builder.get_object("InitSimplifiedChinese")
        self.__init_trad = self.__builder.get_object("IniTraditionalChinese")
        
        # UI
        self.__lookup_table_page_size = self.__builder.get_object("LookupTablePageSize")
        self.__lookup_table_orientation = self.__builder.get_object("LookupTableOrientation")
        renderer = gtk.CellRendererText()
        self.__lookup_table_orientation.pack_start(renderer)
        self.__lookup_table_orientation.set_attributes(renderer, text=0)

        # read values
        self.__init_chinese.set_active(self.__get_value("InitChinese", True))
        self.__init_full.set_active(self.__get_value("InitFull", False))
        self.__init_full_punct.set_active(self.__get_value("InitFullPunct", True))
        self.__init_simp.set_active(self.__get_value("InitSimplifiedChinese", True))
        self.__lookup_table_orientation.set_active(self.__get_value("LookupTableOrientation", 0))
        self.__lookup_table_page_size.set_value(self.__get_value("LookupTablePageSize", 5))

        # connect signals
        self.__init_chinese.connect("toggled", self.__toggled_cb, "InitChinese")
        self.__init_full.connect("toggled", self.__toggled_cb, "InitFull")
        self.__init_full_punct.connect("toggled", self.__toggled_cb, "InitFullPunct")
        self.__init_simp.connect("toggled", self.__toggled_cb, "InitSimplifiedChinese")

        def __lookup_table_page_size_changed_cb(adjustment):
            self.__set_value("LookupTablePageSize", int(adjustment.get_value()))

        def __lookup_table_orientation_changed_cb(widget):
            self.__set_value("LookupTableOrientation", widget.get_active())

        self.__lookup_table_orientation.connect("changed", __lookup_table_orientation_changed_cb)
        self.__lookup_table_page_size.connect("value-changed", __lookup_table_page_size_changed_cb)

    def __init_pinyin(self):
        # page
        self.__page_pinyin_mode.show()
        
        # pinyin
        self.__full_pinyin = self.__builder.get_object("FullPinyin")
        self.__incomplete_pinyin = self.__builder.get_object("IncompletePinyin")
        self.__double_pinyin = self.__builder.get_object("DoublePinyin")
        self.__double_pinyin_schema = self.__builder.get_object("DoublePinyinSchema")
        # self.__double_pinyin_schema_label = self.__builder.get_object("labelDoublePinyinSchema")
        self.__double_pinyin_show_raw = self.__builder.get_object("DoublePinyinShowRaw")

        renderer = gtk.CellRendererText()
        self.__double_pinyin_schema.pack_start(renderer)
        self.__double_pinyin_schema.set_attributes(renderer, text=0)

        # read value
        self.__incomplete_pinyin.set_active(self.__get_value("IncompletePinyin", True))
        self.__full_pinyin.set_active(not self.__get_value("DoublePinyin", False))
        self.__double_pinyin_schema.set_active(self.__get_value("DoublePinyinSchema", 0))
        if self.__full_pinyin.get_active():
            # self.__incomplete_pinyin.set_sensitive(True)
            self.__double_pinyin_schema.set_sensitive(False)
            # self.__double_pinyin_schema_label.set_sensitive(False)
            self.__double_pinyin_show_raw.set_sensitive(False)
        else:
            # self.__incomplete_pinyin.set_sensitive(False)
            self.__double_pinyin_schema.set_sensitive(True)
            # self.__double_pinyin_schema_label.set_sensitive(True)
            self.__double_pinyin_show_raw.set_sensitive(True)

        def __double_pinyin_toggled_cb(widget):
            val = widget.get_active()
            self.__set_value("DoublePinyin", val)
            self.__double_pinyin_schema.set_sensitive(val)
            # self.__double_pinyin_schema_label.set_sensitive(val)
            self.__double_pinyin_show_raw.set_sensitive(val)

        def __double_pinyin_schema_changed_cb(widget):
            self.__set_value("DoublePinyinSchema", widget.get_active())

        # connect signals
        self.__double_pinyin.connect("toggled", __double_pinyin_toggled_cb)
        self.__incomplete_pinyin.connect("toggled", self.__toggled_cb, "IncompletePinyin")
        self.__double_pinyin_schema.connect("changed", __double_pinyin_schema_changed_cb)
        self.__double_pinyin_show_raw.connect("toggled", self.__toggled_cb, "DoublePinyinShowRaw")
        
        self.__init_input_custom()
        self.__init_correct_pinyin()
        
    def __init_bopomofo(self):
        # page Bopomodo Mode
        self.__page_bopomofo_mode.show()
        
        # bopomofo mode
        self.__incomplete_bopomofo = self.__builder.get_object("IncompleteBopomofo")
        self.__bopomofo_keyboard_mapping = self.__builder.get_object("BopomofoKeyboardMapping")
        renderer = gtk.CellRendererText()
        self.__bopomofo_keyboard_mapping.pack_start(renderer)
        self.__bopomofo_keyboard_mapping.set_attributes(renderer, text=0)
        
        # selection mode
        self.__select_keys = self.__builder.get_object("SelectKeys")
        self.__select_keys.pack_start(renderer)
        self.__select_keys.set_attributes(renderer, text=0)
        self.__guide_key = self.__builder.get_object("GuideKey")
        self.__auxiliary_select_key_f = self.__builder.get_object("AuxiliarySelectKey_F")
        self.__auxiliary_select_key_kp = self.__builder.get_object("AuxiliarySelectKey_KP")

        # read value
        self.__bopomofo_keyboard_mapping.set_active(self.__get_value("BopomofoKeyboardMapping", 0))
        self.__incomplete_bopomofo.set_active(self.__get_value("IncompletePinyin", False))
        self.__select_keys.set_active(self.__get_value("SelectKeys", 0))
        self.__guide_key.set_active(self.__get_value("GuideKey", 1))
        self.__auxiliary_select_key_f.set_active(self.__get_value("AuxiliarySelectKey_F", 1))
        self.__auxiliary_select_key_kp.set_active(self.__get_value("AuxiliarySelectKey_KP", 1))

        # connect signals
        def __bopomofo_keyboard_mapping_changed_cb(widget):
            self.__set_value("BopomofoKeyboardMapping", widget.get_active())
        def __select_keys_changed_cb(widget):
            self.__set_value("SelectKeys", widget.get_active())
        
        self.__bopomofo_keyboard_mapping.connect("changed", __bopomofo_keyboard_mapping_changed_cb)
        self.__incomplete_bopomofo.connect("toggled", self.__toggled_cb, "IncompletePinyin")
        self.__select_keys.connect("changed", __select_keys_changed_cb)
        self.__guide_key.connect("toggled", self.__toggled_cb, "GuideKey")
        self.__auxiliary_select_key_f.connect("toggled", self.__toggled_cb, "AuxiliarySelectKey_F")
        self.__auxiliary_select_key_kp.connect("toggled", self.__toggled_cb, "AuxiliarySelectKey_KP")

    def __init_input_custom(self):
        # others
        self.__shift_select_candidate = self.__builder.get_object("ShiftSelectCandidate")
        self.__minus_equal_page = self.__builder.get_object("MinusEqualPage")
        self.__comma_period_page = self.__builder.get_object("CommaPeriodPage")
        self.__auto_commit = self.__builder.get_object("AutoCommit")

        # read values
        self.__shift_select_candidate.set_active(self.__get_value("ShiftSelectCandidate", False))
        self.__minus_equal_page.set_active(self.__get_value("MinusEqualPage", True))
        self.__comma_period_page.set_active(self.__get_value("CommaPeriodPage", True))
        self.__auto_commit.set_active(self.__get_value("AutoCommit", False))

        # connect signals
        self.__shift_select_candidate.connect("toggled", self.__toggled_cb, "ShiftSelectCandidate")
        self.__minus_equal_page.connect("toggled", self.__toggled_cb, "MinusEqualPage")
        self.__comma_period_page.connect("toggled", self.__toggled_cb, "CommaPeriodPage")
        self.__auto_commit.connect("toggled", self.__toggled_cb, "AutoCommit")

    def __init_correct_pinyin(self):
        # auto correct
        self.__correct_pinyin = self.__builder.get_object("CorrectPinyin")
        self.__correct_pinyin_widgets = [
            ("CorrectPinyin_GN_NG", True),
            ("CorrectPinyin_MG_NG", True),
            ("CorrectPinyin_IOU_IU", True),
            ("CorrectPinyin_UEI_UI", True),
            ("CorrectPinyin_UEN_UN", True),
            ("CorrectPinyin_UE_VE", True),
            ("CorrectPinyin_V_U", True),
        ]

        def __correct_pinyin_toggled_cb(widget):
            val = widget.get_active()
            map(lambda w: self.__builder.get_object(w[0]).set_sensitive(val),
                self.__correct_pinyin_widgets)
        self.__correct_pinyin.connect("toggled", __correct_pinyin_toggled_cb)

        # init value
        self.__correct_pinyin.set_active(self.__get_value("CorrectPinyin", True))
        for name, defval in self.__correct_pinyin_widgets:
            widget = self.__builder.get_object(name)
            widget.set_active(self.__get_value(name, defval))

        self.__correct_pinyin.connect("toggled", self.__toggled_cb, "CorrectPinyin")
        for name, defval in self.__correct_pinyin_widgets:
            widget = self.__builder.get_object(name)
            widget.connect("toggled", self.__toggled_cb, name)

    def __init_fuzzy(self):
        # page Fuzzy
        self.__page_fuzzy.show()
        
        # fuzzy pinyin
        self.__fuzzy_pinyin = self.__builder.get_object("FuzzyPinyin")
        self.__fuzzy_pinyin_widgets = [
            ("FuzzyPinyin_C_CH", True),
            ("FuzzyPinyin_Z_ZH", True),
            ("FuzzyPinyin_S_SH", True),
            ("FuzzyPinyin_CH_C", False),
            ("FuzzyPinyin_ZH_Z", False),
            ("FuzzyPinyin_SH_S", False),
            ("FuzzyPinyin_L_N", True),
            ("FuzzyPinyin_F_H", True),
            ("FuzzyPinyin_L_R", False),
            ("FuzzyPinyin_K_G", True),
            ("FuzzyPinyin_N_L", False),
            ("FuzzyPinyin_H_F", False),
            ("FuzzyPinyin_R_L", False),
            ("FuzzyPinyin_G_K", False),
            ("FuzzyPinyin_AN_ANG", True),
            ("FuzzyPinyin_EN_ENG", True),
            ("FuzzyPinyin_IN_ING", True),
            ("FuzzyPinyin_ANG_AN", True),
            ("FuzzyPinyin_ENG_EN", True),
            ("FuzzyPinyin_ING_IN", True),
            ("FuzzyPinyin_IAN_IANG", True),
            ("FuzzyPinyin_UAN_UANG", True),
            ("FuzzyPinyin_IANG_IAN", True),
            ("FuzzyPinyin_UANG_UAN", True),
        ]

        def __fuzzy_pinyin_toggled_cb(widget):
            val = widget.get_active()
            map(lambda w: self.__builder.get_object(w[0]).set_sensitive(val),
                self.__fuzzy_pinyin_widgets)
        self.__fuzzy_pinyin.connect("toggled", __fuzzy_pinyin_toggled_cb)

        # init value
        self.__fuzzy_pinyin.set_active(self.__get_value("FuzzyPinyin", False))
        for name, defval in self.__fuzzy_pinyin_widgets:
            widget = self.__builder.get_object(name)
            widget.set_active(self.__get_value(name, defval))

        self.__fuzzy_pinyin.connect("toggled", self.__toggled_cb, "FuzzyPinyin")
        for name, defval in self.__fuzzy_pinyin_widgets:
            widget = self.__builder.get_object(name)
            widget.connect("toggled", self.__toggled_cb, name)

    def __convert_fuzzy_pinyin_to_bopomofo(self):
        self.__builder.get_object("FuzzyPinyin_C_CH").set_label("ㄘ => ㄔ")
        self.__builder.get_object("FuzzyPinyin_Z_ZH").set_label("ㄗ => ㄓ")
        self.__builder.get_object("FuzzyPinyin_S_SH").set_label("ㄙ => ㄕ")
        self.__builder.get_object("FuzzyPinyin_CH_C").set_label("ㄔ => ㄘ")
        self.__builder.get_object("FuzzyPinyin_ZH_Z").set_label("ㄓ => ㄗ")
        self.__builder.get_object("FuzzyPinyin_SH_S").set_label("ㄕ => ㄙ")
        self.__builder.get_object("FuzzyPinyin_L_N").set_label("ㄌ => ㄋ")
        self.__builder.get_object("FuzzyPinyin_F_H").set_label("ㄈ => ㄏ")
        self.__builder.get_object("FuzzyPinyin_L_R").set_label("ㄌ => ㄖ")
        self.__builder.get_object("FuzzyPinyin_K_G").set_label("ㄎ => ㄍ")
        self.__builder.get_object("FuzzyPinyin_N_L").set_label("ㄋ => ㄌ")
        self.__builder.get_object("FuzzyPinyin_H_F").set_label("ㄏ => ㄈ")
        self.__builder.get_object("FuzzyPinyin_R_L").set_label("ㄖ => ㄌ")
        self.__builder.get_object("FuzzyPinyin_G_K").set_label("ㄍ => ㄎ")
        self.__builder.get_object("FuzzyPinyin_AN_ANG").set_label("ㄢ => ㄤ")
        self.__builder.get_object("FuzzyPinyin_EN_ENG").set_label("ㄣ => ㄥ")
        self.__builder.get_object("FuzzyPinyin_IN_ING").set_label("ㄧㄣ => ㄧㄥ")
        self.__builder.get_object("FuzzyPinyin_ANG_AN").set_label("ㄤ => ㄢ")
        self.__builder.get_object("FuzzyPinyin_ENG_EN").set_label("ㄥ => ㄣ")
        self.__builder.get_object("FuzzyPinyin_ING_IN").set_label("ㄧㄥ => ㄧㄣ")
        self.__builder.get_object("FuzzyPinyin_IAN_IANG").set_label("ㄧㄢ => ㄧㄤ")
        self.__builder.get_object("FuzzyPinyin_UAN_UANG").set_label("ㄨㄢ => ㄨㄤ")
        self.__builder.get_object("FuzzyPinyin_IANG_IAN").set_label("ㄧㄤ => ㄧㄢ")
        self.__builder.get_object("FuzzyPinyin_UANG_UAN").set_label("ㄨㄤ => ㄨㄢ")

    def __init_dictionary(self):
        # page Dictionary
        self.__page_dictionary.show()
    
        # dictionary
        self.__special_phrases = self.__builder.get_object("SpecialPhrases")
        self.__edit_special_phrases = self.__builder.get_object("EditSpecialPhrases")

        # read values
        self.__special_phrases.set_active(self.__get_value("SpecialPhrases", True))

        def __edit_special_phrases_clicked_cb(widget):
            from xdg import BaseDirectory
            import shutil
            path = os.path.join(BaseDirectory.xdg_config_home, "ibus", "pinyin")
            os.path.exists(path) or os.makedirs(path)
            path = os.path.join(path, "phrases.txt")
            if not os.path.exists(path):
                datadir = os.getenv("IBUS_DATAROOTDIR") or "/usr/share"
                src = os.path.join(datadir, "ibus-pinyin", "phrases.txt")
                shutil.copyfile(src, path)
            os.system("xdg-open %s" % path)

        # connect signals
        self.__special_phrases.connect("toggled", self.__toggled_cb, "SpecialPhrases")
        self.__edit_special_phrases.connect("clicked", __edit_special_phrases_clicked_cb)

    def __init_about(self):
        # page About
        self.__page_about.show()
        
        self.__name_version = self.__builder.get_object("NameVersion")
        self.__name_version.set_markup(_("<big><b>IBus Pinyin %s</b></big>") % version.get_version())

    def __changed_cb(self, widget, name):
        self.__set_value(name, widget.get_active())

    def __toggled_cb(self, widget, name):
        self.__set_value(name, widget.get_active ())

    def __get_value(self, name, defval):
        value = self.__config.get_value(self.__config_namespace, name, "test_default_value_9898")
        if value != "test_default_value_9898":
            return value
        self.__set_value(name, defval)
        return defval

    def __set_value(self, name, val):
        self.__config.set_value(self.__config_namespace, name, val)

    def run(self):
        return self.__dialog.run()

def main():
    name = "pinyin"
    if len(sys.argv) == 2:
        name = sys.argv[1]
    if name not in ("pinyin", "bopomofo"):
        name = "pinyin"
    PreferencesDialog(name).run()


if __name__ == "__main__":
    main()
