#include <Wire.h>

int inputleft=6; // stepper switch
int inputright=7; // stepper switch
int motoren=8;
int step=2;
int dirr=3;
int whereweare=0, lefthit=0, righthit=0;


void setup() {
  pinMode(7, OUTPUT);
  Serial.begin(9600); // start serial for output
  //  pinMode(inputleft, INPUT_PULLUP);
}

void loop() {
  digitalWrite(7, HIGH);
  delay(6000);
  digitalWrite(7, LOW);
  delay(3000);  
  }
