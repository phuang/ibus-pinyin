#ifndef __PY_SIGNAL_H_
#define __PY_SIGNAL_H_

#include <boost/signals2.hpp>
#include <boost/bind.hpp>

namespace PY {

template <typename Signature>
class signal : public boost::signals2::signal_type <Signature, boost::signals2::keywords::mutex_type<boost::signals2::dummy_mutex> >::type {};
using boost::bind;

};

#endif
