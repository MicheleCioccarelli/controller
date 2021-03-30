#include "transmission.h"
#include "utilities.h"

void transmit_data()
{
    if (radio.write(&dataTrasnfer, ARRAY_SIZE)) {  
        print_array(dataTrasnfer);
        Serial.println("Success");
    }
}

void receive_data()
{  
    if ( radio.available()) {
        Serial.println("Success");
       
        radio.read(&dataTrasnfer, ARRAY_SIZE);
        print_array(dataTrasnfer);
    }
}
