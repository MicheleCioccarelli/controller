#include "transmission.h"

#define ARRAY_SIZE 13

bool transmit_data(byte stuffToSend[])
{
    Serial.println("called");
    if (radio.write(&stuffToSend, ARRAY_SIZE))
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

bool receive_data(byte dataReceived[])
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