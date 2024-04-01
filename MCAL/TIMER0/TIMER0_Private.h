/*
 * TIMER0_Private.h
 *
 * Created: 2/29/2024 7:42:20 PM
 *  Author: Omar
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0_REG	*((volatile uint8_t*) 0x53)
#define TCNT0_REG	*((volatile uint8_t*) 0x52)
#define OCR0_REG	*((volatile uint8_t*) 0x5C)
#define TIMSK_REG	*((volatile uint8_t*) 0x59)

#endif /* TIMER0_PRIVATE_H_ */