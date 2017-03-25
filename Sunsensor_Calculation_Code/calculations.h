#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LOOKUP lookup.txt

FILE * fp;
char * line = NULL;
size_t len = 0;
ssize_t read;

typedef struct angle_s {
	int alpha;
	int beta;
} angle_t;

typedef struct voltage_s {
	float volt1;
	float volt2;
	float volt3;
	float volt4;
} voltage_t;

angle_t *getAngles(voltage_t *realVolts);

float getDeviation(voltage_t *realVolts, voltage_t *lookVolts);