// BranchingFunctionsDelays.c Lab 6
// Runs on LM4F120/TM4C123
// Use simple programming structures in C to 
// toggle an LED while a button is pressed and 
// turn the LED on when the button is released.  
// This lab will use the hardware already built into the LaunchPad.
// Daniel Valvano, Jonathan Valvano
// January 15, 2016

// Completed by Guillaume Galasso with a score of 100% (simulation and real board)

// built-in connection: PF0 connected to negative logic momentary switch, SW2
// built-in connection: PF1 connected to red LED
// built-in connection: PF2 connected to blue LED
// built-in connection: PF3 connected to green LED
// built-in connection: PF4 connected to negative logic momentary switch, SW1


/////////////////////
///// Algorithm /////
/////////////////////

/*

main     Turn on the clock for Port F
               Clear the PF4 and PF2 bits in Port F AMSEL to disable analog
               Clear the PF4 and PF2 bit fields in Port F PCTL to configure as GPIO
               Set the Port F direction register so 
                                PF4 is an input and 
                                PF2 is an output
               Clear the PF4 and PF2 bits in Port F AFSEL to disable alternate functions
               Set the PF4 and PF2 bits in Port F DEN to enable digital
               Set the PF4 bit in Port F PUR to activate an internal pullup resistor
               Set the PF2 bit in Port F DATA so the LED is initially ON
loop       Delay about 100 ms
                Read the switch and test if the switch is pressed
                If PF4=0 (the switch is pressed),
                                toggle PF2 (flip bit from 0 to 1, or from 1 to 0)
                If PF4=1 (the switch is not pressed), 
                                set PF2, so LED is ON
                Go to loop

*/


#include "TExaS.h"

#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_RCGC2_GPIOF      0x00000020  // port F Clock 

// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts


// PortF initialisation function
void PortF_Init() { 
		volatile unsigned long delay;
		SYSCTL_RCGC2_R = 0x000000020;
		delay = SYSCTL_RCGC2_R;
		GPIO_PORTF_LOCK_R = 0x4C4F434B;
		GPIO_PORTF_CR_R = 0x1F;
		GPIO_PORTF_AMSEL_R = 0x00;
		GPIO_PORTF_PCTL_R = 0x00000000;
		GPIO_PORTF_DIR_R = 0x0E;
		GPIO_PORTF_AFSEL_R = 0x00;
		GPIO_PORTF_PUR_R = 0x11;
		GPIO_PORTF_DEN_R = 0x1F;
		GPIO_PORTF_DATA_R = 0x04;		
	}

// delay function
void Delay100ms(unsigned long time){
  unsigned long i;
  while(time > 0){
    i = 1333333;  // this number means 100ms
    while(i > 0){
      i --;
    }
    time --; // decrements every 100 ms
  }
}

// global variables
unsigned long input; // input = PF4
unsigned long output; // output = PF2 (blue LED)

int main(void){
  TExaS_Init(SW_PIN_PF4, LED_PIN_PF2);  // activate grader and set system clock to 80 MHz
  PortF_Init(); // initialization of Port F
  EnableInterrupts();           // enable interrupts for the grader
	
  while(1){
    Delay100ms(1); // 100ms delay
		input = (GPIO_PORTF_DATA_R&0x10) >> 2 ; // read the GPIO_PORTF_DATA_R for the sw1 and right shift for sw1 state recuperation
		
		// test of the switch
		if (input==0x00) // sw1 is pressed
			output = GPIO_PORTF_DATA_R ^= 0x04; // output is toogled blue LED
		else output = GPIO_PORTF_DATA_R = 0x04; // output is  blue LED
  }
}

// Color    LED(s) PortF
// dark     ---    0
// red      R--    0x02
// blue     --B    0x04
// green    -G-    0x08
// yellow   RG-    0x0A
// sky blue -GB    0x0C
// white    RGB    0x0E
// pink     R-B    0x06