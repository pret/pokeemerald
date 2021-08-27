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
 *  Plats (i.e. elevator platforms) code, raising/lowering.
 *
 *-----------------------------------------------------------------------------*/

#include "doomstat.h"
#include "m_random.h"
#include "r_main.h"
#include "p_spec.h"
#include "p_tick.h"
#include "s_sound.h"
#include "sounds.h"

#include "global_data.h"

//
// T_PlatRaise()
//
// Action routine to move a plat up and down
//
// Passed a plat structure containing all pertinent information about the move
// No return
//
// jff 02/08/98 all cases with labels beginning with gen added to support
// generalized line type behaviors.

void T_PlatRaise(plat_t* plat)
{
  result_e      res;

  // handle plat moving, up, down, waiting, or in stasis,
  switch(plat->status)
  {
    case up: // plat moving up
      res = T_MovePlane(plat->sector,plat->speed,plat->high,plat->crush,0,1);

      // if a pure raise type, make the plat moving sound
      if (plat->type == raiseAndChange
          || plat->type == raiseToNearestAndChange)
      {
        if (!(_g->leveltime&7))
          S_StartSound2(&plat->sector->soundorg, sfx_stnmov);
      }

      // if encountered an obstacle, and not a crush type, reverse direction
      if (res == crushed && (!plat->crush))
      {
        plat->count = plat->wait;
        plat->status = down;
        S_StartSound2(&plat->sector->soundorg, sfx_pstart);
      }
      else  // else handle reaching end of up stroke
      {
        if (res == pastdest) // end of stroke
        {
          // if not an instant toggle type, wait, make plat stop sound
          if (plat->type!=toggleUpDn)
          {
            plat->count = plat->wait;
            plat->status = waiting;
            S_StartSound2(&plat->sector->soundorg, sfx_pstop);
          }
          else // else go into stasis awaiting next toggle activation
          {
            plat->oldstatus = plat->status;//jff 3/14/98 after action wait
            plat->status = in_stasis;      //for reactivation of toggle
          }

          // lift types and pure raise types are done at end of up stroke
          // only the perpetual type waits then goes back up
          switch(plat->type)
          {
            case blazeDWUS:
            case downWaitUpStay:
            case raiseAndChange:
            case raiseToNearestAndChange:
            case genLift:
              P_RemoveActivePlat(plat);     // killough
            default:
              break;
          }
        }
      }
      break;

    case down: // plat moving down
      res = T_MovePlane(plat->sector,plat->speed,plat->low,false,0,-1);

      // handle reaching end of down stroke
      if (res == pastdest)
      {
        // if not an instant toggle, start waiting, make plat stop sound
        if (plat->type!=toggleUpDn) //jff 3/14/98 toggle up down
        {                           // is silent, instant, no waiting
          plat->count = plat->wait;
          plat->status = waiting;
          S_StartSound2(&plat->sector->soundorg,sfx_pstop);
        }
        else // instant toggles go into stasis awaiting next activation
        {
          plat->oldstatus = plat->status;//jff 3/14/98 after action wait
          plat->status = in_stasis;      //for reactivation of toggle
        }

        //jff 1/26/98 remove the plat if it bounced so it can be tried again
        //only affects plats that raise and bounce
        //killough 1/31/98: relax compatibility to demo_compatibility

          switch(plat->type)
          {
            case raiseAndChange:
            case raiseToNearestAndChange:
              P_RemoveActivePlat(plat);
            default:
              break;
          }

      }
      break;

    case waiting: // plat is waiting
      if (!--plat->count)  // downcount and check for delay elapsed
      {
        if (plat->sector->floorheight == plat->low)
          plat->status = up;     // if at bottom, start up
        else
          plat->status = down;   // if at top, start down

        // make plat start sound
        S_StartSound2(&plat->sector->soundorg,sfx_pstart);
      }
      break; //jff 1/27/98 don't pickup code added later to in_stasis

    case in_stasis: // do nothing if in stasis
      break;
  }
}


//
// EV_DoPlat
//
// Handle Plat linedef types
//
// Passed the linedef that activated the plat, the type of plat action,
// and for some plat types, an amount to raise
// Returns true if a thinker is started, or restarted from stasis
//
int EV_DoPlat
( const line_t*       line,
  plattype_e    type,
  int           amount )
{
  plat_t* plat;
  int             secnum;
  int             rtn;
  sector_t*       sec;

  secnum = -1;
  rtn = 0;


  // Activate all <type> plats that are in_stasis
  switch(type)
  {
    case perpetualRaise:
      P_ActivateInStasis(line->tag);
      break;

    case toggleUpDn:
      P_ActivateInStasis(line->tag);
      rtn=1;
      break;

    default:
      break;
  }

  // act on all sectors tagged the same as the activating linedef
  while ((secnum = P_FindSectorFromLineTag(line,secnum)) >= 0)
  {
    sec = &_g->sectors[secnum];

    // don't start a second floor function if already moving
    if (P_SectorActive(floor_special,sec)) //jff 2/23/98 multiple thinkers
      continue;

    // Create a thinker
    rtn = 1;
    plat = Z_Malloc( sizeof(*plat), PU_LEVSPEC, 0);
    memset(plat, 0, sizeof(*plat));
    P_AddThinker(&plat->thinker);

    plat->type = type;
    plat->sector = sec;
    plat->sector->floordata = plat; //jff 2/23/98 multiple thinkers
    plat->thinker.function = T_PlatRaise;
    plat->crush = false;
    plat->tag = line->tag;

    //jff 1/26/98 Avoid raise plat bouncing a head off a ceiling and then
    //going down forever -- default low to plat height when triggered
    plat->low = sec->floorheight;

    // set up plat according to type
    switch(type)
    {
      case raiseToNearestAndChange:
        plat->speed = PLATSPEED/2;
        sec->floorpic = _g->sides[line->sidenum[0]].sector->floorpic;
        plat->high = P_FindNextHighestFloor(sec,sec->floorheight);
        plat->wait = 0;
        plat->status = up;
        sec->special = 0;
        //jff 3/14/98 clear old field as well
        sec->oldspecial = 0;

        S_StartSound2(&sec->soundorg,sfx_stnmov);
        break;

      case raiseAndChange:
        plat->speed = PLATSPEED/2;
        sec->floorpic = _g->sides[line->sidenum[0]].sector->floorpic;
        plat->high = sec->floorheight + amount*FRACUNIT;
        plat->wait = 0;
        plat->status = up;

        S_StartSound2(&sec->soundorg,sfx_stnmov);
        break;

      case downWaitUpStay:
        plat->speed = PLATSPEED * 4;
        plat->low = P_FindLowestFloorSurrounding(sec);

        if (plat->low > sec->floorheight)
          plat->low = sec->floorheight;

        plat->high = sec->floorheight;
        plat->wait = 35*PLATWAIT;
        plat->status = down;
        S_StartSound2(&sec->soundorg,sfx_pstart);
        break;

      case blazeDWUS:
        plat->speed = PLATSPEED * 8;
        plat->low = P_FindLowestFloorSurrounding(sec);

        if (plat->low > sec->floorheight)
          plat->low = sec->floorheight;

        plat->high = sec->floorheight;
        plat->wait = 35*PLATWAIT;
        plat->status = down;
        S_StartSound2(&sec->soundorg,sfx_pstart);
        break;

      case perpetualRaise:
        plat->speed = PLATSPEED;
        plat->low = P_FindLowestFloorSurrounding(sec);

        if (plat->low > sec->floorheight)
          plat->low = sec->floorheight;

        plat->high = P_FindHighestFloorSurrounding(sec);

        if (plat->high < sec->floorheight)
          plat->high = sec->floorheight;

        plat->wait = 35*PLATWAIT;
        plat->status = P_Random()&1;

        S_StartSound2(&sec->soundorg,sfx_pstart);
        break;

      case toggleUpDn: //jff 3/14/98 add new type to support instant toggle
        plat->speed = PLATSPEED;  //not used
        plat->wait = 35*PLATWAIT; //not used
        plat->crush = true; //jff 3/14/98 crush anything in the way

        // set up toggling between ceiling, floor inclusive
        plat->low = sec->ceilingheight;
        plat->high = sec->floorheight;
        plat->status =  down;
        break;

      default:
        break;
    }
    P_AddActivePlat(plat);  // add plat to list of active plats
  }
  return rtn;
}

// The following were all rewritten by Lee Killough
// to use the new structure which places no limits
// on active plats. It also avoids spending as much
// time searching for active plats. Previously a
// fixed-size array was used, with NULL indicating
// empty entries, while now a doubly-linked list
// is used.

//
// P_ActivateInStasis()
//
// Activate a plat that has been put in stasis
// (stopped perpetual floor, instant floor/ceil toggle)
//
// Passed the tag of the plat that should be reactivated
// Returns nothing
//
void P_ActivateInStasis(int tag)
{
  platlist_t *pl;
  for (pl=_g->activeplats; pl; pl=pl->next)   // search the active plats
  {
    plat_t *plat = pl->plat;              // for one in stasis with right tag
    if (plat->tag == tag && plat->status == in_stasis)
    {
      if (plat->type==toggleUpDn) //jff 3/14/98 reactivate toggle type
        plat->status = plat->oldstatus==up? down : up;
      else
        plat->status = plat->oldstatus;
      plat->thinker.function = T_PlatRaise;
    }
  }
}

//
// EV_StopPlat()
//
// Handler for "stop perpetual floor" linedef type
//
// Passed the linedef that stopped the plat
// Returns true if a plat was put in stasis
//
// jff 2/12/98 added int return value, fixed return
//
int EV_StopPlat(const line_t* line)
{
  platlist_t *pl;
  for (pl=_g->activeplats; pl; pl=pl->next)  // search the active plats
  {
    plat_t *plat = pl->plat;             // for one with the tag not in stasis
    if (plat->status != in_stasis && plat->tag == line->tag)
    {
      plat->oldstatus = plat->status;    // put it in stasis
      plat->status = in_stasis;
      plat->thinker.function = NULL;
    }
  }
  return 1;
}

//
// P_AddActivePlat()
//
// Add a plat to the head of the active plat list
//
// Passed a pointer to the plat to add
// Returns nothing
//
void P_AddActivePlat(plat_t* plat)
{
    platlist_t* old_head = _g->activeplats;

    platlist_t *list = Z_Malloc(sizeof *list, PU_LEVEL, &_g->activeplats);
    list->plat = plat;
    plat->list = list;
    if ((list->next = old_head))
        list->next->prev = &list->next;

    list->prev = old_head;
}

//
// P_RemoveActivePlat()
//
// Remove a plat from the active plat list
//
// Passed a pointer to the plat to remove
// Returns nothing
//
void P_RemoveActivePlat(plat_t* plat)
{
  platlist_t *list = plat->list;
  plat->sector->floordata = NULL; //jff 2/23/98 multiple thinkers

  P_RemoveThinker(&plat->thinker);

  if (list->prev && (*list->prev = list->next))
    list->next->prev = list->prev;

  free(list);
}

//
// P_RemoveAllActivePlats()
//
// Remove all plats from the active plat list
//
// Passed nothing, returns nothing
//
void P_RemoveAllActivePlats(void)
{
  while (_g->activeplats)
  {
    platlist_t *next = _g->activeplats->next;
    free(_g->activeplats);
    _g->activeplats = next;
  }
}
