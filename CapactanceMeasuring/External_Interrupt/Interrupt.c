/*
 * Interrupt.c
 *
 * Created: 9/6/2022 1:36:51 PM
 *  Author: khaled
 */ 
#include "Interrupt.h"
extern float temp_capacitance ; 
extern float Setpoint ;
extern float MaxPoint ;
void EX_INT0_init(SenseControl_t IntSrc) 
{
	EICRA |=(IntSrc<<ISC00); 
	EIMSK |= (1U<<INT0_EN); 
}

void EX_INT1_init(SenseControl_t IntSrc) 
{
	EICRA |=(IntSrc<<ISC10);
	EIMSK |= (1U<<INT1_EN);
}

void setCallBackFunc_INT0(CallBackFpt_t callBackFunction)
{
	CallBackFuncINT0_ptr = callBackFunction ; 
}
void setCallBackFunc_INT1(CallBackFpt_t callBackFunction)
{
	CallBackFuncINT1_ptr = callBackFunction ; 
}

void INT0_Handler(void)
{
	MaxPoint = temp_capacitance - Setpoint ;
}
void INT1_Handler(void)
{
	Setpoint = temp_capacitance ; 
}
