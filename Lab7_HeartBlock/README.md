# Lab7_HeartBlock subject

Lab achieved with a score of 100% in simulation and real board tests.

## Purpose

In Lab7 you will walk through the design process to build a simple pacemaker. \
The system will read from a switch, makes decisions, and outputs to an LED. 

You will learn and understand the steps required to initialize parallel ports. You will write subroutines that wait for the switch to be pressed, wait for the switch to be released, and create an output pulse of fixed duration.

## System Requirements

In this lab you will create seven subroutines. \
There is one input called the Atrial sensor (AS), and two outputs Ready and Ventricular trigger (VT). \
AS input is connected to PF4. In a real pacemaker, electrodes (wires) are attached to the heart and electronics are used to sense the activity of the heart. \
In this lab, a switch will be used to emulate the operation of the atrial sensor. 
- When the switch SW1 is pressed (AS=0) it means the atria has begun to contract.
- When the switch SW1 is released, it means the atria have completed contraction. 

The Ready output is connected to PF3. The LED will be green when Ready is high. The Ready signal is used for debugging, and not part of an actual pacemaker. 
In this lab, the VT output is connected to PF1, such that the LED will be red when VT is high. A 250 ms pulse will cause the ventricules to contract.

## Completed files

`main.c` - main file

## Circuit diagram

![Alt text](Lab7_circuit.jpg?raw=true "Lab 7 circuit")
*Lab 7 circuit uses SW1 and the LED already on the LaunchPad. PF4 is an input, PF3 and PF1 are outputs*.
