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
 *      Map utility functions
 *
 *-----------------------------------------------------------------------------*/

#ifndef __P_MAPUTL__
#define __P_MAPUTL__

#include "r_defs.h"

/* mapblocks are used to check movement against lines and things */
#define MAPBLOCKUNITS   128
#define MAPBLOCKSIZE    (MAPBLOCKUNITS*FRACUNIT)
#define MAPBLOCKSHIFT   (FRACBITS+7)
#define MAPBMASK        (MAPBLOCKSIZE-1)
#define MAPBTOFRAC      (MAPBLOCKSHIFT-FRACBITS)

#define PT_ADDLINES     1
#define PT_ADDTHINGS    2
#define PT_EARLYOUT     4

#define MAXINTERCEPTS 64

typedef struct
{
  fixed_t     x;
  fixed_t     y;
  fixed_t     dx;
  fixed_t     dy;
} divline_t;

typedef struct {
  fixed_t     frac;           /* along trace line */
  boolean     isaline;
  union
  {
    mobj_t* thing;
    const line_t* line;
  } d;
} intercept_t;

typedef struct {
  fixed_t sightzstart, t2x, t2y;   // eye z of looker
  divline_t strace;                // from t1 to t2
  fixed_t topslope, bottomslope;   // slopes to top and bottom of target
  fixed_t bbox[4];
  fixed_t maxz,minz;               // cph - z optimisations for 2sided lines
} los_t;

typedef boolean (*traverser_t)(intercept_t *in);

fixed_t CONSTFUNC P_AproxDistance (fixed_t dx, fixed_t dy);
int     P_PointOnLineSide (fixed_t x, fixed_t y, const line_t *line);
int     P_BoxOnLineSide (const fixed_t *tmbox, const line_t *ld);
/* cph - old compatibility version below */
fixed_t P_InterceptVector2(const divline_t *v2, const divline_t *v1);

void    P_LineOpening (const line_t *linedef);
void    P_UnsetThingPosition(mobj_t *thing);
void    P_SetThingPosition(mobj_t *thing);
boolean P_BlockLinesIterator (int x, int y, boolean func(const line_t *));
boolean P_BlockThingsIterator(int x, int y, boolean func(mobj_t *));
boolean P_PathTraverse(fixed_t x1, fixed_t y1, fixed_t x2, fixed_t y2,
                       int flags, boolean trav(intercept_t *));

#endif  /* __P_MAPUTL__ */
