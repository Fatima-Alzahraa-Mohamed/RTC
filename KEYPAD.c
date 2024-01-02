/*
 * KEYPAD.c
 *
 *
 *  Author: Zahraa Mohamed
 */ 
#include "KEYPAD.h"

void KEYPAD_INIT(void)
{
	DIO_SET_NIBBLE_DIR(KEYPAD_PORT,OUTPIN0,OUTPUT);
	DIO_SET_NIBBLE_DIR(KEYPAD_PORT,INPIN0,INPUT);
	
	DIO_CONNECT_PULLUP(KEYPAD_PORT,INPIN0,ENABLE);
	DIO_CONNECT_PULLUP(KEYPAD_PORT,INPIN1,ENABLE);
	DIO_CONNECT_PULLUP(KEYPAD_PORT,INPIN2,ENABLE);
	DIO_CONNECT_PULLUP(KEYPAD_PORT,INPIN3,ENABLE);
}



unsigned char KEYPAD_READ(void)
{
	unsigned char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'}};
	unsigned char row,column;
	unsigned char returnval= NOTPRESSED;
	
	for(row=0;row<4;row++)
	{
		DIO_WRITE_PIN(KEYPAD_PORT,OUTPIN0,1);
		DIO_WRITE_PIN(KEYPAD_PORT,OUTPIN1,1);
		DIO_WRITE_PIN(KEYPAD_PORT,OUTPIN2,1);
		DIO_WRITE_PIN(KEYPAD_PORT,OUTPIN3,1);
		DIO_WRITE_PIN(KEYPAD_PORT,row+OUTPIN0,0);
		for(column=0;column<4;column++)
		{
			if (DIO_READ_PIN(KEYPAD_PORT,column+INPIN0)==0)  //button pressed
			{
				returnval = arr[row][column];
				break;
			}
		}
		if (returnval!= NOTPRESSED)
		{
			break;
		}
	}
	return returnval ;
}
