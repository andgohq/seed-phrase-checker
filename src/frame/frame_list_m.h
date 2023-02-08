#ifndef _FRAME_LIST_M_H_
#define _FRAME_LIST_M_H_

#include "frame_base.h"
#include "../epdgui/epdgui.h"

class Frame_PrintM : public Frame_Base {
   public:
    Frame_PrintM(bool isHorizontal = false);
    ~Frame_PrintM();
    int run();
    int init(epdgui_args_vector_t &args);
    
    EPDGUI_Textbox *inputbox;
};

#endif  //_FRAME_LIST_M_H_