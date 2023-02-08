#ifndef _FRAME_LIST_S_H_
#define _FRAME_LIST_S_H_

#include "frame_base.h"
#include "../epdgui/epdgui.h"

class Frame_PrintS : public Frame_Base {
   public:
    Frame_PrintS(bool isHorizontal = false);
    ~Frame_PrintS();
    int run();
    int init(epdgui_args_vector_t &args);
    
    EPDGUI_Textbox *inputbox;
};

#endif  //_FRAME_LIST_S_H_