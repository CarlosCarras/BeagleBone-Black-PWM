/****************************************************************************
* voltage2pwm.cpp
*
* @about      : converts a voltage value into a PWM period (in ns) value.
* @author     : Carlos Carrasquillo
* @contact    : c.carrasquillo@ufl.edu
* @date       : May 21, 2021
* @modified   : May 23, 2021
*
* Property of ADAMUS lab, University of Florida.
****************************************************************************/

#include "PWM.h"

int pwm_channels[NUM_PWM_CHANNELS] = {0, 1, 2};


int initPWM() {
	int status = 0;

	/* sets all PWM periods */
	for (int i = 0; i < NUM_PWM_CHANNELS; i++) {
		status += set_period(pwm_channels[i], PWM_PERIOD);
	}

	return status;
}


unsigned long voltage2pwm(float voltage) {
	return (voltage - MIN_VOLTAGE) * (MAX_PWM_DUTY - MIN_PWM_DUTY) / (MAX_VOLTAGE - MIN_VOLTAGE) + MIN_PWM_DUTY;	// mapping function
}


int updatePWM(float* voltage) {
	int pwm[NUM_PWM_CHANNELS];
	unsigned long period;
	int status = 0;

	/* sets length of all PWM duty cycles */
	for (int i = 0; i < NUM_PWM_CHANNELS; i++) {
		period = voltage2pwm(voltage[i]);
		status += set_duty(pwm_channels[i], period);
	}

	return status;
}