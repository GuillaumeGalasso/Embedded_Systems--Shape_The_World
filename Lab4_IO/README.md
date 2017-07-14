# Lab4_IO subject

Lab achieved with a score of 100% in simulation and real board tests.

## Purpose

The purpose of this second lab is to introduce a simple debugging process. \
We ask you to debug a simple program involving input from switches and output to LEDs.

## System Requirements

The system will have two inputs and three outputs. 
- The inputs are switches called SW1 and SW2, which are connected port pin PF4 and PF0 respectively.
- Three outputs (PF3, PF2, PF1) are connected to one multi-color LED. 
The color of the LED is determined by the 3-bit value written to the outputs. 

| Switch Input  | LED Output |
| --- | --- |
| Both switches SW1 and SW2 are pressed  | The LED should be blue |
| Just SW1 switch is pressed | The LED should be red |
| Just SW2 switch is pressed | The LED should be green |
| Neither SW1 or SW2 is pressed | The LED should be off |

*Specifications for Lab 4. SW1 is on PF4 and SW2 is on PF0*.

## Completed files

`main.c` - main file

## Circuit diagram

![Alt text](Lab4circuit.jpg?raw=true "Circuit diagram of the I/O using in Lab 4")
*Circuit diagram of the I/O using in Lab 4*.
