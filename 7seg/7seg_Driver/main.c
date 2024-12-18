/*
 * main.c
 *
 *  Created on: Aug 19, 2024
 *      Author: Yahia-PC
 */

#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include<util/delay.h>
int main(){
	//SET_Direction(PORT_A, PIN_2, INPUT);
	SET_Direction_4LSB(PORT_C, OUTPUT);
	SET_Direction_4MSB(PORT_C, OUTPUT);
	//SET_Value(PORT_A, PIN_2, HIGH);
	u8 current_number1 = 0;
	u8 current_number2 = 0;
	while(1){

		//if (GET_Value(PORT_A, PIN_2)==LOW){
			if(current_number1 == 9){
				current_number1=0;
				if(current_number2==9){
								current_number2=0;
							}else{
				current_number2++;
							}
			}
			else{
				current_number1++;
			}

		//}
		SET_Value_4LSB(PORT_C, current_number1);
		SET_Value_4MSB(PORT_C, current_number2<<4);
	_delay_ms(100);
	}
}
