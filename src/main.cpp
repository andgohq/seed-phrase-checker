#include "keyboard.hpp"
#include "textbox.hpp"
#include <M5EPD.h>

M5EPD_Canvas canvas(&M5.EPD);
Textbox textbox;

void setup() {
  M5.begin();
  M5.EPD.SetRotation(0);
  M5.EPD.Clear(true);
  M5.RTC.begin();

  Serial.begin(115200);

  canvas.createCanvas(960, 540);
  canvas.drawRect(10, 10, 30, 50, 15);
  canvas.setTextSize(1);
  canvas.drawString("Hello World/\\good Morning", 0, 0);
  canvas.setTextSize(2);
  canvas.drawString("Hello World/\\good Morning", 0, 9);
  canvas.setTextSize(3);
  canvas.drawString("Hello World/\\good Morning", 0, 27);
  canvas.setTextSize(4);
  canvas.drawString("Hello World/\\good Morning", 0, 63);
  canvas.setTextSize(5);
  canvas.drawString("Hello World/\\good sfwarz", 0, 108);
  canvas.pushCanvas(0, 0, UPDATE_MODE_DU4);
  canvas.deleteCanvas();

  drawKeyboard();
}

void loop() {

  char c = getKey();
  if (c == '<') {
    Serial.println("backspace");
    textbox.deleteChar();
  } else if (c != 0) {
    textbox.addChar(c);
  }
}