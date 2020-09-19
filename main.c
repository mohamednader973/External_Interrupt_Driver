/*
 * External_Interrupt_Driver.c
 *
 * Created: 9/18/2020 8:57:14 PM
 * Author : monad
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "External_Interrupt.h"
#include "DIO_INOUT.h"
char flag;
int main(void)
{
	DIO_init(DIO_PORTC,PIN_SEVEN,OUTPUT);
	DIO_init(DIO_PORTC,PIN_TWO,OUTPUT);
	DIO_init(DIO_PORTA,PIN_THREE,OUTPUT);
	DIO_init(DIO_PORTD,PIN_TWO,INPUT);
	ExternalInterrupt_Init(Rising_Edge,INT_Zero);
    /* Replace with your application code */
    while (1) 
    {
		if (((PIND>>2)&1)==1)
		{
			sei();
		}
		DIO_WRITE(DIO_PORTC,PIN_SEVEN,HIGH);
		
		
    }
}
ISR(INT0_vect)
{
	 DIO_WRITE(DIO_PORTC,PIN_SEVEN,HIGH);
	 DIO_WRITE(DIO_PORTA,PIN_THREE,HIGH);
	 _delay_ms(3000);
	 DIO_WRITE(DIO_PORTC,PIN_SEVEN,LOW);
	 DIO_WRITE(DIO_PORTA,PIN_THREE,LOW);
	 _delay_ms(3000);
	 cli();
}

