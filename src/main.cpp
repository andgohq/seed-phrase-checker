#include <M5EPD.h>

#include <checker.hpp>
#include <keyboard.hpp>
#include <textbox.hpp>

M5EPD_Canvas canvas(&M5.EPD);
Textbox textbox;
Keyboard keyboard;

void checkLoop(void *);

void setup() {
  M5.begin();
  M5.EPD.SetRotation(0);
  M5.EPD.Clear(true);
  M5.RTC.begin();

  Serial.begin(115200);

  keyboard.drawKeyboard();

  delay(1000);
  // Priority: 5 / Core: 0
  xTaskCreatePinnedToCore(checkLoop, "checkLoop", 8192, NULL, 1, NULL, 0);
}

int error;
bool errorChanged = false;

void checkLoop(void *param) {
  int oldError;

  while (1) {
    error = checkSeedPhrase(textbox.getText());
    if (oldError != error) {
      oldError = error;
      errorChanged = true;
    }
    delay(1);
  }
}

// Priority: 1 / Core: 0
void loop() {

  char c = keyboard.getKey();
  switch (c) {
  case '#':
    // for demonstration
    delay(1000);
    break;

  case '\0':
    // keyboard.redrawKey();

    if (errorChanged == false) {
      break;
    }

    switch (error) {
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

    errorChanged = false;

    break;

  case '<':
    Serial.println("backspace");
    textbox.deleteChar();
    break;

  case ' ':
    textbox.addChar(c);

    if (!textbox.isWordCountUpdated())
      break;

    break;

  default:
    textbox.addChar(c);
  }
}
