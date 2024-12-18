/*
 * main.c
 *
 *  Created on: Nov 27, 2024
 *      Author: Yahia-PC
 */
#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include <util/delay.h>

int main(){
	SET_Direction(PORT_C, PIN_0, OUTPUT );
	SET_Direction(PORT_C, PIN_1, OUTPUT );
	SET_Direction(PORT_C, PIN_2, OUTPUT );
	SET_Direction_4MSB(PORT_C, OUTPUT);
	LCD_Init();

	LCD_String("Yahia");
	LCD_SendNumbers(2000);

	while(1){

	}
}

