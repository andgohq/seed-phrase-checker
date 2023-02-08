#ifndef _FRAME_LIST_N_H_
#define _FRAME_LIST_N_H_

#include "frame_base.h"
#include "../epdgui/epdgui.h"

class Frame_PrintNO : public Frame_Base {
   public:
    Frame_PrintNO(bool isHorizontal = false);
    ~Frame_PrintNO();
    int run();
    int init(epdgui_args_vector_t &args);
    
    EPDGUI_Textbox *inputbox;
};

#endif  //_FRAME_LIST_N_H_