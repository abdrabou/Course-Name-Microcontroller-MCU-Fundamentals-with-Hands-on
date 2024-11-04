#include <stdint.h>
#include"tm4c123gh6pm.h"

int main(void)
{
    SYSCTL_RCGCGPIO_R = 0x20;   // Enable clock for PORTF
    GPIO_PORTF_DEN_R  = 0x0E;    // Enable PORTF Pin1, 2 and 3 as a digital pins
    GPIO_PORTF_DIR_R  = 0x0E;    // Configure PORTF Pin1, 2 and 3 digital output pins
    while (1)
        {
        GPIO_PORTF_DATA_R |= 0x02; // turn on red LED
        __delay_cycles(8000000);   // delay 1 sec
        GPIO_PORTF_DATA_R &= 0x00; // turn off red LED
        __delay_cycles(8000000);   // delay 1 sec

        GPIO_PORTF_DATA_R |= 0x04; // turn on blue LED
        __delay_cycles(8000000);   // delay 1 sec
        GPIO_PORTF_DATA_R &= 0x00; // turn off blue LED
        __delay_cycles(8000000);   // delay 1 sec

        GPIO_PORTF_DATA_R |= 0x08; // turn on green LED
        __delay_cycles(8000000);   // delay 1 sec
        GPIO_PORTF_DATA_R &= 0x00; // turn off green LED
        __delay_cycles(8000000);   // delay 1 sec
        }
}
