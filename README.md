# EMBEDDED_SYSTEMS - SHAPE_THE_WORLD
A two-module embedded systems MOOC from UTAustinX

This 16-week class is split into two 8-week classes : 
- UT.6.10x Embedded Systems - Shape The World: Microcontroller Input/Output includes Modules 1 to 10
- UT.6.20x Embedded Systems - Shape The World: Multi-Threaded Interfacing includes Modules 11 to 16

## Goals for UT.6.10x Embedded Systems - Shape The World: Microcontroller Input/Output :

1. The understanding of embedded systems using modular design and abstraction
2. Embedded C programming: considering both function and style
3. The strategic use of memory
4. Debugging and verification using a simulator and on the real microcontroller 
5. How input/output using switches, LEDs, stepper motors, and serial ports
6. The implementation of an I/O driver using busy-wait synchronization
7. Understanding how local variables and parameters work
8. Simple motors (e.g., open stepper motor control)


## Goals UT.6.20x Embedded Systems - Shape The World: Multi-Threaded Interfacing :

1. How input/output using switches, LEDs, DACs, ADCs, motors, and serial ports
2. The implementation of an I/O driver using interrupt synchronization
3. Multithreaded programming using interrupts
4. Analog to digital conversion (ADC), periodic sampling 
5. DC motors and closed-loop motor control
6. Digital to analog conversion (DAC), used to make simple sounds, Design and implementation of elementary data structures
7. Introduction to the Internet of Things using wifi

## Syllabus

### Module 1: Introduction

### Module 2: Fundamental concepts: numbers, computers, and the ARM Cortex M processor
Example. Develop a system that toggles an LED on the LaunchPad

Lab 2. Run existing project on LaunchPad with switch input and LED output

### Module 3: Electronics: resistors, voltage, current and Ohm’s Law    

### Module 4: Digital Logic: transistors, flip flops and logic functions
Lab 4. Debug a system with two inputs and two outputs

### Module 5: Introduction to C/Embedded C programming
Example. Develop a system that inputs and outputs on the serial port \
Lab 5. Write a C function and perform input/output on the serial port

### Module 6: Microcontroller Input/Output
Example. Develop a system that inputs from a switch and toggles an LED output
Lab 6. Write C software that inputs from a switch and toggles an LED output

### Module 7: Design and Development Process
Example. Develop a system that outputs a pattern on an LED 
Lab 7. Write C functions that inputs from a switch and outputs to two LEDs, which is a simulated pacemaker

### Module 8: Interfacing Switches and LEDs
Example. Develop a system with an external switch and LED
Lab 8. Interface an external switch and LED and write input/output software.

### Module 9: Arrays and Functional Debugging
Example. Develop a system that debugs by dumping data into an array
Lab 9. Write C functions using array data structures that collect/debug your system.

### Module 10: Finite State Machines
Example. Develop a simple finite state machine
Example. Develop a vending machine using a finite state machine
Example. Develop a line-tracking robot using a finite state machine
Example. Develop a stepper motor robot using a finite state machine
Lab 10. Interface 3 switches and 6 LEDs and create a traffic light finite state machine

### Module 11: UART - The Serial Interface, I/O Synchronization
Example 11. Develop a communication network using the serial port
Lab 11. Write C functions that output decimal and fixed-point numbers to serial port

### Module 12: Interrupts
Example 12. Develop a system that outputs a square wave using interrupts
Example 12. Develop a system that inputs from a switch using interrupts
Example 12. Develop a system that outputs to a DC motor that uses pulse width modulation
Lab 12. Design and test a guitar tuner, producing a 440 Hz tone

### Module 13: DAC and Sound
Example 13. Develop a system that outputs analog signal with a R-2R digital to analog converter 
Lab 13. Design and test a digital piano, with 4 inputs, digital to analog conversion, and sound

### Module 14: ADC and Data Acquisition
Example 14. Develop a system that inputs an analog signal with an analog to digital  converter 
Example 14. Develop an autonomous robot that uses two DC motors and two distance sensors 
Lab 14. Design and test a position measurement, with analog to digital conversion and calibrated output

### Module 15: Systems Approach to Game Design
Lab 15. Design and test a hand-held video game, which integrates all components from previous labs.

### Module 16: Wireless Communication and the Internet of Things
Lab 16. Connect a CC3100 booster pack to the LaunchPad and communicate with an access point. Lab 16 will not be graded, but we will provide a way for you communicate with a class server
