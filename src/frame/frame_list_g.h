#ifndef _FRAME_LIST_G_H_
#define _FRAME_LIST_G_H_

#include "frame_base.h"
#include "../epdgui/epdgui.h"

class Frame_PrintGH : public Frame_Base {
   public:
    Frame_PrintGH(bool isHorizontal = false);
    ~Frame_PrintGH();
    int run();
    int init(epdgui_args_vector_t &args);
    
    EPDGUI_Textbox *inputbox;
};

#endif  //_FRAME_LIST_G_H_