#include <stdint.h>
#include"tm4c123gh6pm.h"

# define GPIO_PORTF_DATA_RD (*(( volatile unsigned long *)0x40025040))
# define GPIO_PORTF_DATA_WR (*(( volatile unsigned long *)0x40025020))

int main(void) {
  static char flag = 0;
//  SYSCTL_RCGCGPIO_R |= 0x20; // Enable clock to GPIO Port F
//  GPIO_PORTF_DEN_R  |= 0x18;
//  GPIO_PORTF_DIR_R  |= 0x08;
//  GPIO_PORTF_DIR_R  &= 0xfe;
//  GPIO_PORTF_LOCK_R = 0x4C4F434B; // unlockGPIOCR register
//  GPIO_PORTF_CR_R |= 0x10;        //En. GPIOPUR enable to commit
//  GPIO_PORTF_PUR_R  |= 0x10;


  SYSCTL_RCGCGPIO_R |= 0x20;      // Enable clock to GPIO Port F
  GPIO_PORTF_DEN_R  |= 0x18;      // Enable digital function on PF3 and PF4 (0x18 = 00011000)
  GPIO_PORTF_DIR_R  |= 0x08;      // Set PF3 as output (0x08 = 00001000)
  GPIO_PORTF_DIR_R  &= 0xFE;      // Set PF4 as input (clear bit 0, leaving other bits unchanged)
  GPIO_PORTF_LOCK_R = 0x4C4F434B; // Unlock GPIOCR register to modify protected pins (e.g., PF4)
  GPIO_PORTF_CR_R   |= 0x10;      // Allow commits to PF4 (0x10 = 00010000)
  GPIO_PORTF_PUR_R  |= 0x10;      // Enable pull-up resistor on PF4 (0x10 = 00010000)

while(1)
{
  if(GPIO_PORTF_DATA_RD == 0)
  {
    __delay_cycles(1000000);   // delay 1/8 sec
    if(( flag == 0) && (GPIO_PORTF_DATA_RD == 0))
    {
      GPIO_PORTF_DATA_WR ^= 0x08;
      flag = 1;
    }
  }
  else
  {
    flag = 0;
  }
}
}
