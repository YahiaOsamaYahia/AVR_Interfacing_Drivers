/*
 * Servo_Program.c
 *
 *  Created on: Dec 6, 2024
 *      Author: Yahia-PC
 */
#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "Servo_Interface.h"


void Timer1_Init(){

	//Fast PWM ICR1 top
	CLR_BIT(TCCR1A, 0);
	SET_BIT(TCCR1A, 1);
	SET_BIT(TCCR1B, 3);
	SET_BIT(TCCR1B, 4);

	//Non-inverting Mode
	SET_BIT(TCCR1A, 7);
	CLR_BIT(TCCR1A, 6);

	//Set pre-scaler to 8
	CLR_BIT(TCCR1B, 0);
	SET_BIT(TCCR1B, 1);
	CLR_BIT(TCCR1B, 2);
}

void SET_TOP_Value(u16 TOP_Value){
	ICR1 = TOP_Value;
}

void SET_OCR_Value(u16 ORC_Value){
	OCR1 = ORC_Value;
}
