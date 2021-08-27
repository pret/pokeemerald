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
 *  Block memory allocator
 *  This is designed to be a fast allocator for small, regularly used block sizes
 *-----------------------------------------------------------------------------*/

struct block_memory_alloc_s {
  void  *firstpool;
  size_t size;
  size_t perpool;
  int    tag;
  const char *desc;
};

#define DECLARE_BLOCK_MEMORY_ALLOC_ZONE(name) extern struct block_memory_alloc_s name
#define IMPLEMENT_BLOCK_MEMORY_ALLOC_ZONE(name, size, tag, num, desc) \
struct block_memory_alloc_s name = { NULL, size, num, tag, desc}
#define NULL_BLOCK_MEMORY_ALLOC_ZONE(name) name.firstpool = NULL

void* Z_BMalloc(struct block_memory_alloc_s *pzone);

__inline static void* Z_BCalloc(struct block_memory_alloc_s *pzone)
{ void *p = Z_BMalloc(pzone); memset(p,0,pzone->size); return p; }

void Z_BFree(struct block_memory_alloc_s *pzone, void* p);
