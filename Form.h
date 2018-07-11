#ifndef __FORM_H__
#define __FORM_H__

#include "Arduino.h"
#include "TouchScreen.h"

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library

#include "Button.h"

#define MAX_BUTTONS 10

class Form {
  public:
    Form(Adafruit_TFTLCD *tft, TouchScreen *ts);
    
    void update(void);

    void addControl(Button *b);

    void show(void);
    void draw(void);

    static Form *currentForm;

  private:
    Adafruit_TFTLCD *_tft;
    TouchScreen *_ts;
    Button *_buttons[MAX_BUTTONS];
    byte _numButtons;
};

#endif
