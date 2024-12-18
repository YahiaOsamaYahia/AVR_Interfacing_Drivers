/*
 * PWM.h
 *
 *  Created on: Nov 1, 2023
 *      Author: Lenovo
 */

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"
/************************************************************************
 *                        function prototype
 ***********************************************************************/
/*
 * Description :
 * Start the timer: Generate a PWM signal with frequency 500Hz
 * 500 = 1Mhz/(256*N) N = 8
 * Pre-scaler will be F_CPU_8
 * Duty cycle value will be updated in the compare register
 */

void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
