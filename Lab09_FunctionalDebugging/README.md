# Lab9_FunctionalDebugging subject

Lab achieved with a score of 100% in simulation and real board tests.

## Purpose
Lean to implement a data dump for debugging.

## System Requirements
Use built-in switch to flash the built-in LED at 10Hz or leave it off. 
Also dumps data with timestamp whenever switch input changes.

Your system will be graded on its ability to satisfy the following requirements.

- If both PF4 and PF0 switch are not pressed, the PF1 output should be low.
- If either PF4 or PF0 switches is pressed, the output is inverted every 50 ms, making it oscillate at 10 Hz (±10%).
- Information collected in the Data array matches the I/O on PortF.
- 50 data points are collected only on a change in input or a change in output. (i.e., no adjacent elements in the array are equal).

## Completed files

`main.c` - main file
