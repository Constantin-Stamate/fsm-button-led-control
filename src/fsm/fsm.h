#ifndef FSM_H
#define FSM_H

enum State {
    STATE_OFF,
    STATE_ON,
    STATE_BLINK
};

void fsmInit();
void fsmUpdate(bool event);
State fsmGetState();

#endif