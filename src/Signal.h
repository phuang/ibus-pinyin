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
template <typename Signature>
struct signal : public boost::signals2::signal_type <Signature, boost::signals2::keywords::mutex_type<boost::signals2::dummy_mutex> >::type {
    };
#elif HAVE_BOOST_SIGNALS_HPP
using boost::signal;
#endif

};

#endif
