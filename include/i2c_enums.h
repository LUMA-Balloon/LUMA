// Might it be a good idea to force all of these to be a fixed size?
// Then we can request that many bytes over I2C easily

// These will be updated to real numbers later
enum TargetAddresses {
    LONG_RANGE_COMMS = 0,
    VENT_DROP = 0
};

enum SensorType {
    GPS_SENSOR = 0,
    BAROMETRIC = 0,
    ASCENT = 0,
    PAYLOAD = 0,
    BATTERY_VOLTAGE = 0,
};

enum Secret {
    IS_PAYLOAD_DEAD = 0,
    AHHHHHHHHH = 0,
    STINKY = 0
};

// Added by Sam, we can remove if not needed
enum i2cAction {
    HEARTBEAT = 0,
    DATA_TRANSFER = 0,
    PAYLOAD_DATA_TRANSFER = 0,
    COMMAND_TRANSFER = 0,
    PAYLOAD_COMMAND_TRANSFER = 0,
};


