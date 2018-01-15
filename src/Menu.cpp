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
#include "Menu.h"

//
// Menu Init 
//
void Menu::Init() {
    menuisactive = false;

    MenuItem[ 1].Text = "Timer";       MenuItem[ 1].Next = 15; MenuItem[ 1].Prev = 58; MenuItem[ 1].Parent = 0;  MenuItem[ 1].Child = 2;
    MenuItem[15].Text = "Heater";      MenuItem[15].Next = 20; MenuItem[15].Prev =  1; MenuItem[15].Parent = 0;  MenuItem[15].Child = 2;
    MenuItem[20].Text = "Ventilation"; MenuItem[20].Next = 24; MenuItem[20].Prev = 15; MenuItem[20].Parent = 0;  MenuItem[20].Child = 2;
    MenuItem[24].Text = "Settings";    MenuItem[24].Next = 58; MenuItem[24].Prev = 20; MenuItem[24].Parent = 0;  MenuItem[24].Child = 2;
    MenuItem[58].Text = "Exit";        MenuItem[58].Next =  1; MenuItem[58].Prev = 24; MenuItem[58].Parent = 0;  MenuItem[58].Child = 2;
}


bool Menu::IsActive() {
    return(menuisactive);
}

void Menu::Enable() {
    menuisactive = true;
}

void Menu::Disable() {
    menuisactive = false;
}

byte Menu::Next(byte item) {
    return (MenuItem[item].Next);
}

byte Menu::Prev(byte item) {
    return (MenuItem[item].Prev);
}

byte Menu::Parent(byte item) {
    return (MenuItem[item].Parent);
}

byte Menu::Child(byte item) {
    return (MenuItem[item].Child);
}
