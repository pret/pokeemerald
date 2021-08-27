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
 *      System specific interface stuff.
 *
 *-----------------------------------------------------------------------------*/

#ifndef __R_DRAW__
#define __R_DRAW__

#include "r_defs.h"

#ifdef __GNUG__
#pragma interface
#endif


// Packaged into a struct - POPE
typedef struct {
  int                 x;
  int                 yl;
  int                 yh;
  fixed_t             iscale;
  fixed_t             texturemid;

  const byte          *source; // first pixel in a column

  const lighttable_t  *colormap;
  const byte          *translation;

} draw_column_vars_t;

void R_SetDefaultDrawColumnVars(draw_column_vars_t *dcvars);

typedef struct {
  unsigned int        position;
  unsigned int        step;
  const byte          *source; // start of a 64*64 tile image
  const lighttable_t  *colormap;
} draw_span_vars_t;

typedef struct
{
  unsigned short *byte_topleft;
} draw_vars_t;

extern draw_vars_t drawvars;


typedef void (*R_DrawColumn_f)(const draw_column_vars_t *dcvars);

// Draw with color translation tables,
//  for player sprite rendering,
//  Green/Red/Blue/Indigo shirts.
void	R_DrawTranslatedColumn (const draw_column_vars_t *dcvars);

void R_InitBuffer();




#endif
