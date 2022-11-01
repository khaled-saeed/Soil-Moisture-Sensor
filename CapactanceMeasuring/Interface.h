/*
 * Interface.h
 *
 * Created: 9/30/2022 12:00:11 AM
 *  Author: khaled
 */ 

#ifndef INTERFACE_H_
#define INTERFACE_H_
#define F_CPU 1000000U
#define SLAVE_ADDR 0x09
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "ADC/ADC.h"
#include <stdlib.h>
#include "I2C/I2CSlave.h"
#include "millis/millis.h"
#include "External_Interrupt/Interrupt.h"

const float IN_CAP_TO_GND  = 24.48;
const int MAX_ADC_VALUE = 1023;
float Setpoint = 3.3f ;
float MaxPoint= 34.2f;
int8_t percentage = 0 ;
float temp_capacitance = 0 ;
float capacitance = 0 ;
uint32_t lastTime = 0;
uint16_t _delay = 800 ;
uint32_t NoSamples = 0 ;

#define  SENSOR_OUT			(1<<2)	//PC2
#define  SENSOR_IN			(1<<0)	//PC0
#define  LED				(1<<4)	//PD4
#define  HIGH_LIMIT_BUTTON	(1<<2)	//PD2
#define  LOW_LIMIT_BUTTON	(1<<3)	//PD3 

typedef enum {
	UNPRESSED,
	PRESSED
	}BUTTON_STATUS_t;

BUTTON_STATUS_t LOW_BUTTON = UNPRESSED ; 
BUTTON_STATUS_t HIGH_BUTTON = UNPRESSED ;

#endif /* INTERFACE_H_ */