/* vim:set et ts=4 sts=4:
 *
 * ibus-pinyin - The Chinese PinYin engine for IBus
 *
 * Copyright (c) 2008-2010 Peng Huang <shawn.p.huang@gmail.com>
 * Copyright (c) 2010 BYVoid <byvoid1@gmail.com>
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
#ifndef __PY_BOPOMOFO_EDITOR_H_
#define __PY_BOPOMOFO_EDITOR_H_

#include "PinyinEditor.h"

namespace PY {

class BopomofoEditor : public PinyinEditor {

public:
    BopomofoEditor (PinyinProperties & props, Config & config = BopomofoConfig::instance ());
    ~BopomofoEditor (void);

public:
    /* virtual functions */
    virtual gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    virtual void reset (void);

protected:
    std::wstring bopomofo;
    gboolean m_select_mode;

    virtual void updatePinyin (void);
    virtual void updateAuxiliaryText (void);
    virtual void updatePreeditText (void);
    virtual void commit (void);

    gboolean insert (gint ch);

    gboolean removeCharBefore (void);
    gboolean removeCharAfter (void);
    gboolean removeWordBefore (void);
    gboolean removeWordAfter (void);

    gboolean moveCursorLeft (void);
    gboolean moveCursorRight (void);
    gboolean moveCursorLeftByWord (void);
    gboolean moveCursorRightByWord (void);
    gboolean moveCursorToBegin (void);
    gboolean moveCursorToEnd (void);

    gboolean processSpace (guint keyval, guint keycode, guint modifiers);
    gboolean processNumber (guint keyval, guint keycode, guint modifiers);
    gboolean processNumberWithShift (guint keyval, guint keycode, guint modifiers);
    gboolean processBopomofo (guint keyval, guint keycode, guint modifiers);
    gint keyvalToBopomofo(gint ch);


};

};

#endif
