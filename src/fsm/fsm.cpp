#include "fsm.h"

static State currentState = STATE_OFF;

void fsmInit() {
    currentState = STATE_OFF;
}

void fsmUpdate(bool event) {
    if (event) {
        switch (currentState) {
            case STATE_OFF:
                currentState = STATE_ON;
                break;

            case STATE_ON:
                currentState = STATE_BLINK;
                break;

            case STATE_BLINK:
                currentState = STATE_OFF;
                break;
        }
    }
}

State fsmGetState() {
    return currentState;
}