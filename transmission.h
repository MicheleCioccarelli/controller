#pragma once
#define ARRAY_SIZE 10

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

extern RF24 radio;
extern const byte thisSlaveAddress[5];
extern int state;

extern uint8_t stuffToSend[];
extern uint8_t dataReceived[];

// Main State
extern bool has_synced;

void transmit_data();

void receive_data();
