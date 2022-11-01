/*
 * Interrupt.h
 *
 * Created: 9/6/2022 1:36:36 PM
 *  Author: khaled
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include <avr/io.h>

/************************************************************************/
/*				       Registers Pins Definition                        */
/************************************************************************/
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define INT1_EN  1
#define INT0_EN  0
#define INT1_F  1
#define INT0_F  0

/************************************************************************/
/*				     The Interrupt Trigger INT0/1                       */
/************************************************************************/
typedef enum {
	LOW_LEVEL,
	RISING_FALLING_EDGE,
	FALLING_EDGE,
	RISING_EDGE
	}SenseControl_t;

/************************************************************************/
/*			       Callback functions initializations                   */
/************************************************************************/
typedef void(*CallBackFpt_t)(void); 
CallBackFpt_t CallBackFuncINT0_ptr ,CallBackFuncINT1_ptr,CallBackFuncINT2_ptr;
/************************************************************************/
/*				         Interrupts control Functions                   */
/************************************************************************/
/* 
 * Function EX_INT0_init
 * Desc     Function To Initialize External interrupt 0 INT0 
 * Input    The trigger signal type
 * Output   nothing
 */
	

void EX_INT0_init(SenseControl_t) ;


/*
 * Function EX_INT1_init
 * Desc     Function To Initialize External interrupt 1 INT1 
 * Input    The trigger signal type
 * Output   nothing
 */
	
void EX_INT1_init(SenseControl_t) ;

/*
 * Function setCallBackFunc_INT0
 * Desc     Initialize the callback function for interrupt 0 INT0 
 * Input    pointer  to the interrupt handler
 * Output   nothing
 */

void setCallBackFunc_INT0(CallBackFpt_t); 

/*
 * Function setCallBackFunc_INT1
 * Desc     Initialize the callback function for interrupt 1 INT1 
 * Input    pointer  to the interrupt handler
 * Output   nothing
 */
void setCallBackFunc_INT1(CallBackFpt_t);



/*
 * Function INT0_Handler
 * Desc     Function of the ISR handler of INT0
 * Input    nothing
 * Output   nothing
 */
void INT0_Handler(void);

/*
 * Function INT1_Handler
 * Desc     Function of the ISR handler of INT1
 * Input    nothing
 * Output   nothing
 */
void INT1_Handler(void);



#endif /* INTERRUPT_H_ */