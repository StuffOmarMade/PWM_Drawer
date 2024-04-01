/*
 * TIMER0_Interface.c
 *
 * Created: 2/29/2024 7:41:48 PM
 *  Author: Omar
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER0_Private.h"
#include "TIMER0_Interface.h"

void TIMER0_void_Init(uint8_t copy_u8_clock_select, uint8_t copy_u8_mode)
{
	uint8_t loc_port_value = copy_u8_clock_select | copy_u8_mode;
	TCCR0_REG = loc_port_value;
}

void TIMER0_void_Set_Compare_Output_Mode(uint8_t copy_u8_compare_output_mode)
{
	TCCR0_REG |= (copy_u8_compare_output_mode<<COM00_b);
}

void TIMER0_void_Force_Output_Compare()
{
	SET_BIT(TCCR0_REG, FOC0_b);
}

void TIMER0_void_Interrupt_Enable(uint8_t copy_u8_interrupt)
{
	switch(copy_u8_interrupt)
	{
		case TIMER0_OUTPUT_COMPARE_MATCH_INTERRUPT:
			SET_BIT(TIMSK_REG, OCIE0_b);
		break;
		case TIMER0_OVERFLOW_INTERRUPT:
			SET_BIT(TIMSK_REG, TOIE0_b);
		break;	
	}
}

void TIMER0_void_Interrupt_Disable(uint8_t copy_u8_interrupt)
{
	switch(copy_u8_interrupt)
	{
		case TIMER0_OUTPUT_COMPARE_MATCH_INTERRUPT:
		CLR_BIT(TIMSK_REG, OCIE0_b);
		break;
		case TIMER0_OVERFLOW_INTERRUPT:
		CLR_BIT(TIMSK_REG, TOIE0_b);
		break;		
	}
}

void TIMER0_void_Set_Counter_Value(uint8_t copy_u8_value)
{
	TCNT0_REG = copy_u8_value;
}

void TIMER0_void_Set_Top_Value(uint8_t copy_u8_value)
{
	OCR0_REG = copy_u8_value;	
}

void TIMER0_void_Stop()
{
	TCCR0_REG &= 0b11111000;
}