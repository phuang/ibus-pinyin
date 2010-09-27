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
#  include <config.h>
#endif

#ifdef __GXX_EXPERIMENTAL_CXX0X__

#  include <functional>

namespace PY {

using namespace std::placeholders;

// implement signal templates
template<typename R  = void,
         typename T1 = void,
         typename T2 = void,
         typename T3 = void>
struct signal
{
};

template<typename R, typename T1, typename T2, typename T3>
struct signal< R(), T1, T2, T3>
{
    typedef std::function<R()> func_type;
    void connect (func_type f) { m_func = f; }
    R operator ()() const { m_func (); }
private:
    func_type m_func;
};

template<typename R, typename T1, typename T2, typename T3>
struct signal< R(T1), T2, T3>
{
    typedef std::function<R(T1)> func_type;
    void connect (func_type f) { m_func = f; }
    R operator ()(T1 a1) const { return m_func (a1); }
private:
    func_type m_func;
};

template<typename R, typename T1, typename T2, typename T3>
struct signal< R(T1, T2), T3>
{
    typedef std::function<R(T1, T2)> func_type;
    void connect (func_type f) { m_func = f; }
    R operator ()(T1 a1, T2 a2) const { return m_func (a1, a2); }
private:
    func_type m_func;
};

template<typename R, typename T1, typename T2, typename T3>
struct signal< R(T1, T2, T3)>
{
    typedef std::function<R(T1, T2, T3)> func_type;
    void connect (func_type f) {m_func = f; }
    R operator ()(T1 a1, T2 a2, T3 a3) const { return m_func (a1, a2, a3); }
private:
    func_type m_func;
};

};

#else // __GXX_EXPERIMENTAL_CXX0X__

#  include <boost/signals2.hpp>
#  include <boost/bind.hpp>

namespace std {
    // import boost::bind into std namespace
    using boost::bind;
};

namespace PY {
    // use boost::signal2
    namespace bs2 = boost::signals2;
    template <typename Signature>
    struct signal : public bs2::signal_type
        <Signature, bs2::keywords::mutex_type<bs2::dummy_mutex> >::type { };

};

#endif // __GXX_EXPERIMENTAL_CXX0X__
#endif // __PY_SIGNAL_H_

