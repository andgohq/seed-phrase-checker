#ifndef _FRAME_LIST_B_H_
#define _FRAME_LIST_B_H_

#include "frame_base.h"
#include "../epdgui/epdgui.h"

class Frame_PrintB : public Frame_Base {
   public:
    Frame_PrintB(bool isHorizontal = false);
    ~Frame_PrintB();
    int run();
    int init(epdgui_args_vector_t &args);
    
    EPDGUI_Textbox *inputbox;
};

#endif  //_FRAME_LIST_B_H_