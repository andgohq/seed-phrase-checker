#include <keyboard.hpp>
#include <string>

static constexpr int startx[] = {12, 30, 78};
static constexpr int starty = 300;
static constexpr int textSize = 3;

static constexpr int n[] = {10, 10, 8};
static constexpr int w = 84;
static constexpr int h = 72;
static constexpr int gx = 6;
static constexpr int gy = 6;
static constexpr int cw = textSize * 6;
static constexpr int ch = textSize * 9;

typedef struct {
  int x;
  int y;
} point;

static const char keychar[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
                               'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '<',
                               'z', 'x', 'c', 'v', 'b', 'n', 'm', ' '};

static const char *keytop[] = {
    "Q", "W", "E", "R", "T", "Y",  "U", "I", "O", "P", "A", "S", "D", "F",
    "G", "H", "J", "K", "L", "BS", "Z", "X", "C", "V", "B", "N", "M", "SPACE",
};

void Keyboard::drawKeyboard() {
  M5EPD_Canvas canvas(&M5.EPD);

  canvas.createCanvas(960, (h + gy) * 3);

  int c = 0;
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < n[j]; i++) {
      int x = startx[j] + (w + gx) * i;
      int y = (h + gy) * j;
      addKey(canvas, x, y, c);
      c++;
    }
  }

  canvas.pushCanvas(0, starty, UPDATE_MODE_DU4);
  canvas.deleteCanvas();
}

void Keyboard::addKey(M5EPD_Canvas &canvas, int x, int y, int c) {
  int size = c == 27 ? 2 : 1;
  int len = strlen(keytop[c]);
  canvas.setTextSize(textSize);
  canvas.drawRect(x, y, w * size, h, 15);
  canvas.drawString(keytop[c], x + (w * size - cw * len) / 2, y + (h - ch) / 2);
}

void Keyboard::redrawKey() {
  M5EPD_Canvas canvas(&M5.EPD);

  while (!redrawList.empty()) {
    auto r = redrawList.front();
    redrawList.pop();
    canvas.createCanvas(w, h);
    addKey(canvas, 0, 0, r.c);
    canvas.pushCanvas(r.x, starty + r.y, UPDATE_MODE_DU4);
    canvas.deleteCanvas();
  }
}

char Keyboard::getKey() {
  static int i = 0;
  char ret = "void come effort suffer camp survey warrior heavy shoot "
             "primary clutch crush open amazing screen patrol group "
             "space point ten exist slush involve act #<<<<unfold "[i];
  if (ret != '\0') {
    i++;
    return ret;
  }

  M5EPD_Canvas canvas(&M5.EPD);

  static point prev[2];
  static char oldKey;

  if (M5.TP.avaliable() && !M5.TP.isFingerUp()) {
    M5.TP.update();
    for (int id = 0; id < 1; id++) {
      tp_finger_t p = M5.TP.readFinger(id);
      if ((prev[id].x != p.x) || (prev[id].y != p.y)) {
        prev[id].x = p.x;
        prev[id].y = p.y;

        int j = (p.y - starty) / (h + gy);
        j = j < 0 ? 0 : j;
        j = j > 2 ? 2 : j;
        int i = (p.x - startx[j]) / (w + gx);
        i = i < 0 ? 0 : i;
        i = i >= n[j] ? n[j] - 1 : i;
        int c = 0;
        if (j == 0) {
          c = i;
        } else if (j == 1) {
          c = n[0] + i;
        } else {
          c = n[0] + n[1] + i;
        }
        int x = startx[j] + (w + gx) * i;
        int y = (h + gy) * j;

        canvas.createCanvas(w, h);
        canvas.fillRect(0, 0, w, h, 15);
        canvas.pushCanvas(x, starty + y, UPDATE_MODE_DU4);
        canvas.deleteCanvas();

        redrawList.push({x, y, c});

        char key = keychar[c];

        return key;
      }
    }
  }
  return '\0';
}
