// NIKKI
#include <Arduino.h>
#include <Wire.h>
#include <i2c_enums.h>

bool ventStateGlobal;
bool dropStateGlobal;

void RxHandler(int numBytes){  // ! Won't we have to also check to see if it is a state request so we can return the current state?
  byte RxByte;
  while(Wire.available()){
    RxByte = Wire.read();
  }
  byte VentNybble = RxByte & 0x0F;
  byte DropNybble = (RxByte >> 4) & 0x0F;

  //If vent nybble is high, open vent. Otherwise close
  if(VentNybble == 0x0F){
    ventStateGlobal = true;
  }else{
    ventStateGlobal = false;
  }

  //If drop nybble is high, detach. Otherwise stay attached
  if(DropNybble == 0x0F){
    dropStateGlobal = true;
  }else{
    dropStateGlobal = false;
  }
}

void TxHandler(void){
  //TxByte = (DropByte << 4) | VentByte;
  //Wire.write(TxByte);
}

void setup() {
  Wire.begin(VENT_DROP);
  //Wire.begin(0x69);
  Wire.onReceive(RxHandler);
  Wire.onRequest(TxHandler);
}

void loop(){
  bool ventState = ventStateGlobal;
  bool dropState = dropStateGlobal;

  //If ventState is true, open. Otherwise close
  if(ventState){
    //Open Vent
  }else{
    //Close Vent
  }

  //If dropState is true, detatch
  if(dropState){
    //Open drop
  }else{
    //close drop
  }
}