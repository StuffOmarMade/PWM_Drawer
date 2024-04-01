/*
 * TIMER0_Interface.h
 *
 * Created: 2/29/2024 7:42:06 PM
 *  Author: Omar
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#define FOC0_b					7

#define WGM01_b					6
#define WGM00_b					3

#define COM01_b					5
#define COM00_b					4

#define CS00_b					0
#define CS01_b					1
#define CS02_b					2

#define TOIE0_b					0
#define OCIE0_b					1

#define OC0_PIN					3

#define TIMER0_OUTPUT_COMPARE_MATCH_INTERRUPT	0
#define TIMER0_OVERFLOW_INTERRUPT				1

#define NORMAL					0x00
#define PHASE_CORRECT_PWM		0x40
#define CTC						0x08
#define FAST_PWM				0x48

#define TIMER0_STOP				0b000
#define PRESCALE_1				0b001
#define PRESCALE_8				0b010
#define PRESCALE_64				0b011
#define PRESCALE_256			0b100
#define PRESCALE_1024			0b101
#define EXT_CLK_FALLING_EDGE	0b110
#define EXT_CLK_RISING_EDGE		0b111

#define DISCONNECT_OC0			0b00
#define NON_PWM_TOGGLE_OC0		0b01
#define	NON_PWM_CLEAR_OC0		0b10
#define	NON_PWM_SET_OC0			0b11

#define	FAST_PWM_NON_INVERTING	0b10
#define	FAST_PWM_INVERTING		0b11

#define	PHASE_CORRECT_PWM_CLR_UP		0b10
#define	PHASE_CORRECT_PWM_SET_UP		0b11

void TIMER0_void_Init(uint8_t copy_u8_clock_select, uint8_t copy_u8_mode);
void TIMER0_void_Set_Compare_Output_Mode(uint8_t copy_u8_compare_output_mode);
void TIMER0_void_Force_Output_Compare();
void TIMER1_void_Interrupt_Enable(uint8_t copy_u8_interrupt);
void TIMER1_void_Interrupt_Disable(uint8_t copy_u8_interrupt);
void TIMER0_void_Set_Counter_Value(uint8_t copy_u8_value);
void TIMER0_void_Set_Top_Value(uint8_t copy_u8_value);
void TIMER0_void_Stop();

#endif /* TIMER0_INTERFACE_H_ */