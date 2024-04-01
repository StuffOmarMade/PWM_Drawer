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
#include "PWM_DRAWER_App_Config.h"

#include <avr/interrupt.h>

volatile uint16_t u16_init_val = 0;
volatile uint16_t u16_period_ticks = 0;
volatile uint16_t u16_on_ticks = 0;

uint16_t loc_u16_prescaler = 1;

bool done = false;

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
	void_Handle_Prescaler();
	
	DIO_void_Set_Pin_Direction(PORTB_, OC0_PIN, PIN_OUTPUT);
	DIO_void_Set_Pin_Direction(PORTD_, ICP1_PIN, PIN_INPUT);
	
	GLCD_void_Init();
	GLCD_void_Select_Page(PAGE_0);
	GLCD_void_Send_Command(DISPLAY_ON);
	
	TIMER0_void_Init(config.prescaler, config.mode);
	TIMER0_void_Set_Compare_Output_Mode(config.compare_output_mode);
	
	TIMER0_void_Set_Counter_Value(0);
	TIMER0_void_Set_Top_Value(180);
	
	TIMER1_void_Init(config.prescaler, NORMAL);
	TIMER1_void_ICU_Edge_Select(RISING_EDGE);
	
	TIMER1_void_Interrupt_Enable(TIMER1_INPUT_CAPTURE_INTERRUPT);
	
	TIMER1_void_Set_Counter_Value(0);
	
	GIE_void_Enable();
}

void PWM_DRAWER_Draw()
{
	if(done)
	{
		float32_t loc_f32_pulse_width_ratio = ((float32_t) u16_on_ticks / u16_period_ticks);
		
		float32_t loc_f32_frequency = 1 / ((u16_period_ticks) * ((float32_t) loc_u16_prescaler / F_CPU));
		float32_t loc_f32_time = (u16_period_ticks) * ((float32_t) loc_u16_prescaler / F_CPU) * 1000;
		float32_t loc_f32_duty = (loc_f32_pulse_width_ratio) * 100;
		
		GLCD_void_Select_Page(PAGE_0);
		GLCD_void_Set_Line(LINE_0);
		GLCD_void_Set_Cursor_Position(CURSOR_POSITION_0);
		GLCD_void_Display_String("Freq: ");
		GLCD_void_Display_Floating_Point(loc_f32_frequency);
		
		GLCD_void_Select_Page(PAGE_0);
		GLCD_void_Set_Line(LINE_1);
		GLCD_void_Set_Cursor_Position(CURSOR_POSITION_0);
		GLCD_void_Display_String("TIME: ");
		GLCD_void_Display_Floating_Point(loc_f32_time);
		
		GLCD_void_Select_Page(PAGE_0);
		GLCD_void_Set_Line(LINE_2);
		GLCD_void_Set_Cursor_Position(CURSOR_POSITION_0);
		GLCD_void_Display_String("Duty: ");
		GLCD_void_Display_Floating_Point(loc_f32_duty);
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
			
			for (int i = 0; i < loc_f32_pulse_width_ratio * CYCLE_WIDTH_IN_PIXELS; i++)
			{
				GLCD_void_Display_Pattern(on_pattern);
				j++;
			}
			
			GLCD_void_Display_Pattern(falling_edge_pattern);
			
			for (int i = 0; i < CYCLE_WIDTH_IN_PIXELS - (loc_f32_pulse_width_ratio * CYCLE_WIDTH_IN_PIXELS); i++)
			{
				GLCD_void_Display_Pattern(off_pattern);
				j++;
			}
			
			j+=4;
		}
	}
}

void void_Handle_Prescaler()
{
	switch(config.prescaler)
	{
		case PRESCALE_1:
		loc_u16_prescaler = 1;
		break;
		case PRESCALE_8:
		loc_u16_prescaler = 8;
		break;
		case PRESCALE_64:
		loc_u16_prescaler = 64;
		break;
		case PRESCALE_256:
		loc_u16_prescaler = 256;
		break;
		case PRESCALE_1024:
		loc_u16_prescaler = 1024;
		break;
	}
}