#ifndef _FRAME_LIST_Q_H_
#define _FRAME_LIST_Q_H_

#include "frame_base.h"
#include "../epdgui/epdgui.h"

class Frame_PrintQR : public Frame_Base {
   public:
    Frame_PrintQR(bool isHorizontal = false);
    ~Frame_PrintQR();
    int run();
    int init(epdgui_args_vector_t &args);
    
    EPDGUI_Textbox *inputbox;
};

#endif  //_FRAME_LIST_Q_H_