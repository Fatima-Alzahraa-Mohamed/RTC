/*
 * seven_seg.c
 *
 *
 *  Author: Zahraa Mohamed
 */ 
 #include "seven_seg.h"
 
 void SEVEN_SEG_INIT(char PORT)
 {
	 DIO_SET_PORT_DIR(PORT,0xff);
 }
 
 void SEVEN_SEG_WRITE (char PORT , char num)
 {
	 #if defined CC
		char arr[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	 #else
		char arr[] = {~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x07,~0x7f,~0x6f};
	 #endif
	 DIO_WRITE_PORT(PORT,arr[num]);
 }
 
 void SEVEN_SEG_BCD_INIT(char PORT, char firstpin)
 {
	 DIO_SET_PIN_DIR(PORT,firstpin,OUTPUT);
	 DIO_SET_PIN_DIR(PORT,firstpin+1,OUTPUT);
	 DIO_SET_PIN_DIR(PORT,firstpin+2,OUTPUT);
	 DIO_SET_PIN_DIR(PORT,firstpin+3,OUTPUT);
 }
 
 void SEVEN_SEG_BCD_WRITE_NIBBLE(char PORT , char firstpin , char val)
 {
	 DIO_WRITE_NIBBLE(PORT,firstpin,val);
 }
 
 void SEVEN_SEG_MUX_INIT(char EN_PORT, char EN_PIN)
 {
	 char i ;
	 for (i = EN_PIN ;i<SEV_MUX_NO;i++)
	 {
		 DIO_SET_PIN_DIR(EN_PORT,i,OUTPUT);
	 }
 }
 void SEVEN_SEG_MUX_ENABLE(char EN_PORT,char EN_PIN)
 {
	 char i ;
	 for(i=0;i<SEV_MUX_NO;i++)
	 {
		 DIO_WRITE_PIN(EN_PORT,i,1);
	 }
	 DIO_WRITE_PIN(EN_PORT,EN_PIN,0);
 }
 