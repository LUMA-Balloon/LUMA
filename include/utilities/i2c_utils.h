#pragma once
// Universal i2c functions allowing for easy encoding and decoding into binary for i2c and radio messages

#include <Wire.h>

// A simple struct to return (so that you can know the length of the array)
struct Bytes {
    byte* data;
    size_t length;
};

// These are the basic conversions
template <typename T>
Bytes toBytes(T &input) {
    Bytes output;
    output.length = sizeof(input);

    output.data = (byte*)&input;
    return output;
}

double toDouble(Bytes input);
int toInt(Bytes input);
float toFloat(Bytes input); // I'm not quite sure why I made this because we already have double 🤷

// Here is the basic sending implementation. It will convert anything to a Bytes object to send
// Note that we currently only have unpacking functions written for ints, floats, and doubles
// template <typename T>
// bool yell(int address, T toSend);


template <typename T>
bool yell(int address, T toSend) {

    Bytes bytes = toBytes(toSend);

    Serial.print("Prepping to print: ");
    for (int i = 0; i < bytes.length; i++) {
        Serial.print(bytes.data[i], HEX);
    }
    Serial.print(" with length ");
    Serial.println(bytes.length);

    Wire.beginTransmission(address);

    Wire.write(bytes.data, bytes.length);

    // The transaction was successful if we get a 0 from the end transmission
    return Wire.endTransmission() == 0;
    return false;

}
// The same as the basic send, but this takes an array of Bytes objects to send
// This allows for sending multiple values in the same call
// bool yell(int address, Bytes* toSend, int length);




