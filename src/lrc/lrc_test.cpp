#include <Arduino.h>

// 0 for send, 1 for receive
int a = 0;


// Setup the thingy
void setup() {
    // this is the baud rate for pico_TNC
    Serial.begin(115200);

    // go ahead and turn on the echo so we can see the output (I don't think we need this since we're not reading it)
    Serial.println("ECHO 1");
    
    // set our callsign and alias 
    Serial.println("MYCALL K4UAH");
    Serial.println("MYALIAS LRC_TEST");

}

void loop() {
    // send a buttload of packets and blink light when they send. If there's an error it'll just crash and the light will... uh
    test_lrc();
    delay(1000);
}

void test_lrc() {
    // send a bunch if it's not in receive mode
    if (receive_mode() == 0) {
        Serial.println("UNPROTO DROP_TEST\n");
        
        // blink the light so we know it's alive
        digitalWrite(LED_BUILTIN, HIGH);
        delay(100);
        digitalWrite(LED_BUILTIN, LOW);
    }

    // if in receive mode go ahead and listen only.
    // technically these aren't mutually exclusive.
    else if (receive_mode() == 1) {
        // this will print everything incoming on the serial
        Serial.println("MON all");

        // if we get the packet we sent, blink the light so we know it worked
        if (Serial.readString() == "DROP_TEST") {
            // blink the light so we know we got it
            digitalWrite(LED_BUILTIN, HIGH);
            delay(100);
            digitalWrite(LED_BUILTIN, LOW);
        }
    }


}

// this is really dumb for now but will be useful when we can change stuff.
bool receive_mode() {
    return a == 0 ? 0 : 1;
}