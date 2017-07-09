# EMBEDDED SYSTEMS - SHAPE THE WORLD
A two-module embedded systems MOOC on edX from the University of Texas at Austin. \
Date: June - September 2017

This 16-week class is split into two 8-week classes : 
- **UT.6.10x Embedded Systems - Shape The World: [Microcontroller Input/Output](https://www.edx.org/course/embedded-systems-shape-world-utaustinx-ut-6-10x)** includes Modules 1 to 10. \
  [Certificate]() obtained with a grade of % (*not shown on the certificate but you can find a view [here]()*) \
  [Certifcate Verification]()
- **UT.6.20x Embedded Systems - Shape The World: [Multi-Threaded Interfacing](https://www.edx.org/course/embedded-systems-shape-world-multi-utaustinx-ut-6-20x)** includes Modules 11 to 16. \
  [Certificate]() obtained with a grade of % (*not shown on the certificate but you can find a view [here]()*) \
  [Certifcate Verification]()

## Syllabus

#### Module 1: Introduction

#### Module 2: Fundamental concepts: numbers, computers, and the ARM Cortex M processor
2.1 Binary Number and Systems
2.2 Embedded Systems
2.3 Introduction to Computers
2.4 I/O Ports
2.5 CPU Registers
2.6 Assembly Language
2.7 Address Space
2.8 Software Development Process
Lab 2: Run existing project on LaunchPad with switch input and LED output

#### Module 3: Electronics: resistors, voltage, current and Ohm’s Law    

#### Module 4: Digital Logic: transistors, flip flops and logic functions
Lab 4: Debug a system with two inputs and two outputs

#### Module 5: Introduction to C/Embedded C programming
Lab 5: Write a C function and perform input/output on the serial port

#### Module 6: Microcontroller Input/Output\
Lab 6: Write C software that inputs from a switch and toggles an LED output

#### Module 7: Design and Development Process
Lab 7: Write C functions that inputs from a switch and outputs to two LEDs, which is a simulated pacemaker \
Lab 7 bis : Write C functions that inputs from a switch and outputs a LED, which is a SOS morse code message

#### Module 8: Interfacing Switches and LEDs
Lab 8: Interface an external switch and LED and write input/output software.

#### Module 9: Arrays and Functional Debugging
Lab 9: Write C functions using array data structures that collect/debug your system.

#### Module 10: Finite State Machines
Lab 10: Interface 3 switches and 6 LEDs and create a traffic light finite state machine 

#### Module 11: UART - The Serial Interface, I/O Synchronization
Lab 11: Write C functions that output decimal and fixed-point numbers to serial port 

#### Module 12: Interrupts
Lab 12: Design and test a guitar tuner, producing a 440 Hz tone 

#### Module 13: DAC and Sound
Lab 13: Design and test a digital piano, with 4 inputs, digital to analog conversion, and sound

#### Module 14: ADC and Data Acquisition
Lab 14: Design and test a position measurement, with analog to digital conversion and calibrated output

#### Module 15: Systems Approach to Game Design
Lab 15: Design and test a hand-held video game, which integrates all components from previous labs

#### Module 16: Wireless Communication and the Internet of Things
Lab 16: Connect a CC3100 booster pack (wifi module) to the LaunchPad and communicate with an access point

## Common Files

There are some file types which will appear in every lab assignment. \
I will just describe their purpose here instead of repeating in each README.md. 

`***.uvproj` `***.uvgui` `***.uvopt` - uVision files (open `***.uvproj` to get the full project) \
`***.axf` `TExaS.h` `texas.o` - autograder files \
`tm4c123gh6pm.h` - useful address definitions for launchpad \
`startup.s` - assembly startup file

## Requirements

**[Kiel uVsion 4](https://www.keil.com/demo/eval/armv4.htm)** - All the code/debug were done on this IDE. \
**[Stellaris/Tiva LaunchPad](http://www.ti.com/tool/ek-tm4c123gxl)** - Everything is meant to work on a EK-TM4C123G launchpad. \
**[Electronic Components](http://edx-org-utaustinx.s3.amazonaws.com/UT601x/worldwide.html)** - Some labs requires a set of extra electronic parts.
