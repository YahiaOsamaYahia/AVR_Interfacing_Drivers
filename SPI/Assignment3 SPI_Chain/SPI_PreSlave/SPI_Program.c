/*
 * SPI_Program.c
 *
 *  Created on: Dec 13, 2024
 *      Author: Yahia-PC
 */
#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "SPI_Interface.h"

void SPI_Init_Master(){
	//Set data order to LSB
	SET_BIT(SPCR, 5);

	//Leading edge rising clock polarity
	CLR_BIT(SPCR, 3);

	//sample at leading edge
	CLR_BIT(SPCR, 2);

	//64 pre-scaler
	CLR_BIT(SPSR, 0);
	SET_BIT(SPCR, 1);
	CLR_BIT(SPCR, 0);

	//Master mode
	SET_BIT(SPCR, 4);

	//Enable SPI
	SET_BIT(SPCR, 6);

}

void SPI_Init_Slave(){
	//Set data order to LSB
	SET_BIT(SPCR, 5);

	//Leading edge rising clock polarity
	CLR_BIT(SPCR, 3);

	//sample at leading edge
	CLR_BIT(SPCR, 2);

	//Slave mode
	CLR_BIT(SPCR, 4);

	//Enable SPI
	SET_BIT(SPCR, 6);
}

u8 SPI_SendData(u8 data){
	SPDR = data;
	while(!GET_BIT(SPSR, 7));
	return SPDR;
}

