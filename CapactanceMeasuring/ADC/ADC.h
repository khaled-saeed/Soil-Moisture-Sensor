/*
 * ADC.h
 *
 * Created: 9/6/2022 8:23:10 PM
 *  Author: khaled
 */ 


#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>
uint16_t ADC_INT_VAL ;
typedef void(*CallBackFuncPtr_t)(void); 
CallBackFuncPtr_t CallBackFuncPtr ; 
typedef enum{
	CH0,
	CH1,
	CH2,
	CH3,
	CH4,
	CH5,

	}Channel_t;
typedef enum{
	AREF,
	AVCC,
	INTERNAL=3
	}ReferenceVal_t;
typedef enum{
	INT_DISABLED,
	INT_ENABLED
	}InterruptStatus_t;
typedef enum{
	PRESCALER2,
	PRESCALER4=2,
	PRESCALER8,
	PRESCALER16,
	PRESCALER32,
	PRESCALER64,
	PRESCALER128
	}Prescaler_t;
typedef enum{
	SW_TRIGGERED,
	AUTO_TRIGGERED
}EnableMode_t;



void ADC_init(Channel_t,ReferenceVal_t,InterruptStatus_t,Prescaler_t);
uint16_t ADC_read(Channel_t);
void ADC_INT_Handler(void); 
void SetCallBackFunc(CallBackFuncPtr_t);



#endif /* ADC_H_ */