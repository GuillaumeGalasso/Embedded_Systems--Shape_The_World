# Lab2_HelloLaunchPad subject

## Purpose

When first learning a new programming language it is tradition to begin by running a program that outputs the message “Hello World”. \
Later you will write your own programs, but in this lab you will run simply a program that we have written for you. \

The input and output on the microcontroller comes from physical devices like switches and LEDs. \
Consequently, our “Hello World” will ask you to push a switch and observe an LED. \
The purpose of this lab is to work through the process of configuring the development system for the microcontroller board, and to learn how we will be grading labs in this course.

## System Requirements

The system will have one input and three outputs. 
- The input is a switch called SW1, which is connected port pin PF4. 
- Three outputs (PF3, PF2, PF1) are connected to one multi-color LED. \
  The color of the LED is determined by the 3-bit value written to the outputs. 
  * If SW1 is not pressed the LED toggles blue-red
  * If SW1 is pressed the LED toggles blue-green.
