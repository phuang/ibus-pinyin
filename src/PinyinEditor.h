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
#ifndef __PY_PINYIN_EDITOR_H_
#define __PY_PINYIN_EDITOR_H_

#include <glib.h>
#include "Editor.h"
#include "Database.h"
#include "PinyinParser.h"
#include "PhraseEditor.h"
#include "SpecialPhraseTable.h"

namespace PY {

#define MAX_PINYIN_LEN 64

class SpecialPhraseTable;

class PinyinEditor : public Editor {
public:
    PinyinEditor (PinyinProperties & props, Config & config = PinyinConfig::instance ());

public:
    /* virtual functions */
    virtual gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    virtual void pageUp (void);
    virtual void pageDown (void);
    virtual void cursorUp (void);
    virtual void cursorDown (void);
    virtual void update (void);
    virtual void reset (void);
    virtual void candidateClicked (guint index, guint button, guint state);
    virtual void updateAuxiliaryTextBefore (String &buffer);
    virtual void updateAuxiliaryTextAfter (String &buffer);
protected:

    gboolean processPinyin (guint keyval, guint keycode, guint modifiers);
    gboolean processCapitalLetter (guint keyval, guint keycode, guint modifiers);
    gboolean processNumber (guint keyval, guint keycode, guint modifiers);
    gboolean processPunct (guint keyval, guint keycode, guint modifiers);
    gboolean processSpace (guint keyval, guint keycode, guint modifiers);
    gboolean processOthers (guint keyval, guint keycode, guint modifiers);

    gboolean fillLookupTableByPage (void);

    void updatePhraseEditor (void) { m_phrase_editor.update (m_pinyin); }
    gboolean updateSpecialPhrases (void);
    gboolean selectCandidate (guint i);
    gboolean selectCandidateInPage (guint i);
    gboolean resetCandidate (guint i);
    gboolean resetCandidateInPage (guint i);

    void commit (const gchar *str);

    const String & text (void) const { return m_text; }
    const gchar * textAfterPinyin (void) const { return (const gchar *)m_text + m_pinyin_len; }
    const gchar * textAfterPinyin (guint i) const {
        g_assert (i <= m_pinyin.size ());
        if ( G_UNLIKELY (i == 0))
            return m_text;
        i--;
        return (const gchar *)m_text + m_pinyin[i].begin + m_pinyin[i].len;
    }
    const gchar * textAfterCursor (void) const { return (const gchar *)m_text + m_cursor; }
    guint cursor (void) const { return m_cursor; }
    gboolean empty (void) const { return m_buffer.empty (); }
    const PinyinArray & pinyin (void) const { return m_pinyin; }
    guint pinyinLength (void) const { return m_pinyin_len; }
    operator gboolean (void) const { return ! empty (); }

    /* virtual functions */
    virtual void updatePreeditText (void);
    virtual void updateAuxiliaryText (void);
    virtual void updateLookupTable (void);
    virtual void commit (void);
    virtual gboolean insert (gint ch) = 0;
    virtual gboolean removeCharBefore (void) = 0;
    virtual gboolean removeCharAfter (void) = 0;
    virtual gboolean removeWordBefore (void) = 0;
    virtual gboolean removeWordAfter (void) = 0;
    virtual gboolean moveCursorLeft (void) = 0;
    virtual gboolean moveCursorRight (void) = 0;
    virtual gboolean moveCursorLeftByWord (void) = 0;
    virtual gboolean moveCursorRightByWord (void) = 0;
    virtual gboolean moveCursorToBegin (void) = 0;
    virtual gboolean moveCursorToEnd (void) = 0;

protected:
    PinyinArray m_pinyin;       // pinyin array
    guint       m_pinyin_len;   // pinyin length in char
    String      m_buffer;       // temp buffer
    LookupTable m_lookup_table;
    PhraseEditor m_phrase_editor;
    std::vector<std::string> m_special_phrases;
    std::string m_selected_special_phrase;
};
};

#endif
