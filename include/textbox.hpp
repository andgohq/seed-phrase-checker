#include <M5EPD.h>
#include <string>

constexpr int MAX_SIZE = 256;
constexpr int TEXT_SIZE = 4;
constexpr int CHAR_W = 6;
constexpr int CHAR_H = 9;
constexpr int X = 36;
constexpr int Y = 36;
constexpr int W = 888;
constexpr int H = 228;

class Textbox {
private:
  std::string text;
  int cursor = 0;
  void drawChar(char ch);

public:
  std::string getText();
  void addChar(char ch);
  void deleteChar();
};
