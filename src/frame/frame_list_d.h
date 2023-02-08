#ifndef _FRAME_LIST_D_H_
#define _FRAME_LIST_D_H_

#include "frame_base.h"
#include "../epdgui/epdgui.h"

class Frame_PrintD : public Frame_Base {
   public:
    Frame_PrintD(bool isHorizontal = false);
    ~Frame_PrintD();
    int run();
    int init(epdgui_args_vector_t &args);
    
    EPDGUI_Textbox *inputbox;
};

#endif  //_FRAME_LIST_D_H_