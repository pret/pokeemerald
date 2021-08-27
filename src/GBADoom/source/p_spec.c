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
 *   -Loads and initializes texture and flat animation sequences
 *   -Implements utility functions for all linedef/sector special handlers
 *   -Dispatches walkover and gun line triggers
 *   -Initializes and implements special sector types
 *   -Implements donut linedef triggers
 *   -Initializes and implements BOOM linedef triggers for
 *     Scrollers/Conveyors
 *     Friction
 *     Wind/Current
 *
 *-----------------------------------------------------------------------------*/

#include "doomstat.h"
#include "p_spec.h"
#include "p_tick.h"
#include "p_setup.h"
#include "m_random.h"
#include "d_englsh.h"
#include "w_wad.h"
#include "r_main.h"
#include "r_data.h"
#include "p_maputl.h"
#include "p_map.h"
#include "g_game.h"
#include "p_inter.h"
#include "s_sound.h"
#include "sounds.h"
#include "m_bbox.h"                                         // phares 3/20/98
#include "r_plane.h"
#include "lprintf.h"

#include "global_data.h"

                 // no longer a strict limit -- killough


//
// P_InitPicAnims
//

// Floor/ceiling animation sequences,
//  defined by first and last frame,
//  i.e. the flat (64x64 tile) name to
//  be used.
// The full animation sequence is given
//  using all the flats between the start
//  and end entry, in the order found in
//  the WAD file.
//
const animdef_t		animdefs[] =
{
    {false,	"NUKAGE3",	"NUKAGE1",	8},
    {false,	"FWATER4",	"FWATER1",	8},
    {false,	"SWATER4",	"SWATER1", 	8},
    {false,	"LAVA4",	"LAVA1",	8},
    {false,	"BLOOD3",	"BLOOD1",	8},

    // DOOM II flat animations.
    {false,	"RROCK08",	"RROCK05",	8},
    {false,	"SLIME04",	"SLIME01",	8},
    {false,	"SLIME08",	"SLIME05",	8},
    {false,	"SLIME12",	"SLIME09",	8},

    {true,	"BLODGR4",	"BLODGR1",	8},
    {true,	"SLADRIP3",	"SLADRIP1",	8},

    {true,	"BLODRIP4",	"BLODRIP1",	8},
    {true,	"FIREWALL",	"FIREWALA",	8},
    {true,	"GSTFONT3",	"GSTFONT1",	8},
    {true,	"FIRELAVA",	"FIRELAV3",	8},
    {true,	"FIREMAG3",	"FIREMAG1",	8},
    {true,	"FIREBLU2",	"FIREBLU1",	8},
    {true,	"ROCKRED3",	"ROCKRED1",	8},

    {true,	"BFALL4",	"BFALL1",	8},
    {true,	"SFALL4",	"SFALL1",	8},
    {true,	"WFALL4",	"WFALL1",	8},
    {true,	"DBRAIN4",	"DBRAIN1",	8},

    {-1}
};


// killough 3/7/98: Initialize generalized scrolling
static void P_SpawnScrollers(void);

//
// P_InitPicAnims
//
// Load the table of animation definitions, checking for existence of
// the start and end of each frame. If the start doesn't exist the sequence
// is skipped, if the last doesn't exist, BOOM exits.
//
// Wall/Flat animation sequences, defined by name of first and last frame,
// The full animation sequence is given using all lumps between the start
// and end entry, in the order found in the WAD file.
//
// This routine modified to read its data from a predefined lump or
// PWAD lump called ANIMATED rather than a static table in this module to
// allow wad designers to insert or modify animation sequences.
//
// Lump format is an array of byte packed animdef_t structures, terminated
// by a structure with istexture == -1. The lump can be generated from a
// text source file using SWANTBLS.EXE, distributed with the BOOM utils.
// The standard list of switches and animations is contained in the example
// source text file DEFSWANI.DAT also in the BOOM util distribution.
//
//
void P_InitPicAnims (void)
{
    int		i;

    //	Init animation
    _g->lastanim = _g->anims;
    for (i=0 ; animdefs[i].istexture != -1 ; i++)
    {
        if (animdefs[i].istexture)
        {
            // different episode ?
            if (R_CheckTextureNumForName(animdefs[i].startname) == -1)
                continue;

            _g->lastanim->picnum = R_CheckTextureNumForName (animdefs[i].endname);
            _g->lastanim->basepic = R_CheckTextureNumForName (animdefs[i].startname);
        }
        else
        {
            if (W_CheckNumForName(animdefs[i].startname) == -1)
                continue;

            _g->lastanim->picnum = R_FlatNumForName (animdefs[i].endname);
            _g->lastanim->basepic = R_FlatNumForName (animdefs[i].startname);
        }

        _g->lastanim->istexture = animdefs[i].istexture;
        _g->lastanim->numpics = _g->lastanim->picnum - _g->lastanim->basepic + 1;

        if (_g->lastanim->numpics < 2)
            I_Error ("P_InitPicAnims: bad cycle from %s to %s",
                     animdefs[i].startname,
                     animdefs[i].endname);

        _g->lastanim->speed = animdefs[i].speed;

        _g->lastanim++;
    }

}

///////////////////////////////////////////////////////////////
//
// Linedef and Sector Special Implementation Utility Functions
//
///////////////////////////////////////////////////////////////

//
// getSide()
//
// Will return a side_t*
//  given the number of the current sector,
//  the line number, and the side (0/1) that you want.
//
// Note: if side=1 is specified, it must exist or results undefined
//
side_t* getSide
( int           currentSector,
  int           line,
  int           side )
{
  return &_g->sides[ (_g->sectors[currentSector].lines[line])->sidenum[side] ];
}


//
// getSector()
//
// Will return a sector_t*
//  given the number of the current sector,
//  the line number and the side (0/1) that you want.
//
// Note: if side=1 is specified, it must exist or results undefined
//
static sector_t* getSector
( int           currentSector,
  int           line,
  int           side )
{
  return _g->sides[ (_g->sectors[currentSector].lines[line])->sidenum[side] ].sector;
}


//
// twoSided()
//
// Given the sector number and the line number,
//  it will tell you whether the line is two-sided or not.
//
// modified to return actual two-sidedness rather than presence
// of 2S flag unless compatibility optioned
//
int twoSided
( int   sector,
  int   line )
{
  //jff 1/26/98 return what is actually needed, whether the line
  //has two sidedefs, rather than whether the 2S flag is set

  return (_g->sectors[sector].lines[line])->sidenum[1] != NO_INDEX;
}


//
// getNextSector()
//
// Return sector_t * of sector next to current across line.
//
// Note: returns NULL if not two-sided line, or both sides refer to sector
//
sector_t* getNextSector
( const line_t*       line,
  sector_t*     sec )
{


  if (LN_FRONTSECTOR(line) == sec)
  {
    if (LN_BACKSECTOR(line)!=sec)
      return LN_BACKSECTOR(line); //jff 5/3/98 don't retn sec unless compatibility
    else                       // fixes an intra-sector line breaking functions
      return NULL;             // like floor->highest floor
  }
  return LN_FRONTSECTOR(line);
}


//
// P_FindLowestFloorSurrounding()
//
// Returns the fixed point value of the lowest floor height
// in the sector passed or its surrounding sectors.
//
fixed_t P_FindLowestFloorSurrounding(sector_t* sec)
{
  int                 i;
  const line_t*             check;
  sector_t*           other;
  fixed_t             floor = sec->floorheight;

  for (i=0 ;i < sec->linecount ; i++)
  {
    check = sec->lines[i];
    other = getNextSector(check,sec);

    if (!other)
      continue;

    if (other->floorheight < floor)
      floor = other->floorheight;
  }
  return floor;
}


//
// P_FindHighestFloorSurrounding()
//
// Passed a sector, returns the fixed point value of the largest
// floor height in the surrounding sectors, not including that passed
//
// NOTE: if no surrounding sector exists -32000*FRACUINT is returned
//       if compatibility then -500*FRACUNIT is the smallest return possible
//
fixed_t P_FindHighestFloorSurrounding(sector_t *sec)
{
  int i;
  const line_t* check;
  sector_t* other;
  fixed_t floor = -500*FRACUNIT;

  //jff 1/26/98 Fix initial value for floor to not act differently
  //in sections of wad that are below -500 units
  floor = -32000*FRACUNIT;   // in height calculations

  for (i=0 ;i < sec->linecount ; i++)
  {
    check = sec->lines[i];
    other = getNextSector(check,sec);

    if (!other)
      continue;

    if (other->floorheight > floor)
      floor = other->floorheight;
  }
  return floor;
}


//
// P_FindNextHighestFloor()
//
// Passed a sector and a floor height, returns the fixed point value
// of the smallest floor height in a surrounding sector larger than
// the floor height passed. If no such height exists the floorheight
// passed is returned.
//
// Rewritten by Lee Killough to avoid fixed array and to be faster
//
fixed_t P_FindNextHighestFloor(sector_t *sec, int currentheight)
{
  sector_t *other;
  int i;

  for (i=0 ;i < sec->linecount ; i++)
    if ((other = getNextSector(sec->lines[i],sec)) &&
         other->floorheight > currentheight)
    {
      int height = other->floorheight;
      while (++i < sec->linecount)
        if ((other = getNextSector(sec->lines[i],sec)) &&
            other->floorheight < height &&
            other->floorheight > currentheight)
          height = other->floorheight;
      return height;
    }
  /* cph - my guess at doom v1.2 - 1.4beta compatibility here.
   * If there are no higher neighbouring sectors, Heretic just returned
   * heightlist[0] (local variable), i.e. noise off the stack. 0 is right for
   * RETURN01 E1M2, so let's take that. */
  return (currentheight);
}


//
// P_FindNextLowestFloor()
//
// Passed a sector and a floor height, returns the fixed point value
// of the largest floor height in a surrounding sector smaller than
// the floor height passed. If no such height exists the floorheight
// passed is returned.
//
// jff 02/03/98 Twiddled Lee's P_FindNextHighestFloor to make this
//
fixed_t P_FindNextLowestFloor(sector_t *sec, int currentheight)
{
  sector_t *other;
  int i;

  for (i=0 ;i < sec->linecount ; i++)
    if ((other = getNextSector(sec->lines[i],sec)) &&
         other->floorheight < currentheight)
    {
      int height = other->floorheight;
      while (++i < sec->linecount)
        if ((other = getNextSector(sec->lines[i],sec)) &&
            other->floorheight > height &&
            other->floorheight < currentheight)
          height = other->floorheight;
      return height;
    }
  return currentheight;
}


//
// P_FindNextLowestCeiling()
//
// Passed a sector and a ceiling height, returns the fixed point value
// of the largest ceiling height in a surrounding sector smaller than
// the ceiling height passed. If no such height exists the ceiling height
// passed is returned.
//
// jff 02/03/98 Twiddled Lee's P_FindNextHighestFloor to make this
//
fixed_t P_FindNextLowestCeiling(sector_t *sec, int currentheight)
{
  sector_t *other;
  int i;

  for (i=0 ;i < sec->linecount ; i++)
    if ((other = getNextSector(sec->lines[i],sec)) &&
        other->ceilingheight < currentheight)
    {
      int height = other->ceilingheight;
      while (++i < sec->linecount)
        if ((other = getNextSector(sec->lines[i],sec)) &&
            other->ceilingheight > height &&
            other->ceilingheight < currentheight)
          height = other->ceilingheight;
      return height;
    }
  return currentheight;
}


//
// P_FindNextHighestCeiling()
//
// Passed a sector and a ceiling height, returns the fixed point value
// of the smallest ceiling height in a surrounding sector larger than
// the ceiling height passed. If no such height exists the ceiling height
// passed is returned.
//
// jff 02/03/98 Twiddled Lee's P_FindNextHighestFloor to make this
//
fixed_t P_FindNextHighestCeiling(sector_t *sec, int currentheight)
{
  sector_t *other;
  int i;

  for (i=0 ;i < sec->linecount ; i++)
    if ((other = getNextSector(sec->lines[i],sec)) &&
         other->ceilingheight > currentheight)
    {
      int height = other->ceilingheight;
      while (++i < sec->linecount)
        if ((other = getNextSector(sec->lines[i],sec)) &&
            other->ceilingheight < height &&
            other->ceilingheight > currentheight)
          height = other->ceilingheight;
      return height;
    }
  return currentheight;
}


//
// P_FindLowestCeilingSurrounding()
//
// Passed a sector, returns the fixed point value of the smallest
// ceiling height in the surrounding sectors, not including that passed
//
// NOTE: if no surrounding sector exists 32000*FRACUINT is returned
//       but if compatibility then INT_MAX is the return
//
fixed_t P_FindLowestCeilingSurrounding(sector_t* sec)
{
  int                 i;
  const line_t*             check;
  sector_t*           other;
  fixed_t             height = INT_MAX;

  /* jff 3/12/98 avoid ovf in height calculations */
    height = 32000*FRACUNIT;

  for (i=0 ;i < sec->linecount ; i++)
  {
    check = sec->lines[i];
    other = getNextSector(check,sec);

    if (!other)
      continue;

    if (other->ceilingheight < height)
      height = other->ceilingheight;
  }
  return height;
}


//
// P_FindHighestCeilingSurrounding()
//
// Passed a sector, returns the fixed point value of the largest
// ceiling height in the surrounding sectors, not including that passed
//
// NOTE: if no surrounding sector exists -32000*FRACUINT is returned
//       but if compatibility then 0 is the smallest return possible
//
fixed_t P_FindHighestCeilingSurrounding(sector_t* sec)
{
  int             i;
  const line_t* check;
  sector_t*       other;
  fixed_t height = 0;

  /* jff 1/26/98 Fix initial value for floor to not act differently
   * in sections of wad that are below 0 units
   * jff 3/12/98 avoid ovf in height calculations */
    height = -32000*FRACUNIT;

  for (i=0 ;i < sec->linecount ; i++)
  {
    check = sec->lines[i];
    other = getNextSector(check,sec);

    if (!other)
      continue;

    if (other->ceilingheight > height)
      height = other->ceilingheight;
  }
  return height;
}


//
// P_FindShortestTextureAround()
//
// Passed a sector number, returns the shortest lower texture on a
// linedef bounding the sector.
//
// Note: If no lower texture exists 32000*FRACUNIT is returned.
//       but if compatibility then INT_MAX is returned
//
// jff 02/03/98 Add routine to find shortest lower texture
//
fixed_t P_FindShortestTextureAround(int secnum)
{
  int minsize = INT_MAX;
  side_t*     side;
  int i;
  sector_t *sec = &_g->sectors[secnum];

    minsize = 32000<<FRACBITS; //jff 3/13/98 prevent overflow in height calcs

  for (i = 0; i < sec->linecount; i++)
  {
    if (twoSided(secnum, i))
    {
      side = getSide(secnum,i,0);
      if (side->bottomtexture > 0)  //jff 8/14/98 texture 0 is a placeholder
        if (textureheight[side->bottomtexture] < minsize)
          minsize = textureheight[side->bottomtexture];
      side = getSide(secnum,i,1);
      if (side->bottomtexture > 0)  //jff 8/14/98 texture 0 is a placeholder
        if (textureheight[side->bottomtexture] < minsize)
          minsize = textureheight[side->bottomtexture];
    }
  }
  return minsize;
}


//
// P_FindShortestUpperAround()
//
// Passed a sector number, returns the shortest upper texture on a
// linedef bounding the sector.
//
// Note: If no upper texture exists 32000*FRACUNIT is returned.
//       but if compatibility then INT_MAX is returned
//
// jff 03/20/98 Add routine to find shortest upper texture
//
fixed_t P_FindShortestUpperAround(int secnum)
{
  int minsize = INT_MAX;
  side_t*     side;
  int i;
  sector_t *sec = &_g->sectors[secnum];

    minsize = 32000<<FRACBITS; //jff 3/13/98 prevent overflow
                               // in height calcs
  for (i = 0; i < sec->linecount; i++)
  {
    if (twoSided(secnum, i))
    {
      side = getSide(secnum,i,0);
      if (side->toptexture > 0)     //jff 8/14/98 texture 0 is a placeholder
        if (textureheight[side->toptexture] < minsize)
          minsize = textureheight[side->toptexture];
      side = getSide(secnum,i,1);
      if (side->toptexture > 0)     //jff 8/14/98 texture 0 is a placeholder
        if (textureheight[side->toptexture] < minsize)
          minsize = textureheight[side->toptexture];
    }
  }
  return minsize;
}


//
// P_FindModelFloorSector()
//
// Passed a floor height and a sector number, return a pointer to a
// a sector with that floor height across the lowest numbered two sided
// line surrounding the sector.
//
// Note: If no sector at that height bounds the sector passed, return NULL
//
// jff 02/03/98 Add routine to find numeric model floor
//  around a sector specified by sector number
// jff 3/14/98 change first parameter to plain height to allow call
//  from routine not using floormove_t
//
sector_t *P_FindModelFloorSector(fixed_t floordestheight,int secnum)
{
  int i;
  sector_t *sec=NULL;
  int linecount;

  sec = &_g->sectors[secnum]; //jff 3/2/98 woops! better do this
  //jff 5/23/98 don't disturb sec->linecount while searching
  // but allow early exit in old demos
  linecount = sec->linecount;
  for (i = 0; i < (linecount); i++)
  {
    if ( twoSided(secnum, i) )
    {
      if (getSide(secnum,i,0)->sector-_g->sectors == secnum)
          sec = getSector(secnum,i,1);
      else
          sec = getSector(secnum,i,0);

      if (sec->floorheight == floordestheight)
        return sec;
    }
  }
  return NULL;
}


//
// P_FindModelCeilingSector()
//
// Passed a ceiling height and a sector number, return a pointer to a
// a sector with that ceiling height across the lowest numbered two sided
// line surrounding the sector.
//
// Note: If no sector at that height bounds the sector passed, return NULL
//
// jff 02/03/98 Add routine to find numeric model ceiling
//  around a sector specified by sector number
//  used only from generalized ceiling types
// jff 3/14/98 change first parameter to plain height to allow call
//  from routine not using ceiling_t
//
sector_t *P_FindModelCeilingSector(fixed_t ceildestheight,int secnum)
{
  int i;
  sector_t *sec=NULL;
  int linecount;

  sec = &_g->sectors[secnum]; //jff 3/2/98 woops! better do this
  //jff 5/23/98 don't disturb sec->linecount while searching
  // but allow early exit in old demos
  linecount = sec->linecount;
  for (i = 0; i < (linecount); i++)
  {
    if ( twoSided(secnum, i) )
    {
      if (getSide(secnum,i,0)->sector-_g->sectors == secnum)
          sec = getSector(secnum,i,1);
      else
          sec = getSector(secnum,i,0);

      if (sec->ceilingheight == ceildestheight)
        return sec;
    }
  }
  return NULL;
}

//
// RETURN NEXT SECTOR # THAT LINE TAG REFERS TO
//
int P_FindSectorFromLineTag(const line_t* line, int start)
{
    int	i;

    for (i=start+1; i<_g->numsectors; i++)
    {
        if (_g->sectors[i].tag == line->tag)
            return i;
    }

    return -1;
}


// killough 4/16/98: Same thing, only for linedefs

int P_FindLineFromLineTag(const line_t *line, int start)
{

    int	i;

    for (i=start+1; i<_g->numlines; i++)
    {
        if (_g->lines[i].tag == line->tag)
            return i;
    }

    return -1;
}

// Hash the sector tags across the sectors and linedefs.
static void P_InitTagLists(void)
{

}

//
// P_FindMinSurroundingLight()
//
// Passed a sector and a light level, returns the smallest light level
// in a surrounding sector less than that passed. If no smaller light
// level exists, the light level passed is returned.
//
int P_FindMinSurroundingLight
( sector_t*     sector,
  int           max )
{
  int         i;
  int         min;
  const line_t*     line;
  sector_t*   check;

  min = max;
  for (i=0 ; i < sector->linecount ; i++)
  {
    line = sector->lines[i];
    check = getNextSector(line,sector);

    if (!check)
      continue;

    if (check->lightlevel < min)
      min = check->lightlevel;
  }
  return min;
}


//
// P_CanUnlockGenDoor()
//
// Passed a generalized locked door linedef and a player, returns whether
// the player has the keys necessary to unlock that door.
//
// Note: The linedef passed MUST be a generalized locked door type
//       or results are undefined.
//
// jff 02/05/98 routine added to test for unlockability of
//  generalized locked doors
//
boolean P_CanUnlockGenDoor
( const line_t* line,
  player_t* player)
{
  // does this line special distinguish between skulls and keys?
  int skulliscard = (LN_SPECIAL(line) & LockedNKeys)>>LockedNKeysShift;

  // determine for each case of lock type if player's keys are adequate
  switch((LN_SPECIAL(line) & LockedKey)>>LockedKeyShift)
  {
    case AnyKey:
      if
      (
        !player->cards[it_redcard] &&
        !player->cards[it_redskull] &&
        !player->cards[it_bluecard] &&
        !player->cards[it_blueskull] &&
        !player->cards[it_yellowcard] &&
        !player->cards[it_yellowskull]
      )
      {
        player->message = PD_ANY; // Ty 03/27/98 - externalized
        S_StartSound(player->mo,sfx_oof);             // killough 3/20/98
        return false;
      }
      break;
    case RCard:
      if
      (
        !player->cards[it_redcard] &&
        (!skulliscard || !player->cards[it_redskull])
      )
      {
        player->message = skulliscard? PD_REDK : PD_REDC; // Ty 03/27/98 - externalized
        S_StartSound(player->mo,sfx_oof);             // killough 3/20/98
        return false;
      }
      break;
    case BCard:
      if
      (
        !player->cards[it_bluecard] &&
        (!skulliscard || !player->cards[it_blueskull])
      )
      {
        player->message = skulliscard? PD_BLUEK : PD_BLUEC; // Ty 03/27/98 - externalized
        S_StartSound(player->mo,sfx_oof);             // killough 3/20/98
        return false;
      }
      break;
    case YCard:
      if
      (
        !player->cards[it_yellowcard] &&
        (!skulliscard || !player->cards[it_yellowskull])
      )
      {
        player->message = skulliscard? PD_YELLOWK : PD_YELLOWC; // Ty 03/27/98 - externalized
        S_StartSound(player->mo,sfx_oof);             // killough 3/20/98
        return false;
      }
      break;
    case RSkull:
      if
      (
        !player->cards[it_redskull] &&
        (!skulliscard || !player->cards[it_redcard])
      )
      {
        player->message = skulliscard? PD_REDK : PD_REDS; // Ty 03/27/98 - externalized
        S_StartSound(player->mo,sfx_oof);             // killough 3/20/98
        return false;
      }
      break;
    case BSkull:
      if
      (
        !player->cards[it_blueskull] &&
        (!skulliscard || !player->cards[it_bluecard])
      )
      {
        player->message = skulliscard? PD_BLUEK : PD_BLUES; // Ty 03/27/98 - externalized
        S_StartSound(player->mo,sfx_oof);             // killough 3/20/98
        return false;
      }
      break;
    case YSkull:
      if
      (
        !player->cards[it_yellowskull] &&
        (!skulliscard || !player->cards[it_yellowcard])
      )
      {
        player->message = skulliscard? PD_YELLOWK : PD_YELLOWS; // Ty 03/27/98 - externalized
        S_StartSound(player->mo,sfx_oof);             // killough 3/20/98
        return false;
      }
      break;
    case AllKeys:
      if
      (
        !skulliscard &&
        (
          !player->cards[it_redcard] ||
          !player->cards[it_redskull] ||
          !player->cards[it_bluecard] ||
          !player->cards[it_blueskull] ||
          !player->cards[it_yellowcard] ||
          !player->cards[it_yellowskull]
        )
      )
      {
        player->message = PD_ALL6; // Ty 03/27/98 - externalized
        S_StartSound(player->mo,sfx_oof);             // killough 3/20/98
        return false;
      }
      if
      (
        skulliscard &&
        (
          (!player->cards[it_redcard] &&
            !player->cards[it_redskull]) ||
          (!player->cards[it_bluecard] &&
            !player->cards[it_blueskull]) ||
          (!player->cards[it_yellowcard] &&
            !player->cards[it_yellowskull])
        )
      )
      {
        player->message = PD_ALL3; // Ty 03/27/98 - externalized
        S_StartSound(player->mo,sfx_oof);             // killough 3/20/98
        return false;
      }
      break;
  }
  return true;
}


//
// P_SectorActive()
//
// Passed a linedef special class (floor, ceiling, lighting) and a sector
// returns whether the sector is already busy with a linedef special of the
// same class. If old demo compatibility true, all linedef special classes
// are the same.
//
// jff 2/23/98 added to prevent old demos from
//  succeeding in starting multiple specials on one sector
//
boolean PUREFUNC P_SectorActive(special_e t, const sector_t *sec)
{
    switch (t)             // return whether thinker of same type is active
    {
      case floor_special:
        return sec->floordata != NULL;
      case ceiling_special:
        return sec->ceilingdata != NULL;
      case lighting_special:
        return false;
    }
  return true; // don't know which special, must be active, shouldn't be here
}


//
// P_CheckTag()
//
// Passed a line, returns true if the tag is non-zero or the line special
// allows no tag without harm. If compatibility, all linedef specials are
// allowed to have zero tag.
//
// Note: Only line specials activated by walkover, pushing, or shooting are
//       checked by this routine.
//
// jff 2/27/98 Added to check for zero tag allowed for regular special types
//
int P_CheckTag(const line_t *line)
{
  /* tag not zero, allowed, or
   * killough 11/98: compatibility option */
  if (line->tag)
    return 1;

  switch(LN_SPECIAL(line))
  {
    case 1:                 // Manual door specials
    case 26:
    case 27:
    case 28:
    case 31:
    case 32:
    case 33:
    case 34:
    case 117:
    case 118:

    case 139:               // Lighting specials
    case 170:
    case 79:
    case 35:
    case 138:
    case 171:
    case 81:
    case 13:
    case 192:
    case 169:
    case 80:
    case 12:
    case 194:
    case 173:
    case 157:
    case 104:
    case 193:
    case 172:
    case 156:
    case 17:

    case 195:               // Thing teleporters
    case 174:
    case 97:
    case 39:
    case 126:
    case 125:
    case 210:
    case 209:
    case 208:
    case 207:

    case 11:                // Exits
    case 52:
    case 197:
    case 51:
    case 124:
    case 198:

    case 48:                // Scrolling walls
    case 85:
      return 1;   // zero tag allowed

    default:
      break;
  }
  return 0;       // zero tag not allowed
}


//
// P_IsSecret()
//
// Passed a sector, returns if the sector secret type is still active, i.e.
// secret type is set and the secret has not yet been obtained.
//
// jff 3/14/98 added to simplify checks for whether sector is secret
//  in automap and other places
//
boolean PUREFUNC P_IsSecret(const sector_t *sec)
{
  return (sec->special==9 || (sec->special&SECRET_MASK));
}


//
// P_WasSecret()
//
// Passed a sector, returns if the sector secret type is was active, i.e.
// secret type was set and the secret has been obtained already.
//
// jff 3/14/98 added to simplify checks for whether sector is secret
//  in automap and other places
//
boolean PUREFUNC P_WasSecret(const sector_t *sec)
{
  return (sec->oldspecial==9 || (sec->oldspecial&SECRET_MASK));
}


//////////////////////////////////////////////////////////////////////////
//
// Events
//
// Events are operations triggered by using, crossing,
// or shooting special lines, or by timed thinkers.
//
/////////////////////////////////////////////////////////////////////////

//
// P_CrossSpecialLine - Walkover Trigger Dispatcher
//
// Called every time a thing origin is about
//  to cross a line with a non 0 special, whether a walkover type or not.
//
// jff 02/12/98 all W1 lines were fixed to check the result from the EV_
//  function before clearing the special. This avoids losing the function
//  of the line, should the sector already be active when the line is
//  crossed. Change is qualified by demo_compatibility.
//
// CPhipps - take a line_t pointer instead of a line number, as in MBF
void P_CrossSpecialLine(const line_t *line, int side, mobj_t *thing)
{
  int         ok;

  //  Things that should never trigger lines
  if (!thing->player)
  {
    // Things that should NOT trigger specials...
    switch(thing->type)
    {
      case MT_ROCKET:
      case MT_PLASMA:
      case MT_BFG:
      case MT_TROOPSHOT:
      case MT_HEADSHOT:
      case MT_BRUISERSHOT:
        return;

      default: break;
    }
  }


    // pointer to line function is NULL by default, set non-null if
    // line special is walkover generalized linedef type
    int (*linefunc)(const line_t *line)=NULL;

    // check each range of generalized linedefs
    if ((unsigned)LN_SPECIAL(line) >= GenEnd)
    {
      // Out of range for GenFloors
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenFloorBase)
    {
      if (!thing->player)
        if ((LN_SPECIAL(line) & FloorChange) || !(LN_SPECIAL(line) & FloorModel))
          return;     // FloorModel is "Allow Monsters" if FloorChange is 0
      if (!line->tag) //jff 2/27/98 all walk generalized types require tag
        return;
      linefunc = EV_DoGenFloor;
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenCeilingBase)
    {
      if (!thing->player)
        if ((LN_SPECIAL(line) & CeilingChange) || !(LN_SPECIAL(line) & CeilingModel))
          return;     // CeilingModel is "Allow Monsters" if CeilingChange is 0
      if (!line->tag) //jff 2/27/98 all walk generalized types require tag
        return;
      linefunc = EV_DoGenCeiling;
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenDoorBase)
    {
      if (!thing->player)
      {
        if (!(LN_SPECIAL(line) & DoorMonster))
          return;                    // monsters disallowed from this door
        if (line->flags & ML_SECRET) // they can't open secret doors either
          return;
      }
      if (!line->tag) //3/2/98 move outside the monster check
        return;
      linefunc = EV_DoGenDoor;
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenLockedBase)
    {
      if (!thing->player)
        return;                     // monsters disallowed from unlocking doors
      if (((LN_SPECIAL(line)&TriggerType)==WalkOnce) || ((LN_SPECIAL(line)&TriggerType)==WalkMany))
      { //jff 4/1/98 check for being a walk type before reporting door type
        if (!P_CanUnlockGenDoor(line,thing->player))
          return;
      }
      else
        return;
      linefunc = EV_DoGenLockedDoor;
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenLiftBase)
    {
      if (!thing->player)
        if (!(LN_SPECIAL(line) & LiftMonster))
          return; // monsters disallowed
      if (!line->tag) //jff 2/27/98 all walk generalized types require tag
        return;
      linefunc = EV_DoGenLift;
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenStairsBase)
    {
      if (!thing->player)
        if (!(LN_SPECIAL(line) & StairMonster))
          return; // monsters disallowed
      if (!line->tag) //jff 2/27/98 all walk generalized types require tag
        return;
      linefunc = EV_DoGenStairs;
    }

    if (linefunc) // if it was a valid generalized type
      switch((LN_SPECIAL(line) & TriggerType) >> TriggerTypeShift)
      {
        case WalkOnce:
          if (linefunc(line))
            LN_SPECIAL(line) = 0;    // clear special if a walk once type
          return;
        case WalkMany:
          linefunc(line);
          return;
        default:                  // if not a walk type, do nothing here
          return;
      }


  if (!thing->player)
  {
    ok = 0;
    switch(LN_SPECIAL(line))
    {
      case 39:      // teleport trigger
      case 97:      // teleport retrigger
      case 125:     // teleport monsteronly trigger
      case 126:     // teleport monsteronly retrigger
      case 4:       // raise door
      case 10:      // plat down-wait-up-stay trigger
      case 88:      // plat down-wait-up-stay retrigger
        //jff 3/5/98 add ability of monsters etc. to use teleporters
      case 208:     //silent thing teleporters
      case 207:
      case 243:     //silent line-line teleporter
      case 244:     //jff 3/6/98 make fit within DCK's 256 linedef types
      case 262:     //jff 4/14/98 add monster only
      case 263:     //jff 4/14/98 silent thing,line,line rev types
      case 264:     //jff 4/14/98 plus player/monster silent line
      case 265:     //            reversed types
      case 266:
      case 267:
      case 268:
      case 269:
        ok = 1;
        break;
    }
    if (!ok)
      return;
  }

  if (!P_CheckTag(line))  //jff 2/27/98 disallow zero tag on some types
    return;

  // Dispatch on the line special value to the line's action routine
  // If a once only function, and successful, clear the line special

  switch (LN_SPECIAL(line))
  {
      // Regular walk once triggers

    case 2:
      // Open Door
      if (EV_DoDoor(line,dopen))
        LN_SPECIAL(line) = 0;
      break;

    case 3:
      // Close Door
      if (EV_DoDoor(line,dclose))
        LN_SPECIAL(line) = 0;
      break;

    case 4:
      // Raise Door
      if (EV_DoDoor(line,normal))
        LN_SPECIAL(line) = 0;
      break;

    case 5:
      // Raise Floor
      if (EV_DoFloor(line,raiseFloor))
        LN_SPECIAL(line) = 0;
      break;

    case 6:
      // Fast Ceiling Crush & Raise
      if (EV_DoCeiling(line,fastCrushAndRaise))
        LN_SPECIAL(line) = 0;
      break;

    case 8:
      // Build Stairs
      if (EV_BuildStairs(line,build8))
        LN_SPECIAL(line) = 0;
      break;

    case 10:
      // PlatDownWaitUp
      if (EV_DoPlat(line,downWaitUpStay,0))
        LN_SPECIAL(line) = 0;
      break;

    case 12:
      // Light Turn On - brightest near
      if (EV_LightTurnOn(line,0))
        LN_SPECIAL(line) = 0;
      break;

    case 13:
      // Light Turn On 255
      if (EV_LightTurnOn(line,255))
        LN_SPECIAL(line) = 0;
      break;

    case 16:
      // Close Door 30
      if (EV_DoDoor(line,close30ThenOpen))
        LN_SPECIAL(line) = 0;
      break;

    case 17:
      // Start Light Strobing
      if (EV_StartLightStrobing(line))
        LN_SPECIAL(line) = 0;
      break;

    case 19:
      // Lower Floor
      if (EV_DoFloor(line,lowerFloor))
        LN_SPECIAL(line) = 0;
      break;

    case 22:
      // Raise floor to nearest height and change texture
      if (EV_DoPlat(line,raiseToNearestAndChange,0))
        LN_SPECIAL(line) = 0;
      break;

    case 25:
      // Ceiling Crush and Raise
      if (EV_DoCeiling(line,crushAndRaise))
        LN_SPECIAL(line) = 0;
      break;

    case 30:
      // Raise floor to shortest texture height
      //  on either side of lines.
      if (EV_DoFloor(line,raiseToTexture))
        LN_SPECIAL(line) = 0;
      break;

    case 35:
      // Lights Very Dark
      if (EV_LightTurnOn(line,35))
        LN_SPECIAL(line) = 0;
      break;

    case 36:
      // Lower Floor (TURBO)
      if (EV_DoFloor(line,turboLower))
        LN_SPECIAL(line) = 0;
      break;

    case 37:
      // LowerAndChange
      if (EV_DoFloor(line,lowerAndChange))
        LN_SPECIAL(line) = 0;
      break;

    case 38:
      // Lower Floor To Lowest
      if (EV_DoFloor(line, lowerFloorToLowest))
        LN_SPECIAL(line) = 0;
      break;

    case 39:
      // TELEPORT! //jff 02/09/98 fix using up with wrong side crossing
      if (EV_Teleport(line, side, thing))
        LN_SPECIAL(line) = 0;
      break;

    case 40:
      // RaiseCeilingLowerFloor
        if (EV_DoCeiling(line, raiseToHighest))
          LN_SPECIAL(line) = 0;
      break;

    case 44:
      // Ceiling Crush
      if (EV_DoCeiling(line, lowerAndCrush))
        LN_SPECIAL(line) = 0;
      break;

    case 52:
      // EXIT!
      // killough 10/98: prevent zombies from exiting levels
      if (!(thing->player && thing->player->health <= 0))
  G_ExitLevel ();
      break;

    case 53:
      // Perpetual Platform Raise
      if (EV_DoPlat(line,perpetualRaise,0))
        LN_SPECIAL(line) = 0;
      break;

    case 54:
      // Platform Stop
      if (EV_StopPlat(line))
        LN_SPECIAL(line) = 0;
      break;

    case 56:
      // Raise Floor Crush
      if (EV_DoFloor(line,raiseFloorCrush))
        LN_SPECIAL(line) = 0;
      break;

    case 57:
      // Ceiling Crush Stop
      if (EV_CeilingCrushStop(line))
        LN_SPECIAL(line) = 0;
      break;

    case 58:
      // Raise Floor 24
      if (EV_DoFloor(line,raiseFloor24))
        LN_SPECIAL(line) = 0;
      break;

    case 59:
      // Raise Floor 24 And Change
      if (EV_DoFloor(line,raiseFloor24AndChange))
        LN_SPECIAL(line) = 0;
      break;

    case 100:
      // Build Stairs Turbo 16
      if (EV_BuildStairs(line,turbo16))
        LN_SPECIAL(line) = 0;
      break;

    case 104:
      // Turn lights off in sector(tag)
      if (EV_TurnTagLightsOff(line))
        LN_SPECIAL(line) = 0;
      break;

    case 108:
      // Blazing Door Raise (faster than TURBO!)
      if (EV_DoDoor(line,blazeRaise))
        LN_SPECIAL(line) = 0;
      break;

    case 109:
      // Blazing Door Open (faster than TURBO!)
      if (EV_DoDoor (line,blazeOpen))
        LN_SPECIAL(line) = 0;
      break;

    case 110:
      // Blazing Door Close (faster than TURBO!)
      if (EV_DoDoor (line,blazeClose))
        LN_SPECIAL(line) = 0;
      break;

    case 119:
      // Raise floor to nearest surr. floor
      if (EV_DoFloor(line,raiseFloorToNearest))
        LN_SPECIAL(line) = 0;
      break;

    case 121:
      // Blazing PlatDownWaitUpStay
      if (EV_DoPlat(line,blazeDWUS,0))
        LN_SPECIAL(line) = 0;
      break;

    case 124:
      // Secret EXIT
      // killough 10/98: prevent zombies from exiting levels
      // CPhipps - change for lxdoom's compatibility handling
      if (!(thing->player && thing->player->health <= 0))
  G_SecretExitLevel ();
      break;

    case 125:
      // TELEPORT MonsterONLY
      if (!thing->player &&
          (EV_Teleport(line, side, thing)))
        LN_SPECIAL(line) = 0;
      break;

    case 130:
      // Raise Floor Turbo
      if (EV_DoFloor(line,raiseFloorTurbo))
        LN_SPECIAL(line) = 0;
      break;

    case 141:
      // Silent Ceiling Crush & Raise
      if (EV_DoCeiling(line,silentCrushAndRaise))
        LN_SPECIAL(line) = 0;
      break;

      // Regular walk many retriggerable

    case 72:
      // Ceiling Crush
      EV_DoCeiling( line, lowerAndCrush );
      break;

    case 73:
      // Ceiling Crush and Raise
      EV_DoCeiling(line,crushAndRaise);
      break;

    case 74:
      // Ceiling Crush Stop
      EV_CeilingCrushStop(line);
      break;

    case 75:
      // Close Door
      EV_DoDoor(line,dclose);
      break;

    case 76:
      // Close Door 30
      EV_DoDoor(line,close30ThenOpen);
      break;

    case 77:
      // Fast Ceiling Crush & Raise
      EV_DoCeiling(line,fastCrushAndRaise);
      break;

    case 79:
      // Lights Very Dark
      EV_LightTurnOn(line,35);
      break;

    case 80:
      // Light Turn On - brightest near
      EV_LightTurnOn(line,0);
      break;

    case 81:
      // Light Turn On 255
      EV_LightTurnOn(line,255);
      break;

    case 82:
      // Lower Floor To Lowest
      EV_DoFloor( line, lowerFloorToLowest );
      break;

    case 83:
      // Lower Floor
      EV_DoFloor(line,lowerFloor);
      break;

    case 84:
      // LowerAndChange
      EV_DoFloor(line,lowerAndChange);
      break;

    case 86:
      // Open Door
      EV_DoDoor(line,dopen);
      break;

    case 87:
      // Perpetual Platform Raise
      EV_DoPlat(line,perpetualRaise,0);
      break;

    case 88:
      // PlatDownWaitUp
      EV_DoPlat(line,downWaitUpStay,0);
      break;

    case 89:
      // Platform Stop
      EV_StopPlat(line);
      break;

    case 90:
      // Raise Door
      EV_DoDoor(line,normal);
      break;

    case 91:
      // Raise Floor
      EV_DoFloor(line,raiseFloor);
      break;

    case 92:
      // Raise Floor 24
      EV_DoFloor(line,raiseFloor24);
      break;

    case 93:
      // Raise Floor 24 And Change
      EV_DoFloor(line,raiseFloor24AndChange);
      break;

    case 94:
      // Raise Floor Crush
      EV_DoFloor(line,raiseFloorCrush);
      break;

    case 95:
      // Raise floor to nearest height
      // and change texture.
      EV_DoPlat(line,raiseToNearestAndChange,0);
      break;

    case 96:
      // Raise floor to shortest texture height
      // on either side of lines.
      EV_DoFloor(line,raiseToTexture);
      break;

    case 97:
      // TELEPORT!
      EV_Teleport( line, side, thing );
      break;

    case 98:
      // Lower Floor (TURBO)
      EV_DoFloor(line,turboLower);
      break;

    case 105:
      // Blazing Door Raise (faster than TURBO!)
      EV_DoDoor (line,blazeRaise);
      break;

    case 106:
      // Blazing Door Open (faster than TURBO!)
      EV_DoDoor (line,blazeOpen);
      break;

    case 107:
      // Blazing Door Close (faster than TURBO!)
      EV_DoDoor (line,blazeClose);
      break;

    case 120:
      // Blazing PlatDownWaitUpStay.
      EV_DoPlat(line,blazeDWUS,0);
      break;

    case 126:
      // TELEPORT MonsterONLY.
      if (!thing->player)
        EV_Teleport( line, side, thing );
      break;

    case 128:
      // Raise To Nearest Floor
      EV_DoFloor(line,raiseFloorToNearest);
      break;

    case 129:
      // Raise Floor Turbo
      EV_DoFloor(line,raiseFloorTurbo);
      break;

      // Extended walk triggers

      // jff 1/29/98 added new linedef types to fill all functions out so that
      // all have varieties SR, S1, WR, W1

      // killough 1/31/98: "factor out" compatibility test, by
      // adding inner switch qualified by compatibility flag.
      // relax test to demo_compatibility

      // killough 2/16/98: Fix problems with W1 types being cleared too early

    default:
        switch (LN_SPECIAL(line))
        {
          // Extended walk once triggers

          case 142:
            // Raise Floor 512
            // 142 W1  EV_DoFloor(raiseFloor512)
            if (EV_DoFloor(line,raiseFloor512))
              LN_SPECIAL(line) = 0;
            break;

          case 143:
            // Raise Floor 24 and change
            // 143 W1  EV_DoPlat(raiseAndChange,24)
            if (EV_DoPlat(line,raiseAndChange,24))
              LN_SPECIAL(line) = 0;
            break;

          case 144:
            // Raise Floor 32 and change
            // 144 W1  EV_DoPlat(raiseAndChange,32)
            if (EV_DoPlat(line,raiseAndChange,32))
              LN_SPECIAL(line) = 0;
            break;

          case 145:
            // Lower Ceiling to Floor
            // 145 W1  EV_DoCeiling(lowerToFloor)
            if (EV_DoCeiling( line, lowerToFloor ))
              LN_SPECIAL(line) = 0;
            break;

          case 146:
            // Lower Pillar, Raise Donut
            // 146 W1  EV_DoDonut()
            if (EV_DoDonut(line))
              LN_SPECIAL(line) = 0;
            break;

          case 199:
            // Lower ceiling to lowest surrounding ceiling
            // 199 W1 EV_DoCeiling(lowerToLowest)
            if (EV_DoCeiling(line,lowerToLowest))
              LN_SPECIAL(line) = 0;
            break;

          case 200:
            // Lower ceiling to highest surrounding floor
            // 200 W1 EV_DoCeiling(lowerToMaxFloor)
            if (EV_DoCeiling(line,lowerToMaxFloor))
              LN_SPECIAL(line) = 0;
            break;

          case 207:
            // killough 2/16/98: W1 silent teleporter (normal kind)
            if (EV_SilentTeleport(line, side, thing))
              LN_SPECIAL(line) = 0;
            break;

            //jff 3/16/98 renumber 215->153
          case 153: //jff 3/15/98 create texture change no motion type
            // Texture/Type Change Only (Trig)
            // 153 W1 Change Texture/Type Only
            if (EV_DoChange(line,trigChangeOnly))
              LN_SPECIAL(line) = 0;
            break;

          case 239: //jff 3/15/98 create texture change no motion type
            // Texture/Type Change Only (Numeric)
            // 239 W1 Change Texture/Type Only
            if (EV_DoChange(line,numChangeOnly))
              LN_SPECIAL(line) = 0;
            break;

          case 219:
            // Lower floor to next lower neighbor
            // 219 W1 Lower Floor Next Lower Neighbor
            if (EV_DoFloor(line,lowerFloorToNearest))
              LN_SPECIAL(line) = 0;
            break;

          case 227:
            // Raise elevator next floor
            // 227 W1 Raise Elevator next floor
            if (EV_DoElevator(line,elevateUp))
              LN_SPECIAL(line) = 0;
            break;

          case 231:
            // Lower elevator next floor
            // 231 W1 Lower Elevator next floor
            if (EV_DoElevator(line,elevateDown))
              LN_SPECIAL(line) = 0;
            break;

          case 235:
            // Elevator to current floor
            // 235 W1 Elevator to current floor
            if (EV_DoElevator(line,elevateCurrent))
              LN_SPECIAL(line) = 0;
            break;

          case 243: //jff 3/6/98 make fit within DCK's 256 linedef types
            // killough 2/16/98: W1 silent teleporter (linedef-linedef kind)
            if (EV_SilentLineTeleport(line, side, thing, false))
              LN_SPECIAL(line) = 0;
            break;

          case 262: //jff 4/14/98 add silent line-line reversed
            if (EV_SilentLineTeleport(line, side, thing, true))
              LN_SPECIAL(line) = 0;
            break;

          case 264: //jff 4/14/98 add monster-only silent line-line reversed
            if (!thing->player &&
                EV_SilentLineTeleport(line, side, thing, true))
              LN_SPECIAL(line) = 0;
            break;

          case 266: //jff 4/14/98 add monster-only silent line-line
            if (!thing->player &&
                EV_SilentLineTeleport(line, side, thing, false))
              LN_SPECIAL(line) = 0;
            break;

          case 268: //jff 4/14/98 add monster-only silent
            if (!thing->player && EV_SilentTeleport(line, side, thing))
              LN_SPECIAL(line) = 0;
            break;

          //jff 1/29/98 end of added W1 linedef types

          // Extended walk many retriggerable

          //jff 1/29/98 added new linedef types to fill all functions
          //out so that all have varieties SR, S1, WR, W1

          case 147:
            // Raise Floor 512
            // 147 WR  EV_DoFloor(raiseFloor512)
            EV_DoFloor(line,raiseFloor512);
            break;

          case 148:
            // Raise Floor 24 and Change
            // 148 WR  EV_DoPlat(raiseAndChange,24)
            EV_DoPlat(line,raiseAndChange,24);
            break;

          case 149:
            // Raise Floor 32 and Change
            // 149 WR  EV_DoPlat(raiseAndChange,32)
            EV_DoPlat(line,raiseAndChange,32);
            break;

          case 150:
            // Start slow silent crusher
            // 150 WR  EV_DoCeiling(silentCrushAndRaise)
            EV_DoCeiling(line,silentCrushAndRaise);
            break;

          case 151:
            // RaiseCeilingLowerFloor
            // 151 WR  EV_DoCeiling(raiseToHighest),
            //         EV_DoFloor(lowerFloortoLowest)
            EV_DoCeiling( line, raiseToHighest );
            EV_DoFloor( line, lowerFloorToLowest );
            break;

          case 152:
            // Lower Ceiling to Floor
            // 152 WR  EV_DoCeiling(lowerToFloor)
            EV_DoCeiling( line, lowerToFloor );
            break;

            //jff 3/16/98 renumber 153->256
          case 256:
            // Build stairs, step 8
            // 256 WR EV_BuildStairs(build8)
            EV_BuildStairs(line,build8);
            break;

            //jff 3/16/98 renumber 154->257
          case 257:
            // Build stairs, step 16
            // 257 WR EV_BuildStairs(turbo16)
            EV_BuildStairs(line,turbo16);
            break;

          case 155:
            // Lower Pillar, Raise Donut
            // 155 WR  EV_DoDonut()
            EV_DoDonut(line);
            break;

          case 156:
            // Start lights strobing
            // 156 WR Lights EV_StartLightStrobing()
            EV_StartLightStrobing(line);
            break;

          case 157:
            // Lights to dimmest near
            // 157 WR Lights EV_TurnTagLightsOff()
            EV_TurnTagLightsOff(line);
            break;

          case 201:
            // Lower ceiling to lowest surrounding ceiling
            // 201 WR EV_DoCeiling(lowerToLowest)
            EV_DoCeiling(line,lowerToLowest);
            break;

          case 202:
            // Lower ceiling to highest surrounding floor
            // 202 WR EV_DoCeiling(lowerToMaxFloor)
            EV_DoCeiling(line,lowerToMaxFloor);
            break;

          case 208:
            // killough 2/16/98: WR silent teleporter (normal kind)
            EV_SilentTeleport(line, side, thing);
            break;

          case 212: //jff 3/14/98 create instant toggle floor type
            // Toggle floor between C and F instantly
            // 212 WR Instant Toggle Floor
            EV_DoPlat(line,toggleUpDn,0);
            break;

          //jff 3/16/98 renumber 216->154
          case 154: //jff 3/15/98 create texture change no motion type
            // Texture/Type Change Only (Trigger)
            // 154 WR Change Texture/Type Only
            EV_DoChange(line,trigChangeOnly);
            break;

          case 240: //jff 3/15/98 create texture change no motion type
            // Texture/Type Change Only (Numeric)
            // 240 WR Change Texture/Type Only
            EV_DoChange(line,numChangeOnly);
            break;

          case 220:
            // Lower floor to next lower neighbor
            // 220 WR Lower Floor Next Lower Neighbor
            EV_DoFloor(line,lowerFloorToNearest);
            break;

          case 228:
            // Raise elevator next floor
            // 228 WR Raise Elevator next floor
            EV_DoElevator(line,elevateUp);
            break;

          case 232:
            // Lower elevator next floor
            // 232 WR Lower Elevator next floor
            EV_DoElevator(line,elevateDown);
            break;

          case 236:
            // Elevator to current floor
            // 236 WR Elevator to current floor
            EV_DoElevator(line,elevateCurrent);
            break;

          case 244: //jff 3/6/98 make fit within DCK's 256 linedef types
            // killough 2/16/98: WR silent teleporter (linedef-linedef kind)
            EV_SilentLineTeleport(line, side, thing, false);
            break;

          case 263: //jff 4/14/98 add silent line-line reversed
            EV_SilentLineTeleport(line, side, thing, true);
            break;

          case 265: //jff 4/14/98 add monster-only silent line-line reversed
            if (!thing->player)
              EV_SilentLineTeleport(line, side, thing, true);
            break;

          case 267: //jff 4/14/98 add monster-only silent line-line
            if (!thing->player)
              EV_SilentLineTeleport(line, side, thing, false);
            break;

          case 269: //jff 4/14/98 add monster-only silent
            if (!thing->player)
              EV_SilentTeleport(line, side, thing);
            break;

            //jff 1/29/98 end of added WR linedef types
        }
      break;
  }
}

//
// P_ShootSpecialLine - Gun trigger special dispatcher
//
// Called when a thing shoots a special line with bullet, shell, saw, or fist.
//
// jff 02/12/98 all G1 lines were fixed to check the result from the EV_
// function before clearing the special. This avoids losing the function
// of the line, should the sector already be in motion when the line is
// impacted. Change is qualified by demo_compatibility.
//
void P_ShootSpecialLine
( mobj_t*       thing,
  const line_t*       line )
{
    // pointer to line function is NULL by default, set non-null if
    // line special is gun triggered generalized linedef type
    int (*linefunc)(const line_t *line)=NULL;

    // check each range of generalized linedefs
    if ((unsigned)LN_SPECIAL(line) >= GenEnd)
    {
      // Out of range for GenFloors
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenFloorBase)
    {
      if (!thing->player)
        if ((LN_SPECIAL(line) & FloorChange) || !(LN_SPECIAL(line) & FloorModel))
          return;   // FloorModel is "Allow Monsters" if FloorChange is 0
      if (!line->tag) //jff 2/27/98 all gun generalized types require tag
        return;

      linefunc = EV_DoGenFloor;
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenCeilingBase)
    {
      if (!thing->player)
        if ((LN_SPECIAL(line) & CeilingChange) || !(LN_SPECIAL(line) & CeilingModel))
          return;   // CeilingModel is "Allow Monsters" if CeilingChange is 0
      if (!line->tag) //jff 2/27/98 all gun generalized types require tag
        return;
      linefunc = EV_DoGenCeiling;
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenDoorBase)
    {
      if (!thing->player)
      {
        if (!(LN_SPECIAL(line) & DoorMonster))
          return;   // monsters disallowed from this door
        if (line->flags & ML_SECRET) // they can't open secret doors either
          return;
      }
      if (!line->tag) //jff 3/2/98 all gun generalized types require tag
        return;
      linefunc = EV_DoGenDoor;
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenLockedBase)
    {
      if (!thing->player)
        return;   // monsters disallowed from unlocking doors
      if (((LN_SPECIAL(line)&TriggerType)==GunOnce) || ((LN_SPECIAL(line)&TriggerType)==GunMany))
      { //jff 4/1/98 check for being a gun type before reporting door type
        if (!P_CanUnlockGenDoor(line,thing->player))
          return;
      }
      else
        return;
      if (!line->tag) //jff 2/27/98 all gun generalized types require tag
        return;

      linefunc = EV_DoGenLockedDoor;
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenLiftBase)
    {
      if (!thing->player)
        if (!(LN_SPECIAL(line) & LiftMonster))
          return; // monsters disallowed
      linefunc = EV_DoGenLift;
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenStairsBase)
    {
      if (!thing->player)
        if (!(LN_SPECIAL(line) & StairMonster))
          return; // monsters disallowed
      if (!line->tag) //jff 2/27/98 all gun generalized types require tag
        return;
      linefunc = EV_DoGenStairs;
    }
    else if ((unsigned)LN_SPECIAL(line) >= GenCrusherBase)
    {
      if (!thing->player)
        if (!(LN_SPECIAL(line) & StairMonster))
          return; // monsters disallowed
      if (!line->tag) //jff 2/27/98 all gun generalized types require tag
        return;
      linefunc = EV_DoGenCrusher;
    }

    if (linefunc)
      switch((LN_SPECIAL(line) & TriggerType) >> TriggerTypeShift)
      {
        case GunOnce:
          if (linefunc(line))
            P_ChangeSwitchTexture(line,0);
          return;
        case GunMany:
          if (linefunc(line))
            P_ChangeSwitchTexture(line,1);
          return;
        default:  // if not a gun type, do nothing here
          return;
      }

  // Impacts that other things can activate.
  if (!thing->player)
  {
    int ok = 0;
    switch(LN_SPECIAL(line))
    {
      case 46:
        // 46 GR Open door on impact weapon is monster activatable
        ok = 1;
        break;
    }
    if (!ok)
      return;
  }

  if (!P_CheckTag(line))  //jff 2/27/98 disallow zero tag on some types
    return;

  switch(LN_SPECIAL(line))
  {
    case 24:
      // 24 G1 raise floor to highest adjacent
      if (EV_DoFloor(line,raiseFloor))
        P_ChangeSwitchTexture(line,0);
      break;

    case 46:
      // 46 GR open door, stay open
      EV_DoDoor(line,dopen);
      P_ChangeSwitchTexture(line,1);
      break;

    case 47:
      // 47 G1 raise floor to nearest and change texture and type
      if (EV_DoPlat(line,raiseToNearestAndChange,0))
        P_ChangeSwitchTexture(line,0);
      break;

    //jff 1/30/98 added new gun linedefs here
    // killough 1/31/98: added demo_compatibility check, added inner switch

    default:
        switch (LN_SPECIAL(line))
        {
          case 197:
            // Exit to next level
            // killough 10/98: prevent zombies from exiting levels
            if(thing->player && thing->player->health<=0)
              break;
            P_ChangeSwitchTexture(line,0);
            G_ExitLevel();
            break;

          case 198:
            // Exit to secret level
            // killough 10/98: prevent zombies from exiting levels
            if(thing->player && thing->player->health<=0)
              break;
            P_ChangeSwitchTexture(line,0);
            G_SecretExitLevel();
            break;
            //jff end addition of new gun linedefs
        }
      break;
  }
}


//
// P_PlayerInSpecialSector()
//
// Called every tick frame
//  that the player origin is in a special sector
//
// Changed to ignore sector types the engine does not recognize
//
void P_PlayerInSpecialSector (player_t* player)
{
  sector_t*   sector;

  sector = player->mo->subsector->sector;

  // Falling, not all the way down yet?
  // Sector specials don't apply in mid-air
  if (player->mo->z != sector->floorheight)
    return;

  // Has hit ground.
  //jff add if to handle old vs generalized types
  if (sector->special<32) // regular sector specials
  {
    switch (sector->special)
      {
      case 5:
        // 5/10 unit damage per 31 ticks
        if (!player->powers[pw_ironfeet])
          if (!(_g->leveltime&0x1f))
            P_DamageMobj (player->mo, NULL, NULL, 10);
        break;

      case 7:
        // 2/5 unit damage per 31 ticks
        if (!player->powers[pw_ironfeet])
          if (!(_g->leveltime&0x1f))
            P_DamageMobj (player->mo, NULL, NULL, 5);
        break;

      case 16:
        // 10/20 unit damage per 31 ticks
      case 4:
        // 10/20 unit damage plus blinking light (light already spawned)
        if (!player->powers[pw_ironfeet]
            || (P_Random()<5) ) // even with suit, take damage
        {
          if (!(_g->leveltime&0x1f))
            P_DamageMobj (player->mo, NULL, NULL, 20);
        }
        break;

      case 9:
        // Tally player in secret sector, clear secret special
        player->secretcount++;
        sector->special = 0;
        break;

      case 11:
        if (!(_g->leveltime&0x1f))
          P_DamageMobj (player->mo, NULL, NULL, 20);

        if (player->health <= 10)
          G_ExitLevel();
        break;

      default:
        //jff 1/24/98 Don't exit as DOOM2 did, just ignore
        break;
      }
  }
  else //jff 3/14/98 handle extended sector types for secrets and damage
  {
    switch ((sector->special&DAMAGE_MASK)>>DAMAGE_SHIFT)
    {
      case 0: // no damage
        break;
      case 1: // 2/5 damage per 31 ticks
        if (!player->powers[pw_ironfeet])
          if (!(_g->leveltime&0x1f))
            P_DamageMobj (player->mo, NULL, NULL, 5);
        break;
      case 2: // 5/10 damage per 31 ticks
        if (!player->powers[pw_ironfeet])
          if (!(_g->leveltime&0x1f))
            P_DamageMobj (player->mo, NULL, NULL, 10);
        break;
      case 3: // 10/20 damage per 31 ticks
        if (!player->powers[pw_ironfeet]
            || (P_Random()<5))  // take damage even with suit
        {
          if (!(_g->leveltime&0x1f))
            P_DamageMobj (player->mo, NULL, NULL, 20);
        }
        break;
    }
    if (sector->special&SECRET_MASK)
    {
      player->secretcount++;
      sector->special &= ~SECRET_MASK;
      if (sector->special<32) // if all extended bits clear,
        sector->special=0;    // sector is not special anymore
    }

    // phares 3/19/98:
    //
    // If FRICTION_MASK or PUSH_MASK is set, we don't care at this
    // point, since the code to deal with those situations is
    // handled by Thinkers.

  }
}

//
// P_UpdateSpecials()
//
// Check level timer, frag counter,
// animate flats, scroll walls,
// change button textures
//
// Reads and modifies globals:
//  levelTimer, levelTimeCount,
//  levelFragLimit, levelFragLimitCount
//


void P_UpdateSpecials (void)
{
    anim_t*     anim;
    int         pic;
    int         i;

    // Animate flats and textures globally
    for (anim = _g->anims ; anim < _g->lastanim ; anim++)
    {
        unsigned int t = (_g->leveltime >> 3);
        unsigned int n = anim->numpics;

        if((n & (n - 1)) == 0)
            pic = anim->basepic + (t & (n - 1));
        else
            pic = anim->basepic + (t % n);

        for(i = anim->basepic; i<anim->basepic+anim->numpics; i++)
        {
            if(anim->istexture)
                texturetranslation[i] = pic;
            else
                flattranslation[i] = pic;
        }
    }

    // Check buttons (retriggerable switches) and change texture on timeout
    for (i = 0; i < MAXBUTTONS; i++)
    {
        if (_g->buttonlist[i].btimer)
        {
            _g->buttonlist[i].btimer--;

            if (!_g->buttonlist[i].btimer)
            {
                switch(_g->buttonlist[i].where)
                {
                    case top:
                        _g->sides[_g->buttonlist[i].line->sidenum[0]].toptexture =
                                _g->buttonlist[i].btexture;
                        break;

                    case middle:
                        _g->sides[_g->buttonlist[i].line->sidenum[0]].midtexture =
                                _g->buttonlist[i].btexture;
                        break;

                    case bottom:
                        _g->sides[_g->buttonlist[i].line->sidenum[0]].bottomtexture =
                                _g->buttonlist[i].btexture;
                        break;
                }

                S_StartSound2(_g->buttonlist[i].soundorg, sfx_swtchn);
                memset(&_g->buttonlist[i],0,sizeof(button_t));
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////
//
// Sector and Line special thinker spawning at level startup
//
//////////////////////////////////////////////////////////////////////

//
// P_SpawnSpecials
// After the map has been loaded,
//  scan for specials that spawn thinkers
//

// Parses command line parameters.
void P_SpawnSpecials (void)
{
  sector_t*   sector;
  int         i;
  int         episode;

  episode = 1;
  if (W_CheckNumForName("texture2") >= 0)
    episode = 2;

  //  Init special sectors.
  sector = _g->sectors;
  for (i=0 ; i<_g->numsectors ; i++, sector++)
  {
    if (!sector->special)
      continue;

    if (sector->special&SECRET_MASK) //jff 3/15/98 count extended
      _g->totalsecret++;                 // secret sectors too

    switch (sector->special&31)
    {
      case 1:
        // random off
        P_SpawnLightFlash (sector);
        break;

      case 2:
        // strobe fast
        P_SpawnStrobeFlash(sector,FASTDARK,0);
        break;

      case 3:
        // strobe slow
        P_SpawnStrobeFlash(sector,SLOWDARK,0);
        break;

      case 4:
        // strobe fast/death slime
        P_SpawnStrobeFlash(sector,FASTDARK,0);
        sector->special |= 3<<DAMAGE_SHIFT; //jff 3/14/98 put damage bits in
        break;

      case 8:
        // glowing light
        P_SpawnGlowingLight(sector);
        break;
      case 9:
        // secret sector
        if (sector->special<32) //jff 3/14/98 bits don't count unless not
          _g->totalsecret++;        // a generalized sector type
        break;

      case 10:
        // door close in 30 seconds
        P_SpawnDoorCloseIn30 (sector);
        break;

      case 12:
        // sync strobe slow
        P_SpawnStrobeFlash (sector, SLOWDARK, 1);
        break;

      case 13:
        // sync strobe fast
        P_SpawnStrobeFlash (sector, FASTDARK, 1);
        break;

      case 14:
        // door raise in 5 minutes
        P_SpawnDoorRaiseIn5Mins (sector, i);
        break;

      case 17:
        // fire flickering
        P_SpawnFireFlicker(sector);
        break;
    }
  }

  P_RemoveAllActiveCeilings();  // jff 2/22/98 use killough's scheme

  P_RemoveAllActivePlats();     // killough

  for (i = 0;i < MAXBUTTONS;i++)
    memset(&_g->buttonlist[i],0,sizeof(button_t));

  // P_InitTagLists() must be called before P_FindSectorFromLineTag()
  // or P_FindLineFromLineTag() can be called.

  P_InitTagLists();   // killough 1/30/98: Create xref tables for tags

  P_SpawnScrollers(); // killough 3/7/98: Add generalized scrollers
}

// killough 2/28/98:
//
// This function, with the help of r_plane.c and r_bsp.c, supports generalized
// scrolling floors and walls, with optional mobj-carrying properties, e.g.
// conveyor belts, rivers, etc. A linedef with a special type affects all
// tagged sectors the same way, by creating scrolling and/or object-carrying
// properties. Multiple linedefs may be used on the same sector and are
// cumulative, although the special case of scrolling a floor and carrying
// things on it, requires only one linedef. The linedef's direction determines
// the scrolling direction, and the linedef's length determines the scrolling
// speed. This was designed so that an edge around the sector could be used to
// control the direction of the sector's scrolling, which is usually what is
// desired.
//
// Process the active scrollers.
//
// This is the main scrolling code
// killough 3/7/98

void T_Scroll(scroll_t *s)
{
    side_t *side  =_g->sides + s->affectee;
    side->textureoffset++;
}

//
// Add_Scroller()
//
// Add a generalized scroller to the thinker list.
//
// type: the enumerated type of scrolling: floor, ceiling, floor carrier,
//   wall, floor carrier & scroller
//
// (dx,dy): the direction and speed of the scrolling or its acceleration
//
// control: the sector whose heights control this scroller's effect
//   remotely, or -1 if no control sector
//
// affectee: the index of the affected object (sector or sidedef)
//
// accel: non-zero if this is an accelerative effect
//

static void Add_Scroller(int affectee)
{
  scroll_t *s = Z_Malloc(sizeof *s, PU_LEVSPEC, 0);
  s->thinker.function = T_Scroll;
  s->affectee = affectee;
  P_AddThinker(&s->thinker);
}

// Initialize the scrollers
static void P_SpawnScrollers(void)
{
    int i;
    const line_t *l = _g->lines;

    for (i=0;i<_g->numlines;i++,l++)
    {
        int special = LN_SPECIAL(l);

        switch (special)
        {
        case 48:                  // scroll first side
            Add_Scroller(_g->lines[i].sidenum[0]);
            break;

        }
    }
}

