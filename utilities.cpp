#include "utilities.h"

void print_array(const uint8_t array[])
{
    for (uint8_t i = 0; i < ARRAY_SIZE; i++) {
        Serial.print(array[i]);
        Serial.print(" ");
    }
    Serial.println(" ");
}

void inject_all(Button& button, Button& lever,
                Joystick& j_l, Joystick& j_r, Joystick& p_l, Joystick& p_r)
{
    button.inject_value();
    lever.inject_value();
    j_l.inject_values();
    j_r.inject_values();
    p_r.inject_values();
    p_l.inject_values();
}

void update_all(Button& button, Button& lever,
                Joystick& j_l, Joystick& j_r, Joystick& p_l, Joystick& p_r)
{
    button.set_value(dataTrasnfer[0]);
    lever.set_value(dataTrasnfer[1]);
    j_l.set_values(dataTrasnfer[2], dataTrasnfer[3]);
    j_l.set_values(dataTrasnfer[4], dataTrasnfer[5]);
    p_l.set_values(dataTrasnfer[6], dataTrasnfer[7]);
    p_r.set_values(dataTrasnfer[8], dataTrasnfer[9]);
}