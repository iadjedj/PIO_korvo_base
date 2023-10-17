#ifndef KORVO_LCD_H
#define KORVO_LCD_H

#include "TFT_eSPI.h"
#include "Arduino.h"
#include "Wire.h"
#include "KorvoExpander.h"

class KorvoLCD : public TFT_eSPI {
    public:
        void init(KorvoExpander *expander);
        KorvoLCD(uint16_t width, uint16_t height);
        uint8_t getTouchRaw(uint16_t *x, uint16_t *y);
    private:
        KorvoExpander* _expander;
        void _init_lcd();
};

#endif