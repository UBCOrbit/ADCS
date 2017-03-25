#define _GNU_SOURCE
#include "calculations.c"

int main(void) {
	angle_t *currentAngle = malloc(sizeof(angle_t));
	voltage_t *realVolts = malloc(sizeof(voltage_t));
	realVolts->volt1 = 0.27;
	realVolts->volt2 = 0.60;
	realVolts->volt3 = 0.11;
	realVolts->volt4 = 0.02;
	currentAngle = getAngles(realVolts);
	printf("The servo angle is : %d\n", currentAngle->alpha);
	printf("The platform angle is : %d\n", currentAngle->beta);
}