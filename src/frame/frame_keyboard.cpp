#include "frame_keyboard.h"

uint16_t textsize = 26;

Frame_Keyboard::Frame_Keyboard(bool isHorizontal) : Frame_Base() {
    _frame_name      = "Frame_Keyboard";
    uint8_t language = GetLanguage();
    if (isHorizontal) {
        inputbox = new EPDGUI_Textbox(34, 25, 712, 250);
    } else {
        const uint16_t kKeyBaseY = 628;
        inputbox                 = new EPDGUI_Textbox(4, 75, 530, 615);
    }

    inputbox->SetState(EPDGUI_Textbox::EVENT_PRESSED);

    keyboard = new EPDGUI_Keyboard(isHorizontal);

    if (language == LANGUAGE_EN) {
        exitbtn("Home");
        _canvas_title->drawString("What's your SeedPhrase?", 310, 34);
    }

    _key_exit->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0, (void *)(&_is_run));
    _key_exit->Bind(EPDGUI_Button::EVENT_RELEASED, &Frame_Base::exit_cb);
}

Frame_Keyboard::~Frame_Keyboard() {
    delete inputbox;
    delete keyboard;
}

int Frame_Keyboard::init(epdgui_args_vector_t &args) {
    _is_run = 1;
    M5.EPD.Clear();
    _canvas_title->pushCanvas(0, 8, UPDATE_MODE_NONE);
    EPDGUI_AddObject(inputbox);
    EPDGUI_AddObject(keyboard);
    EPDGUI_AddObject(_key_exit);
    return 6;
}

int Frame_Keyboard::run(void) {
    Frame_Base::run();
    inputbox->AddText(keyboard->getData());
    return 1;
}
