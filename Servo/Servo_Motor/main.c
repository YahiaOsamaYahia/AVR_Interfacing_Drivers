/*
 * main.c
 *
 *  Created on: Dec 6, 2024
 *      Author: Yahia-PC
 */

#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "Servo_Interface.h"
#include <util/delay.h>

int main(){
	SET_Direction(PORT_D, PIN_5, OUTPUT);
	SET_TOP_Value(20000);
	SET_OCR_Value(1500);
	Timer1_Init();
	_delay_ms(2000);
	SET_OCR_Value(1000);
	_delay_ms(2000);
	SET_OCR_Value(2000);
	_delay_ms(2000);
	SET_OCR_Value(1500);

	while(1){

	}
	return 0;
}

