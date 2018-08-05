#include "TinyWire.h"

const byte own_address = 13;
//Pines y variables
#define pinBtn1 1
#define pinBtn2 3
#define pinLec A2
int lectura = 0;
byte selector = 0;

void setup() {
  TinyWire.begin(own_address);
  TinyWire.onRequest(onI2CRequest);
  TinyWire.onReceive(onI2CReceive);
  pinMode(pinBtn1, INPUT);
  pinMode(pinBtn2, INPUT);
  pinMode(pinLec, INPUT);
}

void loop() {
  //Almacenando
  lectura = analogRead(pinLec);
}

void onI2CReceive(int howMany) {
  while (TinyWire.available()) {
    selector = TinyWire.receive();
  }
}

void onI2CRequest() {
  int data = 0;
  switch (selector) {
    case 0:
      data = own_address;
      break;
    case 1:
      data = digitalRead(pinBtn1);
      break;
    case 3:
      data = digitalRead(pinBtn2);
      break;
    case 4:
      data = lectura;
      break;
  }
  TinyWire.write(data >> 2);
  TinyWire.write(data & 255);
}
