# wbus-arduino

Raspberry PI

PlatformIO

Teensy 3.6

Webasto EVO-40

OLED Yellow/Blue 128x32

NXP MC33660 / MC33290


```
Install:

platformio init -b teensy3.6

platformio lib install git+https://github.com/adafruit/Adafruit-GFX-Library
platformio lib install git+https://github.com/adafruit/Adafruit_SSD1306

platformio run -t upload


```
Set Arduino/Teensy Time:

t=`date +%s` ; s=`echo -n "TIME:" ; expr $t + 3600` ; echo $s > /dev/ttyACM0

