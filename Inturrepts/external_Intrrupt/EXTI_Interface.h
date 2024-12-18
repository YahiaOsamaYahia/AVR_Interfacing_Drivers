/*
 * EXTI_Interface.h
 *
 *  Created on: Nov 12, 2024
 *      Author: Yahia-PC
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
#define LOW_Level 0
#define Any_Logical_Change 1
#define FALLING_EDGE 2
#define RISING_EDGE 3
#define Sense_Control LOW_Level

#define MCUCR *((volatile u8*)0x55)
#define GICR *((volatile u8*)0x5B)
void EXTI_Enable(u8 INT_NUM );

#endif /* EXTI_INTERFACE_H_ */
