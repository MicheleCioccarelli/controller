#include "utilities.h"

void print_array(const uint8_t array[])
{
    for (uint8_t i = 0; i < ARRAY_SIZE; i++) {
        Serial.print(array[i]);
        Serial.print(" ");
    }
    Serial.println(" ");
}