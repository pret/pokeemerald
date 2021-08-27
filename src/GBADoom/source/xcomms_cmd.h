/*

	Header file for libgba Xboo Communicator commands

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
#ifndef _xcomms_cmd_h_
#define _xcomms_cmd_h_
//---------------------------------------------------------------------------------

#define PRINT_CMD	('PRT'<<8)
#define DPUTC_CMD	('DPT'<<8)

#define FOPEN_CMD	('OPN'<<8)
#define FCLOSE_CMD	('CLS'<<8)

#define FREAD_CMD	('FRD'<<8)
#define FWRITE_CMD	('FWR'<<8)

#define FSEEK_CMD	('FSK'<<8)
#define REWIND_CMD	('RWD'<<8)
#define FTELL_CMD	('FTL'<<8)

#define FGETC_CMD	('FGT'<<8)
#define FPUTC_CMD	('FPT'<<8)

#define GETCH_CMD	('GTC'<<8)
#define KBHIT_CMD	('KBH'<<8)

//---------------------------------------------------------------------------------
#endif //_xcomms_cmd_h_
//---------------------------------------------------------------------------------
