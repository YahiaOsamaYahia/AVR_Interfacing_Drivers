/*
 * I2C_Interface.h
 *
 *  Created on: Dec 16, 2024
 *      Author: Yahia-PC
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#define TWBR *((volatile u8*)0x20)
#define TWCR *((volatile u8*)0x56)
#define TWSR *((volatile u8*)0x21)
#define TWAR *((volatile u8*)0x22)
#define TWDR *((volatile u8*)0x23)

typedef enum{
	NO_ERROR,
	START_ERROR,
	REPEATED_START_ERROR,
	SLAVE_ADDRESS_WRITE_ERROR,
	SLAVE_ADDRESS_READ_ERROR,
	MASTER_SEND_ERROR,
	MASTER_RECEIVE_ERRORS
}ERRORS;

void I2C_InitMaster(u8 masterAdress);
void I2C_InitSlave(u8 slaveAddress);
ERRORS I2C_SendStartCondition();
ERRORS I2C_RepeatedStartCondition();
ERRORS I2C_Send_SlaveAddress_Write(u8 slaveAddress);
ERRORS I2C_Send_SlaveAddress_Read(u8 slaveAddress);
ERRORS I2C_MasterSendData(u8 data);
ERRORS I2C_MasterReceiveData(u8 *data);
void I2C_SlaveRead_AddressMatch();
u8 I2C_SlaveRead();
void I2C_SlaveWrite_AddressMatch();
void  I2C_SlaveWite(u8 data);
void I2C_SetStopCondition();

#endif /* I2C_INTERFACE_H_ */
