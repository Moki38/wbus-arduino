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

#include "Main.h"
#include <Arduino.h> 

#ifdef SDCARD
#include <SD.h>
#include <SPI.h>
#endif

//
// Serial vars
//
String serial_command = "";
String command = "";
String value_string = "";
int value = 0;
boolean command_complete = false;

#ifdef SDCARD
Sdcard S;
#endif

Wbus W;
Webasto webasto;
Webasto_Setup webasto_setup; 

int webasto_time = 0;

void setup() {
    // Open serial communications and wait for port to open:
    Serial.begin(115200);
//    while (!Serial) {
//          ; // wait for serial port to connect. Needed for Leonardo only
//    }

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)

    webasto.timer = false;
    webasto.temp = 21;
    webasto.mode = 2;
    webasto.status_temp = 0;

    display.clearDisplay();

    Serial.println("Starting Webasto Controller...");

#ifdef SDCARD
    S.Init();
    S.Read(webasto_setup);
#endif

    W.Init();
}

void webasto_loop() {
    webasto_time = millis();

    W.Status(webasto);
    delay(100);
    W.Loop(webasto);
}

void printDigits(int digits) {
    // utility function for digital clock display: prints preceding colon and leading 0
    if (digits < 10) {
        display.print('0');
    }
    display.print(digits);
}

void loop() {
    int time = millis();
    time_t t = now();

    //
    // Every 10000 μs run the webasto loop
    //
    if (time >= (webasto_time + 2000)) {
        webasto_loop();
    }



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
//    printDigits(webasto.status_temp);
//    Serial.println(webasto.status_temp);
//    Serial.print("Main switch: ");
//    Serial.println(webasto.status_ms);
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

    if (command_complete) {
        serial_command.trim();
        int pos = serial_command.indexOf(':');
        command = serial_command.substring(0, pos);
        value_string = serial_command.substring(pos + 1);
        value = value_string.toInt();

        if (command == "TIME") {
            setTime(value);
        }

        if (command == "W_ON") {
            W.On(webasto,value);
        }

        if (command == "W_OFF") {
            W.Off(webasto);
        }

#ifndef DEBUG
            Serial.print("Command: ");
            Serial.print(command);
            Serial.print(" Value: ");
            Serial.println(value);
#endif
        serial_command = "";
        command_complete = false;
    }
}

void serialEvent()
{
    while (Serial.available()) {
        // get the new byte:
        char inChar = (char) Serial.read();
        // add it to the inputString:
        serial_command += inChar;
        // if the incoming character is a newline, set a flag
        // so the main loop can do something about it:
        if (inChar == '\n') {
            command_complete = true;
        }
    }
}

void serialEvent1(){
    if (Serial1.available() > 0) {
        W.Gather(webasto,Serial1.read());
    }
}

