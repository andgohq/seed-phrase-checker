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

  canvas.createCanvas(W, CHAR_H * TEXT_SIZE);
  canvas.setTextSize(TEXT_SIZE);
  canvas.drawString(message.c_str(), 0, 0);
  canvas.pushCanvas(X, Y + CHAR_H * TEXT_SIZE * 6, UPDATE_MODE_DU4);
  canvas.deleteCanvas();
}

int Textbox::getWordCount() { return wordCount; }
