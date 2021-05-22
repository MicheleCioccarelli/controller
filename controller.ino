#include "transmission.h"
#include "classes.h"
#include "utilities.h"
#include "decoder.h"

#define TX 1
#define RX 2

#define DEBUG 1
#define STATE RX

#define CE_PIN   9
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
Component button1(0, 1, 8); // Index, id, pin
Component button2(0, 2, 9);
Component button3(0, 3, 2);
Component button4(0, 4, 3);
Component lever1(1, 1, 7);
Component lever2(1, 2, 4);

// Button objects are pure, handled by a function and Component objects
Button button(0, 0, 0);
Button lever(0, 0, 0);
Joystick j_l(2, A1, A0); // Index, Xpin, Ypin
Joystick j_r(4, A2, A3);
Potentiometer p_l(6, A7); // Index, pin
Potentiometer p_r(7, A6);
    
void setup() 
{
    Serial.begin(9600);
    radio.begin();
    radio.setDataRate( RF24_250KBPS );

    #if STATE == TX

/* Input pins table:
 *  lever1 = 7      | lever2 = 4
 *  b1 = 8  | b2 = 9    | b3 = 2    | b4 = 3
 *  j1Y = A0    | j1X = A1  | j2X = A2  | j2Y = A3
 *  p1 = A7     | p2 = A6
 * 
 * Check howToMechatronics for how to actually hook it up
*/
        button1.set_input(button1.pin);
        button2.set_input(button2.pin);        
        button3.set_input(button3.pin);        
        button4.set_input(button4.pin);        
        lever1.set_input(lever1.pin);
        lever2.set_input(lever2.pin);
        j_l.set_input(j_l.Xpin);
        j_r.set_input(j_r.Ypin);
        p_l.set_input(p_l.pin);
        p_r.set_input(p_r.pin);

        radio.setRetries(3,5);
        radio.openWritingPipe(thisSlaveAddress); 
    #elif STATE == RX
        radio.openReadingPipe(1, thisSlaveAddress);
        radio.startListening();
    #endif
}


void loop() 
{
    #if STATE == TX
    #if DEBUG == 1
        button.set_state(0);
        lever.set_state(1);
        j_l.set_values(2, 3);
        j_r.set_values(4, 5);
        p_l.set_values(6);
        p_r.set_values(7);
    #endif

        /*button1.get_input();
        button2.get_input();        
        button3.get_input();        
        button4.get_input();        
        lever1.get_input();
        lever2.get_input();*/ Need to create function
        j_l.get_input();
        j_r.get_input();
        p_l.get_input();
        p_r.get_input();

        print_array(stuffToSend);
        inject_all(button, lever, j_l, j_r, p_l, p_r);
        transmit_data();
        
    #elif STATE == RX
        receive_data();
        decoder(button, lever, j_l, j_r, p_l, p_r);
    #endif

    delay(500);
}
