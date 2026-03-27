#pragma once

// These will be updated to real numbers later
enum TargetAddresses {
    LONG_RANGE_COMMS = 0x55,
    VENT_DROP = 0x69,
};

enum DataType {
    GPS_RECEIVER = 0x33,
    BAROMETRIC = 0x5A,
    ASCENT_RATE = 0x3C,
    PAYLOAD_STATE = 0xAA,
    BATTERY_VOLTAGE = 0x99,
};

enum Command {
    OPEN_VENT = 0x0F,
    DETACH_DROP = 0xF0,    
    SET_TARGET_ALTITUDE = 0x96,
};

enum Secret {
    IS_PAYLOAD_DEAD = 0,
    AHHHHHHHHH = 0,
    STINKY = 0,
};

enum I2CAction {
    HEARTBEAT = 0xCC,
    DATA_TRANSFER = 0x66,
    PAYLOAD_DATA_TRANSFER = 0xC3,
    COMMAND_TRANSFER = 0xA5,
    PAYLOAD_COMMAND_TRANSFER = 0x5A,
};


// 00 - Vent Closed / DROP Closed
// 0F - Vent Open / DROP Closed
// 33 - GPS_SENSOR
// 3C - ASCENT_RATE
// 55 - LRC I2C Address
// 5A - BAROMETRIC  |  PAYLOAD_COMMAND_TRANSFER
// 66 - DATA_TRANSFER
// 69 - Vent/DROP I2C Address
// 96 - SET_TARGET_ALTITUDE
// 99 - BATTERY_VOLTAGE
// A5 - COMMAND_TRANSFER
// AA - PAYLOAD_STATE
// C3 - PAYLOAD_DATA_TRANSFER
// CC - HEARTBEAT
// F0 - Vent Closed / DROP Open
// FF - Vent Open / DROP Open