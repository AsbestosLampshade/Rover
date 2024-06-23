#include <MotorDriver.h>
#define START_TORQUE 120
#define START_TIME 50
#define IDLE_TORQUE 50
#define IDLE_TIME 2000
MotorDriver m;
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   Serial.println("Entering Loop");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    switch(Serial.read()){
      case 'F':
        m.motor(1, FORWARD, START_TORQUE);
        delay(START_TIME);
        m.motor(1, FORWARD, IDLE_TORQUE);
        delay(IDLE_TIME);
        m.motor(1, RELEASE, 0);
      break;
      case 'R':
        m.motor(1, BACKWARD, START_TORQUE);
        delay(START_TIME);
        m.motor(1, BACKWARD, IDLE_TORQUE);
        delay(IDLE_TIME);
        m.motor(1, RELEASE, 0);
      break;
    }
  }
}
