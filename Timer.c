/*
 * Timer.c
 *
 *
 *  Author: Zahraa Mohamed
 */ 
#include "Timer.h"

void TIMER0_CTC_INIT_INTERRUPT( void)
{
	// clock prescaler selection >>> 1024
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	// mode selection  >>> CTC
	SET_BIT(TCCR0,WGM01);  
	//load 64 in OCR0
	OCR0 = 64;
	// interrupt enable
	sei();
	SET_BIT(TIMSK,OCIE0);
}

void TIMER0_WAVE_NON_PWM(void)
{
	// clock prescaler selection >>> 1024
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	// mode selection >>> CTC
	SET_BIT(TCCR0,WGM01);
	//load 64 in OCR0
	OCR0 = 64;
	// set OC0 as output pin
	DIO_SET_PIN_DIR('B',3,OUTPUT);
	// compare output mode >> toggle OC0 at compare match
	SET_BIT(TCCR0,COM00);
	
}

void TIMER0_WAVE_FAST_PWM (void)
{
	// clock prescaler selection >>> 1024
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	// mode selection >>> fast PWM
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	// load 64 in OCR0
	OCR0 = 64;
	// set OC0 as output pin
	DIO_SET_PIN_DIR('B',3,OUTPUT);
	// compare output mode >>> set OC0 on compare match & clear OC0 at BOTTOM
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01); 
}

void TIMER0_WAVE_PHASECORRECT_PWM(void)
{
	// clock prescaler selection >>> 1024
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	//mode selection >>> phase correct PWM
	SET_BIT(TCCR0,WGM00);
	//load 64 in OCR0
	OCR0 = 64;
	// set OC0 as output pin
	DIO_SET_PIN_DIR('B',3,OUTPUT);
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	
}

void TIMER2_OVERFLOW_INIT_INTERRUPT(void)
{
	// clock selection
	SET_BIT(ASSR,AS2);
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	//mode selection >>> default (normal mode)
	// enable interrupt
	sei();
	SET_BIT(TIMSK,TOIE2);
	
}