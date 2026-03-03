#include "modules.h"


class LRC : Module {

public:

    // Sets all of the sensor data at once on the LRC to be sent to the ground
    bool setSensorData();

    // Gets the most recent command received from the radio and saves it in data.
    bool getCommand();

    // Sets the payload data on the LRC that it will transmit to the ground.
    bool setPayloadData();

    // Gets the most recent payload command received from the radio and saves it in data.
    bool getPayloadCommand();

    // Setters for all of the data, added so that we can request specific information in i2c communications
    bool setPacketCount();
    bool setMissionTime();
    bool setFlightState();
    bool setAcceleration();
    bool setGyro();
    bool setOrientation();
    bool setPosition();
    bool setUTCTime();
    bool setSIV();
    bool setAtmoData();
    
};