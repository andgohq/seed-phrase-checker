#ifndef _FRAME_LIST_P_H_
#define _FRAME_LIST_P_H_

#include "frame_base.h"
#include "../epdgui/epdgui.h"

class Frame_PrintP : public Frame_Base {
   public:
    Frame_PrintP(bool isHorizontal = false);
    ~Frame_PrintP();
    int run();
    int init(epdgui_args_vector_t &args);
    
    EPDGUI_Textbox *inputbox;
};

#endif  //_FRAME_LIST_P_H_