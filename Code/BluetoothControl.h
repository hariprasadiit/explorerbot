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

#ifndef _BLUETOOTH_CONTROL_H_
#define _BLUETOOTH_CONTROL_H_

	/* Includes: */
		#include <avr/io.h>
		#include <stdbool.h>
		#include <stdlib.h>

		#include <LUFA/Drivers/USB/USB.h>
		
		#include "Bluetooth/Bluetooth.h"
		#include "Bluetooth/Services/SDP/SDP.h"
		#include "Bluetooth/Services/HID/HID.h"
		#include "Bluetooth/Services/RFCOMM/RFCOMM.h"

		#include "USB/JoystickHID.h"
		
		#include "BluetoothRobot.h"
		
	/* External Variables: */
		extern RFCOMM_Channel_t* RFCOMM_SensorStream;

#endif

