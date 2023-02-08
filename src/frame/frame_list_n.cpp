#include "frame_list_n.h"

Frame_PrintNO::Frame_PrintNO(bool isHorizontal) : Frame_Base() {
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
        _canvas_title->drawString("wordlist [N][O] ", 310, 34);
    }

    _key_exit->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0, (void *)(&_is_run));
    _key_exit->Bind(EPDGUI_Button::EVENT_RELEASED, &Frame_Base::exit_cb);
}

Frame_PrintNO::~Frame_PrintNO() {
    delete inputbox;
}

int Frame_PrintNO::init(epdgui_args_vector_t &args) {
    _is_run = 1;
    M5.EPD.Clear();
    _canvas_title->pushCanvas(0, 8, UPDATE_MODE_NONE);
    EPDGUI_AddObject(inputbox);
    inputbox->SetText("naive name napkin narrow nasty nation nature near neck need negative neglect neither nephew nerve nest net network neutral never news next nice night noble noise nominee noodle normal north nose notable note nothing notice novel now nuclear number nurse nut oak obey object oblige obscure observe obtain obvious occur ocean october odor off offer office often oil okay old olive olympic omit once one onion online only open opera opinion oppose option orange orbit orchard order ordinary organ orient original orphan ostrich other outdoor outer output outside oval oven over own owner oxygen oyster ozone ");
    EPDGUI_AddObject(_key_exit);
    return 6;
}

int Frame_PrintNO::run(void) {
    Frame_Base::run();
    return 1;
}
