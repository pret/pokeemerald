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
 *  Generalized linedef type handlers
 *  Floors, Ceilings, Doors, Locked Doors, Lifts, Stairs, Crushers
 *
 *-----------------------------------------------------------------------------*/

#include "doomstat.h" //jff 6/19/98 for demo_compatibility
#include "r_main.h"
#include "p_spec.h"
#include "p_tick.h"
#include "m_random.h"
#include "s_sound.h"
#include "sounds.h"

#include "global_data.h"

//////////////////////////////////////////////////////////
//
// Generalized Linedef Type handlers
//
//////////////////////////////////////////////////////////

//
// EV_DoGenFloor()
//
// Handle generalized floor types
//
// Passed the line activating the generalized floor function
// Returns true if a thinker is created
//
// jff 02/04/98 Added this routine (and file) to handle generalized
// floor movers using bit fields in the line special type.
//
int EV_DoGenFloor
( const line_t*       line )
{
  int                   secnum;
  int                   rtn;
  boolean               manual;
  sector_t*             sec;
  floormove_t*          floor;
  unsigned              value = (unsigned)LN_SPECIAL(line) - GenFloorBase;

  // parse the bit fields in the line's special type

  int Crsh = (value & FloorCrush) >> FloorCrushShift;
  int ChgT = (value & FloorChange) >> FloorChangeShift;
  int Targ = (value & FloorTarget) >> FloorTargetShift;
  int Dirn = (value & FloorDirection) >> FloorDirectionShift;
  int ChgM = (value & FloorModel) >> FloorModelShift;
  int Sped = (value & FloorSpeed) >> FloorSpeedShift;
  int Trig = (value & TriggerType) >> TriggerTypeShift;

  rtn = 0;

  // check if a manual trigger, if so do just the sector on the backside
  manual = false;
  if (Trig==PushOnce || Trig==PushMany)
  {
    if (!(sec = LN_BACKSECTOR(line)))
      return rtn;
    secnum = sec-_g->sectors;
    manual = true;
    goto manual_floor;
  }

  secnum = -1;
  // if not manual do all sectors tagged the same as the line
  while ((secnum = P_FindSectorFromLineTag(line,secnum)) >= 0)
  {
    sec = &_g->sectors[secnum];

manual_floor:
    // Do not start another function if floor already moving
    if (P_SectorActive(floor_special,sec))
    {
      if (!manual)
        continue;
      else
        return rtn;
    }

    // new floor thinker
    rtn = 1;
    floor = Z_Malloc (sizeof(*floor), PU_LEVSPEC, 0);
    memset(floor, 0, sizeof(*floor));
    P_AddThinker (&floor->thinker);
    sec->floordata = floor;
    floor->thinker.function = T_MoveFloor;
    floor->crush = Crsh;
    floor->direction = Dirn? 1 : -1;
    floor->sector = sec;
    floor->texture = sec->floorpic;
    floor->newspecial = sec->special;
    //jff 3/14/98 transfer old special field too
    floor->oldspecial = sec->oldspecial;
    floor->type = genFloor;

    // set the speed of motion
    switch (Sped)
    {
      case SpeedSlow:
        floor->speed = FLOORSPEED;
        break;
      case SpeedNormal:
        floor->speed = FLOORSPEED*2;
        break;
      case SpeedFast:
        floor->speed = FLOORSPEED*4;
        break;
      case SpeedTurbo:
        floor->speed = FLOORSPEED*8;
        break;
      default:
        break;
    }

    // set the destination height
    switch(Targ)
    {
      case FtoHnF:
        floor->floordestheight = P_FindHighestFloorSurrounding(sec);
        break;
      case FtoLnF:
        floor->floordestheight = P_FindLowestFloorSurrounding(sec);
        break;
      case FtoNnF:
        floor->floordestheight = Dirn?
          P_FindNextHighestFloor(sec,sec->floorheight) :
          P_FindNextLowestFloor(sec,sec->floorheight);
        break;
      case FtoLnC:
        floor->floordestheight = P_FindLowestCeilingSurrounding(sec);
        break;
      case FtoC:
        floor->floordestheight = sec->ceilingheight;
        break;
      case FbyST:
        floor->floordestheight = (floor->sector->floorheight>>FRACBITS) +
          floor->direction * (P_FindShortestTextureAround(secnum)>>FRACBITS);
        if (floor->floordestheight>32000)  //jff 3/13/98 prevent overflow
          floor->floordestheight=32000;    // wraparound in floor height
        if (floor->floordestheight<-32000)
          floor->floordestheight=-32000;
        floor->floordestheight<<=FRACBITS;
        break;
      case Fby24:
        floor->floordestheight = floor->sector->floorheight +
          floor->direction * 24*FRACUNIT;
        break;
      case Fby32:
        floor->floordestheight = floor->sector->floorheight +
          floor->direction * 32*FRACUNIT;
        break;
      default:
        break;
    }

    // set texture/type change properties
    if (ChgT)   // if a texture change is indicated
    {
      if (ChgM) // if a numeric model change
      {
        sector_t *sec;

        //jff 5/23/98 find model with ceiling at target height if target
        //is a ceiling type
        sec = (Targ==FtoLnC || Targ==FtoC)?
          P_FindModelCeilingSector(floor->floordestheight,secnum) :
          P_FindModelFloorSector(floor->floordestheight,secnum);
        if (sec)
        {
          floor->texture = sec->floorpic;
          switch(ChgT)
          {
            case FChgZero:  // zero type
              floor->newspecial = 0;
              //jff 3/14/98 change old field too
              floor->oldspecial = 0;
              floor->type = genFloorChg0;
              break;
            case FChgTyp:   // copy type
              floor->newspecial = sec->special;
              //jff 3/14/98 change old field too
              floor->oldspecial = sec->oldspecial;
              floor->type = genFloorChgT;
              break;
            case FChgTxt:   // leave type be
              floor->type = genFloorChg;
              break;
            default:
              break;
          }
        }
      }
      else     // else if a trigger model change
      {
        floor->texture = LN_FRONTSECTOR(line)->floorpic;
        switch (ChgT)
        {
          case FChgZero:    // zero type
            floor->newspecial = 0;
            //jff 3/14/98 change old field too
            floor->oldspecial = 0;
            floor->type = genFloorChg0;
            break;
          case FChgTyp:     // copy type
            floor->newspecial = LN_FRONTSECTOR(line)->special;
            //jff 3/14/98 change old field too
            floor->oldspecial = LN_FRONTSECTOR(line)->oldspecial;
            floor->type = genFloorChgT;
            break;
          case FChgTxt:     // leave type be
            floor->type = genFloorChg;
          default:
            break;
        }
      }
    }
    if (manual) return rtn;
  }
  return rtn;
}


//
// EV_DoGenCeiling()
//
// Handle generalized ceiling types
//
// Passed the linedef activating the ceiling function
// Returns true if a thinker created
//
// jff 02/04/98 Added this routine (and file) to handle generalized
// floor movers using bit fields in the line special type.
//
int EV_DoGenCeiling
( const line_t*       line )
{
  int                   secnum;
  int                   rtn;
  boolean               manual;
  fixed_t               targheight;
  sector_t*             sec;
  ceiling_t*            ceiling;
  unsigned              value = (unsigned)LN_SPECIAL(line) - GenCeilingBase;

  // parse the bit fields in the line's special type

  int Crsh = (value & CeilingCrush) >> CeilingCrushShift;
  int ChgT = (value & CeilingChange) >> CeilingChangeShift;
  int Targ = (value & CeilingTarget) >> CeilingTargetShift;
  int Dirn = (value & CeilingDirection) >> CeilingDirectionShift;
  int ChgM = (value & CeilingModel) >> CeilingModelShift;
  int Sped = (value & CeilingSpeed) >> CeilingSpeedShift;
  int Trig = (value & TriggerType) >> TriggerTypeShift;

  rtn = 0;

  // check if a manual trigger, if so do just the sector on the backside
  manual = false;
  if (Trig==PushOnce || Trig==PushMany)
  {
    if (!(sec = LN_BACKSECTOR(line)))
      return rtn;
    secnum = sec-_g->sectors;
    manual = true;
    goto manual_ceiling;
  }

  secnum = -1;
  // if not manual do all sectors tagged the same as the line
  while ((secnum = P_FindSectorFromLineTag(line,secnum)) >= 0)
  {
    sec = &_g->sectors[secnum];

manual_ceiling:
    // Do not start another function if ceiling already moving
    if (P_SectorActive(ceiling_special,sec)) //jff 2/22/98
    {
      if (!manual)
        continue;
      else
        return rtn;
    }

    // new ceiling thinker
    rtn = 1;
    ceiling = Z_Malloc (sizeof(*ceiling), PU_LEVSPEC, 0);
    memset(ceiling, 0, sizeof(*ceiling));
    P_AddThinker (&ceiling->thinker);
    sec->ceilingdata = ceiling; //jff 2/22/98
    ceiling->thinker.function = T_MoveCeiling;
    ceiling->crush = Crsh;
    ceiling->direction = Dirn? 1 : -1;
    ceiling->sector = sec;
    ceiling->texture = sec->ceilingpic;
    ceiling->newspecial = sec->special;
    //jff 3/14/98 change old field too
    ceiling->oldspecial = sec->oldspecial;
    ceiling->tag = sec->tag;
    ceiling->type = genCeiling;

    // set speed of motion
    switch (Sped)
    {
      case SpeedSlow:
        ceiling->speed = CEILSPEED;
        break;
      case SpeedNormal:
        ceiling->speed = CEILSPEED*2;
        break;
      case SpeedFast:
        ceiling->speed = CEILSPEED*4;
        break;
      case SpeedTurbo:
        ceiling->speed = CEILSPEED*8;
        break;
      default:
        break;
    }

    // set destination target height
    targheight = sec->ceilingheight;
    switch(Targ)
    {
      case CtoHnC:
        targheight = P_FindHighestCeilingSurrounding(sec);
        break;
      case CtoLnC:
        targheight = P_FindLowestCeilingSurrounding(sec);
        break;
      case CtoNnC:
        targheight = Dirn?
          P_FindNextHighestCeiling(sec,sec->ceilingheight) :
          P_FindNextLowestCeiling(sec,sec->ceilingheight);
        break;
      case CtoHnF:
        targheight = P_FindHighestFloorSurrounding(sec);
        break;
      case CtoF:
        targheight = sec->floorheight;
        break;
      case CbyST:
        targheight = (ceiling->sector->ceilingheight>>FRACBITS) +
          ceiling->direction * (P_FindShortestUpperAround(secnum)>>FRACBITS);
        if (targheight>32000)  //jff 3/13/98 prevent overflow
          targheight=32000;    // wraparound in ceiling height
        if (targheight<-32000)
          targheight=-32000;
        targheight<<=FRACBITS;
        break;
      case Cby24:
        targheight = ceiling->sector->ceilingheight +
          ceiling->direction * 24*FRACUNIT;
        break;
      case Cby32:
        targheight = ceiling->sector->ceilingheight +
          ceiling->direction * 32*FRACUNIT;
        break;
      default:
        break;
    }
    if (Dirn) ceiling->topheight = targheight;
    else ceiling->bottomheight = targheight;

    // set texture/type change properties
    if (ChgT)     // if a texture change is indicated
    {
      if (ChgM)   // if a numeric model change
      {
        sector_t *sec;

        //jff 5/23/98 find model with floor at target height if target
        //is a floor type
        sec = (Targ==CtoHnF || Targ==CtoF)?
          P_FindModelFloorSector(targheight,secnum) :
          P_FindModelCeilingSector(targheight,secnum);
        if (sec)
        {
          ceiling->texture = sec->ceilingpic;
          switch (ChgT)
          {
            case CChgZero:  // type is zeroed
              ceiling->newspecial = 0;
              //jff 3/14/98 change old field too
              ceiling->oldspecial = 0;
              ceiling->type = genCeilingChg0;
              break;
            case CChgTyp:   // type is copied
              ceiling->newspecial = sec->special;
              //jff 3/14/98 change old field too
              ceiling->oldspecial = sec->oldspecial;
              ceiling->type = genCeilingChgT;
              break;
            case CChgTxt:   // type is left alone
              ceiling->type = genCeilingChg;
              break;
            default:
              break;
          }
        }
      }
      else        // else if a trigger model change
      {
        ceiling->texture = LN_FRONTSECTOR(line)->ceilingpic;
        switch (ChgT)
        {
          case CChgZero:    // type is zeroed
            ceiling->newspecial = 0;
            //jff 3/14/98 change old field too
            ceiling->oldspecial = 0;
            ceiling->type = genCeilingChg0;
            break;
          case CChgTyp:     // type is copied
            ceiling->newspecial = LN_FRONTSECTOR(line)->special;
            //jff 3/14/98 change old field too
            ceiling->oldspecial = LN_FRONTSECTOR(line)->oldspecial;
            ceiling->type = genCeilingChgT;
            break;
          case CChgTxt:     // type is left alone
            ceiling->type = genCeilingChg;
            break;
          default:
            break;
        }
      }
    }
    P_AddActiveCeiling(ceiling);  // add this ceiling to the active list
    if (manual) return rtn;
  }
  return rtn;
}

//
// EV_DoGenLift()
//
// Handle generalized lift types
//
// Passed the linedef activating the lift
// Returns true if a thinker is created
//
int EV_DoGenLift
( const line_t*       line )
{
  plat_t*         plat;
  int             secnum;
  int             rtn;
  boolean         manual;
  sector_t*       sec;
  unsigned        value = (unsigned)LN_SPECIAL(line) - GenLiftBase;

  // parse the bit fields in the line's special type

  int Targ = (value & LiftTarget) >> LiftTargetShift;
  int Dely = (value & LiftDelay) >> LiftDelayShift;
  int Sped = (value & LiftSpeed) >> LiftSpeedShift;
  int Trig = (value & TriggerType) >> TriggerTypeShift;

  secnum = -1;
  rtn = 0;

  // Activate all <type> plats that are in_stasis

  if (Targ==LnF2HnF)
    P_ActivateInStasis(line->tag);

  // check if a manual trigger, if so do just the sector on the backside
  manual = false;
  if (Trig==PushOnce || Trig==PushMany)
  {
    if (!(sec = LN_BACKSECTOR(line)))
      return rtn;
    secnum = sec-_g->sectors;
    manual = true;
    goto manual_lift;
  }

  // if not manual do all sectors tagged the same as the line
  while ((secnum = P_FindSectorFromLineTag(line,secnum)) >= 0)
  {
    sec = &_g->sectors[secnum];

manual_lift:
    // Do not start another function if floor already moving
    if (P_SectorActive(floor_special,sec))
    {
      if (!manual)
        continue;
      else
        return rtn;
    }

    // Setup the plat thinker
    rtn = 1;
    plat = Z_Malloc( sizeof(*plat), PU_LEVSPEC, 0);
    memset(plat, 0, sizeof(*plat));
    P_AddThinker(&plat->thinker);

    plat->sector = sec;
    plat->sector->floordata = plat;
    plat->thinker.function = T_PlatRaise;
    plat->crush = false;
    plat->tag = line->tag;

    plat->type = genLift;
    plat->high = sec->floorheight;
    plat->status = down;

    // setup the target destination height
    switch(Targ)
    {
      case F2LnF:
        plat->low = P_FindLowestFloorSurrounding(sec);
        if (plat->low > sec->floorheight)
          plat->low = sec->floorheight;
        break;
      case F2NnF:
        plat->low = P_FindNextLowestFloor(sec,sec->floorheight);
        break;
      case F2LnC:
        plat->low = P_FindLowestCeilingSurrounding(sec);
        if (plat->low > sec->floorheight)
          plat->low = sec->floorheight;
        break;
      case LnF2HnF:
        plat->type = genPerpetual;
        plat->low = P_FindLowestFloorSurrounding(sec);
        if (plat->low > sec->floorheight)
          plat->low = sec->floorheight;
        plat->high = P_FindHighestFloorSurrounding(sec);
        if (plat->high < sec->floorheight)
          plat->high = sec->floorheight;
        plat->status = P_Random()&1;
        break;
      default:
        break;
    }

    // setup the speed of motion
    switch(Sped)
    {
      case SpeedSlow:
        plat->speed = PLATSPEED * 2;
        break;
      case SpeedNormal:
        plat->speed = PLATSPEED * 4;
        break;
      case SpeedFast:
        plat->speed = PLATSPEED * 8;
        break;
      case SpeedTurbo:
        plat->speed = PLATSPEED * 16;
        break;
      default:
        break;
    }

    // setup the delay time before the floor returns
    switch(Dely)
    {
      case 0:
        plat->wait = 1*35;
        break;
      case 1:
        plat->wait = PLATWAIT*35;
        break;
      case 2:
        plat->wait = 5*35;
        break;
      case 3:
        plat->wait = 10*35;
        break;
    }

    S_StartSound2(&sec->soundorg,sfx_pstart);
    P_AddActivePlat(plat); // add this plat to the list of active plats

    if (manual)
      return rtn;
  }
  return rtn;
}

//
// EV_DoGenStairs()
//
// Handle generalized stair building
//
// Passed the linedef activating the stairs
// Returns true if a thinker is created
//
int EV_DoGenStairs
( const line_t*       line )
{
  int                   secnum;
  int                   osecnum; //jff 3/4/98 preserve loop index
  int                   height;
  int                   i;
  int                   newsecnum;
  int                   texture;
  int                   ok;
  int                   rtn;
  boolean               manual;

  sector_t*             sec;
  sector_t*             tsec;

  floormove_t*  floor;

  fixed_t               stairsize;
  fixed_t               speed;

  unsigned              value = (unsigned)LN_SPECIAL(line) - GenStairsBase;

  // parse the bit fields in the line's special type

  int Igno = (value & StairIgnore) >> StairIgnoreShift;
  int Dirn = (value & StairDirection) >> StairDirectionShift;
  int Step = (value & StairStep) >> StairStepShift;
  int Sped = (value & StairSpeed) >> StairSpeedShift;
  int Trig = (value & TriggerType) >> TriggerTypeShift;

  rtn = 0;

  // check if a manual trigger, if so do just the sector on the backside
  manual = false;
  if (Trig==PushOnce || Trig==PushMany)
  {
    if (!(sec = LN_BACKSECTOR(line)))
      return rtn;
    secnum = sec-_g->sectors;
    manual = true;
    goto manual_stair;
  }

  secnum = -1;
  // if not manual do all sectors tagged the same as the line
  while ((secnum = P_FindSectorFromLineTag(line,secnum)) >= 0)
  {
    sec = &_g->sectors[secnum];

manual_stair:
    //Do not start another function if floor already moving
    //jff 2/26/98 add special lockout condition to wait for entire
    //staircase to build before retriggering
    if (P_SectorActive(floor_special,sec))
    {
      if (!manual)
        continue;
      else
        return rtn;
    }

    // new floor thinker
    rtn = 1;
    floor = Z_Malloc (sizeof(*floor), PU_LEVSPEC, 0);
    memset(floor, 0, sizeof(*floor));
    P_AddThinker (&floor->thinker);
    sec->floordata = floor;
    floor->thinker.function = T_MoveFloor;
    floor->direction = Dirn? 1 : -1;
    floor->sector = sec;

    // setup speed of stair building
    switch(Sped)
      {
      default:
      case SpeedSlow:
        floor->speed = FLOORSPEED/4;
        break;
      case SpeedNormal:
        floor->speed = FLOORSPEED/2;
        break;
      case SpeedFast:
        floor->speed = FLOORSPEED*2;
        break;
      case SpeedTurbo:
        floor->speed = FLOORSPEED*4;
        break;
      }

    // setup stepsize for stairs
    switch(Step)
    {
      default:
      case 0:
        stairsize = 4*FRACUNIT;
        break;
      case 1:
        stairsize = 8*FRACUNIT;
        break;
      case 2:
        stairsize = 16*FRACUNIT;
        break;
      case 3:
        stairsize = 24*FRACUNIT;
        break;
    }

    speed = floor->speed;
    height = sec->floorheight + floor->direction * stairsize;
    floor->floordestheight = height;
    texture = sec->floorpic;
    floor->crush = false;
    floor->type = genBuildStair; // jff 3/31/98 do not leave uninited

    osecnum = secnum;            //jff 3/4/98 preserve loop index
    // Find next sector to raise
    // 1.     Find 2-sided line with same sector side[0]
    // 2.     Other side is the next sector to raise
    do
    {
      ok = 0;
      for (i = 0;i < sec->linecount;i++)
      {


        if ( !LN_BACKSECTOR((sec->lines[i])) )
          continue;

        tsec = LN_FRONTSECTOR((sec->lines[i]));
        newsecnum = tsec-_g->sectors;

        if (secnum != newsecnum)
          continue;

        tsec = LN_BACKSECTOR((sec->lines[i]));
        newsecnum = tsec - _g->sectors;

        if (!Igno && tsec->floorpic != texture)
          continue;


        //jff 2/26/98 special lockout condition for retriggering
        if (P_SectorActive(floor_special,tsec))
          continue;

        height += floor->direction * stairsize;

        sec = tsec;
        secnum = newsecnum;
        floor = Z_Malloc (sizeof(*floor), PU_LEVSPEC, 0);

        memset(floor, 0, sizeof(*floor));
        P_AddThinker (&floor->thinker);

        sec->floordata = floor;
        floor->thinker.function = T_MoveFloor;
        floor->direction = Dirn? 1 : -1;
        floor->sector = sec;
        floor->speed = speed;
        floor->floordestheight = height;
        floor->crush = false;
        floor->type = genBuildStair; // jff 3/31/98 do not leave uninited

        ok = 1;
        break;
      }
    } while(ok);
      if (manual)
        return rtn;
      secnum = osecnum; //jff 3/4/98 restore old loop index
  }
  // retriggerable generalized stairs build up or down alternately
  if (rtn)
    LN_SPECIAL(line) ^= StairDirection; // alternate dir on succ activations
  return rtn;
}

//
// EV_DoGenCrusher()
//
// Handle generalized crusher types
//
// Passed the linedef activating the crusher
// Returns true if a thinker created
//
int EV_DoGenCrusher
( const line_t*       line )
{
  int                   secnum;
  int                   rtn;
  boolean               manual;
  sector_t*             sec;
  ceiling_t*            ceiling;
  unsigned              value = (unsigned)LN_SPECIAL(line) - GenCrusherBase;

  // parse the bit fields in the line's special type

  int Slnt = (value & CrusherSilent) >> CrusherSilentShift;
  int Sped = (value & CrusherSpeed) >> CrusherSpeedShift;
  int Trig = (value & TriggerType) >> TriggerTypeShift;

  //jff 2/22/98  Reactivate in-stasis ceilings...for certain types.
  //jff 4/5/98 return if activated
  rtn = P_ActivateInStasisCeiling(line);

  // check if a manual trigger, if so do just the sector on the backside
  manual = false;
  if (Trig==PushOnce || Trig==PushMany)
  {
    if (!(sec = LN_BACKSECTOR(line)))
      return rtn;
    secnum = sec-_g->sectors;
    manual = true;
    goto manual_crusher;
  }

  secnum = -1;
  // if not manual do all sectors tagged the same as the line
  while ((secnum = P_FindSectorFromLineTag(line,secnum)) >= 0)
  {
    sec = &_g->sectors[secnum];

manual_crusher:
    // Do not start another function if ceiling already moving
    if (P_SectorActive(ceiling_special,sec)) //jff 2/22/98
    {
      if (!manual)
        continue;
      else
        return rtn;
    }

    // new ceiling thinker
    rtn = 1;
    ceiling = Z_Malloc (sizeof(*ceiling), PU_LEVSPEC, 0);
    memset(ceiling, 0, sizeof(*ceiling));
    P_AddThinker (&ceiling->thinker);
    sec->ceilingdata = ceiling; //jff 2/22/98
    ceiling->thinker.function = T_MoveCeiling;
    ceiling->crush = true;
    ceiling->direction = -1;
    ceiling->sector = sec;
    ceiling->texture = sec->ceilingpic;
    ceiling->newspecial = sec->special;
    ceiling->tag = sec->tag;
    ceiling->type = Slnt? genSilentCrusher : genCrusher;
    ceiling->topheight = sec->ceilingheight;
    ceiling->bottomheight = sec->floorheight + (8*FRACUNIT);

    // setup ceiling motion speed
    switch (Sped)
    {
      case SpeedSlow:
        ceiling->speed = CEILSPEED;
        break;
      case SpeedNormal:
        ceiling->speed = CEILSPEED*2;
        break;
      case SpeedFast:
        ceiling->speed = CEILSPEED*4;
        break;
      case SpeedTurbo:
        ceiling->speed = CEILSPEED*8;
        break;
      default:
        break;
    }
    ceiling->oldspeed=ceiling->speed;

    P_AddActiveCeiling(ceiling);  // add to list of active ceilings
    if (manual) return rtn;
  }
  return rtn;
}

//
// EV_DoGenLockedDoor()
//
// Handle generalized locked door types
//
// Passed the linedef activating the generalized locked door
// Returns true if a thinker created
//
int EV_DoGenLockedDoor
( const line_t* line )
{
  int   secnum,rtn;
  sector_t* sec;
  vldoor_t* door;
  boolean manual;
  unsigned  value = (unsigned)LN_SPECIAL(line) - GenLockedBase;

  // parse the bit fields in the line's special type

  int Kind = (value & LockedKind) >> LockedKindShift;
  int Sped = (value & LockedSpeed) >> LockedSpeedShift;
  int Trig = (value & TriggerType) >> TriggerTypeShift;

  rtn = 0;

  // check if a manual trigger, if so do just the sector on the backside
  manual = false;
  if (Trig==PushOnce || Trig==PushMany)
  {
    if (!(sec = LN_BACKSECTOR(line)))
      return rtn;
    secnum = sec-_g->sectors;
    manual = true;
    goto manual_locked;
  }

  secnum = -1;
  rtn = 0;

  // if not manual do all sectors tagged the same as the line
  while ((secnum = P_FindSectorFromLineTag(line,secnum)) >= 0)
  {
    sec = &_g->sectors[secnum];
manual_locked:
    // Do not start another function if ceiling already moving
    if (P_SectorActive(ceiling_special,sec)) //jff 2/22/98
    {
      if (!manual)
        continue;
      else
        return rtn;
    }

    // new door thinker
    rtn = 1;
    door = Z_Malloc (sizeof(*door), PU_LEVSPEC, 0);
    memset(door, 0, sizeof(*door));
    P_AddThinker (&door->thinker);
    sec->ceilingdata = door; //jff 2/22/98

    door->thinker.function = T_VerticalDoor;
    door->sector = sec;
    door->topwait = VDOORWAIT;
    door->line = line;
    door->topheight = P_FindLowestCeilingSurrounding(sec);
    door->topheight -= 4*FRACUNIT;
    door->direction = 1;

    /* killough 10/98: implement gradual lighting */
    door->lighttag = (LN_SPECIAL(line)&6) == 6 &&
      LN_SPECIAL(line) > GenLockedBase ? line->tag : 0;

    // setup speed of door motion
    switch(Sped)
    {
      default:
      case SpeedSlow:
        door->type = Kind? genOpen : genRaise;
        door->speed = VDOORSPEED;
        break;
      case SpeedNormal:
        door->type = Kind? genOpen : genRaise;
        door->speed = VDOORSPEED*2;
        break;
      case SpeedFast:
        door->type = Kind? genBlazeOpen : genBlazeRaise;
        door->speed = VDOORSPEED*4;
        break;
      case SpeedTurbo:
        door->type = Kind? genBlazeOpen : genBlazeRaise;
        door->speed = VDOORSPEED*8;

        break;
    }

    // killough 4/15/98: fix generalized door opening sounds
    // (previously they always had the blazing door close sound)

    S_StartSound2(&door->sector->soundorg,   // killough 4/15/98
                 door->speed >= VDOORSPEED*4 ? sfx_bdopn : sfx_doropn);

    if (manual)
      return rtn;
  }
  return rtn;
}

//
// EV_DoGenDoor()
//
// Handle generalized door types
//
// Passed the linedef activating the generalized door
// Returns true if a thinker created
//
int EV_DoGenDoor
( const line_t* line )
{
  int   secnum,rtn;
  sector_t* sec;
  boolean   manual;
  vldoor_t* door;
  unsigned  value = (unsigned)LN_SPECIAL(line) - GenDoorBase;

  // parse the bit fields in the line's special type

  int Dely = (value & DoorDelay) >> DoorDelayShift;
  int Kind = (value & DoorKind) >> DoorKindShift;
  int Sped = (value & DoorSpeed) >> DoorSpeedShift;
  int Trig = (value & TriggerType) >> TriggerTypeShift;

  rtn = 0;

  // check if a manual trigger, if so do just the sector on the backside
  manual = false;
  if (Trig==PushOnce || Trig==PushMany)
  {
    if (!(sec = LN_BACKSECTOR(line)))
      return rtn;
    secnum = sec-_g->sectors;
    manual = true;
    goto manual_door;
  }


  secnum = -1;
  rtn = 0;

  // if not manual do all sectors tagged the same as the line
  while ((secnum = P_FindSectorFromLineTag(line,secnum)) >= 0)
  {
    sec = &_g->sectors[secnum];
manual_door:
    // Do not start another function if ceiling already moving
    if (P_SectorActive(ceiling_special,sec)) //jff 2/22/98
    {
      if (!manual)
        continue;
      else
        return rtn;
    }

    // new door thinker
    rtn = 1;
    door = Z_Malloc (sizeof(*door), PU_LEVSPEC, 0);
    memset(door, 0, sizeof(*door));
    P_AddThinker (&door->thinker);
    sec->ceilingdata = door; //jff 2/22/98

    door->thinker.function = T_VerticalDoor;
    door->sector = sec;
    // setup delay for door remaining open/closed
    switch(Dely)
    {
      default:
      case 0:
        door->topwait = 35;
        break;
      case 1:
        door->topwait = VDOORWAIT;
        break;
      case 2:
        door->topwait = 2*VDOORWAIT;
        break;
      case 3:
        door->topwait = 7*VDOORWAIT;
        break;
    }

    // setup speed of door motion
    switch(Sped)
    {
      default:
      case SpeedSlow:
        door->speed = VDOORSPEED;
        break;
      case SpeedNormal:
        door->speed = VDOORSPEED*2;
        break;
      case SpeedFast:
        door->speed = VDOORSPEED*4;
        break;
      case SpeedTurbo:
        door->speed = VDOORSPEED*8;
        break;
    }
    door->line = line; // jff 1/31/98 remember line that triggered us

    /* killough 10/98: implement gradual lighting */
    door->lighttag = (LN_SPECIAL(line)&6) == 6 &&
      LN_SPECIAL(line) > GenLockedBase ? line->tag : 0;

    // set kind of door, whether it opens then close, opens, closes etc.
    // assign target heights accordingly
    switch(Kind)
    {
      case OdCDoor:
        door->direction = 1;
        door->topheight = P_FindLowestCeilingSurrounding(sec);
        door->topheight -= 4*FRACUNIT;
        if (door->topheight != sec->ceilingheight)
          S_StartSound2(&door->sector->soundorg,Sped>=SpeedFast ? sfx_bdopn : sfx_doropn);
        door->type = Sped>=SpeedFast? genBlazeRaise : genRaise;
        break;
      case ODoor:
        door->direction = 1;
        door->topheight = P_FindLowestCeilingSurrounding(sec);
        door->topheight -= 4*FRACUNIT;
        if (door->topheight != sec->ceilingheight)
          S_StartSound2(&door->sector->soundorg,Sped>=SpeedFast ? sfx_bdopn : sfx_doropn);
        door->type = Sped>=SpeedFast? genBlazeOpen : genOpen;
        break;
      case CdODoor:
        door->topheight = sec->ceilingheight;
        door->direction = -1;
        S_StartSound2(&door->sector->soundorg,Sped>=SpeedFast ? sfx_bdcls : sfx_dorcls);
        door->type = Sped>=SpeedFast? genBlazeCdO : genCdO;
        break;
      case CDoor:
        door->topheight = P_FindLowestCeilingSurrounding(sec);
        door->topheight -= 4*FRACUNIT;
        door->direction = -1;
        S_StartSound2(&door->sector->soundorg,Sped>=SpeedFast ? sfx_bdcls : sfx_dorcls);
        door->type = Sped>=SpeedFast? genBlazeClose : genClose;
        break;
      default:
        break;
    }
    if (manual)
      return rtn;
  }
  return rtn;
}
