/*
 * PWM.c
 *
 *  Created on: Nov 7, 2023
 *      Author: Lenovo
 */


#include "PWM.h"
#include "common_macros.h"
#include "gpio.h"
#include <avr/io.h>


void PWM_Timer0_Start(uint8 duty_cycle)
{
	/* configure the timer registers:
	 * 1-operate on fast PWM mode
	 * 2-prescaler with F_CPU/8.
	 * 3-the PWM mode with Non-Inverting
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);

	/* Configure PB3/OC0 as output pin */
	GPIO_setupPinDirection(PORTD_ID, PIN7_ID , PIN_OUTPUT);

	 /* initial value for the timer */
	TCNT0=0;

	/* set compare value */
	OCR0= (uint8)((255*duty_cycle)/100);

}

