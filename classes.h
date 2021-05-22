#pragma once

#include <Arduino.h>


extern uint8_t stuffToSend[];

class Component {
protected:
    const uint8_t pin;
    // This is the index int array[] at which the object's value is stored
    const uint8_t index;
    // The id is used to differentiate between objects of the same type
    // For example to distinguish between the six buttons or the 2 levers.
    uint8_t id;

    void set_input(uint8_t Pin) {pinMode(Pin, INPUT);}
public:
    Component(uint8_t Index, uint8_t Pin = 0, uint8_t Id = 0)
    : index(Index), pin(Pin), id(Id) {}
};

class Button;
class Potentiometer;

class Joystick : protected Component
{
    uint8_t Xvalue;
    uint8_t Yvalue;

    uint8_t Xpin;
    uint8_t Ypin;

    void set_values(uint8_t XValue, uint8_t YValue);
public:
    void get_input();

    // Insert Xvalue and Yvalue in stuffToSend[] at the index provided with the constructor
    void inject_values();

    uint8_t get_x() {return this->Xvalue;} 
    uint8_t get_y() {return this->Yvalue;}
    uint8_t get_index() {return this->index;}

    Joystick(uint8_t Index, uint8_t XPin = 0, uint8_t YPin = 0)
    : Component(Index, pin), Xpin(XPin), Ypin(YPin), Xvalue(0), Yvalue(0) {}

    Joystick(uint8_t Index, uint8_t XPin, uint8_t YPin, uint8_t XValue, uint8_t YValue)
    : Component(Index), Xpin(XPin), Ypin(YPin), Xvalue(XValue), Yvalue(YValue) {}

    friend void inject_all(Button& button, Button& lever, Joystick& j_l, Joystick& j_r, Potentiometer& p_l, Potentiometer& p_r);
    friend void update_all(Button& button, Button& lever, Joystick& j_l, Joystick& j_r, Potentiometer& p_l, Potentiometer& p_r);
};

class Button : protected Component 
{
    // Either 0 or 1
    uint8_t state;

    // This is refined and includes all the information needed about the state oh the object
    uint8_t value;

    void set_id(uint8_t Id);
    void set_state(uint8_t State);
    void set_values(uint8_t Value);
public:
    void get_input();

    // Insert Value in stuffToSend[] at the index specified with the constructor
    // value is a compressed variable
    void inject_values();
    
    uint8_t get_id() { return this->id; }
    uint8_t get_value() {return this->value; } 

    Button(uint8_t Index, uint8_t Id, uint8_t pin = 0)
    : Component(Index, pin, Id), state(0), value(0) {}

    //Button(uint8_t Index, uint8_t Id, uint8_t pin, uint8_t State = 0)
    //: Component(Index, pin, Id), state(State), value(0) {} used for debugging

    friend void inject_all(Button& button, Button& lever, Joystick& j_l, Joystick& j_r, Potentiometer& p_l, Potentiometer& p_r);
    friend void update_all(Button& button, Button& lever, Joystick& j_l, Joystick& j_r, Potentiometer& p_l, Potentiometer& p_r);
};

class Potentiometer : protected Component 
{
    uint8_t value;
    void set_values(uint8_t value) {this->value = value;}

public:
    void get_input();

    uint8_t get_values() {return this->value;}

    void inject_values();

    Potentiometer(uint8_t index, uint8_t pin = 0, uint8_t value = 0)
    : Component(index, pin), value(value) {}

    friend void inject_all(Button& button, Button& lever, Joystick& j_l, Joystick& j_r, Potentiometer& p_l, Potentiometer& p_r);
    friend void update_all(Button& button, Button& lever, Joystick& j_l, Joystick& j_r, Potentiometer& p_l, Potentiometer& p_r);
};
