/****************************************************************************
* voltage2pwm.h
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


#define NUM_PWM_CHANNELS 3			// 3 channels

#define MIN_VOLTAGE 0				// 0 V
#define MAX_VOLTAGE 5				// 5 V
#define MIN_PWM_PERIOD 0			// 0 milliseconds
#define MAX_PWM_PERIOD 20000000 	// 20 milliseconds


unsigned long voltage2pwm(float voltage);
int updatePWM(float* voltage);