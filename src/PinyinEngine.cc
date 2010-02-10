/* vim:set et sts=4: */

#include <ibus.h>
#include <string.h>
#include <libintl.h>
#include "FullPinyinEditor.h"
#include "DoublePinyinEditor.h"
#include "PinyinEngine.h"
#include "HalfFullConverter.h"
#include "SimpTradConverter.h"
#include "Config.h"
#include "Text.h"
#include "Util.h"

#define _(text) (dgettext (GETTEXT_PACKAGE, text))

namespace PY {

/* constructor */
PinyinEngine::PinyinEngine (IBusEngine *engine)
    : m_engine (engine),
      m_need_update (0),
      m_quote (TRUE),
      m_double_quote (TRUE),
      m_prev_pressed_key (0),
      m_prev_pressed_key_result (0),
      m_prev_commited_char (0),
      m_input_mode (MODE_INIT)
{
    gint i;
    /* create editors */
    if (Config::doublePinyin ())
        m_editors[MODE_INIT] = new DoublePinyinEditor (m_props);
    else
        m_editors[MODE_INIT] = new FullPinyinEditor (m_props);

    for (i = MODE_RAW; i < MODE_LAST; i++) {
        m_editors[i] = new RawEditor (m_props);
    }

    m_props.signalUpdateProperty ().connect (sigc::mem_fun (*this, &PinyinEngine::slotUpdateProperty));

    for (i = MODE_INIT; i < MODE_LAST; i++) {
        connectEditorSignals (m_editors[i]);
    }
}

/* destructor */
PinyinEngine::~PinyinEngine (void)
{
    for (gint i = 0; i < MODE_LAST; i++) {
        delete m_editors[i];
    }
}

#define CMSHM_MASK              \
        (IBUS_CONTROL_MASK |    \
         IBUS_MOD1_MASK |       \
         IBUS_SUPER_MASK |      \
         IBUS_HYPER_MASK |      \
         IBUS_META_MASK)

#define CMSHM_FILTER(modifiers)  \
    (modifiers & (CMSHM_MASK))

inline gboolean
PinyinEngine::processPunct (guint keyval, guint keycode, guint modifiers)
{
    guint cmshm_modifiers = CMSHM_FILTER (modifiers);

    if (G_UNLIKELY (keyval == IBUS_period && cmshm_modifiers == IBUS_CONTROL_MASK)) {
        m_props.toggleModeFullPunct ();
        return TRUE;
    }

    /* check ctrl, alt, hyper, supper masks */
    if (cmshm_modifiers != 0)
        return FALSE;

    /* English mode */
    if (G_UNLIKELY (!m_props.modeChinese ())) {
        if (G_UNLIKELY (m_props.modeFull ()))
            commit (HalfFullConverter::toFull (keyval));
        else
            commit (keyval);
        return TRUE;
    }
    else {
        /* Chinese mode */
        if (m_props.modeFullPunct ()) {
            switch (keyval) {
            case '`':
                commit ("·"); return TRUE;
            case '~':
                commit ("～"); return TRUE;
            case '!':
                commit ("！"); return TRUE;
            // case '@':
            // case '#':
            case '$':
                commit ("￥"); return TRUE;
            // case '%':
            case '^':
                commit ("……"); return TRUE;
            // case '&':
            // case '*':
            case '(':
                commit ("（"); return TRUE;
            case ')':
                commit ("）"); return TRUE;
            // case '-':
            case '_':
                commit ("——"); return TRUE;
            // case '=':
            // case '+':
            case '[':
                commit ("【"); return TRUE;
            case ']':
                commit ("】"); return TRUE;
            case '{':
                commit ("『"); return TRUE;
            case '}':
                commit ("』"); return TRUE;
            case '\\':
                commit ("、"); return TRUE;
            // case '|':
            case ';':
                commit ("；"); return TRUE;
            case ':':
                commit ("："); return TRUE;
            case '\'':
                commit (m_quote ? "‘" : "’");
                m_quote = !m_quote;
                return TRUE;
            case '"':
                commit (m_double_quote ? "“" : "”");
                m_double_quote = !m_double_quote;
                return TRUE;
            case ',':
                commit ("，"); return TRUE;
            case '.':
                if (m_prev_commited_char >= '0' && m_prev_commited_char <= '9')
                    commit (keyval);
                else
                    commit ("。");
                return TRUE;
            case '<':
                commit ("《"); return TRUE;
            case '>':
                commit ("》"); return TRUE;
            // case '/':
            case '?':
                commit ("？"); return TRUE;
            }
        }
        commit (m_props.modeFull () ? HalfFullConverter::toFull (keyval) : keyval);
    }
    return TRUE;
}

gboolean
PinyinEngine::processKeyEvent (guint keyval, guint keycode, guint modifiers)
{
    gboolean retval;

    retval = m_editors[m_input_mode]->processKeyEvent (keyval, keycode, modifiers);

    if (retval == FALSE) {
        // ignore release event
        if (modifiers & IBUS_RELEASE_MASK) {
            if (m_prev_pressed_key != keyval || m_prev_pressed_key_result != FALSE)
                return TRUE;

            switch (keyval) {
            case IBUS_Shift_L:
            case IBUS_Shift_R:
                m_props.toggleModeChinese ();
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
                      IBUS_META_MASK);

        switch (keyval) {
            /* letters */
            case IBUS_a ... IBUS_z:
            case IBUS_A ... IBUS_Z:
            /* numbers */
            case IBUS_0 ... IBUS_9:
            case IBUS_KP_0 ... IBUS_KP_9:
                if (modifiers == 0) {
                    commit (m_props.modeFull () ? HalfFullConverter::toFull (keyval) : (gchar) keyval);
                    retval = TRUE;
                }
                break;
            /* punct */
            case IBUS_exclam ... IBUS_slash:
            case IBUS_colon ... IBUS_at:
            case IBUS_bracketleft ... IBUS_quoteleft:
            case IBUS_braceleft ... IBUS_asciitilde:
                retval = processPunct (keyval, keycode, modifiers);
                break;
            /* space */
            case IBUS_space:
                if (modifiers == 0) {
                    commit (m_props.modeFull () ? "　" : " ");
                    retval = TRUE;
                }
                break;
            /* others */
            default:
                break;
        }
    }

    m_prev_pressed_key = keyval;
    m_prev_pressed_key_result = retval;
    return retval;
}

void
PinyinEngine::focusIn (void)
{
    /* reset pinyin parser */
    if (Config::doublePinyin ()) {
        if (dynamic_cast <DoublePinyinEditor *> (m_editors[MODE_INIT]) == NULL)
            delete m_editors[MODE_INIT];
        m_editors[MODE_INIT] = new DoublePinyinEditor (m_props);
        connectEditorSignals (m_editors[MODE_INIT]);
    }
    else {
        if (dynamic_cast <FullPinyinEditor *> (m_editors[MODE_INIT]) == NULL)
            delete m_editors[MODE_INIT];
        m_editors[MODE_INIT] = new FullPinyinEditor (m_props);
        connectEditorSignals (m_editors[MODE_INIT]);
    }
    ibus_engine_register_properties (m_engine, m_props.properties ());
}


void
PinyinEngine::pageUp (void)
{
    m_editors[m_input_mode]->pageUp ();
}

void
PinyinEngine::pageDown (void)
{
    m_editors[m_input_mode]->pageDown ();
}

void
PinyinEngine::cursorUp (void)
{
    m_editors[m_input_mode]->cursorUp ();
}

void
PinyinEngine::cursorDown (void)
{
    m_editors[m_input_mode]->cursorDown ();
}

inline void
PinyinEngine::showSetupDialog (void)
{
    g_spawn_command_line_async (LIBEXECDIR"/ibus-setup-pinyin", NULL);
}

gboolean
PinyinEngine::propertyActivate (const gchar *prop_name, guint prop_state)
{
    const static StaticString setup ("setup");
    if (m_props.propertyActivate (prop_name, prop_state)) {
        return TRUE;
    }
    else if (setup == prop_name) {
        showSetupDialog ();
        return TRUE;
    }
    return FALSE;
}

void
PinyinEngine::candidateClicked (guint index, guint button, guint state)
{
    m_editors[m_input_mode]->candidateClicked (index, button, state);
}

inline void
PinyinEngine::commit (gchar ch)
{
    gchar str[2] = {ch, 0};
    ibus_engine_commit_text (m_engine, StaticText (str));
    m_prev_commited_char = ch;
}

inline void
PinyinEngine::commit (gunichar ch)
{
    ibus_engine_commit_text (m_engine, Text (ch));
    m_prev_commited_char = ch;
}

inline void
PinyinEngine::commit (const gchar *str)
{
    ibus_engine_commit_text (m_engine, StaticText (str));
    m_prev_commited_char = 0;
}

inline void
PinyinEngine::commit (const String &str)
{
    commit ((const gchar *)str);
}

void
PinyinEngine::slotCommitText (Text & text)
{
    ibus_engine_commit_text (m_engine, text);
}

void
PinyinEngine::slotUpdatePreeditText (Text & text, guint cursor, gboolean visible)
{
    ibus_engine_update_preedit_text (m_engine, text, cursor, visible);
}

void
PinyinEngine::slotShowPreeditText (void)
{
    ibus_engine_show_preedit_text (m_engine);
}

void
PinyinEngine::slotHidePreeditText (void)
{
    ibus_engine_hide_preedit_text (m_engine);
}

void
PinyinEngine::slotUpdateAuxiliaryText (Text & text, gboolean visible)
{
    ibus_engine_update_auxiliary_text (m_engine, text, visible);
}

void
PinyinEngine::slotShowAuxiliaryText (void)
{
    ibus_engine_show_auxiliary_text (m_engine);
}

void
PinyinEngine::slotHideAuxiliaryText (void)
{
    ibus_engine_hide_auxiliary_text (m_engine);
}

void
PinyinEngine::slotUpdateLookupTable (LookupTable & table, gboolean visible)
{
    ibus_engine_update_lookup_table (m_engine, table, visible);
}

void
PinyinEngine::slotUpdateLookupTableFast (LookupTable & table, gboolean visible)
{
    ibus_engine_update_lookup_table_fast (m_engine, table, visible);
}

void
PinyinEngine::slotShowLookupTable (void)
{
    ibus_engine_show_lookup_table (m_engine);
}

void
PinyinEngine::slotHideLookupTable (void)
{
    ibus_engine_hide_lookup_table (m_engine);
}

void
PinyinEngine::slotUpdateProperty (Property & prop)
{
    ibus_engine_update_property (m_engine, prop);
}

void
PinyinEngine::connectEditorSignals (Editor *editor)
{
    editor->signalCommitText ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotCommitText));

    editor->signalUpdatePreeditText ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotUpdatePreeditText));
    editor->signalShowPreeditText ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotShowPreeditText));
    editor->signalHidePreeditText ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotHidePreeditText));

    editor->signalUpdateAuxiliaryText ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotUpdateAuxiliaryText));
    editor->signalShowAuxiliaryText ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotShowAuxiliaryText));
    editor->signalHideAuxiliaryText ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotHideAuxiliaryText));

    editor->signalUpdateLookupTable ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotUpdateLookupTable));
    editor->signalUpdateLookupTableFast ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotUpdateLookupTableFast));
    editor->signalShowLookupTable ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotShowLookupTable));
    editor->signalHideLookupTable ().connect (
        sigc::mem_fun (*this, &PinyinEngine::slotHideLookupTable));

}

};

