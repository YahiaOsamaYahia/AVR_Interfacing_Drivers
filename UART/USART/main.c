/*
 * main.c
 *
 *  Created on: Dec 12, 2024
 *      Author: Yahia-PC
 */

#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "USART_Interface.h"

int main(){
	SET_Direction(PORT_B, PIN_0, INPUT);
	SET_Value(PORT_B, PIN_0, HIGH);
	SET_Direction(PORT_D, PIN_0, INPUT);
	SET_Direction(PORT_D, PIN_1, OUTPUT);
	USART_Init();

	while(1){
		 if(!GET_Value(PORT_B, PIN_0)){
			 USART_Send('1');
		 }
		 else if(GET_Value(PORT_B, PIN_0)){
			 USART_Send('0');
		 }
	}
}
