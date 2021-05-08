#pragma once

extern uint8_t dataReceived[];

extern Button button;
extern Button lever;
extern Joystick j_l;
extern Joystick j_r;
extern Joystick p_l;
extern Joystick p_r;

void decode();

void button(uint8_t value);

void lever(uint8_t value);

void j_lX(uint8_t value);

void j_lY(uint8_t value);

void j_rX(uint8_t value);

void j_rY (uint8_t value);

void p_l(uint8_t value);

void p_r(uint8_t value);