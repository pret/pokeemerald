/*---------------------------------------------------------------------------------

	Header file for libgba video definitions

	Copyright 2003-2006 by Dave Murphy.

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

/*! \file gba_video.h
    \brief gba video definitions.

*/

//---------------------------------------------------------------------------------
#ifndef _gba_video_h_
#define _gba_video_h_
//---------------------------------------------------------------------------------

#include "gba_base.h"

/*! \def BG_COLORS
*/
#define BG_COLORS		((u16 *)0x05000000)	// Background color table
#define BG_PALETTE		((u16 *)0x05000000)	// Background color table
/*! \def OBJ_COLORS
*/
#define	OBJ_COLORS		((u16 *)0x05000200)	// Sprite color table
#define	SPRITE_PALETTE	((u16 *)0x05000200)	// Sprite color table

/*! \def REG_DISPCNT

    \brief LCD control register

	This register controls all aspects of the GBA display.
*/
#define	REG_DISPCNT		*((vu16 *)(REG_BASE + 0x00))

//!  LCDC bits.
/*!
  These bits are used in conjuction with REG_DISPCNT to control the GBA display hardware.
*/
//---------------------------------------------------------------------------------
typedef enum LCDC_BITS {
//---------------------------------------------------------------------------------
	MODE_0	=	0,	/*!< BG Mode 0 */
	MODE_1	=	1,	/*!< BG Mode 1 */
	MODE_2	=	2,	/*!< BG Mode 2 */
	MODE_3	=	3,	/*!< BG Mode 3 */
	MODE_4	=	4,	/*!< BG Mode 4 */
	MODE_5	=	5,	/*!< BG Mode 5 */

	BACKBUFFER	=	BIT(4),		/*!< buffer display select			*/
	OBJ_1D_MAP	=	BIT(6),		/*!< sprite 1 dimensional mapping	*/
	LCDC_OFF	=	BIT(7),		/*!< LCDC OFF						*/
	BG0_ON		=	BIT(8),		/*!< enable background 0			*/
	BG1_ON		=	BIT(9),		/*!< enable background 1			*/
	BG2_ON		=	BIT(10),	/*!< enable background 2			*/
	BG3_ON		=	BIT(11),	/*!< enable background 3			*/
	OBJ_ON		=	BIT(12),	/*!< enable sprites					*/
	WIN0_ON		=	BIT(13),	/*!< enable window 0				*/
	WIN1_ON		=	BIT(14),	/*!< enable window 1				*/
	OBJ_WIN_ON	=	BIT(15),	/*!< enable obj window				*/

	BG0_ENABLE		=	BG0_ON,		/*!< enable background 0	*/
	BG1_ENABLE		=	BG1_ON, 	/*!< enable background 1	*/
	BG2_ENABLE		=	BG2_ON, 	/*!< enable background 2	*/
	BG3_ENABLE		=	BG3_ON,		/*!< enable background 3	*/
	OBJ_ENABLE		=	OBJ_ON, 	/*!< enable sprites			*/
	WIN0_ENABLE		=	WIN0_ON,	/*!< enable window 0		*/
	WIN1_ENABLE		=	WIN1_ON,	/*!< enable window 1		*/
	OBJ_WIN_ENABLE	=	OBJ_WIN_ON, /*!< enable obj window		*/

	BG_ALL_ON		=	BG0_ON | BG1_ON | BG2_ON | BG3_ON, 	    /*!< All Backgrounds on.		*/
	BG_ALL_ENABLE	=	BG0_ON | BG1_ON | BG2_ON | BG3_ON	    /*!< All Backgrounds enabled.	*/

} LCDC_BITS;

/*! \def REG_DISPSTAT

    \brief General LCD Status.

	This register controls the LCD interrupts.
*/
#define	REG_DISPSTAT	*((vu16 *)(REG_BASE + 0x04))

//---------------------------------------------------------------------------------
// LCDC Interrupt bits
//---------------------------------------------------------------------------------
enum LCDC_IRQ {
	LCDC_VBL_FLAG	=	(1<<0),
	LCDC_HBL_FLAG	=	(1<<1),
	LCDC_VCNT_FLAG	=	(1<<2),
	LCDC_VBL		=	(1<<3),
	LCDC_HBL		=	(1<<4),
	LCDC_VCNT		=	(1<<5)
};

static inline u32 VCOUNT( int m) { return m<<8; }


/*! \def REG_VCOUNT

    \brief

*/
#define	REG_VCOUNT		*((vu16 *)(REG_BASE + 0x06))

/*! \def BGCTRL

	\brief Array definition for background control registers.

	BGCTRL[0] references background 0 control register.<BR>
	BGCTRL[1] references background 1 control register.<BR>
	BGCTRL[2] references background 2 control register.<BR>
	BGCTRL[3] references background 3 control register.<BR>

*/
#define BGCTRL		((vu16 *)(REG_BASE + 0x08))
/*! \def REG_BG0CNT

	\brief Background 0 control register.

*/
#define REG_BG0CNT	*((vu16 *)(REG_BASE + 0x08))
/*! \def REG_BG1CNT

	\brief Background 1 control register.

*/
#define REG_BG1CNT	*((vu16 *)(REG_BASE + 0x0a))
/*! \def REG_BG2CNT

	\brief Background 2 control register.

*/
#define REG_BG2CNT	*((vu16 *)(REG_BASE + 0x0c))
/*! \def REG_BG3CNT

	\brief Background 3 control register.

*/
#define REG_BG3CNT	*((vu16 *)(REG_BASE + 0x0e))

typedef struct {
	vu16 x;
	vu16 y;
} bg_scroll;

#define BG_OFFSET ((bg_scroll *)(REG_BASE + 0x10))

#define	REG_BG0HOFS		*((u16 *)(REG_BASE + 0x10))	// BG 0 H Offset
#define	REG_BG0VOFS		*((u16 *)(REG_BASE + 0x12))	// BG 0 V Offset
#define	REG_BG1HOFS		*((u16 *)(REG_BASE + 0x14))	// BG 1 H Offset
#define	REG_BG1VOFS		*((u16 *)(REG_BASE + 0x16))	// BG 1 V Offset
#define	REG_BG2HOFS		*((u16 *)(REG_BASE + 0x18))	// BG 2 H Offset
#define	REG_BG2VOFS		*((u16 *)(REG_BASE + 0x1a))	// BG 2 V Offset
#define	REG_BG3HOFS		*((u16 *)(REG_BASE + 0x1c))	// BG 3 H Offset
#define	REG_BG3VOFS		*((u16 *)(REG_BASE + 0x1e))	// BG 3 V Offset

#define	REG_BG2PA	*((s16 *)(REG_BASE + 0x20))
#define	REG_BG2PB	*((s16 *)(REG_BASE + 0x22))
#define	REG_BG2PC	*((s16 *)(REG_BASE + 0x24))
#define	REG_BG2PD	*((s16 *)(REG_BASE + 0x26))
#define	REG_BG2X	*((s32 *)(REG_BASE + 0x28))
#define	REG_BG2Y	*((s32 *)(REG_BASE + 0x2c))
#define	REG_BG3PA	*((s16 *)(REG_BASE + 0x30))
#define	REG_BG3PB	*((s16 *)(REG_BASE + 0x32))
#define	REG_BG3PC	*((s16 *)(REG_BASE + 0x34))
#define	REG_BG3PD	*((s16 *)(REG_BASE + 0x36))
#define	REG_BG3X	*((s32 *)(REG_BASE + 0x38))
#define	REG_BG3Y	*((s32 *)(REG_BASE + 0x3c))

#define BG_SIZE(m)		((m<<14))
/*! \enum BG_CTRL_BITS

	\brief bit values for background control
*/
enum BG_CTRL_BITS {
	BG_MOSAIC		=	BIT(6),		/*!< enable background mosaic			*/
	BG_16_COLOR		=	(0<<7),		/*!< background uses 16 color tiles		*/
	BG_256_COLOR	=	BIT(7),		/*!< background uses 256 color tiles	*/
	BG_WRAP			=	BIT(13),	/*!< background wraps when scrolling	*/
	BG_SIZE_0		=	BG_SIZE(0),	/*!< Map Size 256x256	*/
	BG_SIZE_1		=	BG_SIZE(1),	/*!< Map Size 512x256	*/
	BG_SIZE_2		=	BG_SIZE(2),	/*!< Map Size 256x512	*/
	BG_SIZE_3		=	BG_SIZE(3),	/*!< Map Size 512x512	*/
};

#define	CHAR_BASE(m)		((m) << 2)
#define BG_TILE_BASE(m)		((m) << 2)
#define CHAR_BASE_ADR(m)	((void *)(VRAM + ((m) << 14)))
#define CHAR_BASE_BLOCK(m)	((void *)(VRAM + ((m) << 14)))
#define MAP_BASE_ADR(m)		((void *)(VRAM + ((m) << 11)))
#define SCREEN_BASE_BLOCK(m)((void *)(VRAM + ((m) << 11)))
#define SCREEN_BASE(m)		((m) << 8)
#define BG_MAP_BASE(m)		((m) << 8)

//alternate names for char and screen base
#define	TILE_BASE(m)		((m) << 2)
#define TILE_BASE_ADR(m)	((void *)(VRAM + ((m) << 14)))

#define MAP_BASE_ADR(m)		((void *)(VRAM + ((m) << 11)))
#define MAP_BASE(m)			((m) << 8)

#define BG_PRIORITY(m)		((m))
#define CHAR_PALETTE(m)		((m)<<12)

/*---------------------------------------------------------------------------------
	CHAR_BASE_ADR() is the direct equivalent to old PATRAM(),
	giving the base address of a chr bank.
	These macros pinpoint the base address of a single tile.
---------------------------------------------------------------------------------*/
#define PATRAM4(x, tn) ((u32 *)(VRAM | (((x) << 14) + ((tn) << 5)) ))
#define PATRAM8(x, tn) ((u32 *)(VRAM | (((x) << 14) + ((tn) << 6)) ))
#define SPR_VRAM(tn) ((u32 *)(VRAM | 0x10000 | ((tn) << 5)))

/*---------------------------------------------------------------------------------
	MAP_BASE_ADR() only gives the beginning of a map.
	Each cell of a text map can be accessed using 3D array notation:

	MAP[page][y][x]
---------------------------------------------------------------------------------*/
typedef u16 NAMETABLE[32][32];
#define MAP ((NAMETABLE *)0x06000000)

/*---------------------------------------------------------------------------------
	width and height of a GBA text map can (and probably should)
	be controlled separately.
---------------------------------------------------------------------------------*/
#define BG_WID_32 BG_SIZE_0
#define BG_WID_64 BG_SIZE_1
#define BG_HT_32  BG_SIZE_0
#define BG_HT_64  BG_SIZE_2
//---------------------------------------------------------------------------------
// Symbolic names for the rot/scale map sizes
//---------------------------------------------------------------------------------
#define ROTBG_SIZE_16  BG_SIZE_0
#define ROTBG_SIZE_32  BG_SIZE_1
#define ROTBG_SIZE_64  BG_SIZE_2
#define ROTBG_SIZE_128 BG_SIZE_3

#define TEXTBG_SIZE_256x256    BG_SIZE_0
#define TEXTBG_SIZE_512x256    BG_SIZE_1
#define TEXTBG_SIZE_256x512    BG_SIZE_2
#define TEXTBG_SIZE_512x512    BG_SIZE_3

#define ROTBG_SIZE_128x128    BG_SIZE_0
#define ROTBG_SIZE_256x256    BG_SIZE_1
#define ROTBG_SIZE_512x512    BG_SIZE_2
#define ROTBG_SIZE_1024x1024  BG_SIZE_3

//---------------------------------------------------------------------------------
// Framebuffers for mode 3 and 5
//---------------------------------------------------------------------------------
typedef u16 MODE3_LINE[240];
typedef u16 MODE5_LINE[160];

#define MODE3_FB ((MODE3_LINE *)0x06000000)
#define MODE5_FB ((MODE5_LINE *)0x06000000)
#define MODE5_BB ((MODE5_LINE *)0x0600A000)

#define	REG_WIN0H	*((vu16 *)(REG_BASE + 0x40))
#define	REG_WIN1H	*((vu16 *)(REG_BASE + 0x42))
#define	REG_WIN0V	*((vu16 *)(REG_BASE + 0x44))
#define	REG_WIN1V	*((vu16 *)(REG_BASE + 0x46))
#define	REG_WININ	*((vu16 *)(REG_BASE + 0x48))
#define	REG_WINOUT	*((vu16 *)(REG_BASE + 0x4A))

#define	REG_MOSAIC	*(vu16 *)(REG_BASE + 0x4c)

#define	REG_BLDCNT		*((vu16 *)(REG_BASE + 0x50))
#define	REG_BLDALPHA	*((vu16 *)(REG_BASE + 0x52))
#define	REG_BLDY		*((vu16 *)(REG_BASE + 0x54))

//---------------------------------------------------------------------------------
// Helper macros
//---------------------------------------------------------------------------------
static inline void SetMode(int mode)	{REG_DISPCNT = mode;}

#define RGB5(r,g,b)	((r)|((g)<<5)|((b)<<10))
#define RGB8(r,g,b)	( (((b)>>3)<<10) | (((g)>>3)<<5) | ((r)>>3) )


#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160

//---------------------------------------------------------------------------------
#endif // _gba_video_h_
//---------------------------------------------------------------------------------
