#include "Form.h"
Form* Form::currentForm;

Form::Form(Adafruit_TFTLCD *tft, TouchScreen *ts) {
  this->_tft = tft;
  this->_ts = ts;
}

void Form::update(void) {
  bool anythingHappened = false;
  TSPoint p = _ts->getPoint();
  if(p.z > _ts->pressureThreshhold) {
    for(byte i=0;i<_numButtons;i++) {
      if(_buttons[i]->isPressed(p)) {
        anythingHappened = true;
        _buttons[i]->doCallback();
      }
    }
  }

  if(anythingHappened) {
    draw();
  }
}

void Form::addControl(Button *b) {
  _buttons[_numButtons] = b;
  _numButtons++;
}

void Form::show() {
  Form::currentForm = this;
  draw();
}

void Form::draw() {
  for(byte i=0;i<_numButtons;i++){
    _buttons[i]->draw(_tft);
  }
}

