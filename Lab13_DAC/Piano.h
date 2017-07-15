// Piano.h
// Runs on LM4F120 or TM4C123, 
// edX lab 13 
// There are four keys in the piano
// Daniel Valvano, Jonathan Valvano
// December 29, 2014

// Completed by Guillaume Galasso with a score of 100% (simulation and real board)

#define DO_PERIOD  4790  // 80Mz / (523.251Hz * len (wave_table))
#define RE_PERIOD  4256 
#define MI_PERIOD  3792 
#define SOL_PERIOD 3189 

#define SILENCE  0x0  
#define DO       0x01 // C @ 523.251 Hz
#define RE       0x02 // D @ 587.330 Hz
#define MI       0x04 // E @ 659.255 Hz
#define SOL      0x08 // G @ 783.991 Hz

// **************Piano_Init*********************
// Initialize piano key inputs
// Input: none
// Output: none
void Piano_Init(void); 
  

// **************Piano_In*********************
// Input from piano key inputs
// Input: none 
// Output: 0 to 15 depending on keys
// 0x01 is key 0 pressed, 0x02 is key 1 pressed,
// 0x04 is key 2 pressed, 0x08 is key 3 pressed
unsigned long Piano_In(void);
