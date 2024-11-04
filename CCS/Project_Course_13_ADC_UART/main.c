#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include"tm4c123gh6pm.h"

void Delay(unsigned long counter);
void UART5_init(void);
void UART5_Transmitter(unsigned char data);
void printstring(char *str);
char mesg[1000];
float voltage;

int main(void)
{
    unsigned int adc_value;
    UART5_init();

    /* Enable Clock to ADC0 and GPIO pins*/
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R4; /* Enable Clock to GPIOE or PE3/AN0 */
    SYSCTL_RCGCADC_R = SYSCTL_RCGCADC_R0;  /* AD0 clock enable*/

    /* initialize PE3 for AIN0 input*/
    GPIO_PORTE_AFSEL_R |= (1<<3); /* enable alternate function */
    GPIO_PORTE_DEN_R &= ~(1<<3);  /* disable digital function */
    GPIO_PORTE_AMSEL_R |= (1<<3); /* enable analog function */

    /* initialize sample sequencer3*/
    ADC0_ACTSS_R &= ~(1<<3);/* disable SS3 during configuration */
    ADC0_EMUX_R &= ~0xF000;    /* software trigger conversion */
    ADC0_SSMUX3_R = 0;         /* get input from channel 0 */
    ADC0_SSCTL3_R |= (1<<1)|(1<<2);        /* take one sample at a time, set flag at 1st sample */
    ADC0_ACTSS_R  |= (1<<3);         /* enable ADC0 sequencer 3 */

    printstring("\rReading ADR Value through MCU-UART to PC-UART:\n");
    printstring("\r==============================================\n");

    while(1)
    {
        ADC0_PC_R = 0x3;              /*sampling rate = 250ksps*/
        ADC0_PSSI_R |= (1<<3);        /* Enable SS3 conversion or start sampling data from AN0 */
        while((ADC0_RIS_R & 8) == 0) ;   /* Wait untill sample conversion completed*/
        adc_value = ADC0_SSFIFO3_R; /* read adc coversion result from SS3 FIFO*/
        ADC0_ISC_R = 8;          /* clear coversion clear flag bit*/

        /* convert digital value back into voltage */
        voltage = (adc_value * 0.0008);

        sprintf(mesg, "\r\nVoltage = %0.3f Volts", voltage);
        printstring(mesg);
        Delay(1000);
    }
}

void UART5_init(void)
{
    SYSCTL_RCGCUART_R |= 0x20;  /* enable clock to UART5 */
    SYSCTL_RCGCGPIO_R |= 0x10;  /* enable clock to PORTE for PE4/Rx and PE5/Tx */

    Delay(1);

    /* UART5 TX5 and RX5 use PE4 and PE5. Configure them digital and enable alternate function */
    GPIO_PORTE_DEN_R   = 0x30;           /* set PE4 and PE5 as digital */
    GPIO_PORTE_AFSEL_R = 0x30;           /* Use PE4,PE5 alternate function */
    GPIO_PORTE_AMSEL_R = 0;              /* Turn off analog function */
    GPIO_PORTE_PCTL_R  = 0x00110000;     /* configure PE4 and PE5 for UART, P.1352 */
    /* 0x00330000  for I2C, P.1352 */
    /* 0x00440000  for PWM, P.1352 */
    /* UART5 initialization */
    UART5_CTL_R = 0;         /* UART5 module disbable */
    UART5_IBRD_R = 104;      /* for 9600 baud rate, integer = 104 */
    UART5_FBRD_R = 11;       /* for 9600 baud rate, fractional = 11*/
    UART5_CC_R = 0;          /*select system clock*/
    UART5_LCRH_R = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
    UART5_CTL_R = 0x301;     /* Enable UART5 module, Rx and Tx */
}

void UART5_Transmitter(unsigned char data)
{
    while((UART5_FR_R & (1<<5)) != 0); /* wait until Tx buffer not full */
    UART5_DR_R = data;                 /* before giving it another byte */
}

void printstring(char *str)
{
    while(*str)
    {
        UART5_Transmitter(*(str++));
    }
}

void Delay(unsigned long counter)
{
    unsigned long i = 0;

    for(i=0; i< counter*1000; i++);
}

