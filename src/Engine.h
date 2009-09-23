/* vim:set et sts=4: */
#ifndef __PY_ENGINE_H__
#define __PY_ENGINE_H__

#include <ibus.h>

namespace PY {

#define IBUS_TYPE_PINYIN_ENGINE	\
	(PY::ibus_pinyin_engine_get_type ())

GType   ibus_pinyin_engine_get_type    (void);
};

#endif
