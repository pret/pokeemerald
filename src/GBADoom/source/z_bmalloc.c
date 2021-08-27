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
 * This is designed to be a fast allocator for small, regularly used block sizes
 *-----------------------------------------------------------------------------
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "doomtype.h"
#include "z_zone.h"
#include "z_bmalloc.h"
#include "lprintf.h"

typedef struct bmalpool_s {
  struct bmalpool_s *nextpool;
  size_t             blocks;
  byte               used[0];
} bmalpool_t;

__inline static void* getelem(bmalpool_t *p, size_t size, size_t n)
{
  return (((byte*)p) + sizeof(bmalpool_t) + sizeof(byte)*(p->blocks) + size*n);
}

__inline static PUREFUNC int iselem(const bmalpool_t *pool, size_t size, const void* p)
{
  // CPhipps - need portable # of bytes between pointers
  int dif = (const char*)p - (const char*)pool;

  dif -= sizeof(bmalpool_t);
  dif -= pool->blocks;
  if (dif<0) return -1;
  dif /= size;
  return (((size_t)dif >= pool->blocks) ? -1 : dif);
}

enum { unused_block = 0, used_block = 1};

void* Z_BMalloc(struct block_memory_alloc_s *pzone)
{
  register bmalpool_t **pool = (bmalpool_t **)&(pzone->firstpool);
  while (*pool != NULL) {
    byte *p = memchr((*pool)->used, unused_block, (*pool)->blocks); // Scan for unused marker
    if (p) {
      int n = p - (*pool)->used;
      (*pool)->used[n] = used_block;
      return getelem(*pool, pzone->size, n);
    } else
      pool = &((*pool)->nextpool);
  }
  {
    // Nothing available, must allocate a new pool
    bmalpool_t *newpool;

    // CPhipps: Allocate new memory, initialised to 0

    *pool = newpool = Z_Calloc(sizeof(*newpool) + (sizeof(byte) + pzone->size)*(pzone->perpool),
             1,  pzone->tag, NULL);
    newpool->nextpool = NULL; // NULL = (void*)0 so this is redundant

    // Return element 0 from this pool to satisfy the request
    newpool->used[0] = used_block;
    newpool->blocks = pzone->perpool;
    return getelem(newpool, pzone->size, 0);
  }
}

void Z_BFree(struct block_memory_alloc_s *pzone, void* p)
{
  register bmalpool_t **pool = (bmalpool_t**)&(pzone->firstpool);

  while (*pool != NULL) {
    int n = iselem(*pool, pzone->size, p);
    if (n >= 0) {
      (*pool)->used[n] = unused_block;
      if (memchr(((*pool)->used), used_block, (*pool)->blocks) == NULL) {
  // Block is all unused, can be freed
  bmalpool_t *oldpool = *pool;
  *pool = (*pool)->nextpool;
  Z_Free(oldpool);
      }
      return;
    } else pool = &((*pool)->nextpool);
  }
  I_Error("Z_BFree: Free not in zone %s", pzone->desc);
}
