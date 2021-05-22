#include "classes.h"

void Joystick::set_values(uint8_t XValue, uint8_t YValue)
{
    this->Xvalue = XValue;
    this->Yvalue = YValue;
}

void Joystick::get_input() 
{
    set_values(map(analogRead(Xpin), 0, 1023, 0, 255), map(analogRead(Ypin), 0, 1023, 0, 255));
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

void Button::get_input() {
    this->state = analogRead(this->pin);
}

void Button::inject_values()
{
    this->value = this->id * 10 + this->state;
    stuffToSend[this->index] = this->state;
}
// ========================================================
void Potentiometer::get_input() {
    this->value = map(analogRead(this->pin), 0, 1023, 0, 255);
}

void Potentiometer::inject_values() {
    stuffToSend[this->index] = this->value;
}
