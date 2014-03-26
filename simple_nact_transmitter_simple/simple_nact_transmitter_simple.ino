/*
 A SIMPLE (lol) protocol for controlling LED lights!
 
 Steve Levine (sjlevine@mit.edu) and Victor Hung (vhung@mit.edu)
*/

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

// I like constants
#define CSN_PIN 10
#define CE_PIN 9
#define PAYLOAD_SIZE 5
#define SYNC_BYTE 0x61

#define STATUS_LED_PIN 13

#define PIPE_TO_LIGHTS   0xF0F0F0F0E1LL
#define PIPE_FROM_LIGHTS 0xF0F0F0F0D2LL

// Set up an RF24 radio. Make sure you have the library installed!
RF24 radio(CE_PIN, CSN_PIN);

char msg[5];
int counter;

void setup_nrf() {
  // Set up some defaults  
  radio.begin();
  
  // Set the 2.4 GHz channel
  radio.setChannel(76); // This is supposedely a good choice
  
  // Max power baby
  radio.setPALevel(RF24_PA_HIGH);
  
  // Set up a 16-bit CRC
  radio.setCRCLength(RF24_CRC_16);
  
  // Set the speed. 256 kbps for safety. Can be 1Mbps
  // or 2 Mbps if we need more speed.
  radio.setDataRate(RF24_250KBPS);
  
  // Set the payload size. We can use constant, based
  // on the SIMPLE protocol!
  radio.setPayloadSize(PAYLOAD_SIZE);
  
  // Turn auto-ack off
  radio.setAutoAck(false);
  
  // Number of retries. Are these used if acks are off (?)
  radio.setRetries(10, 15);
  
}

void setup_transmitting() {
  // Should only be called in the receiver - i.e., the lights, not in the transmitter
  radio.openWritingPipe(PIPE_TO_LIGHTS);
  radio.openReadingPipe(1, PIPE_FROM_LIGHTS);
  // Start listening
  //radio.startListening();
}

void setup() {
  // Set up the nRF
  setup_nrf();
  
  // Set up pipes for the receiver
  setup_transmitting();
  
  
  // Set up a status LED pin
  //pinMode(STATUS_LED_PIN, OUTPUT);
  Serial.begin(9600);
  
}


uint8_t victor[5] = {0x61, 0x62, 0x63, 0x64, 0x65};
uint8_t steve[5] = {0x62, 0x32, 0x43, 0x54, 0x65};
uint8_t bob[5] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE};

void loop() {
  // put your main code here, to run repeatedly:
    radio.stopListening();
    radio.flush_tx();
    Serial.println("SENDING:");
    bool ok  = radio.write(victor,5);
        
    if (ok)
      Serial.println("ok...");
    else
      Serial.println("failed.\n\r");
      
    radio.startListening();
    radio.stopListening();
    Serial.println("SENDINGsteve:");
     ok  = radio.write(steve,5);
        
    if (ok)
      Serial.println("ok...");
    else
      Serial.println("failed.\n\r"); 
      
    radio.startListening();
    delay(500);
    /*
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    
    
  }
  */
}
