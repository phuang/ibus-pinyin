#ifndef __PY_ARRAY_H_
#define __PY_ARRAY_H_

namespace PY {

template<typename T>
class Array {
public:
    Array (guint init_size = 0) {
        m_array = g_array_sized_new (FALSE, FALSE, sizeof (T), init_size);
    }

    ~Array () {
        g_array_free (m_array, TRUE);
    }

    T & get (guint i) {
        return g_array_index (m_array, T, i);
    }

    const T & get (guint i) const {
        return g_array_index (m_array, T, i);
    }

    guint length (void) const {
        return m_array->len;
    }

    gboolean isEmpty (void) const {
        return length () == 0;
    }

    Array<T> & setSize (guint size) {
        g_array_set_size (m_array, size);
        return *this;
    }

    Array<T> & removeAll () {
        setSize (0);
        return *this;
    }

    Array<T> & append (const T & v) {
        g_array_append_val (m_array, v);
        return *this;
    }

    Array<T> & append (const Array<T> & a) {
        for (guint i = 0; i < a.length (); i++)
            append (a[i]);
        return *this;
    }

    Array<T> & push (const T & v) {
        append (v);
        return *this;
    }

    T & pop (void) {
        T & v = g_array_index (m_array, T, length () - 1);
        g_array_set_size (m_array, length () - 1);
        return v;
    }

    Array<T> & operator = (const Array<T> & v) {
        removeAll ();
        for (guint i = 0; i < v.length(); i++)
            append (v[i]);
        return *this;
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

    Array<T> & operator << (const T & v) {
        return append (v);
    }

    Array<T> & operator << (const Array<T> & a) {
        return append (a);
    }

    T & operator[] (guint i) {
        return get (i);
    }

    const T & operator[] (guint i) const {
        return get (i);
    }

    operator gboolean (void) const {
        return length () != 0;
    }

private:
    GArray *m_array;
};

};

#endif
