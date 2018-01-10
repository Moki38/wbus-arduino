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

#include "Wbus.h"


byte pos;
byte len = 0;
byte buffer[20];
int version_run = 0;
int status_run = 0;

// 
// Print Long State
//

const char* Wbus::Print_State(byte state) {
    switch(state) {
        case 0x00 : return ("Burn Out"); break;
        case 0x01 : return ("Deactivation"); break;
        case 0x02 : return ("Burn Out ADR"); break;
        case 0x03 : return ("Burn Out Ramp"); break;
        case 0x04 : return ("Off State"); break;
        case 0x05 : return ("Combustion process part load"); break;
        case 0x06 : return ("Combustion process full load"); break;
        case 0x07 : return ("Fuel supply"); break;
        case 0x08 : return ("Combustion air fan start"); break;
        case 0x09 : return ("Fuel supply interruption"); break;
        case 0x0a : return ("Diagnostic state"); break;
        case 0x0b : return ("Fuel pump interruption"); break;
        case 0x0c : return ("EMF measurement"); break;
        case 0x0d : return ("Debounce"); break;
        case 0x0e : return ("Deactivation"); break;
        case 0x0f : return ("Flame detector interrogation"); break;
        case 0x10 : return ("Flame detector cooling"); break;
        case 0x11 : return ("Flame detector measuring phase"); break;
        case 0x12 : return ("Flame detector measuring phase ZUE"); break;
        case 0x13 : return ("Fan start up"); break;
        case 0x14 : return ("Glow plug ramp"); break;
        case 0x15 : return ("Heater interlock"); break;
        case 0x16 : return ("Initialization"); break;
        case 0x17 : return ("Fuel bubble compensation"); break;
        case 0x18 : return ("Fan cold start-up"); break;
        case 0x19 : return ("Cold start enrichment"); break;
        case 0x1a : return ("Cooling"); break;
        case 0x1b : return ("Load change PL-FL"); break;
        case 0x1c : return ("Ventilation"); break;
        case 0x1d : return ("Load change FL-PL"); break;
        case 0x1e : return ("New initialization"); break;
        case 0x1f : return ("Controlled operation"); break;
        case 0x20 : return ("Control iddle period"); break;
        case 0x21 : return ("Soft start"); break;
        case 0x22 : return ("Savety time"); break;
        case 0x23 : return ("Purge"); break;
        case 0x24 : return ("Start"); break;
        case 0x25 : return ("Stabilization"); break;
        case 0x26 : return ("Start ramp"); break;
        case 0x27 : return ("Out of power"); break;
        case 0x28 : return ("Interlock"); break;
        case 0x29 : return ("Interlock ADR (Australian design rules)"); break;
        case 0x2a : return ("Stabilization time"); break;
        case 0x2b : return ("Change to controlled operation"); break;
        case 0x2c : return ("Decision state"); break;
        case 0x2d : return ("Prestart fuel supply"); break;
        case 0x2e : return ("Glowing"); break;
        case 0x2f : return ("Glowing power control"); break;
        case 0x30 : return ("Delay lowering"); break;
        case 0x31 : return ("Sluggish fan start"); break;
        case 0x32 : return ("Additional glowing"); break;
        case 0x33 : return ("Ignition interruption"); break;
        case 0x34 : return ("Ignition"); break;
        case 0x35 : return ("Intermittent glowing"); break;
        case 0x36 : return ("Application monitoring"); break;
        case 0x37 : return ("Interlock save to memory"); break;
        case 0x38 : return ("Heater interlock deactivation"); break;
        case 0x39 : return ("Output control"); break;
        case 0x3a : return ("Circulating pump control"); break;
        case 0x3b : return ("Initialization uP"); break;
        case 0x3c : return ("Stray light interrogation"); break;
        case 0x3d : return ("Prestart"); break;
        case 0x3e : return ("Pre-ignition"); break;
        case 0x3f : return ("Flame ignition"); break;
        case 0x40 : return ("Flame stabilization"); break;
        case 0x41 : return ("Combustion process parking heating"); break;
        case 0x42 : return ("Combustion process suppl. heating"); break;
        case 0x43 : return ("Combustion failure failure heating"); break;
        case 0x44 : return ("Combustion failure suppl. heating"); break;
        case 0x45 : return ("Heater off after run"); break;
        case 0x46 : return ("Control iddle after run"); break;
        case 0x47 : return ("After-run due to failure"); break;
        case 0x48 : return ("Time-controlled after-run due to failure"); break;
        case 0x49 : return ("Interlock circulation pump"); break;
        case 0x4a : return ("Control iddle after parking heating"); break;
        case 0x4b : return ("Control iddle after suppl. heating"); break;
        case 0x4c : return ("Control iddle period suppl. heating with circulation pump"); break;
        case 0x4d : return ("Circulation pump without heating function"); break;
        case 0x4e : return ("Waiting loop overvoltage"); break;
        case 0x4f : return ("Fault memory update"); break;
        case 0x50 : return ("Waiting loop"); break;
        case 0x51 : return ("Component test"); break;
        case 0x52 : return ("Boost"); break;
        case 0x53 : return ("Cooling"); break;
        case 0x54 : return ("Heater interlock permanent"); break;
        case 0x55 : return ("Fan iddle"); break;
        case 0x56 : return ("Break away"); break;
        case 0x57 : return ("Temperature interrogation"); break;
        case 0x58 : return ("Prestart undervoltage"); break;
        case 0x59 : return ("Accident interrogation"); break;
        case 0x5a : return ("After-run solenoid valve"); break;
        case 0x5b : return ("Fault memory update solenoid valve"); break;
        case 0x5c : return ("Timer-controlled after-run solenoid valve"); break;
        case 0x5d : return ("Startup attempt"); break;
        case 0x5e : return ("Prestart extension"); break;
        case 0x5f : return ("Combustion process"); break;
        case 0x60 : return ("Timer-controlled after-run due to undervoltage"); break;
        case 0x61 : return ("Fault memory update prior switch off"); break;
        case 0x62 : return ("Ramp full load"); break;
        default   : return ("Unknown");
   }
}

//
// Wbus Init 
//
void Wbus::Init() {
    Serial1.begin(2400,SERIAL_8E1);
#if DEBUG == 2
    Serial.println("Wbus initialization done.");
#endif
}

//
// Wbus Checksum
//
byte Wbus::Checksum(byte *buf, byte len, byte chk) {
    byte i = 0;
    for (i=0;i<=len; i++) {
        chk ^= *buf++;
    }
    return chk;
}

//
// Wbus Gather
//
void Wbus::Gather(Webasto &webasto, int B) {

//    Serial.println(B,HEX);

    switch(B) {
        case 0x34:
        case 0x43:
        case 0x4F:
        case 0xF4:
            pos = 0;
            buffer[pos] = B;
            pos++;
            break;
        default:
            if (pos == 1) {
                 len = B;
                 buffer[pos] = B;
                 pos++;
            } else {
                 len = buffer[1];
                 buffer[pos] = B;
                 pos++;
                 if (pos-1 > len) {
                     pos = 0;
                     Parse(webasto, buffer, len);
                 }
            }
            break;
    }
}

//
// Wbus On
//
void Wbus::On(Webasto &webasto, int temp) {
    webasto.keepalive = true;
    if (temp < 5) {
        temp = 5;
    }
    if (temp > 35) {
        temp = 35;
    }

// 0x34,0x05,0x2A,0x21,0xFF,0x48,0x8D 
    Serial1.write(0xf4);
    Serial1.write(0x05);
    Serial1.write(0x2A);
    Serial1.write(0x21);
    Serial1.write(0xFF);
    Serial1.write(0x48);
    Serial1.write(0x4D);
}

//
// Wbus Off
//
void Wbus::Off(Webasto &webasto) {
    webasto.keepalive = false;
// 0x34,0x02,0x10,0x26
    Serial1.write(0xf4);
    Serial1.write(0x02);
    Serial1.write(0x10);
    Serial1.write(0xE6);
}

//
// Wbus Loop 
//
void Wbus::Loop(Webasto &webasto) {
    if (webasto.keepalive) {
// 0x34,0x04,0x44,0x2A,0x00,0x5E
       Serial1.write(0xf4);
       Serial1.write(0x04);
       Serial1.write(0x44);
       Serial1.write(0x2A);
       Serial1.write(0x00);
       Serial1.write(0x9E);
    }
}


//
// Wbus Parse
//
void Wbus::Parse(Webasto &webasto, byte *buf, byte len) {

#if DEBUG == 2
    byte i = 0;

    for (i=0;i<len+1;i++) {
        Serial.print("0x"); 
        if (buf[i]<0x10) {Serial.print("0");} 
        Serial.print(buf[i],HEX);
        Serial.print(",");
    }
    Serial.print("0x"); 
    if (buffer[i]<0x10) {Serial.print("0");} 
    Serial.print(buf[i],HEX);
    Serial.println();
#endif

//
// Heater Modus
//
    if (buf[2] == 0xAA) {
        if (buf[3] == 0x21) {
            webasto.mode = 2;
            webasto.temp   = buf[5] - 50;
        }
        if (buf[3] == 0x25) {
            webasto.mode = 3;
            webasto.temp   = buf[5] - 50;
        }
        if (buf[3] == 0x26) {
            webasto.mode = 1;
            webasto.temp   = buf[5] - 50;
        }
    }

//
// Heater Info
//
    if (buf[2] == 0xD1) {
        if (buf[3] == 0x0B) {
        }
    }

//
// Heater Status
//
    if (buf[2] == 0xD0) {
//        Serial.println("Webasto Status"); 
        if (buf[3] == 0x02) {
            webasto.status_ms = (buf[4] & 0x01) ? 1 : 0;
            webasto.status_shr = (buf[4] & 0x10) ? 1 : 0;
        }
        if (buf[3] == 0x03) {
            webasto.status_caf = (buf[4] & 0x01) ? 1 : 0;
            webasto.status_gp  = (buf[4] & 0x02) ? 1 : 0;
            webasto.status_fp  = (buf[4] & 0x04) ? 1 : 0;
            webasto.status_cp  = (buf[4] & 0x08) ? 1 : 0;
            webasto.status_vfr = (buf[4] & 0x10) ? 1 : 0;
            webasto.status_nsh = (buf[4] & 0x20) ? 1 : 0;
            webasto.status_fi  = (buf[4] & 0x40) ? 1 : 0;
        }
        if (buf[3] == 0x05) {
            webasto.status_temp   = buf[4] - 50;
            webasto.status_mvolt  = (buf[5]*256+buf[6])/1000;
            webasto.status_fd     = buf[7];
            webasto.status_hp     = (buf[8]*256+buf[9])/10;
            webasto.status_fdr    = (buf[10]*256+buf[11])/10000;
        }
        if (buf[3] == 0x06) {
            webasto.status_wh   = buf[4]*256+buf[5];
            webasto.status_wm   = buf[6];
            webasto.status_oh   = buf[7]*256+buf[8];
            webasto.status_om   = buf[9];
            webasto.status_sc   = buf[10]*256+buf[11];
        }
        if (buf[3] == 0x07) {
            webasto.status_os = buf[4];
            webasto.status_os_long = Print_State(webasto.status_os);
        }
        if (buf[3] == 0x0F) {
            webasto.status_gpp  = buf[4]*2;
            webasto.status_fpf  = buf[5]*2;
            webasto.status_afp  = buf[6]*2;
        }
    }
}

void Wbus::Version(Webasto &webasto) {
//        byte info_version;     // Version
//        byte info_devname;     // Device name
//        byte info_wbuscode;    // WBUS Code
//        byte info_wbusvers;    // WBUS version

    switch(version_run) {
        case 0:
            Serial1.write(0xf4);
            Serial1.write(0x03);
            Serial1.write(0x51);
            Serial1.write(0x02);
            Serial1.write(0xa4);
            version_run++;
            break;
        case 1:
            Serial1.write(0xf4);
            Serial1.write(0x03);
            Serial1.write(0x51);
            Serial1.write(0x0a);
            Serial1.write(0xac);
            version_run++;
            break;
        case 2:
            Serial1.write(0xf4);
            Serial1.write(0x03);
            Serial1.write(0x51);
            Serial1.write(0x0b);
            Serial1.write(0xad);
            version_run++;
            break;
        case 3:
            Serial1.write(0xf4);
            Serial1.write(0x03);
            Serial1.write(0x51);
            Serial1.write(0x0c);
            Serial1.write(0xae);
            version_run++;
            break;
    }

    if (version_run > 6) {
        version_run = 0;
    } else {
       version_run++;
    }
}

void Wbus::Status(Webasto &webasto) {
    switch(status_run) {
        case 0:
            Serial1.write(0xf4);
            Serial1.write(0x03);
            Serial1.write(0x50);
            Serial1.write(0x02);
            Serial1.write(0xa5);
            status_run++;
            break;
        case 1:
            Serial1.write(0xf4);
            Serial1.write(0x03);
            Serial1.write(0x50);
            Serial1.write(0x03);
            Serial1.write(0xa4);
            status_run++;
            break;
        case 2:
            Serial1.write(0xf4);
            Serial1.write(0x03);
            Serial1.write(0x50);
            Serial1.write(0x07);
            Serial1.write(0xa0);
            status_run++;
            break;
        case 3:
            Serial1.write(0xf4);
            Serial1.write(0x03);
            Serial1.write(0x50);
            Serial1.write(0x05);
            Serial1.write(0xa2);
            status_run++;
            break;
        case 4:
            Serial1.write(0xf4);
            Serial1.write(0x03);
            Serial1.write(0x50);
            Serial1.write(0x0f);
            Serial1.write(0xa8);
            status_run++;
            break;
        case 5:
            Serial1.write(0xf4);
            Serial1.write(0x03);
            Serial1.write(0x50);
            Serial1.write(0x06);
            Serial1.write(0xa1);
            status_run++;
            break;
        case 6:
            status_run = 0;
            Version(webasto);
            break;
    }
}

