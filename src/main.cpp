#include <sstream>

#include <M5EPD.h>

#include <checker.hpp>
#include <keyboard.hpp>
#include <sstream>
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

CheckResult result;
bool errorChanged = false;

void checkLoop(void *param) {
  CheckResult oldResult;

  while (1) {
    delay(1); // for WDT reset

    result = checkSeedPhrase(textbox.getText());

    if (oldResult.errorCode != result.errorCode) {
      errorChanged = true;
      oldResult = result;
      continue;
    }

    int i = 0;
    for (auto notinlist : result.wordsNotInList) {
      if (oldResult.wordsNotInList[i] != notinlist) {
        errorChanged = true;
        oldResult = result;
        continue;
      }
      i++;
    }
  }
}

// Priority: 1 / Core: 0
void loop() {
  std::string message = "";
  std::ostringstream os;

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

    switch (result.errorCode) {
    case FAIL_WORD:
      for (int i = 0; i < 24; i++) {
        if (result.wordsNotInList[i]) {
          os << i + 1;
        }
      }
      os << "Not in BIP39 word list.";
      message = os.str();
      break;
    case FAIL_CHECK_SUM:
      message = "Checksum does not match.";
      break;
    case SUCCESS:
      message = "Valid seed phrase.";
      break;
    default:
      message = "Unkown error.";
      break;
    }

    textbox.showMessage(message);

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
