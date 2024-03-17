/*
 * TIMER1_Interface.h
 *
 * Created: 3/11/2024 6:59:46 AM
 *  Author: Omar
 */ 

#define FOC1A_b			3
#define FOC1B_b			2

#define ICNC1_b			7
#define ICES1_b			6
#define TICIE1_b		5
#define ICF1_b			5

#define WGM12_b			3

#define ICP1_PIN		6

#define FALLING_EDGE	0
#define RISING_EDGE		1

#define TIMER1_STOP				0b000
#define PRESCALE_1				0b001
#define PRESCALE_8				0b010
#define PRESCALE_64				0b011
#define PRESCALE_256			0b100
#define PRESCALE_1024			0b101
#define EXT_CLK_FALLING_EDGE	0b110
#define EXT_CLK_RISING_EDGE		0b111

#define PWM_PHASE_CORRECT_8_BIT				1
#define PWM_PHASE_CORRECT_9_BIT				2
#define PWM_PHASE_CORRECT_10_BIT			3
#define CTC_OCR1A							4
#define FAST_PWM_8_BIT						5
#define FAST_PWM_9_BIT						6
#define FAST_PWM_10_BIT						7
#define PWM_PHASE_AND_FREQ_CORRECT_ICR1		8
#define PWM_PHASE_AND_FREQ_CORRECT_OCR1A	9
#define PWM_PHASE_CORRECT_ICR1				10
#define PWM_PHASE_CORRECT_OCR1A				11
#define CTC_ICR1							12
#define FAST_PWM_ICR1						14
#define FAST_PWM_OCR1A						15

#define COMPARE_UNIT_A			0
#define	COMPARE_UNIT_B			1
#define BOTH_COMPARE_UNITS		2

void TIMER1_void_Init(uint8_t copy_u8_clock_select, uint8_t copy_u8_mode);
//void TIMER1_void_Force_Output_Compare(uint8_t copy_u8_compare_unit);
void TIMER1_void_ICU_Edge_Select(uint8_t copy_u8_edge);