/*
 * LCD.c
 *
 *
 *  Author: Zahraa Mohamed
 */ 
#include "DIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"

void LCD_INIT (void)
{
	_delay_ms(200);
	#if defined EIGHT_BIT
	{
		DIO_SET_PORT_DIR(LCD_PORT,OUTPUT);
		DIO_SET_PIN_DIR(RS_PORT,RS_PIN,OUTPUT);
		DIO_SET_PIN_DIR(E_PORT,E_PIN,OUTPUT);
		DIO_SET_PIN_DIR(RW_PORT,RW_PIN,OUTPUT);
		DIO_WRITE_PIN(RW_PORT,RW_PIN,0);
		LCD_SEND_CMD(LCD_8BIT_MODE);
		LCD_SEND_CMD(DISPLAY_ON_CURSOR_ON);
		LCD_CLR_SCREEN();
		LCD_SEND_CMD(ENTRY_MODE);
	}
	#else
	{

		DIO_SET_NIBBLE_DIR(LCD_PORT,LCD_FIRST_PIN,OUTPUT);
		DIO_SET_PIN_DIR(RS_PORT,RS_PIN,OUTPUT);
		DIO_SET_PIN_DIR(E_PORT,E_PIN,OUTPUT);
		DIO_SET_PIN_DIR(RW_PORT,RW_PIN,OUTPUT);
		DIO_WRITE_PIN(RW_PORT,RW_PIN,0);
		LCD_SEND_CMD(RETURN_HOME);
		_delay_ms(10);
		LCD_SEND_CMD(LCD_4BIT_MODE);
		LCD_SEND_CMD(DISPLAY_ON_CURSOR_ON);
		LCD_CLR_SCREEN();
		LCD_SEND_CMD(ENTRY_MODE);
	}
	#endif
	
	
}
void LCD_ENABLE(void)
{
	DIO_WRITE_PIN(E_PORT,E_PIN,1);   //rising edge
	_delay_ms(2);
	DIO_WRITE_PIN(E_PORT,E_PIN,0);   //falling edge
	_delay_ms(2);
}

void LCD_SEND_CHAR(char data)
{
	#if defined EIGHT_BIT
	{
		DIO_WRITE_PORT(LCD_PORT,data);
		DIO_WRITE_PIN(RS_PORT,RS_PIN,1);  // select the data register
		LCD_ENABLE();
	}
	#else
	{
		DIO_WRITE_NIBBLE(LCD_PORT,LCD_FIRST_PIN,data>>4);
		DIO_WRITE_PIN(RS_PORT,RS_PIN,1);  // select the data register
		LCD_ENABLE();
		DIO_WRITE_NIBBLE(LCD_PORT,LCD_FIRST_PIN,data);
		LCD_ENABLE();
	}
	#endif
	
}

void LCD_SEND_CMD(char CMD)
{
	#if defined EIGHT_BIT
	{
		DIO_WRITE_PORT(LCD_PORT,CMD);
		DIO_WRITE_PIN(RS_PORT,RS_PIN,0);  // select the command register
		LCD_ENABLE();
		_delay_ms(1);                     // delay time for execution
	}
	#else
	{
		DIO_WRITE_NIBBLE(LCD_PORT,LCD_FIRST_PIN,CMD>>4);
		DIO_WRITE_PIN(RS_PORT,RS_PIN,0);  // select the command register
		LCD_ENABLE();
		DIO_WRITE_NIBBLE(LCD_PORT,LCD_FIRST_PIN,CMD);
		LCD_ENABLE();
		_delay_ms(1);
	}
	#endif
}

void LCD_CLR_SCREEN(void)
{
	LCD_SEND_CMD(CLEAR_SCREEN);
	_delay_ms(10);
}

void LCD_SEND_STRING(const char*ptr)
{
	while(*ptr!=0)
	{
		LCD_SEND_CHAR(*ptr);
		ptr ++;
	}
}

void LCD_MOVE_CURSOR(char row, char column)
{
	if(row<1 || row>2 || column <1 || column>16)
	{
		LCD_SEND_CMD(0x80);
	}
	else if(row==1)
	{
		LCD_SEND_CMD(0x80+column-1);
	}
	else
	{
		LCD_SEND_CMD(0xc0+column-1);
	}
}