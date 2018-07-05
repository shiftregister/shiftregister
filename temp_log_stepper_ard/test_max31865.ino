#include <Adafruit_MAX31865.h>
#include <SD.h>

// plot with gnuplot: find more software for png etc. just to test

// plot "/root/test2" with lines

// Use software SPI: CS, DI, DO, CLK
// pins from left bottom up of mega 1280 board

// added in ADC0 for light sensor

// added in stepper example code: with ULN2803: https://impremedia.net/uln2803-stepper-motor-arduino/

// have changed these pins for use of sd card logging on 50,51,52,53

int motorPin1 = 49;
int motorPin2 = 47;
int motorPin3 = 45;
int motorPin4 = 43;
int delayTime = 500;

// sd card logger

// CS=53, SCK/CLK=52, MOSI=51, MISO=50

Adafruit_MAX31865 max = Adafruit_MAX31865(42, 44, 46, 48);

// use hardware SPI, just pass in the CS pin
//Adafruit_MAX31865 max = Adafruit_MAX31865(10);

// The value of the Rref resistor. Use 430.0 for PT100 and 4300.0 for PT1000
#define RREF      430.0
// The 'nominal' 0-degrees-C resistance of the sensor
// 100.0 for PT100, 1000.0 for PT1000
#define RNOMINAL  100.0

// for SD card:

int chipSelect = 53; // CS=chip select pin for the MicroSD Card Adapter
File file; // file object that is used to read and write data
char filename[7]="monk00";
int nott=0;

void setup() {
  Serial.begin(115200);
  max.begin(MAX31865_2WIRE);  // set to 2WIRE or 4WIRE as necessary

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  pinMode(chipSelect, OUTPUT); // chip select pin must be set to OUTPUT mode
  
  if (!SD.begin(chipSelect)) { // Initialize SD card
    Serial.println("Could not initialize SD card."); // if return value is false, something went wrong.
  }

  // increment name of file

      strcpy(filename, "monk00");  filename[6]='\0';
    // open new file
      ////
      while(nott==0){

      for (filename[4] = '0'; filename[4] <= '9'; filename[4]++) {
	for (filename[5] = '0'; filename[5] <= '9'; filename[5]++) {
	  if(!SD.exists(filename)){
	    file = SD.open(filename, FILE_WRITE); // open "file.txt" to write data
	    nott=1;
	    break;
	  }
	  //	else file.close();
	if (nott==1) break;
	}
	if (nott==1) break;
      }
	}
      delay(2000);

      Serial.print("Opened filename: "); 
      Serial.println(filename);
}

void loop() {

  if (file) {
  uint16_t rtd = max.readRTD();
  uint16_t lighter;
  
  //  Serial.print("RTD value: "); Serial.println(rtd);
  float ratio = rtd;
  ratio /= 32768;
  //  Serial.print("Ratio = "); Serial.println(ratio,8);
  //  Serial.print("Resistance = "); Serial.println(RREF*ratio,8);
  //  Serial.print("Temperature = "); Serial.println(max.temperature(RNOMINAL, RREF));
  lighter=analogRead(0);
  Serial.print(lighter);
  Serial.print(", ");
  Serial.println(max.temperature(RNOMINAL, RREF));

  // concat lighter and temperature
  file.print(lighter);
  file.print(",");
  file.println(max.temperature(RNOMINAL, RREF)); // write number to file
  file.flush();
  }
  
  // test the motor pins

  // half stepping: - basic test but could be in array and forward backwards functions

  /*  0001
0011
0010
0110
0100
1100
1000
1001*/
  
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);

  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
  

  // Check and print any faults
  /*
  uint8_t fault = max.readFault();
  if (fault) {
    Serial.print("Fault 0x"); Serial.println(fault, HEX);
    if (fault & MAX31865_FAULT_HIGHTHRESH) {
      Serial.println("RTD High Threshold"); 
    }
    if (fault & MAX31865_FAULT_LOWTHRESH) {
      Serial.println("RTD Low Threshold"); 
    }
    if (fault & MAX31865_FAULT_REFINLOW) {
      Serial.println("REFIN- > 0.85 x Bias"); 
    }
    if (fault & MAX31865_FAULT_REFINHIGH) {
      Serial.println("REFIN- < 0.85 x Bias - FORCE- open"); 
    }
    if (fault & MAX31865_FAULT_RTDINLOW) {
      Serial.println("RTDIN- < 0.85 x Bias - FORCE- open"); 
    }
    if (fault & MAX31865_FAULT_OVUV) {
      Serial.println("Under/Over voltage"); 
    }
    max.clearFault();
    }*/
  //  Serial.println();
  //  delay(1);
}
