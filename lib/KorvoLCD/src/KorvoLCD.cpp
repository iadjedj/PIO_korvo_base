#include "KorvoLCD.h"

KorvoLCD::KorvoLCD(uint16_t width, uint16_t height) : TFT_eSPI(width, height) {}

void KorvoLCD::_init_lcd() {
  _expander->set_direction(PIN_PERI_PWR, EXPANDER_OUTPUT);
  _expander->set_pin(PIN_PERI_PWR, EXPANDER_HIGH);

  _expander->set_direction(PIN_LCD_CTRL, EXPANDER_OUTPUT);
  _expander->set_pin(PIN_LCD_CTRL, EXPANDER_HIGH);

  _expander->set_direction(PIN_LCD_CS, EXPANDER_OUTPUT);

  _expander->set_pin(PIN_LCD_CS, EXPANDER_HIGH);
  delay(10);
  _expander->set_pin(PIN_LCD_CS, EXPANDER_LOW);
  delay(10);

  // RST to LOW means reset
  _expander->set_direction(PIN_LCD_RST, EXPANDER_OUTPUT);
  _expander->set_pin(PIN_LCD_RST, EXPANDER_HIGH);
  delay(5);
  _expander->set_pin(PIN_LCD_RST, EXPANDER_LOW);
  delay(20);
  _expander->set_pin(PIN_LCD_RST, EXPANDER_HIGH);
}

void KorvoLCD::init(KorvoExpander *expander) {
    _expander = expander;
    _init_lcd();
    TFT_eSPI::init();
}
