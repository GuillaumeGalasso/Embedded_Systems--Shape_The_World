# Lab14_MeasurementOfDistance subject

Lab achieved with a score of 100% in simulation and real board tests.

## Purpose

This lab has these major objectives: 
1. An introduction to sampling analog signals using the ADC interface 
2. The development of an ADC device driver 
3. Learning data conversion and calibration techniques. 
4. The use of fixed-point numbers, which are integers used to represent non-integer values 
5. The development of an interrupt-driven real-time sampling device driver 
6. The development of a software system involving multiple files  
7. To learn how to debug one module at a time

## System Requirements

In this lab you will design a distance meter. A linear slide potentiometer converts distance into resistance (0 = R = 10 kO). \
Your software will use the 12-bit ADC built into the microcontroller. The ADC will be sampled at 40 Hz using SysTick interrupts. \
You will write a C function that converts the ADC sample into distance, with units of 0.001 cm. That data stream will be passed from the ISR into the main program using a mailbox, and the main program will output the data on a display.

The pot used in the photos and videos measures distance from 0 to 2 cm. You will use an electrical circuit to convert resistance into voltage (Vin). Since the potentiometer has three leads. The default ADC channel is AIN1, which is on PE2. The TM4C123 ADC will convert voltage into a 12-bit digital number (0 to 4095). 

This ADC is a successive approximation device with a conversion time on the order of several µsec. Your software will calculate distance with a resolution of 0.001 cm.

## Completed files

`ADC.c` - ADC functions file \
`MeasurementOfDistance.c` - main file

## Circuit diagram

![Alt text](Lab14_circuit.jpg?raw=true) \
*Possible electrical circuit to interface the distance transducer to the microcontroller. PE2 is ADC channel 1*.
