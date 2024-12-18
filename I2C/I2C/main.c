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
	SET_Direction(PORT_B, PIN_0, INPUT);
	SET_Value(PORT_B, PIN_0, HIGH);
	//because we have only one master
	I2C_InitMaster(0);
	I2C_SendStartCondition();
	I2C_Send_SlaveAddress_Write(0x20);
	while(1){
		if((GET_Value(PORT_B, PIN_0))== LOW){
			I2C_MasterSendData(1);
		}
		else if((GET_Value(PORT_B, PIN_0))== HIGH){
			I2C_MasterSendData(0);
		}
		_delay_ms(200);
		I2C_RepeatedStartCondition();
		I2C_Send_SlaveAddress_Write(0x20);

	}
}
