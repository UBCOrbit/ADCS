#define SENSOR_PIN 5
#define PLATFORM_PIN 6
#define VOLTAGE1_PIN A0
#define VOLTAGE2_PIN A1
#define VOLTAGE3_PIN A2
#define VOLTAGE4_PIN A3
#define PLATFORM_START_ANGLE 85
#define SERVO_START_ANGLE 93

#include <Servo.h>
#include <math.h>

Servo Sensor;
Servo Platform;
int plat;
int sens;
int voltage1;
int voltage2;
int voltage3;
int voltage4;
double sum;

void setup() {
  pinMode(VOLTAGE1_PIN, INPUT);
  pinMode(VOLTAGE2_PIN, INPUT);
  pinMode(VOLTAGE3_PIN, INPUT);
  pinMode(VOLTAGE4_PIN, INPUT);
  
  Serial.begin(9600);
  Sensor.attach(SENSOR_PIN);
  Platform.attach(PLATFORM_PIN);
  Sensor.write(SERVO_START_ANGLE);
  Platform.write(PLATFORM_START_ANGLE);
  //analogReference(EXTERNAL);
  delay(6000);
  for (plat = -30; plat < 30; plat++) {
    delay(200);
    Platform.write(plat + PLATFORM_START_ANGLE);
    sweep(plat%2);
  }
}

void loop() {}

void readAndCalc() {
  voltage1 = analogRead(VOLTAGE1_PIN); delay(100);
  voltage2 = analogRead(VOLTAGE2_PIN); delay(100);
  voltage3 = analogRead(VOLTAGE3_PIN); delay(100);
  voltage4 = analogRead(VOLTAGE4_PIN); delay(100);
  sum = voltage1 + voltage2 + voltage3 + voltage4;
}

void serialPrint() {
  Serial.print(String(sens) + ',' 
                 + String(plat) + ',' 
                 + String(voltage1/sum) + ',' 
                 + String(voltage2/sum) + ',' 
                 + String(voltage3/sum) + ',' 
                 + String(voltage4/sum) + ','
                 + '\n');
}
//void serialPrint() {
//  Serial.print(String(sens) + ',' 
//                 + String(plat) + ',' 
//                 + String(voltage1) + ',' 
//                 + String(voltage2) + ',' 
//                 + String(voltage3) + ',' 
//                 + String(voltage4) + ','
//                 + '\n');
//}

void sweep(bool right) {
  if (right) {
    for (sens = -30; sens < 30; sens++) {
      delay(50);
      Sensor.write(sens + SERVO_START_ANGLE);
      readAndCalc();
      serialPrint();
    }
  }
  else {
    for (sens = 29; sens >= -30; sens--) {
      delay(50);
      Sensor.write(sens + 90);
      readAndCalc();
      serialPrint();
    }
  }
}

