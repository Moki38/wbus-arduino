# wbus-arduino

![Screenshot 1](http://wiki.team-moki.nl/download/attachments/16547884/IMG_0624.jpg?version=1&modificationDate=1514731941631&api=v2)

## Description

A Smart Controller for Webasto Heaters (currently only EVO-40 has been tested)

Raspberry PI
PlatformIO
Teensy 3.6
Webasto EVO-40
OLED Yellow/Blue 128x32
NXP MC33660 / MC33290

## Installation
```console
pio init -b teensy36

platformio lib install git+https://github.com/adafruit/Adafruit-GFX-Library
platformio lib install git+https://github.com/adafruit/Adafruit_SSD1306

pio run -t upload
```

## More documentation
http://wiki.team-moki.nl/display/MOK/Webasto+Teensy


