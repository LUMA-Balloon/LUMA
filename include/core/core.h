// Just like HAVOC.h, this is where global variables and functions will go for the core module

#pragma once
#include <Arduino.h>
#include "config.h"
#include "data.h"
#include "board-io/sensors.h"
#include "board-io/telemetry.h"
#include "core/errorLED.h"

extern Config config;
extern Data data;
extern Sensors sensors; 
extern SPILogger logger;
extern ErrorLED errorLED; 