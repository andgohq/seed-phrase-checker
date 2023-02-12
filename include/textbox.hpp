#include <M5EPD.h>
#include <string>

constexpr int MAX_SIZE = 256;
constexpr int TEXT_SIZE = 4;
constexpr int CHAR_W = 6;
constexpr int CHAR_H = 9;
constexpr int X = 48;
constexpr int Y = 48;
constexpr int W = 864;
constexpr int H = 228;

class Textbox {
private:
  std::string text;
  int cursor = 0;
  void drawChar(char *str);

public:
  std::string getText();
  void addChar(char ch);
  void deleteChar();
};
