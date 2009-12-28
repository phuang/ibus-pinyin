#ifndef __PY_HASH_TABLE_H_
#define __PY_HASH_TABLE_H_
#include <glib.h>

namespace PY {

template<typename T1, typename T2>
class HashTable {
public:
    HashTable () {
        m_table = g_hash_table_new_full ();
    }

private:
    static guint hash (const T1 & v) {
        return v.hash();
    }

private:
    GHashTable *m_table;

};
#endif
