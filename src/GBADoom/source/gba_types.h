/*---------------------------------------------------------------------------------

	Header file for libgba type definitions

	Copyright 2003-2005 by Dave Murphy.

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Library General Public
	License as published by the Free Software Foundation; either
	version 2 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Library General Public License for more details.

	You should have received a copy of the GNU Library General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
	USA.

	Please report all bugs and problems through the bug tracker at
	"http://sourceforge.net/tracker/?group_id=114505&atid=668551".


---------------------------------------------------------------------------------*/

/*! \file gba_types.h
    \brief gba type definitions.

*/

//---------------------------------------------------------------------------------
#ifndef	_gba_types_h_
#define	_gba_types_h_
//---------------------------------------------------------------------------------

#include <stdint.h>
#include <stdbool.h>
//---------------------------------------------------------------------------------
// Data	types
//---------------------------------------------------------------------------------
typedef	uint8_t		u8;	/**< Unsigned 8 bit value	*/
typedef	uint16_t	u16;	/**< Unsigned 16 bit value	*/
typedef	uint32_t	u32;	/**< Unsigned 32 bit value	*/
typedef	int8_t		s8;	/**< Signed 8 bit value	*/
typedef	int16_t		s16;	/**< Signed 16 bit value	*/
typedef	int32_t		s32;	/**< Signed 32 bit value	*/
typedef	volatile u8	vu8;	/**< volatile Unsigned 8 bit value	*/
typedef	volatile u16	vu16;	/**< volatile Unigned 16 bit value	*/
typedef	volatile u32	vu32;	/**< volatile Unsigned 32 bit value	*/
typedef	volatile s8	vs8;	/**< volatile Signed 8 bit value	*/
typedef	volatile s16	vs16;	/**< volatile Signed 8 bit value	*/
typedef	volatile s32	vs32;	/**< volatile Signed 8 bit value	*/


//---------------------------------------------------------------------------------
#endif // _gba_types_h_
//---------------------------------------------------------------------------------

