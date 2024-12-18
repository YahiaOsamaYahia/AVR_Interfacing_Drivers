/*
 * TIMER_Interface.h
 *
 *  Created on: Dec 3, 2024
 *      Author: Yahia-PC
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

#define TCCR0 *((volatile u8*)0x53)
#define TIMSK *((volatile u8*)0x59)
#define TCNT0 *((volatile u8*)0x52)
#define TIFR *((volatile u8*)0x58)

void Timer_Mode();
void Enable_Timer_mask();
void Preload(u8 value);
u16 Reset_Overflow(u16 overflow);



#endif /* TIMER_INTERFACE_H_ */
