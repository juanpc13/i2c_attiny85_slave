#include "TinyWire.h"

const byte own_address = 13;

void setup() {
  TinyWire.begin(own_address);
  TinyWire.onRequest(onI2CRequest);
  TinyWire.onReceive(onI2CReceive);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void onI2CReceive(int howMany) {
}

void onI2CRequest() {
}
