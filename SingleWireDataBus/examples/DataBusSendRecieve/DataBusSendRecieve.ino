/* This Library is designed to be a robust protocol to transfer up to 1024 different 
   commands to and from up to 256 different devices on one wire. This sketch provides
   a simple example of this using the serial monitor. Open this sketch twice, upload
   this code to two different arduinos, then type your commands in the serial monitor 
   of the first sketch in the format of address command (e.g. 0010001, this sends 
   address 1, command 1). The data will now appear in the serial monitor of the 
   second sketch. This works vice-versa as well. For this system to work, you will 
   need a 10K resistor going from the data bus wire to ground, and you will need a 
   common ground that all arduinos are connected to.
   
   The author of this sketch accepts no responsability for damage to devices or
   hardware that may occur as a result of using this library.*/

#include "SingleWireDataBus.h"

SingleWireDataBus Bus1(2);  //Call the class, select the desired com pin. (e.g. 2)

String outputData = "";
String addressData = "";

void setup() {
  Serial.begin(9600);
  Bus1.initializeData();
}

void loop() {
  Bus1.recieveData(1);  //Check for incomming data, select chip address to recieve data (e.g. 1)

  while (Serial.available()) {
    String data = Serial.readString();
    addressData = data.substring(0, 3);
    outputData = data.substring(3, data.length());
  }
  if (!Serial.available() && outputData.length() != 0) {
    Bus1.sendData(addressData, outputData);  //Send address, command to the wire
    addressData = "";
    outputData = "";
  }

  if (Bus1.Data >= 0) {
    Serial.println(Bus1.Data);
    Bus1.Address = -1;
    Bus1.Data = -1;
  }
}