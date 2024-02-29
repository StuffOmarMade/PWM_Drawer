/*
 * TIMER0_Interface.h
 *
 * Created: 2/29/2024 7:42:06 PM
 *  Author: Omar
 */ 


#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#define WGM01_b					6
#define WGM00_b					3

#define  COM01_b				5
#define  COM00_b				4

#define CS00_b					0
#define CS01_b					1
#define CS02_b					2

#define NORMAL					0x00
#define PHASE_CORRECT_PWM		0x40
#define CTC						0x08
#define FAST_PWM				0x48

#define TIMER0_STOP				0b000
#define PRESCALE_1				0b001
#define PRESCALE_8				0b010
#define PRESCALE_64				0b001
#define PRESCALE_256			0b100
#define PRESCALE_1024			0b101
#define EXT_CLK_FALLING_EDGE	0b110
#define EXT_CLK_RISING_EDGE		0b111

void TIMER0_Init(uint8_t copy_u8_clock_select, uint8_t copy_u8_waveform_generation_mode);

#endif /* TIMER0_INTERFACE_H_ */