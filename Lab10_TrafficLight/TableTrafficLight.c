// ***** 0. Documentation Section *****
// TableTrafficLight.c for Lab 10
// Runs on LM4F120/TM4C123
// Index implementation of a Moore finite state machine to operate a traffic light.  
// Daniel Valvano, Jonathan Valvano
// January 15, 2016

// Completed by Guillaume Galasso with a score of 100% (simulation and real board)

// east/west red light connected to PB5
// east/west yellow light connected to PB4
// east/west green light connected to PB3
// north/south facing red light connected to PB2
// north/south facing yellow light connected to PB1
// north/south facing green light connected to PB0
// pedestrian detector connected to PE2 (1=pedestrian present)
// north/south car detector connected to PE1 (1=car present)
// east/west car detector connected to PE0 (1=car present)
// "walk" light connected to PF3 (built-in green LED)
// "don't walk" light connected to PF1 (built-in red LED)

// ***** 1. Pre-processor Directives Section *****
#include "TExaS.h"
#include "tm4c123gh6pm.h"

// ***** 2. Global Declarations Section *****

#define NVIC_ST_CTRL_R      (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R    (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R   (*((volatile unsigned long *)0xE000E018))

#define SENSORS							(*((volatile unsigned long *)0x4002401C))
#define LIGHT_WALK	      	(*((volatile unsigned long *)0x40025028))
#define LIGHT_TRAFFIC			  (*((volatile unsigned long *)0x400050FC))
	
// struct of a state in the FSM
typedef struct{
	unsigned long Time; // delay time (Time * 0.5s)
	unsigned long Traffic; // output for traffic lights (portB)
	unsigned long Walk; // output for pedestrian lights (portF)
	unsigned long Next[8]; // next state
} TrafficLightType;

// function prototypes
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void ports_BEF_Init(void); // Initialisation of port B,E and F
void SysTick_Init(void); // Initalise systick
void SysTick_Wait1ms(unsigned long delay); // Function to delay for 1ms
void SysTick_Wait(unsigned long delay); // Fucntion to delay for integer multiples of 10ms
// ***** 3. Subroutines Section *****

void ports_BEF_Init(void){	
	unsigned long volatile delay;
	SYSCTL_RCGC2_R |= 0x32; // activate clock for Port B,E,F
  delay = SYSCTL_RCGC2_R; // allow time for clock to start
	
	// Port B
  GPIO_PORTB_LOCK_R = 0x4C4F434B;   // unlock port
  GPIO_PORTB_CR_R = 0x3F;           // allow changes to PB5-0
	GPIO_PORTB_PCTL_R = 0x00000000;   // clear PCTL
  GPIO_PORTB_AMSEL_R &= ~0x3F;      // disable analog on PB5-0
  GPIO_PORTB_AFSEL_R &= ~0x3F;      // disable alt funct on PB5-0
  GPIO_PORTB_DEN_R |= 0x3F;         // enable digital I/O on PB5-0
	GPIO_PORTB_DIR_R |= 0x3F;         // PB5-0 outputs
	
	// Port E
  GPIO_PORTE_LOCK_R = 0x4C4F434B;   // unlock port
  GPIO_PORTE_CR_R = 0x07;           // allow changes to PE2-0
	GPIO_PORTE_PCTL_R = 0x00000000;   // clear PCTL
  GPIO_PORTE_AMSEL_R &= ~0x07;      // disable analog on PE2-0
  GPIO_PORTE_AFSEL_R &= ~0x07;      // disable alt funct on PE2-0
  GPIO_PORTE_PUR_R &= ~0x07;        // disableb pull-up on PE2-0
  GPIO_PORTE_DEN_R |= 0x07;         // enable digital I/O on PE2-0
	GPIO_PORTE_DIR_R &= ~0x07;        // PE2-0 inputs

	// Port F
  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // unlock port
  GPIO_PORTF_CR_R = 0x0A;           // allow changes to PF1 & PF3
	GPIO_PORTF_PCTL_R = 0x00000000;   // clear PCTL
  GPIO_PORTF_AMSEL_R &= ~0x0A;      // disable analog on PF1 & PF3
  GPIO_PORTF_AFSEL_R &= ~0x0A;      // disable alt funct on PF1 & PF3
  GPIO_PORTF_DEN_R |= 0x0A;         // enable digital I/O on PF1 & PF3
	GPIO_PORTF_DIR_R |= 0x0A;         // PF1 & PF3 outputs
}


void SysTick_Init(void){
  NVIC_ST_CTRL_R = 0;               // disable SysTick during setup
  NVIC_ST_CTRL_R = 0x00000005;      // enable SysTick with core clock
}

void SysTick_Wait1ms(unsigned long delay){
	unsigned long i;
	for (i=0 ; i<delay; i++){
		NVIC_ST_RELOAD_R = 800000 - 1;  // number of counts to wait (80Mhz PLL)
		NVIC_ST_CURRENT_R = 0;       // any value written to CURRENT clears
		while((NVIC_ST_CTRL_R&0x00010000)==0){ // wait for count flag
		}
	}
}

void SysTick_Wait(unsigned long delay){
	unsigned long i;
	for(i=0; i < delay; i++)
		SysTick_Wait1ms(10);
}

int main(void){ 
	// FSM initialisation
	unsigned long current_state = 0; // Initial state is 0
	TrafficLightType FSM[11]={
		{20,0x0C,0x02,{0,0,1,1,1,1,1,1}},
		{30,0x14,0x02,{1,0,2,2,4,4,2,2}},
		{20,0x21,0x02,{2,3,2,3,3,3,3,3}},
		{30,0x22,0x02,{3,0,2,0,4,0,4,4}},
		{20,0x24,0x08,{4,5,5,5,4,5,5,5}},
		{5,0x24,0x00,{4,6,6,6,4,6,6,6}},
		{5,0x24,0x02,{4,7,7,7,4,7,7,7}},
		{5,0x24,0x00,{4,8,8,8,4,8,8,8}},
		{5,0x24,0x02,{4,9,9,9,4,9,9,9}},
		{5,0x24,0x00,{4,10,10,10,4,10,10,10}},
		{5,0x24,0x02,{5,0,2,0,4,0,2,0}}
	};
	
	// General initialisations
	TExaS_Init(SW_PIN_PE210, LED_PIN_PB543210,ScopeOff); // activate grader and set system clock to 80 MHz
	ports_BEF_Init(); // Initialise port B,E,F
	SysTick_Init(); // Initialise systick
  EnableInterrupts(); // Enable interruptions
	
  while(1){
    LIGHT_TRAFFIC = FSM[current_state].Traffic;  // set traffic lights
		LIGHT_WALK = FSM[current_state].Walk; // set pedestrian lights
    SysTick_Wait(FSM[current_state].Time); // delay
    current_state = FSM[current_state].Next[SENSORS];  // next state
  }
}

