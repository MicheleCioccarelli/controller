#include "transmission.h"

#define ARRAY_SIZE 13

bool receive_data()
{
    if ( radio.available())
    {
        radio.read( &dataReceived, ARRAY_SIZE);
        Serial.print("Data received ");
        Serial.println(dataReceived);
        return true;
    }
    else 
    {
        return false;
    }
}

bool transmit_data()
{
    Serial.println("called");
    if (radio.write(&dataToSend, ARRAY_SIZE))
    {
        Serial.println("data sent");
        Serial.println(dataToSend);
        return true;
    } else 
    {
        Serial.println("Tx failed");
        return false;
    }
}
