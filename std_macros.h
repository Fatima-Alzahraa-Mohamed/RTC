/*
 * std_macros.h
 *
 *
 *  Author: Zahraa Mohamed
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define SET_BIT(reg,bit) (reg |= (1<<bit))
#define CLR_BIT(reg,bit) (reg &= ~(1<<bit))
#define TOG_BIT(reg,bit) (reg ^= (1<<bit))
#define READ_BIT(reg,bit) ((reg & (1u<<bit)) >> bit)
#define ROL(reg,number) ()


#define ON 1
#define OFF 0
#define OUTPUT 1
#define INPUT 0
#define ENABLE 1
#define DISABLE 0

#endif /* STD_MACROS_H_ */