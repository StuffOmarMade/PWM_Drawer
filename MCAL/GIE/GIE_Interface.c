/*
 * GIE_Interface.h
 *
 * Created: 3/31/2024 3:08:07 PM
 *  Author: Omar
 */ 


#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_Private.h"
#include "GIE_Interface.h"

void GIE_void_Enable()
{
	SET_BIT(SREG_REG, GLOBAL_INTERRUPT_ENABLE_b);
}

void GIE_void_Disable()
{
	SET_BIT(SREG_REG, GLOBAL_INTERRUPT_ENABLE_b);
}

#endif /* GIE_INTERFACE_H_ */