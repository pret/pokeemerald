/*

	Header file for libgba bios affine functions

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
#ifndef	_gba_affine_h_
#define	_gba_affine_h_
//---------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

#include "gba_base.h"

//---------------------------------------------------------------------------------
typedef struct t_BGAffineSource {
     s32 x;				/*!< Original data's center X coordinate (8bit fractional portion)			*/
     s32 y;				/*!< Original data's center Y coordinate (8bit fractional portion)			*/
     s16 tX;			/*!< Display's center X coordinate																			*/
     s16 tY;			/*!< Display's center Y coordinate																			*/
     s16 sX;			/*!< Scaling ratio in X direction (8bit fractional portion)							*/
     s16 sY;			/*!< Scaling ratio in Y direction (8bit fractional portion)							*/
     u16 theta;		/*!< Angle of rotation (8bit fractional portion) Effective Range 0-FFFF	*/
} BGAffineSource;

typedef struct t_BGAffineDest {
     s16 pa;		/*!< Difference in X coordinate along same line	*/
     s16 pb;		/*!< Difference in X coordinate along next line	*/
     s16 pc;		/*!< Difference in Y coordinate along same line	*/
     s16 pd;		/*!< Difference in Y coordinate along next line	*/
     s32 x;			/*!< Start X coordinate													*/
     s32 y;			/*!< Start Y coordinate													*/
} BGAffineDest;


typedef struct t_ObjAffineSource {
     s16 sX;			/*!< Scaling ratio in X direction (8bit fractional portion)							*/
     s16 sY;			/*!< Scaling ratio in Y direction (8bit fractional portion)							*/
     u16 theta;		/*!< Angle of rotation (8bit fractional portion) Effective Range 0-FFFF	*/
} ObjAffineSource;


typedef struct t_ObjAffineDest {
     s16 pa;		/*!< Difference in X coordinate along same line */
     s16 pb;		/*!< Difference in X coordinate along next line */
     s16 pc;		/*!< Difference in Y coordinate along same line */
     s16 pd;		/*!< Difference in Y coordinate along next line */
} ObjAffineDest;


void ObjAffineSet(ObjAffineSource *source, void *dest, s32 num, s32 offset);
void BgAffineSet(BGAffineSource *source, BGAffineDest *dest, s32 num);

//---------------------------------------------------------------------------------
#ifdef __cplusplus
}	   // extern "C"
#endif
//---------------------------------------------------------------------------------
#endif //_gba_affine_h
//---------------------------------------------------------------------------------
