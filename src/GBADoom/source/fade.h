/*

	Header file for libgba palette fade routines

	Copyright 2003-2004 by Dave Murphy.

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

/*! \file fade.h
    \brief gba palette fading.

*/

//---------------------------------------------------------------------------------
#ifndef _fade_h_
#define _fade_h_
//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//---------------------------------------------------------------------------------

/*! \fn void FadeToPalette(const u16 *NewPalette, int FrameCount)
	\brief fade from the current palette to a preset palette.
	\param NewPalette
	\param FrameCount
    
*/
void	FadeToPalette(const u16 *NewPalette, int FrameCount);

/*! \fn void FadeToGrayScale(int gray, int FrameCount)
	\brief fade from the current palette to a preset palette.
	\param gray
	\param FrameCount
    
*/
void	FadeToGrayScale(int gray, int FrameCount);
/*!	\fn void SetPalette(u16 *Palette)
	\brief Set the current Palette directly
	\param Palette

*/
void	SetPalette(u16 *Palette);

static inline void FadeToBlack(int frames) { FadeToGrayScale(0,frames); }

//---------------------------------------------------------------------------------
#ifdef __cplusplus
}	   // extern "C"
#endif
//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------
#endif // _fade_h_
//---------------------------------------------------------------------------------
