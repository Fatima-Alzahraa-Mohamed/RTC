/*
 * DIO.c
 *
 *
 *  Author: Zahraa Mohamed
 */ 
#include "DIO.h"


 void DIO_SET_PIN_DIR(char PORT , char PIN_NO ,char DIR)
 {
	 switch(PORT)
	 {
		 case'A':
		 case'a':
		 {
			 if(DIR)
			 {
				 SET_BIT(DDRA,PIN_NO);
			 }
			 else
			 {
				 CLR_BIT(DDRA,PIN_NO);
			 }
		 }
		 break;
		 
		 case'B':
		 case'b':
		 {
			 if(DIR)
			 {
				 SET_BIT(DDRB,PIN_NO);
			 }
			 else
			 {
				 CLR_BIT(DDRB,PIN_NO);
			 }
		 }
		 break;
		 
		 case'C':
		 case'c':
		 {
			 if(DIR)
			 {
				 SET_BIT(DDRC,PIN_NO);
			 }
			 else
			 {
				 CLR_BIT(DDRC,PIN_NO);
			 }
		 }
		 break;
		 
		 case'D':
		 case'd':
		 {
			 if(DIR)
			 {
				 SET_BIT(DDRD,PIN_NO);
			 }
			 else
			 {
				 CLR_BIT(DDRD,PIN_NO);
			 }
		 }
		 break;
	 }
 }
 
  void DIO_WRITE_PIN(char PORT, char PIN_NO, char VALUE)
  {
	  switch (PORT)
	  {
		  case 'A':
		  case 'a':
		  {
			  if (VALUE)
			  {
				  SET_BIT(PORTA,PIN_NO);
			  }
			  else
			  {
				  CLR_BIT(PORTA,PIN_NO);
			  }
		  }
		  break;
		  
		  case 'B':
		  case 'b':
		  {
			  if (VALUE)
			  {
				  SET_BIT(PORTB,PIN_NO);
			  }
			  else
			  {
				  CLR_BIT(PORTB,PIN_NO);
			  }
		  }
		  break;
	  
	  case 'C':
	  case 'c':
	  {
		  if (VALUE)
		  {
			  SET_BIT(PORTC,PIN_NO);
		  }
		  else
		  {
			  CLR_BIT(PORTC,PIN_NO);
		  }
	  }
	  break;
	  
	  case 'D':
	  case 'd':
	  {
		  if (VALUE)
		  {
			  SET_BIT(PORTD,PIN_NO);
		  }
		  else
		  {
			  CLR_BIT(PORTD,PIN_NO);
		  }
	  }
	  break;
	  }	  
  }
  
  void DIO_TOG_PIN(char PORT, char PIN_NO)
  {
	  switch(PORT)
	  {
		  case 'A':
		  case 'a':
		  TOG_BIT(PORTA,PIN_NO);
		  break;
		  
		  case 'B':
		  case 'b':
		  TOG_BIT(PORTB,PIN_NO);
		  break;
		  
		  case 'C':
		  case 'c':
		  TOG_BIT(PORTC,PIN_NO);
		  break;
		  
		  case 'D':
		  case 'd':
		  TOG_BIT(PORTD,PIN_NO);
		  break;
	  }
  }
  
  char DIO_READ_PIN(char PORT , char PIN_NO)
  {
	  unsigned char retval;
	  switch(PORT)
	  {
		  case 'A':
		  case 'a':
		  retval = READ_BIT(PINA,PIN_NO);
		  break;
		  
		  case 'B':
		  case 'b':
		  retval = READ_BIT(PINB,PIN_NO);
		  break;
		  
		  case 'C':
		  case 'c':
		  retval = READ_BIT(PINC,PIN_NO);
		  break;
		  
		  case 'D':
		  case 'd':
		  retval = READ_BIT(PIND,PIN_NO);
		  break;
	  }
	  return retval;
	  
  }
  
  void DIO_SET_PORT_DIR(char PORT,char DIR)
  {
	  switch(PORT)
	  {
		  case 'A':
		  case 'a':
		  DDRA = DIR;
		  break;
		  
		  case 'B':
		  case 'b':
		  DDRB = DIR;
		  break;
		  
		  case 'C':
		  case 'c':
		  DDRC = DIR;
		  break;
		  
		  case 'D':
		  case 'd':
		  DDRD = DIR;
		  break;
	  }
  }
  
  void DIO_WRITE_PORT(char PORT, char VALUE)
  {
	  switch(PORT)
	  {
		  case 'A':
		  case 'a':
		  PORTA = VALUE;
		  break;
		  
		  case 'B':
		  case 'b':
		  PORTB = VALUE;
		  break;
		  
		  case 'C':
		  case 'c':
		  PORTC = VALUE;
		  break;
		  
		  case 'D':
		  case 'd':
		  PORTD = VALUE;
		  break;
	  }
  }
  
  char DIO_READ_PORT(char PORT)
  {
	  char retval;
	  switch(PORT)
	  {
		  case 'A':
		  case 'a':
		  retval = PORTA;
		  break;
		  
		  case 'B':
		  case 'b':
		  retval = PORTB;
		  break;
		  
		  case 'C':
		  case 'c':
		  retval = PORTC;
		  break;
		  
		  case 'D':
		  case 'd':
		  retval = PORTD;
		  break;
	  }
	  return retval ;
  }
  
  void DIO_TOG_PORT(char PORT)
  {
	  switch(PORT)
	  {
		  case 'A':
		  case 'a':
		  PORTA ^= 0xff;
		  break;
		  
		  case 'B':
		  case 'b':
		  PORTB ^= 0xff;
		  break;
		  
		  case 'C':
		  case 'c':
		  PORTC ^= 0xff;
		  break;
		  
		  case 'D':
		  case 'd':
		  PORTD ^= 0xff;
		  break;
	  }
  }
  
  void DIO_CONNECT_PULLUP(char PORT ,char PIN_NO,char CONNECT)
  {
	  DIO_WRITE_PIN(PORT,PIN_NO,CONNECT);
  }
  
  void DIO_WRITE_NIBBLE(char PORT , char firstpin, char val)
  {
	  DIO_WRITE_PIN(PORT,firstpin,  READ_BIT(val,0) );
	  DIO_WRITE_PIN(PORT,firstpin+1,READ_BIT(val,1) );
	  DIO_WRITE_PIN(PORT,firstpin+2,READ_BIT(val,2) );
	  DIO_WRITE_PIN(PORT,firstpin+3,READ_BIT(val,3) );
  }
  
  void DIO_SET_NIBBLE_DIR(char PORT,char firstpin, char DIR)
  {
	  DIO_SET_PIN_DIR(PORT,firstpin,DIR);
	  DIO_SET_PIN_DIR(PORT,firstpin+1,DIR);
	  DIO_SET_PIN_DIR(PORT,firstpin+2,DIR);
	  DIO_SET_PIN_DIR(PORT,firstpin+3,DIR);
  }