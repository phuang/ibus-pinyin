# -*- coding: utf-8 -*-
# vim:set et sts=4 sw=4:
#
# ibus-pinyin - The PinYin engine for IBus
#
# Copyright(c) 2007-2008 Huang Peng <shawn.p.huang@gmail.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or(at your option)
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

import ibus
import gobject
from ibus import keysyms
from ibus import modifier
from ibus import ascii

# from scim import IMEngine
# from scim import Attribute
import pyparser
import pysqlitedb
from specialtable import SpecialTable
from specialphrase import SpecialPhrase
import pyutil
import pydict

from gettext import dgettext
_  = lambda a : dgettext("ibus-pinyin", a)
N_ = lambda a : a

__MAX_LEN__ = 64        # Max length of preedit pinyin

# Define colours
RGB = lambda r, g, b : (((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff) )

try:
    import enchant
    __EN_DICT__ = enchant.Dict("en_US")
except:
    class MY_DICT:
        def __init__(self):
            pass
        def suggest(self, word):
            return []
        def check(self, word):
            return True
    __EN_DICT__ = MY_DICT()



class PinYinEngine(ibus.EngineBase):
    
    # create pinyin database
    __pydb = pysqlitedb.PYSQLiteDB(user_db = "user.db")

    # create special table
    __special_phrase = SpecialPhrase()
    __special_table = SpecialTable()
    
    # shuang pin 
    __shuangpin = False
    __shuangpin_schema = "MSPY"

    # gbk
    __gbk = True

    # fuzzy pinyin & auto correct
    __fuzzy_pinyin = False
    __auto_correct = True
    __spell_check = True

    # colors
    __phrase_color             = RGB(0, 0, 0)
    __user_phrase_color         = RGB(0, 0, 0xef)
    __new_phrase_color         = RGB(0xef, 0, 0)
    __special_phrase_color     = RGB(0, 0xbf, 0)
    __english_phrase_color     = RGB(0, 0xbf, 0)
    __error_eng_phrase_color    = RGB(0xef, 0, 0)

    # lookup table page size
    __page_size = 5

    # press [u] or [v] to temp English mode
    __uv_to_temp = True
    
    # press [shift] to select candidates
    __shift_select_candidates = True

    # press [-] [=] to page down & up candidates
    __equal_page_down_up = True

    # press [,] [.] to page down & up candidates
    __comma_page_down_up = True

    # auto commit
    __auto_commit = False


    def __init__(self, conn, object_path):
        super(PinYinEngine, self).__init__(conn, object_path)
        
        self.__need_update = False
        self.__lookup_table = ibus.LookupTable(PinYinEngine.__page_size)
        
        self.__py_parser = pyparser.PinYinParser()
        self.__user_input = UserInput(self.__py_parser)
        
        # 0 = english input mode
        # 1 = chinese input mode
        self.__mode = 1
        self.__full_width_letter = [False, False]
        self.__full_width_punct = [False, True]
        self.__full_width_punct[1] = True #config.read("/IMEngine/Python/PinYin/FullWidthPunct", True)

        self.__committed_phrases = PhraseList()
        self.__preedit_phrases = PhraseList()
        self.reset()

        # init properties
        self.__prop_list = ibus.PropList()
        self.__status_property = ibus.Property("status")
        self.__prop_list.append(self.__status_property)
        self.__letter_property = ibus.Property("full_letter")
        self.__prop_list.append(self.__letter_property)
        self.__punct_property = ibus.Property("full_punct")
        self.__prop_list.append(self.__punct_property)
        # self.__shuangpin_property = ibus.Property("shuangpin")
        # self.__prop_list.append(self.__shuangpin_property)
        # self.__gbk_property = ibus.Property("gbk")
        # self.__prop_list.append(self.__gbk_property)
        self.__setup_property = ibus.Property("setup")
        self.__prop_list.append(self.__setup_property)


    def __refresh_properties(self):
        if self.__mode == 1: # refresh mode
            self.__status_property.label = _("CN")
            self.__status_property.tip = _("Switch to English mode")
        else:
            self.__status_property.label = _("EN")
            self.__status_property.tip = _("Switch to Chinese mode")

        if self.__full_width_letter[self.__mode]:
            self.__letter_property.icon = "/usr/share/scim/icons/full-letter.png" 
            self.__letter_property.tip = _("Switch to half letter mode")
        else:
            self.__letter_property.icon = "/usr/share/scim/icons/half-letter.png" 
            self.__letter_property.tip = _("Switch to full letter mode")

        if self.__full_width_punct[self.__mode]:
            self.__punct_property.icon = "/usr/share/scim/icons/full-punct.png" 
            self.__punct_property.tip = _("Switch to half punctuation mode")
        else:
            self.__punct_property.icon = "/usr/share/scim/icons/half-punct.png" 
            self.__punct_property.tip = _("Switch to full punctuation mode")

        # if PinYinEngine.__shuangpin:
        #     self.__shuangpin_property.label = _("SHUANG")
        #     self.__shuangpin_property.tip = _("Switch to QUAN PIN")
        # else:
        #     self.__shuangpin_property.label = _("QUAN")
        #     self.__shuangpin_property.tip = _("Switch to SHUANG PIN")

        # if PinYinEngine.__gbk:
        #     self.__gbk_property.label = _("GBK")
        #     self.__gbk_property.tip = _("Switch to GB2312 codeset")
        # else:
        #     self.__gbk_property.label = _("GB")
        #     self.__gbk_property.tip = _("Switch to GBK codeset")
            
        properties =(
            self.__status_property, 
            self.__letter_property, 
            self.__punct_property, 
            # self.__shuangpin_property, 
            # self.__gbk_property,
            )

        for prop in properties:
            self.update_property(prop)
        

    def __change_mode(self):
        self.__mode =(self.__mode + 1) % 2
        self.__refresh_properties()

    def __is_input_english(self):
        return self.__mode == 0

    def __update_candidates(self):
        if self.__temp_english_mode:
            if self.__spell_check == False:
                return
            self.__english_candidates = []
            string = "".join(self.__user_input.get_chars())
            if string[0] in u"uv":
                string = string [1:]
            words = string.split()
            if not words:
                return
            word = words[-1]
            
            if len(words) == 1 and word[0:1] in u"uv":
                word = word[1:]

            if not word.isalpha():
                return
            if  __EN_DICT__.check(word):
                return
            self.__current_word = word
            candidates = __EN_DICT__.suggest(word)
            is_same  = lambda x : x[0].isupper() == word[0].isupper()
            self.__english_candidates = filter(is_same, candidates)[:10]
            return

        if self.__i_mode:
            chars = self.__user_input.get_chars()[1:]
            self.__candidates = self.__special_phrase.lookup(u"".join(chars))
            self.__candidates += self.__special_table.lookup(u"".join(chars))
            return
        
        self.__preedit_phrases.clean()
        
        if len(self.__user_input.get_pinyin_list()) == 0:
            self.__candidates = []
            self.__special_candidates = []
            return

        if len(self.__committed_phrases) == 0:
            self.__special_candidates = self.__special_phrase.lookup(u"".join(self.__user_input.get_chars()))
        else:
            self.__special_candidates = []
            

        pinyin_list = self.__user_input.get_pinyin_list()
        pinyin_list = pinyin_list [self.__committed_phrases.length_of_chars():]


        if pinyin_list:
            self.__candidates =  self.__get_candidates(pinyin_list)
            self.__preedit_phrases.append(self.__candidates[0])

        count = self.__preedit_phrases.length_of_chars()

        while count < len(pinyin_list):
            candidate = self.__get_a_candidate(pinyin_list[count:])
            self.__preedit_phrases.append(candidate)
            count += candidate[pysqlitedb.YLEN]

    def __update_ui(self):
        if self.__i_mode:
            preedit_string = u"".join(self.__user_input.get_chars())
            self.update_preedit(preedit_string, None, len(preedit_string), True)
            
            self.update_aux_string(u"", None, False)
            
            self.__lookup_table.clean()
            self.__lookup_table.show_cursor(True)
            if not self.__candidates:
                self.update_lookup_table(self.__lookup_table, False)
            else:
                for c in self.__candidates:
                    self.__lookup_table.append_candidate(c)
                self.update_lookup_table(self.__lookup_table, True)
            return 
            
        if self.__temp_english_mode:
            preedit_string = u"".join(self.__user_input.get_chars())
            if preedit_string [0:1] in(u"v", u"u"):
                preedit_string = " " + preedit_string[1:]
            else:
                preedit_string = " " + preedit_string

            words = preedit_string.split()
            if words:
                aux_string = words[-1]
            else:
                aux_string = u""

            if preedit_string and self.__spell_check:
                self.update_preedit(preedit_string, None, len(preedit_string), True)
                attrs = ibus.AttrList()
                if  not __EN_DICT__.check(aux_string): 
                    attr = ibus.AttributeForeground(PinYinEngine.__error_eng_phrase_color, 0, len(aux_string))
                    attrs.append(attr)
                self.update_aux_string(aux_string, attrs, True)
            else:
                self.update_preeditString(u"", None, 0, False)
                self.update_aux_string(u"", None, False)


            self.__lookup_table.clean()
            self.__lookup_table.show_cursor(False)
            if not self.__english_candidates:
                self.update_lookup_table(self.__lookup_table, False)
            else:
                for c in self.__english_candidates:
                    attrs = ibus.AttrList()
                    artr = ibus.AttributeForeground(PinYinEngine.__english_phrase_color, 0, len(c))
                    self.__lookup_table.append_candidate(c, attrs)
                self.update_lookup_table(self.__lookup_table, True)
                
            return

        if len(self.__candidates) == 0:
            self.update_lookup_table(self.__lookup_table, False)
        else:
            self.__lookup_table.clean()
            candidates = self.__candidates[:]
            if len(self.__preedit_phrases) != 1: # we need display the automatically created new phrase
                attrs = ibus.AttrList ()
                preedit_string = self.__preedit_phrases.get_string()
                attr = ibus.AttributeForeground(PinYinEngine.__new_phrase_color, 0, len(preedit_string))
                attrs.append (attr)
                self.__lookup_table.append_candidate(preedit_string, attrs)
            else:
                c = candidates[0]
                attrs = ibus.AttrList ()
                if c[pysqlitedb.FREQ] == None: # This phrase was created by user.
                    attr = ibus.AttributeForeground(PinYinEngine.__user_phrase_color, 0, c[pysqlitedb.YLEN])
                else:
                    attr = ibus.AttributeForeground(PinYinEngine.__phrase_color, 0, c[pysqlitedb.YLEN])
                attrs.append(attr)
                self.__lookup_table.append_candidate(c[pysqlitedb.PHRASE], attrs)
                del candidates[0]

            for c in self.__special_candidates:
                attr = ibus.AttributeForeground(PinYinEngine.__special_phrase_color, 0, len(c))
                attrs.append(attr)
                self.__lookup_table.append_candidate(c)

            for c in candidates:
                attrs = ibus.AttrList ()
                if c[pysqlitedb.FREQ] == None: # This phrase was created by user.
                    attr = ibus.AttributeForeground(PinYinEngine.__user_phrase_color, 0, c[pysqlitedb.YLEN])
                else:
                    attr = ibus.AttributeForeground(PinYinEngine.__phrase_color, 0, c[pysqlitedb.YLEN])
                attrs.append(attr)
                self.__lookup_table.append_candidate(c[pysqlitedb.PHRASE], attrs)
            self.__lookup_table.show_cursor(True)
            self.__lookup_table.set_cursor_pos(0)
            self.update_lookup_table(self.__lookup_table, True)
        
        committed_string = self.__committed_phrases.get_string()
        invalid_pinyin = self.__user_input.get_invalid_string()
        preedit_string = " ".join([committed_string, self.__preedit_phrases.get_string(), invalid_pinyin])
        preedit_string = preedit_string.strip()

        if preedit_string:
            self.update_preedit(preedit_string, None, len(preedit_string), True)
        else:
            self.update_preedit("", None, 0, False)
            
        if committed_string or len(self.__user_input) != 0:
            pinyin_list = self.__user_input.get_pinyin_list()
            pinyin_list = pinyin_list [len(committed_string):]
            pinyin_list = map(str, pinyin_list)
            if committed_string:
                aux_string = u"".join([committed_string, u" ", u"'".join(pinyin_list)])
            else:
                aux_string = u"'".join(pinyin_list)
                
            if aux_string:
                self.update_aux_string(aux_string, None, True)
            else:
                self.update_aux_string(u"", None, False)
        else:
            self.update_aux_string(u"", None, False)

    def __invalidate(self):
        if self.__need_update:
            return
        self.__need_update = True
        gobject.idle_add(self.__update, priority = gobject.PRIORITY_LOW)

    def __update(self):
        if self.__need_update:
            self.__update_candidates()
            self.__update_ui()
            self.__need_update = False
    
    def __is_gb2312(self, record):
        try:
            record[pysqlitedb.PHRASE].encode("gb2312")
        except:
            return False
        return True

    def __get_candidates(self, pinyin_list):
        candidates = []
        
        for i in range(len(pinyin_list), 0, -1):
            candidates += self.__pydb.select_words_by_pinyin_list(pinyin_list[:i], PinYinEngine.__fuzzy_pinyin)
        if not PinYinEngine.__gbk:
            candidates = filter(self.__is_gb2312, candidates)
        return candidates

    def __get_a_candidate(self, pinyin_list):
        for i in range(len(pinyin_list), 0, -1):
            candidates = self.__pydb.select_words_by_pinyin_list(pinyin_list[:i], PinYinEngine.__fuzzy_pinyin)
            if not PinYinEngine.__gbk:
                candidates = filter(self.__is_gb2312, candidates)
            if candidates:
                return candidates[0]
        return None


    def __append_char(self, char):
        self.__user_input.append(char)
        self.__committed_phrases.clean()
        self.__invalidate()

        return True

    def __pop_char(self):
        if len(self.__user_input) == 0:
            return False
        if len(self.__committed_phrases) != 0:
            self.__committed_phrases.pop()
        else:
            self.__user_input.pop()
        self.__invalidate()
        
        return True

    def __match_hotkey(self, key, code, mask):
        if key.code == code and key.mask == mask:
            if self.__prev_key and key.code == self.__prev_key.code and key.mask & modifier.RELEASE_MASK:
                return True
            if not key.mask & modifier.RELEASE_MASK:
                return True

        return False

    def __internal_process_key_event(self, key):
        
        # When CapsLock is lock, we ignore all key events
        if key.mask & modifier.LOCK_MASK:
            return False
        
        # Match mode switch hotkey
        if self.__match_hotkey(key, keysyms.Shift_L, modifier.SHIFT_MASK + modifier.RELEASE_MASK) or \
            self.__match_hotkey(key, keysyms.Shift_R, modifier.SHIFT_MASK + modifier.RELEASE_MASK):
            if self.__candidates and not self.__is_input_english() and PinYinEngine.__shift_select_canidates:
                index = self.__lookup_table.get_current_page_start()
                if key.code == keysyms.Shift_L:
                    index += 1
                else:
                    index += 2
                result = self.__commit_candidate(index)
                if result:
                    if self.__committed_special_phrase:
                        self.commit_string(self.__committed_special_phrase)
                    else:
                        commit_phrases = self.__committed_phrases.get_phrases()
                        commit_string = self.__committed_phrases.get_string()
                        self.commit_string(commit_string + self.__user_input.get_invalid_string())
                        
                        # adjust phrase freq and create new phrase
                        self.__pydb.commit_phrases(commit_phrases)
                        if len(commit_phrases) > 1:
                            self.__pydb.new_phrase(commit_phrases)
                return True
            else:
                self.trigger_property("status")
                self.reset()
            return True
        
        # Match full half letter mode switch hotkey
        if self.__match_hotkey(key, keysyms.space, modifier.SHIFT_MASK):
            self.trigger_property("full_letter")
            return True
        
        # Match full half punct mode switch hotkey
        if self.__match_hotkey(key, keysyms.period, modifier.CONTROL_MASK):
            self.trigger_property("full_punct")
            return True

        # Match remove user phrase hotkeys
        for code in xrange(keysyms._1, keysyms._1 + PinYinEngine.__page_size):
            if self.__match_hotkey(key, code, modifier.CONTROL_MASK):
                index = code - keysyms._1 + self.__lookup_table.get_current_page_start()
                return self.__remove_candidate(index)

        # we ignore all hotkeys
        if key.mask &(modifier.CONTROL_MASK + modifier.ALT_MASK):
            return False

        # Ignore key release event
        if key.mask & modifier.RELEASE_MASK:
            return True
        
        if self.__is_input_english():
            return self.__english_mode_process_key_event(key)
        else:
            if self.__temp_english_mode:
                return self.__temp_english_mode_process_key_event(key)
            elif self.__i_mode:
                return self.__i_mode_process_key_event(key)
            else:
                return self.__chinese_mode_process_key_event(key)

    def __convert_to_full_width(self, c):
        if c == u".":
            return u"\u3002"
        elif c == u"\\":
            return u"\u3001"
        elif c == u"^":
            return u"\u2026\u2026"
        elif c == u"_":
            return u"\u2014\u2014"
        elif c == u"$":
            return u"\uffe5"
        elif c == u"\"":
            self.__double_quotation_state = not self.__double_quotation_state
            if self.__double_quotation_state:
                return u"\u201c"
            else:
                return u"\u201d"
        elif c == u"'":
            self.__single_quotation_state = not self.__single_quotation_state
            if self.__single_quotation_state:
                return u"\u2018"
            else:
                return u"\u2019"
 
        elif c == u"<":
            if not self.__is_input_english():
                return u"\u300a"
        elif c == u">":
            if not self.__is_input_english():
                return u"\u300b"
         
        return ibus.unichar_half_to_full(c)
    
    def __english_mode_process_key_event(self, key):
        # ignore if key code is not a normal ascii char
        if key.code >= 128:
            return False

        c = unichr(key.code)
        if ascii.ispunct(key.code): # if key code is a punctation
            if self.__full_width_punct[self.__mode]:
                self.commit_string(self.__convert_to_full_width(c))
                return True
            else:
                self.commit_string(c)
                return True
            
        if self.__full_width_letter[self.__mode]: # if key code is a letter or digit
            self.commit_string(self.__convert_to_full_width(c))
            return True
        else:
            self.commit_string(c)
            return True
        
        # should not reach there
        return False

    def __i_mode_process_key_event(self, key):
        if key.code in(keysyms.Return, keysyms.KP_Enter):
            commit_string = u"".join(self.__user_input.get_chars())
            self.commit_string(commit_string)
            return True
        elif key.code == keysyms.BackSpace and len(self.__user_input) != 0:
            self.__user_input.pop()
            if len(self.__user_input) == 0:
                self.__i_mode = False
            self.__invalidate()
            return True
        elif key.code == keysyms.Escape:
            self.__user_input.clean()
            self.__i_mode = False
            self.__invalidate()
            return True
        elif key.code >= keysyms._1 and key.code <= keysyms._9:
            if not self.__candidates:
                return True
            index = key.code - keysyms._1
            if index >= PinYinEngine.__page_size:
                return True
            index += self.__lookup_table.get_current_page_start()
            if index >= len(self.__candidates):
                return True
            self.commit_string(self.__candidates[index])
            return True
        elif key.code in(keysyms.KP_Space, keysyms.space):
            if not self.__candidates:
                return True
            index = self.__lookup_table.get_cursor_pos()
            if index >= len(self.__candidates):
                return True
            self.commit_string(self.__candidates[index])
            return True
        elif key.code == keysyms.Down:
            self.cursor_down()
            return True
        elif key.code == keysyms.Up:
            self.cursor_up()
            return True
        elif key.code == keysyms.Page_Down and self.__candidates: # press PageDown
            self.page_down()
            return True
        elif key.code == keysyms.Page_Up and self.__candidates: # press PageUp
            self.page_up()
            return True
        elif key.code == keysyms.period and self.__candidates and PinYinEngine.__comma_page_down_up: # press .
            self.page_down()
            return True
        elif key.code == keysyms.comma and self.__candidates and PinYinEngine.__comma_page_down_up: # press ,
            self.page_up()
            return True
        elif key.code == keysyms.equal and self.__candidates and PinYinEngine.__equal_page_down_up: # press =
            self.page_down()
            return True
        elif key.code == keysyms.minus and self.__candidates and PinYinEngine.__equal_page_down_up: # press -
            self.page_up()
            return True

        if key.code >= 128:
            return True
        
        self.__user_input.append(unichr(key.code))
        self.__invalidate()
        
        return True

    def __temp_english_mode_process_key_event(self, key):
        if key.code in(keysyms.Return, keysyms.KP_Enter):
            commit_string = u"".join(self.__user_input.get_chars())
            if commit_string[0] in(u"v", u"u"):
                commit_string = commit_string[1:]
            self.commit_string(commit_string)
            return True
        elif key.code == keysyms.BackSpace and len(self.__user_input) != 0:
            self.__user_input.pop()
            if len(self.__user_input) == 0:
                self.__temp_english_mode = False
            self.__invalidate()
            return True
        elif key.code == keysyms.Escape:
            self.__user_input.clean()
            self.__temp_english_mode = False
            self.__invalidate()
            return True
        elif key.code >= keysyms._1 and key.code <= keysyms._9 and self.__english_candidates:
            index = key.code - keysyms._1
            if index >= PinYinEngine.__page_size:
                return False
            index += self.__lookup_table.get_current_page_start()
            if index >=0 and index < len(self.__english_candidates):
                for i in xrange(0, len(self.__current_word)):
                    self.__user_input.pop()
                for c in self.__english_candidates[index]:
                    self.__user_input.append(c)
                self.__invalidate()
                return True
            return False
        elif key.code in(keysyms.Page_Down, ) and self.__english_candidates:
            self.page_down()
            return True
        elif key.code in(keysyms.Page_Up, ) and self.__english_candidates:
            self.page_up()
            return True

        if key.code >= 128:
            return True

        self.__user_input.append(unichr(key.code))
        self.__invalidate()

        return True

    def __chinese_mode_process_key_event(self, key):
        # define a condition half to full width translate functions
        cond_letter_translate = lambda(c): \
            self.__convert_to_full_width(c) if self.__full_width_letter [self.__mode] else c
        cond_punct_translate = lambda(c): \
            self.__convert_to_full_width(c) if self.__full_width_punct [self.__mode] else c

        if key.code in(keysyms.Return, keysyms.KP_Enter):
            if len(self.__user_input) == 0: # forward Return if inputed chars is empty
                return False
            chars = map(cond_letter_translate, self.__user_input.get_chars())
            commit_string = u"".join(chars)
            self.commit_string(commit_string)
            return True
        elif key.code == keysyms.Escape:
            if len(self.__user_input) != 0:
                self.reset()
                return True
            return False
        elif key.code == keysyms.Down:
            return self.cursor_down()
        elif key.code == keysyms.Up:
            return self.cursor_up()
        elif key.code == keysyms.BackSpace:
            return self.__pop_char()
        elif key.code >= keysyms._1 and key.code <= keysyms._9:
            if not self.__candidates:
                self.commit_string(cond_letter_translate(unichr(key.code)))
            else:
                index = key.code - keysyms._1
                if index >= PinYinEngine.__page_size:
                    return True
                index += self.__lookup_table.get_current_page_start()
                result = self.__commit_candidate(index)
                if result:
                    if self.__committed_special_phrase:
                        self.commit_string(self.__committed_special_phrase)
                    else:
                        commit_phrases = self.__committed_phrases.get_phrases()
                        commit_string = self.__committed_phrases.get_string()
                        self.commit_string(commit_string + self.__user_input.get_invalid_string())
                        
                        # adjust phrase freq and create new phrase
                        self.__pydb.commit_phrases(commit_phrases)
                        if len(commit_phrases) > 1:
                            self.__pydb.new_phrase(commit_phrases)
            return True
        elif key.code in(keysyms.KP_Space, keysyms.space):
            if not self.__candidates:
                self.commit_string(cond_letter_translate(u" "))
            else:
                index = self.__lookup_table.get_cursor_pos()
                result = self.__commit_candidate(index)
                if result:
                    if self.__committed_special_phrase:
                        self.commit_string(self.__committed_special_phrase)
                    else:
                        commit_phrases = self.__committed_phrases.get_phrases()
                        commit_string = self.__committed_phrases.get_string()
                        self.commit_string(commit_string + self.__user_input.get_invalid_string())
                        
                        # adjust phrase freq and create new phrase
                        self.__pydb.commit_phrases(commit_phrases)
                        if len(commit_phrases) > 1:
                            self.__pydb.new_phrase(commit_phrases)
            return True
        elif key.code == keysyms.Page_Down and self.__candidates: # press PageDown
            self.page_down()
            return True
        elif key.code == keysyms.equal and self.__candidates and PinYinEngine.__equal_page_down_up: # press equal
            self.page_down()
            return True
        elif key.code == keysyms.period and self.__candidates and PinYinEngine.__comma_page_down_up: # press period
            self.page_down()
            return True
        elif key.code == keysyms.Page_Up and self.__candidates: # press PageUp
            self.page_up()
            return True
        elif key.code == keysyms.minus and self.__candidates and PinYinEngine.__equal_page_down_up: # press minus
            self.page_up()
            return True
        elif key.code == keysyms.comma and self.__candidates and PinYinEngine.__comma_page_down_up: #press comma
            self.page_up()
            return True

        elif key.code in(keysyms.bracketleft, keysyms.bracketright) and self.__candidates:
            cursor_pos = self.__lookup_table.get_cursor_pos()
            candidate = self.__candidates[cursor_pos]
            if key.code == keysyms.bracketleft:
                i = 0
            else:
                i = len(candidate[pysqlitedb.PHRASE]) - 1
            char = candidate[pysqlitedb.PHRASE][i]
            if i < 4:
                pinyin_id = candidate[pysqlitedb.Y0 + i]
                shengmu_id = candidate[pysqlitedb.S0 + i]
            else:
                pinyin = candidate[pysqlitedb.YX].split("'")[-1]
                word = pyutil.PinYinWord(pinyin)
                pinyin_id = word.get_pinyin_id()
                shengmu_id = word.get_sheng_mu_id()

            self.__pydb.commit_char(char, pinyin_id, shengmu_id)
            self.commit_string(char)
            return True
        elif PinYinEngine.__uv_to_temp and not PinYinEngine.__shuangpin \
             and len(self.__user_input) == 0 \
             and key.code in(keysyms.v, keysyms.u):
            self.__user_input.append(unichr(key.code))
            self.__temp_english_mode = True
            self.__invalidate()
            return True
        elif key.code >= keysyms.A and key.code <= keysyms.Z and len(self.__user_input) == 0:
            self.__user_input.append(unichr(key.code))
            self.__temp_english_mode = True
            self.__invalidate()
            return True
        elif not PinYinEngine.__shuangpin \
             and len(self.__user_input) == 0 \
             and key.code == keysyms.i:
            self.__user_input.append(unichr(key.code))
            self.__i_mode = True
            self.__invalidate()
            return True
        elif(key.code >= keysyms.a and key.code <= keysyms.z) or \
           (key.code == keysyms.apostrophe and len(self.__user_input) != 0) or \
           (key.code == keysyms.semicolon and len(self.__user_input) != 0 and PinYinEngine.__shuangpin) :
            return self.__append_char(unichr(key.code))
        elif key.code <= 127:
            if len(self.__user_input) != 0:
                if PinYinEngine.__auto_commit:
                    self.__chinese_mode_process_key_event(KeyEvent(keysyms.space, True, key.mask))
                else:
                    return True
            c = chr(key.code)
            if c == "." and self.__prev_char and self.__prev_char.isdigit() \
                and self.__prev_key and chr(self.__prev_key.code) == self.__prev_char:
                self.commit_string(u".")
            elif ascii.ispunct(key.code):
                self.commit_string(cond_punct_translate(unichr(key.code)))
            else:
                self.commit_string(cond_letter_translate(unichr(key.code)))
            return True
        
        return False

    def __commit_candidate(self, i):
        if i == 0:
            for phrase in self.__preedit_phrases.get_phrases():
                self.__committed_phrases.append(phrase)
            return True
            
        if i >=1 and i <= len(self.__special_candidates):
            self.__committed_special_phrase = self.__special_candidates [i - 1]
            return True
            
        if len(self.__preedit_phrases) != 1:
            i -= 1

        i -= len(self.__special_candidates)

        if i >= len(self.__candidates):
            return False

        self.__committed_phrases.append( self.__candidates[i])
        pinyin_list = self.__user_input.get_pinyin_list()
        
        if self.__committed_phrases.length_of_chars() == len(pinyin_list):
            return True
        
        self.__invalidate()

        return False

    def __remove_candidate(self, i):
        if i >= 1:
            i -= len(self.__special_candidates)

        if len(self.__preedit_phrases) != 1:
            i -= 1

        if i >= len(self.__candidates) or i < 0:
            return False

        if self.__candidates[i][pysqlitedb.FREQ] != None: # This phrase was not create by user.
            return False

        candidate = self.__candidates.pop(i)
        self.__pydb.remove_phrase(candidate)
        self.__invalidate()

        return True

    def process_key_event(self, keyval, is_press, state):
        key = KeyEvent (keyval, is_press, state)
        result = self.__internal_process_key_event(key)
        self.__prev_key = key
        return result

    def commit_string(self, string):
        self.__temp_english_mode = False
        self.__i_mode = False
        self.__candidates = []
        self.__english_candidates = []
        self.__cursor = 0
        self.__user_input.clean()
        self.__preedit_string = u""
        self.__committed_phrases.clean()
        self.__committed_special_phrase = u""
        super(PinYinEngine,self).commit_string(string)
        self.__prev_char = string[-1]
        self.__invalidate()

    def page_up(self):
        if self.__lookup_table.page_up():
            self.update_lookup_table(self.__lookup_table, True)
            return True
        
        return True

    def page_down(self):
        if self.__lookup_table.page_down():
            self.update_lookup_table(self.__lookup_table, True)
            return True
        return True

    def cursor_up(self):
        if len(self.__candidates) == 0:
            return False
        
        if self.__lookup_table.cursor_up():
            self.update_lookup_table(self.__lookup_table, True)
        return True

    def cursor_down(self):
        if len(self.__candidates) == 0:
            return False
        
        if self.__lookup_table.cursor_down():
            self.update_lookup_table(self.__lookup_table, True)
        return True

    def reset(self):
        self.__temp_english_mode = False
        self.__i_mode = False
        self.__user_input.clean()
        self.__committed_phrases.clean()
        self.__committed_special_phrase = u""
        self.__preedit_string = u""
        self.__special_candidates = []
        self.__candidates = []
        self.__english_candidates = []
        self.__cursor = 0
        self.__double_quotation_state = False
        self.__single_quotation_state = False
        self.__prev_key = None
        self.__prev_char = None
        self.__invalidate()

    def __focus_in(self):
        self.__init_properties()
        if PinYinEngine.__shuangpin:
            self.__py_parser = pyparser.ShuangPinParser(PinYinEngine.__shuangpin_schema)
        else:
            self.__py_parser = pyparser.PinYinParser()
        self.__user_input.set_parser(self.__py_parser)
        self.__user_input.set_gbk(PinYinEngine.__gbk)
        self.__user_input.set_auto_correct(PinYinEngine.__auto_correct)
        self.__invalidate()
    
    def focus_out(self):
        self.reset()

    def trigger_property(self, property):
        if property == "status":
            self.__change_mode()
        elif property == "full_letter":
            self.__full_width_letter [self.__mode] = not self.__full_width_letter [self.__mode]
            self.__refresh_properties()
        elif property == "full_punct":
            self.__full_width_punct [self.__mode] = not self.__full_width_punct [self.__mode]
            self.__refresh_properties()
        # elif property == "shuangpin":
        #     PinYinEngine.__shuangpin = not PinYinEngine.__shuangpin
        #     self.reset()
        #     if PinYinEngine.__shuangpin:
        #         self.__py_parser = pyparser.ShuangPinParser(PinYinEngine.__shuangpin_schema)
        #     else:
        #         self.__py_parser = pyparser.PinYinParser()
        #     self.__user_input.set_parser(self.__py_parser)
        #     self.__config.write("/IMEngine/Python/PinYin/ShuangPin", PinYinEngine.__shuangpin)
        #     self.__refresh_properties()
        # elif property == "gbk":
        #     PinYinEngine.__gbk = not PinYinEngine.__gbk
        #     self.reset()
        #     self.__config.write("/IMEngine/Python/PinYin/SupportGBK", PinYinEngine.__gbk)
        #     self.__refresh_properties()

        elif property == "setup":
            self.start_helper("eebeecd7-cb22-48f4-8ced-70e42dad1a79")

        IMEngine.trigger_property(self, property)

    def process_helper_event(self, helper_uuid, trans):
        IMEngine.process_helper_event(self, helper_uuid, trans)

    def update_client_capabilities(self, cap):
        IMEngine.update_client_capabilities(self, cap)

    def reload_config(self, config):
        self.__lookup_table.set_page_size(PinYinEngine.__page_size)
        self.focus_in()
    
    def focus_in(self):
        self.register_properties(self.__prop_list)
        print "FocusIn"

    def focus_out(self):
        print "FocusOut"

    def property_activate(self, prop_name):
        print "PropertyActivate(%s)" % prop_name

class KeyEvent:
    def __init__(self, keyval, is_press, state):
        self.code = keyval
        self.mask = state
        if not is_press:
            self.mask |= modifier.RELEASE_MASK
    def __str__(self):
        return "%s 0x%08x" % (keysyms.keycode_to_name(self.code), self.mask)
        

class UserInput:
    "UserInput holds user input chars"
    def __init__(self, parser, max_length = __MAX_LEN__):
        self.__parser = parser
        self.__max_length = max_length
        self.__auto_correct = True
        self.__gbk = True
        self.__chars =([], [])
        self.__pinyin_list = []


    def clean(self):
        self.__chars =([], [])
        self.__pinyin_list = []

    def set_parser(self, parser):
        self.clean()
        self.__parser = parser

    def set_gbk(self, gbk):
        self.__gbk = gbk
        self.clean()

    def set_auto_correct(self, auto_correct):
        self.__auto_correct = auto_correct
        self.clean()

    def get_pinyin_list(self):
        return self.__pinyin_list

    def get_chars(self):
        return self.__chars[0] + self.__chars[1]

    def get_invalid_chars(self):
        return self.__chars[1]

    def get_invalid_string(self):
        return "".join(self.__chars[1])

    def append(self, c):
        if len(self.__chars[0]) + len(self.__chars[1])  == self.__max_length:
            return
            
        if self.__chars[1]:
            self.__chars[1].append(c)
        else:
            try:
                self.__pinyin_list = self.__parser.parse("".join(self.__chars[0] + [c]), self.__auto_correct, self.__gbk)
                self.__chars[0].append(c)
            except:
                self.__chars[1].append(c)

    def pop(self):
        resutl = []
        if len(self.__chars[1]) != 0:
            return self.__chars[1].pop()
        elif len(self.__chars[0]) != 0:
            c = self.__chars[0].pop()
            if len(self.__chars[0]) != 0:
                self.__pinyin_list = self.__parser.parse("".join(self.__chars[0]), self.__auto_correct, self.__gbk)
            else:
                self.__pinyin_list = []
            return c
        else:
            return ""

    def __len__(self):
        return len(self.__chars[0]) + len(self.__chars[1])
    
class PhraseList:
    """PhraseList contains phrases"""
    def __init__(self):
        self.__list = []
        self.__length_of_chars = 0

    def clean(self):
        """Remove all phrases from the list"""
        self.__list = []
        self.__length_of_chars = 0

    def append(self, phrase):
        """Append a phrase into the list"""
        self.__list.append(phrase)
        self.__length_of_chars += phrase[pysqlitedb.YLEN]

    def pop(self):
        phrase = self.__list.pop()
        self.__length_of_chars -= phrase[pysqlitedb.YLEN]
        return phrase

    def count(self):
        """Return count of phrases in the list"""
        return len(self.__list)

    def length_of_chars(self):
        """Return number of chars in all phrases in the list"""
        return self.__length_of_chars

    def get_phrases(self):
        """Return all phrases"""
        return self.__list
    
    def get_string(self):
        """Join all phrases into a string object and return it."""
        get_phrase = lambda x: x[pysqlitedb.PHRASE]
        return u"".join(map(get_phrase, self.__list))

    def __str__(self):
        return self.get_string().encode("utf8")

    def __len__(self):
        return len(self.__list)

    def reload_config(self, config):
        PinYinEngine.__shuangpin_schema = \
            config.read("/IMEngine/Python/PinYin/ShuangPinSchema", "MSPY")
        if PinYinEngine.__shuangpin_schema not in pydict.SHUANGPIN_SCHEMAS:
            PinYinEngine.__shuangpin_schema = "MSPY"

        PinYinEngine.__fuzzy_pinyin = \
            config.read("/IMEngine/Python/PinYin/FuzzyPinYin", False)
        PinYinEngine.__auto_correct = \
            config.read("/IMEngine/Python/PinYin/AutoCorrect", True)
        PinYinEngine.__spell_check = \
            config.read("/IMEngine/Python/PinYin/AutoCorrect", True)
        PinYinEngine.__page_size = \
            config.read("/IMEngine/Python/PinYin/PageSize", 5)
        if PinYinEngine.__page_size < 1 or PinYinEngine.__page_size > 9:
            PinYinEngine.__page_size = 5
        PinYinEngine.__gbk = \
            config.read("/IMEngine/Python/PinYin/SupportGBK", True)
        PinYinEngine.__shuangpin = \
            config.read("/IMEngine/Python/PinYin/ShuangPin", False)

        PinYinEngine.__phrase_color = \
            config.read("/IMEngine/Python/PinYin/PhraseColor", PinYinEngine.__phrase_color)
        PinYinEngine.__new_phrase_color = \
            config.read("/IMEngine/Python/PinYin/NewPhraseColor", PinYinEngine.__new_phrase_color)
        PinYinEngine.__user_phrase_color = \
            config.read("/IMEngine/Python/PinYin/UserPhraseColor", PinYinEngine.__user_phrase_color)
        PinYinEngine.__special_phrase_color = \
            config.read("/IMEngine/Python/PinYin/SpecialPhraseColor", PinYinEngine.__special_phrase_color)
        PinYinEngine.__english_phrase_color = \
            config.read("/IMEngine/Python/PinYin/EnglishPhraseColor", PinYinEngine.__english_phrase_color)
        PinYinEngine.__error_eng_phrase_color = \
            config.read("/IMEngine/Python/PinYin/ErrorEnglishPhraseColor", PinYinEngine.__error_eng_phrase_color)
        PinYinEngine.__uv_to_temp = \
            config.read("/IMEngine/Python/PinYin/UVToTemp", PinYinEngine.__uv_to_temp)
        PinYinEngine.__shift_select_canidates = \
            config.read("/IMEngine/Python/PinYin/ShiftSelectCandidates", PinYinEngine.__shift_select_candidates)
        PinYinEngine.__comma_page_down_up = \
            config.read("/IMEngine/Python/PinYin/CommaPageDownUp", PinYinEngine.__comma_page_down_up)
        PinYinEngine.__equal_page_down_up = \
            config.read("/IMEngine/Python/PinYin/EqualPageDownUp", PinYinEngine.__equal_page_down_up)
        PinYinEngine.__auto_commit = \
            config.read("/IMEngine/Python/PinYin/AutoCommit", PinYinEngine.__auto_commit)


