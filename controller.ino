#include "transmission.h"
#include "classes.h"
#include "utilities.h"

#define TX 1
#define RX 2

#define STATE RX

#define CE_PIN   9
#define CSN_PIN 10
#define ARRAY_SIZE 10

RF24 radio(CE_PIN, CSN_PIN);

const byte thisSlaveAddress[5] = {'R','x','A','A','A'};

#if STATE == TX
    uint8_t stuffToSend[ARRAY_SIZE] = {8,8,8,8,8,8,8,8, 7, 6};
#elif STATE == RX
    uint8_t dataReceived[ARRAY_SIZE] = {};
#endif


Button button(0, 1);
Button lever(1, 7);
Joystick j_l(2);
Joystick j_r(4);
Joystick p_l(6);
Joystick p_r(8);
    
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

void loop() 
{
    #if STATE == TX
    /*
        button.set_state(1);
        lever.set_state(0);
        j_l.set_values(12, 100);
        j_r.set_values(11, 33);
        p_l.set_values(200, 44);
        p_r.set_values(98, 69); 
    */
        //inject_all(button, lever, j_l, j_r, p_l, p_r, stuffToSend);
        transmit_data();

    #elif STATE == RX

        receive_data();    
        //update_all(button, lever, j_l, j_r, p_l, p_r, dataReceived);
        
    #endif
    delay(1000);
}
