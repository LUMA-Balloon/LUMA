
#include "utilities/i2c_utils.h"
#include <Wire.h>

// Note that none of these have actually been tested

double toDouble (Bytes input) {

    long long out = (long long) (0);

    for (int i = 0; i < input.length; i++) {
        out = (out << 8);
    }

    // Now we have the bytes of the double
    return (double) out;

}


int toInt(Bytes input) {
    long long out = (long long) (0);

    for (int i = 0; i < input.length; i++) {
        out = (out << 8);
    }

    // Now we have the bytes of the int
    return (int) out;

}


float toFloat(Bytes input) {
    long long out = (long long) (0);

    for (int i = 0; i < input.length; i++) {
        out = (out << 8);
    }

    // Now we have the bytes of the float
    return (float) out;

}


// bool yell(int address, Bytes* toSend, int length) {
//     Wire.beginTransmission(address);
//     for (int i = 0; i < length; i++) {
//         Wire.write(toSend[i].data, toSend[i].length);
//     }
//     return Wire.endTransmission() == 0;
// }
