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
 *      WAD I/O functions.
 *
 *-----------------------------------------------------------------------------*/


#ifndef __W_WAD__
#define __W_WAD__

#include "doomtype.h"

//
// TYPES
//

typedef struct
{
  char identification[4];                  // Should be "IWAD" or "PWAD".
  int  numlumps;
  int  infotableofs;
} wadinfo_t;

typedef struct
{
  int  filepos;
  int  size;
  char name[8];
} filelump_t;


// killough 4/17/98: if W_CheckNumForName() called with only
// one argument, pass ns_global as the default namespace

void W_Init(void); // CPhipps - uses the above array

int PUREFUNC W_CheckNumForName(const char* name);   // killough 4/17/98
int PUREFUNC W_GetNumForName (const char* name);
const char* PUREFUNC W_GetNameForNum(int lump);


int PUREFUNC W_LumpLength (int lump);

// CPhipps - modified for 'new' lump locking
const void* PUREFUNC W_CacheLumpNum (int lump);

// CPhipps - convenience macros
#define W_CacheLumpName(name) W_CacheLumpNum(W_GetNumForName(name))

void ExtractFileBase(const char *, char *);       // killough

#endif
