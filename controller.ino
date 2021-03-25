#include "transmission.h"
#include "classes.h"
#include "utilities.h"

#define TX 1
#define RX 2

#define STATE TX

#define CE_PIN   9
#define CSN_PIN 10
#define ARRAY_SIZE 13

RF24 radio(CE_PIN, CSN_PIN);

const byte thisSlaveAddress[5] = {'R','x','A','A','A'};

// This is manipulated by transmit_data() and receive_data()
bool result = false;

#if STATE == TX
    byte stuffToSend[ARRAY_SIZE];
#elif STATE == RX
    byte dataReceived[ARRAY_SIZE];
#endif

Button button(0, 1, 2);
Button lever(1, 7, 3);
Joystick j_l(2, 4);
Joystick j_r(4, 6);
Joystick p_l(6, 7);
Joystick p_r(8, 9);
    
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
        result = transmit_data(stuffToSend);
    #elif STATE == RX-
        result = receive_data(dataReceived);
    #endif
    delay(1000);
}
