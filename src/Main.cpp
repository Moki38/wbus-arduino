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

//
// Serial vars
//
String serial_command = "";
String command = "";
String value_string = "";
int value = 0;
boolean command_complete = false;

//
// Encoder
//
Encoder myEnc(ROT_PIN_A, ROT_PIN_B);
long oldPosition  = -999;

//
// Button
//
int buttonState = 0;
int oldbuttonState = 0;

#ifdef SDCARD
Sdcard S;
#endif

#ifdef DISPLAY
Display D;
#endif
int display_time = 0;

Wbus W;
Webasto webasto;
Webasto_Setup webasto_setup; 
int webasto_time = 0;


Led L;
Menu M;
Button B;

void setup() {
    // Open serial communications
    Serial.begin(115200);

    webasto.timer = false;
    webasto.temp = 21;
    webasto.mode = 2;
    webasto.status_temp = 21;

#ifdef DEBUG
    Serial.println("Starting Webasto Controller...");
#endif

#ifdef DISPLAY
    D.Init();
#endif

#ifdef SDCARD
    S.Init();
    S.Read(webasto_setup);
#endif

    B.Init();
    M.Init();
    L.Init();

    W.Init();
}

void webasto_off() {
    W.Off(webasto);
}

void webasto_loop() {
    webasto_time = millis();

    W.Status(webasto);
    Alarm.delay(100);
//
// Frost protection
// 
    if (webasto.status_temp < 5) {

//
// Turn On Heater (at 10'C)
//
        W.On(webasto, 10);
        Alarm.delay(100);

//
// Set an Alarm to stop after 1 hour (3600 seconds) running time.
//
        webasto.frostalarm = Alarm.timerOnce(3600, webasto_off);
    }
//
// or if temperature has already reached 10'C
//
    if (Alarm.isAlarm(webasto.frostalarm)) {
        if(webasto.status_temp >= 10) {
            Alarm.free(webasto.frostalarm);
            webasto_off();
        }
    }

//
// Webasto Loop
//
    W.Loop(webasto);
}

void display_loop() {
    display_time = millis();

#ifdef DISPLAY
//
// Display Status
//    
    D.Print(webasto);

#endif
}

void loop() {
    int time = millis();

    //
    // Every 2000 μs run the webasto loop
    //
    if (time >= (webasto_time + 2000)) {
        webasto_loop();
    }

    //
    // Every 2000 μs run the display loop
    //
    if (time >= (display_time + 2000)) {
        display_loop();
    }

//
// Button Loop
//
    buttonState = digitalRead(ROT_BUTTON);
    if (buttonState != oldbuttonState) {

        // HIGH == Button Pushed
        if (buttonState == HIGH) {
        } else {
        // LOW == Button Released
        }
    }

#ifdef ROTARY_ENCODER
//
// Encoder Loop
//
    long newPosition = myEnc.read();
    if (newPosition != oldPosition) {
        oldPosition = newPosition;
        Serial.print("Rotary Encoder Position: ");
        Serial.println(newPosition);
    }
#endif //ROTARY_ENCODER
//
// Parse commands send to us on /dev/ACM0
//
    if (command_complete) {
        serial_command.trim();
        int pos = serial_command.indexOf(':');
        command = serial_command.substring(0, pos);
        value_string = serial_command.substring(pos + 1);
        value = value_string.toInt();

//
// Example UTC + 1
//
// t=`date +%s` ; s=`echo -n "DATE:" ; expr $t + 3600` ; echo $s > /dev/ttyACM0
//
        if (command == "DATE") {
            setTime(value);
        }

        if (command == "W_ON") {
            W.On(webasto,value);
        }

        if (command == "W_OFF") {
            W.Off(webasto);
        }

#if DEBUG == 2
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

