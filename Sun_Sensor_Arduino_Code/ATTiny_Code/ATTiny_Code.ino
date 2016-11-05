#include <SoftwareSerial.h>
// Definitions
#define rxPin 10
#define txPin 9

SoftwareSerial mySerial(rxPin, txPin);
int data1;
int data2;
int data3;
int data4;
void setup() 
{
  mySerial.begin(9600);
}

void loop()
{
  data1 = analogRead(0);
  data2 = analogRead(1);
  data3 = analogRead(2);
  data4 = analogRead(3);
  mySerial.print("Sensor1 :");
  mySerial.print(data1, DEC);
  mySerial.print("\n");
  mySerial.print("Sensor2 :");
  mySerial.print(data2, DEC);
  mySerial.print("\n");
  mySerial.print("Sensor3 :");
  mySerial.print(data3, DEC);
  mySerial.print("\n");
  mySerial.print("Sensor4 :");
  mySerial.print(data4, DEC);
  delay(900);
  mySerial.print("\n\n");
  delay(100);
}
