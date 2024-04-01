/*
 * TIMER1_Interface.c
 *
 * Created: 3/11/2024 6:59:18 AM
 *  Author: Omar
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER1_Private.h"
#include "TIMER1_Interface.h"

void TIMER1_void_Init(uint8_t copy_u8_clock_select, uint8_t copy_u8_mode)
{
	TCCR1A_REG = 0x00;
	TCCR1B_REG = 0x00;
	TCCR1B_REG |= ((copy_u8_mode >> 0b10) << WGM12_b) | copy_u8_clock_select;
	TCCR1A_REG |= (copy_u8_mode & 0b0011);
}

void TIMER1_void_Force_Output_Compare(uint8_t copy_u8_compare_unit)
{
	switch(copy_u8_compare_unit)
	{
		case NONE:
			TCCR1A_REG |= (0b00 << FOC1B_b);
		case COMPARE_UNIT_A:
			SET_BIT(TCCR1A_REG, FOC1A_b);
		break;
		
		case COMPARE_UNIT_B:
			SET_BIT(TCCR1A_REG, FOC1B_b);
		break;
		
		case BOTH_COMPARE_UNITS:
			TCCR1A_REG |= (0b11 << FOC1B_b);
		break;	
	}
	
}

void TIMER1_void_Noise_Canceler_Enable()
{
	SET_BIT(TCCR1B_REG, ICNC1_b);
}

void TIMER1_void_Noise_Canceler_Disable()
{
	CLR_BIT(TCCR1B_REG, ICNC1_b);
}

void TIMER1_void_ICU_Edge_Select(uint8_t copy_u8_edge)
{
	switch(copy_u8_edge)
	{
		case RISING_EDGE:
			SET_BIT(TCCR1B_REG, ICES1_b);
		break;
		
		case FALLING_EDGE:
			CLR_BIT(TCCR1B_REG, ICES1_b);
		break;
	}
}

void TIMER1_void_Set_Counter_Value(uint16_t copy_u16_value)
{
	TCNT1H_REG = copy_u16_value >> 8;
	TCNT1L_REG = copy_u16_value;
}

uint16_t TIMER1_u16_Get_ICR1()
{
	uint16_t loc_u16_value = ICR1L_REG;
	return loc_u16_value |= ICR1H_REG << 8;
}

void TIMER1_void_Stop()
{
	TCCR1B_REG &= 0b11111000;
}