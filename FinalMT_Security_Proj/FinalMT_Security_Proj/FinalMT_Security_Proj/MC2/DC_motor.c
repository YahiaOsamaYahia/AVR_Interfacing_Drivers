/*
 * DC_motor.c
 *
 *  Created on: Nov 5, 2023
 *      Author: Lenovo
 */


#include "gpio.h"
#include "PWM.h"
#include "DC_motor.h"
void DcMotor_Init(void)
{
GPIO_setupPinDirection(PORTB_ID, PIN0_ID,PIN_OUTPUT);
GPIO_setupPinDirection(PORTB_ID, PIN1_ID,PIN_OUTPUT);
/* Motor Pins direction output */
GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
/* Motor is stop at the beginning */

}
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	PWM_Timer0_Start((uint8)((float32)(speed*255)/100));

	if(state == CW)
{
	/* Motor rotate clockwise*/
	GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_HIGH);
}

	else if(state == A_CW)
	{
		/* Motor rotate counter clockwise*/
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_HIGH);
	}

	else if(state == STOP)
	{
		GPIO_writePin(PORTB_ID, PIN1_ID, LOGIC_LOW);
		GPIO_writePin(PORTB_ID, PIN0_ID, LOGIC_LOW);
	}


}
