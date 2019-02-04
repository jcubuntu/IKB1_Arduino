#include "IKB1.h"


IKB1::IKB1(){
    Wire.begin();
    Wire.beginTransmission(0x48);
    Wire.write(0);
    Wire.endTransmission();
}

void IKB1::reset(void){
    Wire.beginTransmission(0x48);
    Wire.write(0);
    Wire.endTransmission();
}

void IKB1::servo(uint8_t ch,int angle){
    angle = (angle > 200 ? 200 : angle);
    angle = (angle < -1 ? -1 : angle);
    Wire.beginTransmission(0x48);
    Wire.write(0x40+(1 << (ch-10)));
    Wire.write(angle);
    Wire.endTransmission();
}

void IKB1::motor(int8_t ch, uint8_t power) {
  if (ch > 0 && ch < 5) {
    Wire.beginTransmission(0x48);
    Wire.write(0x20 | (1 << (ch - 1)));
    Wire.write(power);
    Wire.endTransmission();
  }
  else if (ch == 12) {
    Wire.beginTransmission(0x48);
    Wire.write(0x23);
    Wire.write(power);
    Wire.endTransmission();
  }

}

void IKB1::motor_stop(int8_t ch) {
  if (ch > 0 && ch < 5) {
    Wire.beginTransmission(0x48);
    Wire.write(0x20 | (1 << (ch - 1)));
    Wire.write(0);
    Wire.endTransmission();
  }
  else if (ch == 12) {
    Wire.beginTransmission(0x48);
    Wire.write(0x23);
    Wire.write(0);
    Wire.endTransmission();
  }
}

void IKB1::ao(void) {
  Wire.beginTransmission(0x48);
  Wire.write(0x23);
  Wire.write(0);
  Wire.endTransmission();
}

void IKB1::fd(int8_t power) {
  power = (power > 100 ? 100 : power);
  power = (power < 0 ? 0 : power);
  Wire.beginTransmission(0x48);
  Wire.write(0x23);
  Wire.write(power);
  Wire.endTransmission();
}

void IKB1::bk(int8_t power) {
  power = (power > 100 ? 100 : power);
  power = (power < 0 ? 0 : power);
  Wire.beginTransmission(0x48);
  Wire.write(0x23);
  Wire.write(-power);
  Wire.endTransmission();
}

void IKB1::sl(int8_t power) {
  power = (power > 100 ? 100 : power);
  power = (power < 0 ? 0 : power);
  Wire.beginTransmission(0x48);
  Wire.write(0x21);
  Wire.write(-power);
  Wire.endTransmission();
  Wire.beginTransmission(0x48);
  Wire.write(0x22);
  Wire.write(power);
  Wire.endTransmission();
}

void IKB1::sr(int8_t power) {
  power = (power > 100 ? 100 : power);
  power = (power < 0 ? 0 : power);
  Wire.beginTransmission(0x48);
  Wire.write(0x21);
  Wire.write(power);
  Wire.endTransmission();
  Wire.beginTransmission(0x48);
  Wire.write(0x22);
  Wire.write(-power);
  Wire.endTransmission();
}

void IKB1::tl(int8_t power) {
  power = (power > 100 ? 100 : power);
  power = (power < 0 ? 0 : power);
  Wire.beginTransmission(0x48);
  Wire.write(0x21);
  Wire.write(0);
  Wire.endTransmission();
  Wire.beginTransmission(0x48);
  Wire.write(0x22);
  Wire.write(power);
  Wire.endTransmission();
}

void IKB1::tr(int8_t power) {
  power = (power > 100 ? 100 : power);
  power = (power < 0 ? 0 : power);
  Wire.beginTransmission(0x48);
  Wire.write(0x21);
  Wire.write(power);
  Wire.endTransmission();
  Wire.beginTransmission(0x48);
  Wire.write(0x22);
  Wire.write(0);
  Wire.endTransmission();
}

int IKB1::analog(uint8_t ch){
    uint8_t data[2];
    Wire.beginTransmission(0x48);
    Wire.write(0x80 + (ch << 4));
    Wire.endTransmission();
    Wire.requestFrom(0x48, 2);
    if(Wire.available() == 2){
        data[0] = Wire.read();
        data[1] = Wire.read();
    }
    int raw_adc = ((data[0] & 0x0F) * 256) + data[1];
    return raw_adc;
}

int IKB1::in(uint8_t ch){
    uint8_t data;
    Wire.beginTransmission(0x48);
    Wire.write(8 + ch);
    Wire.write(2);
    Wire.endTransmission();
    Wire.requestFrom(0x48, 1);
    if(Wire.available() == 1) data = Wire.read();
    return data;
}

void IKB1::out(int8_t ch, bool state){
    Wire.beginTransmission(0x48);
    Wire.write(8 + ch);
    Wire.write(state);
    Wire.endTransmission();
}