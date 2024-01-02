/*
 * KEYPAD.h
 *
 *
 *  Author: Zahraa Mohamed
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "DIO.h"
void KEYPAD_INIT(void);
unsigned char KEYPAD_READ(void);

#define NOTPRESSED  0xff
#define KEYPAD_PORT 'D'
#define OUTPIN0 0
#define OUTPIN1 1
#define OUTPIN2 2
#define OUTPIN3 3
#define INPIN0 4
#define INPIN1 5
#define INPIN2 6
#define INPIN3 7
#endif
