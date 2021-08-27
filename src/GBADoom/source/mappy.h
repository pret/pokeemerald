/*

	Header file for libgba mappy debug functions

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

//---------------------------------------------------------------------------------
#ifndef	_mappy_h_
#define	_mappy_h_
//---------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//---------------------------------------------------------------------------------

#include "gba_types.h"

//---------------------------------------------------------------------------------
// Don't Use these function names
//---------------------------------------------------------------------------------
void	mappy_dprintf	(char *str, ...);
void	mappy_dputchar	(int c);

//---------------------------------------------------------------------------------
// Use these function names instead
// these will be repeated for Xcomms & MBV2
//---------------------------------------------------------------------------------
#define dprintf		mappy_dprintf
#define dputchar	mappy_dputchar

//---------------------------------------------------------------------------------
// Sorry no file stuff
//---------------------------------------------------------------------------------
#define dfprintf
#define dfopen
#define dfseek
#define dfread
#define dfwrite
#define dftell
#define dfclose
#define dfgetc
#define dfputc
#define drewind


//---------------------------------------------------------------------------------
#ifdef __cplusplus
}	   // extern "C"
#endif
//---------------------------------------------------------------------------------
#endif // _mappy_h
