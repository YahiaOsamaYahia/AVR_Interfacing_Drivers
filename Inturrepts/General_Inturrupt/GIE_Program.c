/*
 * GIE_Program.c
 *
 *  Created on: Nov 17, 2024
 *      Author: Yahia-PC
 */
#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "GIE_Interface.h"
void Inturrept_Enable(){
	SET_BIT(SREG, 7);
}
