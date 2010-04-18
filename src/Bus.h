#ifndef __PY_BUS_H_
#define __PY_BUS_H_

#include <ibus.h>
#include "Object.h"

namespace PY {

class Bus : Object {
public:
    Bus (void) : Object (ibus_bus_new ()) {
    }

    bool isConnected (void) {
        return ibus_bus_is_connected (*this);
    }

    operator IBusBus * (void) const {
        return get<IBusBus> ();
    }
};

};
#endif
