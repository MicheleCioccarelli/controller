#pragma once

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

extern RF24 radio;

extern byte dataToSend[];
extern byte dataReceived[];
extern const byte thisSlaveAddress[5];

bool transmit_data();

bool receive_data();
