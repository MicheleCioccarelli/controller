#include "classes.h"

void Joystick::set_values(byte XValue, byte YValue)
{
    this->Xvalue = XValue;
    this->Yvalue = YValue;
}

void Joystick::inject_values(byte stuffToSend[])
{
    stuffToSend[this->index] = this->Xvalue;
    stuffToSend[this->index + 1 ] = this->Yvalue;
}
// ========================================================
void Button::set_id(byte Id) {
    this->id = Id;
}

void Button::set_state(short State) {
    this->state = State;
}

void Button::set_value(byte Value) {
    this->value = Value;
}

void Button::inject_value(byte stuffToSend[])
{
    this->value = this->id * 10 + this->state;
    stuffToSend[this->index] = this->state;
}