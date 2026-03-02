// Universal i2c functions allowing for easy encoding and decoding into binary for i2c and radio messages

#include <Wire.h>

// A simple struct to return (so that you can know the length of the array)
struct Bytes {
    byte* data;
    int length;
};

// These are the basic conversions
template <typename T>
Bytes toBytes(T input);
double toDouble(Bytes input);
int toInt(Bytes input);
float toFloat(Bytes input); // I'm not quite sure why I made this because we already have double 🤷

// Here is the basic sending implementation. It will convert anything to a Bytes object to send
// Note that we currently only have unpacking functions written for ints, floats, and doubles
template <typename T>
bool send(TwoWire wire, int address, T toSend);

// The same as the basic send, but this takes an array of Bytes objects to send
// This allows for sending multiple values in the same call
bool send(TwoWire wire, int address, Bytes* toSend, int length);




