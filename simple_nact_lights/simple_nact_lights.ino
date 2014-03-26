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

// Set up an RF24 radio. Make sure you have the library installed!
RF24 radio(CE_PIN, CSN_PIN);

/*
 Configure the nRF24L01+ to do our bidding
*/
void setup_nrf() {  
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

  // Begin
  
}

void setup() {
  // Set up the nRF
  setup_nrf();
  

}



void loop() {
  // put your main code here, to run repeatedly:

}
