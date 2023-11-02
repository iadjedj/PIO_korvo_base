#include "Arduino.h"

#include <KorvoLCD.h>

KorvoLCD tft(320, 240);

void setup()
{
	Serial.begin(115200);

	tft.init();
	tft.setRotation(4);
	tft.fillScreen(TFT_BLACK);

	tft.drawString("Hello you!", 10, 10);
}

void loop()
{
	uint16_t t_x, t_y; // To store the touch coordinates

	if (tft.getTouch(&t_x, &t_y))
	{
		uint8_t size = map(tft.getTouchRawZ(), 10, 50, 2, 10);

		tft.fillCircle(t_x, t_y, size, tft.color565(59, 161, 112));

		// printf(">touch:%d:%d|xy\n", t_x, t_y);
	}

	delay(20);
}