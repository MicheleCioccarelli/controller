#pragma once

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

extern RF24 radio;
extern const byte thisSlaveAddress[5];

bool transmit_data(byte stuffToSend[]);

bool receive_data(byte dataReceived[]);
