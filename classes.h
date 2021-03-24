#pragma once
#include "iostream"
#define ARRAY_SIZE 13

#define byte short

class Component {
protected:
    const byte pin;
    // This is the index int array[] at which the object's value is stored
    const byte index;

    Component(byte Index, byte pin)
    : index(Index), pin(pin) {}
};

class Button;

class Joystick : protected Component
{
    byte Xvalue;
    byte Yvalue;

public:
    void set_values(byte XValue, byte YValue);
    void inject_values(byte stuffToSend[]);

    Joystick(byte Index, byte pin)
    : Component(Index, pin), Xvalue(0), Yvalue(0) {}

    Joystick(byte Index, byte pin, byte XValue, byte YValue)
    : Component(Index, pin), Xvalue(XValue), Yvalue(YValue) {}

    friend void inject_all(Button button, Button lever, Joystick j_l, Joystick j_r, Joystick p_l, Joystick P_r, byte stuffToSend[]);
};

class Button : protected Component {
    // The id is used to differentiate between objects of the same type
    // For example to distinguish between the six buttons.
    byte id;
    // Either 0 or 1
    byte state;
    // This is refined and includes all the information needed about the state oh the object
    byte value;

public:
    void set_id(byte Id);
    void set_state(byte State);
    void set_value(byte Value);
    void inject_value(byte stuffToSend[]);
    byte get_id() { return this->id; }

    Button(byte Index, byte Id, byte pin)
    : Component(Index, pin), state(0), id(Id), value(0) {}

    Button(byte Index, byte Id, byte pin, byte State)
    : Component(Index, pin), state(State), id(Id), value(0) {}

    friend void inject_all(Button button, Button lever, Joystick j_l, Joystick j_r, Joystick p_l, Joystick P_r, byte stuffToSend[]);
};