#pragma once
#include <M5EPD.h>
#include <queue>


typedef struct {
  int x;
  int y;
  int c;
} redrawData;

class Keyboard {
private:
  std::queue<redrawData> redrawList;
  void addKey(M5EPD_Canvas &canvas, int x, int y, int c);

public:
  void drawKeyboard();
  char getKey();
  void redrawKey();
};