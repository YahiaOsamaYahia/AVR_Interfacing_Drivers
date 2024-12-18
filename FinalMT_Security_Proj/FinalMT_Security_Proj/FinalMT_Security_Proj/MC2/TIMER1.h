/*
 * TIMER1.h
 *
 *  Created on: Nov 7, 2023
 *      Author: Lenovo
 */

#ifndef TIMER1_H_
#define TIMER1_H_

#include "std_types.h"
/*********************************************************************************
                              Types Declaration  *
 ********************************************************************************/
typedef enum
{
	normal,
	compare
}Timer1_Mode;


typedef enum
{
	no_clk,
	no_prescaler,
	clk_8,
	clk_64,
	clk_256,
	clk_1024,
	falling_edge,
	rising_edge
}Timer1_Prescaler;


typedef struct
{
	Timer1_Mode mode;
	uint16 initial_value;
	uint16 compare_value;
	Timer1_Prescaler prescaler;
}Timer1_ConfigType;


/*******************************************************************************
                               Function prototype*
 ******************************************************************************/
/*
 * Description:
 * Function to initialize the Timer driver
 */
void Timer1_init(const Timer1_ConfigType * Config_Ptr);


/*
 * Description:
 * Function to disable the Timer1.
 */
void Timer1_deInit(void);


/*
 * Description:
 * Function to set the Call Back function address
 */
void Timer1_setCallBack(void(*a_ptr)(void));


#endif /* TIMER1_H_ */
