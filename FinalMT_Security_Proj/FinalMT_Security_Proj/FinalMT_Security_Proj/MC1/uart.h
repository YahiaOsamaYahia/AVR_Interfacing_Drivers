 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Description: Header file for the UART AVR driver
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "std_types.h"
/******************************************************************************
 *                     Types Declaration                                      *
 *****************************************************************************/
typedef enum {
	five_bits,six_bits,seven_bits,eight_bits,nine_bits=7
}UART_Bit_Size;
typedef enum {
	disable,even=2,odd
}UART_Parity;
typedef enum {
	one_bit,two_bits
}UART_StopBit;
typedef enum {
	 baud_2400 =2400,baud_4800=4800,baud_9600=9600
}UART_BaudRate;

typedef enum {
	asynch,synch
}UART_Mode;
typedef enum {
	off,on
}UART_DoubletransRate;
typedef struct {
	UART_Bit_Size Bit_size;
	UART_Parity Parity;
	UART_StopBit StopBit;
	UART_BaudRate BaudRate;
	UART_Mode mode;
	UART_DoubletransRate transRate;
}UART_ConfigType;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 */
void UART_init( UART_ConfigType *Config_ptr);

/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const uint8 data);

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8 UART_recieveByte(void);

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8 *Str);

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(uint8 *Str); // Receive until #

#endif /* UART_H_ */
