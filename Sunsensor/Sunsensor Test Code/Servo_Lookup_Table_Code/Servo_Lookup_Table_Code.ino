#define SENSOR_PIN 6
#define PLATFORM_PIN 5
#define VOLTAGE1_PIN A0
#define VOLTAGE2_PIN A1
#define VOLTAGE3_PIN A2
#define VOLTAGE4_PIN A3
#define PLATFORM_START_ANGLE 100
#define SERVO_START_ANGLE 80
#define WAIT_DELAY 10000
#define DATA_DELAY 50
#define ALPHA 0
#define BETA 0

#define C1 1.0
#define C2 1.0
#define C3 1.0
#define C4 1.0
#define WIDTH 3.0
#define HEIGHT 1.5
#include <math.h>
#include <Servo.h>

Servo Sensor;
Servo Platform;
int plat;
int sens;
int voltage1;
int voltage2;
int voltage3;
int voltage4;
double sum;
double alpha;
double beta;

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
  delay(1000);
  for (plat = -30; plat < 30; plat++) {
    delay(200);
    Platform.write(plat + PLATFORM_START_ANGLE);
    sweep(plat%2);
  }
}

void loop() {
//  Platform.write(PLATFORM_START_ANGLE + ALPHA);
//  Sensor.write(SERVO_START_ANGLE + BETA);
//  serialPrint();
//  delay(5000);
  readAndCalc();
  serialPrint();
}

//double c_finder_a() {
//  double c = (C2*voltage2 + C3*voltage3)/(C1*voltage1 + C4*voltage4);
//  return c;
//}
//
//double c_finder_b() {
//  double c = (C1*voltage1 + C2*voltage2)/(C3*voltage3 + C4*voltage4);
//  return c;
//}



void readAndCalc() {
  delay(DATA_DELAY);
  voltage1 = analogRead(VOLTAGE1_PIN); delay(DATA_DELAY);
  voltage2 = analogRead(VOLTAGE2_PIN); delay(DATA_DELAY);
  voltage3 = analogRead(VOLTAGE3_PIN); delay(DATA_DELAY);
  voltage4 = analogRead(VOLTAGE4_PIN); delay(DATA_DELAY);
//  double Ca = c_finder_a();
//  double Cb = c_finder_b();
  alpha = (180.0/PI)*atan((WIDTH/(2*HEIGHT))*((double)((voltage1+voltage2)-(voltage3+voltage4))/(double)max((voltage1+voltage2),(voltage3+voltage4))));
  beta = (180.0/PI)*atan((WIDTH/(2*HEIGHT))*((double)((voltage1+voltage4)-(voltage2+voltage3))/(double)max((voltage1+voltage4),(voltage2+voltage3))));
}

void serialPrint() {
  Serial.print("Voltage: "
                 + String(C1*voltage1) + ',' 
                 + String(C2*voltage2) + ',' 
                 + String(C3*voltage3) + ',' 
                 + String(C4*voltage4) + ','
                 + "Angles: "
                 + String(alpha) + ','
                 + String(beta) + ','
                 + "AnglesInput: "
                 + String(sens) + ','
                 + String(plat) + ','
                 + '\n');
}

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


