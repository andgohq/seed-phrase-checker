#ifndef _FRAME_LIST_V_H_
#define _FRAME_LIST_V_H_

#include "frame_base.h"
#include "../epdgui/epdgui.h"

class Frame_PrintVZ : public Frame_Base {
   public:
    Frame_PrintVZ(bool isHorizontal = false);
    ~Frame_PrintVZ();
    int run();
    int init(epdgui_args_vector_t &args);
    
    EPDGUI_Textbox *inputbox;
};

#endif  //_FRAME_LIST_V_H_