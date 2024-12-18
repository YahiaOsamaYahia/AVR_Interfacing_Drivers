/*
 * USART_Interface.h
 *
 *  Created on: Dec 12, 2024
 *      Author: Yahia-PC
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#define UCSRA *((volatile u8*)0x2B)
#define UCSRB *((volatile u8*)0x2A)
#define UCSRC *((volatile u8*)0x40)
#define UBRRL *((volatile u8*)0x29)
#define UDR *((volatile u8*)0x2C)

void USART_Init();
void USART_Send(u8 Data);
u8 USART_Receive();
#endif /* USART_INTERFACE_H_ */
