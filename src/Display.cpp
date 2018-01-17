/*
 Copyright (C) 2018 Eric van Dijken <eric@team-moki.nl>
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
*/

#include "Display.h"

#if DISPLAY_TYPE == 1
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#endif

//
// Display Init 
//
void Display::Init() {

#if DISPLAY_TYPE == 1
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
    display.clearDisplay();
#endif

}

void Display::printDigits(int digits) {
    // utility function for digital clock display: prints preceding colon and leading 0
    if (digits < 10) {
#if DISPLAY_TYPE == 1
        display.print('0');
#endif
    }
#if DISPLAY_TYPE == 1
    display.print(digits);
#endif
}

//
// Display Print
//
void Display::Print(Webasto &webasto) {

    time_t t = now();

#if DISPLAY_TYPE == 1
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);

    display.setCursor(0,0);

    if (webasto.timer) {
        display.setTextColor(BLACK, WHITE); // 'inverted' text
    } else {
        display.setTextColor(WHITE);
    }
    display.print("T");
    display.setTextColor(WHITE);


    display.setCursor(20,0);
    display.print(webasto.status_temp);
    display.print("'C");

    display.setCursor(68,0);
    display.print(dayShortStr(weekday()));

    display.setCursor(94,0);
    printDigits(hour(t));
    display.print(":");
    printDigits(minute(t));


    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(20,8);
    switch(webasto.mode) {
        case 1:
            display.drawBitmap(24, 8,  power1_bmp, 8, 16, 1);
            break;
        case 2:
            display.drawBitmap(20, 8,  power1_bmp, 8, 16, 1);
            display.drawBitmap(28, 8,  power1_bmp, 8, 16, 1);
            break;
        case 3:
            display.drawBitmap(16, 8,  power1_bmp, 8, 16, 1);
            display.drawBitmap(24, 8,  power1_bmp, 8, 16, 1);
            display.drawBitmap(32, 8,  power1_bmp, 8, 16, 1);
            break;
    }


    display.setCursor(70,8);
    display.print(webasto.temp);
    display.setTextSize(1);
    display.print("o");
    display.setTextSize(2);
    display.println("C");
    display.setTextSize(1);

    display.setCursor(0,24);
    display.print(webasto.status_os,HEX);

    display.setCursor(20,24);
    display.print("Power: ");
    display.print(webasto.status_hp);
    display.println("W");

    display.display();
#endif

#if DEBUG == 1
    Serial.print("Webasto Room Temp: ");
    Serial.println(webasto.status_temp);
    Serial.print("Webasto Set Temp: ");
    Serial.println(webasto.temp);
    Serial.print("Webasto Mode: ");
    switch(webasto.mode) {
        case 1:
            Serial.println("ECO");
            break;
        case 2:
            Serial.println("NORMAL");
            break;
        case 3:
            Serial.println("BOOST");
            break;
    }

    Serial.print("Webasto Status: ");
    Serial.println(webasto.status_os,HEX);
    Serial.print("Webasto Status Text: ");
    Serial.println(webasto.status_os_long);

    Serial.print("Main Switch: ");
    Serial.println(webasto.status_ms);
    Serial.print("Suplemental heater request: ");
    Serial.println(webasto.status_shr);

    Serial.print("Voltage (V): ");
    Serial.println(webasto.status_mvolt);
    Serial.print("Flame detector: ");
    Serial.println(webasto.status_fd);
    Serial.print("Heating power (W): ");
    Serial.println(webasto.status_hp);
    Serial.print("Flame detector resistance (m Ohm): ");
    Serial.println(webasto.status_fdr);

    Serial.print("Glow plug power: ");
    Serial.println(webasto.status_gpp);
    Serial.print("Fuel pump pulse frequency: ");
    Serial.println(webasto.status_fpf);
    Serial.print("Combustion air fan: ");
    Serial.println(webasto.status_afp);

#endif

}
