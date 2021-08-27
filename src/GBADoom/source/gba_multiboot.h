/*

	Header file for libgba multiboot definitions

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
#ifndef	_gba_multiboot_h_
#define	_gba_multiboot_h_
//---------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif
//---------------------------------------------------------------------------------

#include "gba_base.h"

typedef	struct {
	u32	reserved1[5];
	u8	handshake_data;
	u8	padding;
	u16	handshake_timeout;
	u8	probe_count;
	u8	client_data[3];
	u8	palette_data;
	u8	response_bit;
	u8	client_bit;
	u8	reserved2;
	u8	*boot_srcp;
	u8	*boot_endp;
	u8	*masterp;
	u8	*reserved3[3];
	u32	system_work2[4];
	u8	sendflag;
	u8	probe_target_bit;
	u8	check_wait;
	u8	server_type;
} MultiBootParam;

enum MULTIBOOT_MODES { MODE32_NORMAL, MODE16_MULTI, MODE32_2MHZ};

u32 MultiBoot(MultiBootParam *mp, u32 mode);


//---------------------------------------------------------------------------------
#ifdef __cplusplus
}	   // extern "C"
#endif
//---------------------------------------------------------------------------------
#endif //_gba_multiboot_h_
