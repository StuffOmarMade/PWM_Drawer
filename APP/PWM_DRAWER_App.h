/*
 * PWM_DRAWER_App.h
 *
 * Created: 4/1/2024 1:42:31 PM
 *  Author: Omar
 */ 


#ifndef PWM_DRAWER_APP_H_
#define PWM_DRAWER_APP_H_

#include "../LIB/STD_TYPES.h"

#define CYCLE_WIDTH_IN_PIXELS	60

void PWM_DRAWER_Init();
void PWM_DRAWER_Draw();
void void_Handle_Prescaler();

typedef struct
{
	uint8_t prescaler;
	uint8_t mode;
	uint8_t compare_output_mode;
} PWM_DRAWER_Configuration;


#endif /* PWM_DRAWER_APP_H_ */