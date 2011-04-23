/*
 *   KONNEX/EIB-Protocol-Stack.
 *
 *  (C) 2007-2011 by Christoph Schueler <github.com/Christoph2,
 *                                       cpu12.gems@googlemail.com>
 *
 *   All Rights Reserved
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "knx_address.h"

/*
   static const uint8 KNX_OBJTYPESIZE[16]={ // Hinweis: auch als 'KNX_OBJ_LEN_TAB' definiert!?
    1,   // UINT1
    1,   // UINT2
    1,   // UINT3
    1,   // UINT4
    1,   // UINT5
    1,   // UINT6
    1,   // UINT7
    1,   // UINT8
    2,   // UINT16
    3,   // BYTE3
    4,   // FLOAT
    6,   // DATA6
    8,   // DOUBLE
    10,  // DATA10
    14,  // MAXDATA
    14   // VARDATA     - wichtiger Hinweis: im KNX-Handbuch: Interface Object Reference (4-14 octets).
   };
 */

/*
**  todo: this Fkt. is hardware-dependent !!!
*/
boolean ADR_InProgrammingMode(void)
{
    return TRUE;
}

/*
**
*/

boolean ADR_IsAddressed(Knx_AddressType searched_addr, uint8 * tsap)
{
    uint8   len;
    uint16  mid;
    sint16  left, right;
    boolean ack;
    uint16  ca, * ap;

    ack    = FALSE;
    *tsap  = KNX_INVALID_TSAP;

    if (ADR_IsBroadcastAddress(searched_addr)) {
        return TRUE;
    }

    len = ADR_GrATLength();

    if (len > (uint8)1) {
        ap = ADR_GrATBasePtr();

        left   = (sint16)0;
        right  = len - (sint16)1;

        do {
            mid    = (uint16)(left + right) >> 1;
            ca     = btohs(*(ap + mid));

            if (searched_addr == ca) {
                *tsap  = mid + (uint16)1;
                ack    = TRUE;
                break;
            } else if (searched_addr < ca) {
                right = (sint16)(mid - (uint16)1);
            } else {
                left = (sint16)(mid + (uint16)1);
            }
        } while (left <= right);
    } else if (len == (uint8)0) {
        ack = TRUE; /* passthru of every Frame. */
    } else {        /* len==1. */
        ack = FALSE;
    }

    return ack;
}

Knx_AddressType ADR_GetPhysAddr(void)
{
    return btohs(*(uint16 *)&APP_AddressTable[1]);
}

void ADR_SetPhysAddr(Knx_AddressType addr)
{
    *(uint16 *)APP_AddressTable[1] = htobs(addr);    /* todo: use Memory-Server!!! */
}

void ADR_GetSerialNumber(Knx_SerialNumberType serial_number)
{
/*CopyMem((uint8*)serial_number,(uint8*)DEV_SERIAL_NUM,sizeof(KNX_SerialNumberType)); */
}

boolean ADR_IsOwnPhysicalAddr(Knx_AddressType addr)     /* todo: Macro!!! */
{
    return ADR_GetPhysAddr() == addr;
}

/*
   int CompareAddresses(Knx_AddressType a1,Knx_AddressType a2)   // addrcmp
   {
    // a1==a2 ==> return 0  - a1<a2 ==> return -1   -   a1>a2   ==> return 1
   }
 */
