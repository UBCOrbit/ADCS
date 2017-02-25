#define SENSOR_PIN 9
#define PLATFORM_PIN 10
#define VOLTAGE1_PIN A0
#define VOLTAGE2_PIN A1
#define VOLTAGE3_PIN A2
#define VOLTAGE4_PIN A3
#define REFERENCE_VOLTAGE_PIN A4

#include <Servo.h>

Servo Sensor;
Servo Platform;
int sensorAngle;
int platformAngle;
int voltage1;
int voltage2;
int voltage3;
int voltage4;

void setup() {
  pinMode(VOLTAGE1_PIN, INPUT);
  pinMode(VOLTAGE2_PIN, INPUT);
  pinMode(VOLTAGE3_PIN, INPUT);
  pinMode(VOLTAGE4_PIN, INPUT);
  
  Serial.begin(9600);
  Sensor.attach(SENSOR_PIN);
  Platform.attach(PLATFORM_PIN);
  analogReference(EXTERNAL);
  delay(10000);
  for (int plat = -30; plat < 30; plat++) {
    delay(200);
    platformAngle = plat;
    Platform.write(plat + 90);
    
    for (int sens = -30; sens < 30; sens++) {
      delay(50);
      Sensor.write(sens + 90);
      sensorAngle = sens;
      
      voltage1 = analogRead(VOLTAGE1_PIN); delay(100);
      voltage2 = analogRead(VOLTAGE2_PIN); delay(100);
      voltage3 = analogRead(VOLTAGE3_PIN); delay(100);
      voltage4 = analogRead(VOLTAGE4_PIN); delay(100);
      
      Serial.print(String(sens) + ',' 
                 + String(plat) + ',' 
                 + String(voltage1) + ',' 
                 + String(voltage2) + ',' 
                 + String(voltage3) + ',' 
                 + String(voltage4) + ','
                 + '\n');
    }
    // Slowly reset back to other side
    for (int back = 30; back >= -30; back--) {
      Sensor.write(back + 90);
      delay(10);
    }
  }
}

void loop() {}

