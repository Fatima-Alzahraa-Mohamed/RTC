/*
 * LCD.h
 *
 *
 *  Author: Zahraa Mohamed
 */ 


#ifndef LCD_H_
#define LCD_H_
// LCD COMMANDS
#define CLEAR_SCREEN 0x01
#define RETURN_HOME 0x02
#define SHIFT_CURSOR_LEFT 0x04
#define SHIFT_DISPLAY_RIGHT 0x05
#define ENTRY_MODE 0x06
#define SHIFT_DISPLAY_LEFT 0x07
#define DISPLAY_ON_CURSOR_ON 0x0E
#define DISPLAY_ON_CURSOR_OFF 0x0C
#define LCD_8BIT_MODE 0x38
#define LCD_4BIT_MODE 0x28


#define LCD_PORT 'A'
#define LCD_FIRST_PIN 4
#define RS_PORT 'A'
#define RS_PIN 0
#define RW_PORT 'A'
#define RW_PIN 1
#define E_PORT 'A'
#define E_PIN 2

//#define EIGHT_BIT

void LCD_INIT (void);
void LCD_ENABLE(void);
void LCD_SEND_CHAR(char data);
void LCD_SEND_CMD(char CMD);
void LCD_CLR_SCREEN(void);
void LCD_SEND_STRING(const char*ptr);
void LCD_MOVE_CURSOR(char row, char column);

#endif /* LCD_H_ */