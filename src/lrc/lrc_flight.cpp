// NIKKI
#include <Arduino.h>
#include <Wire.h>
#include <i2c_enums.h>

void RxHandler(int numBytes){

}

void TxHandler(void){

}

void setup(){
  Wire.begin(LONG_RANGE_COMMS);
  Wire.onReceive(RxHandler);
  Wire.onRequest(TxHandler);
}

void loop(){

}