#include "core/modules/vent_drop.h"
#include "i2c_enums.h"
#include <Wire.h>


bool VentDrop::setDrop(DropState dropCommand) {

    // Telling it the command
    Wire.beginTransmission(address);
    Wire.write(DATA_TRANSFER);
    Wire.write(dropCommand);

    // Requesting a response expecting the same command echoed back
    Wire.requestFrom(address, 1);
    if (Wire.available()) {
        if (Wire.read() == dropCommand) {

            // We got a satisfactory response
            Wire.endTransmission();
            return true;

        }
    }

    Wire.endTransmission();

    // If we get here, then we did not get a good acknowledgement
    return false;

}


bool VentDrop::setVent(VentState ventCommand) {

    // Telling it the command
    Wire.beginTransmission(address);
    Wire.write(DATA_TRANSFER);
    Wire.write(ventCommand);

    // Requesting a response expecting the same command echoed back
    Wire.requestFrom(address, 1);
    if (Wire.available()) {
        if (Wire.read() == ventCommand) {

            // We got a satisfactory response
            Wire.endTransmission();
            return true;

        }
    }

    Wire.endTransmission();

    // If we get here, then we did not get a good acknowledgement
    return false;

}


bool VentDrop::getState() {

    // Requesting the information from the module
    Wire.beginTransmission(address);
    Wire.write(DATA_TRANSFER);
    Wire.requestFrom(address, 1);

    // Reading the information
    while (Wire.available()) {

        // TODO Read information from the Vent/Drop module 
        // And write it to the data struct
        return false;
    }

    return true;

}

