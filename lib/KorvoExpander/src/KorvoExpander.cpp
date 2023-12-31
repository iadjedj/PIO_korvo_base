#include "Wire.h"
#include "KorvoExpander.h"

bool KorvoExpander::_init = false;

void KorvoExpander::_write(int addr, int val) {
  _i2c->beginTransmission(TCA9554A_ADDR);
  _i2c->write(addr);
  _i2c->write(val);

  esp_err_t error = _i2c->endTransmission(true); // param: true : send a stop bit / false : restart
  return;
}

uint8_t KorvoExpander::_read(int addr) {
  _i2c->beginTransmission(TCA9554A_ADDR);
  _i2c->write(addr);
  esp_err_t error = _i2c->endTransmission(true);  // param: true : send a stop bit / false : restart

  uint8_t bytesReceived = _i2c->requestFrom(TCA9554A_ADDR, 1);
  uint8_t ret = _i2c->read();
  return ret;
}

KorvoExpander::KorvoExpander()
{
  _init = true;
}

void KorvoExpander::init() {
  if (!i2cIsInit(0)) {
    log_i("Calling Wire.begin() because I2C was not previously configured.");
    Wire.begin(17, 18);
  }
  _i2c = &Wire;

  if (_init) {
    return;
  }
  _write(TCA9554_CONFIGURATION_PORT, 0xFF); // All as Input (default)
  _write(TCA9554_OUTPUT_PORT, 0xFF);        // Output register all High (default)
}

void KorvoExpander::set_direction(expander_pin_t pin, expander_dir_t direction) {
  uint8_t val = _read(TCA9554_CONFIGURATION_PORT);
  if (direction == EXPANDER_INPUT)
    val |= (1 << pin);
  else
    val &= ~(1 << pin);

  _write(TCA9554_CONFIGURATION_PORT, val);
}

void KorvoExpander::set_pin(expander_pin_t pin, expander_state_t state) {
  uint8_t val = _read(TCA9554_OUTPUT_PORT);
  if (state)
    val |= (1 << pin);
  else
    val &= ~(1 << pin);

  _write(TCA9554_OUTPUT_PORT, val);
}
