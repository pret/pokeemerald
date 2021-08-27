/*

	Header file for libgba DMA definitions

	Copyright 2003-2007 by Dave Murphy.

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

*/

//---------------------------------------------------------------------------------
#ifndef _gba_dma_h_
#define _gba_dma_h_
//---------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//---------------------------------------------------------------------------------

#include "gba_base.h"


#define REG_DMA0SAD	*(vu32*)(REG_BASE + 0x0b0)
#define REG_DMA0DAD	*(vu32*)(REG_BASE + 0x0b4)
#define REG_DMA0CNT	*(vu32*)(REG_BASE + 0x0b8)

#define REG_DMA1SAD	*(vu32*)(REG_BASE + 0x0bc)
#define REG_DMA1DAD	*(vu32*)(REG_BASE + 0x0c0)
#define REG_DMA1CNT	*(vu32*)(REG_BASE + 0x0c4)

#define REG_DMA2SAD	*(vu32*)(REG_BASE + 0x0c8)
#define REG_DMA2DAD	*(vu32*)(REG_BASE + 0x0cc)
#define REG_DMA2CNT	*(vu32*)(REG_BASE + 0x0d0)

#define REG_DMA3SAD	*(vu32*)(REG_BASE + 0x0d4)
#define REG_DMA3DAD	*(vu32*)(REG_BASE + 0x0d8)
#define REG_DMA3CNT	*(vu32*)(REG_BASE + 0x0dc)


#define DMA_DST_INC		(0<<21)
#define DMA_DST_DEC		(1<<21)
#define DMA_DST_FIXED	(2<<21)
#define DMA_DST_RELOAD	(3<<21)

#define DMA_SRC_INC		(0<<23)
#define DMA_SRC_DEC		(1<<23)
#define DMA_SRC_FIXED	(2<<23)

#define DMA_REPEAT		(1<<25)

#define DMA16			(0<<26)
#define DMA32			(1<<26)

#define	GAMEPAK_DRQ		(1<<27)

#define DMA_IMMEDIATE	(0<<28)
#define DMA_VBLANK		(1<<28)
#define DMA_HBLANK		(2<<28)
#define DMA_SPECIAL		(3<<28)

#define DMA_IRQ			(1<<30)
#define DMA_ENABLE		(1<<31)

#define DMA_Copy(channel, source, dest, mode) {\
	REG_DMA##channel##SAD = (u32)(source);\
	REG_DMA##channel##DAD = (u32)(dest);\
	REG_DMA##channel##CNT = DMA_ENABLE | (mode); \
}

static inline void dmaCopy(const void * source, void * dest, u32 size) {
	DMA_Copy(3, source, dest, DMA16 | size>>1);
}

#define	DMA0COPY( source, dest, mode) DMA_Copy(0,(source),(dest),(mode))
#define	DMA1COPY( source, dest, mode) DMA_Copy(1,(source),(dest),(mode))
#define	DMA2COPY( source, dest, mode) DMA_Copy(2,(source),(dest),(mode))
#define	DMA3COPY( source, dest, mode) DMA_Copy(3,(source),(dest),(mode))

//---------------------------------------------------------------------------------
#ifdef __cplusplus
}	   // extern "C"
#endif
//---------------------------------------------------------------------------------
#endif // _gba_dma_h_
