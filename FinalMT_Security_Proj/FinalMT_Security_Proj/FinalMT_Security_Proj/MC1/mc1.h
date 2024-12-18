/*
 * mc1.h
 *
 *  Created on: Nov 7, 2023
 *      Author: Lenovo
 */

#ifndef MC1_H_
#define MC1_H_


#include "std_types.h"

/***********************************************************************************
 *                                Function prototypes
 ***********************************************************************************/

 /* Description :
  *  let the user enter the password
  */
void Enter_password(void);


/* Description :
 * send the password to MC2
 */
void Send_password(void);

/* Description :
 *  check on the password if it matches to the password in EEPROM or not
 */
uint8 Check_password(void);


/* Description :
 * when you enter a wrong password
 */
void Wrong_password(void);


/* Description :
 *  to increment the seconds
 */
void Timer1_Inc(void);

/* Description :
 * wait for the required time
 */
void Timer1_wait(uint8 time);


/* Description :
 * to open the door
 */
void OPEN_door(void);


#endif /* MC1_H_ */
