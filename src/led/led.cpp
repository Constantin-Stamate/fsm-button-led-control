#include <Arduino.h>
#include "led.h"

static int ledPin;

void ledInit(int pin) {
    ledPin = pin;

    pinMode(ledPin, OUTPUT);

    digitalWrite(ledPin, LOW);
}

void ledSet(bool on) {
    digitalWrite(ledPin, on ? HIGH : LOW);
}