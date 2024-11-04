#include <stdint.h>
#include"tm4c123gh6pm.h"

int main(void)
{

    SYSCTL_RCC_R |=     0x02400540;
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R5;
//    SYSCTL_RCGCGPIO_R = (1<<5);

    GPIO_PORTF_DEN_R |= 0x0000000F;
    GPIO_PORTF_DIR_R |= 0x0000000F;
    while(1)
    {
        GPIO_PORTF_DATA_R = 0x0000002;
        __delay_cycles(1000000);
        GPIO_PORTF_DATA_R = 0x0000000;
        __delay_cycles(1000000);

        GPIO_PORTF_DATA_R = 0x0000004;
        __delay_cycles(800000);
        GPIO_PORTF_DATA_R = 0x0000000;
        __delay_cycles(800000);

        GPIO_PORTF_DATA_R = 0x0000008;
        __delay_cycles(800000);
        GPIO_PORTF_DATA_R = 0x0000000;
        __delay_cycles(800000);
    }
}
