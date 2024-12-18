/*
 * SPI_Interface.h
 *
 *  Created on: Dec 13, 2024
 *      Author: Yahia-PC
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define SPCR *((volatile u8*)0x2D)
#define SPSR *((volatile u8*)0x2E)
#define SPDR *((volatile u8*)0x2F)

void SPI_Init_Master();
void SPI_Init_Slave();
u8 SPI_SendData(u8 data);

#endif /* SPI_INTERFACE_H_ */
