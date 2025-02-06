This Library is designed to be a robust protocol to transfer up to 1024 different 
commands to and from up to 256 different devices on one wire. This sketch provides
a simple example of this using the serial monitor. Open this sketch twice, upload
this code to two different arduinos, then type your commands in the serial monitor 
of the first sketch in the format of address command (e.g. 0010001, this sends 
address 1, command 1). The data will now appear in the serial monitor of the 
second sketch. This works vice-versa as well. For this system to work, you will 
need a 10K resistor going from the data bus wire to ground, and you will need a 
common ground that all arduinos are connected to.
