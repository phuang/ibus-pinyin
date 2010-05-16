#include "PunctEditor.h"

namespace PY {

#include "PunctTable.h"

PunctEditor::PunctEditor (PinyinProperties & props)
    : Editor (props)
{
}

gboolean
PunctEditor::processKeyEvent (guint keyval, guint keycode, guint modifiers)
{
    return Editor::processKeyEvent (keyval, keycode, modifiers);
}

void
PunctEditor::pageUp (void)
{
    Editor::pageUp ();
}

void
PunctEditor::pageDown (void)
{
    Editor::pageDown ();
}

void
PunctEditor::cursorUp (void)
{
    Editor::cursorUp ();
}

void
PunctEditor::cursorDown (void)
{
    Editor::cursorDown ();
}

void
PunctEditor::update (void)
{
    Editor::update ();
}

void
PunctEditor::reset (void)
{
    Editor::reset ();
}

void
PunctEditor::candidateClicked (guint index, guint button, guint state)
{
    Editor::candidateClicked (index, button, state);
}

};


