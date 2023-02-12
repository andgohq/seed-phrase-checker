#include <M5EPD.h>

#include <checker.hpp>
#include <keyboard.hpp>
#include <textbox.hpp>

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
  switch (c) {
  case '\0':
    keyboard.redrawKey();
    break;

  case '<':
    Serial.println("backspace");
    textbox.deleteChar();
    break;

  case ' ':
    textbox.addChar(c);
    if (textbox.isWordCountUpdated()) {
      checkSeedPhrase(textbox.getText())
    }

    break;

  default:
    textbox.addChar(c);
  }
}
