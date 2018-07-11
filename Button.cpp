#include "Button.h"

Button::Button() {
  _x = 0;
  _y = 0;
  _width = 100;
  _height = 20;
  _text = F("Button");
  _textSize = 3;
}

Button::Button(int x, int y, int width, int height, String text, byte textSize) {
  _x = x;
  _y = y;
  _width = width;
  _height = height;
  _text = text;
  _textSize = textSize;
}

void Button::setLocation(int x, int y) {
  _x = x;
  _y = y;
}

void Button::setSize(int width, int height) {
  _width = width;
  _height = height;
}

bool Button::isPressed(TSPoint p) {
  return p.x >= _x && p.y >= _y && p.x < _x + _width && p.y < _y + _height;
}

void Button::registerCallback(void (*callback)(void)) {
  _callback = callback;
}

void Button::doCallback(void) {
  _callback();
}

void Button::draw(Adafruit_TFTLCD *tft) {
  tft->drawRect(_x, _y, _width, _height, BLACK);
}

