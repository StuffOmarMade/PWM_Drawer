/*
 * DIO_Interface.h
 *
 * Created: 2/29/2024 6:00:54 PM
 *  Author: Omar
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define PIN_INPUT	0
#define PIN_OUTPUT	1

#define PIN_LOW		0
#define PIN_HIGH	1

#define PORTA_		0
#define PORTB_		1
#define PORTC_		2
#define PORTD_		3

uint8_t DIO_u8_Get_Pin_Value(uint8_t copy_u8_port, uint8_t copy_u8_pin);
void	DIO_void_Set_Pin_Direction(uint8_t copy_u8_port, uint8_t copy_u8_pin, uint8_t copy_u8_pin_direction);
void	DIO_void_Set_Pin_Value(uint8_t copy_u8_port, uint8_t copy_u8_pin, uint8_t copy_u8_pin_value);
void	DIO_void_Tog_Pin_Value(uint8_t copy_u8_port, uint8_t copy_u8_pin);

uint8_t DIO_u8_Get_Port_Value(uint8_t copy_u8_port);
void	DIO_void_Set_Port_Direction(uint8_t copy_u8_port, uint8_t copy_u8_port_direction);
void	DIO_void_Set_Port_Value(uint8_t copy_u8_port, uint8_t copy_u8_port_value);
void	DIO_void_Tog_Port_Value(uint8_t copy_u8_port);



#endif /* DIO_INTERFACE_H_ */