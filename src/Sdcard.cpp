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
#include "Sdcard.h"

//
// String vars
//
String sdcard_line = "";
String sd_command = "";
String sd_value_str = "";
byte sd_value;

//
// Set Sdcard Init 
//
void Sdcard::Init() {
    Serial.print("Initializing SD card...");

    if (!SD.begin(chipSelect)) {
        Serial.println("initialization failed!");
        return;
    }
    Serial.println("initialization done.");
}

//
// Set Sdcard Read
//
void Sdcard::Read() {
  // re-open the file for reading:
  myFile = SD.open("webasto.txt");
  if (myFile) {
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
        sdcard_line = myFile.read();

        sdcard_line.trim();
        int pos = sdcard_line.indexOf(':');
        sd_command = sdcard_line.substring(0, pos);
        sd_value_str = sdcard_line.substring(pos + 1);
        sd_value = sd_value_str.toInt();


    }
    // close the file:
    myFile.close();
  } else {
        // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

//
// Sdcard Read (Webasto_Setup)
//
void Sdcard::Read(Webasto_Setup &webasto_setup) {
    if (SD.exists("webasto.001")) {
        Serial.println("webasto.001 exists.");
        while (myFile.available()) {
            Serial.write(myFile.read());
        }
        // close the file:
        myFile.close();
    } else {
        Serial.println("webasto.001 doesn't exist.");
    }
}

//
// Sdcard Write (Webasto_Setup)
//
void Sdcard::Write(Webasto_Setup &webasto_setup) {
    if (SD.exists("webasto.001")) {
        Serial.println("webasto.001 exists.");
        SD.remove("webasto.001");
    } else {
        Serial.println("webasto.001 doesn't exist.");
    }
  
    myFile = SD.open("webasto.001", FILE_WRITE);

    if (myFile) {
        myFile.print("Heater_Type:");
        myFile.println(webasto_setup.Heater_Type);
        myFile.print("Timer_Active:");
        myFile.println(webasto_setup.Timer_Active);
        // close the file:
        myFile.close();
    } else {
        // if the file didn't open, print an error:
        Serial.println("error opening webasto.001");
    }
}


//
// Set Sdcard Write
//
void Sdcard::Write() {
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
        // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

}
