
/*
 * GLCD_Interface.c
 *
 * Created: 3/7/2024 8:49:13 AM
 *  Author: Omar
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/FONT_5x8.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "GLCD_Interface.h"

#include <util/delay.h>

void GLCD_void_Init()
{
	DIO_void_Set_Pin_Direction(CTRL_PORT, RS_PIN, PIN_OUTPUT);
	DIO_void_Set_Pin_Direction(CTRL_PORT, RW_PIN, PIN_OUTPUT);
	DIO_void_Set_Pin_Direction(CTRL_PORT, EN_PIN, PIN_OUTPUT);
	DIO_void_Set_Pin_Direction(CTRL_PORT, CS1_PIN, PIN_OUTPUT);
	DIO_void_Set_Pin_Direction(CTRL_PORT, CS2_PIN, PIN_OUTPUT);
	
	DIO_void_Set_Port_Direction(DATA_PORT, PORT_OUTPUT);
}
	
void GLCD_void_Send_Command(uint8_t copy_u8_command)
{
	DIO_void_Set_Port_Value(DATA_PORT, copy_u8_command);
	
	DIO_void_Set_Pin_Value(CTRL_PORT, RS_PIN, PIN_LOW);
	DIO_void_Set_Pin_Value(CTRL_PORT, RW_PIN, PIN_LOW);
	
	DIO_void_Set_Pin_Value(CTRL_PORT, EN_PIN, PIN_HIGH);
	_delay_us(5);
	DIO_void_Set_Pin_Value(CTRL_PORT, EN_PIN, PIN_LOW);
}

void GLCD_void_Send_Data(uint8_t copy_u8_data)
{
	DIO_void_Set_Port_Value(DATA_PORT, copy_u8_data);
	
	DIO_void_Set_Pin_Value(CTRL_PORT, RS_PIN, PIN_HIGH);
	DIO_void_Set_Pin_Value(CTRL_PORT, RW_PIN, PIN_LOW);
	
	DIO_void_Set_Pin_Value(CTRL_PORT, EN_PIN, PIN_HIGH);
	_delay_us(5);
	DIO_void_Set_Pin_Value(CTRL_PORT, EN_PIN, PIN_LOW);
}

void GLCD_void_Select_Page(uint8_t copy_u8_page)
{
	switch(copy_u8_page)
	{
		case NO_PAGE:
			DIO_void_Set_Pin_Value(CTRL_PORT, CS1_PIN, PIN_LOW);
			DIO_void_Set_Pin_Value(CTRL_PORT, CS2_PIN, PIN_LOW);
		break;
		
		case PAGE_0:
			DIO_void_Set_Pin_Value(CTRL_PORT, CS1_PIN, PIN_HIGH);
			DIO_void_Set_Pin_Value(CTRL_PORT, CS2_PIN, PIN_LOW);
		break;
		
		case PAGE_1:
			DIO_void_Set_Pin_Value(CTRL_PORT, CS1_PIN, PIN_LOW);
			DIO_void_Set_Pin_Value(CTRL_PORT, CS2_PIN, PIN_HIGH);
		break;
		
		case BOTH_PAGES:
			DIO_void_Set_Pin_Value(CTRL_PORT, CS1_PIN, PIN_HIGH);
			DIO_void_Set_Pin_Value(CTRL_PORT, CS2_PIN, PIN_HIGH);
		break;
	}
}

void GLCD_void_Set_Cursor_Position(uint8_t copy_u8_position)
{
	copy_u8_position = (0b01 << 6) | copy_u8_position;
	GLCD_void_Send_Command(copy_u8_position);
}

void GLCD_void_Set_Line(uint8_t copy_u8_line)
{
	copy_u8_line = (0b10111 << 3) | copy_u8_line;
	GLCD_void_Send_Command(copy_u8_line);
}

void GLCD_void_Display_Char(uint8_t copy_u8_char)
{
	for (uint8_t i = 0; i < CHAR_LENGTH; i++)
	{
		GLCD_void_Send_Data(font5x8[((copy_u8_char - 32) * 5) + i]);
	}
}

void GLCD_void_Display_String(char* copy_u8_string)
{
	while (*copy_u8_string != '\0')
	{
		GLCD_void_Display_Char(*copy_u8_string);
		copy_u8_string++;
	}
}

void GLCD_void_Display_Integer(int32_t copy_s32_integer)
{
	uint8_t loc_u8_digit = 0;
	uint8_t str_reversed[5] = "";
	uint8_t* str_ptr = str_reversed;
	
	do {
		loc_u8_digit = copy_s32_integer % 10;
		*str_ptr = (char)(48 + loc_u8_digit);
		copy_s32_integer = copy_s32_integer / 10;
		str_ptr++;
	} while (copy_s32_integer > 0);
	do {
		str_ptr--;
		GLCD_void_Display_Char(*str_ptr);
	} while (str_ptr != str_reversed);
}

void GLCD_void_Display_Floating_Point(float32_t copy_f32_float)
{
	uint32_t integer_part = (int32_t) copy_f32_float;
	GLCD_void_Display_Integer(integer_part);
	GLCD_void_Display_Char('.');
	GLCD_void_Display_Integer((copy_f32_float - integer_part) * 100);
}