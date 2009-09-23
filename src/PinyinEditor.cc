#include "Config.h"
#include "PinyinEditor.h"

namespace PY {

#define MAX_PINYIN_LEN 64


PinyinParser PinyinEditor::m_parser;

PinyinEditor::PinyinEditor (void)
    : m_text (MAX_PINYIN_LEN),
      m_cursor (0),
      m_pinyin (MAX_PHRASE_LEN),
      m_pinyin_len (0)
{
}

};

