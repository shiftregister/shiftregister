//#define F_CPU 8000000UL

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <inttypes.h>
#include <avr/pgmspace.h>
#include <Adafruit_MAX31865.h>

Adafruit_MAX31865 max = Adafruit_MAX31865(44, 46, 48, 50);
#define RREF      430.0
#define RNOMINAL  100.0

void setup() {
  Serial.begin(115200);
  max.begin(MAX31865_2WIRE);  // set to 2WIRE or 4WIRE as necessary
}

void loop() { // NOTE: this is measuring itself - the ARDUINO MEGA!!!!
  uint16_t x,y, value,rtd;
  float ratio;
  //  while(1){
  Serial.println("STARTASM");
  rtd = max.readRTD();
  ratio = rtd;
  ratio /= 32768;
  Serial.println(max.temperature(RNOMINAL, RREF));
  
    // testings
  for (y=0;y<125;y++){
  for (x=0;x<32000;x++){
      value=x&255;
      // LDI R16, x
      // CLR R0-15
      // MOV R16, R0-15

     
      asm volatile("mov __tmp_reg__, %A0" "\n\t"
           "mov %A0, %D0" "\n\t"
           "mov %D0, __tmp_reg__" "\n\t"
           "mov __tmp_reg__, %B0" "\n\t"
           "mov %B0, %C0" "\n\t"
           "mov %C0, __tmp_reg__" "\n\t"
           : "+r" (value));
    }
  }
  Serial.println("ENDASM");
  rtd = max.readRTD();
  ratio = rtd;
  ratio /= 32768;
  Serial.println(max.temperature(RNOMINAL, RREF));

    _delay_ms(2000); // how long?
  }
//}

