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

    if (!textbox.isWordCountUpdated())
      break;

    if (checkLastWord(textbox.getText()) == false) {
      // textbox.showMessage("Last word is not in the BIP39 word list.");
      textbox.showMessage(textbox.getText());
    } else {
      textbox.showMessage("");
    }

    if (textbox.getWordCount() < 24) {
      return;
    }

    switch (checkSeedPhrase(textbox.getText())) {
    case FAIL_WORD:
      textbox.showMessage("Not in BIP39 word list.");
      break;
    case FAIL_CHECK_SUM:
      textbox.showMessage("Checksum does not match.");
      break;
    case SUCCESS:
      textbox.showMessage("Valid seed phrase.");
      break;
    default:
      textbox.showMessage("Unkown error.");
      break;
    }

    break;

  default:
    textbox.addChar(c);
  }
}
