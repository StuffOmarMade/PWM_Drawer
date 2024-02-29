/*
 * DIO_Interface.c
 *
 * Created: 2/29/2024 6:01:05 PM
 *  Author: Omar
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"

uint8_t DIO_u8_Get_Pin_Value(uint8_t copy_u8_port, uint8_t copy_u8_pin)
{
	uint8_t loc_u8_pin_value = 0x00;
	
	switch (copy_u8_port)
	{
		case PORTA_:
			loc_u8_pin_value = GET_BIT(PINA_REG, copy_u8_pin);	
		break;
		
		case PORTB_:
			loc_u8_pin_value = GET_BIT(PINB_REG, copy_u8_pin);
		break;
		
		case PORTC_:
			loc_u8_pin_value = GET_BIT(PINC_REG, copy_u8_pin);
		break;
		
		case PORTD_:
			loc_u8_pin_value = GET_BIT(PIND_REG, copy_u8_pin);
		break;
	}
	
	return loc_u8_pin_value;
}

void	DIO_void_Set_Pin_Direction(uint8_t copy_u8_port, uint8_t copy_u8_pin, uint8_t copy_u8_pin_direction) 
{
	if (copy_u8_pin_direction == PIN_OUTPUT)
	{
		switch(copy_u8_port)
		{
			case PORTA_: SET_BIT(DDRA_REG, copy_u8_pin); break;
			case PORTB_: SET_BIT(DDRB_REG, copy_u8_pin); break;
			case PORTC_: SET_BIT(DDRC_REG, copy_u8_pin); break;
			case PORTD_: SET_BIT(DDRD_REG, copy_u8_pin); break;
		}
	}
	else if(copy_u8_pin_direction == PIN_INPUT)
	{
		switch(copy_u8_port)
		{
			case PORTA_: CLR_BIT(DDRA_REG, copy_u8_pin); break;
			case PORTB_: CLR_BIT(DDRB_REG, copy_u8_pin); break;
			case PORTC_: CLR_BIT(DDRC_REG, copy_u8_pin); break;
			case PORTD_: CLR_BIT(DDRD_REG, copy_u8_pin); break;
		}
	}
}

void	DIO_void_Set_Pin_Value(uint8_t copy_u8_port, uint8_t copy_u8_pin, uint8_t copy_u8_pin_value)
{
	if (copy_u8_pin_value == PIN_HIGH)
	{
		switch(copy_u8_port)
		{
			case PORTA_: SET_BIT(PORTA_REG, copy_u8_pin); break;
			case PORTB_: SET_BIT(PORTB_REG, copy_u8_pin); break;
			case PORTC_: SET_BIT(PORTC_REG, copy_u8_pin); break;
			case PORTD_: SET_BIT(PORTD_REG, copy_u8_pin); break;
		}
	}
	else if(copy_u8_pin_value == PIN_LOW)
	{
		switch(copy_u8_port)
		{
			case PORTA_: CLR_BIT(PORTA_REG, copy_u8_pin); break;
			case PORTB_: CLR_BIT(PORTB_REG, copy_u8_pin); break;
			case PORTC_: CLR_BIT(PORTC_REG, copy_u8_pin); break;
			case PORTD_: CLR_BIT(PORTD_REG, copy_u8_pin); break;
		}
	}
}

void	DIO_void_Tog_Pin_Value(uint8_t copy_u8_port, uint8_t copy_u8_pin)
{
	switch(copy_u8_port)
	{
		case PORTA_: TOG_BIT(PORTA_REG, copy_u8_pin); break;
		case PORTB_: TOG_BIT(PORTB_REG, copy_u8_pin); break;
		case PORTC_: TOG_BIT(PORTC_REG, copy_u8_pin); break;
		case PORTD_: TOG_BIT(PORTD_REG, copy_u8_pin); break;
	}
}

uint8_t DIO_u8_Get_Port_Value(uint8_t copy_u8_port)
{
	uint8_t loc_u8_port_value = 0x00;
	
	switch(copy_u8_port)
	{
		case PORTA_:
			loc_u8_port_value = PINA_REG;
		break;
		
		case PORTB_:
			loc_u8_port_value = PINB_REG;
		break;
		
		case PORTC_:
			loc_u8_port_value = PINC_REG;
		break;
		
		case PORTD_:
			loc_u8_port_value = PIND_REG;
		break;
	}
	
	return loc_u8_port_value;
}

void	DIO_void_Set_Port_Direction(uint8_t copy_u8_port, uint8_t copy_u8_port_direction)
{
	switch(copy_u8_port)
	{
		case PORTA_:
			DDRA_REG = copy_u8_port_direction;
		break;
		
		case PORTB_:
			DDRB_REG = copy_u8_port_direction;
		break;
		
		case PORTC_:
			DDRC_REG = copy_u8_port_direction;
		break;
		
		case PORTD_:
			DDRD_REG = copy_u8_port_direction;
		break;
	}
}
	
void	DIO_void_Set_Port_Value(uint8_t copy_u8_port, uint8_t copy_u8_port_value)
{
	switch(copy_u8_port)
	{
		case PORTA_:
			PORTA_REG = copy_u8_port_value;
		break;
		
		case PORTB_:
			PORTB_REG = copy_u8_port_value;
		break;
		
		case PORTC_:
			PORTC_REG = copy_u8_port_value;
		break;
		
		case PORTD_:
			PORTD_REG = copy_u8_port_value;
		break;
	}
}

void	DIO_void_Tog_Port_Value(uint8_t copy_u8_port)
{
	switch(copy_u8_port)
	{
		case PORTA_:
		PORTA_REG = ~(PORTA_REG);
		break;
		
		case PORTB_:
		PORTB_REG = ~(PORTB_REG);
		break;
		
		case PORTC_:
		PORTC_REG = ~(PORTC_REG);
		break;
		
		case PORTD_:
		PORTD_REG = ~(PORTD_REG);
		break;
	}
}