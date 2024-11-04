 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //                         LED Blinking Example TM4C123G Tiva LaunchPad                                         //
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Enable the clock for PORTF (Enable Clock)
// Physical address of RCGCGPIO = 0x400FE000+0x608=0x400FE608
// # define SYSCTL_RCGCGPIO_R (*(( volatile unsigned long *)0x400FE608))

// Configure the PORTF as a digital output
// GPIO PORTF base address = 0x4002 5000
// GPIODEN Register offset address = 0x51c // page number 682 TM4C123GH6PM datasheet
// physical address = 0x40025000+0x51C = 0x4002551C
// # define GPIO_PORTF_DEN_R (*(( volatile unsigned long *)0x4002551C))

// Setting PORTF Direction
// Base address of PORTF = 0x40025000
// Offset address of GPIODIR = 0x400 // // page number 663 TM4C123GH6PM datasheet
// GPIODIR Physical address =  0x40025000+0x400 = 0x40025400
// # define GPIO_PORTF_DIR_R *(( volatile unsigned long *)0x40025400))

// POTF GPIODATA Register
// PORTF Base Address  =   0x40025000
// GPIODATA Registe offset address = is 0x000
// GPIODATA  Physical address = 0x40025000+0x608 = 0x40025000
// #define GPIO_PORTF_DATA_R (*(( volatile unsigned long *)0x40025038))

// Turn on onboard LEDs of Tiva LaunchPad
//#define SYSCTL_RCGCGPIO_R (*(( volatile unsigned long *)0x400FE608 ) )
//#define GPIO_PORTF_DATA_R (*(( volatile unsigned long *)0x40025038 ) )
//#define GPIO_PORTF_DIR_R  (*(( volatile unsigned long *)0x40025400 ) )
//#define GPIO_PORTF_DEN_R  (*(( volatile unsigned long *)0x4002551C ) )
#include <stdint.h>
#include"tm4c123gh6pm.h"

int main(void) {
// put your main code here, to run repeatedly:
SYSCTL_RCGCGPIO_R |= 0x20;  // Enable clock for PORTF
GPIO_PORTF_DEN_R   = 0x0E;  // Enable PORTF Pin1, 2 and 3 as a digital pins
GPIO_PORTF_DIR_R   = 0x0E;  // Configure ORTF Pin1, 2 and 3 digital output pins

  while (1)
    {
     GPIO_PORTF_DATA_R |= 0x02; // turn on red LED
     __delay_cycles(16000000);
     GPIO_PORTF_DATA_R &= 0xfd; // turn on red LED
     __delay_cycles(16000000);
     GPIO_PORTF_DATA_R |= 0x04; // turn on blue LED
     __delay_cycles(16000000);
     GPIO_PORTF_DATA_R &= 0xfb; // turn on blue LED
     __delay_cycles(16000000);
     GPIO_PORTF_DATA_R |= 0x08; // turn on green LED
     __delay_cycles(16000000);
     GPIO_PORTF_DATA_R &= 0xf7; // turn on blue LED
     __delay_cycles(16000000);
    }
}
