#!/bin/bash

# description : Configures the pins with special functions on the D3 CubeSat's BeagleBone Black.
#
# author   : Carlos Carrasquillo
# email    : carlos.carrasquillo99@gmail.com
# created  : May 18, 2021
# modified : May 18, 2021
# source   : https://www.bacpeters.com/2020/01/25/configuring-the-beaglebone-black-gpio-pins-permanently/
# 
# To execute this script: 
# 	1) place this script in '/home/debian'
#	2) $ sudo chmod +x pin_config.sh 
#	4) place the 'd3-pin-config.service' script in '/etc/systemd/system' 
#	5) $ sudo systemctl start d3-pin-config.service
# 	6) $ sudo systemctl enable d3-pin-config.service


config-pin p9.16 pwm	# magnetorquer 1


exit 0