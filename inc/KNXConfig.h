/*
 *   KONNEX/EIB-Protocol-Stack.
 *
 * (C) 2007-2012 by Christoph Schueler <github.com/Christoph2,
 *                                      cpu12.gems@googlemail.com>
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
#if !defined(__KNXCONFIG_H)
#define __KNXCONFIG_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
** Global defines.
*/
#define KNX_STANDALONE  /* TODO: STD_ON | STD_OFF */
#define KNX_CLIENT_LIB
#define KNX_USE_CONFIMATIONS
#define KNX_BUSACCESS_TPUART
#define KNX_TL_STYLE    ((uint8)3)
#undef  KNX_TL_RATIONALIZE
#define KNX_USER_OBJECTS
#define KNX_MASK_TYPE   ((uint8)21)

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __KNXCONFIG_H */

