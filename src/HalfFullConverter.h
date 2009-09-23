#ifndef __PY_HALF_FULL_CONVERTER_H_
#define __PY_HALF_FULL_CONVERTER_H_

#include <glib.h>

namespace PY {

class HalfFullConverter {

public:
    static gunichar toFull (gunichar ch);
    static gunichar toHalf (gunichar ch);

private:
    const static guint m_table[][3];
};

};
#endif
