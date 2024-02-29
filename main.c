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
#include "avr/interrupt.h"


int main(void)
{	
	DIO_void_Set_Pin_Direction(PORTB_, 3, PIN_OUTPUT);
	
	TIMER0_Init(PRESCALE_1024, FAST_PWM);
	TCCR0 |= 0x30;
	TCNT0 = 0;
	OCR0 = 127;
	
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

