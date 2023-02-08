#ifndef _FRAME_LIST_E_H_
#define _FRAME_LIST_E_H_

#include "frame_base.h"
#include "../epdgui/epdgui.h"

class Frame_PrintE : public Frame_Base {
   public:
    Frame_PrintE(bool isHorizontal = false);
    ~Frame_PrintE();
    int run();
    int init(epdgui_args_vector_t &args);
    
    EPDGUI_Textbox *inputbox;
};

#endif  //_FRAME_LIST_E_H_