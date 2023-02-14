#include <sstream>

#include <M5EPD.h>

#include <checker.hpp>
#include <keyboard.hpp>
#include <textbox.hpp>

M5EPD_Canvas canvas(&M5.EPD);
Textbox textbox;
Keyboard keyboard;
enum Mode { NOMAL, TOSHUTDOWN, SHUTDOWN } mode = NOMAL;

void checkLoop(void *);
void modeNomal(bool);
void modeToShutdown(bool);
void modeShutdown(bool);

void setup() {
  M5.begin();
  M5.EPD.SetRotation(0);
  M5.EPD.Clear(true);
  M5.RTC.begin();

  Serial.begin(115200);

  keyboard.drawKeyboard();
  keyboard.drawCloseButton();

  delay(1000);

  // Priority: 5 / Core: 0
  xTaskCreatePinnedToCore(checkLoop, "checkLoop", 8192, NULL, 1, NULL, 0);
}

CheckResult result;
bool errorChanged = false;

void checkLoop(void *param) {
  CheckResult oldResult;

  while (1) {
    delay(1000); // for WDT reset

    result = checkSeedPhrase(textbox.getWords());

    errorChanged = true;
  }
}

// Priority: 1 / Core: 0
void loop() {
  switch (mode) {
  case Mode::NOMAL:
    modeNomal(false);
    break;
  case Mode::TOSHUTDOWN:
    modeToShutdown(false);
    break;
  case Mode::SHUTDOWN:
    modeShutdown(false);
    break;
  default:
    break;
  }
}

void modeNomal(bool entering) {
  if (entering) {
    mode = NOMAL;
  }

  std::string message = "";

  char c = keyboard.getKey();
  switch (c) {
  case '*':
    modeToShutdown(true);
    break;
  case '#':
    // for demonstration
    delay(1000);
    break;

  case '\0':
    keyboard.redrawKey();

    if (errorChanged == false) {
      break;
    }

    switch (result.errorCode) {
    case FAIL_EMPTY:
      message = "Input BIP39 seed phrase.";
      break;
    case FAIL_WORD:
      for (int i = 0; i < 24; i++) {
        if (result.wordsNotInList[i]) {
          message += textbox.getWords()[i] + "/";
          continue;
        }
      }
      message.pop_back();
      message += result.count == 1 ? " is" : " are";
      message += " not in wordlist.";
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

void modeToShutdown(bool entering) {
  if (entering) {
    mode = TOSHUTDOWN;
    textbox.showMessage("Would you like to shutdown (y/n)?");
  }

  char c = keyboard.getKey();

  switch (c) {
  case 'y':
    modeShutdown(true);
    break;

  case 'n':
    modeNomal(true);
    break;

  case '\0':
    keyboard.redrawKey();
  default:
    break;
  }
}

void modeShutdown(bool entering) {
  if (entering) {
    mode = SHUTDOWN;
    textbox.showMessage("Bye.");
    textbox.wipe();
    delay(1000);
    M5.shutdown();
  }
  while (1)
    ;
}