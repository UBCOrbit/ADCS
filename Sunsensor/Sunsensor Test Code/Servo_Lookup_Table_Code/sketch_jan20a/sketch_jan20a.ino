#include <Servo.h>

#define SENSOR_PIN 5
#define PLATFORM_PIN 6
#define PLATFORM_START_ANGLE 85
#define SERVO_START_ANGLE 93
#define ALPHA 0
#define BETA 0
#include <math.h>

Servo Sensor;
Servo Platform;
int plat;
int sens;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Sensor.attach(SENSOR_PIN);
  Platform.attach(PLATFORM_PIN);
  Sensor.write(SERVO_START_ANGLE);
  Platform.write(PLATFORM_START_ANGLE);
  analogReference(EXTERNAL);
  delay(2000);
}

void loop() {
  Platform.write(PLATFORM_START_ANGLE + ALPHA);
  Sensor.write(SERVO_START_ANGLE + BETA);
  serialPrint();
  delay(5000);
}

void serialPrint() {
  Serial.print(String(sens) + ',' 
                 + String(plat) + ',' 
                 + '\n');
}


