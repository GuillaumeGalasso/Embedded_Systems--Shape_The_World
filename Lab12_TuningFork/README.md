# Lab12_TuningFork subject

Lab achieved with a score of 100% in simulation and real board tests.

## Purpose

This lab has these major objectives: 
1. The understanding and implementing of interrupt software 
2. Interfacing an output pin to the speaker, so that the software can generate a quiet buzzing sound at 440 Hz 
3. the study the accuracy of the pitch created with interrupts. Please read the entire lab before starting.

## System Requirements

In this lab you will make a square wave sound at 440 Hz, which is a standard frequency created by a tuning fork. \
You will interface a positive logic switch as the input, and you will interface the headphones as an output.

A resistor placed in series with the headphones will control the loudness of the sound. \
Any value between 680 O and 2 kO will be OK. Selecting a larger the resistor will make the sound quieter.

## Completed files

`TuningFork.c` - main file

## Circuit diagram

![Alt text](Lab12_circuit.png?raw=true) \
*Possible hardware interface for Lab 12*.
