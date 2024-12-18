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

	SET_Direction(PORT_C, PIN_7, OUTPUT);
	SET_Direction(PORT_D, PIN_0, INPUT);
	SET_Direction(PORT_D, PIN_1, OUTPUT);
	USART_Init();

	while(1){
		 if(USART_Receive()=='1'){
			 SET_Value(PORT_C, PIN_7, HIGH);
		 }
		 else if(USART_Receive()=='0'){
			 SET_Value(PORT_C, PIN_7, LOW);
		 }
	}
}
