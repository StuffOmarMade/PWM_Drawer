/*
 * TIMER1_Private.h
 *
 * Created: 3/11/2024 6:59:30 AM
 *  Author: Omar
 */ 

#define TCCR1A_REG	*((volatile uint8_t*) 0x4F)
#define TCCR1B_REG	*((volatile uint8_t*) 0x4E)

#define TCNT1H_REG	*((volatile uint8_t*) 0x4D)
#define TCNT1L_REG	*((volatile uint8_t*) 0x4C)

#define OCR1AH_REG	*((volatile uint8_t*) 0x4B)
#define OCR1AL_REG	*((volatile uint8_t*) 0x4A)

#define OCR1BH_REG	*((volatile uint8_t*) 0x49)
#define OCR1BL_REG	*((volatile uint8_t*) 0x48)

#define ICR1H_REG	*((volatile uint8_t*) 0x47)
#define ICR1L_REG	*((volatile uint8_t*) 0x46)

#define TIMSK_REG	*((volatile uint8_t*) 0x59)
#define TIFR_REG	*((volatile uint8_t*) 0x58)

#define DDRD_REG	*((volatile uint8_t*) 0x31)