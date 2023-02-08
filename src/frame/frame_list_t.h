#ifndef _FRAME_LIST_T_H_
#define _FRAME_LIST_T_H_

#include "frame_base.h"
#include "../epdgui/epdgui.h"

class Frame_PrintTU : public Frame_Base {
   public:
    Frame_PrintTU(bool isHorizontal = false);
    ~Frame_PrintTU();
    int run();
    int init(epdgui_args_vector_t &args);
    
    EPDGUI_Textbox *inputbox;
};

#endif  //_FRAME_LIST_T_H_