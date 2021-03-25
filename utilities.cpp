#include "utilities.h"

void print_array(byte array[])
{
    for (int i = 0; i < ARRAY_SIZE; i++) {
        Serial.print(array[i]);
        Serial.print(" ");
    }
    Serial.println(" ");
}

void inject_all(Button button, Button lever,
                Joystick j_l, Joystick j_r, Joystick p_l, Joystick p_r,
                byte stuffToSend[])
{
    button.inject_value(stuffToSend);
    lever.inject_value(stuffToSend);
    j_l.inject_values(stuffToSend);
    j_r.inject_values(stuffToSend);
    p_l.inject_values(stuffToSend);
    p_r.inject_values(stuffToSend);
}

void update_all(Button button, Button lever,
                Joystick j_l, Joystick j_r, Joystick p_l, Joystick p_r,
                byte dataReceived[])
{
    button.set_value(dataReceived[0]);
    lever.set_value(dataReceived[1]);
    j_l.set_values(dataReceived[2], dataReceived[3]);
    j_l.set_values(dataReceived[4], dataReceived[5]);
    p_l.set_values(dataReceived[6], dataReceived[7]);
    p_r.set_values(dataReceived[8], dataReceived[9]);
}
