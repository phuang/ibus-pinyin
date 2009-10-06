#ifndef __PY_PHRASE_EDITOR_H_
#define __PY_PHRASE_EDITOR_H_

#include "Database.h"
#include "PhraseArray.h"

namespace PY {

class PhraseEditor {
public:
    PhraseEditor(void);
    ~PhraseEditor(void);

    const String & selectedString (void) const { return m_selected_string; }
    const PinyinArray & pinyin (void) const { return m_pinyin; }
    const PhraseArray & candidates (void) const { return m_candidates; }
    guint cursor (void) const { return m_cursor; }
    gboolean pinyinExistsAfterCursor (void) const {
        return m_pinyin.length () > m_cursor;
    }

    const Phrase & candidate (guint i) const {
        return m_candidates[i];
    }

    const PhraseArray & candidate0 (void) const {
        return m_candidate_0_phrases;
    }

    gboolean candidateIsUserPhease (guint i) const {
        return m_candidates[i].user_freq > 0 && m_candidates[i].freq == 0;
    }

    void reset (void) {
        m_candidates.removeAll ();
        m_selected_phrases.removeAll ();
        m_selected_string.truncate (0);
        m_candidate_0_phrases.removeAll ();
        m_pinyin.removeAll ();
        m_cursor = 0;
    }

    gboolean modeSimp (void) const {
        return m_mode_simp;
    }

    void setModeSimp (gboolean mode) {
        m_mode_simp = mode;
    }

    void update (const PinyinArray &pinyin);
    gboolean selectCandidate (guint i);
    gboolean resetCandidate (guint i);
    void commit (void) {
        m_selected_phrases << m_candidate_0_phrases;
        m_database.commit (m_selected_phrases);
        reset ();
    }

    gboolean isEmpty (void) const {
        return m_selected_string.isEmpty () && m_candidate_0_phrases.isEmpty ();
    }

    operator gboolean (void) const {
        return !isEmpty ();
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
    gboolean m_mode_simp;

private:
    static Database m_database;
};

};

#endif
