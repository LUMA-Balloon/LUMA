// Testing I2C communication with Vent/Drop
#include <Wire.h>
#include "i2c_enums.h"
#include "utilities/i2c_utils.h"

void setup() {
    Wire.begin();
    Serial.begin(9600);
}

const double doubleToSend = 69.69;
const float floatToSend = 96.0;
const int intToSend = 69;

void loop() {

    // Turning both on
    yell(VENT_DROP, (byte)0x0F);
    
    // Waiting 1 second
    delay(1000);

    yell(VENT_DROP, (byte)0xF0);

    // Waiting 1 second
    delay(1000);
 
    yell(VENT_DROP, (byte)0x00);

    delay(1000);

    yell(VENT_DROP, (byte)0xFF);

    delay(1000);


    // // Waiting 1 second
    // delay(1000);

}

