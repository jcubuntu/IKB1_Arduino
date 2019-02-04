#include "IKB1.h"

IKB1 ikb1;

void setup() {
  // Motor 1 & 2 Forward power 50%
  ikb1.motor(1,50);
  ikb1.motor(2,50);
  // Wait 1 Sec.
  delay(1000);
  // motor Stop
  ikb1.motor_stop(ALL);

  // Motor 1 & 2 Forward power 50%
  ikb1.fd(50);
  // Wait 1 Sec.
  delay(1000);
  // motor Stop
  ikb1.ao();

  // Motor 1 & 2 Backward power 50%
  ikb1.bk(50);
  // Wait 1 Sec.
  delay(1000);
  // motor Stop
  ikb1.ao();

  // Motor 1 Backward  2 Forward power 50%
  ikb1.sl(50);
  // Wait 1 Sec.
  delay(1000);
  // motor Stop
  ikb1.ao();

   // Motor 1 Forward  2 Backward power 50%
  ikb1.sr(50);
  // Wait 1 Sec.
  delay(1000);
  // motor Stop
  ikb1.ao();

   // Motor 1 to 0 and  2 Forward power 50%
  ikb1.tl(50);
  // Wait 1 Sec.
  delay(1000);
  // motor Stop
  ikb1.ao();

   // Motor 1 Forward power 50% and 2 to 0
  ikb1.tr(50);
  // Wait 1 Sec.
  delay(1000);
  // motor Stop
  ikb1.ao();
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
