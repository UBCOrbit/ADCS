#include <stdio.h>
#include <math.h>

main()
{
	
	}

// param: the x, y, z gyroscope data provided by the IMU
// return: a struct containing double amperage values to be supplied to the three reaction wheels
	struct findDiscrepancy (double x, doubly y, double z){
		
		// placeholder constants to adjust the amperage, will likely not actually be a constant
		const k_a = 
		const k_b = 
		const k_g = 

		struct Vector amps;

		double magnitude = sqrt(x * x + y * y + z * z);

		// need to look in to undefined conditions for acos
		double alpha = acos(x/mag);
		double beta = acos(y/mag);
		double gamma = acos(z/mag);

		strcopy(amps.x , k_a * alpha);
		strcopy(amps.y , k_b * beta);
		strcopy(amps.z , k_g * gamma);

		return amps;
	}

struct Vector {
	// consider renaming variables for clarity with findDiscrepancy parameters
    double x;
    double y;
    double z;
};