/****************************************************************************
* PWM.h
*
* @about      : a library for inrerfacing with PWM pins on the BBB.
* @hardware   : BeagleBone Black
* @author     : Carlos Carrasquillo
* @contact    : c.carrasquillo@ufl.edu
* @date       : May 21, 2021
* @modified   : May 21, 2021
*
* Property of ADAMUS lab, University of Florida.
****************************************************************************/

#include <string.h>


#define MAX_BUF 64


int set_period_ns(unsigned int channel, unsigned long period);
int set_duty_ns(unsigned int channel, unsigned long duty);
int start_pwms(unsigned int channel);
int stop_pwms(unsigned int channel);

/*********************************** Supplemental ***********************************/
int set_pwm_property(unsigned int channel, std::string property, unsigned long value);