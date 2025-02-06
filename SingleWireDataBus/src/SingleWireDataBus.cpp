#include "SingleWireDataBus.h"

SingleWireDataBus::SingleWireDataBus(int pin) {
  busPin = pin;
  delayTime = 5;
  Address = 0;
  Data = 0;
  incommingByte = false;
}

void SingleWireDataBus::initializeData() {
  pinMode(busPin, INPUT);
}

void SingleWireDataBus::sendData(String chipNum, String data) {
  while (incommingByte == true) {
    delay(50);
  }
  pinMode(busPin, OUTPUT);
  int chipNum2 = chipNum.toInt();
  int chipByte0 = bitRead(chipNum2, 0);
  int chipByte1 = bitRead(chipNum2, 1);
  int chipByte2 = bitRead(chipNum2, 2);
  int chipByte3 = bitRead(chipNum2, 3);
  int chipByte4 = bitRead(chipNum2, 4);
  int chipByte5 = bitRead(chipNum2, 5);
  int chipByte6 = bitRead(chipNum2, 6);
  int chipByte7 = bitRead(chipNum2, 7);

  int data2 = data.toInt();
  int byte0 = bitRead(data2, 0);
  int byte1 = bitRead(data2, 1);
  int byte2 = bitRead(data2, 2);
  int byte3 = bitRead(data2, 3);
  int byte4 = bitRead(data2, 4);
  int byte5 = bitRead(data2, 5);
  int byte6 = bitRead(data2, 6);
  int byte7 = bitRead(data2, 7);
  int byte8 = bitRead(data2, 8);
  int byte9 = bitRead(data2, 9);

  digitalWrite(busPin, HIGH);
  delay(delayTime);
  digitalWrite(busPin, chipByte0);
  delay(delayTime);
  digitalWrite(busPin, chipByte1);
  delay(delayTime);
  digitalWrite(busPin, chipByte2);
  delay(delayTime);
  digitalWrite(busPin, chipByte3);
  delay(delayTime);
  digitalWrite(busPin, chipByte4);
  delay(delayTime);
  digitalWrite(busPin, chipByte5);
  delay(delayTime);
  digitalWrite(busPin, chipByte6);
  delay(delayTime);
  digitalWrite(busPin, chipByte7);
  delay(delayTime);
  digitalWrite(busPin, byte0);
  delay(delayTime);
  digitalWrite(busPin, byte1);
  delay(delayTime);
  digitalWrite(busPin, byte2);
  delay(delayTime);
  digitalWrite(busPin, byte3);
  delay(delayTime);
  digitalWrite(busPin, byte4);
  delay(delayTime);
  digitalWrite(busPin, byte5);
  delay(delayTime);
  digitalWrite(busPin, byte6);
  delay(delayTime);
  digitalWrite(busPin, byte7);
  delay(delayTime);
  digitalWrite(busPin, byte8);
  delay(delayTime);
  digitalWrite(busPin, byte9);
  delay(delayTime);
  digitalWrite(busPin, LOW);

  data = "";
  data2 = 0;
  byte0 = 0;
  byte1 = 0;
  byte2 = 0;
  byte3 = 0;
  byte4 = 0;
  byte5 = 0;
  byte6 = 0;
  byte7 = 0;
  byte8 = 0;
  byte9 = 0;

  chipNum = "";
  chipNum2 = 0;
  chipByte0 = 0;
  chipByte1 = 0;
  chipByte2 = 0;
  chipByte3 = 0;
  chipByte4 = 0;
  chipByte5 = 0;
  chipByte6 = 0;
  chipByte7 = 0;

  pinMode(busPin, INPUT);
}

void SingleWireDataBus::recieveData() {
  boolean incommingByte = false;
  int bitCounter = 0;
  int inputNum = 0;
  int chipNum = 0;
  String inputData = "";
  String chipData = "";
  if (incommingByte == false && digitalRead(busPin) == 1) {
    incommingByte = true;
    delay(1);
  }
  while (incommingByte == true) {
    delay(delayTime);
    bitCounter++;
    if (bitCounter <= 8) {
      chipData = chipData + String(digitalRead(busPin));
      if (bitCounter == 8) {
        if (chipData.charAt(0) == '1') {
          chipNum = chipNum + 1;
        }
        if (chipData.charAt(1) == '1') {
          chipNum = chipNum + 2;
        }
        if (chipData.charAt(2) == '1') {
          chipNum = chipNum + 4;
        }
        if (chipData.charAt(3) == '1') {
          chipNum = chipNum + 8;
        }
        if (chipData.charAt(4) == '1') {
          chipNum = chipNum + 16;
        }
        if (chipData.charAt(5) == '1') {
          chipNum = chipNum + 32;
        }
        if (chipData.charAt(6) == '1') {
          chipNum = chipNum + 64;
        }
        if (chipData.charAt(7) == '1') {
          chipNum = chipNum + 128;
        }
        Address = chipNum;
        chipData = "";
        chipNum = 0;
      }
    }
    if (bitCounter > 8 && bitCounter <= 18) {
      inputData = inputData + String(digitalRead(busPin));
      if (bitCounter == 18) {
        if (inputData.charAt(0) == '1') {
          inputNum = inputNum + 1;
        }
        if (inputData.charAt(1) == '1') {
          inputNum = inputNum + 2;
        }
        if (inputData.charAt(2) == '1') {
          inputNum = inputNum + 4;
        }
        if (inputData.charAt(3) == '1') {
          inputNum = inputNum + 8;
        }
        if (inputData.charAt(4) == '1') {
          inputNum = inputNum + 16;
        }
        if (inputData.charAt(5) == '1') {
          inputNum = inputNum + 32;
        }
        if (inputData.charAt(6) == '1') {
          inputNum = inputNum + 64;
        }
        if (inputData.charAt(7) == '1') {
          inputNum = inputNum + 128;
        }
        if (inputData.charAt(8) == '1') {
          inputNum = inputNum + 256;
        }
        if (inputData.charAt(9) == '1') {
          inputNum = inputNum + 512;
        }
        Data = inputNum;
        inputData = "";
        inputNum = 0;
        bitCounter = 0;
        delay(delayTime);
        incommingByte = false;
        break;
      }
    }
  }
}