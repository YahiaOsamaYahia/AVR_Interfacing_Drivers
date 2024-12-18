/*
 * DC_motor.h
 *
 *  Created on: Nov 5, 2023
 *      Author: Lenovo
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

typedef enum
{
	CW,
	A_CW,
	STOP
}DcMotor_State;


void DcMotor_Init(void);


void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */
