/*

	Header file for libgba sprite definitions

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

*/

//---------------------------------------------------------------------------------
#ifndef _gba_sprites_h_
#define _gba_sprites_h_
//---------------------------------------------------------------------------------

#include "gba_base.h"

typedef struct {
	u16 attr0;
	u16 attr1;
	u16 attr2;
	u16 dummy;
} ALIGN(4) OBJATTR;

typedef struct {
	u16 attribute[3];
	u16 dummy;
} ALIGN(4) SpriteEntry;

typedef struct {
	u16 dummy0[3];
	s16 pa;
	u16 dummy1[3];
	s16 pb;
	u16 dummy2[3];
	s16 pc;
	u16 dummy3[3];
	s16 pd;
} ALIGN(4) OBJAFFINE;

typedef struct {
  /* Attribute 0 */
  u16 Y:8;
  u16 RotationScaling:1;
  u16 Disable:1;
  u16 Mode:2;
  u16 Mosaic:1;
  u16 ColorMode:1;
  u16 Shape:2;
  /* Attribute 1 */
  u16 X:9;
  u16 NotUsed:3;
  u16 HFlip:1;
  u16 VFlip:1;
  u16 Size:2;
  /* Attribute 2 */
  u16 Character:10;
  u16 Priority:2;
  u16 Palette:4;
  /* Attribute 3 */
  u16 dummy;
} ALIGN(4) Sprite;

typedef struct {
  /* Attribute 0 */
  u16 Y:8;
  u16 RotationScaling:1;
  u16 DoubleSize:1;
  u16 Mode:2;
  u16 Mosaic:1;
  u16 ColorMode:1;
  u16 Shape:2;
  /* Attribute 1 */
  u16 X:9;
  u16 Affine:5;
  u16 Size:2;
  /* Attribute 2 */
  u16 Character:10;
  u16 Priority:2;
  u16 Palette:4;
  /* Attribute 3 */
  u16 dummy;
} ALIGN(4) AffineSprite;


#define	OAM					((OBJATTR *)0x07000000)
#define OBJ_BASE_ADR		((void *)(VRAM + 0x10000))
#define SPRITE_GFX			((u16 *)(VRAM + 0x10000))
#define BITMAP_OBJ_BASE_ADR	((void *)(VRAM + 0x14000))

enum SPRITE_SHAPES {
	SQUARE,
	WIDE,
	TALL
};
#define OBJ_SHAPE(m)		((m)<<14)


// Sprite Attribute 0
#define OBJ_Y(m)			((m)&0x00ff)
#define OBJ_ROT_SCALE_ON	(1<<8)
#define OBJ_DISABLE			(1<<9)
#define OBJ_DOUBLE			(1<<9)
#define OBJ_MODE(m)			((m)<<10)
#define OBJ_MOSAIC			(1<<12)
#define	OBJ_256_COLOR		(1<<13)
#define	OBJ_16_COLOR		(0<<13)

#define ATTR0_MOSAIC			(1<<12)
#define ATTR0_COLOR_256			(1<<13)
#define ATTR0_COLOR_16			(0<<13)
#define ATTR0_TYPE_NORMAL		(0<<10)
#define ATTR0_TYPE_BLENDED		(1<<10)
#define ATTR0_TYPE_WINDOWED		(2<<10)
#define ATTR0_NORMAL			(0<<8)
#define ATTR0_ROTSCALE			(1<<8)
#define ATTR0_DISABLED			(2<<8)
#define ATTR0_ROTSCALE_DOUBLE	(3<<8)

#define ATTR0_SQUARE	OBJ_SHAPE(SQUARE)
#define ATTR0_WIDE		OBJ_SHAPE(WIDE)
#define ATTR0_TALL		OBJ_SHAPE(TALL)



// Sprite Attribute 1
#define OBJ_X(m)			((m)&0x01ff)
#define OBJ_ROT_SCALE(m)	((m)<<9)
#define OBJ_HFLIP			(1<<12)
#define OBJ_VFLIP			(1<<13)


#define ATTR1_ROTDATA(n)      ((n)<<9)  // note: overlaps with flip flags
#define ATTR1_FLIP_X          (1<<12)
#define ATTR1_FLIP_Y          (1<<13)
#define ATTR1_SIZE_8          (0<<14)
#define ATTR1_SIZE_16         (1<<14)
#define ATTR1_SIZE_32         (2<<14)
#define ATTR1_SIZE_64         (3<<14)



#define OBJ_SIZE(m)		((m)<<14)

// Sprite Attribute 2
#define OBJ_CHAR(m)		((m)&0x03ff)
#define OBJ_PRIORITY(m)	((m)<<10)
#define OBJ_PALETTE(m)	((m)<<12)

#define ATTR2_PRIORITY(n)     ((n)<<10)
#define ATTR2_PALETTE(n)      ((n)<<12)

#define OBJ_TRANSLUCENT	OBJ_MODE(1)
#define OBJ_OBJWINDOW	OBJ_MODE(2)
#define OBJ_SQUARE		OBJ_SHAPE(0)
#define OBJ_WIDE		OBJ_SHAPE(1)
#define OBJ_TALL		OBJ_SHAPE(2)

//---------------------------------------------------------------------------------
enum SPRITE_SIZECODE {
		Sprite_8x8,		// OBJ_SHAPE(0) OBJ_SIZE(0)
		Sprite_16x16,	// OBJ_SHAPE(0) OBJ_SIZE(1)
		Sprite_32x32,	// OBJ_SHAPE(0) OBJ_SIZE(2)
		Sprite_64x64,	// OBJ_SHAPE(0) OBJ_SIZE(3)
		Sprite_16x8,	// OBJ_SHAPE(1) OBJ_SIZE(0)
		Sprite_32x8,	// OBJ_SHAPE(1) OBJ_SIZE(1)
		Sprite_32x16,	// OBJ_SHAPE(1) OBJ_SIZE(2)
		Sprite_64x32,	// OBJ_SHAPE(1) OBJ_SIZE(3)
		Sprite_8x16,	// OBJ_SHAPE(2) OBJ_SIZE(0)
		Sprite_8x32,	// OBJ_SHAPE(2) OBJ_SIZE(1)
		Sprite_16x32,	// OBJ_SHAPE(2) OBJ_SIZE(2)
		Sprite_32x64	// OBJ_SHAPE(2) OBJ_SIZE(3)
};



//---------------------------------------------------------------------------------
#endif // _gba_sprites_h_
//---------------------------------------------------------------------------------
