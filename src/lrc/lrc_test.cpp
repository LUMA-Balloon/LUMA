#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    Serial.println("ECHO 1");
    Serial.println("MYCALL K4UAH");
    Serial.println("MYALIAS LRC_TEST");
    Serial.println("MON all");
}

void loop() {
    test_lrc();
    delay(1000);
}

void test_lrc() {
    Serial.println("UNPROTO DROP_TEST");
}