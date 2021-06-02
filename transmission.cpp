#include "transmission.h"
#include "utilities.h"

void transmit_data()
{
    if (radio.write(&stuffToSend, ARRAY_SIZE)) {  
        Serial.print("Information sent succesfully: ");
    }
}

void receive_data()
{  
    if ( radio.available()) {       
        radio.read(&dataReceived, ARRAY_SIZE);
    }
}
