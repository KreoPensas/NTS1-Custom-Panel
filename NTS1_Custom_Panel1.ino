/*
    KreoPensas Custom Control Panel for Korg NTS-1

    
    BSD 3-Clause License
    Copyright (c) 2020, KORG INC.
    All rights reserved.
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
   * Redistributions of source code must retain the above copyright notice, this
      list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.
    * Neither the name of the copyright holder nor the names of its
      contributors may be used to endorse or promote products derived from
      this software without specific prior written permission.

    This is free and unencumbered software released into the public domain.

    Anyone is free to copy, modify, publish, use, compile, sell, or
    distribute this software, either in source code form or as a compiled
    binary, for any purpose, commercial or non-commercial, and by any
    means.

    In jurisdictions that recognize copyright laws, the author or authors
    of this software dedicate any and all copyright interest in the
    software to the public domain. We make this dedication for the benefit
    of the public at large and to the detriment of our heirs and
    successors. We intend this dedication to be an overt act of
    relinquishment in perpetuity of all present and future rights to this
    software under copyright law.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
    OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
    ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.

    For more information, please refer to <http://unlicense.org/>
  //*/

#include <nts-1.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64

#define ENC_CLK PB7
#define ENC_DATA PB6
#define ENC_CLK2 PB4
#define ENC_DATA2 PB5
#define ENC_CLK3 PB3
#define ENC_DATA3 PD2
#define ENC_BUT PC12
#define ENC_BUT2 PC11
#define ENC_BUT3 PC10

#define EEPROM_ADR_LOW_BLOCK 0x50
#define EEPROM_ADR_HIGH_BLOCK 0x54

#define OLED_RESET     -1

NTS1 nts1;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


volatile uint32_t encoderCount;
volatile uint32_t encoderCount2;
volatile uint32_t encoderCount3;


void setup() {
  nts1.init();
    Serial.begin(9600);
  Wire.setSDA(PB9);
  Wire.setSCL(PB8);
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.display();
  pinMode(ENC_CLK, INPUT);
  pinMode(ENC_DATA, INPUT);
  pinMode(ENC_CLK2, INPUT);
  pinMode(ENC_DATA2, INPUT);
  pinMode(ENC_CLK3, INPUT);
  pinMode(ENC_DATA3, INPUT);
  pinMode(ENC_BUT, INPUT_PULLUP);
  pinMode(ENC_BUT2, INPUT_PULLUP);
  pinMode(ENC_BUT3, INPUT_PULLUP);
  encoderCount = 10000;
  encoderCount2 = 10000;
  encoderCount3 = 10000;
  Serial.println("debug ready");
 // writeEEPROM(0,101);
 // byte bunny;
 // bunny = readEEPROM(0);
 // Serial.println(bunny);

  // put your setup code here, to run once:

}

void loop() {
  nts1.idle();

  // put your main code here, to run repeatedly:
  static uint32_t count;
  static uint32_t prevCount;
  static uint32_t count2;
  static uint32_t prevCount2;
  count = encoderCount;
  count2 = encoderCount2;
  if (count != prevCount)
  {
    prevCount = count;
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("Count : "));
    display.println(count);
    display.print(F("Count2: "));
    display.println(count2);
    display.display();

  }
  if (count2 != prevCount2)
  {
    prevCount2 = count2;
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(F("Count : "));
    display.println(count);
    display.print(F("Count2: "));
    display.println(count2);
    display.display();

  }
}
