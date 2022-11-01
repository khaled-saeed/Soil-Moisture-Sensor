/*
 * ADC.c
 *
 * Created: 9/6/2022 8:22:41 PM
 *  Author: khaled
 */ 
#include "ADC.h"
// right adjusted so we can read ADC 16 bit 
void ADC_init(Channel_t ch,ReferenceVal_t ref,InterruptStatus_t intStatus ,Prescaler_t pre)
{
	DDRC &= ~(1U<<ch); 
	ADMUX |= (ref<<REFS0) ; 
	ADMUX |= (ch<<MUX0) ; 
	if (intStatus == INT_ENABLED)
	{
		ADCSRA |= (1U<<ADIE) ;	// enable interrupt 
		ADCSRA |= (pre<<ADPS0);	// set prescaler 
		ADCSRA |= (1U<<ADEN);	// enable ADC 
		ADCSRA |= (1U<< ADSC);	// start conversion 
	}
	else
	{
		ADCSRA &= ~(1U<<ADIE) ; 
		ADCSRA |= (pre<<ADPS0);	// set prescaler

	}
}
uint16_t ADC_read(Channel_t ch)
{	
	DDRC &= ~(1U<<ch); 
	ADMUX |= (ch<<MUX0) ;
	ADCSRA |= (1U<<ADEN);						// enable ADC
	ADCSRA |= (1U<< ADSC);						// start conversion
	while(((ADCSRA&(1U<<ADIF))>>ADIF) != 1);	// busy wait as long the conversion has not finished 
	ADCSRA &= ~(1U<<ADIF);						// clear the flag 
	return ADC ;								// return the ADCL+ADCH 
}
void ADC_INT_Handler(void)
{
	ADC_INT_VAL = ADC ; 
	ADCSRA |= (1U<< ADSC);	// start conversion
}
void SetCallBackFunc(CallBackFuncPtr_t funcPtr)
{
	CallBackFuncPtr = funcPtr ; 
}