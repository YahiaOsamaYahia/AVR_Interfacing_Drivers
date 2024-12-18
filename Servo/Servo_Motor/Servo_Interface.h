/*
 * Servo_Interface.h
 *
 *  Created on: Dec 6, 2024
 *      Author: Yahia-PC
 */

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

#define TCCR1A *((volatile u8*)0x4f)
#define TCCR1B *((volatile u8*)0x4E)
#define ICR1 *((volatile u16*)0x46)
#define OCR1 *((volatile u16*)0x4A)

void Timer1_Init();
void SET_TOP_Value(u16 TOP_Value);
void SET_OCR_Value(u16 ORC_Value);

#endif /* SERVO_INTERFACE_H_ */
