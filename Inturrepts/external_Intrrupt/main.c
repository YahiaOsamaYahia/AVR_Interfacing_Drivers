/*
 * main.c
 *
 *  Created on: Nov 12, 2024
 *      Author: Yahia-PC
 */

#include"BIT_OP.h"
#include "STD_TYPES.h"
#include "GIE_Interface.h"
#include "EXTI_Interface.h"
#include "DIO_Interface.h"
#include <util/delay.h>
int main(){
	SET_Direction(PORT_D, PIN_2, INPUT);
	SET_Direction(PORT_C, PIN_7, OUTPUT);
	SET_Value(PORT_D, PIN_2, HIGH);
	EXTI_Enable(0);
	Inturrept_Enable();
	u8 flag = 0;
	while(1){
		if (flag ==0){
			SET_Value(PORT_C, PIN_7, HIGH);
			flag =1;
		}
		else if(flag ==1){
			SET_Value(PORT_C, PIN_7, LOW);
			flag = 0;
		}
		_delay_ms(50);
	}
}

void __vector_1(void) __attribute__ ((signal));
void __vector_1(void){
	SET_Value(PORT_C, PIN_7, HIGH);
	_delay_ms(200);
}

