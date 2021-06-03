#include "transmission.h"
#include "classes.h"
#include "utilities.h"
#include "decoder.h"

#define TX 1
#define RX 2

#define STATE RX

#define CE_PIN 6
#define CSN_PIN 10
#define ARRAY_SIZE 10

RF24 radio(CE_PIN, CSN_PIN);

const byte thisSlaveAddress[5] = {'R','x','A','A','A'};

// Using two arrays avoids confusion when debugging
#if STATE == TX
    uint8_t stuffToSend[ARRAY_SIZE] = {};
#elif STATE == RX
    uint8_t dataReceived[ARRAY_SIZE] = {};
#endif

/* Component objects wait for input on each of their pins, once they detect something they write it into
 * Button objects. The handling function should look for input on their pins and write it into the 
 * respective objects
 */
Waiter buttons[6] {Waiter(0, 1, 8), Waiter(0, 2, 9), Waiter(0, 3, 5), Waiter(0, 4, 3), Waiter(0, 5, 1), Waiter(0, 6, 0)};                                                                     //left Joystick
//Right joystick

Waiter levers[2] {Waiter(1, 1, 7), Waiter(1, 2, 4)};

// Button objects are pure, handled by a function and Component objects
Button button(0); // index
Button lever(1);
Joystick j_l(2, A1, A0); // Index, Xpin, Ypin
Joystick j_r(4, A2, A3);
Potentiometer p_l(6, A4); // Index, pin || Should be A7, but arduino uno doesn't have it
Potentiometer p_r(7, A5); // Should be A6
    
void setup() 
{
    Serial.begin(9600);
    radio.begin();
    radio.setDataRate( RF24_250KBPS );

    #if STATE == TX
        radio.setRetries(3,5);
        radio.openWritingPipe(thisSlaveAddress); 

    #elif STATE == RX
        radio.openReadingPipe(1, thisSlaveAddress);
        radio.startListening();
    #endif
}

void loop() {
    #if STATE == TX
        for (Waiter &c : buttons) {
            c.get_input();
            if (c.oldState != c.newState) {
                c.oldState = c.newState;
                button.id = c.id;
                button.newState = c.newState;
                button.inject_values();
                break;
            }
        }
        for (Waiter &c : levers) {
            c.get_input();
            if (c.oldState != c.newState) {
                c.oldState = c.newState;
                lever.id = c.id;
                lever.newState = c.newState              
                lever.inject_values();
                break;
            }
        }
        j_l.get_input();
        j_r.get_input();
        j_l.inject_values();
        j_r.inject_values();

        p_l.get_input();
        p_r.get_input();
        p_l.inject_values();
        p_r.inject_values();

        transmit_data();
    #elif STATE == RX
        receive_data();
        print_array(dataReceived);
        //decoder(button, lever, j_l, j_r, p_l, p_r);
    #endif
}
