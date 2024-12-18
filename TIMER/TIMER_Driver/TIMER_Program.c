/*
 * TIMER_Program.h
 *
 *  Created on: Dec 3, 2024
 *      Author: Yahia-PC
 */

#include "BIT_OP.h"
#include "STD_TYPES.h"
#include "TIMER_Interface.h"

void Timer_Mode(){
	//CTC mode
	SET_BIT(TCCR0, 3);
	CLR_BIT(TCCR0, 6);

	//Toggle OC0 on Compare Match
	CLR_BIT(TCCR0, 5);
	SET_BIT(TCCR0, 4);

	//Pre-scaler set to 256
	SET_BIT(TCCR0, 2);
	CLR_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 0);

	//irrelevant to CTC
	CLR_BIT(TCCR0, 7);
}

void Enable_Timer_mask(){
	SET_BIT(TIMSK, 0);
}

void Preload(u8 value){
	TCNT0 = value;
}

u16 Reset_Overflow(u16 overflow){
	if (GET_BIT(TIFR, 0)) {
		overflow++;                   // Increment overflow counter
		SET_BIT(TIFR, 0);
	}
	return overflow;
}


