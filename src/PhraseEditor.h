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
#ifndef __PY_PHRASE_EDITOR_H_
#define __PY_PHRASE_EDITOR_H_

#include "String.h"
#include "Database.h"
#include "PhraseArray.h"
#include "PinyinProperties.h"

#define FILL_GRAN (12)

namespace PY {

class PhraseEditor {
public:
    PhraseEditor (PinyinProperties & props);
    ~PhraseEditor (void);

    const String & selectedString (void) const { return m_selected_string; }
    const PinyinArray & pinyin (void) const { return m_pinyin; }
    const PhraseArray & candidates (void) const { return m_candidates; }
    guint cursor (void) const { return m_cursor; }
    guint cursorInChar (void) const { return m_cursor == 0 ? 0 : m_pinyin[m_cursor - 1].begin + m_pinyin[m_cursor - 1].len; }
    gboolean pinyinExistsAfterCursor (void) const {
        return m_pinyin.size () > m_cursor;
    }

    const Phrase & candidate (guint i) const {
        return m_candidates[i];
    }

    gboolean fillCandidates (void) {
        if (G_UNLIKELY (m_query.get () == NULL)) {
            return FALSE;
        }

        gint ret = m_query->fill (m_candidates, FILL_GRAN);

        if (G_UNLIKELY (ret < FILL_GRAN)) {
            /* got all candidates from query */
            m_query.reset ();
        }

        return ret > 0 ? TRUE : FALSE;
    }

    const PhraseArray & candidate0 (void) const {
        return m_candidate_0_phrases;
    }

    gboolean candidateIsUserPhease (guint i) const {
        const Phrase & phrase = m_candidates[i];
        return phrase.len > 1 && phrase.user_freq > 0 && phrase.freq == 0;
    }

    gboolean unselectCandidates (void) {
        if (m_cursor == 0) {
            return FALSE;
        }
        else {
            m_selected_phrases.clear ();
            m_selected_string.truncate (0);
            m_cursor = 0;
            updateCandidates ();
            return TRUE;
        }
    }

    void reset (void) {
        m_candidates.clear ();
        m_selected_phrases.clear ();
        m_selected_string.truncate (0);
        m_candidate_0_phrases.clear ();
        m_pinyin.clear ();
        m_cursor = 0;
        m_query.reset ();
    }

    gboolean update (const PinyinArray &pinyin);
    gboolean selectCandidate (guint i);
    gboolean resetCandidate (guint i);
    void commit (void) {
    #if 0
        m_selected_phrases.insert (m_selected_phrases.end (),
                    m_candidate_0_phrases.begin (), m_candidate_0_phrases.end ());
    #endif
        Database::instance ().commit (m_selected_phrases);
        reset ();
    }

    gboolean empty (void) const {
        return m_selected_string.empty () && m_candidate_0_phrases.empty ();
    }

    operator gboolean (void) const {
        return !empty ();
    }

private:
    void updateCandidates (void);
    void updateTheFirstCandidate (void);

private:
    PhraseArray m_candidates;           // candidates phrase array
    PhraseArray m_selected_phrases;     // selected phrases, before cursor
    String      m_selected_string;      // selected phrases, in string format
    PhraseArray m_candidate_0_phrases;  // the first candidate in phrase array format
    PinyinArray m_pinyin;
    guint m_cursor;
    PinyinProperties & m_props;
    QueryPtr    m_query;
};

};

#endif
