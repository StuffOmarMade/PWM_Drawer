/*
 * BIT_MATH.h
 *
 * Created: 2/29/2024 5:49:07 PM
 *  Author: Omar
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_
 
#define GET_BIT(REG, BIT)	((REG>>BIT) & 1)
#define SET_BIT(REG, BIT)	REG|=(1<<BIT)
#define CLR_BIT(REG, BIT)	REG&=~(1<<BIT)
#define TOG_BIT(REG, BIT)	REG^=(1<<BIT) 

#endif /* BIT_MATH_H_ */