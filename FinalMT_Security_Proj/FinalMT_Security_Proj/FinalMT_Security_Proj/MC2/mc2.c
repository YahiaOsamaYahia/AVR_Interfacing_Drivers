/*
 * mc2.c
 *
 *  Created on: Nov 1, 2023
 *      Author: Lenovo
 */

#include "mc2.h"
#include "BUZZER.h"
#include "external_eeprom.h"
#include "dc_motor.h"
#include "TIMER1.h"
#include "twi.h"
#include "gpio.h"
#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>
#include "common_macros.h"
#include <avr/interrupt.h>
#define START_ADDRESS 0x0311
#define PASSWORD_SIZE 5
#define MAX_WRONG_ENTITIES 3
#define compare_value 31250
/**********************************************************************************************************
 *                                   Global variables                                                     *
 *********************************************************************************************************/
uint8 g_sec=0;
uint8 g_flag=0;
/**********************************************************************************************************
 *                                   Function body                                                        *
 *********************************************************************************************************/
/*
 * Description : function to increment timer
 */
void Timer1_Inc(void){
	g_sec++;
}
/*
 * Description : function to perform wait operation
 */
void Door_wait(uint8 time){
	g_sec=0;
	if (g_sec < time){
		/* wait */
	}
}
/*
 * Description : function to check that the password in MC1 matches the password in MC2
 */
uint8 Check_Password(uint8* p1,uint8* p2){
	/* return 0 in case of don't match */
    /* return 1 in case of matching */
	uint8 i=0;
	for(i=0 ; i < PASSWORD_SIZE ; i++){
		if(p1[i] != p2[i]){ /* the two passwords don't match */
			UART_sendByte(FALSE);
			return 0;
		}
	}
	UART_sendByte(TRUE); /* the two passwords are matching */
	return 1;
}
/*
 * Description : Function to save the password in EEPROM
 */
void Save_Password(const uint8* PW){
	uint8 i=0;
	for(i=0 ; i < PASSWORD_SIZE ; i++){
        EEPROM_writeByte(START_ADDRESS + i,PW[i]);
        _delay_us(10);
	}
}
/*
 * Description : Function to read the password from EEPROM
 */
void Read_Password(uint8 *PW){
	uint8 i;
	for(i=0 ; i < PASSWORD_SIZE ; i++){
	    EEPROM_readByte(START_ADDRESS+i, &PW[i]);
	        _delay_us(10);
		}
}
/*
 * Description : function that take the input password from the user
 */
void Input_Password(uint8* PW){
	uint8 i=0;
	while(i < PASSWORD_SIZE + 1){
		PW[i]=UART_recieveByte();
		if(PW[i] == '='){
			break;
		}
		_delay_us(1);
		i++;
	}
}
/*
 * Description : function to control DC-Motor to open the door
 */
void Open_door(void){
	 UART_sendByte(0);
	 DcMotor_Rotate(CW,100);
	 Door_wait(15);
	 DcMotor_Rotate(STOP,0);
	 Door_wait(3);
	 DcMotor_Rotate(A_CW,100);
	 Door_wait(15);
	 DcMotor_Rotate(STOP,0);
}
int main(){
	uint8 password_1[PASSWORD_SIZE + 1]; /* two arrays to save the two passwords in it */
	uint8 password_2[PASSWORD_SIZE + 1];
	uint8 key=0,flag=0;
	SREG |= (1<<7); /* to enable the interrupts */
	UART_ConfigType UART_Config ={eight_bits,disable,one_bit,baud_9600,asynch,on}; /* initialize UART driver*/
    UART_init(&UART_Config);
	DcMotor_Init(); /* initialize DC-Motor driver */
	Buzzer_init();  /* initialize BUZZER driver */
    Timer1_ConfigType Timer_Config = {compare,0,compare_value,clk_256}; /* initialize Timer driver*/
    Timer1_init(&Timer_Config);
    Timer1_setCallBack(Timer1_Inc);
    while(1){
    	if(g_flag == 0){ /* password not written */
    		Input_Password(password_1); /* the user enter the first password */
    		Input_Password(password_2); /* the user enter the second password */
    		g_flag=Check_Password(password_1,password_2);
    		if(g_flag){
    			Save_Password(password_1); /* if the password matches save the password in EEPROM */
    		}
    	}
    	else if (g_flag){
    		key=UART_recieveByte();
    		switch (key){
    		/* case '+' : open the door
    		 * case '-' : change password
    		 */
    		case '+':
    			flag=0;
        		Input_Password(password_1); /* the user enter the first password */
        		Read_Password(password_2); /* read the password from the EEPROM  */
        		flag=Check_Password(password_1,password_2);
        		UART_sendByte(flag);
        		if(flag){
        			Open_door();
        		}
        		else if ( UART_recieveByte() == MAX_WRONG_ENTITIES){
        			Buzzer_on();
        			Door_wait(60);
        			Buzzer_off();
        		}
        		break; /* end this case */
    		case '-':
    			g_flag=0;
    			break;
    		}
    	}
    }
    return 0;
}
