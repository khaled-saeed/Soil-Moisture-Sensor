#include "Interface.h"

void I2C_requested()
{
	I2C_transmitByte((int)percentage);
}


int main()
{
	init_millis(F_CPU); 
	ADC_init(CH0,AVCC,INT_DISABLED,PRESCALER16);
	I2C_setRequestedCallbacks(I2C_requested);
	I2C_init(SLAVE_ADDR); 
	DDRD |=	LED;  
	DDRD &=~ LOW_LIMIT_BUTTON; 
	DDRD &=~ HIGH_LIMIT_BUTTON;  
	DDRC |= SENSOR_OUT;
	EX_INT0_init(RISING_EDGE);
	EX_INT1_init(RISING_EDGE);
	setCallBackFunc_INT0(&INT0_Handler);
	setCallBackFunc_INT1(&INT1_Handler);
	sei();
	while(1) {
			DDRC &= ~SENSOR_IN; 
			PORTC |= SENSOR_OUT; 
			uint16_t val =ADC_read(CH0); 
			PORTC &= ~SENSOR_OUT; 
			if((val <1000) )
			{
				DDRC |=SENSOR_IN; 
				capacitance += (float)val * IN_CAP_TO_GND / (float)(MAX_ADC_VALUE - val);	
				NoSamples++; 
				if(millis() - lastTime >= _delay)
				{
					capacitance/= NoSamples ;
					temp_capacitance =capacitance ; 
					percentage =((capacitance-Setpoint)/MaxPoint)*100 ; 
					if (percentage < 0)
					{
						percentage = 0 ; 
					}
					else if (percentage > 100)
					{
						percentage = 100; 
					}
					NoSamples = 0 ;
					capacitance = 0 ;
					lastTime = millis();
				}
			}
			if (LOW_BUTTON == UNPRESSED && (PIND&LOW_LIMIT_BUTTON))
			{
				LOW_BUTTON = PRESSED ; 
			}
			if (LOW_BUTTON == PRESSED && (PIND&LOW_LIMIT_BUTTON))
			{
				//Setpoint = temp_capacitance ; 
				int i  ; 
				for (i = 0 ; i <6 ;i++)
				{
					PORTD ^= LED ; 
					_delay_ms(100) ; 
				}
			}
			else
			{
				LOW_BUTTON =UNPRESSED ;
				
			}
			if (HIGH_BUTTON == UNPRESSED && (PIND&HIGH_LIMIT_BUTTON))
			{
				HIGH_BUTTON = PRESSED ;
			}
			if (HIGH_BUTTON == PRESSED && (PIND&HIGH_LIMIT_BUTTON))
			{
				//MaxPoint = temp_capacitance ;
				int i  ;
				for (i = 0 ; i <6 ;i++)
				{
					PORTD ^= LED ;
					_delay_ms(100) ;
				}
			}
			else
			{
				HIGH_BUTTON =UNPRESSED ; 
				
			}
			if (HIGH_BUTTON == UNPRESSED && (PIND&HIGH_LIMIT_BUTTON) &&LOW_BUTTON == PRESSED && (PIND&LOW_LIMIT_BUTTON))
			{
				Setpoint = 0 ; 
				
				MaxPoint = 0 ; 
			}
			//while (millis() % 50 != 0);
		}      
}

ISR(INT0_vect)	// LOW limit
{
	(*CallBackFuncINT0_ptr)(); 
}

ISR(INT1_vect) // High limit
{
	(*CallBackFuncINT1_ptr)(); 
}