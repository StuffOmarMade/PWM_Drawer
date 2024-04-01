/*
 * PWM_Drawer.c
 *
 * Created: 2/29/2024 3:49:38 PM
 * Author : Omar
 */ 

#include "APP/PWM_DRAWER_App.h"

int main(void)
{
	PWM_DRAWER_Init();
	
    /* Replace with your application code */
    while (1) 
    {
		PWM_DRAWER_Draw();
	}
}

