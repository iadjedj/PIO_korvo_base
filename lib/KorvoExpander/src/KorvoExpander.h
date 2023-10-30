/*
Source :
https://github.com/espressif/esp-adf/blob/ef058dac1fb53d73b354ed8e7b2ae873e09fd937/components/audio_board/esp32_s3_korvo2_v3/board.c#L88
https://github.com/espressif/esp-adf/blob/master/components/esp_peripherals/lib/tca9554/tca9554.c
https://www.ti.com/lit/ds/symlink/tca9554a.pdf
*/

#ifndef KORVO_EXPANDER_H
#define KORVO_EXPANDER_H

#include "Wire.h"

#define TCA9554A_ADDR 0x38

#define TCA9554_INPUT_PORT              0x00
#define TCA9554_OUTPUT_PORT             0x01
#define TCA9554_POLARITY_INVERSION_PORT 0x02
#define TCA9554_CONFIGURATION_PORT      0x03

typedef enum {
  PIN_PA_CTRL = 0,// Power Amplifier (Sound) ON/OFF
  PIN_LCD_CTRL,
  PIN_LCD_RST,
  PIN_LCD_CS,
  PIN_TP_INT,
  PIN_PERI_PWR, // Alim LCD + Camera
  PIN_RED_LED,
  PIN_BLUE_LED
} expander_pin_t;


typedef enum {
    EXPANDER_INPUT,
    EXPANDER_OUTPUT,
} expander_dir_t;

typedef enum {
    EXPANDER_LOW,
    EXPANDER_HIGH,
} expander_state_t;

class KorvoExpander {
  public:
    KorvoExpander();
    void init();
    void set_direction(expander_pin_t pin, expander_dir_t direction);
    void set_pin(expander_pin_t pin, expander_state_t state);
    // expander_state_t read_pin(expander_pin_t pin);
  private:
    static bool _init;
    void _write(int addr, int val);
    uint8_t _read(int addr);
    TwoWire *_i2c;
};

#endif