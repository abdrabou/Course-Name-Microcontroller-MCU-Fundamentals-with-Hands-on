#include <stdint.h>
#include"tm4c123gh6pm.h"

int main(void)
{
   unsigned int state;                 // Used to hold the state of the button.
   SYSCTL_RCGCGPIO_R  |= 0x20;         // enable clock to GPIOF
   GPIO_PORTF_LOCK_R   = 0x4C4F434B;   // unlockGPIOCR register
   GPIO_PORTF_CR_R    |= 0x10;         // Enable GPIOPUR register enable to commit
   GPIO_PORTF_PUR_R   |= 0x10;         // Enable Pull Up resistor PF4
   GPIO_PORTF_DIR_R   |= 0x02;         // set PF1 as an output and PF4 as an input pin
   GPIO_PORTF_DEN_R   |= 0x12;         // Enable PF1 and PF4 as a digital GPIO pins

    while(1)
    {
        state = GPIO_PORTF_DATA_R & 0x10; // Read PF4 (active high)
        // Control the red LED based on PF4 state
        if (state) {
            GPIO_PORTF_DATA_R &= ~0x02; // Turn of red LED (PF1)
        } else {
            GPIO_PORTF_DATA_R |= 0x02;  // Turn on red LED (PF1)
        }
    }
}
