#include "Config.h"
#include "PhraseEditor.h"

namespace PY {

/* init static members */
Database PhraseEditor::m_database;

PhraseEditor::PhraseEditor (void)
    : m_candidates (32),
      m_phrases1 (8),
      m_string1 (32),
      m_phrases2 (8),
      m_string2 (32),
      m_pinyin (16),
      m_cursor (0)
{
}

PhraseEditor::~PhraseEditor (void)
{
}

void
PhraseEditor::update (const PinyinArray &pinyin)
{
    gboolean diff = FALSE;

    if (m_cursor > pinyin.length ()) {
        diff = TRUE;
    }
    else {
        for (gint i = m_cursor - 1; i >= 0; i--) {
            if (m_pinyin[i] != pinyin[i]) {
                diff = TRUE;
                break;
            }
        }
    }

    m_pinyin = pinyin;

    if (diff) {
        /* FIXME, should not remove all phrases1 */
        m_phrases1.removeAll ();
        m_string1.truncate (0);
        m_cursor = 0;
    }

    updateCandidates ();
    updatePhrases ();
}

gboolean
PhraseEditor::resetCandidate (guint i)
{
    if (G_UNLIKELY (i >= m_candidates.length ()))
        return FALSE;

    if (G_UNLIKELY (i == 0 && m_phrases2.length () > 1))
        return FALSE;

    m_database.remove (m_candidates[i]);

    updateCandidates ();
    updatePhrases ();
    return TRUE;
}

gboolean
PhraseEditor::selectCandidate (guint i)
{
    if (G_LIKELY (i == 0)) {
        m_phrases1 << m_phrases2;
        m_string1 << m_string2;
        m_cursor = m_pinyin.length ();
    }
    else {
        if (m_phrases2.length() > 1)
            i --;

        if (G_UNLIKELY (i >= m_candidates.length ()))
            return FALSE;

        m_phrases1 << m_candidates[i];
        m_string1 << m_candidates[i].phrase;
        m_cursor += m_candidates[i].len;
    }

    updateCandidates ();
    updatePhrases ();
    return TRUE;
}

void
PhraseEditor::updateCandidates (void)
{
    gboolean retval;
    m_candidates.removeAll ();

    guint len = MIN (MAX_PHRASE_LEN, m_pinyin.length () - m_cursor);
    for (; len > 0; len--) {
        retval = m_database.query (m_pinyin,
                                   m_cursor,
                                   len,
                                   -1,
                                   Config::option (),
                                   m_candidates);
    }
}

void
PhraseEditor::updatePhrases (void)
{
    guint begin;
    guint end;
    gboolean retval;

    m_phrases2.removeAll ();
    m_string2.truncate (0);

    if (G_UNLIKELY (m_pinyin.length () == 0))
        return;

    if (G_LIKELY (m_cursor < m_pinyin.length ())) {
        m_phrases2 << m_candidates[0];

        begin = m_phrases2[0].len + m_cursor;
        end = m_pinyin.length ();

        while (begin != end) {
            for (guint i = MIN (end, begin + MAX_PHRASE_LEN); i > begin; i--) {
                retval = m_database.query (m_pinyin,
                                           begin,
                                           i - begin,
                                           1,
                                           Config::option (),
                                           m_phrases2);
                if (G_LIKELY (retval > 0)) {
                    begin += m_phrases2[m_phrases2.length () - 1].len;
                    break;
                }
            }
            if (retval <= 0)
                g_debug ("%s", m_pinyin[begin]->text);
            g_assert (retval > 0);
        }
    }

    for (guint i = 0; i < m_phrases2.length (); i++) {
        m_string2 << m_phrases2[i].phrase;
    }
}

};


