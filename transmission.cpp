#include "transmission.h"
#include "utilities.h"

void transmit_data(uint8_t stuffToSend[])
{
    if (radio.write(&stuffToSend, sizeof(stuffToSend))) // ARRAY_SIZE
    {   
    print_array(stuffToSend);
        Serial.println("Success");
    } else {
        Serial.println("Fail");
    }
}

void receive_data(uint8_t dataReceived[])
{   
    if ( radio.available()) {
        Serial.println("Success");
                print_array(dataReceived);
        radio.read(&dataReceived, sizeof(dataReceived));

        print_array(dataReceived);
        //Serial.println(dataReceived[7]);
        /*for(int i = 0; i < ARRAY_SIZE; i++)
            dataReceived[i] = i;
        print_array(dataReceived);*/
        
    } else {
        Serial.println("Fail");
    }
        
}
