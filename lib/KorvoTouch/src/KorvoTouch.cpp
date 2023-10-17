#include "Wire.h"
#include "KorvoTouch.h"

static const char* TAG = "KorvoTouch";

void KorvoTouch::_write(int addr, int val) {
	_i2c->beginTransmission(TT211X_ADDR);
	_i2c->write(addr);
	_i2c->write(val);

	_i2c->endTransmission(true);
	return;
}

uint8_t* KorvoTouch::_read(int addr, int len) {
	uint8_t buff[len];

	_i2c->requestFrom(TT211X_ADDR, len);
	_i2c->readBytes(buff, len);
	return buff;
}

void KorvoTouch::refresh() {
	// Todo: Add reset when no touch
	
	_i2c->beginTransmission(TT211X_ADDR);
	esp_err_t error = _i2c->endTransmission(true);  // param: true : send a stop bit / false : restart

	// The two first avalaible bytes are the size of the rest of the paquet
	uint8_t bytesReceived = _i2c->requestFrom(TT211X_ADDR, 2);

	if (bytesReceived > 0) {  //If received more than zero bytes
		uint8_t buff[bytesReceived] = { 0 };
		_i2c->readBytes(buff, bytesReceived);

		uint16_t to_read = buff[0] + (buff[1] << 8);

		_i2c->requestFrom(TT211X_ADDR, to_read);

		uint8_t data[to_read];

		_i2c->readBytes(data, to_read);

		if (to_read == 14)  // skip red btn
		return;

		// Can be written in a better way
		nb_touch = to_read / 10;

		if (nb_touch > 0) {
			pt1.x = data[9] + (data[10] << 8);
			pt1.y = data[11] + (data[12] << 8);
			pt1.z = data[13];
		}
		if (nb_touch > 1) {
			pt2.x = data[19] + (data[20] << 8);
			pt2.y = data[21] + (data[22] << 8);
			pt2.z = data[23];
		}
	}
}

KorvoTouch::KorvoTouch(TwoWire *i2c) : _i2c(i2c)
{
    ESP_LOGI(TAG, "Initialized!");
}