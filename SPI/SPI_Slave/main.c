/*
 * main.c
 *
 *  Created on: Dec 13, 2024
 *      Author: Yahia-PC
 */
#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "SPI_Interface.h"

int main(){
	SET_Direction(PORT_C, PIN_7, OUTPUT);
	SET_Direction(PORT_B, PIN_5, INPUT);
	SET_Direction(PORT_B, PIN_6, OUTPUT);
	SET_Direction(PORT_B, PIN_4, INPUT);
	SET_Direction(PORT_B, PIN_7, INPUT);
	SET_Value(PORT_C, PIN_7, LOW);
	SPI_Init_Slave();

	while(1){
		if(SPI_SendData('1')=='1'){
			SET_Value(PORT_C, PIN_7, HIGH);
		}
		else if(SPI_SendData('0')=='0'){
			SET_Value(PORT_C, PIN_7, LOW);
		}
	}
}
