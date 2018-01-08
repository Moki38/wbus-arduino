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
int status_run = 0;

// 
// Print Long State
//

void Wbus::Print_State(byte state) {
    switch(state) {
        case 0x00 : Serial.println("0x00 Burn Out"); break;
        case 0x01 : Serial.println("0x01 Deactivation"); break;
        case 0x02 : Serial.println("0x02 Burn Out ADR"); break;
        case 0x03 : Serial.println("0x03 Burn Out Ramp"); break;
        case 0x04 : Serial.println("0x04 Off State"); break;
        case 0x05 : Serial.println("0x05 Combustion process part load"); break;
        case 0x06 : Serial.println("0x06 Combustion process full load"); break;
        case 0x07 : Serial.println("0x07 Fuel supply"); break;
        case 0x08 : Serial.println("0x08 Combustion air fan start"); break;
        case 0x09 : Serial.println("0x09 Fuel supply interruption"); break;
        case 0x0a : Serial.println("0x0a Diagnostic state"); break;
        case 0x0b : Serial.println("0x0b Fuel pump interruption"); break;
        case 0x0c : Serial.println("0x0c EMF measurement"); break;
        case 0x0d : Serial.println("0x0d Debounce"); break;
        case 0x0e : Serial.println("0x0e Deactivation"); break;
        case 0x0f : Serial.println("0x0f Flame detector interrogation"); break;
        case 0x10 : Serial.println("0x10 Flame detector cooling"); break;
        case 0x11 : Serial.println("0x11 Flame detector measuring phase"); break;
        case 0x12 : Serial.println("0x12 Flame detector measuring phase ZUE"); break;
        case 0x13 : Serial.println("0x13 Fan start up"); break;
        case 0x14 : Serial.println("0x14 Glow plug ramp"); break;
        case 0x15 : Serial.println("0x15 Heater interlock"); break;
        case 0x16 : Serial.println("0x16 Initialization"); break;
        case 0x17 : Serial.println("0x17 Fuel bubble compensation"); break;
        case 0x18 : Serial.println("0x18 Fan cold start-up"); break;
        case 0x19 : Serial.println("0x19 Cold start enrichment"); break;
        case 0x1a : Serial.println("0x1a Cooling"); break;
        case 0x1b : Serial.println("0x1b Load change PL-FL"); break;
        case 0x1c : Serial.println("0x1c Ventilation"); break;
        case 0x1d : Serial.println("0x1d Load change FL-PL"); break;
        case 0x1e : Serial.println("0x1e New initialization"); break;
        case 0x1f : Serial.println("0x1f Controlled operation"); break;
        case 0x20 : Serial.println("0x20 Control iddle period"); break;
        case 0x21 : Serial.println("0x21 Soft start"); break;
        case 0x22 : Serial.println("0x22 Savety time"); break;
        case 0x23 : Serial.println("0x23 Purge"); break;
        case 0x24 : Serial.println("0x24 Start"); break;
        case 0x25 : Serial.println("0x25 Stabilization"); break;
        case 0x26 : Serial.println("0x26 Start ramp"); break;
        case 0x27 : Serial.println("0x27 Out of power"); break;
        case 0x28 : Serial.println("0x28 Interlock"); break;
        case 0x29 : Serial.println("0x29 Interlock ADR (Australian design rules)"); break;
        case 0x2a : Serial.println("0x2a Stabilization time"); break;
        case 0x2b : Serial.println("0x2b Change to controlled operation"); break;
        case 0x2c : Serial.println("0x2c Decision state"); break;
        case 0x2d : Serial.println("0x2d Prestart fuel supply"); break;
        case 0x2e : Serial.println("0x2e Glowing"); break;
        case 0x2f : Serial.println("0x2f Glowing power control"); break;
        case 0x30 : Serial.println("0x30 Delay lowering"); break;
        case 0x31 : Serial.println("0x31 Sluggish fan start"); break;
        case 0x32 : Serial.println("0x32 Additional glowing"); break;
        case 0x33 : Serial.println("0x33 Ignition interruption"); break;
        case 0x34 : Serial.println("0x34 Ignition"); break;
        case 0x35 : Serial.println("0x35 Intermittent glowing"); break;
        case 0x36 : Serial.println("0x36 Application monitoring"); break;
        case 0x37 : Serial.println("0x37 Interlock save to memory"); break;
        case 0x38 : Serial.println("0x38 Heater interlock deactivation"); break;
        case 0x39 : Serial.println("0x39 Output control"); break;
        case 0x3a : Serial.println("0x3a Circulating pump control"); break;
        case 0x3b : Serial.println("0x3b Initialization uP"); break;
        case 0x3c : Serial.println("0x3c Stray light interrogation"); break;
        case 0x3d : Serial.println("0x3d Prestart"); break;
        case 0x3e : Serial.println("0x3e Pre-ignition"); break;
        case 0x3f : Serial.println("0x3f Flame ignition"); break;
        case 0x40 : Serial.println("0x40 Flame stabilization"); break;
        case 0x41 : Serial.println("0x41 Combustion process parking heating"); break;
        case 0x42 : Serial.println("0x42 Combustion process suppl. heating"); break;
        case 0x43 : Serial.println("0x43 Combustion failure failure heating"); break;
        case 0x44 : Serial.println("0x44 Combustion failure suppl. heating"); break;
        case 0x45 : Serial.println("0x45 Heater off after run"); break;
        case 0x46 : Serial.println("0x46 Control iddle after run"); break;
        case 0x47 : Serial.println("0x47 After-run due to failure"); break;
        case 0x48 : Serial.println("0x48 Time-controlled after-run due to failure"); break;
        case 0x49 : Serial.println("0x49 Interlock circulation pump"); break;
        case 0x4a : Serial.println("0x4a Control iddle after parking heating"); break;
        case 0x4b : Serial.println("0x4b Control iddle after suppl. heating"); break;
        case 0x4c : Serial.println("0x4c Control iddle period suppl. heating with circulation pump"); break;
        case 0x4d : Serial.println("0x4d Circulation pump without heating function"); break;
        case 0x4e : Serial.println("0x4e Waiting loop overvoltage"); break;
        case 0x4f : Serial.println("0x4f Fault memory update"); break;
        case 0x50 : Serial.println("0x50 Waiting loop"); break;
        case 0x51 : Serial.println("0x51 Component test"); break;
        case 0x52 : Serial.println("0x52 Boost"); break;
        case 0x53 : Serial.println("0x53 Cooling"); break;
        case 0x54 : Serial.println("0x54 Heater interlock permanent"); break;
        case 0x55 : Serial.println("0x55 Fan iddle"); break;
        case 0x56 : Serial.println("0x56 Break away"); break;
        case 0x57 : Serial.println("0x57 Temperature interrogation"); break;
        case 0x58 : Serial.println("0x58 Prestart undervoltage"); break;
        case 0x59 : Serial.println("0x59 Accident interrogation"); break;
        case 0x5a : Serial.println("0x5a After-run solenoid valve"); break;
        case 0x5b : Serial.println("0x5b Fault memory update solenoid valve"); break;
        case 0x5c : Serial.println("0x5c Timer-controlled after-run solenoid valve"); break;
        case 0x5d : Serial.println("0x5d Startup attempt"); break;
        case 0x5e : Serial.println("0x5e Prestart extension"); break;
        case 0x5f : Serial.println("0x5f Combustion process"); break;
        case 0x60 : Serial.println("0x60 Timer-controlled after-run due to undervoltage"); break;
        case 0x61 : Serial.println("0x61 Fault memory update prior switch off"); break;
        case 0x62 : Serial.println("0x62 Ramp full load"); break;
   }
}

//
// Wbus Init 
//
void Wbus::Init() {
    Serial1.begin(2400,SERIAL_8E1);
    Serial.println("Wbus initialization done.");
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


#ifdef DEBUG
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
// Heater Status
//
    if (buf[2] == 0xD0) {
//        Serial.println("Webasto Status"); 
        if (buf[3] == 0x02) {
            webasto.status_ms = (buf[4] & 0x01) ? 1 : 0;
            webasto.status_shr = (buf[4] & 0x10) ? 1 : 0;
#ifdef DEBUG
            Serial.print("Main Switch: ");
            Serial.println(webasto.status_ms);
            Serial.print("Suplemental heater request: ");
            Serial.println(webasto.status_shr);
#endif
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
#ifdef DEBUG
            Serial.print("Temperature: ");
            Serial.println(webasto.status_temp);
            Serial.print("Voltage (V): ");
            Serial.println(webasto.status_mvolt);
            Serial.print("Flame detector: ");
            Serial.println(webasto.status_fd);
            Serial.print("Heating power (W): ");
            Serial.println(webasto.status_hp);
            Serial.print("Flame detector resistance (m Ohm): ");
            Serial.println(webasto.status_fdr);
#endif
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
#ifdef DEBUG
            Serial.println();
            Print_State(webasto.status_os);
#endif
        }
        if (buf[3] == 0x0F) {
            webasto.status_gpp  = buf[4]*2;
            webasto.status_fpf  = buf[5]*2;
            webasto.status_afp  = buf[6]*2;
#ifdef DEBUG
            Serial.print("Glow plug power: ");
            Serial.println(webasto.status_gpp);
            Serial.print("Fuel pump pulse frequency: ");
            Serial.println(webasto.status_fpf);
            Serial.print("Combustion air fan: ");
            Serial.println(webasto.status_afp);
#endif
        }
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
            break;
    }
}

