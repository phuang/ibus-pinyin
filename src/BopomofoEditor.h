#ifndef __PY_BOPOMOFO_EDITOR_H_
#define __PY_BOPOMOFO_EDITOR_H_

#include "PinyinEditor.h"

namespace PY {

#include "Bopomofo.h"

class BopomofoEditor : public PinyinEditor {

public:
    BopomofoEditor (PinyinProperties & props);
    ~BopomofoEditor (void);

public:
    /* virtual functions */
    virtual gboolean processKeyEvent (guint keyval, guint keycode, guint modifiers);
    virtual void reset (void);

protected:
    std::wstring bopomofo;

    virtual void updatePinyin (void);
    virtual void updateAuxiliaryText (void);
    virtual void updatePreeditText (void);
    virtual void commit (void);

    gboolean insert (gint ch);

    gboolean removeCharBefore (void);
    gboolean removeCharAfter (void);
    gboolean removeWordBefore (void);
    gboolean removeWordAfter (void);

    gboolean moveCursorLeft (void);
    gboolean moveCursorRight (void);
    gboolean moveCursorLeftByWord (void);
    gboolean moveCursorRightByWord (void);
    gboolean moveCursorToBegin (void);
    gboolean moveCursorToEnd (void);

    gboolean processBopomofo (guint keyval, guint keycode, guint modifiers);

    gint keyvalToBopomofo(gint ch) {
        switch(ch){
        case IBUS_1: return BOPOMOFO_B;
        case IBUS_q: return BOPOMOFO_P;
        case IBUS_a: return BOPOMOFO_M;
        case IBUS_z: return BOPOMOFO_F;
        case IBUS_2: return BOPOMOFO_D;
        case IBUS_w: return BOPOMOFO_T;
        case IBUS_s: return BOPOMOFO_N;
        case IBUS_x: return BOPOMOFO_L;
        case IBUS_e: return BOPOMOFO_G;
        case IBUS_d: return BOPOMOFO_K;
        case IBUS_c: return BOPOMOFO_H;
        case IBUS_r: return BOPOMOFO_J;
        case IBUS_f: return BOPOMOFO_Q;
        case IBUS_v: return BOPOMOFO_X;
        case IBUS_5: return BOPOMOFO_ZH;
        case IBUS_t: return BOPOMOFO_CH;
        case IBUS_g: return BOPOMOFO_SH;
        case IBUS_b: return BOPOMOFO_R;
        case IBUS_y: return BOPOMOFO_Z;
        case IBUS_h: return BOPOMOFO_C;
        case IBUS_n: return BOPOMOFO_S;

        case IBUS_u: return BOPOMOFO_I;
        case IBUS_j: return BOPOMOFO_U;
        case IBUS_m: return BOPOMOFO_V;
        case IBUS_8: return BOPOMOFO_A;
        case IBUS_i: return BOPOMOFO_O;
        case IBUS_k: return BOPOMOFO_E;
        case IBUS_comma: return BOPOMOFO_E2;
        case IBUS_9: return BOPOMOFO_AI;
        case IBUS_o: return BOPOMOFO_EI;
        case IBUS_l: return BOPOMOFO_AO;
        case IBUS_period: return BOPOMOFO_OU;
        case IBUS_0: return BOPOMOFO_AN;
        case IBUS_p: return BOPOMOFO_EN;
        case IBUS_semicolon: return BOPOMOFO_ANG;
        case IBUS_slash: return BOPOMOFO_ENG;
        case IBUS_minus: return BOPOMOFO_ER;

        case IBUS_3: return BOPOMOFO_TONE_2;
        case IBUS_4: return BOPOMOFO_TONE_3;
        case IBUS_6: return BOPOMOFO_TONE_4;
        case IBUS_7: return BOPOMOFO_TONE_5;

        default:
            return 0;
        }
    }


};

};

#endif
