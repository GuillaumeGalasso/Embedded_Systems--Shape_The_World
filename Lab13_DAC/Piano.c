// Piano.c
// Runs on LM4F120 or TM4C123, 
// edX lab 13 
// There are four keys in the piano
// Daniel Valvano
// December 29, 2014

// Port A bits 5-2 have 4 piano keys

#include "Piano.h"
#include "..//tm4c123gh6pm.h"

#define KEY_C  (* ((volatile unsigned long *) 0x40004010))  
#define KEY_D  (* ((volatile unsigned long *) 0x40004020))  
#define KEY_E  (* ((volatile unsigned long *) 0x40004040))  
#define KEY_G  (* ((volatile unsigned long *) 0x40004080))  

// functions declaration
void Piano_Init(void);
unsigned long Piano_In(void);

// **************Piano_Init*********************
// Initialize piano key inputs
// Input: none
// Output: none
void Piano_Init(void){ 
  unsigned long volatile delay;
  SYSCTL_RCGC2_R |= 0x00000001; // activate port A
  delay = SYSCTL_RCGC2_R;
	
	// OUTPUT
  GPIO_PORTA_AMSEL_R &= ~0x0C;      // no analog
  GPIO_PORTA_PCTL_R &= ~0x00FFFF00; // regular function
	GPIO_PORTA_DIR_R &= 0xC3;         // make PA 2-5 in
  GPIO_PORTA_AFSEL_R &= ~0x3C;      // disable alt funct on PA 2-5
  GPIO_PORTA_DEN_R |= 0x3C;         // enable digital I/O on PA3, PA2
}

// **************Piano_In*********************
// Input from piano key inputs
// Input: none 
// Output: 0 to 15 depending on keys
// 0x01 is key 0 pressed, 0x02 is key 1 pressed,
// 0x04 is key 2 pressed, 0x08 is key 3 pressed
unsigned long Piano_In(void){
  unsigned long key_pressed = SILENCE;
	
	if (KEY_C)   key_pressed = DO;
	if (KEY_D)   key_pressed = RE;
	if (KEY_E)   key_pressed = MI;
	if (KEY_G)   key_pressed = SOL;
	
	return key_pressed;
}
