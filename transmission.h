#pragma once
#define ARRAY_SIZE 10

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

extern RF24 radio;
extern const byte thisSlaveAddress[5];

extern uint8_t stuffToSend[];
extern uint8_t dataReceived[];

// Stream stuffToSend[] to the receiver
void transmit_data();

// Empty the nrf24l01's data buffer into dataReceived[]
void receive_data();