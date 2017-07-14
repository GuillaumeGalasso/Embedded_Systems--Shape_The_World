# Lab10_TrafficLight subject

Lab achieved with a score of 100% in simulation and real board tests.

## Purpose
Learn to implement a finite state machine & use SysTick.  


## System Requirements
Simulates the traffic light of a traffic junction.  
Has 3 vehicle/pedestrian direction, of which only 1 direction will be green at any time.   
Uses buttons as vehicle/pedestrian sensor, and LEDs as traffic lights.

You will interface 6 LEDs that represent the two Red-Yellow-Green traffic lights, and you will use 
- the PF3 green LED for the “walk” light 
- the PF1 red LED for the “don’t walk” light. 

The system behavior is:
When the “walk” condition is signified, pedestrians are allowed to cross in any direction. \
When the “don’t walk” light flashes (and the two traffic signals are red), pedestrians should hurry up and finish crossing. \
When the “don’t walk” condition is on steady, pedestrians should not enter the intersection.

![Alt text](Lab10_circuit.png?raw=true "Traffic Light Intersection")

*Traffic Light Intersection*.

## Completed files

`TableTrafficLight.c` - main file
