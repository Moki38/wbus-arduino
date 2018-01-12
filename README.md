# wbus-arduino

![Screenshot 1](http://wiki.team-moki.nl/download/attachments/16547884/IMG_0624.jpg?version=1&modificationDate=1514731941631&api=v2)

## Description

A Smart Controller for Webasto Heaters (currently only EVO-40 has been tested)

- Raspberry PI
- PlatformIO
- Teensy 3.6
- Webasto EVO-40
- OLED Yellow/Blue 128x64
- NXP MC33660 / MC33290

## If you use a Raspberry Pi like me, use these commands to setup your enviromment
```console
sudo su -
apt-get install -y locate htop git i2c-tools build-essential

cd 
wget https://downloads.arduino.cc/arduino-1.8.4-linuxarm.tar.xz 
cd /usr/share 
tar xfJ ~/arduino-1.8.4-linuxarm.tar.xz 
ln -s arduino-1.8.4 arduino

cd /etc/udev/rules.d/ 
wget https://github.com/platformio/platformio-core/blob/develop/scripts/99-platformio-udev.rules 
systemctl restart udev 

cd 
wget https://raw.githubusercontent.com/platformio/platformio/develop/scripts/get-platformio.py 
python get-platformio.py
pip install -U platformio 

git clone https://github.com/Moki38/wbus-arduino.git
cd wbus-arduino
```

## Installation
```console
pio init -b teensy36

pio lib install git+https://github.com/adafruit/Adafruit-GFX-Library
pio lib install git+https://github.com/adafruit/Adafruit_SSD1306
pio lib install git+https://github.com/PaulStoffregen/Encoder.git

pio run -t upload
```

## More documentation
http://wiki.team-moki.nl/display/MOK/Webasto+Teensy

