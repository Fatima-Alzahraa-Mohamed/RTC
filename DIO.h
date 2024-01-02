/*
 * DIO.h
 *
 *
 *  Author: Zahraa Mohamed
 */ 


#ifndef DIO_H_
#define DIO_H_

void DIO_SET_PIN_DIR(char PORT , char PIN_NO ,char DIR);
void DIO_WRITE_PIN(char PORT, char PIN_NO, char VALUE);
void DIO_TOG_PIN(char PORT, char PIN_NO);
char DIO_READ_PIN(char PORT , char PIN_NO);
void DIO_SET_PORT_DIR(char PORT,char DIR);
void DIO_WRITE_PORT(char PORT, char VALUE);
char DIO_READ_PORT(char PORT);
void DIO_TOG_PORT(char PORT);
void DIO_CONNECT_PULLUP(char PORT ,char PIN_NO,char CONNECT);
 void DIO_WRITE_NIBBLE(char PORT , char firtpin, char val);
 void DIO_SET_NIBBLE_DIR(char PORT,char firstpin, char DIR);


#include <avr/io.h>
#include "std_macros.h"

#endif /* DIO_H_ */