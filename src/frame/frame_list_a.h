#ifndef _FRAME_LIST_A_H_
#define _FRAME_LIST_A_H_

#include "frame_base.h"
#include "../epdgui/epdgui.h"

class Frame_PrintA : public Frame_Base {
   public:
    Frame_PrintA(bool isHorizontal = false);
    ~Frame_PrintA();
    int run();
    int init(epdgui_args_vector_t &args);
    
    EPDGUI_Textbox *inputbox;
};

#endif  //_FRAME_LIST_A_H_