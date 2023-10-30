#include "KorvoLCD.h"

KorvoLCD::KorvoLCD(uint16_t width, uint16_t height) : TFT_eSPI(width, height) {}
KorvoLCD::KorvoLCD() : TFT_eSPI(320, 240) {}

void KorvoLCD::_init_lcd() {
	// Turn ON Peripheral Power
	_expander->set_direction(PIN_PERI_PWR, EXPANDER_OUTPUT);
	_expander->set_pin(PIN_PERI_PWR, EXPANDER_LOW); // PERI_PWR_ON	=	L，	PER_VCC_3V3	= ON

	// ?
	_expander->set_direction(PIN_LCD_CTRL, EXPANDER_OUTPUT);
	_expander->set_pin(PIN_LCD_CTRL, EXPANDER_HIGH);

	// Chip Select LCD
	_expander->set_direction(PIN_LCD_CS, EXPANDER_OUTPUT);
	_expander->set_pin(PIN_LCD_CS, EXPANDER_HIGH);
	delay(10);
	_expander->set_pin(PIN_LCD_CS, EXPANDER_LOW);
	delay(10);

	// RST to LOW means reset (both LCD and Touch)
	_expander->set_direction(PIN_LCD_RST, EXPANDER_OUTPUT);
	_expander->set_pin(PIN_LCD_RST, EXPANDER_HIGH);
	delay(5);
	_expander->set_pin(PIN_LCD_RST, EXPANDER_LOW);
	delay(20);
	_expander->set_pin(PIN_LCD_RST, EXPANDER_HIGH);
}

uint8_t KorvoLCD::getTouch(uint16_t *x, uint16_t *y, uint16_t threshold) {
	_touch->refresh();

	if (_touch->nb_touch > 0) {
		*x = _width - _touch->pt1.x;
		*y = _touch->pt1.y;
		return (_touch->pt1.z > threshold);
	}
	return false;
}

uint8_t KorvoLCD::getTouchRaw(uint16_t *x, uint16_t *y) {
	_touch->refresh();
	
	if (_touch->nb_touch > 0) {
		*x = _width - _touch->pt1.x;
		*y = _touch->pt1.y;
	}
	return true;
}

uint16_t KorvoLCD::getTouchRawZ(void) {
	// FIXME: Find a better way to handle the refresh process
	// _touch->refresh();

	if (_touch->nb_touch == 0)
		return 0;

	return (uint16_t)_touch->pt1.z;
}

void KorvoLCD::init(KorvoExpander *expander, uint8_t tc) {
	// Not the cleaniest way to handle Wire
	// but ensure compatibility with original TFT_eSPI::init()
	if (!i2cIsInit(0)) {
		log_i("Calling Wire.begin() because I2C was not previously configured.");
		Wire.begin(17, 18);
	}
	if (expander)
		_expander = expander;
	else {
		_expander = new KorvoExpander();
		_expander->init();
	}
	_touch = new KorvoTouch(&Wire);
	_init_lcd();
	TFT_eSPI::init();
}

void KorvoLCD::begin(KorvoExpander *expander, uint8_t tc) {
	init(expander);
}