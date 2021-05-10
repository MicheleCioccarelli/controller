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
                Joystick& j_l, Joystick& j_r, Potentiometer& p_l, Potentiometer& p_r)
{
    button.inject_values();
    lever.inject_values();
    j_l.inject_values();
    j_r.inject_values();
    p_l.inject_values();
    p_r.inject_values();
}

void update_all(Button& button, Button& lever,
                Joystick& j_l, Joystick& j_r, Potentiometer& p_l, Potentiometer& p_r)
{
    button.set_values(dataReceived[0]);
    lever.set_values(dataReceived[1]);
    j_l.set_values(dataReceived[2], dataReceived[3]);
    j_l.set_values(dataReceived[4], dataReceived[5]);
    p_l.set_values(dataReceived[6]);
    p_r.set_values(dataReceived[7]);
}
