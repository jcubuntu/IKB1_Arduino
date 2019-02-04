#ifndef IKB1_H
#include "Wire.h"
#include "Arduino.h"

#define IKB1_H

#define ALL 12
#define ON   1
#define OFF  0

class IKB1{
    
    public  :
        IKB1();
        void reset(void);
        void servo(uint8_t ch,int angle);
        void motor(int8_t ch, uint8_t power);
        void motor_stop(int8_t ch);
        void ao(void);
        void fd(int8_t power);
        void bk(int8_t power);
        void sl(int8_t power);
        void sr(int8_t power);
        void tl(int8_t power);
        void tr(int8_t power);
        int analog(uint8_t ch);
        int in(uint8_t ch);
        void out(int8_t ch, bool state);

};


#endif