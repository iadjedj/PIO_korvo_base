#include "Arduino.h"
#include "Wire.h"
#include <KorvoLCD.h>
#include <KorvoExpander.h>
#include <TFT_eWidget.h>
#include "salut_bmp.h"

KorvoExpander expander;
KorvoLCD tft(320, 240);


// GraphWidget gr = GraphWidget(&tft);    // Graph widget gr instance with pointer to tft
// TraceWidget tr = TraceWidget(&gr);     // Graph trace tr with pointer to gr


float cur_x;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Wire.begin(17, 18);

  expander.init(&Wire);
  expander.set_direction(PIN_RED_LED, EXPANDER_OUTPUT);

  tft.init(&expander);
  tft.setRotation(4);

  tft.fillScreen(TFT_BLACK);

  // gr.createGraph(320, 120, tft.color565(20, 20, 20));

  // gr.setGraphScale(-5.0, 5.0, 0.0, 5.0);

  // gr.setGraphGrid(-5.0, 0.2, 0.0, 1.0, tft.color565(120, 120, 120));

  // // Draw empty graph, top left corner at pixel coordinate 0,0
  // gr.drawGraph(0, 0);
  // tr.startTrace(TFT_WHITE);

  // cur_x = -5.0;

  tft.pushImage(0, 0, 320, 240, (uint16_t*)my_bitmap);
}

void loop() {
  // tr.addPoint(cur_x, (float)esp_random()/(UINT32_MAX / 5));
  // cur_x += 0.1;

  // if (cur_x >= 5.0) {
  //   cur_x = -5.0;
  //   gr.drawGraph(0, 0);
  //   tr.startTrace(TFT_WHITE);
  // }
  // vTaskDelay(pdMS_TO_TICKS(5));
}
