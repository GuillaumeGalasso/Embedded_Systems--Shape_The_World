// ADC.c
// Runs on LM4F120/TM4C123
// Provide functions that initialize ADC0 SS3 to be triggered by
// software and trigger a conversion, wait for it to finish,
// and return the result. 
// Daniel Valvano
// January 15, 2016

/* This example accompanies the book
   "Embedded Systems: Introduction to ARM Cortex M Microcontrollers",
   ISBN: 978-1469998749, Jonathan Valvano, copyright (c) 2015

 Copyright 2016 by Jonathan W. Valvano, valvano@mail.utexas.edu
    You may use, edit, run or distribute this file
    as long as the above copyright notice remains
 THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 VALVANO SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 For more information about my classes, my research, and my books, see
 http://users.ece.utexas.edu/~valvano/
 */

#include "ADC.h"
#include "..//tm4c123gh6pm.h"

// This initialization function sets up the ADC 
// Max sample rate: <=125,000 samples/second
// SS3 triggering event: software trigger
// SS3 1st sample source:  channel 1
// SS3 interrupts: enabled but not promoted to controller
void ADC0_Init(void){ 
// Intialises ADC on PE2
	unsigned long volatile delay;
	SYSCTL_RCGC2_R |= 0x10; 				// activate port E
  delay = SYSCTL_RCGC2_R;
  GPIO_PORTE_DIR_R &= ~0X04;     	// make PE2 in
	GPIO_PORTE_AFSEL_R |= 0X04;  		// enable alt funct on PE2
	GPIO_PORTE_DEN_R &= ~0X04;     	// disable digital I/O on PE2
	GPIO_PORTE_AMSEL_R |= 0x04;     // enable analog on PE2
	
	SYSCTL_RCGC0_R |= 0x00010000;   // activate ADC0
	delay = SYSCTL_RCGC2_R;        
	SYSCTL_RCGC0_R &= ~0x00000300;  // 125K samplig rate
	ADC0_SSPRI_R = 0x0123;          // SS3 = highest priority
	ADC0_ACTSS_R &= ~0x0008;        // disable SS3
	ADC0_EMUX_R &= ~0xF000;         // software trigger
	ADC0_SSMUX3_R &= ~0x000F;       // clear SS3 
	ADC0_SSMUX3_R += 1;             // set channel to Ain1/PE2
	ADC0_SSCTL3_R = 0x0006;         // no TS0 D0, yes IE0 END0
	ADC0_ACTSS_R |= 0x0008;         // enable SS3
}


//------------ADC0_In------------
// Busy-wait Analog to digital conversion
// Input: none
// Output: 12-bit result of ADC conversion
unsigned long ADC0_In(void){  
	unsigned long res;
	ADC0_PSSI_R = 0x0008; // 1. initiate SS3
	while(!ADC0_RIS_R&0x08); // 2. wait for convertion (while ADC0_RIS_R&0x08 == 0)
	res = ADC0_SSFIFO3_R&0xFFF; // 3. result recuperation
	ADC0_ISC_R = 0x0008; // 4. acknowledge completion
	return res;
}
