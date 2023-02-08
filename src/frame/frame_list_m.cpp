#include "frame_list_m.h"

Frame_PrintM::Frame_PrintM(bool isHorizontal) : Frame_Base() {
    _frame_name      = "Frame_M";
    uint8_t language = GetLanguage();

    if (isHorizontal) {
        inputbox = new EPDGUI_Textbox(34, 25, 712, 250);
    } else {
        const uint16_t kKeyBaseY = 628;
        inputbox                 = new EPDGUI_Textbox(4, 75, 530, 850);
    }

    if (language == LANGUAGE_EN) {
        exitbtn("Home");
        _canvas_title->drawString("wordlist [M] ", 310, 34);
    }

    _key_exit->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0, (void *)(&_is_run));
    _key_exit->Bind(EPDGUI_Button::EVENT_RELEASED, &Frame_Base::exit_cb);
}

Frame_PrintM::~Frame_PrintM() {
    delete inputbox;
}

int Frame_PrintM::init(epdgui_args_vector_t &args) {
    _is_run = 1;
    M5.EPD.Clear();
    _canvas_title->pushCanvas(0, 8, UPDATE_MODE_NONE);
    EPDGUI_AddObject(inputbox);
    inputbox->SetText("machine mad magic magnet maid mail main major make mammal man manage mandate mango mansion manual maple marble march margin marine market marriage mask mass master match material math matrix matter maximum maze meadow mean measure meat mechanic medal media melody melt member memory mention menu mercy merge merit merry mesh message metal method middle midnight milk million mimic mind minimum minor minute miracle mirror misery miss mistake mix mixed mixture mobile model modify mom moment monitor monkey monster month moon moral more morning mosquito mother motion motor mountain mouse move movie much muffin mule multiply muscle museum mushroom music must mutual myself mystery myth");
    EPDGUI_AddObject(_key_exit);
    return 6;
}

int Frame_PrintM::run(void) {
    Frame_Base::run();
    return 1;
}
