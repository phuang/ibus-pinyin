#ifndef __PY_SIGNAL_H_
#define __PY_SIGNAL_H_

#include <boost/signals2.hpp>
#include <boost/bind.hpp>

namespace PY {

using boost::bind;

template <typename Signature>
struct signal : public boost::signals2::signal_type <Signature, boost::signals2::keywords::mutex_type<boost::signals2::dummy_mutex> >::type {
};

};

#endif
