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

#pragma once
#ifndef _MENU_H
#define _MENU_H
#include <Arduino.h>
#include "Config.h"

#define MAX_MENU_ITEMS 100
#define MAX_LANGUAGES  2

class Menu {
    public:
        void Init();
        bool IsActive();
        void Enable(); 
        void Disable(); 
        byte Next(byte);
        byte Prev(byte);
        byte Parent(byte);
        byte Child(byte);
    private:
        bool menuisactive;
        struct MenuItems {
            String Text[MAX_LANGUAGES];
            byte Next;
            byte Prev;
            byte Parent;
            byte Child;
        } MenuItem[MAX_MENU_ITEMS];
};

#endif
