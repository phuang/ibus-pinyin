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
      m_props (props)
{
}

PhraseEditor::~PhraseEditor (void)
{
}

gboolean
PhraseEditor::update (const PinyinArray &pinyin)
{
    /* the length of pinyin must not bigger than MAX_PHRASE_LEN */
    g_assert (pinyin.length () <= MAX_PHRASE_LEN);

    m_pinyin = pinyin;
    m_cursor = 0;

    /* FIXME, should not remove all phrases1 */
    m_selected_phrases.removeAll ();
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
    if (G_UNLIKELY (i >= m_candidates.length ()))
        return FALSE;

    if (G_LIKELY (i == 0)) {
        m_selected_phrases << m_candidate_0_phrases;
        if (G_LIKELY (m_props.modeSimp ()))
            m_selected_string << m_candidates[0].phrase;
        else
            SimpTradConverter::simpToTrad (m_candidates[0].phrase, m_selected_string);
        m_cursor = m_pinyin.length ();
    }
    else {
        m_selected_phrases << m_candidates[i];
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
    gboolean retval;

    m_candidates.removeAll ();
    updateTheFirstCandidate ();

    if (G_UNLIKELY (m_pinyin.length () == 0))
        return;

    if (G_LIKELY (m_candidate_0_phrases.length () > 1)) {
        m_candidates.resize (1);
        m_candidates[0].reset ();
        for (guint i = 0; i < m_candidate_0_phrases.length (); i++)
            m_candidates[0] += m_candidate_0_phrases[i];
    }

    {
        Query query (m_database,
                     m_pinyin,
                     m_cursor, 
                     m_pinyin.length () - m_cursor,
                     Config::option ());
        query.fill (m_candidates, -1);
    }
}

void
PhraseEditor::updateTheFirstCandidate (void)
{
    guint begin;
    guint end;
    gboolean retval;

    m_candidate_0_phrases.removeAll ();

    if (G_UNLIKELY (m_pinyin.length () == 0))
        return;

    begin = m_cursor;
    end = m_pinyin.length ();

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
    g_debug ("is me");
}

};


