#pragma once

#include <Arduino.h>

extern uint8_t stuffToSend[];

class Button;
class Potentiometer;
class Joystick;

class Component {
public:
    // This is the index int array[] at which the object's value is stored
    const uint8_t index;
    const uint8_t pin;
    Component(uint8_t Index, uint8_t Pin = 0)
    : index(Index), pin(Pin) {}
};

class Waiter : public Component {
public:
    // Either 0 or 1
    uint8_t newState;

    uint8_t oldState;

    // This is refined and includes all the information needed about the state oh the object
    uint8_t value;

    // The id is used to differentiate between objects of the same type: 6 buttons, 2 levers
    uint8_t id;
    
    //void set_state(uint8_t State);
    void set_values(uint8_t Value);
    
    void get_input();
    void set_input(uint8_t Pin) {pinMode(Pin, INPUT_PULLUP);}
    
    Waiter(uint8_t Index = 0, uint8_t Id = 0, uint8_t pin = 0)
    : Component(Index, pin), id(Id), oldState(1), newState(1), value(0) {this->set_input(pin);}

    friend void update_all(Button& button, Button& lever, Joystick& j_l, Joystick& j_r,Potentiometer& p_l, Potentiometer& p_r);
};

class Joystick : public Component
{
public:
    uint8_t Xvalue;
    uint8_t Yvalue;

    uint8_t Xpin;
    uint8_t Ypin;

    void set_values(uint8_t XValue, uint8_t YValue);

    void set_input(uint8_t Pin) {pinMode(Pin, INPUT);}
    void get_input();

    // Insert Xvalue and Yvalue in stuffToSend[] at the index provided with the constructor
    void inject_values();

    Joystick(uint8_t Index, uint8_t XPin = 0, uint8_t YPin = 0)
    : Component(Index, pin), Xpin(XPin), Ypin(YPin), Xvalue(0), Yvalue(0) {this->set_input(pin);}

    Joystick(uint8_t Index, uint8_t XPin, uint8_t YPin, uint8_t XValue, uint8_t YValue)
    : Component(Index), Xpin(XPin), Ypin(YPin), Xvalue(XValue), Yvalue(YValue) {this->set_input(pin);}

    friend void update_all(Button& button, Button& lever, Joystick& j_l, Joystick& j_r, Potentiometer& p_l, Potentiometer& p_r);
};

class Button : public Waiter 
{
public:
    // Insert Value in stuffToSend[] at the index specified with the constructor
    // value is a compressed variable
    void inject_values();

    Button(uint8_t Index = 0, uint8_t Pin = 0, uint8_t Id = 0)
    : Waiter(Index, Pin, Id) {this->set_input(pin);}

    friend void update_all(Button& button, Button& lever, Joystick& j_l, Joystick& j_r, Potentiometer& p_l, Potentiometer& p_r);
};

class Potentiometer : public Component 
{
public:
    uint8_t value;

    void set_values(uint8_t value) {this->value = value;}
    void set_input(uint8_t Pin) {pinMode(Pin, INPUT);}
    void get_input();

    void inject_values();

    Potentiometer(uint8_t index, uint8_t pin = 0, uint8_t value = 0)
    : Component(index, pin), value(value) {this->set_input(pin);}
    
    friend void update_all(Button& button, Button& lever, Joystick& j_l, Joystick& j_r, Potentiometer& p_l, Potentiometer& p_r);
};
