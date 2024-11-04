#include <stdint.h>

#define SYSCTL_RCGCGPIO_R       (*((volatile uint32_t *)0x400FE608))
#define GPIO_PORTF_DEN_R        (*((volatile uint32_t *)0x4002551C))
#define GPIO_PORTF_DIR_R        (*((volatile uint32_t *)0x40025400))
#define GPIO_PORTF_DATA_R (*(( volatile unsigned long *)0x40025038 ))

int main(void)
{
    SYSCTL_RCGCGPIO_R = 0x20;   // Enable clock for PORTF
    GPIO_PORTF_DEN_R = 0x0E;    // Enable PORTF Pin1, 2 and 3 as a digital pins
    GPIO_PORTF_DIR_R = 0x0E;    // Configure PORTF Pin1, 2 and 3 digital output pins
    while (1)
        {
        GPIO_PORTF_DATA_R |= 0x02; // turn on red LED
//        GPIO_PORTF_DATA_R = (1<<1); // turn on red LED
//        GPIO_PORTF_DATA_R = (1<<2); // turn on blue LED
//        GPIO_PORTF_DATA_R = (1<<3); // turn on green LED

        }
}
