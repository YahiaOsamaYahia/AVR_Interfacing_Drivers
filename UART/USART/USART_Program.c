/*
 * USART_Program.c
 *
 *  Created on: Dec 12, 2024
 *      Author: Yahia-PC
 */

#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "USART_Interface.h"

void USART_Init(){
	u8 temp = 0;

	//Selection bit set to UCSRC
	SET_BIT(temp, 7);

	//working with Asynchronous operation
	CLR_BIT(temp, 6);

	//Disable Party
	CLR_BIT(temp, 5);
	CLR_BIT(temp, 4);

	//1-bit Stop bits
	CLR_BIT(temp, 3);

	//8-bit mode
	SET_BIT(temp, 2);
	SET_BIT(temp, 1);

	UCSRA = temp;

	//Enable Receiver and transmitter
	SET_BIT(UCSRB, 3);
	SET_BIT(UCSRB, 4);

	//SET for 8-bit mode
	CLR_BIT(UCSRB, 2);

	//Setting baud Rate from table
	UBRRL = 51;

}

void USART_Send(u8 Data){
	while(!GET_BIT(UCSRA, 5));
		UDR = Data;

}

u8 USART_Receive(){
	while(!GET_BIT(UCSRA, 7));
		return UDR;

}
