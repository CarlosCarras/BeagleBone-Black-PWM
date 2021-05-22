/****************************************************************************
* voltage2pwm.cpp
*
* @about      : converts a voltage value into a PWM period (in ns) value.
* @author     : Carlos Carrasquillo
* @contact    : c.carrasquillo@ufl.edu
* @date       : May 21, 2021
* @modified   : May 21, 2021
*
* Property of ADAMUS lab, University of Florida.
****************************************************************************/

#include "PWM.h"

int pwm_channels[NUM_PWM_CHANNELS] = {0, 1, 2};


unsigned long voltage2pwm(float voltage) {
	return (voltage - MIN_VOLTAGE) * (MAX_PWM_PERIOD - MIN_PWM_PERIOD) / (MAX_VOLTAGE - MIN_VOLTAGE) + MIN_PWM_PERIOD;	// mapping function
}


int updatePWM(float* voltage) {
	int pwm[NUM_PWM_CHANNELS];
	unsigned long period;
	int status = 0;

	for (int i = 0; i < NUM_PWM_CHANNELS; i++) {
		period = voltage2pwm(voltage[i]);
		status += set_period(pwm_channels[i], period_ns);
	}

	return status;
}