#include "textbox.hpp"

#include <string>

std::string Textbox::getText() { return text; }

void Textbox::drawChar(char *str) {
  M5EPD_Canvas canvas(&M5.EPD);

  int cx = CHAR_W * TEXT_SIZE * cursor % (W - CHAR_W * TEXT_SIZE);
  int cy = CHAR_W * TEXT_SIZE * cursor / (W - CHAR_W * TEXT_SIZE) * CHAR_H *
           TEXT_SIZE;

  if (cx + 2 * CHAR_W * TEXT_SIZE < W) {
    canvas.createCanvas(CHAR_W * TEXT_SIZE * 2, CHAR_H * TEXT_SIZE);
    canvas.setTextSize(TEXT_SIZE);
    canvas.drawString(str, 0, 0);
    canvas.pushCanvas(X + cx, Y + cy, UPDATE_MODE_DU4);
    canvas.deleteCanvas();
  } else {
    char buf1[] = {str[0], '\0'};
    canvas.createCanvas(CHAR_W * TEXT_SIZE, CHAR_H * TEXT_SIZE);

    canvas.setTextSize(TEXT_SIZE);
    canvas.drawString(buf1, 0, 0);
    canvas.pushCanvas(X + cx, Y + cy, UPDATE_MODE_DU4);

    char buf2[] = {str[1], '\0'};
    canvas.setTextSize(TEXT_SIZE);
    canvas.drawString(buf2, 0, 0);
    canvas.pushCanvas(X, Y + cy + CHAR_H * TEXT_SIZE, UPDATE_MODE_DU4);

    canvas.deleteCanvas();
  }
}

void Textbox::addChar(char ch) {
  if (cursor >= MAX_SIZE) {
    return;
  }

  char str[2] = {ch, '_'};
  drawChar(str);

  text.push_back(ch);
  cursor++;
}

void Textbox::deleteChar() {
  if (cursor <= 0) {
    return;
  }
  text.pop_back();
  cursor--;

  char str[2] = {'_', ' '};
  drawChar(str);
}
