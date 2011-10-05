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

#ifndef _BLUETOOTH_L2CAP_H_
#define _BLUETOOTH_L2CAP_H_

	/* Includes: */
		#include <stdbool.h>
		#include <stdint.h>
		
		#include "BluetoothCommon.h"
		#include "BluetoothL2CAPPacketTypes.h"
		#include "BluetoothL2CAPSignalCodes.h"
		#include "BluetoothHCI.h"

	/* Macros: */
		/** Lowest possible channel number for L2CAP data channels. */
		#define BT_CHANNEL_BASEOFFSET             0x0040

		/** Bluetooth specification defined channel number for signaling commands. */
		#define BT_CHANNEL_SIGNALING              0x0001

		/** Bluetooth specification defined channel number for connectionless data. */
		#define BT_CHANNEL_CONNECTIONLESS         0x0002
		
		/** HCI connection flag to automatically flush packets to the receiver. */
		#define BT_L2CAP_FIRST_AUTOFLUSH          (1 << 13)

	/* Function Prototypes: */
		void Bluetooth_L2CAP_NotifyHCIDisconnection(BT_StackConfig_t* const StackState,
		                                            const uint16_t ConnectionHandle);

		BT_L2CAP_Channel_t* const Bluetooth_L2CAP_FindChannel(BT_StackConfig_t* const StackState,
		                                                      const uint16_t ConnectionHandle,
		                                                      const uint16_t LocalChannel,
		                                                      const uint16_t RemoteChannel);

		void Bluetooth_L2CAP_Init(BT_StackConfig_t* const StackState);
		void Bluetooth_L2CAP_ProcessPacket(BT_StackConfig_t* const StackState,
		                                   BT_HCI_Connection_t* const HCIConnection,
		                                   const void* Data);
		bool Bluetooth_L2CAP_Manage(BT_StackConfig_t* const StackState);

		BT_L2CAP_Channel_t* const Bluetooth_L2CAP_OpenChannel(BT_StackConfig_t* const StackState,
                                                              BT_HCI_Connection_t* const HCIConnection,
                                                              const uint16_t PSM);
		void Bluetooth_L2CAP_CloseChannel(BT_StackConfig_t* const StackState,
		                                  BT_L2CAP_Channel_t* const L2CAPChannel);

		bool Bluetooth_L2CAP_SendPacket(BT_StackConfig_t* const StackState,
		                                BT_L2CAP_Channel_t* const L2CAPChannel,
		                                const uint16_t Length,
		                                const void* Data);

#endif