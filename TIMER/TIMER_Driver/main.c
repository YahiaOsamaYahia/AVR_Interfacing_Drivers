	/*
	 * main.c
	 *
	 *  Created on: Dec 3, 2024
	 *      Author: Yahia-PC
	 */
	#include "BIT_OP.h"
	#include "STD_TYPES.h"
	#include "DIO_Interface.h"
	#include "TIMER_Interface.h"
	#include <util/delay.h>

	int main(){
		SET_Direction(PORT_C, PIN_0, OUTPUT );
		Timer_Mode();
		u16 overflow = 0;
		u8 b=1;
		SET_Value(PORT_C, PIN_0, b);

		while(1){
			overflow = Reset_Overflow(overflow);
			if (overflow >= 2000) {        // If overflow count reaches 122
				overflow = 0;             // Reset overflow counter
				Preload(135);             // Preload timer with initial value
				SET_Value(PORT_C, PIN_0, !b);
				b=!b;
			}
			/*
			SET_Value(PORT_C, PIN_0, HIGH);
			_delay_ms(2000);
			SET_Value(PORT_C, PIN_0, LOW);
			_delay_ms(2000);*/


		}

	}
