// DAC.c
// Runs on LM4F120 or TM4C123, 
// edX lab 13 
// Implementation of the 4-bit digital to analog converter
// Daniel Valvano, Jonathan Valvano
// December 29, 2014
// Port B bits 3-0 have the 4-bit DAC

#include "DAC.h"
#include "..//tm4c123gh6pm.h"

#define output_DAC  (* ((volatile unsigned long *) 0x400050FC)) // PORTB 0-5 0x04 + 0x08 + 0x10 + 0x20 + 0x40 + 0x80

// functions delaration
void DAC_Init(void);
void DAC_Out(unsigned long data);

// **************DAC_Init*********************
// Initialize 4-bit DAC 
// Input: none
// Output: none
void DAC_Init(void){
	// DAC in port B0 - B5
	volatile unsigned long delay;
	
  SYSCTL_RCGC2_R |= 0x00000002;        // 1) B clock
  delay = SYSCTL_RCGC2_R;              // delay   
  GPIO_PORTB_AMSEL_R &= ~0x3F;         // 3) disable analog function
  GPIO_PORTB_PCTL_R  &= ~0x00FFFFFF;   // 4) GPIO clear bit PCTL  
  GPIO_PORTB_DIR_R   |=  0x3F;         // 5) PB5 -- PB0 output   
	GPIO_PORTB_DR8R_R  |= 0x3F;          //    Enable 8 mA drive on PB5 - PB0
  GPIO_PORTB_AFSEL_R &= ~0x3F;         // 6) no alternate function
  GPIO_PORTB_PUR_R   &= ~0x03;         // disable pullup resistors on PB0 - PB1
  GPIO_PORTB_DEN_R    = 0x3F;          // 7) enable digital pins PB5-PB0       
	GPIO_PORTB_DATA_R  &= ~0x3F;         // 8) initialize DAC to off
}


// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Output: none
void DAC_Out(unsigned long data){
  output_DAC = (0x0F & data);
}
