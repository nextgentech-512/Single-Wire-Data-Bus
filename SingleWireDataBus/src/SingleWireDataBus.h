#ifndef SingleWireDataBus_h
#define SingleWireDataBus_h

#include <Arduino.h>

class SingleWireDataBus {
public:
  SingleWireDataBus(int pin);
  void initializeData();
  void sendData(String chipNum, String data);
  void recieveData();

  int Address;
  int Data;
private:
  float delayTime;
  int busPin;
  boolean incommingByte;
};

#endif