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

    Array<T> & push (const T & v) {
        std::vector<T>::push_back (v);
        return *this;
    }

    void pop (void) {
        g_assert (!isEmpty ());
        std::vector<T>::pop_back ();
    }

    Array<T> & operator << (const T & v) {
        return append (v);
    }

    Array<T> & operator << (const Array<T> & a) {
        return append (a);
    }

    T & operator[] (guint i) {
        g_assert (i < length ());
        return std::vector<T>::operator[](i);
    }

    const T & operator[] (guint i) const {
        g_assert (i < length ());
        return std::vector<T>::operator[](i);
    }

    operator gboolean (void) const {
        return length () != 0;
    }
};

};

#endif
