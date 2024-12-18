/*
 * main.c
 *
 *  Created on: Dec 16, 2024
 *      Author: Yahia-PC
 */

#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "I2C_Interface.h"
#include "DIO_Interface.h"
#include <util/delay.h>
int main (){
	SET_Direction(PORT_C, PIN_7, HIGH);
	//SET_Value(PORT_C, PIN_7, LOW);
	//because we have only one master
	I2C_InitSlave(0x20);
	u8 data;
	while(1){
		I2C_SlaveRead_AddressMatch();
		data = I2C_SlaveRead();
		if(data == 1 ){
			SET_Value(PORT_C, PIN_7, HIGH);
		}
		else if (data==0){
			SET_Value(PORT_C, PIN_7, LOW);
		}
	}
}
