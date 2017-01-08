#include <SPI.h>
#include <Ethernet.h>
#include <OneWire.h>

/*
  Web Server

 A simple web server that shows the value of attached temperature sensors
 using an Arduino Wiznet Ethernet shield.

 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * DS18B20 OneWire device connected to pin 2

 Web Server code from example:

  created 18 Dec 2009
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe
  modified 02 Sept 2015
  by Arturo Guadalupi

 Temperature Sensor code from:
 http://www.tweaking4all.com/hardware/arduino/arduino-ds18b20-temperature-sensor/

 */


// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {
  0x90, 0xA2, 0xDA, 0x00, 0x88, 0x48
};
IPAddress ip(192, 168, 2, 177);

// Initialize the Ethernet server library
// with the IP address and port you want to use
// (port 80 is default for HTTP):
EthernetServer server(80);

OneWire  ds(2);  // on pin 2 (a 4.7K resistor is necessary)

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}


void loop() {
  
  float temperature = 0;
  
  temperature = GetTemp();
  WebServer(temperature);
  
  
}

