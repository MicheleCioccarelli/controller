#pragma once

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

extern RF24 radio;

extern char dataToSend[];
extern char dataReceived[];
extern const byte thisSlaveAddress[5];

bool transmit_data();

bool receive_data();
