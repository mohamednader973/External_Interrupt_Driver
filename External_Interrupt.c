/*
 * External_Interrupt.c
 *
 * Created: 9/18/2020 9:06:50 PM
 *  Author: monad
 */ 
#include "External_Interrupt.h"
#include "DIO_INOUT.h"
#include <avr/interrupt.h>
void Glob_INT_Enable(void)
{
	STAT_REG |=(1<<7);
}
void Glob_INT_Clear(void)
{
	STAT_REG &=~(1<<7);
}
void ExternalInterrupt_Init(Interrupt_SenseCtrl ISC,Interrupt_Number INTNUM)
{
	if (INTNUM==INT_Zero)
	{
		switch(ISC)
		{
			case LOW_Level:
			General_Interrupt_ControlRegister |=(1<<6);
			ClearBIT(Interrupt_ControlRegister,ISC_00);
			ClearBIT(Interrupt_ControlRegister,ISC_01);
			break;
			case Change_Level:
			General_Interrupt_ControlRegister |=(1<<6);
			SetBIT(Interrupt_ControlRegister,ISC_00);
			ClearBIT(Interrupt_ControlRegister,ISC_01);
			break;
			case Falling_Edge:
			General_Interrupt_ControlRegister |=(1<<6);
			ClearBIT(Interrupt_ControlRegister,ISC_00);
			SetBIT(Interrupt_ControlRegister,ISC_01);
			break;
			case Rising_Edge:
			General_Interrupt_ControlRegister |=(1<<6);
			SetBIT(Interrupt_ControlRegister,ISC_00);
			SetBIT(Interrupt_ControlRegister,ISC_01);
			break;
		}
	}
	else if (INTNUM==INT_One)
	{
		switch(ISC)
		{
			case LOW_Level:
			General_Interrupt_ControlRegister |=(1<<7);
			ClearBIT(Interrupt_ControlRegister,ISC_10);
			ClearBIT(Interrupt_ControlRegister,ISC_11);
			break;
			case Change_Level:
			General_Interrupt_ControlRegister |=(1<<7);
			SetBIT(Interrupt_ControlRegister,ISC_10);
			ClearBIT(Interrupt_ControlRegister,ISC_11);
			break;
			case Falling_Edge:
			General_Interrupt_ControlRegister |=(1<<7);
			ClearBIT(Interrupt_ControlRegister,ISC_10);
			SetBIT(Interrupt_ControlRegister,ISC_11);
			break;
			case Rising_Edge:
			General_Interrupt_ControlRegister |=(1<<7);
			SetBIT(Interrupt_ControlRegister,ISC_10);
			SetBIT(Interrupt_ControlRegister,ISC_11);
			break;
		}
	}
	else if (INTNUM==INT_Two)
	{
		switch(ISC)
		{
			case LOW_Level:
			break;
			case Change_Level:
			break;
			case Falling_Edge:
			General_Interrupt_ControlRegister |=(1<<5);
			ClearBIT(Interrupt_ControlRegister,ISC_2);
			break;
			case Rising_Edge:
			General_Interrupt_ControlRegister |=(1<<5);
			SetBIT(Interrupt_ControlRegister,ISC_2);
			break;	
		}
	}	
}
/*void ExternalInterrupt_Func(void)
{
 DIO_WRITE(DIO_PORTC,PIN_SEVEN,HIGH);	
}*/
