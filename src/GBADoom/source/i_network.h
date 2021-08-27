/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2000 by
 *  Jess Haas, Nicolas Kalkhof, Colin Phipps, Florian Schulze
 *  Copyright 2005, 2006 by
 *  Florian Schulze, Colin Phipps, Neil Stevens, Andrey Budko
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *  Low level network interface.
 *-----------------------------------------------------------------------------*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#define UDP_CHANNEL struct sockaddr

#ifndef IPPORT_RESERVED
        #define IPPORT_RESERVED 1024
#endif

void I_InitNetwork(void);
size_t I_GetPacket(packet_header_t* buffer, size_t buflen);
void I_SendPacket(packet_header_t* packet, size_t len);
void I_WaitForPacket(int ms);

#ifdef AF_INET
void I_SendPacketTo(packet_header_t* packet, size_t len, UDP_CHANNEL *to);
void I_SetupSocket(int sock, int port, int family);
void I_PrintAddress(FILE* fp, UDP_CHANNEL *addr);

extern UDP_CHANNEL sentfrom;
extern int v4socket, v6socket;
#endif

extern size_t sentbytes, recvdbytes;
