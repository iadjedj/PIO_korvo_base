#ifndef KORVO_LCD_H
#define KORVO_LCD_H

#include "TFT_eSPI.h"
#include "Arduino.h"
#include "Wire.h"
#include <KorvoExpander.h>
#include <KorvoTouch.h>

class KorvoLCD : public TFT_eSPI {
    public:
        void init(KorvoExpander *expander = NULL, uint8_t tc = 0);  // Should not be used with a Korvo Display
        void begin(KorvoExpander *expander = NULL, uint8_t tc = 0); // Should not be used with a Korvo Display

        KorvoLCD();
        KorvoLCD(uint16_t width, uint16_t height);

        uint8_t getTouchRaw(uint16_t *x, uint16_t *y);
        uint16_t getTouchRawZ(void);
        uint8_t getTouch(uint16_t *x, uint16_t *y, uint16_t threshold = 15);
    private:
        KorvoExpander* _expander;
        KorvoTouch* _touch;
        void _init_lcd();
};

#endif