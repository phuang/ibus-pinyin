#ifndef __PY_PHRASE_EDITOR_H_
#define __PY_PHRASE_EDITOR_H_

#include "Database.h"
#include "PhraseArray.h"

namespace PY {

class PhraseEditor {
public:
    PhraseEditor(void);
    ~PhraseEditor(void);

    const String & string1 (void) const { return m_string1; }
    const String & string2 (void) const { return m_string2; }
    const PinyinArray & pinyin (void) const { return m_pinyin; }
    const PhraseArray & candidates (void) const { return m_candidates; }
    guint cursor (void) const { return m_cursor; }

    guint candidateNumber (void) const {
        if (m_phrases2.length () > 1)
            return m_candidates.length () + 1;
        return m_candidates.length ();
    }

    const gchar * candidate (guint i) const {
        if (G_UNLIKELY (i == 0))
            return m_string2;
        if (G_UNLIKELY (m_phrases2.length () > 1))
            return m_candidates[i - 1].phrase;
        return m_candidates[i].phrase;
    }

    gboolean candidateInUserPhease (guint i) const {
        if (G_UNLIKELY (m_phrases2.length () > 1)) {
            if (G_UNLIKELY (i == 0))
                return FALSE;
            else
                return m_candidates[i - 1].user_freq > 0 && m_candidates[i - 1].freq == 0;
        }
        else {
            return m_candidates[i].user_freq > 0 && m_candidates[i].freq == 0;
        }
    }

    void reset (void) {
        m_candidates.removeAll ();
        m_phrases1.removeAll ();
        m_string1.truncate (0);
        m_phrases2.removeAll ();
        m_string2.truncate (0);
        m_pinyin.removeAll ();
        m_cursor = 0;
    }

    void update (const PinyinArray &pinyin);
    gboolean selectCandidate (guint i);
    gboolean resetCandidate (guint i);
    void commit (void) {
        m_phrases1 << m_phrases2;
        m_database.commit (m_phrases1);
        reset ();
    }

    gboolean isEmpty (void) const {
        return m_string1.isEmpty () && m_string2.isEmpty ();
    }

    operator gboolean (void) const {
        return !isEmpty ();
    }

private:
    void updateCandidates (void);
    void updatePhrases (void);

private:
    PhraseArray m_candidates;   // candidates phrase array
    PhraseArray m_phrases1;     // phrases before cursor
    String      m_string1;      // phrases before cursor as string
    PhraseArray m_phrases2;     // phrases after cursor
    String      m_string2;      // phrases before cursor as string
    PinyinArray m_pinyin;
    guint m_cursor;

private:
    static Database m_database;
};

};

#endif
