#include "classes.h"

void Joystick::set_values(uint8_t XValue, uint8_t YValue)
{
    this->Xvalue = XValue;
    this->Yvalue = YValue;
}

void Joystick::inject_values()
{
    dataTrasnfer[this->index] = this->Xvalue;
    dataTrasnfer[this->index + 1 ] = this->Yvalue;
}
// ========================================================
void Button::set_id(uint8_t Id) {
    this->id = Id;
}

void Button::set_state(uint8_t State) {
    this->state = State;
}

void Button::set_value(uint8_t Value) {
    this->value = Value;
}

void Button::inject_value()
{
    this->value = this->id * 10 + this->state;
    dataTrasnfer[this->index] = this->state;
}
