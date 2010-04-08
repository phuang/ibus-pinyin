#include "Config.h"
#include "PhraseEditor.h"
#include "SimpTradConverter.h"

namespace PY {

Database PhraseEditor::m_database;

PhraseEditor::PhraseEditor (PinyinProperties & props)
    : m_candidates (32),
      m_selected_phrases (8),
      m_selected_string (32),
      m_candidate_0_phrases (8),
      m_pinyin (16),
      m_cursor (0),
      m_props (props),
      m_query (NULL)
{
}

PhraseEditor::~PhraseEditor (void)
{
    if (m_query)
        delete m_query;
}

gboolean
PhraseEditor::update (const PinyinArray &pinyin)
{
    /* the size of pinyin must not bigger than MAX_PHRASE_LEN */
    g_assert (pinyin.size () <= MAX_PHRASE_LEN);

    m_pinyin = pinyin;
    m_cursor = 0;

    /* FIXME, should not remove all phrases1 */
    m_selected_phrases.clear ();
    m_selected_string.truncate (0);
    updateCandidates ();
    return TRUE;
}

gboolean
PhraseEditor::resetCandidate (guint i)
{
    m_database.remove (m_candidates[i]);

    updateCandidates ();
    return TRUE;
}

gboolean
PhraseEditor::selectCandidate (guint i)
{
    if (G_UNLIKELY (i >= m_candidates.size ()))
        return FALSE;

    if (G_LIKELY (i == 0)) {
        m_selected_phrases.insert (m_selected_phrases.end (),
                                   m_candidate_0_phrases.begin (),
                                   m_candidate_0_phrases.end ());
        if (G_LIKELY (m_props.modeSimp ()))
            m_selected_string << m_candidates[0].phrase;
        else
            SimpTradConverter::simpToTrad (m_candidates[0].phrase, m_selected_string);
        m_cursor = m_pinyin.size ();
    }
    else {
        m_selected_phrases.push_back (m_candidates[i]);
        if (G_LIKELY (m_props.modeSimp ()))
            m_selected_string << m_candidates[i].phrase;
        else
            SimpTradConverter::simpToTrad (m_candidates[i].phrase, m_selected_string);
        m_cursor += m_candidates[i].len;
    }

    updateCandidates ();
    return TRUE;
}

void
PhraseEditor::updateCandidates (void)
{
    m_candidates.clear ();
    updateTheFirstCandidate ();
    if (m_query) {
        delete m_query;
        m_query = NULL;
    }

    if (G_UNLIKELY (m_pinyin.size () == 0))
        return;

    if (G_LIKELY (m_candidate_0_phrases.size () > 1)) {
        Phrase phrase;
        phrase.reset ();
        for (guint i = 0; i < m_candidate_0_phrases.size (); i++)
            phrase += m_candidate_0_phrases[i];
        m_candidates.push_back (phrase);
    }

    m_query = new Query (m_database,
                         m_pinyin,
                         m_cursor,
                         m_pinyin.size () - m_cursor,
                         Config::option ());
    fillCandidates ();
}

void
PhraseEditor::updateTheFirstCandidate (void)
{
    guint begin;
    guint end;

    m_candidate_0_phrases.clear ();

    if (G_UNLIKELY (m_pinyin.size () == 0))
        return;

    begin = m_cursor;
    end = m_pinyin.size ();

    while (begin != end) {
        gint ret;
        Query query (m_database,
                     m_pinyin,
                     begin,
                     end - begin,
                     Config::option ());
        ret = query.fill (m_candidate_0_phrases, 1);
        g_assert (ret == 1);
        begin += m_candidate_0_phrases.back ().len;
    }
}

};


