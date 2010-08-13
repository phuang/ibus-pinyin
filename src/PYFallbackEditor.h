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
#ifndef __PY_FALLBACK_EDITOR_
#define __PY_FALLBACK_EDITOR_

#include "PYText.h"
#include "PYEditor.h"

namespace PY {

class FallbackEditor : public Editor {
public:
    FallbackEditor (PinyinProperties &props, Config & config)
        : Editor (props, config),
          m_quote (TRUE),
          m_double_quote (TRUE),
          m_prev_committed_char (0) { }

    gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    void reset (void);

    void setPrevCommittedChar (gunichar ch)
    {
        m_prev_committed_char = ch;
    }

private:
    void commit (gchar ch)
    {
        gchar str[2] = {ch, 0};
        StaticText text (str);
        commitText (text);
    }

    void commit (gunichar ch)
    {
        Text text (ch);
        commitText (text);
    }

    void commit (const gchar *str)
    {
        StaticText text (str);
        commitText (text);
    }

    void commit (const String &str)
    {
        commit ((const gchar *)str);
    }

    gboolean processPunct (guint keyval, guint keycode, guint modifiers);
    gboolean processPunctForSimplifiedChinese (guint keyval, guint keycode, guint modifiers);
    gboolean processPunctForTraditionalChinese (guint keyval, guint keycode, guint modifiers);

private:
    gboolean m_quote;
    gboolean m_double_quote;
    gunichar m_prev_committed_char;
    
};

};
#endif
