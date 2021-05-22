/****************************************************************************
* main.cpp
*
* @about      : a demo - ONLY TO BE USED BY CAMILO FOR TESTING
* @author     : Carlos Carrasquillo
* @contact    : c.carrasquillo@ufl.edu
* @date       : May 21, 2021
* @modified   : May 21, 2021
*
* Property of ADAMUS lab, University of Florida.
****************************************************************************/

#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include "voltage2pwm.h"


void get_voltages(float* voltages) {
	voltages[0] = rand() % 6;	// random number ranges from 0 to 5V
	voltages[1] = rand() % 6;	// random number ranges from 0 to 5V
	voltages[2] = rand() % 6;	// random number ranges from 0 to 5V
}


int main() {
	float voltages[3]; 
	int status;

	while(1) {
		get_voltages(voltages);
		updatePWM(voltages);
		sleep(1);
	}

	return 0;
}