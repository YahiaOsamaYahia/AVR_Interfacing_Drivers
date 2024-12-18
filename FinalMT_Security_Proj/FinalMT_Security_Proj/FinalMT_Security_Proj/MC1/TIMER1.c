/*
 * TIMER1.c
 *
 *  Created on: Nov 1, 2023
 *      Author: Lenovo
 */


#include "TIMER1.h"
#include "common_macros.h"
#include <avr/interrupt.h>
#include <avr/io.h>


/***********************************************************************************
                                 Global variables*
************************************************************************************/

/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;



/**********************************************************************************
                           interrupt service routine *
************************************************************************************/


/* If Compare Mode is used, ISR handles the callback*/
ISR(TIMER1_COMPA_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}


/* If Overflow Mode is used, ISR handles the callback*/
ISR(TIMER1_OVF_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}


void Timer1_init(const Timer1_ConfigType * Config_Ptr)
{
	/* FOC1A , FOC1B are active as we use a non-PWM mode*/
	TCCR1A = (1<<FOC1A) | (1<<FOC1B);
	TCCR1B = (TCCR1B & 0xF8) | (Config_Ptr->prescaler & (0x07));
	TCCR1B |= ((Config_Ptr->mode)>>2)<<3;
	TCCR1A |= ((Config_Ptr->mode)&(0x03));
	TCNT1 = Config_Ptr->initial_value;

	if( Config_Ptr-> mode == compare)
	{
		OCR1A = Config_Ptr->compare_value;
		TIMSK = (1<< OCIE1A);
	}
	else if(Config_Ptr-> mode == normal)
	{
		TIMSK = (1<< TOIE1);
	}

}
void Timer1_deInit(void)
{
	/* clear all TIMER1 registers */
	TIMSK = 0;
	TCNT1 = 0;
	TCCR1A = 0;
	TCCR1B = 0;
	OCR1A = 0;
}
void Timer1_setCallBack(void(*a_ptr)(void))
{
	g_callBackPtr = a_ptr;
}
