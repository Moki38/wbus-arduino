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
#include "Led.h"

//
// Led Init 
//
void Led::Init() {
    pinMode(LED_PIN_R, OUTPUT);
    pinMode(LED_PIN_G, OUTPUT);
    pinMode(LED_PIN_B, OUTPUT);
}

//
// Led_R_On
//
void Led::Led_R_On() {
    digitalWrite(LED_PIN_R, HIGH);
}

//
// Led_G_On
//
void Led::Led_G_On() {
    digitalWrite(LED_PIN_G, HIGH);
}

//
// Led_B_On
//
void Led::Led_B_On() {
    digitalWrite(LED_PIN_B, HIGH);
}

//
// Led_R_Off
//
void Led::Led_R_Off() {
    digitalWrite(LED_PIN_R, LOW);
}

//
// Led_G_Off
//
void Led::Led_G_Off() {
    digitalWrite(LED_PIN_G, LOW);
}

//
// Led_B_Off
//
void Led::Led_B_Off() {
    digitalWrite(LED_PIN_B, LOW);
}


