#ifndef __PY_POINTER_H_
#define __PY_POINTER_H_

#include <glib-object.h>

namespace PY {

template<typename T>
class Pointer {
public:
    Pointer (T *p = NULL) : m_p (NULL) {
        set (p);
    }

    ~Pointer (void) {
        set (NULL);
    }

    void set (T * p) {
        if (m_p) {
            g_object_unref (m_p);
        }

        m_p = p;
        if (p) {
            // g_debug ("%s, floating = %d",G_OBJECT_TYPE_NAME (p), g_object_is_floating (p));
            g_object_ref_sink (p);
        }
    }
    
    Pointer<T> &operator = (T *p) {
        set (p);
        return *this;
    }

    Pointer<T> &operator = (const Pointer<T> & p) {
        set (p.m_p);
        return *this;
    }

    operator T * (void) const {
        return m_p;
    }
    
    operator gboolean (void) const {
        return m_p != NULL;
    }

private:
    T *m_p;
};

};

#endif
