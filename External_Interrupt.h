/*
 * External_Interrupt.h
 *
 * Created: 9/18/2020 9:07:09 PM
 *  Author: monad
 */ 
#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_
typedef unsigned char Uint8;
#define Interrupt_ControlRegister         (*((volatile Uint8*)0x55))
#define STAT_REG                          (*((volatile Uint8*)0x5F))
#define Interrupt_Control_StatRegister    (*((volatile Uint8*)0x54))
#define General_Interrupt_ControlRegister (*((volatile Uint8*)0x5B))
#define General_Interrupt_FlagRegister    (*((volatile Uint8*)0x5A))
// (Interrupt_ControlRegister &(0xF0))|(Low_Level) ----------------------------------->>>>>>

#define ISC_00 0
#define ISC_01 1
#define ISC_10 2
#define ISC_11 3
#define ISC_2  6
typedef enum{
LOW_Level=0,
Change_Level,
Falling_Edge,
Rising_Edge	
}Interrupt_SenseCtrl;

typedef enum{
	INT_Zero =0,
	INT_One,
    INT_Two
}Interrupt_Number;

typedef enum{
	INT0_EN=0,
	INT1_EN,
	INT2_EN
}Interrupt_Enable;
void Glob_INT_Enable(void);
void ExternalInterrupt_Init(Interrupt_SenseCtrl ISC,Interrupt_Number INTNUM);
void ExternalInterrupt_Func(void);
#endif /* EXTERNAL_INTERRUPT_H_ */