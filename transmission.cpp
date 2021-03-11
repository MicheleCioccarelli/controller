#include "transmission.h"

#define ARRAY_SIZE 13

bool receive_data()
{
    if ( radio.available())
    {
        radio.read( &dataReceived, ARRAY_SIZE);
        Serial.println("Data received ");
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
          int info = dataReceived[i];
          Serial.print(info);
          Serial.print(" ");
        }
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
        //Serial.println(dataToSend);
        return true;
    } else 
    {
        Serial.println("Tx failed");
        return false;
    }
}
