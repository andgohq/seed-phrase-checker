#include <cmath>
#include <string>

#include <textbox.hpp>

std::string Textbox::getText() { return text; }

std::vector<std::string> Textbox::getWords() {
  std::vector<std::string> elems;
  std::string item;
  for (char ch : text) {
    if (ch == ' ') {
      if (!item.empty())
        elems.push_back(item);
      item.clear();
    } else {
      item += ch;
    }
  }
  if (!item.empty())
    elems.push_back(item);
  return std::move(elems);
}

void Textbox::drawChar(char *str) {
  M5EPD_Canvas canvas(&M5.EPD);

  int cx = CHAR_W * cursor % W;
  int cy = CHAR_W * cursor / W * CHAR_H;

  if (cx + 2 * CHAR_W < W) {
    canvas.createCanvas(CHAR_W * 2, CHAR_H);
    canvas.setTextSize(TEXT_SIZE);
    canvas.drawString(str, 0, 0);
    canvas.pushCanvas(X + cx, Y + cy, UPDATE_MODE_DU4);
    canvas.deleteCanvas();
  } else {
    char buf1[] = {str[0], '\0'};
    canvas.createCanvas(CHAR_W, CHAR_H);

    canvas.setTextSize(TEXT_SIZE);
    canvas.drawString(buf1, 0, 0);
    canvas.pushCanvas(X + cx, Y + cy, UPDATE_MODE_DU4);

    char buf2[] = {str[1], '\0'};
    canvas.setTextSize(TEXT_SIZE);
    canvas.drawString(buf2, 0, 0);
    canvas.pushCanvas(X, Y + cy + CHAR_H, UPDATE_MODE_DU4);

    canvas.deleteCanvas();
  }
}

void Textbox::addChar(char ch) {
  if (cursor >= MAX_SIZE) {
    return;
  }

  char str[2] = {ch, '_'};
  drawChar(str);

  if (ch == ' ' && (text.length() > 0 && text.back() != ' ')) {
    incWordCount();
  }

  text.push_back(ch);
  cursor++;
}

void Textbox::deleteChar() {
  if (cursor <= 0) {
    return;
  }

  char ch = text.back();
  text.pop_back();
  cursor--;

  if (ch == ' ' && (text.length() > 0 && text.back() != ' ')) {
    decWordCount();
  }

  char str[2] = {'_', ' '};
  drawChar(str);
}

void Textbox::incWordCount() {
  wordCount++;
  updatedWordCount = true;
}

void Textbox::decWordCount() {
  wordCount--;
  updatedWordCount = true;
}

bool Textbox::isWordCountUpdated() {
  if (updatedWordCount == true) {
    updatedWordCount = false;
    return true;
  }
  return false;
}

void Textbox::showMessage(std::string message) {
  M5EPD_Canvas canvas(&M5.EPD);

  canvas.createCanvas(W, CHAR_H);
  canvas.setTextSize(TEXT_SIZE);
  canvas.drawString(message.c_str(), 0, 0);
  canvas.pushCanvas(X, Y + CHAR_H * 6, UPDATE_MODE_DU4);
  canvas.deleteCanvas();
}

int Textbox::getWordCount() { return wordCount; }

void Textbox::wipe() {
  M5EPD_Canvas canvas(&M5.EPD);
  canvas.createCanvas(W, CHAR_H * 7);

  for (int j = 0; j < 5; j++) {
    canvas.setTextSize(TEXT_SIZE);

    text.clear();
    for (int i = 0; i < MAX_SIZE; i++) {
      text.append(1, 'a' + (char)((float)(rand()) / RAND_MAX * 25));
    }
    for (int i = 0; i < 6; i++) {
      canvas.drawString(text.substr(i * (W / CHAR_W), W / CHAR_W).c_str(), 0,
                        i * CHAR_H);
    }

    canvas.pushCanvas(X, Y, UPDATE_MODE_DU4);
    canvas.clear();

    delay(1);
  }
  M5.EPD.Clear(true);
  canvas.deleteCanvas();
}