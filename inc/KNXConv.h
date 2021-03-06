/*
 *   KONNEX/EIB-Protocol-Stack.
 *
 *  (C) 2007-2012 by Christoph Schueler <github.com/Christoph2,
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
#if !defined(__KNXCONV_H)
#define __KNXCONV_H

#include "KNXDefs.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#if defined(__HIWARE__)
#define KNX_BIG_ENDIAN
#undef  KNX_LITTLE_ENDIAN
#elif defined(_MSC_VER)
#undef  KNX_BIG_ENDIAN
#define KNX_LITTLE_ENDIAN
#endif

#if defined(KNX_BIG_ENDIAN)
#define btohs(w)    (w)
#define htobs(w)    (w)

#elif defined(KNX_LITTLE_ENDIAN)

/* #define btohs(w)    MAKEWORD(LOBYTE((w)),HIBYTE((w))) */

/*
** Global functions.
*/
#if KSTACK_MEMORY_MAPPING == STD_ON
FUNC(uint16, KSTACK_CODE)   LongToDPT9(sint32 value);
FUNC(uint16, KSTACK_CODE)   FloatToDPT9(float64 value);
FUNC(float64, KSTACK_CODE)  DPT9ToFloat(uint16 value);
FUNC(sint32, KSTACK_CODE)   DPT9ToLong(uint16 value);
FUNC(uint16, KSTACK_CODE)   btohs(uint16 w);
#else
uint16  LongToDPT9(sint32 value);
uint16  FloatToDPT9(float64 value);
float64 DPT9ToFloat(uint16 value);
sint32  DPT9ToLong(uint16 value);
uint16  btohs(uint16 w);


#endif /* KSTACK_MEMORY_MAPPING */

#define htobs(w) btohs(w)
#else
 #error "No Endianess defined!!!"
#endif

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __KNXCONV_H */

