import gtk
import ibus
import locale
import os
import gettext

class PreferencesDialog:
    def __init__(self):
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

        self.__init_pinyin()
        self.__init_init_state()
        self.__init_others()
        self.__init_correct_pinyin()
        self.__init_fuzzy_pinyin()

    def __init_pinyin(self):
        # pinyin
        self.__full_pinyin = self.__builder.get_object("FullPinyin")
        self.__incomplete_pinyin = self.__builder.get_object("IncompletePinyin")
        self.__double_pinyin = self.__builder.get_object("DoublePinyin")
        self.__double_pinyin_schema = self.__builder.get_object("DoublePinyinSchema")
        self.__double_pinyin_schema_label = self.__builder.get_object("labelDoublePinyinSchema")

        renderer = gtk.CellRendererText()
        self.__double_pinyin_schema.pack_start(renderer)
        self.__double_pinyin_schema.set_attributes(renderer, text=0)

        # read value
        self.__incomplete_pinyin.set_active(self.__get_value("IncompletePinyin", True))
        self.__full_pinyin.set_active(not self.__get_value("DoublePinyin", False))
        self.__double_pinyin_schema.set_active(self.__get_value("DoublePinyinSchema", 0))
        if self.__full_pinyin.get_active():
            self.__incomplete_pinyin.set_sensitive(True)
            self.__double_pinyin_schema.set_sensitive(False)
            self.__double_pinyin_schema_label.set_sensitive(False)
        else:
            self.__incomplete_pinyin.set_sensitive(False)
            self.__double_pinyin_schema.set_sensitive(True)
            self.__double_pinyin_schema_label.set_sensitive(True)

        def __full_pinyin_toggled_cb(widget):
            val = widget.get_active()
            self.__set_value("DoublePinyin", not val)
            self.__incomplete_pinyin.set_sensitive(val)

        def __double_pinyin_toggled_cb(widget):
            val = widget.get_active()
            self.__set_value("DoublePinyin", val)
            self.__double_pinyin_schema.set_sensitive(val)
            self.__double_pinyin_schema_label.set_sensitive(val)

        def __double_pinyin_schema_changed_cb(widget):
            self.__set_value("DoublePinyinSchema", widget.get_active())

        # connect signals
        self.__full_pinyin.connect("toggled", __full_pinyin_toggled_cb)
        self.__double_pinyin.connect("toggled", __double_pinyin_toggled_cb)
        self.__incomplete_pinyin.connect("toggled", self.__toggled_cb, "IncompletePinyin")
        self.__double_pinyin_schema.connect("changed", __double_pinyin_schema_changed_cb)

    def __init_init_state(self):
        # init state
        self.__init_chinese = self.__builder.get_object("InitChinese")
        self.__init_english = self.__builder.get_object("InitEnglish")
        self.__init_full = self.__builder.get_object("InitFull")
        self.__init_half = self.__builder.get_object("InitHalf")
        self.__init_full_punct = self.__builder.get_object("InitFullPunct")
        self.__init_half_punct = self.__builder.get_object("InitHalfPunct")
        self.__init_simp = self.__builder.get_object("InitSimplifiedChinese")
        self.__init_trad = self.__builder.get_object("IniTraditionalChinese")

        # read values
        self.__init_chinese.set_active(self.__get_value("InitChinese", True))
        self.__init_full.set_active(self.__get_value("InitFull", False))
        self.__init_full_punct.set_active(self.__get_value("InitFullPunct", True))
        self.__init_simp.set_active(self.__get_value("InitSimplifiedChinese", True))

        # connect signals
        self.__init_chinese.connect("toggled", self.__toggled_cb, "InitChinese")
        self.__init_full.connect("toggled", self.__toggled_cb, "InitFull")
        self.__init_full_punct.connect("toggled", self.__toggled_cb, "InitFullPunct")
        self.__init_simp.connect("toggled", self.__toggled_cb, "InitSimplifiedChinese")

    def __init_others(self):
        #others
        self.__lookup_table_page_size = self.__builder.get_object("LookupTablePageSize")

        self.__shift_select_candidate = self.__builder.get_object("ShiftSelectCandidate")
        self.__minus_equal_page = self.__builder.get_object("MinusEqualPage")
        self.__comma_period_page = self.__builder.get_object("CommaPeriodPage")
        self.__auto_commit = self.__builder.get_object("AutoCommit")
        self.__trad_candidate = self.__builder.get_object("TradCandidate")
        self.__half_width_puncts = self.__builder.get_object("HalfWidthPuncts")

        # read values
        self.__lookup_table_page_size.set_value(self.__get_value("LookupTablePageSize", 5))
        self.__shift_select_candidate.set_active(self.__get_value("ShiftSelectCandidate", False))
        self.__minus_equal_page.set_active(self.__get_value("MinusEqualPage", True))
        self.__comma_period_page.set_active(self.__get_value("CommaPeriodPage", True))
        self.__auto_commit.set_active(self.__get_value("AutoCommit", False))
        self.__trad_candidate.set_active(self.__get_value("TradCandidate", False))
        self.__half_width_puncts.set_text(self.__get_value("HalfWidthPuncts", "+-*/=%"))

        # connect signals
        def __lookup_table_page_size_changed_cb(adjustment):
            self.__set_value("LookupTablePageSize", int(adjustment.get_value()))

        self.__shift_select_candidate.connect("toggled", self.__toggled_cb, "ShiftSelectCandidate")
        self.__minus_equal_page.connect("toggled", self.__toggled_cb, "MinusEqualPage")
        self.__comma_period_page.connect("toggled", self.__toggled_cb, "CommaPeriodPage")
        self.__auto_commit.connect("toggled", self.__toggled_cb, "AutoCommit")
        self.__trad_candidate.connect("toggled", self.__toggled_cb, "TradCandidate")
        self.__lookup_table_page_size.connect("value-changed", __lookup_table_page_size_changed_cb)

        def __entry_activate_cb(widget, name):
            text = widget.get_text()
            self.__set_value(name, text)
        self.__half_width_puncts.connect("activate", __entry_activate_cb, "HalfWidthPuncts")

    def __init_correct_pinyin(self):
        # auto correct
        self.__correct_pinyin = self.__builder.get_object("CorrectPinyin")
        self.__correct_pinyin_widgets = [
            ("CorrectPinyin_GN_NG", True),
            ("CorrectPinyin_MG_NG", True),
            ("CorrectPinyin_IOU_IU", True),
            ("CorrectPinyin_UEI_UI", True),
            ("CorrectPinyin_UEN_UN", True),
            ("CorrectPinyin_VE_UE", True),
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

    def __init_fuzzy_pinyin(self):
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
            ("FuzzyPinyin_IAN_IANG", False),
            ("FuzzyPinyin_UAN_UANG", False),
            ("FuzzyPinyin_IANG_IAN", False),
            ("FuzzyPinyin_UANG_UAN", False),
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

    def __changed_cb(self, widget, name):
        self.__set_value(name, widget.get_active())

    def __toggled_cb(self, widget, name):
        self.__set_value(name, widget.get_active ())

    def __get_value(self, name, defval):
        value = self.__config.get_value("engine/Pinyin", name, "test_default_value_9898")
        if value != "test_default_value_9898":
            return value
        self.__set_value(name, defval)
        return defval

    def __set_value(self, name, val):
        self.__config.set_value("engine/Pinyin", name, val)

    def run(self):
        return self.__dialog.run()

def main():
    PreferencesDialog().run()


if __name__ == "__main__":
    main()
