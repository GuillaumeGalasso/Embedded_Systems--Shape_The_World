# Lab13_DAC subject

## Purpose

This lab has these major objectives: 
1. To learn about DAC conversion
2. To understand how digital data stored in a computer could be used to represent sounds and music
3. To study how the DAC  and interrupts can be used together to create sounds

## System Requirements

Most digital music devices rely on high-speed DACs to create the analog waveforms required to produce high-quality sound. \
In this lab, you will create a very simple sound generation system that illustrates this application of the DAC. \
Your goal is to create an embedded system that plays four notes, which will be a digital piano with four keys.

The first step is to design and test a 4-bit binary-weighted DAC, which converts 4 bits of digital output from the TM4C123 to an analog signal. \
You are free to design your DAC with a precision of more than 4 bits. The simulator supports up to 6 bits. \
You will convert the digital output signals to an analog output using a simple resistor network. During the static testing phase, you will connect the DAC analog output to the voltmeter and measure resolution, range, precision, and accuracy. \
During the dynamic testing phase, you will connect the DAC output to the scope to see the waveform verses time. If you connect the DAC to headphones, you will be able to hear the sounds created by your software.

The performance score of this lab is not based on loudness but sound quality. The quality of the music will depend on both hardware and software factors. \
The precision of the DAC, the external noise, and the dynamic range of the speaker are some of the hardware factors. Software factors include the DAC output rate and the number of data points stored in the sound data.

![Alt text](Lab13_circuit.png?raw=true)
*DAC allows the software to create music. In the simulator mode, the output voltage Vout is called DACOUT*.

The second step is to design a low-level device driver for the DAC.
The third step is to design a low-level device driver for the four keys of the piano. 
The fourth step is to organize the sound generation software into a device driver

The wave should be generated whenever one key is pressed and held. These are the standard frequencies which your digital piano must produce:
- Piano key 3: G generates a sinusoidal DACOUT at 783.991 Hz
- Piano key 2: E generates a sinusoidal DACOUT at 659.255 Hz
- Piano key 1: D generates a sinusoidal DACOUT at 587.330 Hz
- Piano key 0: C generates a sinusoidal DACOUT at 523.251 Hz