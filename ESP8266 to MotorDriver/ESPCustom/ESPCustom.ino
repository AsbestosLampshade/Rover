#include "MotorControls.hpp"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Entering Loop");
  pinMode(SER,OUTPUT);
  pinMode(ENABLE,OUTPUT);
  pinMode(PWM_M1,OUTPUT);
  pinMode(PWM_M2,OUTPUT);
  pinMode(CLK,OUTPUT);
  pinMode(LATCH,OUTPUT);
  digitalWrite(CLK,LOW);
  digitalWrite(SER,LOW);
  digitalWrite(ENABLE,LOW);
  digitalWrite(LATCH,LOW);
  analogWrite(PWM_M1,0);
  analogWrite(PWM_M2,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    switch(Serial.read()){
      uint8_t val;
      case '1':
        setPins(0x10);
        break;
      case '0':
        setPins(0x00);
        break;
      case '2':
        setPins(0x20);
        break;
      case '3':
        setPins(0x30);
        break;
      case '4':
        setPins(0x08);
        break;
      case '5':
        setPins(0x48);
        break;
      case '6':
        setPins(0x40);
        break;
      case 'p':
        val=Serial.parseInt();
        analogWrite(PWM_M1,val);
        Serial.flush();
        break;
      case 'q':
        val=Serial.parseInt();
        analogWrite(PWM_M2,val);
        Serial.flush();
        break;
    }
  }
}
