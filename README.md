# ESP32 Korvo PlatforIO

Base project for PlatformIO using the ESP32S3 Korvo 2 board

# Useful links

- **Korvo Board**:
	- Main Board:
		- ["Documentation"](https://docs.espressif.com/projects/esp-adf/en/latest/design-guide/dev-boards/user-guide-esp32-s3-korvo-2.html)
		- [Schematic](https://dl.espressif.com/dl/schematics/SCH_ESP32-S3-KORVO-2_V3_0_20210918.pdf)
	- LCD + Cam:
		- [""Documentation""](https://docs.espressif.com/projects/esp-adf/en/latest/design-guide/dev-boards/user-guide-esp32-s3-korvo-2-lcd.html)
		- [Schematic](https://dl.espressif.com/dl/schematics/SCH_ESP32-S3-KORVO-2-LCD_V1.0_20210918.pdf)
	
- **Frameworks**
	- [GitHub : Arduino ESP32 Framework](https://github.com/espressif/arduino-esp32)
	- [Documentation : esp-idf for ESP32S3](https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/index.html)
	- [GitHub : esp-idf](https://github.com/espressif/esp-idf/)
- **Librairies**
	- [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI/) 
	- [TFT_eWidget](https://github.com/Bodmer/TFT_eWidget/)

# Folder structure

```
	.
	|__ .pio/
		|__ build/
		|__ libdeps/
	|__ .vscode/
		|__ extensions.json
	|__ include/
	|__ boards/
		|__ korvo_board.json
	|__ lib/
		|__ KorvoExpander/
		|__ KorvoLCD/
		|__ KorvoTouch/
	|__ src/
		|__ main.cpp
	|__ .gitignore
	|__ platformio.ini
	|__ README.md
```