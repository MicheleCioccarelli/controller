#pragma once
#include "classes.h"
#include "utilities.h"

extern uint8_t dataReceived[];

extern Button button;
extern Button lever;
extern Joystick j_l;
extern Joystick j_r;
extern Potentiometer p_l;
extern Potentiometer p_r;

void decoder();

void print_button();

void print_lever();

void print_j_lX();

void print_j_lY();

void print_j_rX();

void print_j_rY ();

void print_p_l();

void print_p_r();
