#ifndef _FRAME_LIST_C_H_
#define _FRAME_LIST_C_H_

#include "frame_base.h"
#include "../epdgui/epdgui.h"

class Frame_PrintC : public Frame_Base {
   public:
    Frame_PrintC(bool isHorizontal = false);
    ~Frame_PrintC();
    int run();
    int init(epdgui_args_vector_t &args);
    
    EPDGUI_Textbox *inputbox;
};

#endif  //_FRAME_LIST_C_H_