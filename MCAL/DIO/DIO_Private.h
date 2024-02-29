/*
 * DIO_Private.h
 *
 * Created: 2/29/2024 6:01:21 PM
 *  Author: Omar
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define PORTA_REG	*((volatile uint8_t*) 0x3B)
#define DDRA_REG	*((volatile uint8_t*) 0x3A)
#define	PINA_REG	*((volatile uint8_t*) 0x39)

#define PORTB_REG	*((volatile uint8_t*) 0x38)
#define DDRB_REG	*((volatile uint8_t*) 0x37)
#define	PINB_REG	*((volatile uint8_t*) 0x36)

#define PORTC_REG	*((volatile uint8_t*) 0x35)
#define DDRC_REG	*((volatile uint8_t*) 0x34)
#define	PINC_REG	*((volatile uint8_t*) 0x33)

#define PORTD_REG	*((volatile uint8_t*) 0x32)
#define DDRD_REG	*((volatile uint8_t*) 0x31)
#define	PIND_REG	*((volatile uint8_t*) 0x30)

#endif /* DIO_PRIVATE_H_ */