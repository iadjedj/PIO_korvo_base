#ifndef KORVO_TOUCH_H
#define KORVO_TOUCH_H

#include "Wire.h"

/*
Sources :
 https://github.com/jessebraham/tt21100/blob/main/src/lib.rs#L125
 https://github.com/espressif/esp-iot-solution/blob/master/examples/extended_vfs/i2c/i2c_tt21100/main/i2c_tt21100_main.c

 uPython: https://github.com/adafruit/Adafruit_CircuitPython_TT21100/blob/b3113a4/adafruit_tt21100.py#L59-L63
*/

#define TT211X_ADDR 0x24

struct Point {
    uint16_t x;
    uint16_t y;
    uint8_t z; // Supposed to be "pressure" not very reliable
};

class KorvoTouch {
  public:
    KorvoTouch(TwoWire*);
    void refresh();
    uint8_t nb_touch;
    Point pt1, pt2;
  private:
    TwoWire *_i2c;
};

#endif