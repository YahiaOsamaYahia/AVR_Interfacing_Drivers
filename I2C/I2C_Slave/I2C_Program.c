/*
 * I2C_Program.c
 *
 *  Created on: Dec 16, 2024
 *      Author: Yahia-PC
 */
#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "I2C_Interface.h"

void I2C_InitMaster(u8 masterAddress){
	if(masterAddress !=0 ){
		TWAR = masterAddress<<1;
	}
	else{
		//Enable Ack bit
		SET_BIT(TWCR, 6);

		//Enable I2C
		SET_BIT(TWCR, 2);

		//Set the pre-scaler to 64
		CLR_BIT(TWSR, 1);
		CLR_BIT(TWSR, 0);

		TWBR = 3;
	}

}

void I2C_InitSlave(u8 slaveAddress){

	TWAR = slaveAddress<<1;

	//Enable Ack bit
	SET_BIT(TWCR, 6);

	//Enable I2C
	SET_BIT(TWCR, 2);
}

ERRORS I2C_SendStartCondition(){

	ERRORS err = NO_ERROR;

	//Setting start condition bit
	SET_BIT(TWCR, 5);

	//Setting interrupt flag
	SET_BIT(TWCR, 7);
	while(!GET_BIT(TWCR, 7 ));

	//check the error
	if((TWSR&0b11111000)!=0x08)
		err= START_ERROR;
	else {}
	return err;
}

ERRORS I2C_RepeatedStartCondition(){

	ERRORS err = NO_ERROR;

	//Setting start condition bit
	SET_BIT(TWCR, 5);

	//Setting interrupt flag
	SET_BIT(TWCR, 7);
	while(!GET_BIT(TWCR, 7 ));

	//check the error
	if((TWSR&0b11111000)!=0x10)
		err= REPEATED_START_ERROR;
	else {}
	return err;
}

ERRORS I2C_Send_SlaveAddress_Write(u8 slaveAddress){

	ERRORS err = NO_ERROR;

	//Address of slave
	TWDR = slaveAddress<<1;

	//setting it to write
	CLR_BIT(TWDR, 0);

	CLR_BIT(TWCR,5);
	//Setting interrupt flag
	SET_BIT(TWCR, 7);
	while(!GET_BIT(TWCR, 7 ));

	//check the error
	if((TWSR&0b11111000)!=0x18)
		err= SLAVE_ADDRESS_WRITE_ERROR;
	else {}
	return err;
}

ERRORS I2C_Send_SlaveAddress_Read(u8 slaveAddress){

	ERRORS err = NO_ERROR;

	//Address of slave
	TWDR = slaveAddress<<1;

	//setting it to write
	SET_BIT(TWDR, 0);
	CLR_BIT(TWCR,5);
	//Setting interrupt flag
	SET_BIT(TWCR, 7);
	while(!GET_BIT(TWCR, 7 ));

	//check the error
	if((TWSR&0b11111000)!=0x40)
		err= SLAVE_ADDRESS_READ_ERROR;
	else {}
	return err;
}

ERRORS I2C_MasterSendData(u8 data){

	ERRORS err = NO_ERROR;

	TWDR = data;
	//Setting interrupt flag
	SET_BIT(TWCR, 7);
	while(!GET_BIT(TWCR, 7 ));

	//check the error
	if((TWSR&0b11111000)!=0x28)
		err= MASTER_SEND_ERROR;
	else {}
	return err;
}

ERRORS I2C_MasterReceiveData(u8 *data){
	ERRORS err = NO_ERROR;


	//Setting interrupt flag
	SET_BIT(TWCR, 7);
	while(!GET_BIT(TWCR, 7));

	//check the error
	if((TWSR&0b11111000)!=0x50)
		err= MASTER_RECEIVE_ERRORS;
	else {
		*data=TWDR;
	}
	return err;
}

void I2C_SlaveRead_AddressMatch(){

	while((TWSR&0b11111000)!=0x60){
		//Setting interrupt flag
		SET_BIT(TWCR, 7);
		while(!GET_BIT(TWCR, 7));
	}
}

u8 I2C_SlaveRead(){
	u8 data;
	SET_BIT(TWCR, 7);
	while(!GET_BIT(TWCR, 7));
	if((TWSR&0b11111000)!=0x80){

	}
	else {
		data = TWDR;
	}
	return data;
}

void I2C_SlaveWrite_AddressMatch(){
	while((TWSR&0b11111000)!=0xA8){
		//Setting interrupt flag
		SET_BIT(TWCR, 7);
		while(!GET_BIT(TWCR, 7));
	}
}

void I2C_SlaveWite(u8 data){
	TWDR = data;
	SET_BIT(TWCR,7);
	while(!GET_BIT(TWCR,7));
	while((TWSR&0b11111000)!=0xC0);
}

void I2C_SetStopCondition(){
	SET_BIT(TWCR, 4);
	SET_BIT(TWCR, 7);
}



