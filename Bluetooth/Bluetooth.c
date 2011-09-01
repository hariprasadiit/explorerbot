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

/** \file
 *
 *  Main module for the Bluetooth stack. This module contains the main Bluetooth stack management functions.
 */

#include "Bluetooth.h"

/** Initializes the Bluetooth stack ready for use. This must be called once at application startup to reset the internal
 *  stack state.
 *
 *  \param[in, out] StackState  Pointer to a Bluetooth Stack state table.
 */
void Bluetooth_Init(BT_StackConfig_t* const StackState)
{
	memset(&StackState->State, 0x00, sizeof(StackState->State));
	
	Bluetooth_HCI_Init(StackState);
	Bluetooth_ACL_Init(StackState);
}

/** Manages the Bluetooth connections between the local and remote Bluetooth devices. This must be called periodically to
 *  maintain connections.
 *
 *  \param[in, out] StackState  Pointer to a Bluetooth Stack state table.
 *
 *  \return Boolean \c true if more management is required, \c false if all pending management tasks have completed.
 */
bool Bluetooth_ManageConnections(BT_StackConfig_t* const StackState)
{
	return (Bluetooth_HCI_Manage(StackState) || Bluetooth_ACL_Manage(StackState));
}

/** Processes the Bluetooth packet of the specified type currently stored in the input packet buffer.
 *
 *  \param[in, out] StackState  Pointer to a Bluetooth Stack state table.
 *  \param[in]      Type        Packet type, a value from the \ref BT_PacketType_t enum.
 */
void Bluetooth_ProcessPacket(BT_StackConfig_t* const StackState,
                             const uint8_t Type)
{
	switch (Type)
	{
		case BLUETOOTH_PACKET_HCIEvent:
			Bluetooth_HCI_ProcessPacket(StackState);
			return;
		case BLUETOOTH_PACKET_ACLData:
			Bluetooth_ACL_ProcessPacket(StackState);
			return;
	}
}
