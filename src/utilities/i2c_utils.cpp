#include "utilities/i2c_utils.h"
#include <Wire.h>

// Note that none of these have actually been tested

template <typename T>
Bytes toBytes(T input) {
    Bytes output;
    output.length = sizeof(input);
    output.data = (byte *)&input;
    return output;
}

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

template <typename T>
bool send(TwoWire wire, int address, T toSend) {

    Bytes bytes = toBytes(toSend);

    wire.beginTransmission(address);

    wire.write(bytes.data, bytes.length);

    // The transaction was successful if we get a 0 from the end transmission
    if (wire.endTransmission() != 0) {
        return false; 
    }

}

