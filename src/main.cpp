/*******************************************************************
    A door opener via Telegram bot.
 *                                                                 *
 *  october 2018                                                   *
    written by Enkel Bici, Giacomo Leonzi and Francesco Pasino
 *******************************************************************/

#include <Arduino.h>

#ifdef ENV_ESP32
#include "wifi.h"
#endif

#include "nfc.h"

const int doorPin = 15; // D8
const int internalDoorPin = 13; // D7
int ledStatus = 0;

void setup() {
  // inizialize the relay pins
  pinMode(doorPin, OUTPUT); // initialize digital doorPin as an output.
  digitalWrite(doorPin, LOW);
  pinMode(internalDoorPin, OUTPUT); // initialize digital doorPin as an output.
  digitalWrite(internalDoorPin, LOW);

  Serial.begin(115200); // initialize the Serial

  #ifdef ENV_ESP32
  initWifi();
  #endif

  initNfc();
}

void loop() {
  listenForNfcCards();
}
