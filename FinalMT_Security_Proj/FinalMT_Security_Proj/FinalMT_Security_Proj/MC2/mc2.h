/*
 * mc2.h
 *
 *  Created on: Nov 1, 2023
 *      Author: Lenovo
 */

#ifndef MC2_H_
#define MC2_H_

#include "std_types.h"
/******************************************************************************************
 *                                  Function prototype                                    *
 *****************************************************************************************/
void Timer1_Inc(void);

void Door_wait(uint8 time);

void Open_door(void);


void Read_Password(uint8 *PW);

void Save_Password(const uint8 *PW);

uint8 Check_Password(uint8 *p1,uint8 *p2);

void Wrong_Password(void);


#endif /* MC2_H_ */
