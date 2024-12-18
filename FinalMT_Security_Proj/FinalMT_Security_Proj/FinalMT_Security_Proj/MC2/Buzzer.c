/*
 * Buzzer.c
 *
 *  Created on: Nov 2, 2023
 *      Author: Lenovo
 */


#include "Buzzer.h"
#include "GPIO.h"

void Buzzer_init(void)
{
	GPIO_setupPinDirection(PORTD_ID, PIN7_ID, PIN_OUTPUT);
	GPIO_writePin(PORTD_ID, PIN7_ID, LOGIC_LOW);
}


void Buzzer_on(void)
{
	GPIO_writePin(PORTD_ID, PIN7_ID, LOGIC_HIGH);

}


void Buzzer_off(void)
{
	GPIO_writePin(PORTD_ID, PIN7_ID, LOGIC_LOW);
}
