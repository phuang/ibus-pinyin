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
#ifndef __PY_PINYIN_EDITOR_H_
#define __PY_PINYIN_EDITOR_H_

#include "PhoneticEditor.h"

namespace PY {

#define MAX_PINYIN_LEN 64

class SpecialPhraseTable;

class PinyinEditor : public PhoneticEditor {
public:
    PinyinEditor (PinyinProperties & props);

protected:
    gboolean processPinyin (guint keyval, guint keycode, guint modifiers);
    gboolean processNumber (guint keyval, guint keycode, guint modifiers);
    gboolean processPunct (guint keyval, guint keycode, guint modifiers);
    gboolean processFunctionKey (guint keyval, guint keycode, guint modifiers);

    void commit ();

    void updateAuxiliaryText (void);
    void updateLookupTable (void);
    void updatePreeditText (void);

    virtual gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    virtual void updateAuxiliaryTextBefore (String &buffer) {};
    virtual void updateAuxiliaryTextAfter  (String &buffer) {};
};

};

#endif
