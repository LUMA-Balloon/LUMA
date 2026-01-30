#include "modules.h"


class LRC : Module {

public:

    // Sets the sensor data on the LRC that it will transmit to the ground.
    bool setSensorData();

    // Gets the most recent command recieved from the radio and saves it in data.
    bool getCommand();

    // Sets the payload data on the LRC that it will transmit to the ground.
    bool setPayloadData();

    // Gets the most recent payload command recieved from the radio and saves it in data.
    bool getPayloadCommand();
};