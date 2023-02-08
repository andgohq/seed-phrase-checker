#include "frame_list_f.h"

Frame_PrintF::Frame_PrintF(bool isHorizontal) : Frame_Base() {
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
        _canvas_title->drawString("wordlist [F] ", 310, 34);
    }

    _key_exit->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0, (void *)(&_is_run));
    _key_exit->Bind(EPDGUI_Button::EVENT_RELEASED, &Frame_Base::exit_cb);
}

Frame_PrintF::~Frame_PrintF() {
    delete inputbox;
}

int Frame_PrintF::init(epdgui_args_vector_t &args) {
    _is_run = 1;
    M5.EPD.Clear();
    _canvas_title->pushCanvas(0, 8, UPDATE_MODE_NONE);
    EPDGUI_AddObject(inputbox);
    inputbox->SetText("fabric face faculty fade faint faith fall false fame family famous fan fancy fantasy farm fashion fat fatal father fatigue fault favorite feature february federal fee feed feel female fence festival fetch fever few fiber fiction field figure file film filter final find fine finger finish fire firm first fiscal fish fit fitness fix flag flame flash flat flavor flee flight flip float flock floor flower fluid flush fly foam focus fog foil fold follow food foot force forest forget fork fortune forum forward fossil foster found fox fragile frame frequent fresh friend fringe frog front frost frown frozen fruit fuel fun funny furnace fury future");
    EPDGUI_AddObject(_key_exit);
    return 6;
}

int Frame_PrintF::run(void) {
    Frame_Base::run();
    return 1;
}
