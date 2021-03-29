#include "transmission.h"
#include "utilities.h"

void transmit_data()
{
    if (radio.write(&stuffToSend, ARRAY_SIZE)) {  
        print_array(stuffToSend);
        Serial.println("Success");
    }
}

void receive_data()
{  
    if ( radio.available()) {
        Serial.println("Success");
       
        radio.read(&dataReceived, ARRAY_SIZE);
        print_array(dataReceived);
    }
}
