/* This is a timer interrupt example code of TM4C123 Tiva C Launchpad */
/* Generates a delay of one second using Timer1A interrupt handler routine */

#include <stdint.h>
#include"tm4c123gh6pm.h"      // Device header file for Tiva Series Microcontroller
#define Blue (1<<3)   // PF3 pin of TM4C123 Tiva Launchpad, Blue LED

void Time1A_1sec_delay(void);

int main(void)
{
    /*Iniitialize PF3 as a digital output pin */
   SYSCTL_RCGCGPIO_R |= 0x20; // turn on bus clock for GPIOF
   GPIO_PORTF_DIR_R       |= Blue; // set blue pin as a digital output pin
   GPIO_PORTF_DEN_R       |= Blue;  // Enable PF2 pin as a digital pin
   Time1A_1sec_delay();
    while(1)
    {
        // do nothing wait for the interrupt to occur
    }
}

/* Timer1 subtimer A interrupt service routine */
//TIMER1A_Handler()
void TIMER1A_Handler(void)
{
      if(TIMER1_MIS_R & 0x1)
      {
        GPIO_PORTF_DATA_R  ^= Blue; /* toggle Blue LED*/
        TIMER1_ICR_R = 0x1;          /* Timer1A timeout flag bit clears*/
      }
}

void Time1A_1sec_delay(void)
{
SYSCTL_RCGCTIMER_R |= (1<<1);   /*enable clock Timer1 subtimer A in run mode */
TIMER1_CTL_R        = 0;        /* disable timer1 output */
TIMER1_CFG_R        = 0x4;      /*select 16-bit configuration option */
TIMER1_TAMR_R       = 0x02;     /*select periodic down counter mode of timer1 */
TIMER1_TAPR_R       = 122-1;    /* TimerA prescaler value */
TIMER1_TAILR_R      = 64000-1 ; /* TimerA counter starting count down value  */
TIMER1_ICR_R        = 0x1;      /* TimerA timeout flag bit clears*/
TIMER1_IMR_R       |=(1<<0);    /*enables TimerA time-out  interrupt mask */
TIMER1_CTL_R       |= 0x01;     /* Enable TimerA module */
NVIC_EN0_R         |= (1<<21);  /*enable IRQ21 */
}
