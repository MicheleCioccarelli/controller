#include "classes.h"

void Joystick::set_values(uint8_t XValue, uint8_t YValue)
{
    this->Xvalue = XValue;
    this->Yvalue = YValue;
}

void Joystick::inject_values()
{
    stuffToSend[this->index] = this->Xvalue;
    stuffToSend[this->index + 1] = this->Yvalue;
}
// ========================================================
void Button::set_id(uint8_t Id) {
    this->id = Id;
}

void Button::set_state(uint8_t State) {
    this->state = State;
}

void Button::set_values(uint8_t Value) {
    this->value = Value;
}

void Button::inject_values()
{
    this->value = this->id * 10 + this->state;
    stuffToSend[this->index] = this->state;
}

void Potentiometer::inject_values() {
    stuffToSend[this->index] = this->value;
}
