#include "IKB1.h"

IKB1 ikb1;

void setup() {



}

void loop() {
  for (int  i = 1; i <= 180; i++) {
    // set servo port 10 degree to i
    ikb1.servo(10, i);
    delay(20);
  }
  for (int  i = 180; >= 1; i--) {
    // set servo port 10 degree to i
    ikb1.servo(10, i);
    delay(20);
  }

}
