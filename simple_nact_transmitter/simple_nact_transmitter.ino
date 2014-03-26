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

// Set up an RF24 radio. Make sure you have the library installed!
RF24 radio(CE_PIN, CSN_PIN);

void setup() {
  // Configure the nRF24L01+ to do our bidding
  
  // Set the 2.4 GHz channel
  
  
  // Max power baby
  
  // Set the speed. 256 kbps for safety. Can be 1Mbps
  // or 2 Mbps if we need more speed.
  
  // Set the payload size. We can use constant, based
  // on the SIMPLE protocol!
  
  
  // Turn auto-ack off

}

void loop() {
  // put your main code here, to run repeatedly:

}
