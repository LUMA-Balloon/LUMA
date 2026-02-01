#pragma once
#include <string>

enum FlightState {
    INITIALIZATION,
    STANDBY,
    LAUNCH_READY,
    FLIGHT,
    LANDED,
};

enum VentState {
    OPEN,
    CLOSE,
};

enum DropState {
    ATTACH,
    DETACH,
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

struct Target {
    float altitude;         // Perchance // m MSL
    VentDropState ventDrop; // Where we are trying to go 
};

struct VentDropState { // Defaulted to attached and closed
    VentState ventState = CLOSE;
    DropState dropState = ATTACH;
};

struct Data {
    unsigned long packetCount = 0;
    unsigned long missionTime = 0;  // ms
    FlightState state = FlightState::STANDBY;
    Vector acceleration; // m/s
    Vector gyro; // deg/s
    Vector orientation; // deg
    GPS gps;
    Atmospheric atmo;
    Target target;
    VentDropState ventDrop;
};