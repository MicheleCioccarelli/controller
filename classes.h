#pragma once

#include <Arduino.h>

extern uint8_t dataTrasnfer[];

class Component {
protected:
    const uint8_t pin;
    // This is the index int array[] at which the object's value is stored
    const uint8_t index;

    Component(uint8_t Index, uint8_t pin)
    : index(Index), pin(pin) {}
};

class Button;

class Joystick : protected Component
{
    uint8_t Xvalue;
    uint8_t Yvalue;

public:
    void set_values(uint8_t XValue, uint8_t YValue);
    void inject_values();

    uint8_t get_value() {return this->Xvalue; } 

    Joystick(uint8_t Index, uint8_t pin = 0)
    : Component(Index, pin), Xvalue(0), Yvalue(0) {}

    Joystick(uint8_t Index, uint8_t pin, uint8_t XValue, uint8_t YValue)
    : Component(Index, pin), Xvalue(XValue), Yvalue(YValue) {}

    friend void inject_all(Button& button, Button& lever, Joystick& j_l, Joystick& j_r, Joystick& p_l, Joystick& p_r);
};

class Button : protected Component {
    // The id is used to differentiate between objects of the same type
    // For example to distinguish between the six buttons.
    uint8_t id;
    // Either 0 or 1
    uint8_t state;
    // This is refined and includes all the information needed about the state oh the object
    uint8_t value;

public:
    void set_id(uint8_t Id);
    void set_state(uint8_t State);
    void set_value(uint8_t Value);
    void inject_value();
    uint8_t get_id() { return this->id; }
    uint8_t get_value() {return this->value; } 

    Button(uint8_t Index, uint8_t Id, uint8_t pin = 0)
    : Component(Index, pin), state(0), id(Id), value(0) {}

    Button(uint8_t Index, uint8_t Id, uint8_t pin, uint8_t State)
    : Component(Index, pin), state(State), id(Id), value(0) {}

    friend void inject_all(Button& button, Button& lever, Joystick& j_l, Joystick& j_r, Joystick& p_l, Joystick& P_r);
};
