#include "utilities.h"

void printarray(byte stuffToSend[]) {
    for (byte i = 0; i < 13; i++)
        std::cout << stuffToSend[i] << " ";
    std::cout << std::endl;
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
                byte stuffToSend[])
{
    button.set_value(stuffToSend[0]);
    lever.set_value(stuffToSend[1]);
    j_l.set_values(stuffToSend[2], stuffToSend[3]);
    j_l.set_values(stuffToSend[4], stuffToSend[5]);
    p_l.set_values(stuffToSend[6], stuffToSend[7]);
    p_r.set_values(stuffToSend[8], stuffToSend[9]);
}
