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
#ifndef __PY_SIGNAL_H_
#define __PY_SIGNAL_H_

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#ifdef HAVE_BOOST_SIGNALS2_HPP
#  include <boost/signals2.hpp>
#elif HAVE_BOOST_SIGNALS_HPP
#  include <boost/signals.hpp>
#else
#  error "Can not find boost.signals2 or boost.signal"
#endif

#include <boost/bind.hpp>

namespace PY {

using boost::bind;

#if HAVE_BOOST_SIGNALS2_HPP
namespace bs2 = boost::signals2;
template <typename Signature>
struct signal : public bs2::signal_type <Signature, bs2::keywords::mutex_type<bs2::dummy_mutex> >::type { };
#elif HAVE_BOOST_SIGNALS_HPP
using boost::signal;
#endif

};

#endif
