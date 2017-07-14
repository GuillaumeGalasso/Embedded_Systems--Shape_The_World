# Lab8_SwitchLEDinterface subject

Lab achieved with a score of 100% in simulation and real board tests.

## Purpose
The purpose of this lab is to learn how to interface a switch and an LED. \
You will perform explicit measurements on the circuits in order to verify they are operational.

## System Requirements
Use external switch to flash the external LED at 5Hz or leave it off. 

1. Make PE1 an output and make PE0 an input. 
2. The system starts with the LED on (make PE1 =1). 
3. Wait about 100 ms
4. If the switch is pressed (PE0 is 1), then toggle the LED once, else turn the LED on. 
5. Steps 3 and 4 are repeated over and over.

## Completed files

`SwitchLEDInterface.c` - main file

## Circuit diagram

![Alt text](Lab8circuit.png?raw=true "Lab 7 circuit")

*One possible Lab 8 interface connecting the input to PE0 and the output to PE1*.
