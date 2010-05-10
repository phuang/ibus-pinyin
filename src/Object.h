#ifndef __PY_OBJECT_H_
#define __PY_OBJECT_H_

#include <glib-object.h>
#include "Pointer.h"

namespace PY {

class Object {
protected:
    template <typename T>
    Object (T *p) : m_p ((GObject *)p) {
        g_assert (get <GObject *>() != NULL);
    }

    operator GObject * (void) const {
        return m_p;
    }

    template <typename T>
    T * get (void) const {
        return (T *) (GObject *) m_p;
    }

private:
    Pointer<GObject> m_p;
};

};

#endif
