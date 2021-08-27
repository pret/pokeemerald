/*

	Header file for libgba mbv2 functions

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
#ifndef	_mbv2_h_
#define	_mbv2_h_
//---------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//---------------------------------------------------------------------------------

//---------------------------------------------------------------------------------
// Don't Use these function names
//---------------------------------------------------------------------------------
void	mbv2_dprintf	(char *str, ...);
void	mbv2_dfprintf	(int fp, char *str, ...);
int		mbv2_dputchar	(int c);
int		mbv2_dgetch		(void);
int		mbv2_dkbhit		(void);

int		mbv2_dfopen		(const char *file, const char *type);
int		mbv2_dfclose	(int fp);
int		mbv2_dfgetc		(int fp);
int		mbv2_dfputc		(int ch, int fp);
void	mbv2_drewind	(int fp);

//---------------------------------------------------------------------------------
// Use these function names instead
// these will be repeated for VBA & Xcomms
//---------------------------------------------------------------------------------
#define dprintf		mbv2_dprintf
#define dfprintf	mbv2_dfprintf
#define dputchar	mbv2_dputchar
#define dgetch		mbv2_dgetch
#define dkbhit		mbv2_dkbhit

#define dfopen		mbv2_dfopen
#define dfclose		mbv2_dfclose
#define dfgetc		mbv2_dfgetc
#define dfputc		mbv2_dfputc
#define drewind		mbv2_drewind

#define __DOUTBUFSIZE	256
#define __FINBUFSIZE	256  //Must be a multiple of 2! (ex: 32,64,128,256,512..)
#define __KINBUFSIZE	64   //Must be a multiple of 2! (ex: 32,64,128,256,512..)
#define __ESCCHR		27

#define __ESC_NADA				0
#define __ESC_ESCCHR			1
#define __ESC_FOPEN				2
#define __ESC_FCLOSE			3
#define __ESC_FGETC				4
#define __ESC_FPUTC				5
#define __ESC_REWIND			6
#define __ESC_FPUTC_PROCESSED	7	// PC side add CR before LF if DOS machine
#define __ESC_KBDCHR 			8

int __dputchar (int c);

//---------------------------------------------------------------------------------
#ifdef __cplusplus
}	   // extern "C"
#endif
//---------------------------------------------------------------------------------
#endif // _mbv2_h
