
/*
 * GLCD_Interface.h
 *
 * Created: 3/7/2024 8:49:27 AM
 *  Author: Omar
 */ 

#define F_CPU	16000000UL

#define CHAR_LENGTH	5

#define DISPLAY_OFF	0b00111110
#define DISPLAY_ON	0b00111111

#define CTRL_PORT	PORTC_
#define DATA_PORT	PORTA_

#define RS_PIN	0
#define RW_PIN	1
#define EN_PIN	2

#define CS1_PIN	3
#define CS2_PIN	4

#define NO_PAGE		0
#define PAGE_0		1
#define PAGE_1		2
#define BOTH_PAGES	3

#define MAX_WIDTH	128
#define PAGE_WIDTH	64

#define LINE_0 0b000
#define LINE_1 0b001
#define LINE_2 0b010
#define LINE_3 0b011
#define LINE_4 0b100
#define LINE_5 0b101
#define LINE_6 0b110
#define LINE_7 0b111

#define CURSOR_POSITION_0 0x00
#define CURSOR_POSITION_1 0x01
#define CURSOR_POSITION_2 0x02
#define CURSOR_POSITION_3 0x03
#define CURSOR_POSITION_4 0x04
#define CURSOR_POSITION_5 0x05
#define CURSOR_POSITION_6 0x06
#define CURSOR_POSITION_7 0x07
#define CURSOR_POSITION_8 0x08
#define CURSOR_POSITION_9 0x09
#define CURSOR_POSITION_10 0x0A
#define CURSOR_POSITION_11 0x0B
#define CURSOR_POSITION_12 0x0C
#define CURSOR_POSITION_13 0x0D
#define CURSOR_POSITION_14 0x0E
#define CURSOR_POSITION_15 0x0F
#define CURSOR_POSITION_16 0x10
#define CURSOR_POSITION_17 0x11
#define CURSOR_POSITION_18 0x12
#define CURSOR_POSITION_19 0x13
#define CURSOR_POSITION_20 0x14
#define CURSOR_POSITION_21 0x15
#define CURSOR_POSITION_22 0x16
#define CURSOR_POSITION_23 0x17
#define CURSOR_POSITION_24 0x18
#define CURSOR_POSITION_25 0x19
#define CURSOR_POSITION_26 0x1A
#define CURSOR_POSITION_27 0x1B
#define CURSOR_POSITION_28 0x1C
#define CURSOR_POSITION_29 0x1D
#define CURSOR_POSITION_30 0x1E
#define CURSOR_POSITION_31 0x1F
#define CURSOR_POSITION_32 0x20
#define CURSOR_POSITION_33 0x21
#define CURSOR_POSITION_34 0x22
#define CURSOR_POSITION_35 0x23
#define CURSOR_POSITION_36 0x24
#define CURSOR_POSITION_37 0x25
#define CURSOR_POSITION_38 0x26
#define CURSOR_POSITION_39 0x27
#define CURSOR_POSITION_40 0x28
#define CURSOR_POSITION_41 0x29
#define CURSOR_POSITION_42 0x2A
#define CURSOR_POSITION_43 0x2B
#define CURSOR_POSITION_44 0x2C
#define CURSOR_POSITION_45 0x2D
#define CURSOR_POSITION_46 0x2E
#define CURSOR_POSITION_47 0x2F
#define CURSOR_POSITION_48 0x30
#define CURSOR_POSITION_49 0x31
#define CURSOR_POSITION_50 0x32
#define CURSOR_POSITION_51 0x33
#define CURSOR_POSITION_52 0x34
#define CURSOR_POSITION_53 0x35
#define CURSOR_POSITION_54 0x36
#define CURSOR_POSITION_55 0x37
#define CURSOR_POSITION_56 0x38
#define CURSOR_POSITION_57 0x39
#define CURSOR_POSITION_58 0x3A
#define CURSOR_POSITION_59 0x3B
#define CURSOR_POSITION_60 0x3C
#define CURSOR_POSITION_61 0x3D
#define CURSOR_POSITION_62 0x3E
#define CURSOR_POSITION_63 0x3F

void GLCD_void_Init();
void GLCD_void_Send_Command(uint8_t copy_u8_command);
void GLCD_void_Send_Data(uint8_t copy_u8_data);

void GLCD_void_Select_Page(uint8_t copy_u8_page);
void GLCD_void_Set_Cursor_Position(uint8_t copy_u8_position);
void GLCD_void_Set_Line(uint8_t copy_u8_line);

void GLCD_void_Display_Char(uint8_t copy_u8_char);
void GLCD_void_Display_String(char* copy_u8_string);

void GLCD_void_Display_Integer(int32_t copy_s32_integer);
void GLCD_void_Display_Floating_Point(float32_t copy_f32_float);

void GLCD_void_Display_Pattern(uint8_t pattern[]);