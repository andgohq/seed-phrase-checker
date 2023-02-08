#include "frame_list_c.h"

Frame_PrintC::Frame_PrintC(bool isHorizontal) : Frame_Base() {
    _frame_name      = "Frame_C";
    uint8_t language = GetLanguage();

    if (isHorizontal) {
        inputbox = new EPDGUI_Textbox(34, 25, 712, 250);
    } else {
        const uint16_t kKeyBaseY = 628;
        inputbox                 = new EPDGUI_Textbox(4, 75, 530, 850);
    }

    if (language == LANGUAGE_EN) {
        exitbtn("Home");
        _canvas_title->drawString("wordlist [C] ", 310, 34);
    }

    _key_exit->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0, (void *)(&_is_run));
    _key_exit->Bind(EPDGUI_Button::EVENT_RELEASED, &Frame_Base::exit_cb);
}

Frame_PrintC::~Frame_PrintC() {
    delete inputbox;
}

int Frame_PrintC::init(epdgui_args_vector_t &args) {
    _is_run = 1;
    M5.EPD.Clear();
    _canvas_title->pushCanvas(0, 8, UPDATE_MODE_NONE);
    EPDGUI_AddObject(inputbox);
    inputbox->SetText("cabbage cabin cable cactus cage cake call calm camera camp can canal cancel candy cannon canoe canvas canyon capable capital captain car carbon card cargo carpet carry cart case cash casino castle casual cat catalog catch category cattle caught cause caution cave ceiling celery cement census century cereal certain chair chalk champion change chaos chapter charge chase chat cheap check cheese chef cherry chest chicken chief child chimney choice choose chronic chuckle chunk churn cigar cinnamon circle citizen city civil claim clap clarify claw clay clean clerk clever click client cliff climb clinic clip clock clog close cloth cloud clown club clump cluster clutch coach coast coconut code coffee coil coin collect color column combine come comfort comic common company concert conduct confirm congress connect consider control convince cook cool copper copy coral core corn correct cost cotton couch country couple course cousin cover coyote crack cradle craft cram crane crash crater crawl crazy cream credit creek crew cricket crime crisp critic crop cross crouch crowd crucial cruel cruise crumble crunch crush cry crystal cube culture cup cupboard curious current curtain curve cushion custom cute cycle");
    EPDGUI_AddObject(_key_exit);
    return 6;
}

int Frame_PrintC::run(void) {
    Frame_Base::run();
    return 1;
}
