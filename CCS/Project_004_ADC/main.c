/* TM4C123G Tiva C Series ADC Example */

/* This Program controls the onboard green LED based on discrete digital value of ADC */
/* If AN0 channel value is less 2048 digital value than LED turns off and otherwise remain on */
//#include "TM4C123GH6PM.h"
#include <stdint.h>

#include"tm4c123gh6pm.h"


//void SystemInit(void)
//{
//    SCB->CPACR |= 0x00f00000;
//}


int main(void)
{
     unsigned int adc_value;

/* Enable Clock to ADC0 and GPIO pins*/
      SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R4; /* Enable Clock to GPIOE or PE3/AN0 */
      SYSCTL_RCGCADC_R = SYSCTL_RCGCADC_R0;  /* AD0 clock enable*/

/* initialize PE3 for AIN0 input  */
      GPIO_PORTE_AFSEL_R |= (1<<3); /* enable alternate function */
      GPIO_PORTE_DEN_R &= ~(1<<3);  /* disable digital function */
      GPIO_PORTE_AMSEL_R |= (1<<3); /* enable analog function */

/* initialize sample sequencer3 */
      ADC0_ACTSS_R &= ~(1<<3);/* disable SS3 during configuration */
      ADC0_EMUX_R &= ~0xF000;    /* software trigger conversion */
      ADC0_SSMUX3_R = 0;         /* get input from channel 0 */
      ADC0_SSCTL3_R |= (1<<1)|(1<<2);        /* take one sample at a time, set flag at 1st sample */
      ADC0_ACTSS_R  |= (1<<3);         /* enable ADC0 sequencer 3 */

/*Iniitialize PF3 as a digital output pin */
      SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R5; // turn on bus clock for GPIOF
      GPIO_PORTF_DIR_R |= 0x08; //set GREEN pin as a digital output pin
      GPIO_PORTF_DEN_R |= 0x08;  // Enable PF3 pin as a digital pin
    while(1)
    {
        ADC0_PSSI_R |= (1<<3);        /* Enable SS3 conversion or start sampling data from AN0 */
        while((ADC0_RIS_R & 8) == 0) ;   /* Wait untill sample conversion completed*/
        adc_value = ADC0_SSFIFO3_R; /* read adc coversion result from SS3 FIFO*/
        ADC0_ISC_R = 8;          /* clear coversion clear flag bit*/
            /*control Green PF3->LED */
            if(adc_value >= 2048)
                GPIO_PORTF_DATA_R  = 0x08; /* turn on green LED*/
            else if(adc_value < 2048)
                GPIO_PORTF_DATA_R  = 0x00; /* turn off green LED*/
    }
}

//void SystemInit(void)
//{
//    SCB->CPACR |= 0x00f00000;
//}
