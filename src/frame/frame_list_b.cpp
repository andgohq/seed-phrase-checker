#include "frame_list_b.h"

Frame_PrintB::Frame_PrintB(bool isHorizontal) : Frame_Base() {
    _frame_name      = "Frame_B";
    uint8_t language = GetLanguage();

    if (isHorizontal) {
        inputbox = new EPDGUI_Textbox(34, 25, 712, 250);
    } else {
        const uint16_t kKeyBaseY = 628;
        inputbox                 = new EPDGUI_Textbox(4, 75, 530, 815);
    }

    if (language == LANGUAGE_EN) {
        exitbtn("Home");
        _canvas_title->drawString("wordlist [B] ", 310, 34);
    }

    _key_exit->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0, (void *)(&_is_run));
    _key_exit->Bind(EPDGUI_Button::EVENT_RELEASED, &Frame_Base::exit_cb);
}

Frame_PrintB::~Frame_PrintB() {
    delete inputbox;
}

int Frame_PrintB::init(epdgui_args_vector_t &args) {
    _is_run = 1;
    M5.EPD.Clear();
    _canvas_title->pushCanvas(0, 8, UPDATE_MODE_NONE);
    EPDGUI_AddObject(inputbox);
    inputbox->SetText("baby bachelor bacon badge bag balance balcony ball bamboo banana banner bar barely bargain barrel base basic basket battle beach bean beauty because become beef before begin behave behind believe below belt bench benefit best betray better between beyond bicycle bid bike bind biology bird birth bitter black blade blame blanket blast bleak bless blind blood blossom blouse blue blur blush board boat body boil bomb bone bonus book boost border boring borrow boss bottom bounce box boy brain brand brass brave bread breeze brick bridge brief bright bring brisk broccoli broken bronze broom brother brown brush bubble buddy budget buffalo build bulb bulk bullet bundle bunker burden burger burst bus business busy butter buyer buzz");
    EPDGUI_AddObject(_key_exit);
    return 6;
}

int Frame_PrintB::run(void) {
    Frame_Base::run();
    return 1;
}
