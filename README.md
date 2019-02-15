# IKB1_Arduino

![iKB-1](https://raw.githubusercontent.com/jcubuntu/pxt-iKB1/master/icon.png)

The package adds support for the [iKB-1](https://inex.co.th/shop/ikb-1-board.html) conroller board from Innovative Experiment [INEX](https://inex.co.th).

## !Caution do not use iKB-1 with i-BIT board the I2C Address is same ADC IC on i-BIT board  (0x48)

###IKB1 Arduino Library function

* reset() This function for reset IKB-1
```C++
reset();
```

* servo(ch, angle) This function for control servo ch is port on IKB1
```C++
servo(10,100); // Set servo on port 10 to 100 degree
```
* motor(ch, power) This function for control dc motor driver on IKB1
```C++
motor(1,100); // Set motor 1 to forawrd power 100%
```



### Examaple for use Lib

* Create object 
```C++
IKB1 ikb1;
```

* Simple use control motor

```C++
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
  

}
```
