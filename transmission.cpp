#include "transmission.h"
#include "utilities.h"

void transmit_data()
{
        Serial.println("Called");
    if (radio.write(&stuffToSend, ARRAY_SIZE)) {  
        Serial.print("Information sent succesfully: ");
        print_array(stuffToSend);
    }
}

void receive_data()
{  
    Serial.println("Called");
    if ( radio.available()) {       
        radio.read(&dataReceived, ARRAY_SIZE);
        Serial.print("Data received succesfully: ");
        print_array(dataReceived);
    }
}
