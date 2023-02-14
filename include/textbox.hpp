#include <M5EPD.h>
#include <string>

constexpr int TEXT_SIZE = 4;
constexpr int CHAR_W = 6;
constexpr int CHAR_H = 9;
constexpr int X = 48;
constexpr int Y = 48;
constexpr int W = 864;
constexpr int H = 228;
constexpr int MAX_SIZE = W / (CHAR_W * TEXT_SIZE) * 6;

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
};
