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
void Waiter::set_id(uint8_t Id) {
    this->id = Id;
}

void Waiter::set_state(uint8_t State) {
    this->state = State;
}

void Waiter::set_values(uint8_t Value) {
    this->value = Value;
}

void Waiter::get_input() {
    this->state = analogRead(this->pin);
}

void Waiter::inject_values()
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
