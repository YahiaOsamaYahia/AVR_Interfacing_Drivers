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

	SET_Direction(PORT_B, PIN_5, INPUT);
	SET_Direction(PORT_B, PIN_6, OUTPUT);
	SET_Direction(PORT_B, PIN_4, INPUT);
	SET_Direction(PORT_B, PIN_7, INPUT);
	//SET_Value(PORT_B, PIN_0, HIGH);
	//SET_Value(PORT_B, PIN_4, LOW);
	SPI_Init_Slave();


		while(1){
				SPI_SendData(SPDR);
			}

}
