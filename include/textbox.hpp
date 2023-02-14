#include <M5EPD.h>
#include <string>

#include "consts.hpp"

class Textbox {
private:
  void drawChar(char *str);
  void incWordCount();
  void decWordCount();
  std::string text;
  int cursor = 0;
  int wordCount = 0;
  bool updatedWordCount = false;

public:
  std::string getText();
  std::vector<std::string> getWords();
  void addChar(char ch);
  void deleteChar();
  int getWordCount();
  bool isWordCountUpdated();
  void showMessage(std::string message);
  void wipe();
};
