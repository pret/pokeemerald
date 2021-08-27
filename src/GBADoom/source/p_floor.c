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
 *  General plane mover and floor mover action routines
 *  Floor motion, pure changer types, raising stairs. donuts, elevators
 *
 *-----------------------------------------------------------------------------*/

#include "doomstat.h"
#include "r_main.h"
#include "p_map.h"
#include "p_spec.h"
#include "p_tick.h"
#include "s_sound.h"
#include "sounds.h"

#include "global_data.h"

///////////////////////////////////////////////////////////////////////
//
// Plane (floor or ceiling), Floor motion and Elevator action routines
//
///////////////////////////////////////////////////////////////////////

//
// T_MovePlane()
//
// Move a plane (floor or ceiling) and check for crushing. Called
// every tick by all actions that move floors or ceilings.
//
// Passed the sector to move a plane in, the speed to move it at,
// the dest height it is to achieve, whether it crushes obstacles,
// whether it moves a floor or ceiling, and the direction up or down
// to move.
//
// Returns a result_e:
//  ok - plane moved normally, has not achieved destination yet
//  pastdest - plane moved normally and is now at destination height
//  crushed - plane encountered an obstacle, is holding until removed
//
result_e T_MovePlane
( sector_t*     sector,
  fixed_t       speed,
  fixed_t       dest,
  boolean       crush,
  int           floorOrCeiling,
  int           direction )
{
  boolean       flag;
  fixed_t       lastpos;
  fixed_t       destheight; //jff 02/04/98 used to keep floors/ceilings
                            // from moving thru each other

  switch(floorOrCeiling)
  {
    case 0:
      // Moving a floor
      switch(direction)
      {
        case -1:
          // Moving a floor down
          if (sector->floorheight - speed < dest)
          {
            lastpos = sector->floorheight;
            sector->floorheight = dest;
            flag = P_CheckSector(sector,crush); //jff 3/19/98 use faster chk
            if (flag == true)
            {
              sector->floorheight =lastpos;
              P_CheckSector(sector,crush);      //jff 3/19/98 use faster chk
            }
            return pastdest;
          }
          else
          {
            lastpos = sector->floorheight;
            sector->floorheight -= speed;
            flag = P_CheckSector(sector,crush); //jff 3/19/98 use faster chk
      /* cph - make more compatible with original Doom, by
       *  reintroducing this code. This means floors can't lower
       *  if objects are stuck in the ceiling */
          }
          break;

        case 1:
          // Moving a floor up
          // jff 02/04/98 keep floor from moving thru ceilings
          // jff 2/22/98 weaken check to demo_compatibility
          destheight = (dest<sector->ceilingheight)?
                          dest : sector->ceilingheight;
          if (sector->floorheight + speed > destheight)
          {
            lastpos = sector->floorheight;
            sector->floorheight = destheight;
            flag = P_CheckSector(sector,crush); //jff 3/19/98 use faster chk
            if (flag == true)
            {
              sector->floorheight = lastpos;
              P_CheckSector(sector,crush);      //jff 3/19/98 use faster chk
            }
            return pastdest;
          }
          else
          {
            // crushing is possible
            lastpos = sector->floorheight;
            sector->floorheight += speed;
            flag = P_CheckSector(sector,crush); //jff 3/19/98 use faster chk
            if (flag == true)
            {

              sector->floorheight = lastpos;
              P_CheckSector(sector,crush);      //jff 3/19/98 use faster chk
              return crushed;
            }
          }
          break;
      }
      break;

    case 1:
      // moving a ceiling
      switch(direction)
      {
        case -1:
          // moving a ceiling down
          // jff 02/04/98 keep ceiling from moving thru floors
          // jff 2/22/98 weaken check to demo_compatibility
          destheight = (dest>sector->floorheight)?
                          dest : sector->floorheight;
          if (sector->ceilingheight - speed < destheight)
          {
            lastpos = sector->ceilingheight;
            sector->ceilingheight = destheight;
            flag = P_CheckSector(sector,crush); //jff 3/19/98 use faster chk

            if (flag == true)
            {
              sector->ceilingheight = lastpos;
              P_CheckSector(sector,crush);      //jff 3/19/98 use faster chk
            }
            return pastdest;
          }
          else
          {
            // crushing is possible
            lastpos = sector->ceilingheight;
            sector->ceilingheight -= speed;
            flag = P_CheckSector(sector,crush); //jff 3/19/98 use faster chk

            if (flag == true)
            {
              if (crush == true)
                return crushed;
              sector->ceilingheight = lastpos;
              P_CheckSector(sector,crush);      //jff 3/19/98 use faster chk
              return crushed;
            }
          }
          break;

        case 1:
          // moving a ceiling up
          if (sector->ceilingheight + speed > dest)
          {
            lastpos = sector->ceilingheight;
            sector->ceilingheight = dest;
            flag = P_CheckSector(sector,crush); //jff 3/19/98 use faster chk
            if (flag == true)
            {
              sector->ceilingheight = lastpos;
              P_CheckSector(sector,crush);      //jff 3/19/98 use faster chk
            }
            return pastdest;
          }
          else
          {
            lastpos = sector->ceilingheight;
            sector->ceilingheight += speed;
            flag = P_CheckSector(sector,crush); //jff 3/19/98 use faster chk
          }
          break;
      }
      break;
  }
  return ok;
}

//
// T_MoveFloor()
//
// Move a floor to it's destination (up or down).
// Called once per tick for each moving floor.
//
// Passed a floormove_t structure that contains all pertinent info about the
// move. See P_SPEC.H for fields.
// No return.
//
// jff 02/08/98 all cases with labels beginning with gen added to support
// generalized line type behaviors.

void T_MoveFloor(floormove_t* floor)
{
  result_e      res;

  res = T_MovePlane       // move the floor
  (
    floor->sector,
    floor->speed,
    floor->floordestheight,
    floor->crush,
    0,
    floor->direction
  );

  if (!(_g->leveltime&7))     // make the floormove sound
    S_StartSound2(&floor->sector->soundorg, sfx_stnmov);

  if (res == pastdest)    // if destination height is reached
  {
    if (floor->direction == 1)       // going up
    {
      switch(floor->type) // handle texture/type changes
      {
        case donutRaise:
          floor->sector->special = floor->newspecial;
          floor->sector->floorpic = floor->texture;
          break;
        case genFloorChgT:
        case genFloorChg0:
          floor->sector->special = floor->newspecial;
          //jff add to fix bug in special transfers from changes
          floor->sector->oldspecial = floor->oldspecial;
          //fall thru
        case genFloorChg:
          floor->sector->floorpic = floor->texture;
          break;
        default:
          break;
      }
    }
    else if (floor->direction == -1) // going down
    {
      switch(floor->type) // handle texture/type changes
      {
        case lowerAndChange:
          floor->sector->special = floor->newspecial;
          //jff add to fix bug in special transfers from changes
          floor->sector->oldspecial = floor->oldspecial;
          floor->sector->floorpic = floor->texture;
          break;
        case genFloorChgT:
        case genFloorChg0:
          floor->sector->special = floor->newspecial;
          //jff add to fix bug in special transfers from changes
          floor->sector->oldspecial = floor->oldspecial;
          //fall thru
        case genFloorChg:
          floor->sector->floorpic = floor->texture;
          break;
        default:
          break;
      }
    }

    floor->sector->floordata = NULL; //jff 2/22/98
    P_RemoveThinker(&floor->thinker);//remove this floor from list of movers

    // make floor stop sound
    S_StartSound2(&floor->sector->soundorg, sfx_pstop);
  }
}

//
// T_MoveElevator()
//
// Move an elevator to it's destination (up or down)
// Called once per tick for each moving floor.
//
// Passed an elevator_t structure that contains all pertinent info about the
// move. See P_SPEC.H for fields.
// No return.
//
// jff 02/22/98 added to support parallel floor/ceiling motion
//
void T_MoveElevator(elevator_t* elevator)
{
  result_e      res;

  if (elevator->direction<0)      // moving down
  {
    res = T_MovePlane             //jff 4/7/98 reverse order of ceiling/floor
    (
      elevator->sector,
      elevator->speed,
      elevator->ceilingdestheight,
      0,
      1,                          // move floor
      elevator->direction
    );
    if (res==ok || res==pastdest) // jff 4/7/98 don't move ceil if blocked
      T_MovePlane
      (
        elevator->sector,
        elevator->speed,
        elevator->floordestheight,
        0,
        0,                        // move ceiling
        elevator->direction
      );
  }
  else // up
  {
    res = T_MovePlane             //jff 4/7/98 reverse order of ceiling/floor
    (
      elevator->sector,
      elevator->speed,
      elevator->floordestheight,
      0,
      0,                          // move ceiling
      elevator->direction
    );
    if (res==ok || res==pastdest) // jff 4/7/98 don't move floor if blocked
      T_MovePlane
      (
        elevator->sector,
        elevator->speed,
        elevator->ceilingdestheight,
        0,
        1,                        // move floor
        elevator->direction
      );
  }

  // make floor move sound
  if (!(_g->leveltime&7))
    S_StartSound2(&elevator->sector->soundorg, sfx_stnmov);

  if (res == pastdest)            // if destination height acheived
  {
    elevator->sector->floordata = NULL;     //jff 2/22/98
    elevator->sector->ceilingdata = NULL;   //jff 2/22/98
    P_RemoveThinker(&elevator->thinker);    // remove elevator from actives

    // make floor stop sound
    S_StartSound2(&elevator->sector->soundorg, sfx_pstop);
  }
}

///////////////////////////////////////////////////////////////////////
//
// Floor motion linedef handlers
//
///////////////////////////////////////////////////////////////////////

//
// EV_DoFloor()
//
// Handle regular and extended floor types
//
// Passed the line that activated the floor and the type of floor motion
// Returns true if a thinker was created.
//
int EV_DoFloor
( const line_t*       line,
  floor_e       floortype )
{
  int           secnum;
  int           rtn;
  int           i;
  sector_t*     sec;
  floormove_t*  floor;

  secnum = -1;
  rtn = 0;
  // move all floors with the same tag as the linedef
  while ((secnum = P_FindSectorFromLineTag(line,secnum)) >= 0)
  {
    sec = &_g->sectors[secnum];

    // Don't start a second thinker on the same floor
    if (P_SectorActive(floor_special,sec)) //jff 2/23/98
      continue;

    // new floor thinker
    rtn = 1;
    floor = Z_Malloc (sizeof(*floor), PU_LEVSPEC, 0);
    memset(floor, 0, sizeof(*floor));
    P_AddThinker (&floor->thinker);
    sec->floordata = floor; //jff 2/22/98
    floor->thinker.function = T_MoveFloor;
    floor->type = floortype;
    floor->crush = false;

    // setup the thinker according to the linedef type
    switch(floortype)
    {
      case lowerFloor:
        floor->direction = -1;
        floor->sector = sec;
        floor->speed = FLOORSPEED;
        floor->floordestheight = P_FindHighestFloorSurrounding(sec);
        break;

        //jff 02/03/30 support lowering floor by 24 absolute
      case lowerFloor24:
        floor->direction = -1;
        floor->sector = sec;
        floor->speed = FLOORSPEED;
        floor->floordestheight = floor->sector->floorheight + 24 * FRACUNIT;
        break;

        //jff 02/03/30 support lowering floor by 32 absolute (fast)
      case lowerFloor32Turbo:
        floor->direction = -1;
        floor->sector = sec;
        floor->speed = FLOORSPEED*4;
        floor->floordestheight = floor->sector->floorheight + 32 * FRACUNIT;
        break;

      case lowerFloorToLowest:
        floor->direction = -1;
        floor->sector = sec;
        floor->speed = FLOORSPEED;
        floor->floordestheight = P_FindLowestFloorSurrounding(sec);
        break;

        //jff 02/03/30 support lowering floor to next lowest floor
      case lowerFloorToNearest:
        floor->direction = -1;
        floor->sector = sec;
        floor->speed = FLOORSPEED;
        floor->floordestheight =
          P_FindNextLowestFloor(sec,floor->sector->floorheight);
        break;

      case turboLower:
        floor->direction = -1;
        floor->sector = sec;
        floor->speed = FLOORSPEED * 4;
        floor->floordestheight = P_FindHighestFloorSurrounding(sec);
        if (floor->floordestheight != sec->floorheight)
          floor->floordestheight += 8*FRACUNIT;
        break;

      case raiseFloorCrush:
        floor->crush = true;
      case raiseFloor:
        floor->direction = 1;
        floor->sector = sec;
        floor->speed = FLOORSPEED;
        floor->floordestheight = P_FindLowestCeilingSurrounding(sec);
        if (floor->floordestheight > sec->ceilingheight)
          floor->floordestheight = sec->ceilingheight;
        floor->floordestheight -= (8*FRACUNIT)*(floortype == raiseFloorCrush);
        break;

      case raiseFloorTurbo:
        floor->direction = 1;
        floor->sector = sec;
        floor->speed = FLOORSPEED*4;
        floor->floordestheight = P_FindNextHighestFloor(sec,sec->floorheight);
        break;

      case raiseFloorToNearest:
        floor->direction = 1;
        floor->sector = sec;
        floor->speed = FLOORSPEED;
        floor->floordestheight = P_FindNextHighestFloor(sec,sec->floorheight);
        break;

      case raiseFloor24:
        floor->direction = 1;
        floor->sector = sec;
        floor->speed = FLOORSPEED;
        floor->floordestheight = floor->sector->floorheight + 24 * FRACUNIT;
        break;

        // jff 2/03/30 support straight raise by 32 (fast)
      case raiseFloor32Turbo:
        floor->direction = 1;
        floor->sector = sec;
        floor->speed = FLOORSPEED*4;
        floor->floordestheight = floor->sector->floorheight + 32 * FRACUNIT;
        break;

      case raiseFloor512:
        floor->direction = 1;
        floor->sector = sec;
        floor->speed = FLOORSPEED;
        floor->floordestheight = floor->sector->floorheight + 512 * FRACUNIT;
        break;

      case raiseFloor24AndChange:
        floor->direction = 1;
        floor->sector = sec;
        floor->speed = FLOORSPEED;
        floor->floordestheight = floor->sector->floorheight + 24 * FRACUNIT;
        sec->floorpic = LN_FRONTSECTOR(line)->floorpic;
        sec->special = LN_FRONTSECTOR(line)->special;
        //jff 3/14/98 transfer both old and new special
        sec->oldspecial = LN_FRONTSECTOR(line)->oldspecial;
        break;

      case raiseToTexture:
        {
          int minsize = INT_MAX;
          side_t*     side;

    /* jff 3/13/98 no ovf */

            minsize = 32000<<FRACBITS;
          floor->direction = 1;
          floor->sector = sec;
          floor->speed = FLOORSPEED;
          for (i = 0; i < sec->linecount; i++)
          {
            if (twoSided (secnum, i) )
            {
              side = getSide(secnum,i,0);
              // jff 8/14/98 don't scan texture 0, its not real
              if (side->bottomtexture > 0)
                if (textureheight[side->bottomtexture] < minsize)
                  minsize = textureheight[side->bottomtexture];
              side = getSide(secnum,i,1);
              // jff 8/14/98 don't scan texture 0, its not real
              if (side->bottomtexture > 0)
                if (textureheight[side->bottomtexture] < minsize)
                  minsize = textureheight[side->bottomtexture];
            }
          }
          {
            floor->floordestheight =
              (floor->sector->floorheight>>FRACBITS) + (minsize>>FRACBITS);
            if (floor->floordestheight>32000)
              floor->floordestheight = 32000;        //jff 3/13/98 do not
            floor->floordestheight<<=FRACBITS;       // allow height overflow
          }
        }
      break;

      case lowerAndChange:
        floor->direction = -1;
        floor->sector = sec;
        floor->speed = FLOORSPEED;
        floor->floordestheight = P_FindLowestFloorSurrounding(sec);
        floor->texture = sec->floorpic;

        // jff 1/24/98 make sure floor->newspecial gets initialized
        // in case no surrounding sector is at floordestheight
        // --> should not affect compatibility <--
        floor->newspecial = sec->special;
        //jff 3/14/98 transfer both old and new special
        floor->oldspecial = sec->oldspecial;

        //jff 5/23/98 use model subroutine to unify fixes and handling
        sec = P_FindModelFloorSector(floor->floordestheight,sec-_g->sectors);
        if (sec)
        {
          floor->texture = sec->floorpic;
          floor->newspecial = sec->special;
          //jff 3/14/98 transfer both old and new special
          floor->oldspecial = sec->oldspecial;
        }
        break;
      default:
        break;
    }
  }
  return rtn;
}

//
// EV_DoChange()
//
// Handle pure change types. These change floor texture and sector type
// by trigger or numeric model without moving the floor.
//
// The linedef causing the change and the type of change is passed
// Returns true if any sector changes
//
// jff 3/15/98 added to better support generalized sector types
//
int EV_DoChange
( const line_t*       line,
  change_e      changetype )
{
  int                   secnum;
  int                   rtn;
  sector_t*             sec;
  sector_t*             secm;

  secnum = -1;
  rtn = 0;
  // change all sectors with the same tag as the linedef
  while ((secnum = P_FindSectorFromLineTag(line,secnum)) >= 0)
  {
    sec = &_g->sectors[secnum];

    rtn = 1;

    // handle trigger or numeric change type
    switch(changetype)
    {
      case trigChangeOnly:
        sec->floorpic = LN_FRONTSECTOR(line)->floorpic;
        sec->special = LN_FRONTSECTOR(line)->special;
        sec->oldspecial = LN_FRONTSECTOR(line)->oldspecial;
        break;
      case numChangeOnly:
        secm = P_FindModelFloorSector(sec->floorheight,secnum);
        if (secm) // if no model, no change
        {
          sec->floorpic = secm->floorpic;
          sec->special = secm->special;
          sec->oldspecial = secm->oldspecial;
        }
        break;
      default:
        break;
    }
  }
  return rtn;
}

/*
 * EV_BuildStairs()
 *
 * Handles staircase building. A sequence of sectors chosen by algorithm
 * rise at a speed indicated to a height that increases by the stepsize
 * each step.
 *
 * Passed the linedef triggering the stairs and the type of stair rise
 * Returns true if any thinkers are created
 *
 * cph 2001/09/21 - compatibility nightmares again
 * There are three different ways this function has, during its history, stepped
 * through all the stairs to be triggered by the single switch
 * - original Doom used a linear P_FindSectorFromLineTag, but failed to preserve
 * the index of the previous sector found, so instead it would restart its
 * linear search from the last sector of the previous staircase
 * - MBF/PrBoom with comp_stairs fail to emulate this, because their
 * P_FindSectorFromLineTag is a chained hash table implementation. Instead they
 * start following the hash chain from the last sector of the previous
 * staircase, which will (probably) have the wrong tag, so they miss any further
 * stairs
 * - Boom fixed the bug, and MBF/PrBoom without comp_stairs work right
 */
static inline int P_FindSectorFromLineTagWithLowerBound
(const line_t* l, int start, int min)
{
  /* Emulate original Doom's linear lower-bounded P_FindSectorFromLineTag
   * as needed */
  do {
    start = P_FindSectorFromLineTag(l,start);
  } while (start >= 0 && start <= min);
  return start;
}

int EV_BuildStairs
( const line_t*       line,
  stair_e       type )
{
  /* cph 2001/09/22 - cleaned up this function to save my sanity. A separate
   * outer loop index makes the logic much cleared, and local variables moved
   * into the inner blocks helps too */
  int                   ssec = -1;
  int                   minssec = -1;
  int                   rtn = 0;

  // start a stair at each sector tagged the same as the linedef
  while ((ssec = P_FindSectorFromLineTagWithLowerBound(line,ssec,minssec)) >= 0)
  {
   int           secnum = ssec;
   sector_t*     sec = &_g->sectors[secnum];

    // don't start a stair if the first step's floor is already moving
   if (!P_SectorActive(floor_special,sec)) { //jff 2/22/98
    floormove_t*  floor;
    int           texture, height;
    fixed_t       stairsize;
    fixed_t       speed;
    int           ok;

    // create new floor thinker for first step
    rtn = 1;
    floor = Z_Malloc (sizeof(*floor), PU_LEVSPEC, 0);
    memset(floor, 0, sizeof(*floor));
    P_AddThinker (&floor->thinker);
    sec->floordata = floor;
    floor->thinker.function = T_MoveFloor;
    floor->direction = 1;
    floor->sector = sec;
    floor->type = buildStair;   //jff 3/31/98 do not leave uninited

    // set up the speed and stepsize according to the stairs type
    switch(type)
    {
      default: // killough -- prevent compiler warning
      case build8:
        speed = FLOORSPEED/4;
        stairsize = 8*FRACUNIT;
          floor->crush = false; //jff 2/27/98 fix uninitialized crush field
        break;
      case turbo16:
        speed = FLOORSPEED*4;
        stairsize = 16*FRACUNIT;
          floor->crush = true;  //jff 2/27/98 fix uninitialized crush field
        break;
    }
    floor->speed = speed;
    height = sec->floorheight + stairsize;
    floor->floordestheight = height;

    texture = sec->floorpic;

    // Find next sector to raise
    //   1. Find 2-sided line with same sector side[0] (lowest numbered)
    //   2. Other side is the next sector to raise
    //   3. Unless already moving, or different texture, then stop building
    do
    {
      int i;
      ok = 0;

      for (i = 0;i < sec->linecount;i++)
      {          
        sector_t* tsec = LN_FRONTSECTOR((sec->lines[i]));
        int newsecnum;
        if ( !((sec->lines[i])->flags & ML_TWOSIDED) )
          continue;

        newsecnum = tsec-_g->sectors;

        if (secnum != newsecnum)
          continue;

        tsec = LN_BACKSECTOR((sec->lines[i]));
        if (!tsec) continue;     //jff 5/7/98 if no backside, continue
        newsecnum = tsec - _g->sectors;

        // if sector's floor is different texture, look for another
        if (tsec->floorpic != texture)
          continue;

        // if sector's floor already moving, look for another
        if (P_SectorActive(floor_special,tsec)) //jff 2/22/98
          continue;

        height += stairsize;

        sec = tsec;
        secnum = newsecnum;

        // create and initialize a thinker for the next step
        floor = Z_Malloc (sizeof(*floor), PU_LEVSPEC, 0);
        memset(floor, 0, sizeof(*floor));
        P_AddThinker (&floor->thinker);

        sec->floordata = floor; //jff 2/22/98
        floor->thinker.function = T_MoveFloor;
        floor->direction = 1;
        floor->sector = sec;
        floor->speed = speed;
        floor->floordestheight = height;
        floor->type = buildStair; //jff 3/31/98 do not leave uninited
        //jff 2/27/98 fix uninitialized crush field
          floor->crush = type==build8? false : true;
        ok = 1;
        break;
      }
    } while(ok);      // continue until no next step is found

   }
  }
  return rtn;
}

//
// EV_DoDonut()
//
// Handle donut function: lower pillar, raise surrounding pool, both to height,
// texture and type of the sector surrounding the pool.
//
// Passed the linedef that triggered the donut
// Returns whether a thinker was created
//
int EV_DoDonut(const line_t*  line)
{
  sector_t* s1;
  sector_t* s2;
  sector_t* s3;
  int       secnum;
  int       rtn;
  int       i;
  floormove_t* floor;

  secnum = -1;
  rtn = 0;
  // do function on all sectors with same tag as linedef
  while ((secnum = P_FindSectorFromLineTag(line,secnum)) >= 0)
  {
    s1 = &_g->sectors[secnum];                // s1 is pillar's sector

    // do not start the donut if the pillar is already moving
    if (P_SectorActive(floor_special,s1)) //jff 2/22/98
      continue;

    s2 = getNextSector(s1->lines[0],s1);  // s2 is pool's sector
    if (!s2) continue;                    // note lowest numbered line around
                                          // pillar must be two-sided

    /* do not start the donut if the pool is already moving
     * cph - DEMOSYNC - was !compatibility */
    if (P_SectorActive(floor_special,s2))
      continue;                           //jff 5/7/98

    // find a two sided line around the pool whose other side isn't the pillar
    for (i = 0;i < s2->linecount;i++)
    {


        if (!LN_BACKSECTOR((s2->lines[i])) || LN_BACKSECTOR((s2->lines[i])) == s1)
            continue;

      rtn = 1; //jff 1/26/98 no donut action - no switch change on return

      s3 = LN_BACKSECTOR((s2->lines[i]));      // s3 is model sector for changes

      //  Spawn rising slime
      floor = Z_Malloc (sizeof(*floor), PU_LEVSPEC, 0);
      memset(floor, 0, sizeof(*floor));
      P_AddThinker (&floor->thinker);
      s2->floordata = floor; //jff 2/22/98
      floor->thinker.function = T_MoveFloor;
      floor->type = donutRaise;
      floor->crush = false;
      floor->direction = 1;
      floor->sector = s2;
      floor->speed = FLOORSPEED / 2;
      floor->texture = s3->floorpic;
      floor->newspecial = 0;
      floor->floordestheight = s3->floorheight;

      //  Spawn lowering donut-hole pillar
      floor = Z_Malloc (sizeof(*floor), PU_LEVSPEC, 0);
      memset(floor, 0, sizeof(*floor));
      P_AddThinker (&floor->thinker);
      s1->floordata = floor; //jff 2/22/98
      floor->thinker.function = T_MoveFloor;
      floor->type = lowerFloor;
      floor->crush = false;
      floor->direction = -1;
      floor->sector = s1;
      floor->speed = FLOORSPEED / 2;
      floor->floordestheight = s3->floorheight;
      break;
    }
  }
  return rtn;
}

//
// EV_DoElevator
//
// Handle elevator linedef types
//
// Passed the linedef that triggered the elevator and the elevator action
//
// jff 2/22/98 new type to move floor and ceiling in parallel
//
int EV_DoElevator
( const line_t*       line,
  elevator_e    elevtype )
{
  int                   secnum;
  int                   rtn;
  sector_t*             sec;
  elevator_t*           elevator;

  secnum = -1;
  rtn = 0;
  // act on all sectors with the same tag as the triggering linedef
  while ((secnum = P_FindSectorFromLineTag(line,secnum)) >= 0)
  {
    sec = &_g->sectors[secnum];

    // If either floor or ceiling is already activated, skip it
    if (sec->floordata || sec->ceilingdata) //jff 2/22/98
      continue;

    // create and initialize new elevator thinker
    rtn = 1;
    elevator = Z_Malloc (sizeof(*elevator), PU_LEVSPEC, 0);
    memset(elevator, 0, sizeof(*elevator));
    P_AddThinker (&elevator->thinker);
    sec->floordata = elevator; //jff 2/22/98
    sec->ceilingdata = elevator; //jff 2/22/98
    elevator->thinker.function = T_MoveElevator;
    elevator->type = elevtype;

    // set up the fields according to the type of elevator action
    switch(elevtype)
    {
        // elevator down to next floor
      case elevateDown:
        elevator->direction = -1;
        elevator->sector = sec;
        elevator->speed = ELEVATORSPEED;
        elevator->floordestheight =
          P_FindNextLowestFloor(sec,sec->floorheight);
        elevator->ceilingdestheight =
          elevator->floordestheight + sec->ceilingheight - sec->floorheight;
        break;

        // elevator up to next floor
      case elevateUp:
        elevator->direction = 1;
        elevator->sector = sec;
        elevator->speed = ELEVATORSPEED;
        elevator->floordestheight =
          P_FindNextHighestFloor(sec,sec->floorheight);
        elevator->ceilingdestheight =
          elevator->floordestheight + sec->ceilingheight - sec->floorheight;
        break;

        // elevator to floor height of activating switch's front sector
      case elevateCurrent:
        elevator->sector = sec;
        elevator->speed = ELEVATORSPEED;
        elevator->floordestheight = LN_FRONTSECTOR(line)->floorheight;
        elevator->ceilingdestheight =
          elevator->floordestheight + sec->ceilingheight - sec->floorheight;
        elevator->direction =
          elevator->floordestheight>sec->floorheight?  1 : -1;
        break;

      default:
        break;
    }
  }
  return rtn;
}
