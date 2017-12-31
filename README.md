# wbus-arduino

Webasto EVO-40
Teensy 3.6
OLED Yellow/Blue 128x32
MC33660

```
Install

platformio init -b teensy3.6

platformio lib install git+https://github.com/adafruit/Adafruit-GFX-Library
platformio lib install git+https://github.com/adafruit/Adafruit_SSD1306

platformio run -t upload

