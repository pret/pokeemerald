/*

	Header file for libgba xboo cable functions

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
#ifndef	_xcomms_h_
#define	_xcomms_h_
//---------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//---------------------------------------------------------------------------------

#include "gba_types.h"

//---------------------------------------------------------------------------------
// Don't Use these function names
//---------------------------------------------------------------------------------
void	xcomms_dprintf	(char *str, ...);
void	xcomms_dfprintf	(int handle, char *str, ...);
void	xcomms_dputchar	(int c);

u8		xcomms_dfopen	(const char *file, const char *type);
void	xcomms_dfclose	(int handle);
u8		xcomms_dfgetc	(int handle);
void	xcomms_dfputc	(int ch, int handle);

void	xcomms_fread	( void *buffer, u32 size, u32 count, int handle );
void	xcomms_fwrite	( void *buffer, u32 size, u32 count, int handle );
void	xcomms_drewind	(int handle);

void 	xcomms_fseek	( int handle, u32 offset, int origin );
u32		xcomms_ftell	( int handle );


void	xcomms_send(u32 data);
void	xcomms_sendblock(const void *block, int len);

int		xcomms_getch	(void);
int		xcomms_kbhit	(void);

void	xcomms_init();

//---------------------------------------------------------------------------------
// Use these function names instead
// these will be repeated for VBA & MBV2
//---------------------------------------------------------------------------------
#define dprintf		xcomms_dprintf
#define dfprintf	xcomms_dfprintf
#define dputchar	xcomms_dputchar

#define dfopen		xcomms_dfopen
#define dfseek		xcomms_fseek
#define dfread		xcomms_fread
#define dfwrite		xcomms_fwrite
#define dftell		xcomms_ftell
#define dfclose		xcomms_dfclose
#define dfgetc		xcomms_dfgetc
#define dfputc		xcomms_dfputc
#define drewind		xcomms_drewind

#define dgetch		xcomms_getch
#define dkbhit		xcomms_kbhit

//---------------------------------------------------------------------------------
#ifdef __cplusplus
}	   // extern "C"
#endif
//---------------------------------------------------------------------------------
#endif // _xcomms_h
