#include <Arduino.h>

#include "button/button.h"
#include "display/display.h"
#include "fsm/fsm.h"
#include "led/led.h"

#define LED_PIN 8
#define BTN_PIN 2

#define BLINK_INTERVAL 500

static unsigned long lastBlinkTime = 0;
static bool blinkLedState = false;

void setup() {
    Serial.begin(9600);

    fsmInit();

    ledInit(LED_PIN);
    buttonInit(BTN_PIN);
    displayInit();

    ledSet(false);

    Serial.println("System ready");
    Serial.println("State: OFF");
}

void loop() {
    bool event = buttonReadEvent();

    if (event) {
        fsmUpdate(event);

        State state = fsmGetState();

        displayUpdate(state);

        Serial.print("State changed to: ");

        switch (state) {
            case STATE_OFF:
                Serial.println("OFF");
                break;

            case STATE_ON:
                Serial.println("ON");
                break;

            case STATE_BLINK:
                Serial.println("BLINK");
                break;
        }
    }

    State state = fsmGetState();

    switch (state) {
        case STATE_OFF:
            ledSet(false);
            blinkLedState = false;
            break;

        case STATE_ON:
            ledSet(true);
            blinkLedState = false;
            break;

        case STATE_BLINK:
            if (millis() - lastBlinkTime >= BLINK_INTERVAL) {
                lastBlinkTime = millis();

                blinkLedState = !blinkLedState;

                ledSet(blinkLedState);
            }
            break;
    }
}