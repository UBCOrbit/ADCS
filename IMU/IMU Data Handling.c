#include <stdio.h>
#include <math.h>

main()
{
	
	}

// param: the x, y, z gyroscope data provided by the IMU that defines the IMU's axis of rotation
// return: a struct containing double amperage values to be supplied to the three reaction wheels
	struct reactionWheelsManeuwver (double x, doubly y, double z){
		
		// placeholder constants to adjust the amperage, will likely not actually be a constant
		const k_x =   
		const k_y = 
		const k_z = 

		struct WheelAmps amps;

		// exponential included so that the motor spins at higher speed when there is higher displacement
		// will need adjustment depending on range of x, y, z possible and constant multiplier
		double wheel_1 = x > 0 ? k_x * exp(abs(x)) : -1.0 * k_x * exp(abs(x));
		double wheel_2 = y > 0 ? k_y * exp(abs(y)) : -1.0 * k_y * exp(abs(y));
		double wheel_3 = z > 0 ? k_z * exp(abs(z)) : -1.0 * k_z * exp(abs(z));

		//conditional statement included so that reaction wheel is inactive if angular velocity on corresponding axis is 0
		strcopy(amps.wheel1Amps , x = 0.0 ? 0.0 : wheel_1);
		strcopy(amps.wheel2Amps , y = 0.0 ? 0.0 : wheel_2);
		strcopy(amps.wheel3Amps , z = 0.0 ? 0.0 : wheel_3);

		return amps;
	}

struct WheelAmps {
	// consider renaming variables for clarity with findDiscrepancy parameters
    double wheel1Amps;
    double wheel2Amps;
    double wheel3Amps;
};