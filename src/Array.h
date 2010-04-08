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

    Array<T> & removeAll () {
        std::vector<T>::clear ();
        return *this;
    }

    Array<T> & append (const T & v) {
        std::vector<T>::push_back (v);
        return *this;
    }

    Array<T> & append (const Array<T> & a) {
        for (guint i = 0; i < a.size (); i++)
            append (a.at (i));
        return *this;
    }

    Array<T> & push (const T & v) {
        std::vector<T>::push_back (v);
        return *this;
    }

    void pop (void) {
        g_assert (! std::vector<T>::empty ());
        std::vector<T>::pop_back ();
    }

    Array<T> & operator << (const T & v) {
        return append (v);
    }

    Array<T> & operator << (const Array<T> & a) {
        return append (a);
    }

    T & operator[] (guint i) {
        g_assert (i < std::vector<T>::size ());
        return std::vector<T>::operator[](i);
    }

    const T & operator[] (guint i) const {
        g_assert (i < std::vector<T>::size ());
        return std::vector<T>::operator[](i);
    }

    operator gboolean (void) const {
        return ! std::vector<T>::empty ();
    }
};

};

#endif
