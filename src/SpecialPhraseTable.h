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
#ifndef __PY_SPECIAL_PHRASE_TABLE_H_
#define __PY_SPECIAL_PHRASE_TABLE_H_

#include <map>
#include <string>
#include <vector>
#include <glib.h>
#include "SpecialPhrase.h"

namespace PY {

class SpecialPhraseTable {
private:
    SpecialPhraseTable (void);

public:
    gboolean lookup (const std::string &command, std::vector<std::string> &result);

private:
    gboolean load (const gchar *file);

public:
    static SpecialPhraseTable & instance (void) { return m_instance; }

private:
    typedef std::multimap<std::string, SpecialPhrasePtr> Map;
    Map m_map;

private:
    static SpecialPhraseTable m_instance;
};

};

#endif
