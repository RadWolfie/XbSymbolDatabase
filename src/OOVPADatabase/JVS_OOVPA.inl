// ******************************************************************
// *
// *   OOVPADatabase->JVS_OOVPA.inl
// *
// *  XbSymbolDatabase is free software; you can redistribute them
// *  and/or modify them under the terms of the GNU General Public
// *  License as published by the Free Software Foundation; either
// *  version 2 of the license, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have recieved a copy of the GNU General Public License
// *  along with this program; see the file COPYING.
// *  If not, write to the Free Software Foundation, Inc.,
// *  59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
// *
// *  (c) 2019 Luke Usher
// *
// *  All rights reserved
// *
// ******************************************************************

// Titles which did compiled with full library
//   [LibV] Title Name                       |  Verify   |  Comments
//-------------------------------------------------------------------
// * [4831] House of The Dead 3              |   100%    | Contain full library.
// * [4831] Crazy Taxi 3                     |   100%    | Contain full library.
// * [5028] SegaBoot v2.00.0                 |   100%    | Contain full library.
// * [5028] SegaBoot v2.13.0                 |   100%    | Contain full library.
// * [5028] Virtua Cop 3                     |   100%    | Contain full library.
// * [5455] Ollie King                       |   100%    | Contain full library.
// * [5558] Outrun 2                         |   100%    | Contain full library.
// * [5659] Outrun 2 SP                      |   100%    | Contain full library.
// * [5788] Ghost Squad                      |   100%    | Contain full library.
// * [5849] Sega Golf 2006                   |   100%    | Contain full library.

// NOTES:
//  * JVSSendCommand1/2/3 sometime changes even when the library version
//    is the same except the functions are quite different in layout, etc
//    and some offsets are different within them too.

#ifndef JVS_OOVPA_INL
#define JVS_OOVPA_INL

#include "OOVPA.h"

#include "JVS/4831.inl"

// ******************************************************************
// * JVSLIB_OOVPA
// ******************************************************************
OOVPATable JVSLIB_OOVPA[] = {

    // Chihiro/JVS (XRef strings)
    REGISTER_OOVPAS(JVS_SendCommand_String, 4831),
    REGISTER_OOVPAS(JvsBACKUP_Read_String, 4831),
    REGISTER_OOVPAS(JvsBACKUP_Write_String, 4831),
    REGISTER_OOVPAS(JvsEEPROM_Read_String, 4831),
    REGISTER_OOVPAS(JvsEEPROM_Write_String, 4831),
    REGISTER_OOVPAS(JvsFirmwareDownload_String, 4831),
    REGISTER_OOVPAS(JvsFirmwareUpload_String, 4831),
    REGISTER_OOVPAS(JvsNodeReceivePacket_String, 4831),
    REGISTER_OOVPAS(JvsNodeSendPacket_String, 4831),
    REGISTER_OOVPAS(JvsRTC_Read_String, 4831),
    REGISTER_OOVPAS(JvsRTC_Write_String, 4831),
    REGISTER_OOVPAS(JvsScFirmwareDownload_String, 4831),
    REGISTER_OOVPAS(JvsScFirmwareUpload_String, 4831),
    REGISTER_OOVPAS(JvsScReceiveMidi_String, 4831),
    REGISTER_OOVPAS(JvsScReceiveRs323c_String, 4831),
    REGISTER_OOVPAS(JvsScSendMidi_String, 4831),
    REGISTER_OOVPAS(JvsScSendRs323c_String, 4831),

    // Chihiro/JVS (Functions)
    REGISTER_OOVPAS(JVS_SendCommand, 4831),
    REGISTER_OOVPAS(JVS_SendCommand2, 4831),
    REGISTER_OOVPAS(JVS_SendCommand3, 4831),
    REGISTER_OOVPAS(JvsBACKUP_Read, 4831),
    REGISTER_OOVPAS(JvsBACKUP_Read2, 4831), 
    REGISTER_OOVPAS(JvsBACKUP_Read3, 4831),
    REGISTER_OOVPAS(JvsBACKUP_Write, 4831),
    REGISTER_OOVPAS(JvsBACKUP_Write2, 4831),
    REGISTER_OOVPAS(JvsEEPROM_Read, 4831),
    REGISTER_OOVPAS(JvsEEPROM_Read2, 4831),
    REGISTER_OOVPAS(JvsEEPROM_Read3, 4831),
    REGISTER_OOVPAS(JvsEEPROM_Write, 4831),
    REGISTER_OOVPAS(JvsEEPROM_Write2, 4831),
    REGISTER_OOVPAS(JvsEEPROM_Write3, 4831),
    REGISTER_OOVPAS(JvsFirmwareDownload, 4831),
    REGISTER_OOVPAS(JvsFirmwareDownload2, 4831),
    REGISTER_OOVPAS(JvsFirmwareDownload3, 4831),
    REGISTER_OOVPAS(JvsFirmwareDownload4, 4831),
    REGISTER_OOVPAS(JvsFirmwareUpload, 4831),
    REGISTER_OOVPAS(JvsFirmwareUpload2, 4831),
    REGISTER_OOVPAS(JvsFirmwareUpload3, 4831),
    REGISTER_OOVPAS(JvsFirmwareUpload4, 4831),
    REGISTER_OOVPAS(JvsNodeReceivePacket, 4831),
    REGISTER_OOVPAS(JvsNodeReceivePacket2, 4831),
    REGISTER_OOVPAS(JvsNodeSendPacket, 4831),
    REGISTER_OOVPAS(JvsNodeSendPacket2, 4831),
    REGISTER_OOVPAS(JvsRTC_Read, 4831),
    REGISTER_OOVPAS(JvsRTC_Read2, 4831),
    REGISTER_OOVPAS(JvsRTC_Read3, 4831),
    REGISTER_OOVPAS(JvsRTC_Write, 4831),
    REGISTER_OOVPAS(JvsRTC_Write2, 4831),
    REGISTER_OOVPAS(JvsScFirmwareDownload, 4831),
    REGISTER_OOVPAS(JvsScFirmwareDownload2, 4831),
    REGISTER_OOVPAS(JvsScFirmwareDownload3, 4831),
    REGISTER_OOVPAS(JvsScFirmwareDownload4, 4831),
    REGISTER_OOVPAS(JvsScFirmwareUpload, 4831),
    REGISTER_OOVPAS(JvsScFirmwareUpload2, 4831),
    REGISTER_OOVPAS(JvsScFirmwareUpload3, 4831),
    REGISTER_OOVPAS(JvsScReceiveMidi, 4831),
    REGISTER_OOVPAS(JvsScReceiveMidi2, 4831),
    REGISTER_OOVPAS(JvsScReceiveRs323c, 4831),
    REGISTER_OOVPAS(JvsScReceiveRs323c2, 4831),
    REGISTER_OOVPAS(JvsScSendMidi, 4831),
    REGISTER_OOVPAS(JvsScSendMidi2, 4831),
    REGISTER_OOVPAS(JvsScSendRs323c, 4831),
    REGISTER_OOVPAS(JvsScSendRs323c2, 4831),
};

// ******************************************************************
// * JVSLIB_OOVPA_COUNT
// ******************************************************************
#define JVSLIB_OOVPA_COUNT XBSDB_ARRAY_SIZE(JVSLIB_OOVPA)

#endif
