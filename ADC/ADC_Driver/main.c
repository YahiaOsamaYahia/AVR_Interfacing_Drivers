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
#include "ADC_Interface.h"
#include <util/delay.h>

int main(){
	SET_Direction(PORT_C, PIN_0, OUTPUT );
	SET_Direction(PORT_C, PIN_1, OUTPUT );
	SET_Direction(PORT_C, PIN_2, OUTPUT );
	SET_Direction_4MSB(PORT_C, OUTPUT);
	SET_Direction(PORT_A, PIN_0, INPUT);
	LCD_Init();
	ADC_Init();
	u16 Digital;
	u16 Analog=0;
	u16 prevAnalog=0;
	//LCD_String("Yahia");
	//LCD_SendNumbers(2000);
	while(1){
		ADC_Start(0);
		Digital = ADC_Result();
		Analog = Analog_Value(Digital);
		if(Analog != prevAnalog){
			LCD_SendCommands(Display_Clear>>4);
			LCD_SendCommands(Display_Clear);
			LCD_SendNumbers(Analog);
			prevAnalog = Analog;
		}
		else{

		}
		_delay_ms(500);
	}
}


