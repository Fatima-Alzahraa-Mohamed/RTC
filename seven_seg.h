/*
 * seven_seg.h
 *
 *
 *  Author: Zahraa Mohamed
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

void SEVEN_SEG_INIT(char PORT);
void SEVEN_SEG_WRITE (char PORT , char num);
void SEVEN_SEG_BCD_INIT(char PORT, char firstpin);
void SEVEN_SEG_BCD_WRITE_NIBBLE(char PORT , char firstpin, char val );
void SEVEN_SEG_MUX_ENABLE(char EN_PORT,char EN_PIN);
void SEVEN_SEG_MUX_INIT(char EN_PORT, char EN_PIN);

#include <avr/io.h>
#include "DIO.h"
#include "std_macros.h"
#define CC
#define SEV_MUX_NO 6



#endif /* SEVEN_SEG_H_ */