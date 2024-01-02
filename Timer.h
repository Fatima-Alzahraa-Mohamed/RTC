/*
 * Timer.h
 *
 *
 *  Author: Zahraa Mohamed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include "DIO.h"
#include "std_macros.h"
#include "avr\interrupt.h"

void TIMER0_CTC_INIT_INTERRUPT( void);
void TIMER0_WAVE_NON_PWM(void);
void TIMER0_WAVE_FAST_PWM (void);
void TIMER0_WAVE_PHASECORRECT_PWM(void);
void TIMER2_OVERFLOW_INIT_INTERRUPT(void);

#endif /* TIMER_H_ */