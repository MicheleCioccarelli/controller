#include "transmission.h"

#define TX 1
#define RX 2

#define STATE RX

#define CE_PIN   9
#define CSN_PIN 10
#define ARRAY_SIZE 13

RF24 radio(CE_PIN, CSN_PIN);

const byte thisSlaveAddress[5] = {'R','x','A','A','A'};

// This is manipulated by transmit_data() and receive_data()
bool result = false;
byte dataToSend[ARRAY_SIZE] = {255, 200, 1, 57};
byte dataReceived[ARRAY_SIZE];

void setup() {
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
        result = transmit_data();
    #elif STATE == RX
        result = receive_data();
    #endif
    delay(1000);
}
