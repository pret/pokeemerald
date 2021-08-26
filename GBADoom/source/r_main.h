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
 *      Renderer main interface.
 *
 *-----------------------------------------------------------------------------*/

#ifndef __R_MAIN__
#define __R_MAIN__

#include "d_player.h"
#include "r_data.h"

#ifdef __GNUG__
#pragma interface
#endif

//
// Lighting LUT.
// Used for z-depth cuing per column/row,
//  and other lighting effects (sector ambient, flash).
//

// Lighting constants.

#define LIGHTLEVELS       16
#define LIGHTSEGSHIFT      4
#define MAXLIGHTSCALE     48
#define LIGHTSCALESHIFT   12
#define MAXLIGHTZ        128
#define LIGHTZSHIFT       20

// Number of diminishing brightness levels.
// There a 0-31, i.e. 32 LUT in the COLORMAP lump.

#define NUMCOLORMAPS 32

extern const int viewheight;

extern const int centery;

extern const fixed_t projection;
extern const fixed_t iprojection;



//Global vars.

extern int numnodes;
extern const mapnode_t *nodes;

extern fixed_t  viewx, viewy, viewz;

extern angle_t  viewangle;

extern short *floorclip, *ceilingclip;

extern const lighttable_t *fullcolormap;
extern const lighttable_t *colormaps;
extern const lighttable_t* fixedcolormap;

extern int extralight;                           // bumped light from gun blasts

extern const texture_t **textures; // proff - 04/05/2000 removed static for OpenGL
extern fixed_t   *textureheight; //needed for texture pegging (and TFE fix - killough)

extern short       *flattranslation;             // for global animation
extern short       *texturetranslation;

extern fixed_t basexscale, baseyscale;

extern fixed_t  viewcos, viewsin;

//
// Utility functions.
//

angle_t R_PointToAngle2(fixed_t x1, fixed_t y1, fixed_t x2, fixed_t y2);
subsector_t *R_PointInSubsector(fixed_t x, fixed_t y);

//
// REFRESH - the actual rendering functions.
//

void R_RenderPlayerView(player_t *player);   // Called by G_Drawer.
void R_Init(void);                           // Called by startup code.
void R_SetupFrame (player_t *player);


#endif
