#import <SoftwareSerial.h>

#define RX 2
#define TX 3

SoftwareSerial USerial(RX, TX);
int data;
boolean newLine;
void setup()
{
  USerial.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  while(USerial.available() > 0){
    char data = USerial.read();
    Serial.print(data);
  } 
}
