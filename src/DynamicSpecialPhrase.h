#ifndef __DYNAMIC_SPECIAL_PHRASE_H_
#define __DYNAMIC_SPECIAL_PHRASE_H_

#include <ctime>
#include <string>
#include <glib.h>
#include "SpecialPhrase.h"

namespace PY {

class DynamicSpecialPhrase : public SpecialPhrase {
public:
    DynamicSpecialPhrase (const std::string &text, guint pos) :
        SpecialPhrase (pos), m_text (text) { }
    ~DynamicSpecialPhrase (void);

    std::string text (void);
    const std::string dec (gint d, const gchar *fmt = "%d");
    const std::string year_cn (gboolean yy = FALSE);
    const std::string month_cn (void);
    const std::string weekday_cn (void);
    const std::string hour_cn (guint i);
    const std::string fullhour_cn (void);
    const std::string halfhour_cn (void);
    const std::string day_cn (void);
    const std::string minsec_cn (guint i);
    const std::string variable (const std::string &name);

private:
    std::string m_text;
    std::tm m_time;
};

};
#endif
