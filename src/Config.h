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

// 
// Version
//
#define VERSION 0.0.2

//
// Debug
//
//#define DEBUG 1

//
// Webasto Version
//     1:    Webasto 3500/3900
//     2:    EVO-40
//
#define WEBASTO	2

// 
// SD-Card available
//
#define SDCARD

// 
// Display 
//     1: OLED Yelllow/Blue 128x64 (i2c 0x3c)
//
#define DISPLAY_TYPE 1

//
// Rotary Encoder
//
#define ROTARY_ENCODER
#define ROT_PIN_A	A18
#define ROT_PIN_B	A19
#define ROT_BUTTON	36

//
// Led Pins
//
#define LED
#define LED_PIN_R	34
#define LED_PIN_G	35
#define LED_PIN_B	33

