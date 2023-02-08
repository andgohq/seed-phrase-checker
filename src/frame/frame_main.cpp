#include "frame_main.h"
#include "frame_keyboard.h"
#include "frame_list_a.h"
#include "frame_list_b.h"
#include "frame_list_c.h"
#include "frame_list_d.h"
#include "frame_list_e.h"
#include "frame_list_f.h"
#include "frame_list_g.h"
#include "frame_list_i.h"
#include "frame_list_m.h"
#include "frame_list_n.h"
#include "frame_list_p.h"
#include "frame_list_q.h"
#include "frame_list_s.h"
#include "frame_list_t.h"
#include "frame_list_v.h"

enum {
    kKeyKeyboard = 0,
    kkeyPrintA,
    kkeyPrintB,
    kkeyPrintC,
    kkeyPrintD,
    kkeyPrintE,
    kkeyPrintF,
    kkeyPrintG,
    kkeyPrintI,
    kkeyPrintM,
    kkeyPrintN,
    kkeyPrintP,
    kkeyPrintQ,
    kkeyPrintS,
    kkeyPrintT,    
    kkeyPrintV,
};

#define KEY_W 92
#define KEY_H 92

void key_keyboard_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_Keyboard");
    if (frame == NULL) {
        frame = new Frame_Keyboard(0);
        EPDGUI_AddFrame("Frame_Keyboard", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_printa_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_printa");
    if (frame == NULL) {
        frame = new Frame_PrintA();
        EPDGUI_AddFrame("Frame_printa", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_printb_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_printb");
    if (frame == NULL) {
        frame = new Frame_PrintB();
        EPDGUI_AddFrame("Frame_printb", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_printc_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_printc");
    if (frame == NULL) {
        frame = new Frame_PrintC();
        EPDGUI_AddFrame("Frame_printc", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_printd_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_printd");
    if (frame == NULL) {
        frame = new Frame_PrintD();
        EPDGUI_AddFrame("Frame_printd", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_printe_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_printe");
    if (frame == NULL) {
        frame = new Frame_PrintE();
        EPDGUI_AddFrame("Frame_printe", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_printf_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_printf");
    if (frame == NULL) {
        frame = new Frame_PrintF();
        EPDGUI_AddFrame("Frame_printf", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_printg_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_printg");
    if (frame == NULL) {
        frame = new Frame_PrintGH();
        EPDGUI_AddFrame("Frame_printg", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_printi_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_printi");
    if (frame == NULL) {
        frame = new Frame_PrintIL();
        EPDGUI_AddFrame("Frame_printi", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_printm_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_printm");
    if (frame == NULL) {
        frame = new Frame_PrintM();
        EPDGUI_AddFrame("Frame_printm", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_printn_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_printn");
    if (frame == NULL) {
        frame = new Frame_PrintNO();
        EPDGUI_AddFrame("Frame_printn", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

void key_printp_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_printp");
    if (frame == NULL) {
        frame = new Frame_PrintP();
        EPDGUI_AddFrame("Frame_printp", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}
void key_printq_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_printq");
    if (frame == NULL) {
        frame = new Frame_PrintQR();
        EPDGUI_AddFrame("Frame_printq", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}
void key_prints_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_prints");
    if (frame == NULL) {
        frame = new Frame_PrintS();
        EPDGUI_AddFrame("Frame_prints", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}
void key_printt_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_printt");
    if (frame == NULL) {
        frame = new Frame_PrintTU();
        EPDGUI_AddFrame("Frame_printt", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}
void key_printv_cb(epdgui_args_vector_t &args) {
    Frame_Base *frame = EPDGUI_GetFrame("Frame_printv");
    if (frame == NULL) {
        frame = new Frame_PrintVZ();
        EPDGUI_AddFrame("Frame_printv", frame);
    }
    EPDGUI_PushFrame(frame);
    *((int *)(args[0])) = 0;
}

Frame_Main::Frame_Main(void) : Frame_Base(false) {
    _frame_name = "Frame_Main";
    _frame_id   = 1;

    _bar = new M5EPD_Canvas(&M5.EPD);
    _bar->createCanvas(540, 44);
    _bar->setTextSize(26);

    _names = new M5EPD_Canvas(&M5.EPD);
    _names->createCanvas(540, 32);
    _names->setTextDatum(CC_DATUM);

    for (int i = 0; i < 4; i++) {
        _key[i] = new EPDGUI_Button("测试", 20 + i * 136, 90, KEY_W, KEY_H);
    }

    for (int i = 0; i < 4; i++) {
        _key[i + 4] =
            new EPDGUI_Button("测试", 20 + i * 136, 240, KEY_W, KEY_H);
    }

    for (int i = 0; i < 4; i++) {
        _key[i + 8] =
            new EPDGUI_Button("测试", 20 + i * 136, 390, KEY_W, KEY_H);
    }
        
    for (int i = 0; i < 4; i++) {
        _key[i + 12] =
            new EPDGUI_Button("测试", 20 + i * 136, 540, KEY_W, KEY_H);
    }

    _key[kKeyKeyboard]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_keyboard_92x92);
    *(_key[kKeyKeyboard]->CanvasPressed()) =
        *(_key[kKeyKeyboard]->CanvasNormal());
    _key[kKeyKeyboard]->CanvasPressed()->ReverseColor();
    _key[kKeyKeyboard]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kKeyKeyboard]->Bind(EPDGUI_Button::EVENT_RELEASED, key_keyboard_cb);

    _key[kkeyPrintA]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_sdcard_92x92);
    *(_key[kkeyPrintA]->CanvasPressed()) =
        *(_key[kkeyPrintA]->CanvasNormal());
    _key[kkeyPrintA]->CanvasPressed()->ReverseColor();
    _key[kkeyPrintA]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kkeyPrintA]->Bind(EPDGUI_Button::EVENT_RELEASED, key_printa_cb);

    _key[kkeyPrintB]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_sdcard_92x92);
    *(_key[kkeyPrintB]->CanvasPressed()) =
        *(_key[kkeyPrintB]->CanvasNormal());
    _key[kkeyPrintB]->CanvasPressed()->ReverseColor();
    _key[kkeyPrintB]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kkeyPrintB]->Bind(EPDGUI_Button::EVENT_RELEASED, key_printb_cb);

    _key[kkeyPrintC]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_sdcard_92x92);
    *(_key[kkeyPrintC]->CanvasPressed()) =
        *(_key[kkeyPrintC]->CanvasNormal());
    _key[kkeyPrintC]->CanvasPressed()->ReverseColor();
    _key[kkeyPrintC]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kkeyPrintC]->Bind(EPDGUI_Button::EVENT_RELEASED, key_printc_cb);

    _key[kkeyPrintD]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_sdcard_92x92);
    *(_key[kkeyPrintD]->CanvasPressed()) =
        *(_key[kkeyPrintD]->CanvasNormal());
    _key[kkeyPrintD]->CanvasPressed()->ReverseColor();
    _key[kkeyPrintD]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kkeyPrintD]->Bind(EPDGUI_Button::EVENT_RELEASED, key_printd_cb);

    _key[kkeyPrintE]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_sdcard_92x92);
    *(_key[kkeyPrintE]->CanvasPressed()) =
        *(_key[kkeyPrintE]->CanvasNormal());
    _key[kkeyPrintE]->CanvasPressed()->ReverseColor();
    _key[kkeyPrintE]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kkeyPrintE]->Bind(EPDGUI_Button::EVENT_RELEASED, key_printe_cb);

    _key[kkeyPrintF]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_sdcard_92x92);
    *(_key[kkeyPrintF]->CanvasPressed()) =
        *(_key[kkeyPrintF]->CanvasNormal());
    _key[kkeyPrintF]->CanvasPressed()->ReverseColor();
    _key[kkeyPrintF]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kkeyPrintF]->Bind(EPDGUI_Button::EVENT_RELEASED, key_printf_cb);

    _key[kkeyPrintG]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_sdcard_92x92);
    *(_key[kkeyPrintG]->CanvasPressed()) =
        *(_key[kkeyPrintG]->CanvasNormal());
    _key[kkeyPrintG]->CanvasPressed()->ReverseColor();
    _key[kkeyPrintG]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kkeyPrintG]->Bind(EPDGUI_Button::EVENT_RELEASED, key_printg_cb);
    
    _key[kkeyPrintI]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_sdcard_92x92);
    *(_key[kkeyPrintI]->CanvasPressed()) =
        *(_key[kkeyPrintI]->CanvasNormal());
    _key[kkeyPrintI]->CanvasPressed()->ReverseColor();
    _key[kkeyPrintI]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kkeyPrintI]->Bind(EPDGUI_Button::EVENT_RELEASED, key_printi_cb);
    
    _key[kkeyPrintM]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_sdcard_92x92);
    *(_key[kkeyPrintM]->CanvasPressed()) =
        *(_key[kkeyPrintM]->CanvasNormal());
    _key[kkeyPrintM]->CanvasPressed()->ReverseColor();
    _key[kkeyPrintM]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kkeyPrintM]->Bind(EPDGUI_Button::EVENT_RELEASED, key_printm_cb);
    
    _key[kkeyPrintN]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_sdcard_92x92);
    *(_key[kkeyPrintN]->CanvasPressed()) =
        *(_key[kkeyPrintN]->CanvasNormal());
    _key[kkeyPrintN]->CanvasPressed()->ReverseColor();
    _key[kkeyPrintN]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kkeyPrintN]->Bind(EPDGUI_Button::EVENT_RELEASED, key_printn_cb);

    _key[kkeyPrintP]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_sdcard_92x92);
    *(_key[kkeyPrintP]->CanvasPressed()) =
        *(_key[kkeyPrintP]->CanvasNormal());
    _key[kkeyPrintP]->CanvasPressed()->ReverseColor();
    _key[kkeyPrintP]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kkeyPrintP]->Bind(EPDGUI_Button::EVENT_RELEASED, key_printp_cb);

    _key[kkeyPrintQ]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_sdcard_92x92);
    *(_key[kkeyPrintQ]->CanvasPressed()) =
        *(_key[kkeyPrintQ]->CanvasNormal());
    _key[kkeyPrintQ]->CanvasPressed()->ReverseColor();
    _key[kkeyPrintQ]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kkeyPrintQ]->Bind(EPDGUI_Button::EVENT_RELEASED, key_printq_cb);

    _key[kkeyPrintS]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_sdcard_92x92);
    *(_key[kkeyPrintS]->CanvasPressed()) =
        *(_key[kkeyPrintS]->CanvasNormal());
    _key[kkeyPrintS]->CanvasPressed()->ReverseColor();
    _key[kkeyPrintS]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kkeyPrintS]->Bind(EPDGUI_Button::EVENT_RELEASED, key_prints_cb);

    _key[kkeyPrintT]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_sdcard_92x92);
    *(_key[kkeyPrintT]->CanvasPressed()) =
        *(_key[kkeyPrintT]->CanvasNormal());
    _key[kkeyPrintT]->CanvasPressed()->ReverseColor();
    _key[kkeyPrintT]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kkeyPrintT]->Bind(EPDGUI_Button::EVENT_RELEASED, key_printt_cb);

    _key[kkeyPrintV]->CanvasNormal()->pushImage(
        0, 0, 92, 92, ImageResource_main_icon_sdcard_92x92);
    *(_key[kkeyPrintV]->CanvasPressed()) =
        *(_key[kkeyPrintV]->CanvasNormal());
    _key[kkeyPrintV]->CanvasPressed()->ReverseColor();
    _key[kkeyPrintV]->AddArgs(EPDGUI_Button::EVENT_RELEASED, 0,
                                (void *)(&_is_run));
    _key[kkeyPrintV]->Bind(EPDGUI_Button::EVENT_RELEASED, key_printv_cb);

    _time             = 0;
    _next_update_time = 0;
}

Frame_Main::~Frame_Main(void) {
    for (int i = 0; i < 8; i++) {
        delete _key[i];
    }
}

void Frame_Main::AppName(m5epd_update_mode_t mode) {
    if (!_names->isRenderExist(20)) {
        _names->createRender(20, 26);
    }
    _names->setTextSize(20);
    _names->fillCanvas(0);
    uint8_t language = GetLanguage();
    if (language == LANGUAGE_EN) {
        _names->drawString("Check", 20 + 46, 16);        
        _names->drawString("word A", 20 + 46 + 136, 16);
        _names->drawString("word B", 20 + 46 + 136 * 2, 16);
        _names->drawString("word C", 20 + 46 + 136 * 3, 16);
    }
    _names->pushCanvas(0, 186, mode);

    if (language == LANGUAGE_EN) {
        _names->drawString("word D", 20 + 46, 16);        
        _names->drawString("word E", 20 + 46 + 136, 16);
        _names->drawString("word F", 20 + 46 + 136 * 2, 16);
        _names->drawString("word G-H", 20 + 46 + 136 * 3, 16);
    }
    _names->pushCanvas(0, 337, mode);

    if (language == LANGUAGE_EN) {
        _names->drawString("word I-L", 20 + 46, 16);        
        _names->drawString("word M", 20 + 46 + 136, 16);
        _names->drawString("word N-O", 20 + 46 + 136 * 2, 16);
        _names->drawString(" word P ", 20 + 46 + 136 * 3, 16);
    }
    _names->pushCanvas(0, 488, mode);

    if (language == LANGUAGE_EN) {
        _names->drawString("word Q-R", 20 + 46, 16);        
        _names->drawString("word S", 20 + 46 + 136, 16);
        _names->drawString("word T-U", 20 + 46 + 136 * 2, 16);
        _names->drawString("word V-Z", 20 + 46 + 136 * 3, 16);
    }
    _names->pushCanvas(0, 639, mode);

}

void Frame_Main::StatusBar(m5epd_update_mode_t mode) {
    if ((millis() - _time) < _next_update_time) {
        return;
    }
    char buf[20];
    _bar->fillCanvas(0);
    _bar->drawFastHLine(0, 43, 540, 15);
    _bar->setTextDatum(CL_DATUM);
    _bar->drawString("M5Paper", 10, 27);

    // Battery
    _bar->setTextDatum(CR_DATUM);
    _bar->pushImage(498, 8, 32, 32, ImageResource_status_bar_battery_32x32);
    uint32_t vol = M5.getBatteryVoltage();

    if (vol < 3300) {
        vol = 3300;
    } else if (vol > 4350) {
        vol = 4350;
    }
    float battery = (float)(vol - 3300) / (float)(4350 - 3300);
    if (battery <= 0.01) {
        battery = 0.01;
    }
    if (battery > 1) {
        battery = 1;
    }
    uint8_t px = battery * 25;
    sprintf(buf, "%d%%", (int)(battery * 100));
    // _bar->drawString(buf, 498 - 10, 27);
    _bar->fillRect(498 + 3, 8 + 10, px, 13, 15);
    // _bar->pushImage(498, 8, 32, 32, 2,
    // ImageResource_status_bar_battery_charging_32x32);

    // Time
    rtc_time_t time_struct;
    rtc_date_t date_struct;
    M5.RTC.getTime(&time_struct);
    M5.RTC.getDate(&date_struct);
    sprintf(buf, "%2d:%02d", time_struct.hour, time_struct.min);
    _bar->setTextDatum(CC_DATUM);
    _bar->drawString(buf, 270, 27);
    _bar->pushCanvas(0, 0, mode);

    _time             = millis();
    _next_update_time = (60 - time_struct.sec) * 1000;
}

int Frame_Main::init(epdgui_args_vector_t &args) {
    _is_run = 1;
    for (int i = 0; i < 16; i++) {
        EPDGUI_AddObject(_key[i]);
    }
    _time             = 0;
    _next_update_time = 0;
    StatusBar(UPDATE_MODE_NONE);
    AppName(UPDATE_MODE_NONE);
    return 9;
}

int Frame_Main::run() {
    Frame_Base::run();
    StatusBar(UPDATE_MODE_GL16);
    return 1;
}