#include "keyboard.hpp"
#include "textbox.hpp"
#include <M5EPD.h>

M5EPD_Canvas canvas(&M5.EPD);
Textbox textbox;
Keyboard keyboard;

void setup() {
  M5.begin();
  M5.EPD.SetRotation(0);
  M5.EPD.Clear(true);
  M5.RTC.begin();

  Serial.begin(115200);

  keyboard.drawKeyboard();
}

void loop() {
  char c = keyboard.getKey();
  if (c == '<') {
    Serial.println("backspace");
    textbox.deleteChar();
  } else if (c != 0) {
    textbox.addChar(c);
  } else {
    keyboard.redrawKey();
  }

  if (textbox.getWordCount() >= 24) {
  }
}