#include "textbox.hpp"

#include <string>

std::string Textbox::getText() { return text; }

void Textbox::drawChar(char ch) {
  M5EPD_Canvas canvas(&M5.EPD);

  char buf[] = {ch, '\0'};
  int cx = CHAR_W * TEXT_SIZE * cursor % (W - CHAR_W * TEXT_SIZE);
  int cy = CHAR_W * TEXT_SIZE * cursor / (W - CHAR_W * TEXT_SIZE) * CHAR_H *
           TEXT_SIZE;

  canvas.createCanvas(CHAR_W * TEXT_SIZE, CHAR_H * TEXT_SIZE);
  canvas.setTextSize(TEXT_SIZE);
  canvas.drawString(buf, 0, 0);
  canvas.pushCanvas(X + cx, Y + cy, UPDATE_MODE_DU4);
  canvas.deleteCanvas();
}

void Textbox::addChar(char ch) {
  if (cursor >= MAX_SIZE) {
    return;
  }

  drawChar(ch);

  text.push_back(ch);
  cursor++;
}

void Textbox::deleteChar() {
  if (cursor <= 0) {
    return;
  }
  drawChar(' ');

  text.pop_back();
  cursor--;
}
