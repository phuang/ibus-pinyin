#ifndef __PY_LOOKUP_TABLE_H_
#define __PY_LOOKUP_TABLE_H_

#include <ibus.h>
#include "Pointer.h"
#include "Text.h"

namespace PY {

class LookupTable : public Pointer <IBusLookupTable> {
public:
    LookupTable (guint page_size = 10,
                 guint cursor_pos = 0,
                 gboolean cursor_visible = TRUE,
                 gboolean round = FALSE)
        : Pointer <IBusLookupTable> (ibus_lookup_table_new (page_size, cursor_pos, cursor_visible, round)) { }

    guint pageSize (void) { return ibus_lookup_table_get_page_size (*this); }
    guint cursorPos (void) { return ibus_lookup_table_get_cursor_pos (*this); }

    gboolean pageUp (void) { return ibus_lookup_table_page_up (*this); }
    gboolean pageDown (void) { return ibus_lookup_table_page_down (*this); }
    gboolean cursorUp (void) { return ibus_lookup_table_cursor_up (*this); }
    gboolean cursorDown (void) { return ibus_lookup_table_cursor_down (*this); }

    void setPageSize (guint size) { ibus_lookup_table_set_page_size (*this, size); }
    void clear (void) { ibus_lookup_table_clear (*this); }

    void appendCandidate (Text & text) {
        ibus_lookup_table_append_candidate (*this, text);
    }
};

};

#endif
