#ifndef __PY_ARRAY_H_
#define __PY_ARRAY_H_

#include <vector>

namespace PY {

template<typename T>
class Array : public std::vector<T> {
public:
    Array (guint init_size = 0) : std::vector<T> (){
        std::vector<T>::reserve (init_size);
    }

    ~Array () {
    }

    guint length (void) const {
        return std::vector<T>::size ();
    }

    gboolean isEmpty (void) const {
        return length () == 0;
    }

    Array<T> & removeAll () {
        std::vector<T>::resize (0);
        return *this;
    }

    Array<T> & append (const T & v) {
        std::vector<T>::push_back (v);
        return *this;
    }

    Array<T> & append (const Array<T> & a) {
        for (guint i = 0; i < a.length (); i++)
            append (a.at (i));
        return *this;
    }
#if 0
    Array<T> & insert (guint i, const T & v) {
        g_array_insert_val (m_array, i, v);
        return *this;
    }

    Array<T> & remove (guint i, guint len) {
        g_array_remove_range (m_array, i, len);
        return *this;
    }
#endif
    Array<T> & push (const T & v) {
        std::vector<T>::push_back (v);
        return *this;
    }

    void pop (void) {
        std::vector<T>::pop_back ();
    }
#if 0
    Array<T> & assign (const Array<T> & v) {
        removeAll ();
        for (guint i = 0; i < v.length(); i++)
            append (v[i]);
        return *this;
    }

    Array<T> & operator = (const Array<T> & v) {
        return assign (v);
    }

    gboolean operator == (const Array<T> &v) const {
        if (length () != v.length ())
            return FALSE;
        for (guint i = 0; i < length (); i++) {
            if (get (i) != v[i])
                return FALSE;
        }
        return TRUE;
    }

#endif
    Array<T> & operator << (const T & v) {
        return append (v);
    }

    Array<T> & operator << (const Array<T> & a) {
        return append (a);
    }
    T & operator[] (guint i) {
        return std::vector<T>::operator[](i);
    }

    const T & operator[] (guint i) const {
        return std::vector<T>::operator[](i);
    }

    operator gboolean (void) const {
        return length () != 0;
    }
protected:
};

};

#endif
