/*
 * PWM_DRAWER_App.c
 *
 * Created: 4/1/2024 1:43:25 PM
 *  Author: Omar
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/WAVE_PATTERNS.h"

#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"

#include "../MCAL/TIMER0/TIMER0_Interface.h"
#include "../MCAL/TIMER1/TIMER1_Interface.h"

#include "../HAL/GLCD/GLCD_Interface.h"

#include "PWM_DRAWER_App.h"

#include <util/delay.h>
#include <avr/interrupt.h>

volatile uint16_t u16_init_val = 0;
volatile uint16_t u16_period_ticks = 0;
volatile uint16_t u16_on_ticks = 0;

volatile bool done = false;

ISR(TIMER1_CAPT_vect)
{
	static uint8_t loc_u16_counter = 0;
	
	loc_u16_counter++;
	
	if (loc_u16_counter == 1)
	{
		GIE_void_Disable();
		u16_init_val = TIMER1_u16_Get_ICR1();
		GIE_void_Enable();
	}
	else if(loc_u16_counter == 2)
	{
		GIE_void_Disable();
		u16_period_ticks = TIMER1_u16_Get_ICR1();
		GIE_void_Enable();
		
		TIMER1_void_ICU_Edge_Select(FALLING_EDGE);
	}
	else if(loc_u16_counter == 3)
	{
		GIE_void_Disable();
		u16_on_ticks = TIMER1_u16_Get_ICR1();
		//GIE_void_Enable();
		
		//TIMER1_void_ICU_Edge_Select(RISING_EDGE);
		//loc_u16_counter = 0;
		//TCNT1 = 0;
		
		done = true;
		
		TIMER0_void_Stop();
		TIMER1_void_Stop();
		
		
		u16_on_ticks = u16_on_ticks - u16_period_ticks;
		u16_period_ticks = u16_period_ticks - u16_init_val;
		
		
		//GIE_void_Disable();
	}
}

void PWM_DRAWER_Init()
{
	DIO_void_Set_Pin_Direction(PORTB_, 3, PIN_OUTPUT);
	DIO_void_Set_Pin_Direction(PORTD_, 6, PIN_INPUT);
	
	GLCD_void_Init();
	GLCD_void_Select_Page(PAGE_0);
	GLCD_void_Send_Command(DISPLAY_ON);
	
	TIMER0_void_Init(PRESCALE_256, FAST_PWM);
	TIMER0_void_Set_Compare_Output_Mode(FAST_PWM_NON_INVERTING);
	
	TIMER0_void_Set_Counter_Value(0);
	TIMER0_void_Set_Top_Value(127);
	
	TIMER1_void_Init(PRESCALE_256, NORMAL);
	TIMER1_void_ICU_Edge_Select(RISING_EDGE);
	
	SET_BIT(TIMSK, TICIE1);
	
	TIMER1_void_Set_Counter_Value(0);
	
	GIE_void_Enable();
}

void PWM_DRAWER_Draw()
{
	if(done)
	{
		GLCD_void_Select_Page(PAGE_0);
		GLCD_void_Set_Line(LINE_0);
		GLCD_void_Set_Cursor_Position(CURSOR_POSITION_0);
		GLCD_void_Display_String("Freq: ");
		GLCD_void_Display_Floating_Point(1 / ((u16_period_ticks) * ((float32_t) 256 / F_CPU)));
		
		GLCD_void_Select_Page(PAGE_0);
		GLCD_void_Set_Line(LINE_1);
		GLCD_void_Set_Cursor_Position(CURSOR_POSITION_0);
		GLCD_void_Display_String("TIME: ");
		GLCD_void_Display_Floating_Point((u16_period_ticks) * ((float32_t) 256 / F_CPU) * 1000);
		
		GLCD_void_Select_Page(PAGE_0);
		GLCD_void_Set_Line(LINE_2);
		GLCD_void_Set_Cursor_Position(CURSOR_POSITION_0);
		GLCD_void_Display_String("Duty: ");
		GLCD_void_Display_Floating_Point(((float32_t)(u16_on_ticks) / (u16_period_ticks)) * 100);
		GLCD_void_Display_String("%");
		
		
		GLCD_void_Set_Line(LINE_6);
		GLCD_void_Set_Cursor_Position(CURSOR_POSITION_0);
		
		for (int j = 0; j < MAX_WIDTH;)
		{
			if(j >= PAGE_WIDTH)
			{
				GLCD_void_Select_Page(PAGE_1);
				GLCD_void_Set_Line(LINE_6);
				GLCD_void_Set_Cursor_Position(CURSOR_POSITION_0);
			}
			
			GLCD_void_Display_Pattern(rising_edge_pattern);
			
			for (int i = 0; i < ((float32_t) u16_on_ticks / u16_period_ticks) * 60; i++)
			{
				GLCD_void_Display_Pattern(on_pattern);
				j++;
			}
			
			GLCD_void_Display_Pattern(falling_edge_pattern);
			
			for (int i = 0; i < 60 - (((float32_t) u16_on_ticks / u16_period_ticks) * 60); i++)
			{
				GLCD_void_Display_Pattern(off_pattern);
				j++;
			}
			
			j+=4;
		}
	}
}