#ifndef _FRAME_LIST_F_H_
#define _FRAME_LIST_F_H_

#include "frame_base.h"
#include "../epdgui/epdgui.h"

class Frame_PrintF : public Frame_Base {
   public:
    Frame_PrintF(bool isHorizontal = false);
    ~Frame_PrintF();
    int run();
    int init(epdgui_args_vector_t &args);
    
    EPDGUI_Textbox *inputbox;
};

#endif  //_FRAME_LIST_F_H_