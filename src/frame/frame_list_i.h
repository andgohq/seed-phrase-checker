#ifndef _FRAME_LIST_I_H_
#define _FRAME_LIST_I_H_

#include "frame_base.h"
#include "../epdgui/epdgui.h"

class Frame_PrintIL : public Frame_Base {
   public:
    Frame_PrintIL(bool isHorizontal = false);
    ~Frame_PrintIL();
    int run();
    int init(epdgui_args_vector_t &args);
    
    EPDGUI_Textbox *inputbox;
};

#endif  //_FRAME_LIST_I_H_