#pragma once
#include <string>

enum FlightState {
    // TODO CHANGE TO STATE MACHINE
    STANDBY,
};

struct Vector {
    // Unitless here. Units defined elsewhere.
    double x;
    double y;
    double z;
};

struct Position {
    double lat;  // DD.dddd
    double lon;  // DD.dddd
    double alt;  // m MSL
};

struct UTCTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

    // Add function for string representation later if we care.
};

struct GPS {
    Position pos;
    UTCTime time;
    int SIV;
};

struct Atmospheric {
    float pressure;     // Pa?
    float temperature;  // deg C?
    float alt;          // m MSL
    float humidity;     // percent
};

// TODO add a target 

struct Data {
    unsigned long packetCount = 0;
    unsigned long missionTime = 0;  // ms
    FlightState state = FlightState::STANDBY;
    Vector acceleration; // m/s
    Vector gyro; // deg/s
    Vector orientation; // deg
    GPS gps;
    Atmospheric atmo;
};