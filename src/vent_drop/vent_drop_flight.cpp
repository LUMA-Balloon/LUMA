// NIKKI
#include <Arduino.h>
#include <Wire.h>
#include <i2c_enums.h>

bool ventStateGlobal;
bool dropStateGlobal;

int ventLED = 16;
int dropLED = 17;


void RxHandler(int numBytes){ 
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

  // Testing stuff for I2C
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
}

void TxHandler(void){
  //TxByte = (DropByte << 4) | VentByte;
  //Wire.write(TxByte);
}

void setup() {
  Serial.begin(9600);
  Wire.begin(VENT_DROP);
  //Wire.begin(0x69);
  Wire.onReceive(RxHandler);
  Wire.onRequest(TxHandler);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ventLED, OUTPUT);
  pinMode(dropLED, OUTPUT);
}

void loop() {
  bool ventState = ventStateGlobal;
  bool dropState = dropStateGlobal;

  //If ventState is true, open. Otherwise close
  if(ventState){
    //Open Vent
    digitalWrite(ventLED, HIGH);
  }else{
    //Close Vent
    digitalWrite(ventLED, LOW);
  }

  //If dropState is true, detatch
  if(dropState){
    //Open drop
    digitalWrite(dropLED, HIGH); 
  }else{
    //close drop
    digitalWrite(dropLED, LOW);
  }
}