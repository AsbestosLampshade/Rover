#include "MotorControls.hpp"
#define startTime 100
uint8_t startingTorque=0x64;
bool M1inMotion=false,M2inMotion=false;
uint8_t myval=0x00;
void setPins(uint8_t val){
    shiftOut(SER, CLK, LSBFIRST, val);
    digitalWrite(LATCH,HIGH);
    delay(1);
    digitalWrite(LATCH,LOW);
}
void Motion(int motor,bool inversion,uint8_t pwm){
  if(motor==1){
      if(pwm==0){
        M1inMotion=false;
      }
      if(!inversion){
        if(!M1inMotion){
          myval=0xEF&myval;
          myval=myval|0x20;
          setPins(myval);
          analogWrite(PWM_M1,startingTorque);
          delay(startTime);
        }
        myval=0xEF&myval;
        myval=myval|0x20;
        setPins(myval);
        analogWrite(PWM_M1,pwm);
        Serial.println("M1 standard");
        M1inMotion=true;
      }
      else{
        if(!M1inMotion){
          myval=0xDF&myval;
          myval=myval|0x10;
          setPins(myval);
          analogWrite(PWM_M1,startingTorque);
          delay(startTime);
        }
        myval=0xDF&myval;
        myval=myval|0x10;
        setPins(myval);
        analogWrite(PWM_M1,pwm);
        Serial.println("M1 inv");
        M1inMotion=true;
      }
  }
  else if(motor==2){
      if(pwm==0){
        M1inMotion=false;
      }
      if(!inversion){
        if(!M2inMotion){
          myval=0xF7&myval;
          myval=myval|0x40;
          setPins(myval);
          analogWrite(PWM_M2,startingTorque);
          delay(startTime);
        }
        myval=0xF7&myval;
        myval=myval|0x40;
        setPins(myval);
        analogWrite(PWM_M2,pwm);
        Serial.println("M2 standard");
        M2inMotion=true;

      }
      else{
        if(!M2inMotion){
          myval=0xBF&myval;
          myval=myval|0x08;
          setPins(myval);
          analogWrite(PWM_M2,startingTorque);
          delay(startTime);
        }
        myval=0xBF&myval;
        myval=myval|0x08;
        setPins(myval);
        analogWrite(PWM_M2,pwm);
        Serial.println("M2 inv");
        M2inMotion=true;
      }
  }
  else{
    Serial.print("Bad input - motor");
  }
}