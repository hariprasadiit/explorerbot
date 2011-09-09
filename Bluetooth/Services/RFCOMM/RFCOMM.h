/*
            Bluetooth Stack
     Copyright (C) Dean Camera, 2011.

  dean [at] fourwalledcubicle [dot] com
        www.fourwalledcubicle.com
*/

/*
  Copyright 2011  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  All rights reserved.
*/

#ifndef _RFCOMM_SERVICE_H_
#define _RFCOMM_SERVICE_H_

	/* Includes: */
		#include <stdbool.h>
		#include <stdint.h>

		#include "../../Bluetooth.h"
		#include "RFCOMMService.h"

	/* Function Prototypes: */
		void RFCOMM_Init(BT_StackConfig_t* const StackState);
		void RFCOMM_Manage(BT_StackConfig_t* const StackState);
		void RFCOMM_ChannelOpened(BT_StackConfig_t* const StackState,
		                          BT_L2CAP_Channel_t* const Channel);
		void RFCOMM_ChannelClosed(BT_StackConfig_t* const StackState,
		                          BT_L2CAP_Channel_t* const Channel);
		void RFCOMM_ProcessPacket(BT_StackConfig_t* const StackState,
                                  BT_L2CAP_Channel_t* const Channel,
                                  uint16_t Length,
                                  uint8_t* Data);

#endif
