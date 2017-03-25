#include "calculations.h"
#define MAXBYTES 256
#define MAXVOLTDIFF 4
#define LOOKUPTABLE "lookup.txt"

/*
Calculates the best angle based on a lookup table
@param realvolts - a voltage struct with the voltage readings
@return - an angle struct closest corresponding to the input
*/
angle_t *getAngles(voltage_t *realVolts) {
	float best = 4;
	float current;
	int servo;
	int plat;
	angle_t *currentAngle = malloc(sizeof(angle_t));
	voltage_t *lookVolts = malloc(sizeof(voltage_t));
	
	fp = fopen(LOOKUPTABLE, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	while (fscanf(fp, "%d,%d,%f,%f,%f,%f,", &servo, &plat, &lookVolts->volt1, &lookVolts->volt2, &lookVolts->volt3, &lookVolts->volt4) != EOF) {
		
		//fflush(stdout);
		// Calculates the deviation between these two voltges
		current = getDeviation(realVolts, lookVolts);
		//printf("current: %f", current);
		// replace the best angle if it has a lower deviation
		if (current < best) {
			currentAngle->alpha = servo;
			currentAngle->beta = plat;
			best = current;
			printf("New Best: %f at:", best);
			printf("Read: %d,%d,%f,%f,%f,%f\n", servo, plat, lookVolts->volt1, lookVolts->volt2, lookVolts->volt3, lookVolts->volt4);
		}
	}
	fclose(fp);
	if (line)
		free(line);
	return(currentAngle);
}

/*
Calculates the deviation between two sets of voltage values
@param realVolts - the first voltage struct
@param lookVolts - the second voltage struct
@return - a float between 0 and 4 indicating the deviation
*/
float getDeviation(voltage_t *realVolts, voltage_t *lookVolts) {
	return
		fabs(realVolts->volt1 - lookVolts->volt1) +
		fabs(realVolts->volt2 - lookVolts->volt2) +
		fabs(realVolts->volt3 - lookVolts->volt3) +
		fabs(realVolts->volt4 - lookVolts->volt4);
}

