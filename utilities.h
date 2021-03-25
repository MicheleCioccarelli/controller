#pragma once

#include <Arduino.h>
#include "classes.h"

/*
 * This function sets up stuffToSend[], it fills the array each time with the values provided,
 * anything unknown is defaulted as 0
 * this is the layout of the array:
 *
 *          | Button | Lever | j_l | j_r | p_l | p_r | unused | unused | unused | (9 elements)
 */
void inject_all(Button button, Button lever,
                Joystick j_l, Joystick j_r, Joystick p_l, Joystick p_r,
                byte  stuffToSend[]);

void update_all(Button button, Button lever,
                Joystick j_l, Joystick j_r, Joystick p_l, Joystick p_r,
                byte dataReceived[]);
void print_array(byte array[]);

                
