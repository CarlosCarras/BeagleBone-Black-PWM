/****************************************************************************
* PWM.cpp
*
* @about      : a library for inrerfacing with PWM pins on the BBB.
* @hardware   : BeagleBone Black
* @author     : Carlos Carrasquillo
* @contact    : c.carrasquillo@ufl.edu
* @date       : May 21, 2021
* @modified   : May 23, 2021
*
* Property of ADAMUS lab, University of Florida.
*
* Parts of this code are inspired by code found at: 
*     http://www.nagavenkat.adurthi.com/control-robotics-experiments/304/
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "PWM.h"


int set_period_ns(unsigned int channel, unsigned long period) {
	return set_pwm_property(channel, "period_ns", period);
}


int set_duty_ns(unsigned int channel, unsigned long duty) {
	return set_pwm_property(channel, "duty_ns", period);
}
 

int start_pwms(unsigned int channel) {
	return set_pwm_property(channel, "run", 1);
} 


int stop_pwms(unsigned int channel) {
	return set_pwm_property(channel, "run", 0);
} 



/*********************************** Supplemental ***********************************/

int set_pwm_property(unsigned int channel, std::string property, unsigned long value) {
	char buf[MAX_BUF]; 
	ofstream pwmfile();

	snprintf(buf, sizeof(buf), "/sys/class/pwm/pwm%d/%s", channel, property.c_str());

	pwmfile = open(buf);
	if (!pwmfile.is_open()) { 
		std::cout << "ERROR: Unable to open '" << buf << "' (PWM)." << std::endl; 
		return -1;
	}
		 
	snprintf(buf, sizeof(buf), "%lu", value);
	pwmfile << buf;
	pwmfile.close();

 	return 0;
}