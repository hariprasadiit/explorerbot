/*
             Bluetooth Robot
     Copyright (C) Dean Camera, 2011.

  dean [at] fourwalledcubicle [dot] com
        www.fourwalledcubicle.org
*/

/*
  Copyright 2011  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

#include "Motors.h"

void Motors_Init(void)
{
	DDRD   |= ((1 << 3) | (1 << 4));
	DDRB   |= ((1 << 5) | (1 << 6));
		
	TCCR1A  = ((1 << WGM11) | (1 << WGM10) | (1 << COM1A1) | (1 << COM1A0) | (1 << COM1B1) | (1 << COM1B0));
	TCCR1B  = (1 << CS10);
	
	Motors_SetChannelSpeed(MOTOR_CHANNEL_All, 0);
}

void Motors_SetChannelSpeed(const Motor_Channel_t Channel, const int16_t Power)
{
	uint16_t MotorPWMValue = abs(Power);
	
	// DANGER: DO NOT REMOVE - CLAMPS AVERAGE VOLTAGE BELOW MOTOR DATASHEET THRESHOLD
	if (MotorPWMValue > 0x200)
	  MotorPWMValue = 0x200;

	if (Channel & MOTOR_CHANNEL_Left)
	{
		if (Power < 0)
		  PORTD &= ~(1 << 3);
		else
		  PORTD |=  (1 << 3);
		
		OCR1B = MotorPWMValue;
	}
	
	if (Channel & MOTOR_CHANNEL_Right)
	{
		if (Power < 0)
		  PORTD &= ~(1 << 4);
		else
		  PORTD |=  (1 << 4);
		  
		OCR1A = MotorPWMValue;
	}
}