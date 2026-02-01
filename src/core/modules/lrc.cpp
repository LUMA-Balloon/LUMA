#include "core/modules/lrc.h"
#include "i2c_enums.h"
#include <Wire.h>
#include "core/core.h"
#include "data.h"

// ? Are we going to be parsing each incoming piece of data with a name in front of it?
// I mean, are we just sending everything in CSV format or are we adding labels?
// Here, I have added labels, but they should be simple to remove if needed

bool LRC::setSensorData() {


    Wire.beginTransmission(address); 

    // The type of transmission
    Wire.write(DATA_TRANSFER);

    // Packet count
    Wire.write(data.packetCount);
  
    // Mission time
    Wire.write(data.missionTime);
    
    // Flight State
    Wire.write(data.state);
      
    // Acceleration floats sent in bytes (x,y,z)
    Wire.write((byte *)&data.acceleration.x, sizeof(double));
    Wire.write((byte *)&data.acceleration.y, sizeof(double));
    Wire.write((byte *)&data.acceleration.z, sizeof(double));

    // Gryo (x,y,z)
    Wire.write((byte *)&data.gyro.x, sizeof(double));
    Wire.write((byte *)&data.gyro.y, sizeof(double));
    Wire.write((byte *)&data.gyro.z, sizeof(double));

    // Orientation (x,y,z)
    Wire.write((byte *)&data.orientation.x, sizeof(double));
    Wire.write((byte *)&data.orientation.y, sizeof(double));
    Wire.write((byte *)&data.orientation.z, sizeof(double));
    // Position (lat,long,alt)
    Wire.write((byte *)&data.gps.pos.lat, sizeof(double));
    Wire.write((byte *)&data.gps.pos.lon, sizeof(double));
    Wire.write((byte *)&data.gps.pos.alt, sizeof(double));

    // UTC Time biggest to smallest
    Wire.write(data.gps.time.year);
    Wire.write(data.gps.time.month);
    Wire.write(data.gps.time.day);
    Wire.write(data.gps.time.minute);
    Wire.write(data.gps.time.second);

    // SIV
    Wire.write(data.gps.SIV);

    // Atmospheric data
    Wire.write((byte *)&data.atmo.pressure, sizeof(double));
    Wire.write((byte *)&data.atmo.temperature, sizeof(double));
    Wire.write((byte *)&data.atmo.alt, sizeof(double));
    Wire.write((byte *)&data.atmo.humidity, sizeof(double));

    // TODO Add target stuff here

    Wire.endTransmission(); 

    return true;

};




bool LRC::getCommand() {

    // Initializing the connection with the LRC module
    Wire.beginTransmission(address);
    Wire.write(COMMAND_TRANSFER);
    Wire.endTransmission();

    // The number of bytes to be requested
    //      One for vent/drop
    //      Four for target altitude 
    int requestLength = 5;

    // Getting the actual data
    Wire.requestFrom(address, requestLength);

    for (int byteNum = 0; byteNum < requestLength; byteNum++) {

        // Checking to be safe
        if (!Wire.available()) {
            return false;
        }

        char incomingByte = Wire.read();

        switch (incomingByte) {
           
            case 0: { // Vent/Drop byte

                    // ! Where are we storing these things?
                    // I went ahead and added them to data.h
                
                    // Getting the VENT nybble (the lower nybble)
                    char vent = incomingByte & 0x0F;
                    
                    // Getting the DROP nybble (the upper nybble)
                    char drop = (incomingByte >> 4) & 0x0F;

                    // They are triggered if and only if they are exactly equal to the expected commands
                    if (vent == 0x0F) {
                        data.ventDrop.ventState = OPEN;
                    } else if (vent == 0x00) {
                        data.ventDrop.ventState = CLOSE;
                    }
                
                    if (drop == 0x0F) {
                        data.ventDrop.dropState = DETACH;
                    } else if (drop == 0x00) {
                        data.ventDrop.dropState = ATTACH;
                    } 

                } break;

            case 1: 
            case 2:
            case 3:
            case 4:

                return true;
                // TODO actually use these bytes 
                break;
        }

    }

    return false; // If we get here, something funky happened, so we can't return true

}

bool LRC::getPayloadCommand() {

    // Initializing the connection with the LRC module
    Wire.beginTransmission(address);
    Wire.write(PAYLOAD_COMMAND_TRANSFER);
    Wire.endTransmission();

    // The number of bytes we want 
    int requestLength = 2; // This will be updated later, right now we just have one byte: the payload ID
    
    Wire.requestFrom(address, requestLength);
   
    // TODO Update this for our first payload

    for (int byteNum = 0; byteNum < requestLength; byteNum++) {

        // Checking to be safe
        if (!Wire.available()) {
            return false;
        }

        char incomingByte = Wire.read();

        // Byte reading and whatnot

    }

    return false;
        
}


bool LRC::setPayloadData() {

    Wire.beginTransmission(address);
    Wire.write(PAYLOAD_DATA_TRANSFER);
    Wire.endTransmission();

    // We don't actually have any data to send, so we don't have much here

    return false;

}