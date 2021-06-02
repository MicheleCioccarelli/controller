#pragma once
#define ARRAY_SIZE 10

#include "classes.h"

extern uint8_t stuffToSend[];
extern uint8_t dataReceived[];

/* Call the function inject_values() on every object passed as a parameter, this function
 *   puts the object's value at the correct index, every object's index is specified
 *  at it's creation
 *  stuffToSend/dataReceived layout:
 * 
 *      | Button | Lever | j_lX | j_lY | j_rX | j_lY | p_l | p_r | unused | (9 elements)
 */
void inject_all(Button& button, Button& lever,
                Joystick& j_l, Joystick& j_r, Potentiometer& p_l, Potentiometer& p_r);

/* Put all the values stored in dataReceived[] and put them in the respective objects 
 * the order in which this is done is the on specified in inject_all()'s comment,
 */
void update_all(Button& button, Button& lever,
                Joystick& j_l, Joystick& j_r, Potentiometer& p_l, Potentiometer& p_r);

void print_array(const uint8_t array[]);

// Take input for all the objects
void input();

// Called at the end of every loop, brings everything to its default value
void reset(Button& button, Button& lever,
                Joystick& j_l, Joystick& j_r, Potentiometer& p_l, Potentiometer& p_r);
