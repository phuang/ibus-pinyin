/* vim:set et sts=4: */

#include <ibus.h>
#include <string.h>
#include <libintl.h>
#include "FullPinyinEditor.h"
#include "DoublePinyinEditor.h"
#include "PinyinEngine.h"
#include "HalfFullConverter.h"
#include "Config.h"
#include "Text.h"
#include "Util.h"

#define _(text) (dgettext (GETTEXT_PACKAGE, text))

namespace PY {

/* constructor */
PinyinEngine::PinyinEngine (IBusEngine *engine)
    : m_engine (engine),
      m_pinyin_editor (NULL),
      m_need_update (0),
      m_lookup_table (Config::pageSize ()),
      m_mode_chinese (Config::initChinese ()),
      m_mode_full (Config::initFull ()),
      m_mode_full_punct (Config::initFullPunct ()),
      m_quote (TRUE),
      m_double_quote (TRUE),
      m_prev_pressed_key (0)
{
    /* */
    if (Config::doublePinyin ())
        m_pinyin_editor = new DoublePinyinEditor ();
    else
        m_pinyin_editor = new FullPinyinEditor ();

    /* create properties */
    m_prop_chinese = ibus_property_new ("mode.chinese",
                                        PROP_TYPE_NORMAL,
                                        Text ("CN"),
                                        m_mode_chinese ?
                                            PKGDATADIR"/icons/chinese.svg" :
                                            PKGDATADIR"/icons/english.svg",
                                        Text (_("Chinese")),
                                        TRUE,
                                        TRUE,
                                        PROP_STATE_UNCHECKED,
                                        NULL);
    m_props.append (m_prop_chinese);

    m_prop_full = ibus_property_new ("mode.full",
                                     PROP_TYPE_NORMAL,
                                     Text (m_mode_full? "Ａａ" : "Aa"),
                                     m_mode_full ?
                                        PKGDATADIR"/icons/full.svg" :
                                        PKGDATADIR"/icons/half.svg",
                                     Text (_("Full/Half width")),
                                     TRUE,
                                     TRUE,
                                     PROP_STATE_UNCHECKED,
                                     NULL);
    m_props.append (m_prop_full);

    m_prop_full_punct = ibus_property_new ("mode.full_punct",
                                           PROP_TYPE_NORMAL,
                                           Text (m_mode_full_punct ? "，。" : ",."),
                                           m_mode_full_punct ?
                                           PKGDATADIR"/icons/full-punct.svg" :
                                                PKGDATADIR"/icons/half-punct.svg",
                                           Text (_("Full/Half width punctuation")),
                                           TRUE,
                                           TRUE,
                                           PROP_STATE_UNCHECKED,
                                           NULL);
    m_props.append (m_prop_full_punct);

    m_prop_setup = ibus_property_new ("setup",
                                      PROP_TYPE_NORMAL,
                                      Text (_("Pinyin preferences")),
                                      "gtk-preferences",
                                      Text (_("Pinyin preferences")),
                                      TRUE,
                                      TRUE,
                                      PROP_STATE_UNCHECKED,
                                      NULL);
    m_props.append (m_prop_setup);

}

/* destructor */
PinyinEngine::~PinyinEngine (void)
{
    delete m_pinyin_editor;
}

#define MASK_FILTER(modifiers)          \
    (modifiers & (IBUS_CONTROL_MASK |   \
                  IBUS_MOD1_MASK |      \
                  IBUS_SUPER_MASK |     \
                  IBUS_HYPER_MASK |     \
                  IBUS_META_MASK))

/**
 * process ascii letter
 */
inline gboolean
PinyinEngine::processPinyin (guint keyval, guint keycode, guint modifiers)
{
    if (G_UNLIKELY (MASK_FILTER(modifiers) != 0))
        return FALSE;

    if (G_UNLIKELY (m_mode_chinese == FALSE)) {
        if (G_LIKELY (m_mode_full))
            commit (HalfFullConverter::toFull (keyval));
        else
            commit ((gchar) keyval);
        return TRUE;
    }

    if (m_pinyin_editor->insert (keyval))
        update (FALSE);
    return TRUE;
}

inline gboolean
PinyinEngine::processNumber (guint keyval, guint keycode, guint modifiers)
{
    /* English mode */
    if (G_UNLIKELY (!m_mode_chinese)) {
        commit ((gunichar) m_mode_full ? HalfFullConverter::toFull (keyval) : keyval);
        return TRUE;
    }

    /* Chinese mode, if empty */
    if (G_UNLIKELY (m_pinyin_editor->isEmpty ())) {
        if (G_UNLIKELY (MASK_FILTER (modifiers) != 0))
            return FALSE;
        commit ((gunichar) m_mode_full ? HalfFullConverter::toFull (keyval) : keyval);
        return TRUE;
    }

    /* Chinese mode, if has candidates */
    guint i;
    if (G_UNLIKELY (keyval == IBUS_0))
        i = 10;
    else
        i = keyval - IBUS_1;

    if (modifiers == 0)
        selectCandidate (i);
    else if ((modifiers & ~ IBUS_LOCK_MASK) == IBUS_CONTROL_MASK)
        resetCandidate (i);
    return TRUE;
}

inline gboolean
PinyinEngine::processPunct (guint keyval, guint keycode, guint modifiers)
{
    if (G_UNLIKELY (MASK_FILTER(modifiers) != 0))
        return FALSE;

    /* English mode */
    if (G_UNLIKELY (!m_mode_chinese)) {
        if (G_UNLIKELY (m_mode_full))
            commit (HalfFullConverter::toFull (keyval));
        else
            commit (keyval);
        return TRUE;
    }

    /* Chinese mode */
    if (G_UNLIKELY (isEmpty ())) {
        if (m_mode_full_punct) {
            switch (keyval) {
            case '.':
                commit ("。"); break;
            case '\\':
                commit ("、"); break;
            case '^':
                commit ("……"); break;
            case '_':
                commit ("——"); break;
            case '$':
                commit ("￥"); break;
            case '<':
                commit ("《"); break;
            case '>':
                commit ("》"); break;
            case '"':
                commit (m_double_quote ? "“" : "”");
                m_double_quote = !m_double_quote;
                break;
            case '\'':
                commit (m_quote ? "‘" : "’");
                m_quote = !m_quote;
                break;
            default:
                commit (HalfFullConverter::toFull (keyval));
                break;
            }
        }
        else {
            commit (keyval);
        }
        return TRUE;
    }

    switch (keyval) {
    case IBUS_space:
        commit (); return TRUE;
    case IBUS_apostrophe:
        return processPinyin (keyval, keycode, modifiers);
    case IBUS_comma:
        if (Config::commaPeriodPage ())
            pageUp ();
        return TRUE;
    case IBUS_minus:
        if (Config::minusEqualPage ())
            pageUp ();
        return TRUE;
    case IBUS_period:
        if (Config::commaPeriodPage ())
            pageDown ();
        return TRUE;
    case IBUS_equal:
        if (Config::minusEqualPage ())
            pageDown ();
        return TRUE;
    case IBUS_semicolon:
        /* double pinyin need process ';' */
        if (G_UNLIKELY (Config::doublePinyin ()))
            return processPinyin (keyval, keycode, modifiers);
        return TRUE;
    default:
        return TRUE;
    }
}

inline gboolean
PinyinEngine::processOthers (guint keyval, guint keycode, guint modifiers)
{
    if (G_UNLIKELY (isEmpty ()))
        return FALSE;

    /* process some cursor control keys */
    gboolean _update = FALSE;
    switch (keyval) {
    case IBUS_Return:
        if (G_UNLIKELY (m_mode_full)) {
            m_buffer.truncate (0);
            for (const gchar *p = m_pinyin_editor->text (); *p != 0; p++) {
                m_buffer.appendUnichar (HalfFullConverter::toFull (*p));
            }
            commit (m_buffer);
        }
        else {
            commit (m_pinyin_editor->text ());
        }
        m_pinyin_editor->reset ();
        _update = TRUE;
        break;

    case IBUS_BackSpace:
        if (G_LIKELY (modifiers == 0))
            _update = m_pinyin_editor->removeCharBefore ();
        else if (G_LIKELY (modifiers == IBUS_CONTROL_MASK))
            _update = m_pinyin_editor->removeWordBefore ();
        break;

    case IBUS_Delete:
        if (G_LIKELY (modifiers == 0))
            _update = m_pinyin_editor->removeCharAfter ();
        else if (G_LIKELY (modifiers == IBUS_CONTROL_MASK))
            _update = m_pinyin_editor->removeWordAfter ();
        break;

    case IBUS_Left:
        if (G_LIKELY (modifiers == 0)) {
            // move left single char
            _update = m_pinyin_editor->moveCursorLeft ();
        }
        else if (G_LIKELY (modifiers == IBUS_CONTROL_MASK)) {
            // move left one pinyin
            _update = m_pinyin_editor->moveCursorLeftByWord ();
        }
        break;

    case IBUS_Right:
        if (G_LIKELY (modifiers == 0)) {
            // move right single char
            _update = m_pinyin_editor->moveCursorRight ();
        }
        else if (G_LIKELY (modifiers == IBUS_CONTROL_MASK)) {
            // move right to end
            _update = m_pinyin_editor->moveCursorToEnd ();
        }
        break;

    case IBUS_Home:
        if (G_LIKELY (modifiers == 0)) {
            // move to begin
            _update = m_pinyin_editor->moveCursorToBegin ();
        }
        break;

    case IBUS_End:
        if (G_LIKELY (modifiers == 0)) {
            // move to end
            _update = m_pinyin_editor->moveCursorToEnd ();
        }
        break;

    case IBUS_Up:
        cursorUp (); break;
    case IBUS_Down:
        cursorDown (); break;
    case IBUS_Page_Up:
        pageUp (); break;
    case IBUS_Page_Down:
        pageDown (); break;
    case IBUS_Escape:
        reset (); break;
    }
    if (G_LIKELY (_update))
        update (FALSE);
    return TRUE;
}

gboolean
PinyinEngine::processKeyEvent (guint keyval, guint keycode, guint modifiers)
{
    gboolean retval = FALSE;

    // ignore release event
    if (modifiers & IBUS_RELEASE_MASK) {
        if (m_prev_pressed_key != keyval)
            return TRUE;

        switch (keyval) {
        case IBUS_Shift_L:
        case IBUS_Shift_R:
            if (isEmpty ())
                toggleModeChinese ();
            return TRUE;
        default:
            return TRUE;
        }
    }

    modifiers &= (IBUS_SHIFT_MASK |
                  IBUS_CONTROL_MASK |
                  IBUS_MOD1_MASK |
                  IBUS_SUPER_MASK |
                  IBUS_HYPER_MASK |
                  IBUS_META_MASK |
                  IBUS_LOCK_MASK);

    switch (keyval) {
    /* letters */
    case IBUS_a ... IBUS_z:
    case IBUS_A ... IBUS_Z:
        retval = processPinyin (keyval, keycode, modifiers);
        break;
    /* numbers */
    case IBUS_0 ... IBUS_9:
        retval = processNumber (keyval, keycode, modifiers);
        break;
    /* punct */
    case IBUS_space ... IBUS_slash:
    case IBUS_colon ... IBUS_at:
    case IBUS_bracketleft ... IBUS_quoteleft:
    case IBUS_braceleft ... IBUS_asciitilde:
        retval = processPunct (keyval, keycode, modifiers);
        break;
    /* others */
    default:
        retval = processOthers (keyval, keycode, modifiers);
        break;
    }

    m_prev_pressed_key = keyval;
    return retval;
}

void
PinyinEngine::focusIn (void)
{
    if (Config::doublePinyin ()) {
        if (dynamic_cast <DoublePinyinEditor *> (m_pinyin_editor) == NULL)
            delete m_pinyin_editor;
        m_pinyin_editor = new DoublePinyinEditor ();
    }
    else {
        if (dynamic_cast <FullPinyinEditor *> (m_pinyin_editor) == NULL)
            delete m_pinyin_editor;
        m_pinyin_editor = new FullPinyinEditor ();
    }

    resetQuote ();
    ibus_engine_register_properties (m_engine, m_props);
}


void
PinyinEngine::pageUp (void)
{
    if (m_lookup_table.pageUp ()) {
        ibus_engine_update_lookup_table_fast (m_engine, m_lookup_table, TRUE);
    }
}

void
PinyinEngine::pageDown (void)
{
    if (m_lookup_table.pageDown ()) {
        ibus_engine_update_lookup_table_fast (m_engine, m_lookup_table, TRUE);
    }
}

void
PinyinEngine::cursorUp (void)
{
    if (m_lookup_table.cursorUp ()) {
        ibus_engine_update_lookup_table_fast (m_engine, m_lookup_table, TRUE);
    }
}

void
PinyinEngine::cursorDown (void)
{
    if (m_lookup_table.cursorDown ()) {
        ibus_engine_update_lookup_table_fast (m_engine, m_lookup_table, TRUE);
    }
}

inline void
PinyinEngine::toggleModeChinese (void)
{
    m_mode_chinese = ! m_mode_chinese;
    m_prop_chinese.setLabel (m_mode_chinese ? "CN" : "EN");
    m_prop_chinese.setIcon (m_mode_chinese ?
                                PKGDATADIR"/icons/chinese.svg" :
                                PKGDATADIR"/icons/english.svg");
    ibus_engine_update_property (m_engine, m_prop_chinese);

    m_prop_full_punct.setSensitive (m_mode_chinese);
    ibus_engine_update_property (m_engine, m_prop_full_punct);
}

inline void
PinyinEngine::toggleModeFull (void)
{
    m_mode_full = !m_mode_full;
    m_prop_full.setLabel (m_mode_full ? "Ａａ" : "Aa");
    m_prop_full.setIcon (m_mode_full ?
                            PKGDATADIR"/icons/full.svg" :
                            PKGDATADIR"/icons/half.svg");
    ibus_engine_update_property (m_engine, m_prop_full);
}

inline void
PinyinEngine::toggleModeFullPunct (void)
{
    m_mode_full_punct = !m_mode_full_punct;
    m_prop_full_punct.setLabel (m_mode_full_punct ? "，。" : ",.");
    m_prop_full_punct.setIcon (m_mode_full_punct ?
                                    PKGDATADIR"/icons/full-punct.svg" :
                                    PKGDATADIR"/icons/half-punct.svg");
    ibus_engine_update_property (m_engine, m_prop_full_punct);
}

inline void
PinyinEngine::showSetupDialog (void)
{
    g_spawn_command_line_async (LIBEXECDIR"/ibus-setup-pinyin", NULL);
}

void
PinyinEngine::propertyActivate (const gchar *prop_name, guint prop_state)
{
    const static StaticString mode_chinese ("mode.chinese");
    const static StaticString mode_full ("mode.full");
    const static StaticString mode_full_punct ("mode.full_punct");
    const static StaticString setup ("setup");

    if (mode_chinese == prop_name) {
        toggleModeChinese ();
    }
    else if (mode_full == prop_name) {
        toggleModeFull ();
    }
    else if (mode_full_punct == prop_name) {
        toggleModeFullPunct ();
    }
    else if (setup == prop_name) {
        showSetupDialog ();
    }
}

void
PinyinEngine::updatePreeditText (void)
{
    if (G_UNLIKELY (m_phrase_editor.isEmpty () && m_pinyin_editor->isEmpty ())) {
        ibus_engine_hide_preedit_text (m_engine);
        return;
    }

    m_buffer.truncate (0);
    if (G_UNLIKELY (m_phrase_editor.string1 ()))
        m_buffer << m_phrase_editor.string1 () << ' ';

    m_buffer << m_phrase_editor.string2 ()
             << m_pinyin_editor->textAfterPinyin ();

    Text preedit_text (m_buffer);
    preedit_text.appendAttribute (IBUS_ATTR_TYPE_UNDERLINE, IBUS_ATTR_UNDERLINE_SINGLE, 0, -1);
    ibus_engine_update_preedit_text (m_engine, preedit_text, m_buffer.length (), TRUE);
}

void
PinyinEngine::updateAuxiliaryText (void)
{

    /* clear pinyin array */
    if (G_UNLIKELY (isEmpty ())) {
        ibus_engine_hide_auxiliary_text (m_engine);
        return;
    }

    guint cursor_pos;

    m_buffer.truncate (0);
    if (G_UNLIKELY (m_phrase_editor.string1 ())) {
        m_buffer << m_phrase_editor.string1 ();
    }

    for (guint i = m_phrase_editor.cursor (); i < m_pinyin_editor->pinyin().length (); ++i) {
        if (G_LIKELY (i != m_phrase_editor.cursor ()))
            m_buffer << '\'';
        const Pinyin *p = m_pinyin_editor->pinyin()[i];
        m_buffer << p->sheng;
        m_buffer << p->yun;
    }

    if (G_UNLIKELY (m_pinyin_editor->pinyinLength () == m_pinyin_editor->cursor ())) {
        /* aux = pinyin + non-pinyin */
        cursor_pos =  m_buffer.utf8Length ();
        m_buffer << '|' << m_pinyin_editor->textAfterPinyin ();
    }
    else {
        /* aux = pinyin + non-pinyin before cursor + non-pinyin after cursor */
        m_buffer.append (m_pinyin_editor->textAfterPinyin (),
                     m_pinyin_editor->cursor () - m_pinyin_editor->pinyinLength ());
        cursor_pos =  m_buffer.utf8Length ();
        m_buffer  << '|' << m_pinyin_editor->textAfterCursor ();
    }

    Text aux_text (m_buffer);
    /*
    aux_text.appendAttribute (IBUS_ATTR_TYPE_FOREGROUND, 0x00afafaf, len, cursor_pos);
    aux_text.appendAttribute (IBUS_ATTR_TYPE_FOREGROUND, 0x00afafaf, cursor_pos + 1, -1);
    */
    ibus_engine_update_auxiliary_text (m_engine, aux_text, TRUE);
}

void
PinyinEngine::updateLookupTable (void)
{
    m_lookup_table.clear ();
    m_lookup_table.setPageSize (Config::pageSize ());

    guint candidate_nr = m_phrase_editor.candidateNumber ();

    if (G_UNLIKELY (candidate_nr == 0)) {
        ibus_engine_hide_lookup_table (m_engine);
        return;
    }

    for (guint i = 0; i < candidate_nr; i++) {
        //const Phrase &phrase = m_phrase_editor.candidates()[i];
        Text text (m_phrase_editor.candidate (i));
        if (m_phrase_editor.candidateInUserPhease (i))
            text.appendAttribute (IBUS_ATTR_TYPE_FOREGROUND, 0x000000ef, 0, -1);
        m_lookup_table.appendCandidate (text);
    }

    ibus_engine_update_lookup_table_fast (m_engine,
                                          m_lookup_table,
                                          TRUE);
}

void
PinyinEngine::updatePhraseEditor (void)
{
    m_phrase_editor.update (m_pinyin_editor->pinyin ());
}

inline void
PinyinEngine::commit (gchar ch)
{
    gchar str[2] = {ch, 0};
    ibus_engine_commit_text (m_engine, Text (str));
}

inline void
PinyinEngine::commit (gunichar ch)
{
    ibus_engine_commit_text (m_engine, Text (ch));
}

inline void
PinyinEngine::commit (const gchar *str)
{
    ibus_engine_commit_text (m_engine, Text (str));
}

inline void
PinyinEngine::commit (const String &str)
{
    commit ((const gchar *)str);
}

inline void
PinyinEngine::commit (void)
{
    if (G_UNLIKELY (m_pinyin_editor->isEmpty ()))
        return;

    m_buffer.truncate (0);
    m_buffer << m_phrase_editor.string1 () << m_phrase_editor.string2 ();
    const gchar *p = m_pinyin_editor->textAfterPinyin ();
    if (G_UNLIKELY (m_mode_full)) {
        while (*p != 0)
            m_buffer.appendUnichar (HalfFullConverter::toFull (*p++));
    }
    else {
        m_buffer << p;
    }
    commit ((const gchar *)m_buffer);
    m_phrase_editor.commit ();
    reset ();
}

inline gboolean
PinyinEngine::selectCandidate (guint i)
{
    guint page_size = m_lookup_table.pageSize ();
    guint cursor_pos = m_lookup_table.cursorPos ();
    i += (cursor_pos / page_size) * page_size;

    if (m_phrase_editor.selectCandidate (i)) {
        if (G_UNLIKELY (m_phrase_editor.cursor () == m_pinyin_editor->pinyin ().length ())) {
            commit ();
        }
        else {
            updatePreeditText ();
            updateAuxiliaryText ();
            updateLookupTable ();
        }
    }
    return TRUE;
}

inline gboolean
PinyinEngine::resetCandidate (guint i)
{
    guint page_size = m_lookup_table.pageSize ();
    guint cursor_pos = m_lookup_table.cursorPos ();
    i += (cursor_pos / page_size) * page_size;

    if (m_phrase_editor.resetCandidate (i)) {
        updatePreeditText ();
        updateAuxiliaryText ();
        updateLookupTable ();
    }
    return TRUE;
}

};

