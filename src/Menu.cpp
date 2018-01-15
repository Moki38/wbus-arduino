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

//
// Default Language (ENGLISH) with Menu structure
//
    MenuItem[ 1].Text[0] = "Timer";            MenuItem[ 1].Next = 17; MenuItem[ 1].Prev = 58; MenuItem[ 1].Parent = 0;  MenuItem[ 1].Child = 2;
    MenuItem[ 2].Text[0] = "Timers";           MenuItem[ 2].Next =  0; MenuItem[ 2].Prev =  0; MenuItem[ 2].Parent = 0;  MenuItem[ 2].Child = 0;
    MenuItem[ 3].Text[0] = "Activate";         MenuItem[ 3].Next =  0; MenuItem[ 3].Prev =  0; MenuItem[ 3].Parent = 0;  MenuItem[ 3].Child = 0;
    MenuItem[ 4].Text[0] = "Deactivate";       MenuItem[ 4].Next =  0; MenuItem[ 3].Prev =  0; MenuItem[ 3].Parent = 0;  MenuItem[ 3].Child = 0;
    MenuItem[ 5].Text[0] = "Add Timer";        MenuItem[ 5].Next =  0; MenuItem[ 4].Prev =  0; MenuItem[ 4].Parent = 0;  MenuItem[ 4].Child = 0;
    MenuItem[ 6].Text[0] = "Day";              MenuItem[ 6].Next =  0; MenuItem[ 5].Prev =  0; MenuItem[ 5].Parent = 0;  MenuItem[ 5].Child = 0;
    MenuItem[ 7].Text[0] = "Start Time";       MenuItem[ 7].Next =  0; MenuItem[ 6].Prev =  0; MenuItem[ 6].Parent = 0;  MenuItem[ 6].Child = 0;
    MenuItem[ 8].Text[0] = "End Time";         MenuItem[ 8].Next =  0; MenuItem[ 7].Prev =  0; MenuItem[ 7].Parent = 0;  MenuItem[ 7].Child = 0;
    MenuItem[ 9].Text[0] = "Heating";          MenuItem[ 9].Next =  0; MenuItem[ 8].Prev =  0; MenuItem[ 8].Parent = 0;  MenuItem[ 8].Child = 0;
    MenuItem[10].Text[0] = "Mode";             MenuItem[10].Next =  0; MenuItem[ 9].Prev =  0; MenuItem[ 9].Parent = 0;  MenuItem[ 9].Child = 0;
    MenuItem[11].Text[0] = "Temperature";      MenuItem[11].Next =  0; MenuItem[10].Prev =  0; MenuItem[10].Parent = 0;  MenuItem[10].Child = 0;
    MenuItem[12].Text[0] = "Ventilation";      MenuItem[12].Next =  0; MenuItem[ 8].Prev =  0; MenuItem[ 8].Parent = 0;  MenuItem[ 8].Child = 0;
    MenuItem[13].Text[0] = "Level";            MenuItem[13].Next =  0; MenuItem[ 9].Prev =  0; MenuItem[ 9].Parent = 0;  MenuItem[ 9].Child = 0;
    MenuItem[14].Text[0] = "Delete All Timers";MenuItem[14].Next =  0; MenuItem[12].Prev =  0; MenuItem[12].Parent = 0;  MenuItem[12].Child = 0;
    MenuItem[15].Text[0] = "Ok";               MenuItem[15].Next =  0; MenuItem[13].Prev =  0; MenuItem[13].Parent = 0;  MenuItem[13].Child = 0;
    MenuItem[16].Text[0] = "Back";             MenuItem[16].Next =  0; MenuItem[14].Prev =  0; MenuItem[14].Parent = 0;  MenuItem[14].Child = 0;

    MenuItem[16].Text[0] = "Heater";           MenuItem[15].Next = 21; MenuItem[15].Prev =  1; MenuItem[15].Parent = 0;  MenuItem[15].Child = 2;
    MenuItem[17].Text[0] = "Temperature";      MenuItem[16].Next =  0; MenuItem[16].Prev =  0; MenuItem[16].Parent = 0;  MenuItem[16].Child = 0;
    MenuItem[18].Text[0] = "Mode";             MenuItem[17].Next =  0; MenuItem[17].Prev =  0; MenuItem[17].Parent = 0;  MenuItem[17].Child = 0;
    MenuItem[19].Text[0] = "Time";             MenuItem[18].Next =  0; MenuItem[18].Prev =  0; MenuItem[18].Parent = 0;  MenuItem[18].Child = 0;
    MenuItem[20].Text[0] = "Back";             MenuItem[19].Next =  0; MenuItem[19].Prev =  0; MenuItem[19].Parent = 0;  MenuItem[19].Child = 0;

    MenuItem[21].Text[0] = "Ventilation";      MenuItem[20].Next = 24; MenuItem[20].Prev = 15; MenuItem[20].Parent = 0;  MenuItem[20].Child = 2;
    MenuItem[22].Text[0] = "Level";            MenuItem[21].Next =  0; MenuItem[21].Prev =  0; MenuItem[21].Parent = 0;  MenuItem[21].Child = 0;
    MenuItem[23].Text[0] = "Time";             MenuItem[22].Next =  0; MenuItem[22].Prev =  0; MenuItem[22].Parent = 0;  MenuItem[22].Child = 0;
    MenuItem[24].Text[0] = "Back";             MenuItem[23].Next =  0; MenuItem[23].Prev =  0; MenuItem[23].Parent = 0;  MenuItem[23].Child = 0;

    MenuItem[25].Text[0] = "Settings";         MenuItem[24].Next = 58; MenuItem[24].Prev = 20; MenuItem[24].Parent = 0;  MenuItem[24].Child = 2;
    MenuItem[26].Text[0] = "Quick Start";      MenuItem[25].Next =  0; MenuItem[25].Prev =  0; MenuItem[25].Parent = 0;  MenuItem[25].Child = 0;
    MenuItem[27].Text[0] = "Heating";          MenuItem[ 8].Next =  0; MenuItem[ 8].Prev =  0; MenuItem[ 8].Parent = 0;  MenuItem[ 8].Child = 0;
    MenuItem[28].Text[0] = "Mode";             MenuItem[ 9].Next =  0; MenuItem[ 9].Prev =  0; MenuItem[ 9].Parent = 0;  MenuItem[ 9].Child = 0;
    MenuItem[29].Text[0] = "Temperature";      MenuItem[10].Next =  0; MenuItem[10].Prev =  0; MenuItem[10].Parent = 0;  MenuItem[10].Child = 0;
    MenuItem[30].Text[0] = "Back";             MenuItem[52].Next =  0; MenuItem[52].Prev =  0; MenuItem[52].Parent = 0;  MenuItem[52].Child = 0;
    MenuItem[31].Text[0] = "Ventilation";      MenuItem[ 8].Next =  0; MenuItem[ 8].Prev =  0; MenuItem[ 8].Parent = 0;  MenuItem[ 8].Child = 0;
    MenuItem[32].Text[0] = "Level";            MenuItem[ 9].Next =  0; MenuItem[ 9].Prev =  0; MenuItem[ 9].Parent = 0;  MenuItem[ 9].Child = 0;
    MenuItem[33].Text[0] = "Back";             MenuItem[52].Next =  0; MenuItem[52].Prev =  0; MenuItem[52].Parent = 0;  MenuItem[52].Child = 0;

    MenuItem[34].Text[0] = "Language";         MenuItem[26].Next =  0; MenuItem[26].Prev =  0; MenuItem[26].Parent = 0;  MenuItem[26].Child = 0;
    MenuItem[35].Text[0] = "English";          MenuItem[26].Next =  0; MenuItem[26].Prev =  0; MenuItem[26].Parent = 0;  MenuItem[26].Child = 0;
    MenuItem[36].Text[0] = "Dutch";            MenuItem[26].Next =  0; MenuItem[26].Prev =  0; MenuItem[26].Parent = 0;  MenuItem[26].Child = 0;
    MenuItem[37].Text[0] = "";                 MenuItem[26].Next =  0; MenuItem[26].Prev =  0; MenuItem[26].Parent = 0;  MenuItem[26].Child = 0;
    MenuItem[38].Text[0] = "";                 MenuItem[26].Next =  0; MenuItem[26].Prev =  0; MenuItem[26].Parent = 0;  MenuItem[26].Child = 0;
    MenuItem[39].Text[0] = "";                 MenuItem[26].Next =  0; MenuItem[26].Prev =  0; MenuItem[26].Parent = 0;  MenuItem[26].Child = 0;
    MenuItem[40].Text[0] = "";                 MenuItem[26].Next =  0; MenuItem[26].Prev =  0; MenuItem[26].Parent = 0;  MenuItem[26].Child = 0;
    MenuItem[41].Text[0] = "";                 MenuItem[26].Next =  0; MenuItem[26].Prev =  0; MenuItem[26].Parent = 0;  MenuItem[26].Child = 0;
    MenuItem[42].Text[0] = "";                 MenuItem[26].Next =  0; MenuItem[26].Prev =  0; MenuItem[26].Parent = 0;  MenuItem[26].Child = 0;
    MenuItem[43].Text[0] = "Back";             MenuItem[52].Next =  0; MenuItem[52].Prev =  0; MenuItem[52].Parent = 0;  MenuItem[52].Child = 0;

    MenuItem[44].Text[0] = "Units";            MenuItem[27].Next =  0; MenuItem[27].Prev =  0; MenuItem[27].Parent = 0;  MenuItem[27].Child = 0;
    MenuItem[45].Text[0] = "C";                MenuItem[27].Next =  0; MenuItem[27].Prev =  0; MenuItem[27].Parent = 0;  MenuItem[27].Child = 0;
    MenuItem[46].Text[0] = "F";                MenuItem[27].Next =  0; MenuItem[27].Prev =  0; MenuItem[27].Parent = 0;  MenuItem[27].Child = 0;
    MenuItem[47].Text[0] = "Back";             MenuItem[52].Next =  0; MenuItem[52].Prev =  0; MenuItem[52].Parent = 0;  MenuItem[52].Child = 0;

    MenuItem[48].Text[0] = "Brightness";       MenuItem[28].Next =  0; MenuItem[28].Prev =  0; MenuItem[28].Parent = 0;  MenuItem[28].Child = 0;
    MenuItem[49].Text[0] = "Screen Timeout";   MenuItem[29].Next =  0; MenuItem[29].Prev =  0; MenuItem[29].Parent = 0;  MenuItem[29].Child = 0;
    MenuItem[50].Text[0] = "Day/Night";        MenuItem[30].Next =  0; MenuItem[30].Prev =  0; MenuItem[30].Parent = 0;  MenuItem[30].Child = 0;
    MenuItem[51].Text[0] = "Start Day";        MenuItem[31].Next =  0; MenuItem[31].Prev =  0; MenuItem[31].Parent = 0;  MenuItem[31].Child = 0;
    MenuItem[52].Text[0] = "Hour";             MenuItem[32].Next =  0; MenuItem[32].Prev =  0; MenuItem[32].Parent = 0;  MenuItem[32].Child = 0;
    MenuItem[53].Text[0] = "Minutes";          MenuItem[33].Next =  0; MenuItem[33].Prev =  0; MenuItem[33].Parent = 0;  MenuItem[33].Child = 0;
    MenuItem[54].Text[0] = "Start Night";      MenuItem[34].Next =  0; MenuItem[34].Prev =  0; MenuItem[34].Parent = 0;  MenuItem[34].Child = 0;
    MenuItem[55].Text[0] = "Hour";             MenuItem[35].Next =  0; MenuItem[35].Prev =  0; MenuItem[35].Parent = 0;  MenuItem[35].Child = 0;
    MenuItem[56].Text[0] = "Minutes";          MenuItem[36].Next =  0; MenuItem[36].Prev =  0; MenuItem[36].Parent = 0;  MenuItem[36].Child = 0;
    MenuItem[57].Text[0] = "Back";             MenuItem[52].Next =  0; MenuItem[52].Prev =  0; MenuItem[52].Parent = 0;  MenuItem[52].Child = 0;
    MenuItem[58].Text[0] = "System Info";      MenuItem[37].Next =  0; MenuItem[37].Prev =  0; MenuItem[37].Parent = 0;  MenuItem[37].Child = 0;
    MenuItem[59].Text[0] = "Heater Name";      MenuItem[38].Next =  0; MenuItem[38].Prev =  0; MenuItem[38].Parent = 0;  MenuItem[38].Child = 0;
    MenuItem[60].Text[0] = "Software Version"; MenuItem[38].Next =  0; MenuItem[38].Prev =  0; MenuItem[38].Parent = 0;  MenuItem[38].Child = 0;
    MenuItem[61].Text[0] = "Errors";           MenuItem[38].Next =  0; MenuItem[38].Prev =  0; MenuItem[38].Parent = 0;  MenuItem[38].Child = 0;
    MenuItem[62].Text[0] = "Reset Errors";     MenuItem[38].Next =  0; MenuItem[38].Prev =  0; MenuItem[38].Parent = 0;  MenuItem[38].Child = 0;
    MenuItem[63].Text[0] = "Back";             MenuItem[52].Next =  0; MenuItem[52].Prev =  0; MenuItem[52].Parent = 0;  MenuItem[52].Child = 0;

    MenuItem[64].Text[0] = "Service Menu";     MenuItem[37].Next =  0; MenuItem[37].Prev =  0; MenuItem[37].Parent = 0;  MenuItem[37].Child = 0;
    MenuItem[65].Text[0] = "Heater Type";      MenuItem[38].Next =  0; MenuItem[38].Prev =  0; MenuItem[38].Parent = 0;  MenuItem[38].Child = 0;
    MenuItem[66].Text[0] = "Min Duration";     MenuItem[39].Next =  0; MenuItem[39].Prev =  0; MenuItem[39].Parent = 0;  MenuItem[39].Child = 0;
    MenuItem[67].Text[0] = "Max Duration";     MenuItem[40].Next =  0; MenuItem[40].Prev =  0; MenuItem[40].Parent = 0;  MenuItem[40].Child = 0;
    MenuItem[68].Text[0] = "Permanant Mode";   MenuItem[41].Next =  0; MenuItem[41].Prev =  0; MenuItem[41].Parent = 0;  MenuItem[41].Child = 0;
    MenuItem[69].Text[0] = "Ventilation";      MenuItem[42].Next =  0; MenuItem[42].Prev =  0; MenuItem[42].Parent = 0;  MenuItem[42].Child = 0;
    MenuItem[70].Text[0] = "Min Temperatur";   MenuItem[43].Next =  0; MenuItem[43].Prev =  0; MenuItem[43].Parent = 0;  MenuItem[43].Child = 0;
    MenuItem[71].Text[0] = "Max Temperatur";   MenuItem[44].Next =  0; MenuItem[44].Prev =  0; MenuItem[44].Parent = 0;  MenuItem[44].Child = 0;
    MenuItem[72].Text[0] = "Show Temperatur";  MenuItem[45].Next =  0; MenuItem[45].Prev =  0; MenuItem[45].Parent = 0;  MenuItem[45].Child = 0;
    MenuItem[73].Text[0] = "Under Voltage";    MenuItem[46].Next =  0; MenuItem[46].Prev =  0; MenuItem[46].Parent = 0;  MenuItem[46].Child = 0;
    MenuItem[74].Text[0] = "Shutdown";         MenuItem[47].Next =  0; MenuItem[47].Prev =  0; MenuItem[47].Parent = 0;  MenuItem[47].Child = 0;
    MenuItem[75].Text[0] = "Volt";             MenuItem[48].Next =  0; MenuItem[48].Prev =  0; MenuItem[48].Parent = 0;  MenuItem[48].Child = 0;
    MenuItem[76].Text[0] = "Max Timers";       MenuItem[49].Next =  0; MenuItem[49].Prev =  0; MenuItem[49].Parent = 0;  MenuItem[49].Child = 0;
    MenuItem[77].Text[0] = "Factory Reset";    MenuItem[50].Next =  0; MenuItem[50].Prev =  0; MenuItem[50].Parent = 0;  MenuItem[50].Child = 0;
    MenuItem[78].Text[0] = "Ok";               MenuItem[51].Next =  0; MenuItem[51].Prev =  0; MenuItem[51].Parent = 0;  MenuItem[51].Child = 0;
    MenuItem[79].Text[0] = "Back";             MenuItem[52].Next =  0; MenuItem[52].Prev =  0; MenuItem[52].Parent = 0;  MenuItem[52].Child = 0;
    MenuItem[80].Text[0] = "Exit";             MenuItem[58].Next =  1; MenuItem[58].Prev = 24; MenuItem[58].Parent = 0;  MenuItem[58].Child = 0;

//
// DUTCH Language
//
    MenuItem[ 1].Text[1] = "Timer";
    MenuItem[ 2].Text[1] = "Timers";
    MenuItem[ 3].Text[1] = "Activate";
    MenuItem[ 3].Text[1] = "Deactivate";
    MenuItem[ 4].Text[1] = "Add Timer";
    MenuItem[ 5].Text[1] = "Day";
    MenuItem[ 6].Text[1] = "Start Time";
    MenuItem[ 7].Text[1] = "End Time";
    MenuItem[ 8].Text[1] = "Heating";
    MenuItem[ 9].Text[1] = "Mode";
    MenuItem[10].Text[1] = "Temperature";
    MenuItem[11].Text[1] = "Ventilation";
    MenuItem[12].Text[1] = "Level";
    MenuItem[13].Text[1] = "Delete All Timers";
    MenuItem[14].Text[1] = "Ok";
    MenuItem[15].Text[1] = "Back";

    MenuItem[16].Text[1] = "Heater";
    MenuItem[17].Text[1] = "Temperature";
    MenuItem[18].Text[1] = "Mode";
    MenuItem[19].Text[1] = "Time";
    MenuItem[20].Text[1] = "Back";

    MenuItem[21].Text[1] = "Ventilation";
    MenuItem[22].Text[1] = "Level";
    MenuItem[23].Text[1] = "Time";
    MenuItem[24].Text[1] = "Back";

    MenuItem[25].Text[1] = "Settings";
    MenuItem[26].Text[1] = "Quick Start";
    MenuItem[27].Text[1] = "Heating";
    MenuItem[28].Text[1] = "Mode";
    MenuItem[29].Text[1] = "Temperature";
    MenuItem[30].Text[1] = "Back";
    MenuItem[31].Text[1] = "Ventilation";
    MenuItem[32].Text[1] = "Level";
    MenuItem[33].Text[1] = "Back";

    MenuItem[34].Text[1] = "Language";
    MenuItem[35].Text[1] = "English";
    MenuItem[36].Text[1] = "Dutch";
    MenuItem[37].Text[1] = "";
    MenuItem[38].Text[1] = "";
    MenuItem[39].Text[1] = "";
    MenuItem[40].Text[1] = "";
    MenuItem[41].Text[1] = "";
    MenuItem[42].Text[1] = "";
    MenuItem[43].Text[1] = "Back";

    MenuItem[44].Text[1] = "Units";
    MenuItem[45].Text[1] = "C";
    MenuItem[46].Text[1] = "F";
    MenuItem[47].Text[1] = "Back";

    MenuItem[48].Text[1] = "Brightness";
    MenuItem[49].Text[1] = "Screen Timeout";
    MenuItem[50].Text[1] = "Day/Night";
    MenuItem[51].Text[1] = "Start Day";
    MenuItem[52].Text[1] = "Hour";
    MenuItem[53].Text[1] = "Minutes";
    MenuItem[54].Text[1] = "Start Night";
    MenuItem[55].Text[1] = "Hour";
    MenuItem[56].Text[1] = "Minutes";
    MenuItem[57].Text[1] = "Back";
    MenuItem[58].Text[1] = "System Info";
    MenuItem[59].Text[1] = "Heater Name";
    MenuItem[60].Text[1] = "Software Version";
    MenuItem[61].Text[1] = "Errors";
    MenuItem[62].Text[1] = "Reset Errors";
    MenuItem[63].Text[1] = "Back";

    MenuItem[64].Text[1] = "Service Menu";
    MenuItem[65].Text[1] = "Heater Type";
    MenuItem[66].Text[1] = "Min Duration";
    MenuItem[67].Text[1] = "Max Duration";
    MenuItem[68].Text[1] = "Permanant Mode";
    MenuItem[69].Text[1] = "Ventilation";
    MenuItem[70].Text[1] = "Min Temperatur";
    MenuItem[71].Text[1] = "Max Temperatur";
    MenuItem[72].Text[1] = "Show Temperatur";
    MenuItem[73].Text[1] = "Under Voltage";
    MenuItem[74].Text[1] = "Shutdown";
    MenuItem[75].Text[1] = "Volt";
    MenuItem[76].Text[1] = "Max Timers";
    MenuItem[77].Text[1] = "Factory Reset";
    MenuItem[78].Text[1] = "Ok";
    MenuItem[79].Text[1] = "Back";
    MenuItem[80].Text[1] = "Exit";
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
