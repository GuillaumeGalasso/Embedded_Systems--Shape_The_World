// ***** 0. Documentation Section *****
// SwitchLEDInterface.c for Lab 8
// Runs on LM4F120/TM4C123
// Use simple programming structures in C to toggle an LED
// while a button is pressed and turn the LED on when the
// button is released.  This lab requires external hardware
// to be wired to the LaunchPad using the prototyping board.
// January 15, 2016
//      Jon Valvano and Ramesh Yerraballi

// Completed by Guillaume Galasso with a score of 100% (simulation and real board)

// ***** 1. Pre-processor Directives Section *****
#include "TExaS.h"
#include "tm4c123gh6pm.h"

// ***** 2. Global Declarations Section *****
#define CYCLE_ONE_MS 16000*25/30
#define PE0   (*((volatile unsigned long *)0x40024004))
#define PE1   (*((volatile unsigned long *)0x40024008))
	
unsigned long input;
unsigned long output;

// FUNCTION PROTOTYPES: Each subroutine defined
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts

void portE_init(void);
void Delay1ms(unsigned long time);
void LED_On(void) {GPIO_PORTE_DATA_R |= 0x02;};

// ***** 3. Subroutines Section *****

// Subroutine to delay in units of half seconds
// Inputs: Number of half seconds to delay
// Outputs: None
// simple delay function
// which delays time*500 milliseconds
// assuming 80 MHz clock
// The following C function can be used to delay. 
// The number 133333 assumes 6 cycles per loop (10ms/12.5ns/6). 
// The Keil optimization is set at Level 0 (-O0) and the ?Optimize for Time? mode is unchecked.

void Delay1ms(unsigned long time)
{
  unsigned long i;
  while(time > 0){
    i = CYCLE_ONE_MS; //26666 for 16MHz; // 80MHz clock: 133333 for 16Mhz
    while(i > 0){
      i--;
    }
    time --;
  }
}

void portE_init(void)
{
	unsigned long volatile initDelay;
	
  // E clock
	SYSCTL_RCGC2_R     |= 0x13;           
  initDelay           = SYSCTL_RCGC2_R;       // wait 3-5 bus cycles
	
  GPIO_PORTE_DIR_R   &= ~0x01;        // PE0 input 
  GPIO_PORTE_AFSEL_R &= ~0x01;      // not alternative
  GPIO_PORTE_AMSEL_R &= ~0x01;      // no analog
  GPIO_PORTE_PCTL_R  &= ~0x0000000F; // bits for PE0
  GPIO_PORTE_DEN_R   |= 0x01;         // enable PE0
	GPIO_PORTE_PUR_R   &= ~0x01;        // Pull up disable, we're going to connect it outside
	
  GPIO_PORTE_DIR_R 	 |= 0x02;           // PE1 output
  GPIO_PORTE_AFSEL_R &= ~0x02;          // not alternative
  GPIO_PORTE_AMSEL_R &= ~0x02;          // no analog
  GPIO_PORTE_PCTL_R  &= ~0x000000F0;    // bits for PD1
  GPIO_PORTE_DEN_R   |= 0x02;           // enable PD1
	GPIO_PORTE_PUR_R   &= ~0x02;          // Pull up disable, we're going to connect it outside
}



int main(void){ 
//**********************************************************************
// The following version tests input on PE0 and output on PE1
//**********************************************************************
  TExaS_Init(SW_PIN_PE0, LED_PIN_PE1,ScopeOn);  // activate grader and set system clock to 80 MHz
  
	
  EnableInterrupts();           // enable interrupts for the grader
  
	portE_init();
	LED_On();
	  
	while(1)
	{
		Delay1ms(100);
		input = GPIO_PORTE_DATA_R&0x01;   // read PE0 into In
     if (input == 0x01) {
         GPIO_PORTE_DATA_R = GPIO_PORTE_DATA_R ^ 0x02; // toggle the LED
     } else {
         GPIO_PORTE_DATA_R |= 0x02;         // the LED ON (make PE1 =1). 
     }
  }
  
}