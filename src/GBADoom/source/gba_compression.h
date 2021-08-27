/*

	Header file for libgba bios compression functions

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
#ifndef	_gba_compression_h_
#define	_gba_compression_h_
//---------------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

#include "gba_base.h"

typedef struct {
	u16 SrcNum;				// Source Data Byte Size
	u8  SrcBitNum;			// 1 Source Data Bit Number
	u8  DestBitNum;			// 1 Destination Data Bit Number
	u32 DestOffset:31;		// Number added to Source Data
	u32 DestOffset0_On:1;	// Flag to add/not add Offset to 0 Data
} BUP;


//---------------------------------------------------------------------------------
// Decompression functions
//---------------------------------------------------------------------------------
void BitUnPack(const void  *source, void *dest, BUP* bup);
void LZ77UnCompWram(const void *source, void *dest);
void LZ77UnCompVram(const void *source, void *dest);
void HuffUnComp(const void *source, void *dest);
void RLUnCompWram(const void *source, void *dest);
void RLUnCompVram(const void *source, void *dest);
void Diff8bitUnFilterWram(const void *source, void *dest);
void Diff8bitUnFilterVram(const void *source, void *dest);
void Diff16bitUnFilter(const void *source, void *dest);

//---------------------------------------------------------------------------------
#ifdef __cplusplus
}	   // extern "C"
#endif

//---------------------------------------------------------------------------------
#endif //_gba_compression_h_
