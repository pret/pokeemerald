/*---------------------------------------------------------------------------------

	Header file for libgba timer definitions

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

#ifndef _gba_timers_h_
#define _gba_timers_h_
//---------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//---------------------------------------------------------------------------------

#include "gba_base.h"

#define REG_TM0CNT		*(vu32*)(REG_BASE + 0x100)
#define REG_TM0CNT_L	*(vu16*)(REG_BASE + 0x100)
#define REG_TM0CNT_H	*(vu16*)(REG_BASE + 0x102)

#define REG_TM1CNT		*(vu32*)(REG_BASE + 0x104)
#define REG_TM1CNT_L	*(vu16*)(REG_BASE + 0x104)
#define REG_TM1CNT_H	*(vu16*)(REG_BASE + 0x106)

#define REG_TM2CNT		*(vu32*)(REG_BASE + 0x108)
#define REG_TM2CNT_L	*(vu16*)(REG_BASE + 0x108)
#define REG_TM2CNT_H	*(vu16*)(REG_BASE + 0x10a)

#define REG_TM3CNT		*(vu32*)(REG_BASE + 0x10c)
#define REG_TM3CNT_L	*(vu16*)(REG_BASE + 0x10c)
#define REG_TM3CNT_H	*(vu16*)(REG_BASE + 0x10e)

#define	TIMER_COUNT	BIT(2)
#define	TIMER_IRQ	BIT(6)
#define	TIMER_START	BIT(7)


//---------------------------------------------------------------------------------
#ifdef __cplusplus
}	   // extern "C"
#endif
//---------------------------------------------------------------------------------
#endif // _gba_timers_h_
