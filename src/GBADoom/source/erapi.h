/*

	Header file for libgba Ereader API definitions

	Copyright 2003-2004 by FireFly.

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
#ifndef	_erapi_h_
#define	_erapi_h_
//---------------------------------------------------------------------------------

#include "gba_types.h"

#define	ERAPI_KEY_A			0x0001
#define	ERAPI_KEY_B			0x0002
#define	ERAPI_KEY_SELECT	0x0004
#define	ERAPI_KEY_START		0x0008
#define	ERAPI_KEY_RIGHT		0x0010
#define	ERAPI_KEY_LEFT		0x0020
#define	ERAPI_KEY_UP		0x0040
#define	ERAPI_KEY_DOWN		0x0080
#define	ERAPI_KEY_R			0x0100
#define	ERAPI_KEY_L			0x0200

#define	ERAPI_RAM_START		0x02000000
#define	ERAPI_RAM_END		0x02027800

#define	ERAPI_EXIT_RESTART	0
#define	ERAPI_EXIT_TO_MENU	2

typedef	u32	(*FUNC_U32_X1)(	u32	r0);
typedef	u32	(*FUNC_U32_X2)(	u32	r0,	u32	r1);
typedef	u32	(*FUNC_U32_X3)(	u32	r0,	u32	r1,	u32	r2);
typedef	u32	(*FUNC_U32_X4)(	u32	r0,	u32	r1,	u32	r2,	u32	r3);
typedef	u32	(*FUNC_U32_X5)(	u32	r0,	u32	r1,	u32	r2,	u32	r3,	u32	r4);
typedef	u32	(*FUNC_U32_X6)(	u32	r0,	u32	r1,	u32	r2,	u32	r3,	u32	r4,	u32	r5);

#define	ERAPI_FUNC_X1 ((FUNC_U32_X1)*(u32*)0x030075FC)
#define	ERAPI_FUNC_X2 ((FUNC_U32_X2)*(u32*)0x030075FC)
#define	ERAPI_FUNC_X3 ((FUNC_U32_X3)*(u32*)0x030075FC)
#define	ERAPI_FUNC_X4 ((FUNC_U32_X4)*(u32*)0x030075FC)
#define	ERAPI_FUNC_X5 ((FUNC_U32_X5)*(u32*)0x030075FC)
#define	ERAPI_FUNC_X6 ((FUNC_U32_X6)*(u32*)0x030075FC)

typedef	u8 ERAPI_HANDLE_REGION;
typedef	u16	ERAPI_HANDLE_SPRITE;

typedef	struct _ERAPI_SPRITE ERAPI_SPRITE;
struct _ERAPI_SPRITE
{
	u8*	data_gfx;	// ....	.... .... .... ....
	u8*	data_pal;	// ....	.... .... .... ....
	u8 width;		// 0x08	0x06 0x06 0x02 0x04
	u8 height;		// 0x08	0x06 0x02 0x02 0x04
	u8 frames;		// 0x04	0x04 0x02 0x02 0x04
	u8 unk1;		// 0x01	0x01 0x01 0x01 0x01
	u8 unk2;		// 0x08	0x00 0x00 0x00 0x00
	u8 unk3;		// 0x08	0x00 0x00 0x00 0x00
	u8 unk4;		// 0x03	0x04 0x02 0x02 0x04
};

typedef	struct _ERAPI_BACKGROUND ERAPI_BACKGROUND;
struct _ERAPI_BACKGROUND
{
	u8* data_gfx;
	u8* data_pal;
	u8* data_map;
	u16 tiles;
	u16 palettes;
};

//---------------------------------------------------------------------------------
#ifndef	ERAPI_STUB
//---------------------------------------------------------------------------------
#define	ERAPI_Div(a,b)										ERAPI_FUNC_X3( 0x103, a, b)
#define	ERAPI_Mod(a,b)										ERAPI_FUNC_X3( 0x104, a, b)
#define	ERAPI_PlaySoundSystem(a)							ERAPI_FUNC_X2( 0x105, a)
#define	ERAPI_0106(a,b)										ERAPI_FUNC_X3( 0x106, a, b)
#define	ERAPI_Rand()										ERAPI_FUNC_X1( 0x107)
#define	ERAPI_SetSoundVolume(a,b)							ERAPI_FUNC_X3( 0x108, a, b)
#define	ERAPI_0109(a,b,c)									ERAPI_FUNC_X4( 0x109, a, b,	c)
#define	ERAPI_010A(a,b)										ERAPI_FUNC_X2( 0x10A, a, b)
#define	ERAPI_Set0400XXXX(a,b)								ERAPI_FUNC_X3( 0x10B, a, b)
#define	ERAPI_Get0400XXXX(a)								ERAPI_FUNC_X2( 0x10C, a)
#define	ERAPI_RandMax(a)									ERAPI_FUNC_X2( 0x112, a)
#define	ERAPI_SetSoundSpeed(a,b)							ERAPI_FUNC_X3( 0x113, a, b)
#define	ERAPI_SoundPause(a)									ERAPI_FUNC_X2( 0x116, a)
#define	ERAPI_SoundResume(a)								ERAPI_FUNC_X2( 0x117, a)
#define	ERAPI_PlaySoundSystemEx(a,b)						ERAPI_FUNC_X3( 0x118, a, b)
#define	ERAPI_IsSoundPlaying(a,b)							ERAPI_FUNC_X3( 0x119, a, b)
#define	ERAPI_GetExitCount()								ERAPI_FUNC_X1( 0x11D)
#define	ERAPI_PlaySoundCustom(a,b)							ERAPI_FUNC_X3( 0x12F, (u32)a, b)
#define	ERAPI_PlaySoundCustomEx(a,b,c)						ERAPI_FUNC_X4( 0x131, (u32)a, b, c)
#define	ERAPI_FadeIn(a)										ERAPI_FUNC_X2( 0x200, a)
#define	ERAPI_FadeOut(a)									ERAPI_FUNC_X2( 0x201, a)
#define	ERAPI_LoadBackgroundSystem(a,b)						ERAPI_FUNC_X3( 0x210, b, a)
#define	ERAPI_SetBackgroundOffset(a,b,c)					ERAPI_FUNC_X4( 0x211, a, b,	c)
#define	ERAPI_SetBackgroundAutoScroll(a,b,c)				ERAPI_FUNC_X4( 0x212, a, b,	c)
#define	ERAPI_SetBackgroundMirrorToggle(a,b)				ERAPI_FUNC_X3( 0x213, a, b)
#define	ERAPI_SetBackgroundMode(a)							ERAPI_FUNC_X2( 0x219, a)
#define	ERAPI_LayerShow(a)									ERAPI_FUNC_X2( 0x220, a)
#define	ERAPI_LayerHide(a)									ERAPI_FUNC_X2( 0x221, a)
#define	ERAPI_LoadBackgroundCustom(a,b)						ERAPI_FUNC_X3( 0x22D, a, (u32)b)
#define	ERAPI_SpriteCreateSystem(a,b)						ERAPI_FUNC_X3( 0x230, a, b)
#define	ERAPI_SpriteFree(a)									ERAPI_FUNC_X2( 0x231, a)
#define	ERAPI_SetSpritePos(a,b,c)							ERAPI_FUNC_X4( 0x232, a, b,	c)
#define	ERAPI_SpriteFrameNext(a)							ERAPI_FUNC_X2( 0x234, a)
#define	ERAPI_SpriteFramePrev(a)							ERAPI_FUNC_X2( 0x235, a)
#define	ERAPI_SetSpriteFrame(a,b)							ERAPI_FUNC_X3( 0x236, a, b)
#define	ERAPI_SetSpriteAutoMove(a,b,c)						ERAPI_FUNC_X4( 0x239, a, b,	c)
#define	ERAPI_SpriteAutoAnimate(a,b,c)						ERAPI_FUNC_X4( 0x23C, a, b,	c)
#define	ERAPI_SpriteAutoRotateUntilAngle(a,b,c)				ERAPI_FUNC_X4( 0x23E, a, b,	c)
#define	ERAPI_SpriteAutoRotateByAngle(a,b,c)				ERAPI_FUNC_X4( 0x23F, a, b,	c)
#define	ERAPI_SpriteAutoRotateByTime(a,b,c)					ERAPI_FUNC_X4( 0x240, a, b,	c)
#define	ERAPI_SetSpriteAutoMoveHorizontal(a,b)				ERAPI_FUNC_X3( 0x242, a, b)
#define	ERAPI_SetSpriteAutoMoveVertical(a,b)				ERAPI_FUNC_X3( 0x243, a, b)
#define	ERAPI_SpriteDrawOnBackground(a,b,c)					ERAPI_FUNC_X4( 0x245, a, b,	c)
#define	ERAPI_SpriteShow(a)									ERAPI_FUNC_X2( 0x246, a)
#define	ERAPI_SpriteHide(a)									ERAPI_FUNC_X2( 0x247, a)
#define	ERAPI_SpriteMirrorToggle(a,b)						ERAPI_FUNC_X3( 0x248, a, b)
#define	ERAPI_GetSpritePos(a,b,c)							ERAPI_FUNC_X4( 0x24C, a, (u32)b, (u32)c)
#define	ERAPI_SpriteCreateCustom(a,b)						ERAPI_FUNC_X3( 0x24D, a, (u32)b)
#define	ERAPI_SpriteMove(a,b,c)								ERAPI_FUNC_X4( 0x257, a, b,	c)
#define	ERAPI_SpriteAutoScaleUntilSize(a,b,c)				ERAPI_FUNC_X4( 0x25B, a, b,	c)
#define	ERAPI_SpriteAutoScaleBySize(a,b,c)					ERAPI_FUNC_X4( 0x25C, a, b,	c)
#define	ERAPI_HANDLE_SpriteAutoScaleWidthUntilSize(a,b,c)	ERAPI_FUNC_X4( 0x25D, a, b,	c)
#define	ERAPI_SpriteAutoScaleHeightBySize(a,b,c)			ERAPI_FUNC_X4( 0x25E, a, b,	c)
#define	ERAPI_SetSpriteVisible(a,b)							ERAPI_FUNC_X3( 0x266, a, b)
#define	ERAPI_SetBackgroundPalette(a,b,c)					ERAPI_FUNC_X4( 0x27E, (u32)a, b, c)
#define	ERAPI_GetBackgroundPalette(a,b,c)					ERAPI_FUNC_X4( 0x27F, (u32)a, b, c)
#define	ERAPI_SetSpritePalette(a,b,c)						ERAPI_FUNC_X4( 0x280, a, b,	c)
#define	ERAPI_GetSpritePalette(a,b,c)						ERAPI_FUNC_X4( 0x281, (u32)a, b, c)
#define	ERAPI_ClearPalette()								ERAPI_FUNC_X1( 0x282)
#define	ERAPI_CreateRegion(a,b,c,d,e,f)						ERAPI_FUNC_X4( 0x290, (a <<	8) | b,	(c << 8) | d, (e <<	8) | f)
#define	ERAPI_SetRegionColor(a,b)							ERAPI_FUNC_X3( 0x291, a, b)
#define	ERAPI_ClearRegion(a)								ERAPI_FUNC_X2( 0x292, a)
#define	ERAPI_SetPixel(a,b,c)								ERAPI_FUNC_X3( 0x293, a, (b	<< 8) |	c)
#define	ERAPI_GetPixel(a,b,c)								ERAPI_FUNC_X3( 0x294, a, (b	<< 8) |	c)
#define	ERAPI_DrawLine(a,b,c,d,e)							ERAPI_FUNC_X4( 0x295, a, (b	<< 8) |	c, (d << 8)	| e)
#define	ERAPI_DrawRect(a,b,c,d,e,f)							ERAPI_FUNC_X4( 0x296, (a <<	8) | f,	(b << 8) | c, (d <<	8) | e)
#define	ERAPI_SetTextColor(a,b,c)							ERAPI_FUNC_X3( 0x298, a, (b	<< 8) |	c)
#define	ERAPI_DrawText(a,b,c,d)								ERAPI_FUNC_X4( 0x299, a, (b	<< 8) |	c, (u32)d)
#define	ERAPI_SetTextSize(a,b)								ERAPI_FUNC_X2( 0x29A, (a <<	8) | b)
#define	ERAPI_SetBackgroundModeRaw(a)						ERAPI_FUNC_X2( 0x29F, (u32)a)
#define	ERAPI_02B5(a,b)										ERAPI_FUNC_X3( 0x2B5, a, b)
#define	ERAPI_GetTextWidth(a,b)								ERAPI_FUNC_X3( 0x2C0, a, (u32)b)
#define	ERAPI_GetTextWidthEx(a,b,c)							ERAPI_FUNC_X3( 0x2C1, (a <<	8) | c,	(u32)b)
#define	ERAPI_02C2(a)										ERAPI_FUNC_X2( 0x2C2, (u32)a)
#define	ERAPI_02C3(a)										ERAPI_FUNC_X2( 0x2C3, a)
#define	ERAPI_02DD(a,b)										ERAPI_FUNC_X3( 0x2DD, a, b)
#define	ERAPI_FlashWriteSectorSingle(a,b)					ERAPI_FUNC_X3( 0x2DE, a, (u32)b)
#define	ERAPI_FlashReadSectorSingle(a,b)					ERAPI_FUNC_X3( 0x2DF, a, (u32)b)
#define	ERAPI_SoftReset()									ERAPI_FUNC_X1( 0x2E0)
#define	ERAPI_InitMemory(a)									ERAPI_FUNC_X2( 0x2EA, a)
#define	ERAPI_FlashWriteSectorMulti(a,b,c)					ERAPI_FUNC_X4( 0x2ED, a, b,	c)
#define	ERAPI_FlashReadPart(a,b,c)							ERAPI_FUNC_X4( 0x2EE, a, (u32)b, c)
#define	ERAPI_RandInit(a)									ERAPI_FUNC_X2( 0x2F1, a)
#define	ERAPI_RenderFrame(a)								ERAPI_FUNC_X2( 0x300, a)
#define	ERAPI_GetKeyStateSticky()							ERAPI_FUNC_X1( 0x301)
#define	ERAPI_GetKeyStateRaw()								ERAPI_FUNC_X1( 0x302)


//---------------------------------------------------------------------------------
#endif // ERAPI_STUB
//---------------------------------------------------------------------------------


//---------------------------------------------------------------------------------
#endif // _erapi_h_
//---------------------------------------------------------------------------------



