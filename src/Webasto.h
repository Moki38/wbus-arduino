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
#ifndef _WEBASTO_H
#define _WEBASTO_H
#include <TimeAlarms.h>

class Webasto_Setup {
    public:
        byte Heater_Type;    // 1 = EVO-40, 2 = 3500, 3 = 3900
        bool Timer_Active;    // Timer active True / False;
};

class Webasto_Timer {
    public:
        byte sun;
        byte sun_hour_on;
        byte sun_min_on;
        byte sun_hour_off;
        byte sun_min_off;

};

class Webasto {
    public:
        AlarmID_t frostalarm;
        bool keepalive;
        bool on;
        bool timer;
        byte temp;             // Set TEMP
        byte mode;             // 1 ECO, 2 Normal. 3 Boost 4 Vent 

        byte status_caf;       // Combustion Fan
        byte status_fp;        // Fuel Pump
        byte status_gp;        // Glow Plug
        byte status_cp;        // Circulation Pump
        byte status_vfr;       // Vehicle Fan Relays
        byte status_nsh;       // Nozzle stock heating
        byte status_fi;        // Flame indicator
        byte status_ms;        // Main switch
        byte status_shr;       // Suplemental heater request

        byte status_os;        // Operating state
        String status_os_long; // Operating state Text

        byte status_temp;      // Temperature with  50 C offset (20 C is value=70)
        float status_mvolt;    // Voltage in mili Volt
        byte status_fd;        // Flame detector (set 0x01, not set 0x00)
        float status_hp;       // Heating power in watts, big endian
        float status_fdr;      // Flame detector resistance in mili Ohm, big endian

        byte status_wh;        // Working hours
        byte status_wm;        // Working minutes
        byte status_oh;        // Operating hours
        byte status_om;        // Operating minutes
        byte status_sc;        // Start counter

        byte status_gpp;       // Glow plug power in percent *2
        byte status_fpf;       // Fuel pump pulse frequency in Hz *2
        byte status_afp;       // Combustion air fan in percent*2

        byte info_version;     // Version 
        byte info_devname;     // Device name
        byte info_wbuscode;    // WBUS Code
        byte info_wbusvers;    // WBUS version
};

#endif
