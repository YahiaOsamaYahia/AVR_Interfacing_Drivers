/*
 * mc1.c
 *
 *  Created on: Nov 1, 2023
 *      Author: Lenovo
 */

#include "mc1.h"
#include "lcd.h"
#include "keypad.h"
#include "common_macros.h"
#include "TIMER1.h"
#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


/**********************************************************************************
 * 									Macros
 **********************************************************************************/
#define MAX_WRONG_ENTITIES 		3
#define compare_value 			31250


/************************************************************************************
 *                                 Global variables                                 *
 ***********************************************************************************/
uint8 g_flag=0;
volatile uint8 g_sec=0;
uint8 password[6]={0};
uint8 repass[6]={0};

/************************************************************************************
 *                                Function Prototypes                                     *
 ***********************************************************************************/

/*
 *  Description : let the user enter the password
 */
void Enter_password(void)
{
	LCD_clearScreen();
	LCD_moveCursor(0,0);
	LCD_displayString(" Enter pass: ");
	LCD_moveCursor(1,0);
	Send_password();
	if(!g_flag)
	{ /* password not entered */
		LCD_clearScreen();
		LCD_moveCursor(0,0);
		LCD_displayString(" Re-enter pass: ");
		LCD_moveCursor(1,0);
		Send_password();
	}
}
/*
 * Description : send the password to MC2
 */

void Send_password(void)
{
	uint8 key=0;
	while(1)
	{
		key=KEYPAD_getPressedKey();
		_delay_ms(300);
		if(key == '=')
		{ /* enter is pressed*/
			UART_sendByte(key);
			break;
		}
		else if ((key >= 0) && (key <= 9))
		{
			LCD_displayCharacter('*');
			UART_sendByte(key);
		}
	}
}
/*
 * Description : check on the password if it matches to the password in EEPROM or not
 */
uint8 Check_password(void){
	uint8 byte=0;
	byte = UART_recieveByte();
	return byte;
}
/*
 * Description :  Description : when you enter a wrong password
 */
void Wrong_password(void){
	LCD_clearScreen();
	LCD_moveCursor(0,0);
	LCD_displayString("WRONG PASSWORD!");
	UART_sendByte(MAX_WRONG_ENTITIES);
	Timer1_wait(60);
}
/*
 * Description : to open the door
 */
void OPEN_door(void){
	LCD_clearScreen();
	LCD_moveCursor(0,0);
	while(UART_recieveByte() != 0){/* wait until control ecu */}
	LCD_displayString("Door is Unlocking");
	Timer1_wait(15);
	LCD_clearScreen();
	Timer1_wait(3);
	LCD_clearScreen();
	LCD_displayString("Door is locking");
	Timer1_wait(15);
	LCD_clearScreen();
}
/*
 * Description :Increment the timer
 */
void Timer1_Inc(void){
	g_sec++;
}
/*
 * Description :wait for the required time
 */
void Timer1_wait(uint8 time){
	g_sec=0;
	if (g_sec < time){
		/* wait */
	}
}

int main(void)
{
	uint8 key, false_count=0 , check_flag=0;
	/* Enable the global interrupts*/
	SREG |= (1<<7);

	LCD_init();
	 /* initialize UART driver*/
	UART_ConfigType UART_Config ={eight_bits,disable,one_bit,baud_9600,asynch,on};
	UART_init(&UART_Config);
	/* initialize Timer driver*/
	Timer1_ConfigType Timer_Config = {compare,0,compare_value,clk_256};
	Timer1_init(&Timer_Config);
	Timer1_setCallBack(Timer1_Inc);

	while(1)
	{
		if( g_flag == 0 )
		{ /* password not set */
			Enter_password();
			/* check the password matched or not */
			g_flag=Check_password();
		}
		else if (g_flag == 1 )
		{ /* password is set*/
			LCD_clearScreen();
			LCD_moveCursor(0,0);
			LCD_displayString("+ : open Door");
			LCD_moveCursor(1,0);
			LCD_displayString("- : change pass ");
			key = KEYPAD_getPressedKey();
			_delay_ms(300);
			switch(key)
			{
			case '+': /* open the door */
				check_flag=0;
				while(check_flag == 0)
				{
					/*send the + to MC2 */
					UART_sendByte(key);
					Enter_password();
					check_flag=Check_password();
					if(check_flag == 1)
					{
						OPEN_door();
					}
					else
					{
						false_count++;
						/* send a wrong password */
						UART_sendByte(false_count);
						if (false_count == MAX_WRONG_ENTITIES)
						{
							Wrong_password();
							break;
						}
					}
				}
				break;

				/* change password */
			case '-':
				/* send - to MC2 */
				UART_sendByte(key);
				/*password is not set */
				g_flag=0;
				break;
			}
		}
	}
	return 0;
}
