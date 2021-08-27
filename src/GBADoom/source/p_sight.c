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
 *      LineOfSight/Visibility checks, uses REJECT Lookup Table.
 *
 *-----------------------------------------------------------------------------*/

#include "doomstat.h"
#include "r_main.h"
#include "p_map.h"
#include "p_maputl.h"
#include "p_setup.h"
#include "m_bbox.h"
#include "lprintf.h"

#include "global_data.h"


//
// P_CheckSight
// Returns true
//  if a straight line between t1 and t2 is unobstructed.
// Uses REJECT.
//
// killough 4/20/98: cleaned up, made to use new LOS struct

boolean P_CrossBSPNode(int bspnum);



boolean P_CheckSight(mobj_t *t1, mobj_t *t2)
{
  const sector_t *s1 = t1->subsector->sector;
  const sector_t *s2 = t2->subsector->sector;
  int pnum = (s1-_g->sectors)*_g->numsectors + (s2-_g->sectors);

  // First check for trivial rejection.
  // Determine subsector entries in REJECT table.
  //
  // Check in REJECT table.

  if (_g->rejectmatrix[pnum>>3] & (1 << (pnum&7)))   // can't possibly be connected
    return false;

  /* killough 11/98: shortcut for melee situations
   * same subsector? obviously visible
   * cph - compatibility optioned for demo sync, cf HR06-UV.LMP */
  if (t1->subsector == t2->subsector)
    return true;

  // An unobstructed LOS is possible.
  // Now look from eyes of t1 to any part of t2.

  _g->validcount++;

  _g->los.topslope = (_g->los.bottomslope = t2->z - (_g->los.sightzstart =
                                             t1->z + t1->height -
                                             (t1->height>>2))) + t2->height;
  _g->los.strace.dx = (_g->los.t2x = t2->x) - (_g->los.strace.x = t1->x);
  _g->los.strace.dy = (_g->los.t2y = t2->y) - (_g->los.strace.y = t1->y);

  if (t1->x > t2->x)
    _g->los.bbox[BOXRIGHT] = t1->x, _g->los.bbox[BOXLEFT] = t2->x;
  else
    _g->los.bbox[BOXRIGHT] = t2->x, _g->los.bbox[BOXLEFT] = t1->x;

  if (t1->y > t2->y)
    _g->los.bbox[BOXTOP] = t1->y, _g->los.bbox[BOXBOTTOM] = t2->y;
  else
    _g->los.bbox[BOXTOP] = t2->y, _g->los.bbox[BOXBOTTOM] = t1->y;


    _g->los.maxz = INT_MAX; _g->los.minz = INT_MIN;

  // the head node is the last node output
  return P_CrossBSPNode(numnodes-1);
}
