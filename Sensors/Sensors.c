/*
             Bluetooth Robot
     Copyright (C) Dean Camera, 2011.

  dean [at] fourwalledcubicle [dot] com
        www.fourwalledcubicle.com
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

#include "Sensors.h"

Sensor_t Sensors;

/** Initializes the robot sensors mounted on the board, ready for use. This must be called before any other functions in the
 *  sensors hardware driver.
 */
void Sensors_Init(void)
{
	DDRB &= ~((1 << 0) | (1 << 1) | (1 << 2));
	DDRB |=  (1 << 3);
	DDRD &= ~(1 << 2);
	
	/* Set XCLR line high, to enable the pressure sensor */
	PORTB |= (1 << 3);
	
	/* Initialize the TWI bus at 200KHz for fastest possible read time */
	TWI_Init(TWI_BIT_PRESCALE_1, TWI_BITLENGTH_FROM_FREQ(1, 200000));
	
	/* Clear the sensor information table, reset all sensor data */
	memset(&Sensors, 0x00, sizeof(Sensors));
	
	/* Pre-sensor initialization delay */
	Delay_MS(100);
	
	/* Attempt to initialize all sensors */
	AK8975_Init(&Sensors.Direction);
	BMA150_Init(&Sensors.Acceleration);
	BMP085_Init(&Sensors.Pressure);
	ITG3200_Init(&Sensors.Orientation, &Sensors.Temperature);
	
	/* Pre-sensor calibration delay */
	Delay_MS(100);
	
	/* Attempt to zero-calibrate all sensors that are connected */
	ITG3200_ZeroCalibrate(&Sensors.Orientation);
}

/** Updates the current raw values for each connected sensor. */
void Sensors_Update(void)
{
	/* Update all sensor table items from the new sensor values */
	AK8975_Update(&Sensors.Direction);
	BMA150_Update(&Sensors.Acceleration);
	BMP085_Update(&Sensors.Pressure);
	ITG3200_Update(&Sensors.Orientation, &Sensors.Temperature);
}

