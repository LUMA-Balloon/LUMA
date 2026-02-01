#include "core/modules/modules.h"
#include <Wire.h>
#include "i2c_enums.h"

// The implementation of the heartbeat for every module
bool Module::isConnected() {

    // Requesting one byte from the module
    Wire.beginTransmission(address);
    Wire.write(HEARTBEAT);
    Wire.endTransmission();
    Wire.requestFrom(address, 1);
   
    // Reading the response
    if (Wire.available()) {
        if (Wire.read() == HEARTBEAT) {
            return true;
        }
    }
    return false;

}

