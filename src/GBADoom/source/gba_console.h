/*
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
#ifndef _gba_console_h_
#define _gba_console_h_
//---------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//---------------------------------------------------------------------------------
#include "gba_base.h"

// Make console interaction a little less eye-crossing
#define CON_CLS()		"\033[2J"
#define CON_POS(_x, _y) "\033[" #_y ";" #_x "H"
#define CON_UP(_dy)		"\033[" #_dy "A"
#define CON_DOWN(_dy)	"\033[" #_dy "B"
#define CON_RIGHT(_dx)	"\033[" #_dx "C"
#define CON_LEFT(_dx)	"\033[" #_dx "D"
#define CON_ERASE()		"\033[K"			
#define CON_CLL(_y)		CON_POS(1,_y) CON_ERASE()

void consoleInit(	int charBase, int mapBase, int background,
					const u8* font, int fontsize, int palette);

void consoleDemoInit();
				
//---------------------------------------------------------------------------------
#ifdef __cplusplus
}	   // extern "C"
#endif
//---------------------------------------------------------------------------------
#endif // _gba_console_h_
//---------------------------------------------------------------------------------
