#include <Arduino.h>
#include "button.h"

static int btnPin;

static bool lastButtonState = HIGH;
static bool stableButtonState = HIGH;

static unsigned long lastDebounce = 0;

const unsigned long debounceDelay = 50;

void buttonInit(int pin) {
    btnPin = pin;

    pinMode(btnPin, INPUT_PULLUP);

    lastButtonState = digitalRead(btnPin);
    stableButtonState = lastButtonState;

    lastDebounce = millis();
}

bool buttonReadEvent() {
    bool reading = digitalRead(btnPin);

    bool event = false;

    if (reading != lastButtonState) {
        lastDebounce = millis();
    }

    if ((millis() - lastDebounce) > debounceDelay) {
        if (reading != stableButtonState) {
            stableButtonState = reading;

            if (stableButtonState == LOW) {
                event = true;
            }
        }
    }

    lastButtonState = reading;

    return event;
}