// Testing I2C communication with Vent/Drop
#include <Wire.h>
#include "i2c_enums.h"


void setup() {
    Wire.begin();
    Serial.begin(9600);
}


void loop() {

    // Turning both on
    Wire.beginTransmission(VENT_DROP);
    Wire.write(0xFF);
    Wire.endTransmission();
    Serial.println("Both");

    // Waiting 1 second
    delay(1000);

    // Turning just one on 
    Wire.beginTransmission(VENT_DROP);
    Wire.write(0x0F);
    Wire.endTransmission();
    Serial.println("Vent");
    
    // Waiting 1 second
    delay(1000);

    // Turning the other one on 
    Wire.beginTransmission(VENT_DROP);
    Wire.write(0xF0);
    Wire.endTransmission();
    Serial.println("Drop");

    // Waiting 1 second
    delay(1000);

    // Turning both of them off
    Wire.beginTransmission(VENT_DROP);
    Wire.write(0x00);
    Wire.endTransmission();
    Serial.println("Off");
    
    // Waiting 1 second
    delay(1000);

}

