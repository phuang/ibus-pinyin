#ifndef __PY_BUS_H_
#define __PY_BUS_H_

#include <ibus.h>
#include "Pointer.h"

namespace PY {

class Bus : public Pointer <IBusBus> {
public:
    Bus (void) {
        set (ibus_bus_new ());
    }

    bool isConnected (void) {
        return ibus_bus_is_connected (*this);
    }
};

};
#endif
