#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "Arduino.h"

#include "TouchScreen.h"
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library

#include "Colors.h"

class Button {
  public:
    Button(void);
    Button(int x, int y, int width, int height, String text, byte textSize);

    void setLocation(int x, int y);
    void setSize(int width, int height);

    bool isPressed(TSPoint p);

    void registerCallback(void (*callback)(void));
    void doCallback(void);

    void draw(Adafruit_TFTLCD *tft);

  private:
    int _x,_y, _width, _height;
    byte _textSize;
    String _text;
    void (*_callback)(void);
};

#endif
