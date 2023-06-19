#include <Servo.h>
Servo servo;

int pos = 0;
char in;
int PinA = 2;
int PinB = 3;
int enable = 11;

void Forward(){
  servo.write(135);
  digitalWrite(PinB, LOW);
  digitalWrite(PinA, HIGH);
}
void Backward(){
  servo.write(139);
  digitalWrite(PinB, HIGH);
  digitalWrite(PinA, LOW);
}
void Right(){
  servo.write(175);
}
void Left(){
  servo.write(90);
}
void Stop(){
  servo.write(139);
  digitalWrite(PinA, LOW);
  digitalWrite(PinB, LOW);
}

void setup() {
  servo.attach(9);
  pinMode(PinA, OUTPUT);
  pinMode(PinB, OUTPUT);
  pinMode(enable, OUTPUT);
  analogWrite(enable,250);
  Forward(); delay(6000);
  Left(); delay(6000);
  Forward(); delay(6000);
  Stop(); 
}

void loop(){}
