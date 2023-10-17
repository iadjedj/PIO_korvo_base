#include "Arduino.h"
#include "Wire.h"

#include <KorvoLCD.h>
#include <KorvoExpander.h>

static const char* TAG = "Main";

KorvoLCD      tft(320, 240);
KorvoExpander expander;

void setup()
{
	// put your setup code here, to run once:
	Serial.begin(115200);

	Wire.begin(17, 18);

	expander.init(&Wire);

	tft.init(&Wire, &expander);
	tft.setRotation(4);
	tft.fillScreen(TFT_BLACK);

	tft.drawString("Hello you!", 10, 10);
}

void loop()
{
	uint16_t t_x, t_y; // To store the touch coordinates

	if (tft.getTouch(&t_x, &t_y))
	{
		int32_t size = map(tft.getTouchRawZ(), 10, 50, 2, 10);

		tft.fillCircle(t_x, t_y, size, tft.color565(59, 161, 112));

		// printf(">touch:%d:%d:%d|xy\n", t_x, t_y, millis());
	}

	delay(20);
}