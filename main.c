/*
 * main.c
 *
 *
 *  Author: Zahraa Mohamed
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "KEYPAD.h"
#include "seven_seg.h"
#include "Timer.h"
#include <avr/interrupt.h>

volatile unsigned char seconds_counter=0 ;
unsigned char minutes_counter=0;
unsigned char hours_counter = 0;
unsigned char UNITS_DIGIT,TENS_DIGIT,keypad_press;

int main(void)
{
	LCD_INIT();
	KEYPAD_INIT();
	SEVEN_SEG_INIT('B');
	SEVEN_SEG_MUX_INIT('C',0);
	TIMER2_OVERFLOW_INIT_INTERRUPT();
	LCD_SEND_STRING("Press 1 to");
	LCD_MOVE_CURSOR(2,1);
	LCD_SEND_STRING("set the clock");
    while(1)
    {
        keypad_press = KEYPAD_READ();
		if (keypad_press!=NOTPRESSED)
		{
			if (keypad_press=='1')
			{
				LCD_CLR_SCREEN();
				LCD_SEND_STRING("Hours=__");
				LCD_MOVE_CURSOR(1,7);
				_delay_ms(250);
				do 
				{
					TENS_DIGIT=KEYPAD_READ();
				} while (TENS_DIGIT==NOTPRESSED);
				
				LCD_SEND_CHAR(TENS_DIGIT);
				_delay_ms(250);
				
				do 
				{
					UNITS_DIGIT=KEYPAD_READ();
				} while (UNITS_DIGIT==NOTPRESSED);
				
				LCD_SEND_CHAR(UNITS_DIGIT);
				_delay_ms(250);
				hours_counter= 10*(TENS_DIGIT-48)+(UNITS_DIGIT-48);
				
				LCD_CLR_SCREEN();
				LCD_SEND_STRING("Minutes=__");
				LCD_MOVE_CURSOR(1,9);
				
				do
				{
					TENS_DIGIT=KEYPAD_READ();
				} while (TENS_DIGIT==NOTPRESSED);
				
				LCD_SEND_CHAR(TENS_DIGIT);
				_delay_ms(250);
				
				do
				{
					UNITS_DIGIT=KEYPAD_READ();
				} while (UNITS_DIGIT==NOTPRESSED);
				
				LCD_SEND_CHAR(UNITS_DIGIT);
				_delay_ms(250);
				minutes_counter= 10*(TENS_DIGIT-48)+(UNITS_DIGIT-48);
				
				LCD_CLR_SCREEN();
				LCD_SEND_STRING("Seconds=__");
				LCD_MOVE_CURSOR(1,9);
				
				do
				{
					TENS_DIGIT=KEYPAD_READ();
				} while (TENS_DIGIT==NOTPRESSED);
				
				LCD_SEND_CHAR(TENS_DIGIT);
				_delay_ms(250);
				
				do
				{
					UNITS_DIGIT=KEYPAD_READ();
				} while (UNITS_DIGIT==NOTPRESSED);
				
				LCD_SEND_CHAR(UNITS_DIGIT);
				_delay_ms(300);
				seconds_counter= 10*(TENS_DIGIT-48)+(UNITS_DIGIT-48);
				
				LCD_CLR_SCREEN();
				LCD_SEND_STRING("Press 1 to");
				LCD_MOVE_CURSOR(2,1);
				LCD_SEND_STRING("set the clock");
				
			} 
			else
			{
				LCD_CLR_SCREEN();
				LCD_SEND_STRING("Wrong Choice!");
				_delay_ms(1000);
				LCD_CLR_SCREEN();
				LCD_SEND_STRING("Press 1 to");
				LCD_MOVE_CURSOR(2,1);
				LCD_SEND_STRING("set the clock");
			}
		}
		
		SEVEN_SEG_MUX_ENABLE('C',0);
		SEVEN_SEG_WRITE('B',seconds_counter%10);
		_delay_ms(5);
		
		SEVEN_SEG_MUX_ENABLE('C',1);
		SEVEN_SEG_WRITE('B',seconds_counter/10);
		_delay_ms(5);
		
		SEVEN_SEG_MUX_ENABLE('C',2);
		SEVEN_SEG_WRITE('B',minutes_counter%10);
		_delay_ms(5);
		 
		 SEVEN_SEG_MUX_ENABLE('C',3);
		 SEVEN_SEG_WRITE('B',minutes_counter/10);
		 _delay_ms(5);
		 
		 SEVEN_SEG_MUX_ENABLE('C',4);
		 SEVEN_SEG_WRITE('B',hours_counter%10);
		 _delay_ms(5);
		 
		 SEVEN_SEG_MUX_ENABLE('C',5);
		 SEVEN_SEG_WRITE('B',hours_counter/10);
		 _delay_ms(5);
		 
		 if (seconds_counter==60)
		 {
			 seconds_counter=0;
			 minutes_counter++;
		 }
		 if (minutes_counter==60)
		 {
			 minutes_counter=0;
			 hours_counter++;
		 }
		 if (hours_counter==24)
		 {
			 hours_counter=0;
		 }
    }
}

ISR(TIMER2_OVF_vect)
{
	seconds_counter++;
}