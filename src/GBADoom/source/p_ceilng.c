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
 *   Ceiling aninmation (lowering, crushing, raising)
 *
 *-----------------------------------------------------------------------------*/

#include "doomstat.h"
#include "r_main.h"
#include "p_spec.h"
#include "p_tick.h"
#include "s_sound.h"
#include "sounds.h"

#include "global_data.h"


/////////////////////////////////////////////////////////////////
//
// Ceiling action routine and linedef type handler
//
/////////////////////////////////////////////////////////////////

//
// T_MoveCeiling
//
// Action routine that moves ceilings. Called once per tick.
//
// Passed a ceiling_t structure that contains all the info about the move.
// see P_SPEC.H for fields. No return.
//
// jff 02/08/98 all cases with labels beginning with gen added to support
// generalized line type behaviors.
//
void T_MoveCeiling (ceiling_t* ceiling)
{
  result_e  res;

  switch(ceiling->direction)
  {
    case 0:
      // If ceiling in stasis, do nothing
      break;

    case 1:
      // Ceiling is moving up
      res = T_MovePlane
            (
              ceiling->sector,
              ceiling->speed,
              ceiling->topheight,
              false,
              1,
              ceiling->direction
            );

      // if not a silent crusher, make moving sound
      if (!(_g->leveltime&7))
      {
        switch(ceiling->type)
        {
          case silentCrushAndRaise:
          case genSilentCrusher:
            break;
          default:
            S_StartSound2(&ceiling->sector->soundorg,sfx_stnmov);
            break;
        }
      }

      // handle reaching destination height
      if (res == pastdest)
      {
        switch(ceiling->type)
        {
          // plain movers are just removed
          case raiseToHighest:
          case genCeiling:
            P_RemoveActiveCeiling(ceiling);
            break;

          // movers with texture change, change the texture then get removed
          case genCeilingChgT:
          case genCeilingChg0:
            ceiling->sector->special = ceiling->newspecial;
            //jff 3/14/98 transfer old special field as well
            ceiling->sector->oldspecial = ceiling->oldspecial;
          case genCeilingChg:
            ceiling->sector->ceilingpic = ceiling->texture;
            P_RemoveActiveCeiling(ceiling);
            break;

          // crushers reverse direction at the top
          case silentCrushAndRaise:
            S_StartSound2(&ceiling->sector->soundorg,sfx_pstop);
          case genSilentCrusher:
          case genCrusher:
          case fastCrushAndRaise:
          case crushAndRaise:
            ceiling->direction = -1;
            break;

          default:
            break;
        }
      }
      break;

    case -1:
      // Ceiling moving down
      res = T_MovePlane
            (
              ceiling->sector,
              ceiling->speed,
              ceiling->bottomheight,
              ceiling->crush,
              1,
              ceiling->direction
            );

      // if not silent crusher type make moving sound
      if (!(_g->leveltime&7))
      {
        switch(ceiling->type)
        {
          case silentCrushAndRaise:
          case genSilentCrusher:
            break;
          default:
            S_StartSound2(&ceiling->sector->soundorg,sfx_stnmov);
        }
      }

      // handle reaching destination height
      if (res == pastdest)
      {
        switch(ceiling->type)
        {
          // 02/09/98 jff change slow crushers' speed back to normal
          // start back up
          case genSilentCrusher:
          case genCrusher:
            if (ceiling->oldspeed<CEILSPEED*3)
              ceiling->speed = ceiling->oldspeed;
            ceiling->direction = 1; //jff 2/22/98 make it go back up!
            break;

          // make platform stop at bottom of all crusher strokes
          // except generalized ones, reset speed, start back up
          case silentCrushAndRaise:
            S_StartSound2(&ceiling->sector->soundorg,sfx_pstop);
          case crushAndRaise:
            ceiling->speed = CEILSPEED;
          case fastCrushAndRaise:
            ceiling->direction = 1;
            break;

          // in the case of ceiling mover/changer, change the texture
          // then remove the active ceiling
          case genCeilingChgT:
          case genCeilingChg0:
            ceiling->sector->special = ceiling->newspecial;
            //jff add to fix bug in special transfers from changes
            ceiling->sector->oldspecial = ceiling->oldspecial;
          case genCeilingChg:
            ceiling->sector->ceilingpic = ceiling->texture;
            P_RemoveActiveCeiling(ceiling);
            break;

          // all other case, just remove the active ceiling
          case lowerAndCrush:
          case lowerToFloor:
          case lowerToLowest:
          case lowerToMaxFloor:
          case genCeiling:
            P_RemoveActiveCeiling(ceiling);
            break;

          default:
            break;
        }
      }
      else // ( res != pastdest )
      {
        // handle the crusher encountering an obstacle
        if (res == crushed)
        {
          switch(ceiling->type)
          {
            //jff 02/08/98 slow down slow crushers on obstacle
            case genCrusher:
            case genSilentCrusher:
              if (ceiling->oldspeed < CEILSPEED*3)
                ceiling->speed = CEILSPEED / 8;
              break;
            case silentCrushAndRaise:
            case crushAndRaise:
            case lowerAndCrush:
                ceiling->speed = CEILSPEED / 8;
              break;

            default:
              break;
          }
        }
      }
      break;
  }
}


//
// EV_DoCeiling
//
// Move a ceiling up/down or start a crusher
//
// Passed the linedef activating the function and the type of function desired
// returns true if a thinker started
//
int EV_DoCeiling
( const line_t* line,
  ceiling_e type )
{
  int   secnum;
  int   rtn;
  sector_t* sec;
  ceiling_t*  ceiling;

  secnum = -1;
  rtn = 0;

  // Reactivate in-stasis ceilings...for certain types.
  // This restarts a crusher after it has been stopped
  switch(type)
  {
    case fastCrushAndRaise:
    case silentCrushAndRaise:
    case crushAndRaise:
      //jff 4/5/98 return if activated
      rtn = P_ActivateInStasisCeiling(line);
    default:
      break;
  }

  // affects all sectors with the same tag as the linedef
  while ((secnum = P_FindSectorFromLineTag(line,secnum)) >= 0)
  {
    sec = &_g->sectors[secnum];

    // if ceiling already moving, don't start a second function on it
    if (P_SectorActive(ceiling_special,sec))  //jff 2/22/98
      continue;

    // create a new ceiling thinker
    rtn = 1;
    ceiling = Z_Malloc (sizeof(*ceiling), PU_LEVSPEC, 0);
    memset(ceiling, 0, sizeof(*ceiling));
    P_AddThinker (&ceiling->thinker);
    sec->ceilingdata = ceiling;               //jff 2/22/98
    ceiling->thinker.function = T_MoveCeiling;
    ceiling->sector = sec;
    ceiling->crush = false;

    // setup ceiling structure according to type of function
    switch(type)
    {
      case fastCrushAndRaise:
        ceiling->crush = true;
        ceiling->topheight = sec->ceilingheight;
        ceiling->bottomheight = sec->floorheight + (8*FRACUNIT);
        ceiling->direction = -1;
        ceiling->speed = CEILSPEED * 2;
        break;

      case silentCrushAndRaise:
      case crushAndRaise:
        ceiling->crush = true;
        ceiling->topheight = sec->ceilingheight;
      case lowerAndCrush:
      case lowerToFloor:
        ceiling->bottomheight = sec->floorheight;
        if (type != lowerToFloor)
          ceiling->bottomheight += 8*FRACUNIT;
        ceiling->direction = -1;
        ceiling->speed = CEILSPEED;
        break;

      case raiseToHighest:
        ceiling->topheight = P_FindHighestCeilingSurrounding(sec);
        ceiling->direction = 1;
        ceiling->speed = CEILSPEED;
        break;

      case lowerToLowest:
        ceiling->bottomheight = P_FindLowestCeilingSurrounding(sec);
        ceiling->direction = -1;
        ceiling->speed = CEILSPEED;
        break;

      case lowerToMaxFloor:
        ceiling->bottomheight = P_FindHighestFloorSurrounding(sec);
        ceiling->direction = -1;
        ceiling->speed = CEILSPEED;
        break;

      default:
        break;
    }

    // add the ceiling to the active list
    ceiling->tag = sec->tag;
    ceiling->type = type;
    P_AddActiveCeiling(ceiling);
  }
  return rtn;
}

//////////////////////////////////////////////////////////////////////
//
// Active ceiling list primitives
//
/////////////////////////////////////////////////////////////////////

// jff 2/22/98 - modified Lee's plat code to work for ceilings
//
// The following were all rewritten by Lee Killough
// to use the new structure which places no limits
// on active ceilings. It also avoids spending as much
// time searching for active ceilings. Previously a
// fixed-size array was used, with NULL indicating
// empty entries, while now a doubly-linked list
// is used.

//
// P_ActivateInStasisCeiling()
//
// Reactivates all stopped crushers with the right tag
//
// Passed the line reactivating the crusher
// Returns true if a ceiling reactivated
//
//jff 4/5/98 return if activated
int P_ActivateInStasisCeiling(const line_t *line)
{
  ceilinglist_t *cl;
  int rtn=0;

  for (cl=_g->activeceilings; cl; cl=cl->next)
  {
    ceiling_t *ceiling = cl->ceiling;
    if (ceiling->tag == line->tag && ceiling->direction == 0)
    {
      ceiling->direction = ceiling->olddirection;
      ceiling->thinker.function = T_MoveCeiling;
      //jff 4/5/98 return if activated
      rtn=1;
    }
  }
  return rtn;
}

//
// EV_CeilingCrushStop()
//
// Stops all active ceilings with the right tag
//
// Passed the linedef stopping the ceilings
// Returns true if a ceiling put in stasis
//
int EV_CeilingCrushStop(const line_t* line)
{
  int rtn=0;

  ceilinglist_t *cl;
  for (cl=_g->activeceilings; cl; cl=cl->next)
  {
    ceiling_t *ceiling = cl->ceiling;
    if (ceiling->direction != 0 && ceiling->tag == line->tag)
    {
      ceiling->olddirection = ceiling->direction;
      ceiling->direction = 0;
      ceiling->thinker.function = NULL;
      rtn=1;
    }
  }
  return rtn;
}

//
// P_AddActiveCeiling()
//
// Adds a ceiling to the head of the list of active ceilings
//
// Passed the ceiling motion structure
// Returns nothing
//
void P_AddActiveCeiling(ceiling_t* ceiling)
{
    ceilinglist_t *old_head = _g->activeceilings;

    ceilinglist_t *list = Z_Malloc(sizeof *list, PU_LEVEL, &_g->activeceilings);
    list->ceiling = ceiling;
    ceiling->list = list;

    if ((list->next = old_head))
        list->next->prev = &list->next;

    list->prev = old_head;
}

//
// P_RemoveActiveCeiling()
//
// Removes a ceiling from the list of active ceilings
//
// Passed the ceiling motion structure
// Returns nothing
//
void P_RemoveActiveCeiling(ceiling_t* ceiling)
{
  ceilinglist_t *list = ceiling->list;
  ceiling->sector->ceilingdata = NULL;  //jff 2/22/98

  P_RemoveThinker(&ceiling->thinker);

  if ((list->prev && (*list->prev = list->next)))
    list->next->prev = list->prev;

  free(list);
}

//
// P_RemoveAllActiveCeilings()
//
// Removes all ceilings from the active ceiling list
//
// Passed nothing, returns nothing
//
void P_RemoveAllActiveCeilings(void)
{
  while (_g->activeceilings)
  {
    ceilinglist_t *next = _g->activeceilings->next;
    free(_g->activeceilings);
    _g->activeceilings = next;
  }
}
