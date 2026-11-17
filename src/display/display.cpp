#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#include "display.h"

static LiquidCrystal_I2C lcd(0x27, 16, 2);

static State lastDisplayedState = STATE_OFF;

void displayInit() {
    lcd.init();
    lcd.backlight();
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("State: OFF");

    lastDisplayedState = STATE_OFF;
}

void displayUpdate(State state) {
    if (state != lastDisplayedState) {
        lcd.setCursor(0, 0);
        lcd.print("State:          ");

        lcd.setCursor(0, 0);
        lcd.print("State: ");

        switch (state) {
            case STATE_OFF:
                lcd.print("OFF");
                break;

            case STATE_ON:
                lcd.print("ON");
                break;

            case STATE_BLINK:
                lcd.print("BLINK");
                break;
        }

        lastDisplayedState = state;
    }
}