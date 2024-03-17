/*
 * PWM_Drawer.c
 *
 * Created: 2/29/2024 3:49:38 PM
 * Author : Omar
 */ 

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/TIMER0/TIMER0_Interface.h"
#include "MCAL/TIMER1/TIMER1_Interface.h"

#include "HAL/GLCD/GLCD_Interface.h"

#include <avr/interrupt.h>
#include <avr/io.h>

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
		u16_init_val = ICR1;
	}
	else if(loc_u16_counter == 2)
	{
		u16_period_ticks = ICR1;
		
		TIMER1_void_ICU_Edge_Select(FALLING_EDGE);
	}
	else if(loc_u16_counter == 3)
	{
		u16_on_ticks = ICR1;
		TIMER1_void_ICU_Edge_Select(RISING_EDGE);
		
		loc_u16_counter = 0;
		TCNT1 = 0;
		
		done = true;
		
		cli();
	}
}

int main(void)
{
	DIO_void_Set_Pin_Direction(PORTB_, 3, PIN_OUTPUT);
	DIO_void_Set_Pin_Direction(PORTD_, 6, PIN_INPUT);
	
	GLCD_void_Init();
	GLCD_void_Select_Page(PAGE_0);
	GLCD_void_Send_Command(DISPLAY_ON);
	
	
	TIMER0_void_Init(PRESCALE_1024, CTC);
	TIMER0_void_Set_Compare_Output_Mode(1);
	
	TCNT0 = 0;
	OCR0 = 100;
	
	TIMER1_void_Init(PRESCALE_1024, NORMAL);
	TIMER1_void_ICU_Edge_Select(RISING_EDGE);
	
	SET_BIT(TIMSK, TICIE1);
	
	TCNT1 = 0;
	
	sei();
	

    /* Replace with your application code */
    while (1) 
    {
		if(done)
		{
			GLCD_void_Set_Line(LINE_0);
			GLCD_void_Set_Cursor_Position(CURSOR_POSITION_0);
			GLCD_void_Display_String("Freq: ");
			
			GLCD_void_Select_Page(PAGE_1);
			
			GLCD_void_Set_Line(LINE_0);
			GLCD_void_Set_Cursor_Position(CURSOR_POSITION_0);
			GLCD_void_Display_String("Duty: ");
			GLCD_void_Display_Integer((u16_on_ticks - u16_period_ticks));
			
			GLCD_void_Select_Page(PAGE_0);
			
			GLCD_void_Set_Line(LINE_1);
			GLCD_void_Set_Cursor_Position(CURSOR_POSITION_0);
			GLCD_void_Display_String("TIME: ");
			GLCD_void_Display_Integer(u16_period_ticks - u16_init_val);
			
			GLCD_void_Set_Line(LINE_6);
			GLCD_void_Set_Cursor_Position(CURSOR_POSITION_0);
		}
    }
}

