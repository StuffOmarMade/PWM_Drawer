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

void TIMER0_Init(uint8_t copy_u8_clock_select, uint8_t copy_u8_waveform_generation_mode)
{
	uint8_t loc_port_value = copy_u8_clock_select | copy_u8_waveform_generation_mode;
	TCCR0_REG = loc_port_value;
}